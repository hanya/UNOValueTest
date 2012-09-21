
#ifndef _TEST_HPP_
#define _TEST_HPP_ 1

#include <cppuhelper/implbase3.hxx>

#include <com/sun/star/lang/XInitialization.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/ucb/AlreadyInitializedException.hpp>

#include "mytools/XValueTest.hpp"
#include "mytools/Values.hpp"

#define IMPLEMENTATION_NAME "mytools.ValueTest"
#define SERVICE_NAME "mytools.ValueTest"

namespace mytools {

class ValueTest : 
    public ::cppu::WeakImplHelper3
        <
            ::mytools::XValueTest, 
            ::com::sun::star::lang::XInitialization, 
            ::com::sun::star::lang::XServiceInfo
        >
{
private:
    bool m_bInitialized;
    sal_Unicode m_CharValue;
    sal_Bool m_BooleanValue;
    sal_Int8 m_ByteValue;
    sal_Int16 m_ShortValue;
    sal_uInt16 m_UnsignedShortValue;
    sal_Int32 m_LongValue;
    sal_uInt32 m_UnsignedLongValue;
    sal_Int64 m_HyperValue;
    sal_uInt64 m_UnsignedHyperValue;
    float m_FloatValue;
    double m_DoubleValue;
    ::rtl::OUString m_StringValue;
    ::com::sun::star::uno::Type m_TypeValue;
    ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > m_Interface;
    
public:
    ValueTest( ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext > const &xComponentContext );
    ~ValueTest();
    
    
    static ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > create( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext > &xComponentContext);
    
    
    // XInitialization
    virtual void SAL_CALL initialize( const ::com::sun::star::uno::Sequence< ::com::sun::star::uno::Any >& aArguments ) throw (::com::sun::star::uno::Exception, ::com::sun::star::uno::RuntimeException);

    // XValueTest
    virtual void SAL_CALL getVoid(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Unicode SAL_CALL getChar(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL getBoolean(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Int8 SAL_CALL getByte(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Int16 SAL_CALL getShort(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_uInt16 SAL_CALL getUnsignedShort(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Int32 SAL_CALL getLong(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_uInt32 SAL_CALL getUnsignedLong(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Int64 SAL_CALL getHyper(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_uInt64 SAL_CALL getUnsignedHyper(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual float SAL_CALL getFloat(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual double SAL_CALL getDouble(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::rtl::OUString SAL_CALL getString(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::com::sun::star::uno::Type SAL_CALL getType(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > getInterface(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setChar( ::sal_Unicode c ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setBoolean( ::sal_Bool b ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setByte( ::sal_Int8 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setShort( ::sal_Int16 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setUnsignedShort( ::sal_uInt16 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setLong( ::sal_Int32 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setUnsignedLong( ::sal_uInt32 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setHyper( ::sal_Int64 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setUnsignedHyper( ::sal_uInt64 n ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setFloat( float f ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setDouble( double d ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setString( const ::rtl::OUString& s ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setType( const ::com::sun::star::uno::Type& t ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setInterface( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > &rInterface ) throw (::com::sun::star::uno::RuntimeException);
    
    virtual ::sal_Bool SAL_CALL testOutParam(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL testParamMode( ::sal_Int32 i, ::sal_Int32& v, ::sal_Int32& u ) throw (::com::sun::star::uno::RuntimeException);
    
    virtual ::sal_Bool SAL_CALL testOutParam2(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL testParamMode2( ::sal_Int32 &i, ::sal_Int32 v, ::sal_Int32 &u ) throw (::com::sun::star::uno::RuntimeException);
    
    virtual void SAL_CALL testRuntimeException(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL testNoSuchElementException(  ) throw (::com::sun::star::container::NoSuchElementException, ::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL testThrowException(  ) throw (::com::sun::star::uno::RuntimeException);
    
    virtual ::sal_Bool SAL_CALL testNoMethod(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL testNoAttribute(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL testAttribute(  ) throw (::com::sun::star::uno::RuntimeException);

    // Attributes
    virtual ::sal_Int32 SAL_CALL getIntValue() throw (::com::sun::star::uno::RuntimeException);
    virtual void SAL_CALL setIntValue( ::sal_Int32 _intvalue ) throw (::com::sun::star::uno::RuntimeException);

    
    // XServiceInfo
    virtual ::rtl::OUString SAL_CALL getImplementationName(  ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::sal_Bool SAL_CALL supportsService( const ::rtl::OUString& ServiceName ) throw (::com::sun::star::uno::RuntimeException);
    virtual ::com::sun::star::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames(  ) throw (::com::sun::star::uno::RuntimeException);
    
    
    static ::rtl::OUString SAL_CALL getImplementationName_Static();
    static ::com::sun::star::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames_Static();
    
};
    
}

#endif
