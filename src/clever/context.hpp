//
//  Copyright Silvin Lubecki 2010
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <memory>
#include <map>
#include <set>

#include <boost/algorithm/string.hpp>

#include "error.hpp"
#include "opencl.hpp"
#include "icontext.hpp"
#include "kernel_proxy.hpp"

namespace clever
{

struct context_settings
{
    //TODO remember to remove -g
	context_settings(opencl::device_type device_type = opencl::device_type::default_,
			std::string const& platform_name = "",
			std::string build_options = "-g", bool profile = false,
			cl_command_queue_properties cmd_queue_properties = 0,
			int useComputeUnits = -1) :

			m_platform_name(platform_name),
			m_device_type(device_type),
			m_build_options(build_options),
			m_profile(profile),
			m_cmd_queue_properties(cmd_queue_properties),
			m_useComputeUnits(useComputeUnits)
	{

	}

	std::string m_platform_name;
	opencl::device_type m_device_type;
	std::string m_build_options;
	bool m_profile;
	cl_command_queue_properties m_cmd_queue_properties;
	int m_useComputeUnits;

	static context_settings default_gpu()
	{
		// TODO: make this more generic
		return context_settings(opencl::device_type::gpu);
	}

	static context_settings nvidia_gpu()
	{
		return context_settings(opencl::device_type::gpu,
			opencl::PlatformNameNVIDIA()
		);
	}
	
	static context_settings amd_gpu()
	{
		return context_settings(opencl::device_type::gpu,
			opencl::PlatformNameAMD()
		);
	}
	
	static context_settings default_cpu()
	{
		return context_settings();
	}

	static context_settings amd_cpu()
	{
		return context_settings(opencl::device_type::cpu,
			opencl::PlatformNameAMD()
		);
	}

	static context_settings intel_cpu()
	{
		return context_settings(opencl::device_type::cpu,
			opencl::PlatformNameIntel()
		);
	}
};

struct source_modifier: public boost::noncopyable
{
	virtual ~source_modifier() {} 
	virtual void modify(std::string & src) const = 0;
};


struct tIOEvent{ //event, bytes transferred
	cl_event event;
	size_t bytes;
	cl_ulong time;

	tIOEvent() : event(0), bytes(0), time(0) { }
	tIOEvent(cl_event e, size_t b) : event(e), bytes(b), time(0) { }

	float bandwith(){
		return time != 0 ? ((float) bytes) / time : 0;
	}

	tIOEvent operator+(const tIOEvent & rhs) const {
		tIOEvent result;
		result.time = this->time + rhs.time;
		result.bytes = this->bytes + rhs.bytes;

		return result;
	}

};

typedef std::vector<tIOEvent> tIOEvents;

struct tKernelEvent{ //kernel, event
	cl_event event;
	cl_kernel kernel;
	std::string kernelName;
	range globalSize;
	range localSize;
	cl_ulong time;
	cl_ulong queued;

	tKernelEvent() : event(0), kernel(0), time(0), queued(0) { }
	tKernelEvent(cl_event e, cl_kernel k) : event(e), kernel(k), time(0), queued(0) { }

	bool operator==(const tKernelEvent & rhs) const {
		return this->event == rhs.event;
	}

	bool operator==(const cl_kernel & rhs) const {
		return this->kernel == rhs;
	}

	bool operator==(const cl_event & e) const {
		return this->event == e;
	}

	bool operator==(const std::string & s) const {
			return kernelName == s;
		}

	uint items() const {
		uint r = 1; //its reasonable to assume that the kernel processed at least one item
		for(uint i = 0; i < globalSize.dimension(); ++i)
			r *= globalSize.getSize(i);

		return r;
	}

	uint threads() const {
		uint r = 1; //its reasonable to assume that the kernel was processed by least one thread
		for(uint i = 0; i < globalSize.dimension(); ++i)
			r *= globalSize.getSize(i);

		return r;
	}

	float runtimePerItem() const {
		return time / items();
	}

	tKernelEvent operator+(const tKernelEvent & rhs) const {
		tKernelEvent result;
		result.time = this->time + rhs.time;
		result.queued = this->queued + rhs.queued;

		if(this->kernel == rhs.kernel)
			result.kernel = this->kernel;

		if(this->kernelName.compare(rhs.kernelName) == 0)
			result.localSize = this->localSize;

		if(this->globalSize == rhs.globalSize)
			result.globalSize = this->globalSize;

		if(this->localSize == rhs.localSize)
					result.localSize = this->localSize;

		return result;
	}
};

typedef std::vector<tKernelEvent> tKernelEvents;

class context: public clever::icontext
{
public:
	context(const context_settings & settings = context_settings()) :
			m_settings(settings), sub_dev_id_(NULL)
	{
		init_with_settings(settings);
	}

    //TODO remember to remove -g
	context(opencl::device_type dev_type, std::string platformName,
			std::string buildProperties = "-g",
			cl_command_queue_properties queueSettings = 0, bool profileKernels =
					false, int threadCount = -1) :
			sub_dev_id_(NULL)
	{
		context_settings set(dev_type, platformName, buildProperties,
				profileKernels, queueSettings, threadCount);

		m_settings = set;

		init_with_settings(set);
	}

private:
	void init_with_settings(context_settings const& setttings)
	{
		context_ = opencl::createContext(m_settings.m_device_type,
				m_settings.m_platform_name, m_settings.m_useComputeUnits,
				&sub_dev_id_);
		::size_t size;
		ERROR_HANDLER(
				ERROR = opencl::clGetContextInfo( context_, CL_CONTEXT_DEVICES, 0, NULL, &size ));
		ERROR_HANDLER( ERROR = size > 0 ? CL_SUCCESS : CL_DEVICE_NOT_AVAILABLE);
		m_devices.reset(new cl_device_id[size]);
		ERROR_HANDLER(
				ERROR = opencl::clGetContextInfo( context_, CL_CONTEXT_DEVICES, size, m_devices.get(), NULL ));

		if (m_settings.m_profile)
		{
			m_settings.m_cmd_queue_properties |= CL_QUEUE_PROFILING_ENABLE;
		}

		ERROR_HANDLER(
				queue_ = opencl::clCreateCommandQueue( context_, native_device(), m_settings.m_cmd_queue_properties, &ERROR ));

	}

public:

	~context()
	{
		//std::cout << std::endl << "Flushing command q to free OpenCL context";
		ERROR_HANDLER( ERROR = opencl::clFlush( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clFinish( queue_ ));

		if(!allocatedMemory.empty()){
			//std::cerr << "ERROR Unfreeded memory! " << allocatedMemory.size() << " objects unallocated" << std::endl;

			clearAllBuffers();

			assert(allocatedMemory.empty());
		}

		ERROR_HANDLER( ERROR = opencl::clReleaseCommandQueue( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clReleaseContext( context_ ));
		//std::cout << std::endl << "OpenCL context freed";

		if (sub_dev_id_ != NULL)
		{
			std::cout << std::endl << "# Releasing sub-device" << std::endl;
			ERROR_HANDLER( ERROR = opencl::clReleaseDevice(sub_dev_id_));
		}

	}

	void clearAllBuffers(){

		//std::cout << std::endl << "Flushing command q to free OpenCL context";
		ERROR_HANDLER( ERROR = opencl::clFlush( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clFinish( queue_ ));

		if(!allocatedMemory.empty()){
			//std::cerr << "ERROR Unfreeded memory! " << allocatedMemory.size() << " objects unallocated" << std::endl;

			std::set<cl_mem> toDelete(allocatedMemory);

			for(cl_mem m : toDelete){
				//std::cout << "Unallocating " << m << std::endl;
				release_buffer(m);
			}

			assert(allocatedMemory.empty());
		}

		//ensure again that everything is fine after deletion
		ERROR_HANDLER( ERROR = opencl::clFlush( queue_ ));
		ERROR_HANDLER( ERROR = opencl::clFinish( queue_ ));

	}

	cl_mem create_buffer(size_t buffer_size) const
	{
		cl_mem buff;
		ERROR_HANDLER(
				buff = opencl::clCreateBuffer( this->native_context(), CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
				buffer_size, NULL, &ERROR ));

		allocatedMemory.insert(buff);
		//std::cout << "created " << buff << std::endl;

		return buff;
	}

	void release_buffer(cl_mem memory_handle) const
	{
		allocatedMemory.erase(memory_handle);

		//if(r != 1)
			//std::cerr << "Could not remove memory object: " << memory_handle << std::endl;

		ERROR_HANDLER( ERROR = opencl::clReleaseMemObject( memory_handle ));

	}

	// transfar data from the device buffer to the host mem
	void transfer_from_buffer(cl_mem buffer_handle, void * buffer_data,
			size_t buffer_size, size_t numEventsInWaitList = 0, const cl_event * waitList = NULL, size_t offset = 0) const
	{
		cl_event evt;

		ERROR_HANDLER(
				ERROR = opencl::clEnqueueReadBuffer( this->default_queue(), buffer_handle, CL_TRUE, offset, buffer_size, buffer_data, numEventsInWaitList, waitList, &evt ));

		if(m_settings.m_profile)
			m_profile_reads.push_back(tIOEvent(evt, buffer_size));
	}

	// transfar data from the host to the device buffer
	void transfer_to_buffer(cl_mem buffer_handle, const void * buffer_data,
			size_t buffer_size) const
	{

		cl_event evt;

		ERROR_HANDLER(
				ERROR = opencl::clEnqueueWriteBuffer( this->default_queue(), buffer_handle, CL_TRUE, 0, buffer_size, buffer_data, 0, NULL, &evt ));

		if(m_settings.m_profile)
			m_profile_writes.push_back(tIOEvent(evt, buffer_size));
	}

	/*    virtual cl_mem download_buffer( cl_mem buffer, size_t size ) const = 0;

	 ERROR_HANDLER( handle.mem_ = wrapper.clCreateBuffer( context.native_context(),
	 CL_MEM_READ_WRITE, // | CL_MEM_USE_HOST_PTR,
	 handle.value_size * count, NULL, &ERROR ) );*/

	std::unique_ptr<clever::ikernel_proxy> create(const std::string& name,
			const std::string& sources) const
	{
		//std::cout << "Compiling kernel " << name ;
		//std::cout << " Build Options: " << build_options_ << std::endl;

		// todo: make this more generic
		// add to the source code
		std::stringstream final_source;

		// insert new lines
		std::string sFind(";");
		std::string sReplace(";\n");
		std::string local_sources(sources);
		//boost::replace_all( local_sources, sFind, sReplace );
		//boost::replace_all( local_sources, ",", ",\n" );

		if ((m_settings.m_platform_name == opencl::PlatformNameAMD())
				&& (m_settings.m_device_type == opencl::gpu))
		{
			// special dbl precision floating point flag for AMD GPUs
			final_source << "#pragma OPENCL EXTENSION cl_amd_fp64: enable"
					<< std::endl;
		}
		else
		{
			final_source << "#pragma OPENCL EXTENSION cl_khr_fp64: enable"
					<< std::endl;
		}

		//boost::replace_all( sources, ";", ";\n" );

		final_source << local_sources << std::endl;
		std::string final_sources_str(final_source.str());

		char * line_buffer[2048];

		typedef std::vector<std::string> split_vector_type;

		split_vector_type SplitVec; // #2: Search for tokens
		boost::split(SplitVec, final_sources_str, boost::is_any_of(";"),
				boost::token_compress_on);

		std::stringstream final_source_linebreak;

		size_t line_count = 0;
		for (auto & one_line : SplitVec)
		{
			if (line_count < (SplitVec.size() - 1))
				one_line += ";";

			line_buffer[line_count] = const_cast<char *>(one_line.c_str());
			line_count++;

			final_source_linebreak << one_line << std::endl;

			//std::cout << std::endl << one_line;
		}

		//const ::size_t size = final_sources_str.size();
		//const char* buffer = final_sources_str.c_str();
		//buffer[ size + 1 ] = null;
		//size++;

		cl_program program;
		ERROR_HANDLER(
				program = opencl::clCreateProgramWithSource( context_, line_count, (const char**) &line_buffer[0], NULL, &ERROR ));
		//std::cout << std::endl << build_options_;
		// passing the build options here wastes the NVIDIA SDK somehow, even the option are "" ??s
		//cl_int build_result = wrapper_.clBuildProgram( program, 0, NULL, build_options_.c_str(), NULL, NULL );
		cl_int build_result = opencl::clBuildProgram(program, 0, NULL,
				"-cl-unsafe-math-optimizations -cl-fast-relaxed-math", NULL,
				NULL);

		char char_out[1024];
		size_t char_out_size = 1024;
		size_t char_out_final;

		cl_device_id dev_id = *m_devices;

		if (build_result != CL_SUCCESS)
		{
			opencl::clGetProgramBuildInfo(program, dev_id, CL_PROGRAM_BUILD_LOG,
					char_out_size, &char_out, &char_out_final);

			std::cout << std::endl << " Source: ";
			std::cout << std::endl << final_sources_str << std::endl;

			std::cout << std::endl << "Compile error:" << char_out << std::endl;
			throw std::runtime_error(
					"OpenCL error while compiling kernel " + name);
		}

		//std::cout << "Compile done" << std::endl;

		return std::unique_ptr<clever::ikernel_proxy>(
				new clever::kernel_proxy(name, program,
						final_source_linebreak.str()));
	}

	void finish_default_queue() const
	{
		ERROR_HANDLER( ERROR = opencl::clFlush( default_queue() ));
		ERROR_HANDLER( ERROR = opencl::clFinish( default_queue() ));
	}

	cl_event execute_params(kernel_parameter_list const& parameter,
			const clever::ikernel_proxy& proxy,
			const clever::range & globalRange, const clever::range & localRange,
			const bool reverseParameters = false) const
	{

		cl_event evt =  proxy.execute_params(parameter, context_, queue_, globalRange, localRange,
					reverseParameters);

		if(m_settings.m_profile){
			tKernelEvent t( evt, proxy.native_kernel());
			t.kernelName = proxy.name();
			t.globalSize = globalRange;
			t.localSize = localRange;

			m_profile_kernels.push_back(t);

		}

		return evt;
	}

	int used_compute_units() const
	{
		return m_settings.m_useComputeUnits;
	}


	void add_source_modifier(source_modifier * mod)
	{
		m_source_modifier.push_back(mod);
	}

	bool is_profile() const
	{
		return m_settings.m_profile;
	}

	profile_info report_profile(cl_event ev) const
	{
		profile_info pinfo;

		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_QUEUED, sizeof ( cl_ulong), &pinfo.queued, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_SUBMIT, sizeof ( cl_ulong), &pinfo.submit, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_START, sizeof ( cl_ulong), &pinfo.start, NULL ));
		ERROR_HANDLER(
				ERROR = opencl::clGetEventProfilingInfo( ev, CL_PROFILING_COMMAND_END, sizeof ( cl_ulong), &pinfo.end, NULL ));

		return pinfo;
	}

	tIOEvent getWritePerf() const {
		tIOEvent result;

		for(tIOEvent t : m_profile_writes){
			result.time += report_profile(t.event).runtime();
			result.bytes += t.bytes;
		}

		return result;
	}

	tIOEvent getReadPerf() const {
		tIOEvent result;

		for(tIOEvent t : m_profile_reads){
			result.time += report_profile(t.event).runtime();
			result.bytes += t.bytes;
		}

		return result;
	}

	tIOEvent getIOPerf(){
		return getWritePerf() + getReadPerf();
	}

	tKernelEvent getKernelPerf(cl_event evt) const {

		auto it =  std::find(m_profile_kernels.begin(), m_profile_kernels.end(), evt);
		if(it == m_profile_kernels.end())
			return tKernelEvent();

		profile_info p = report_profile(it->event);
		tKernelEvent e(*it);
		e.time = p.runtime();
		e.queued = p.timetostart();

		return e;

	}

	tKernelEvents getKernelPerfs(cl_kernel kernel) const {

		tKernelEvents r;

		auto it = std::find(m_profile_kernels.begin(), m_profile_kernels.end(), kernel);
		while(it != m_profile_kernels.end()){
			profile_info p = report_profile(it->event);

			tKernelEvent e(*it);
			e.time = p.runtime();
			e.queued = p.timetostart();

			r.push_back(e);

			it = std::find(it, m_profile_kernels.end(), kernel);
		}

		return r;
	}

	tKernelEvents getKernelPerfs(std::string kernel) const {

		tKernelEvents r;

		auto it = std::find(m_profile_kernels.begin(), m_profile_kernels.end(), kernel);
		while(it != m_profile_kernels.end()){
			profile_info p = report_profile(it->event);

			tKernelEvent e(*it);
			e.time = p.runtime();
			e.queued = p.timetostart();

			r.push_back(e);

			it = std::find(it, m_profile_kernels.end(), kernel);
		}

		return r;
	}

	tKernelEvents getKernelPerfs() const {

		tKernelEvents r;

		for(auto & t : m_profile_kernels){
			profile_info p = report_profile(t.event);

			tKernelEvent e(t);
			e.time = p.runtime();
			e.queued = p.timetostart();

			r.push_back(e);
		}

		return r;
	}

	void clearPerfCounters() {
		m_profile_kernels.clear();
		m_profile_reads.clear();
		m_profile_writes.clear();
	}

	const cl_command_queue default_queue() const
	{
		return queue_;
	}

	const cl_context native_context() const
	{
		return context_;
	}

	const cl_device_id native_device() const
	{
		return m_devices.get()[0];
	}

	const cl_ulong getMaxAllocSize() const {

		cl_ulong maxAlloc;
		ERROR_HANDLER(
			ERROR = clGetDeviceInfo(native_device(), CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(cl_ulong), &maxAlloc, NULL));

		return maxAlloc;
	}

	const cl_ulong getGlobalMemSize() const {

		cl_ulong memSize;
		ERROR_HANDLER(
				ERROR = clGetDeviceInfo(native_device(), CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &memSize, NULL));

		return memSize;
	}

	const cl_ulong getLocalMemSize() const {

		cl_ulong memSize;
		ERROR_HANDLER(
				ERROR = clGetDeviceInfo(native_device(), CL_DEVICE_LOCAL_MEM_SIZE, sizeof(cl_ulong), &memSize, NULL));

		return memSize;
	}

private:

	context_settings m_settings;

	cl_context context_;
	cl_command_queue queue_;
	cl_device_id sub_dev_id_;

	std::unique_ptr<cl_device_id> m_devices;

	boost::ptr_vector<source_modifier> m_source_modifier;

	mutable tIOEvents m_profile_reads;
	mutable tIOEvents m_profile_writes;
	mutable tKernelEvents m_profile_kernels;

	mutable std::set<cl_mem> allocatedMemory;

};

}
