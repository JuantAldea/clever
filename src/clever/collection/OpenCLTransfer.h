#pragma once

#include "Collection.hpp"
#include <iostream>
namespace clever
{

template<typename THead = NullData, typename ... TTail>
class OpenCLTransfer: public OpenCLTransfer<TTail ...>  //, private boost::noncopyable
{
public:
    typedef Collection<THead, TTail ...> dataitems_type;
    typedef Collection<TTail ...> dataitems_tail;

    typedef OpenCLTransfer<TTail ...> inherited;

    typedef TypeToCLType<typename THead::data_type> conversion_type;
    typedef typename conversion_type::cl_type this_cl_type;
    const size_t item_size = sizeof(this_cl_type);
    OpenCLTransfer() :
        m_homeContext(nullptr), m_buffer(0), m_transferedBufferSize(0)
    {
    }

    ~OpenCLTransfer()
    {
        if (m_homeContext != nullptr) {
            m_homeContext->release_buffer(m_buffer);
        }
        m_homeContext = nullptr;   
    }

    void release(dataitems_type const& collection)
    {
        if (m_homeContext != nullptr) {
            m_homeContext->release_buffer(m_buffer);
        }
        m_homeContext = nullptr;
        inherited::release(collection);
    }
    

    void initBuffers(context & c, dataitems_type const& collection)
    {
        // init the buffer for the head

        const size_t bufferSize = sizeof(this_cl_type) * collection.size();
        m_buffer = c.create_buffer(bufferSize);

        m_homeContext = &c;

        //std::cout << "Initializing buffer of type " << conversion_type::str()
        //          << " of size " << bufferSize << " bytes" << std::endl;

        // handle the tail of the collection
        inherited::initBuffers(c, collection);
    }

    void toDevice(context & c, dataitems_type & collection)
    {
        c.transfer_to_buffer(m_buffer, collection.getRawBuffer().data(),
                             sizeof(this_cl_type) * collection.size());

        /*  std::cout << "writing value " << collection.getRawBuffer().front()
         << std::endl;*/

        // todo: not so nice to store this here, maybe find a better way
        m_transferedBufferSize = collection.size();

        // will only operate on the tail
        inherited::toDevice(c, collection);
    }

    void fromDevice(context & c, dataitems_type & collection, std::vector<cl_event> * waitList = NULL)
    {
        if (waitList == NULL)
            c.transfer_from_buffer(m_buffer, collection.getRawBuffer().data(),
                                   sizeof(this_cl_type) * collection.size());
        else
            //wait list not empty
            c.transfer_from_buffer(m_buffer, collection.getRawBuffer().data(),
                                   sizeof(this_cl_type) * collection.size(), waitList->size(), waitList->data());

        /*std::cout << "read value " << collection.getRawBuffer().front()
         << std::endl;*/

        // will only operate on the tail
        inherited::fromDevice(c, collection, waitList);
    }

    // necessary to unhide the  methods of the base classes
    using inherited::buffer;

    cl_mem buffer(THead) const
    {
        return m_buffer;
    }

    // can only be called once a buffer has been transfered
    range defaultRange() const
    {
        return range(m_transferedBufferSize);
    }

    // todo: check functions which can tell wether a buffer has been allocated / transfered to hardware

    /*
     *  std::vector <float> float_in ( elements, val );
     std::vector <float> float_out ( elements, 0.0f );

     cl_mem buffer = context.create_buffer (  sizeof(cl_float) * elements );

     context.transfer_from_buffer  ( buffer, &float_in.front(),  sizeof(cl_float) * elements );
     context.transfer_to_buffer  ( buffer, &float_out.front(),  sizeof(cl_float) * elements );
     context.release_buffer(buffer);
     *
     */

// todo: can we do const here ?
private:
    context * m_homeContext;
    cl_mem m_buffer;
    size_t m_transferedBufferSize;
};

template<>
class OpenCLTransfer<> : private boost::noncopyable
{
public:
    void initBuffers(context&, Collection<> const&)
    {
    }
    void toDevice(context&, Collection<> const&)
    {
    }
    void fromDevice(context&, Collection<> const&, std::vector<cl_event> * = NULL)
    {
    }
    void release(Collection<> const&)
    {
    }
    void buffer() const;
};

}


