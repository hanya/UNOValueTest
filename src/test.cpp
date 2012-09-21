
#include "test.hpp"

using ::rtl::OUString;

using ::com::sun::star::uno::XComponentContext;
using ::com::sun::star::uno::Sequence;
using ::com::sun::star::uno::Reference;
using ::com::sun::star::uno::RuntimeException;
using ::com::sun::star::uno::Exception;
using ::com::sun::star::uno::UNO_QUERY;


namespace mytools {

ValueTest::ValueTest( Reference< ::com::sun::star::uno::XComponentContext > const &xComponentContext )
    : m_bInitialized(0), 
      m_CharValue(0)
    , m_BooleanValue(false)
    , m_ByteValue(0)
    , m_ShortValue(0)
    , m_UnsignedShortValue(0)
    , m_LongValue(0)
    , m_UnsignedLongValue(0)
    , m_HyperValue(0)
    , m_UnsignedHyperValue(0)
    , m_FloatValue(0)
    , m_DoubleValue(0)
    , m_StringValue()
    , m_TypeValue()
    , m_Interface()
{
    
}

ValueTest::~ValueTest()
{
}

Reference< ::com::sun::star::uno::XInterface > ValueTest::create( const Reference< XComponentContext > &xComponentContext )
{
    return static_cast< ::cppu::OWeakObject* >(new ValueTest( xComponentContext ));
}

// XInitialization
void SAL_CALL ValueTest::initialize( const Sequence< ::com::sun::star::uno::Any >& aArguments ) throw (Exception, RuntimeException)
{
    if ( m_bInitialized )
        throw ::com::sun::star::ucb::AlreadyInitializedException( OUString(), *this );
    
    if ( aArguments.getLength() != 1 )
        throw RuntimeException(OUString(), Reference< XInterface >());
    
    Values values;
    if ( aArguments[0] >>= values )
    {
        m_CharValue = values.CharValue;
        m_BooleanValue = values.BooleanValue;
        m_ByteValue = values.ByteValue;
        m_ShortValue = values.ShortValue;
        m_UnsignedShortValue = values.UnsignedShortValue;
        m_LongValue = values.LongValue;
        m_UnsignedLongValue = values.UnsignedLongValue;
        m_HyperValue = values.HyperValue;
        m_UnsignedHyperValue = values.UnsignedHyperValue;
        m_FloatValue = values.FloatValue;
        m_DoubleValue = values.DoubleValue;
        m_StringValue = OUString(values.StringValue);
        m_TypeValue = ::com::sun::star::uno::Type(values.TypeValue);
        
        m_bInitialized = 1;
    }
    else
        throw RuntimeException(OUString(), Reference< XInterface >());
}


void SAL_CALL ValueTest::getVoid(  ) throw (::com::sun::star::uno::RuntimeException)
{
    
}
::sal_Unicode SAL_CALL ValueTest::getChar(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_CharValue;
}
::sal_Bool SAL_CALL ValueTest::getBoolean(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_BooleanValue;
}
::sal_Int8 SAL_CALL ValueTest::getByte(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_ByteValue;
}
::sal_Int16 SAL_CALL ValueTest::getShort(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_ShortValue;
}
::sal_uInt16 SAL_CALL ValueTest::getUnsignedShort(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_UnsignedShortValue;
}
::sal_Int32 SAL_CALL ValueTest::getLong(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_LongValue;
}
::sal_uInt32 SAL_CALL ValueTest::getUnsignedLong(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_UnsignedLongValue;
}
::sal_Int64 SAL_CALL ValueTest::getHyper(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_HyperValue;
}
::sal_uInt64 SAL_CALL ValueTest::getUnsignedHyper(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_UnsignedHyperValue;
}
float SAL_CALL ValueTest::getFloat(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_FloatValue;
}
double SAL_CALL ValueTest::getDouble(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_DoubleValue;
}
::rtl::OUString SAL_CALL ValueTest::getString(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_StringValue;
}
::com::sun::star::uno::Type SAL_CALL ValueTest::getType(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_TypeValue;
}
::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > ValueTest::getInterface(  ) throw (::com::sun::star::uno::RuntimeException)
{
    return m_Interface;
}
void SAL_CALL ValueTest::setChar( ::sal_Unicode c ) throw (::com::sun::star::uno::RuntimeException)
{
    m_CharValue = c;
}
void SAL_CALL ValueTest::setBoolean( ::sal_Bool b ) throw (::com::sun::star::uno::RuntimeException)
{
    m_BooleanValue = b;
}
void SAL_CALL ValueTest::setByte( ::sal_Int8 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_ByteValue = n;
}
void SAL_CALL ValueTest::setShort( ::sal_Int16 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_ShortValue = n;
}
void SAL_CALL ValueTest::setUnsignedShort( ::sal_uInt16 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_UnsignedShortValue = n;
}
void SAL_CALL ValueTest::setLong( ::sal_Int32 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_LongValue = n;
}
void SAL_CALL ValueTest::setUnsignedLong( ::sal_uInt32 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_UnsignedLongValue = n;
}
void SAL_CALL ValueTest::setHyper( ::sal_Int64 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_HyperValue = n;
}
void SAL_CALL ValueTest::setUnsignedHyper( ::sal_uInt64 n ) throw (::com::sun::star::uno::RuntimeException)
{
    m_UnsignedHyperValue = n;
}
void SAL_CALL ValueTest::setFloat( float f ) throw (::com::sun::star::uno::RuntimeException)
{
    m_FloatValue = f;
}
void SAL_CALL ValueTest::setDouble( double d ) throw (::com::sun::star::uno::RuntimeException)
{
    m_DoubleValue = d;
}
void SAL_CALL ValueTest::setString( const ::rtl::OUString& s ) throw (::com::sun::star::uno::RuntimeException)
{
    m_StringValue = OUString(s);
}
void SAL_CALL ValueTest::setType( const ::com::sun::star::uno::Type& t ) throw (::com::sun::star::uno::RuntimeException)
{
    m_TypeValue = ::com::sun::star::uno::Type(t);
}
void SAL_CALL ValueTest::setInterface( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > &rInterface ) throw (::com::sun::star::uno::RuntimeException)
{
    m_Interface = rInterface;
}


::sal_Bool SAL_CALL ValueTest::testOutParam(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        sal_Int32 i = 100;
        sal_Int32 v = 200;
        sal_Int32 u = 300;
        
        sal_Bool b = xValueTest->testParamMode(i, v, u);
        if (b && v == 400 && u == 500)
            return sal_True;
    }
    else
        return sal_False;
}


::sal_Bool SAL_CALL ValueTest::testParamMode( ::sal_Int32 i, ::sal_Int32& v, ::sal_Int32& u ) throw (::com::sun::star::uno::RuntimeException)
{
    return sal_False;
}


::sal_Bool SAL_CALL ValueTest::testOutParam2(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        sal_Int32 i = 100;
        sal_Int32 v = 200;
        sal_Int32 u = 300;
        
        xValueTest->testParamMode2(i, v, u);
        if (i == 400 && u == 500)
            return sal_True;
    }
    else
        return sal_False;
}


void SAL_CALL ValueTest::testParamMode2( ::sal_Int32 &i, ::sal_Int32 v, ::sal_Int32& u ) throw (::com::sun::star::uno::RuntimeException)
{
}


void SAL_CALL ValueTest::testRuntimeException(  ) throw (::com::sun::star::uno::RuntimeException)
{
    throw ::com::sun::star::uno::RuntimeException(OUString(RTL_CONSTASCII_USTRINGPARAM("exception?")), Reference< XInterface >());
}

void SAL_CALL ValueTest::testNoSuchElementException(  ) throw (::com::sun::star::container::NoSuchElementException, ::com::sun::star::uno::RuntimeException)
{
    throw ::com::sun::star::container::NoSuchElementException(OUString(RTL_CONSTASCII_USTRINGPARAM("exception!")), Reference< XInterface >());
}

::sal_Bool SAL_CALL ValueTest::testThrowException(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        try
        {
            xValueTest->testRuntimeException();
        }
        catch (::com::sun::star::uno::RuntimeException &e)
        {
            (void)e;
            return sal_True;
        }
    }
    return sal_False;
}

::sal_Bool SAL_CALL ValueTest::testNoMethod(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        try
        {
            xValueTest->testNoMethod();
        }
        catch (::com::sun::star::uno::RuntimeException &e)
        {
            (void)e;
            return sal_True;
        }
    }
    return sal_False;
}

::sal_Bool SAL_CALL ValueTest::testNoAttribute(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        try
        {
            xValueTest->getIntValue();
        }
        catch (::com::sun::star::uno::RuntimeException &e)
        {
            (void)e;
            return sal_True;
        }
    }
    return sal_False;
}

::sal_Bool SAL_CALL ValueTest::testAttribute(  ) throw (::com::sun::star::uno::RuntimeException)
{
    Reference< XValueTest > xValueTest(m_Interface, UNO_QUERY);
    if (xValueTest.is())
    {
        const sal_Int32 n = 100;
        xValueTest->setIntValue(n);
        if (xValueTest->getIntValue() == n)
            return sal_True;
    }
    return sal_False;
}



// Attributes

::sal_Int32 SAL_CALL ValueTest::getIntValue() throw (::com::sun::star::uno::RuntimeException)
{
}

void SAL_CALL ValueTest::setIntValue( ::sal_Int32 _intvalue ) throw (::com::sun::star::uno::RuntimeException)
{
}





// XServiceInfo

OUString ValueTest::getImplementationName_Static() 
{
    return OUString::createFromAscii(IMPLEMENTATION_NAME);
}

Sequence< OUString > ValueTest::getSupportedServiceNames_Static() 
{
    Sequence< OUString > aRet(1);
    aRet[0] = OUString::createFromAscii(SERVICE_NAME);
    return aRet;
}


::rtl::OUString SAL_CALL ValueTest::getImplementationName() 
                throw (RuntimeException)
{
    return ValueTest::getImplementationName_Static();
}

::sal_Bool SAL_CALL ValueTest::supportsService( const ::rtl::OUString& ServiceName ) 
                throw (RuntimeException)
{
    return ServiceName.equalsAscii(SERVICE_NAME);
}

Sequence< ::rtl::OUString > SAL_CALL ValueTest::getSupportedServiceNames() 
                throw (RuntimeException)
{
    return ValueTest::getSupportedServiceNames_Static();
}

} // namespace
