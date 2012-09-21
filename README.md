
This is small extension for testing get/set value through 
language bridge implementation for OpenOffice kind.

How to use

Set up SDK and set its environmental variables.
make
Install generated package through Extension Manager.
The service can be used like as follows. See idl file more detail.

    Sub Foo
        ' default value
        s = CreateUnoStruct("mytools.Values")
        s.BooleanValue = True
        s.StringValue = "foobar"

        t = CreateUnoServiceWithArguments("mytools.ValueTest", Array(s))

        v = t.getBoolean()
        v1 = t.getString()
    End Sub
