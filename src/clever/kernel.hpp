//Auto-generated file clever/src/clever/code_gen/gen_kernelfile.py
#pragma once
#include "builtin.hpp"
#include "kernel_base.hpp"
#include "icontext.hpp"
#include "error.hpp"
#include <string>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace clever
{

template< typename T1 >
class kernel_base1 : public clever::kernel_base
{
public:
    kernel_base1( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base1(){}
    cl_event run( T1 data1, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1, const clever::range & globalRange) const
    {
        return run( data1, globalRange, null_range() );
    }
    void operator()( T1 data1, range const& globalRange, range const& localRange )
    {
        run ( data1, globalRange, localRange );
    }
    void operator()( T1 data1, range const& globalRange )
    {
        run ( data1, globalRange );
    }
};


#define APPLY_DEFINES1_CLASS(  NAME, TYPE1 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base1< TYPE1 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base1< TYPE1  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL1_CLASS(  NAME,  TYPE1 , FUNCTION ) APPLY_DEFINES1_CLASS(  NAME,  TYPE1 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL1_CLASSP(  NAME,  TYPE1 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES1_CLASS(  NAME,  TYPE1 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2 >
class kernel_base2 : public clever::kernel_base
{
public:
    kernel_base2( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base2(){}
    cl_event run( T1 data1,T2 data2, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2, const clever::range & globalRange) const
    {
        return run( data1,data2, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2, range const& globalRange, range const& localRange )
    {
        run ( data1,data2, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2, range const& globalRange )
    {
        run ( data1,data2, globalRange );
    }
};


#define APPLY_DEFINES2_CLASS(  NAME, TYPE1,TYPE2 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base2< TYPE1,TYPE2 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base2< TYPE1,TYPE2  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION ) APPLY_DEFINES2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL2_CLASSP(  NAME,  TYPE1,TYPE2 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES2_CLASS(  NAME,  TYPE1,TYPE2 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3 >
class kernel_base3 : public clever::kernel_base
{
public:
    kernel_base3( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base3(){}
    cl_event run( T1 data1,T2 data2,T3 data3, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3, const clever::range & globalRange) const
    {
        return run( data1,data2,data3, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3, range const& globalRange )
    {
        run ( data1,data2,data3, globalRange );
    }
};


#define APPLY_DEFINES3_CLASS(  NAME, TYPE1,TYPE2,TYPE3 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base3< TYPE1,TYPE2,TYPE3 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base3< TYPE1,TYPE2,TYPE3  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION ) APPLY_DEFINES3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL3_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES3_CLASS(  NAME,  TYPE1,TYPE2,TYPE3 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4 >
class kernel_base4 : public clever::kernel_base
{
public:
    kernel_base4( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base4(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4, range const& globalRange )
    {
        run ( data1,data2,data3,data4, globalRange );
    }
};


#define APPLY_DEFINES4_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base4< TYPE1,TYPE2,TYPE3,TYPE4 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base4< TYPE1,TYPE2,TYPE3,TYPE4  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION ) APPLY_DEFINES4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL4_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES4_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5 >
class kernel_base5 : public clever::kernel_base
{
public:
    kernel_base5( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base5(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5, globalRange );
    }
};


#define APPLY_DEFINES5_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base5< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base5< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION ) APPLY_DEFINES5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL5_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES5_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6 >
class kernel_base6 : public clever::kernel_base
{
public:
    kernel_base6( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base6(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6, globalRange );
    }
};


#define APPLY_DEFINES6_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base6< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base6< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION ) APPLY_DEFINES6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL6_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES6_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7 >
class kernel_base7 : public clever::kernel_base
{
public:
    kernel_base7( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base7(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7, globalRange );
    }
};


#define APPLY_DEFINES7_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base7< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base7< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION ) APPLY_DEFINES7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL7_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES7_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8 >
class kernel_base8 : public clever::kernel_base
{
public:
    kernel_base8( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base8(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8, globalRange );
    }
};


#define APPLY_DEFINES8_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base8< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base8< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION ) APPLY_DEFINES8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL8_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES8_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9 >
class kernel_base9 : public clever::kernel_base
{
public:
    kernel_base9( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base9(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9, globalRange );
    }
};


#define APPLY_DEFINES9_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base9< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base9< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION ) APPLY_DEFINES9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL9_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES9_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10 >
class kernel_base10 : public clever::kernel_base
{
public:
    kernel_base10( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base10(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10, globalRange );
    }
};


#define APPLY_DEFINES10_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base10< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base10< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION ) APPLY_DEFINES10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL10_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES10_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11 >
class kernel_base11 : public clever::kernel_base
{
public:
    kernel_base11( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base11(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11, globalRange );
    }
};


#define APPLY_DEFINES11_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base11< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base11< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION ) APPLY_DEFINES11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL11_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES11_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12 >
class kernel_base12 : public clever::kernel_base
{
public:
    kernel_base12( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base12(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12, globalRange );
    }
};


#define APPLY_DEFINES12_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base12< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base12< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION ) APPLY_DEFINES12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL12_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES12_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13 >
class kernel_base13 : public clever::kernel_base
{
public:
    kernel_base13( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base13(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13, globalRange );
    }
};


#define APPLY_DEFINES13_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base13< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base13< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION ) APPLY_DEFINES13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL13_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES13_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14 >
class kernel_base14 : public clever::kernel_base
{
public:
    kernel_base14( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base14(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14, globalRange );
    }
};


#define APPLY_DEFINES14_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base14< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base14< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION ) APPLY_DEFINES14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL14_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES14_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15 >
class kernel_base15 : public clever::kernel_base
{
public:
    kernel_base15( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base15(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15, globalRange );
    }
};


#define APPLY_DEFINES15_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base15< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base15< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION ) APPLY_DEFINES15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL15_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES15_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16 >
class kernel_base16 : public clever::kernel_base
{
public:
    kernel_base16( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base16(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16, globalRange );
    }
};


#define APPLY_DEFINES16_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base16< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base16< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION ) APPLY_DEFINES16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL16_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES16_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17 >
class kernel_base17 : public clever::kernel_base
{
public:
    kernel_base17( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base17(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17, globalRange );
    }
};


#define APPLY_DEFINES17_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base17< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base17< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION ) APPLY_DEFINES17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL17_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES17_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18 >
class kernel_base18 : public clever::kernel_base
{
public:
    kernel_base18( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base18(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18, globalRange );
    }
};


#define APPLY_DEFINES18_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base18< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base18< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION ) APPLY_DEFINES18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL18_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES18_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19 >
class kernel_base19 : public clever::kernel_base
{
public:
    kernel_base19( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base19(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19, globalRange );
    }
};


#define APPLY_DEFINES19_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base19< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base19< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION ) APPLY_DEFINES19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL19_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES19_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20 >
class kernel_base20 : public clever::kernel_base
{
public:
    kernel_base20( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base20(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20, globalRange );
    }
};


#define APPLY_DEFINES20_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base20< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base20< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION ) APPLY_DEFINES20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL20_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES20_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21 >
class kernel_base21 : public clever::kernel_base
{
public:
    kernel_base21( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base21(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21, globalRange );
    }
};


#define APPLY_DEFINES21_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base21< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base21< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION ) APPLY_DEFINES21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL21_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES21_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22 >
class kernel_base22 : public clever::kernel_base
{
public:
    kernel_base22( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base22(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22, globalRange );
    }
};


#define APPLY_DEFINES22_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base22< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base22< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION ) APPLY_DEFINES22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL22_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES22_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23 >
class kernel_base23 : public clever::kernel_base
{
public:
    kernel_base23( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base23(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23, globalRange );
    }
};


#define APPLY_DEFINES23_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base23< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base23< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION ) APPLY_DEFINES23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL23_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES23_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24 >
class kernel_base24 : public clever::kernel_base
{
public:
    kernel_base24( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base24(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24, globalRange );
    }
};


#define APPLY_DEFINES24_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base24< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base24< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION ) APPLY_DEFINES24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL24_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES24_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25 >
class kernel_base25 : public clever::kernel_base
{
public:
    kernel_base25( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base25(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25, globalRange );
    }
};


#define APPLY_DEFINES25_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base25< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base25< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION ) APPLY_DEFINES25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL25_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES25_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26 >
class kernel_base26 : public clever::kernel_base
{
public:
    kernel_base26( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base26(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26, globalRange );
    }
};


#define APPLY_DEFINES26_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base26< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base26< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION ) APPLY_DEFINES26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL26_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES26_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27 >
class kernel_base27 : public clever::kernel_base
{
public:
    kernel_base27( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base27(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27, globalRange );
    }
};


#define APPLY_DEFINES27_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base27< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base27< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION ) APPLY_DEFINES27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL27_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES27_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28 >
class kernel_base28 : public clever::kernel_base
{
public:
    kernel_base28( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base28(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28, globalRange );
    }
};


#define APPLY_DEFINES28_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base28< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base28< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION ) APPLY_DEFINES28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL28_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES28_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29 >
class kernel_base29 : public clever::kernel_base
{
public:
    kernel_base29( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base29(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29, globalRange );
    }
};


#define APPLY_DEFINES29_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base29< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base29< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION ) APPLY_DEFINES29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL29_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES29_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30 >
class kernel_base30 : public clever::kernel_base
{
public:
    kernel_base30( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base30(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30, globalRange );
    }
};


#define APPLY_DEFINES30_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base30< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base30< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION ) APPLY_DEFINES30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL30_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES30_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30,typename T31 >
class kernel_base31 : public clever::kernel_base
{
public:
    kernel_base31( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base31(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
plist.push_back( parameter_factory< T31>::parameter( data31 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31, globalRange );
    }
};


#define APPLY_DEFINES31_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base31< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base31< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION ) APPLY_DEFINES31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL31_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES31_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31 , FUNCTION, #FUNCTION, PREPROCESSOR ) 


template< typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19,typename T20,typename T21,typename T22,typename T23,typename T24,typename T25,typename T26,typename T27,typename T28,typename T29,typename T30,typename T31,typename T32 >
class kernel_base32 : public clever::kernel_base
{
public:
    kernel_base32( const std::string& name, const clever::icontext& context, const std::string& sources, const std::string& preprocessor )
        : kernel_base(name, context, sources, preprocessor) 
    {
        assert ( kernel_ );
    }
    virtual ~kernel_base32(){}
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, const clever::range & globalRange, const clever::range & localRange ) const
    {
        kernel_parameter_list plist;
        plist.push_back( parameter_factory< T1>::parameter( data1 ));
plist.push_back( parameter_factory< T2>::parameter( data2 ));
plist.push_back( parameter_factory< T3>::parameter( data3 ));
plist.push_back( parameter_factory< T4>::parameter( data4 ));
plist.push_back( parameter_factory< T5>::parameter( data5 ));
plist.push_back( parameter_factory< T6>::parameter( data6 ));
plist.push_back( parameter_factory< T7>::parameter( data7 ));
plist.push_back( parameter_factory< T8>::parameter( data8 ));
plist.push_back( parameter_factory< T9>::parameter( data9 ));
plist.push_back( parameter_factory< T10>::parameter( data10 ));
plist.push_back( parameter_factory< T11>::parameter( data11 ));
plist.push_back( parameter_factory< T12>::parameter( data12 ));
plist.push_back( parameter_factory< T13>::parameter( data13 ));
plist.push_back( parameter_factory< T14>::parameter( data14 ));
plist.push_back( parameter_factory< T15>::parameter( data15 ));
plist.push_back( parameter_factory< T16>::parameter( data16 ));
plist.push_back( parameter_factory< T17>::parameter( data17 ));
plist.push_back( parameter_factory< T18>::parameter( data18 ));
plist.push_back( parameter_factory< T19>::parameter( data19 ));
plist.push_back( parameter_factory< T20>::parameter( data20 ));
plist.push_back( parameter_factory< T21>::parameter( data21 ));
plist.push_back( parameter_factory< T22>::parameter( data22 ));
plist.push_back( parameter_factory< T23>::parameter( data23 ));
plist.push_back( parameter_factory< T24>::parameter( data24 ));
plist.push_back( parameter_factory< T25>::parameter( data25 ));
plist.push_back( parameter_factory< T26>::parameter( data26 ));
plist.push_back( parameter_factory< T27>::parameter( data27 ));
plist.push_back( parameter_factory< T28>::parameter( data28 ));
plist.push_back( parameter_factory< T29>::parameter( data29 ));
plist.push_back( parameter_factory< T30>::parameter( data30 ));
plist.push_back( parameter_factory< T31>::parameter( data31 ));
plist.push_back( parameter_factory< T32>::parameter( data32 ));
 
        assert ( kernel_ );
        return context_.execute_params( plist ,  *kernel_, globalRange, localRange );
    }
    cl_event run( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, const clever::range & globalRange) const
    {
        return run( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31,data32, globalRange, null_range() );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, range const& globalRange, range const& localRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31,data32, globalRange, localRange );
    }
    void operator()( T1 data1,T2 data2,T3 data3,T4 data4,T5 data5,T6 data6,T7 data7,T8 data8,T9 data9,T10 data10,T11 data11,T12 data12,T13 data13,T14 data14,T15 data15,T16 data16,T17 data17,T18 data18,T19 data19,T20 data20,T21 data21,T22 data22,T23 data23,T24 data24,T25 data25,T26 data26,T27 data27,T28 data28,T29 data29,T30 data30,T31 data31,T32 data32, range const& globalRange )
    {
        run ( data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,data31,data32, globalRange );
    }
};


#define APPLY_DEFINES32_CLASS(  NAME, TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, SOURCES, PREPROCESSOR ) \
class NAME##_CLASS : public clever::kernel_base32< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 >                   \
{                                                                           \
public:                                                                     \
    explicit NAME##_CLASS( const clever::icontext& context )              \
                : clever::kernel_base32< TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32  >( #NAME, context, SOURCES, PREPROCESSOR )  \
             {                                                              \
             }                                                              \
    virtual ~NAME##_CLASS() {}                                              \
private:                                                                    \
    FUNCTION                                                               \
} NAME                                                                      
#define KERNEL32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION ) APPLY_DEFINES32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, #FUNCTION, "" ) 
#define KERNEL32_CLASSP(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , PREPROCESSOR, FUNCTION ) APPLY_DEFINES32_CLASS(  NAME,  TYPE1,TYPE2,TYPE3,TYPE4,TYPE5,TYPE6,TYPE7,TYPE8,TYPE9,TYPE10,TYPE11,TYPE12,TYPE13,TYPE14,TYPE15,TYPE16,TYPE17,TYPE18,TYPE19,TYPE20,TYPE21,TYPE22,TYPE23,TYPE24,TYPE25,TYPE26,TYPE27,TYPE28,TYPE29,TYPE30,TYPE31,TYPE32 , FUNCTION, #FUNCTION, PREPROCESSOR ) 



}
