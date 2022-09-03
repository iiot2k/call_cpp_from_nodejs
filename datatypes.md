# Datatypes and Methods in node-addon-api
🏠[To Home Page](README.md)

I list here the most important ***node-addon-api*** classes and methods.<br>
For complete detail, look in [node-addon-api📌](https://github.com/nodejs/node-addon-api) documentation.<br>

Assumption for examples:<br>
- With ``using namespace Napi;``
- Using ``CallbackInfo &info``
- Using ``Env env = info.Env();``

The ***Env*** and ***CallbackInfo*** are helper classes for handle calls,<br>
exceptions and environment context.<br> 

## ```Env```<br>
Class ***Env*** is the environment context of caller JavaScript.<br>

|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Value``|``Null()``|returns an null Value|
|``Value``|``Undefined()``|returns an undefined Value|
|``Object``|``Global()``|returns JavaScript global scope as Object|
|``bool``|``IsExceptionPending()``|check for pending exception|
|``Error``|``GetAndClearPendingException()``|clears pending exception and returns Error|
|``Value``|``RunScript(const char*)``|executes JavaScript code|
|``Value``|``RunScript(const std::string&)``|executes JavaScript code|

### examples
```c++
Value val1 = env.Null();             // creates null Value
Value val1 = env.RunScript("3 * 5"); // executes JavaScript code
return env.Undefined();              // returns undefined Value
```
## ```CallbackInfo```<br>
Class ***CallbackInfo*** contain all parameters and environment context<br>
stored on call from JavaScript.
<br>
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Env``|``Env()``|gets the environment context|
|``size_t``|``Length()``|gets the count of parameters as unsigned integer|
|``Value``|``[size_t]``|(operator) get the parameter with unsigned integer as index|

### examples 
```c++
Env env = info.Env();   // get environment context from CallbackInfo
if (info.Length() != 3) // checks the count of parameters
    ...
Value v1 = info[0];     // gets the first parameter as Value
```

## ``Value``<br>
Class **Value** is the base class of all JavaScript datatypes.<br>
Derived classes also inherit the properties and methods of **Value**.<br>
**Value** can contain any JavaScript datatypes ***Null***, ***Undefined***, ***Boolean***, ***Number***..<br>
### create 
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Value``|``Value::From(Env, ValueType)``|(static) creates from C++ ***ValueType***|

Where ``ValueType`` is:<br>
```c++
bool, IntType, float, double, const char*, const char16_t*, std::string, std::u16string, Value 
```

Where ``IntType`` is:<br>
```c++
uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, int64_t, size_t
```
### examples for create

```c++
Value val0;                                   // creates empty
Value txt1 = Value::From(env, "string");      // creates from string UTF-8
Value txt2 = Value::From(env, u"caractères"); // creates from string UTF-16
Value pi = Value::From(env, 3.14);            // creates from double
Value count = Value::From(env, uint32_t(8));  // creates from uint32_t
return Value::From(env, true);                // returns with bool
return Value::From(env, "ok");                // returns with const char* UTF-8
```
### compare
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``==``|(operator) compare strict equals|
|``bool``|``!=``|(operator) compare not strict equals|
|``bool``|``StrictEquals(Value)``|compare strict equals|

### examples for compare
```c++
if (txt1 != txt2) // compares for not strict equals (here true)
    ...

if (pi.StrictEquals(txt2)) // compares for strict equals (here false)
    ...
```
### check datatype
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``IsEmpty()``|checks for Empty (uninitialized)|
|``bool``|``IsUndefined()``|checks for Undefined|
|``bool``|``IsNull()``|checks for Null|
|``bool``|``IsBoolean()``|checks for Boolean|
|``bool``|``IsNumber()``|checks for Number|
|``bool``|``IsString()``|checks for String|
|``bool``|``IsObject()``|checks for Object|
|``bool``|``IsArray()``|checks for Array|
|``bool``|``IsBuffer() ``|checks for Buffer|
|``bool``|``IsArrayBuffer()``|checks for ArrayBuffer|
|``bool``|``IsFunction()``|checks for Function|
|``napi_valuetype``|``Type()``|returns the datatype as enum [napi_valuetype](https://nodejs.org/api/n-api.html#napi_valuetype)|

### example for check datatype
```c++
if (!info[0].IsBoolean() || !info[1].IsNumber()) // check parameters datatype
    ...

switch(info[1].Type()) // execute code depends of datatype of parameter
{
    case napi_valuetype::napi_boolean: // Boolean
        ...
}
```
### cast to derived class
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Boolean``|``ToBoolean()``|cast to Boolean|
|``Number``|``ToNumber()``|cast to Number|
|``String``|``ToString()``|cast to String|
|``Object``|``ToObject()``|cast to Object|
|``DataType``|``As<DataType>()``|cast to ***DataType***|

Where ``DataType`` is:<br>
```JavaScript
Boolean, Number, String, Object, Array, Buffer, ArrayBuffer, Function ..
```

Return ``DataType`` and parameter ``DataType`` must same. 
### examples for cast to derived class
```c++
Boolean isok = info[0].ToBoolean(); // cast parameter to Boolean
Number cnt = info[1].As<Number>();  // cast parameter to Number
String str1 = txt1.ToString();      // cast to String 
```
## ``Boolean``<br>
Class ***Boolean*** is derived from class ***Value***.<br>
### create
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Boolean``|``Boolean::New(Env, bool)``|(static) creates from bool|

### example for create
```c++
Boolean bval0;                           // creates empty
Boolean bval1 = Boolean::New(env, true); // creates from bool
Boolean bval2 = info[1].As<Boolean>();   // creates from parameter
return Boolean::New(env, false);         // returns with bool
return bval1;                            // returns Boolean
```

### get C++ value
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``Value()``|get bool value|
|``bool``|bool()|(cast operator) get bool value|

### example for get C++ value
```c++
bool b1 = info[0].As<Boolean>().Value(); // get parameter as bool
bool b2 = info[1].ToBoolean().Value();   // get parameter as bool
bool b3 = info[2].ToBoolean();           // get parameter as bool with cast
bool b4 = bval1.Value();                 // get as bool
bool b4 = bval1;                         // get as bool with cast
```
## ```Number```<br>
Class ***Number*** is derived from class ***Value***.<br>
### create
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Number``|``Number::New(Env, double)``|(static) creates from double|

### example create
```c++
Number val0;                          // creates empty
Number val1 = Number::New(env, 3.14); // creates with double constant
Number val2 = info[1].As<Number>();   // creates from parameter
Number Val3 = info[2].ToNumber();     // creates from parameter
return Number::New(env, 0.15);        // returns with double constant
return val1;                          // returns Number
```
### get C++ value
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``int32_t``|``Int32Value()``|get int32_t value|
|``uint32_t``|``Uint32Value()``|get uint32_t value|
|``int64_t``|``Int64Value()``|get int64_t value|
|``float``|``FloatValue()``|get float value|
|``double``|``DoubleValue()``|get double value|
|``int32_t``|``int32_t()``|(cast operator) get int32_t value|
|``uint32_t``|``uint32_t()``|(cast operator) get uint32_t value|
|``int64_t``|``int64_t()``|(cast operator) get int64_t value|
|``float``|``float()``|(cast operator) get float value|
|``double``|``double()``|(cast operator) get double value|

### example get C++ value
```c++
uint32_t n1 = info[0].As<Number>().Uint32Value(); // get parameter as uint32_t
double n2 = info[1].ToNumber().DoubleValue();     // get parameter as double 
double n3 = info[2].ToNumber();                   // get parameter as double with cast
uint32_t n4 = info[3].As<Number>();               // get parameter as uint32_t with cast
int32_t n5 = val1.Int32Value();                   // get as int32_t
double n6 = val1;                                 // get as double with cast
```
## ```String```<br>
Class ***String*** is derived from ***Value::Name***.<br>
**String** can handle [std::string](https://cplusplus.com/reference/string/string/) (UTF-8)
and [std::u16string](https://cplusplus.com/reference/string/u16string/) (UTF-16).<br>
### create
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``String``|``String::New(Env, const char*)``|(static) creates from const char* (UTF-8)|
|``String``|``String::New(Env, const char16_t*)``|(static) creates from const char16_t* (UTF-16)|
|``String``|``String::New(Env, std::string &)``|(static) creates from std::string|
|``String``|``String::New(Env, std::u16string &)``|(static) creates from std::u16string|

### example create
```c++
String str0;                                   // creates empty 
String str1 = String::New(env, "string");      // creates from const char* (UTF-8)
String str2 = String::New(env, u"caractères"); // creates from const char16_t* (UTF-16)
String str3 = info[1].As<String>();            // creates from parameter 
String str4 = info[2].ToString();              // creates from parameter
return String::New(env, "Error");              // returns with const char* (UTF-8)
return str2;                                   // returns String
```
### get C++ value
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``std::string``|``Utf8Value()``|get as std::string (UTF-8)|
|``std::u16string``|``Utf16Value()``|get as std::u16string (UTF-16)|
|``std::string``|``std::string()``|(cast operator) get as std::string (UTF-8)|
|``std::u16string``|``std::u16string()``|(cast operator) get as std::u16string (UTF-16)|

### examples get C++ value
```c++
std::string std_str1 = info[1].As<String>().Utf8Value();   // get parameter as std::string
std::u16string std_str2 = info[2].ToString().Utf16Value(); // get parameter as std::u16string
std::string std_str3 = info[3].As<String>();               // get parameter as std::string with cast
std::u16string std_str4 = info[4].ToString();              // get parameter as std::u16string with cast
std::string std_str3 = str1.Utf8Value();                   // get std::string
std::u16string std_str4 = str2;                            // get std::u16string with cast
```
### get C++ value from std::string and std::u16string methods
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``const char*``|``Utf8Value().c_str()``|get const char* (UTF-8)|
|``const char16_t*``|``Utf16Value().c_str()``|get const char16_t* (UTF-16)|
|``size_t``|``Utf8Value().length()``|get string length as unsigned integer (UTF-8)|
|``size_t``|``Utf16Value().length()``|get string length as unsigned integer (UTF-16)|

### examples get C++ value from std::string and std::u16string methods
```c++
const char* pstr1 = info[1].ToString().Utf8Value().c_str();      // get parameter as string pointer (UTF-8)
const char16_t* pstr2 = info[2].ToString().Utf16Value().c_str(); // get parameter as string pointer (UTF-16)
const char* pstr3 = str1.Utf8Value().c_str();                    // get const char* (UTF-8)
const char16_t* pstr4 = str2.Utf16Value().c_str();               // get const char16_t* (UTF-16) 
uint32_t len = (uint32_t) str1.Utf8Value().length();             // get string length
```
## ```Object```<br>
Class ***Object*** is derived from Value.<br>
**Object** is the base class of classes  **Array, ArrayBuffer and Function**.<br> 
The derived class also inherit the properties and methods of ***Object***.<br>

### create
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Object``|``Object::New(Env)``|(static) creates with no properties|

### example for create
```c++
Object obj0;                            // creates empty
Object obj1 = Object::New(env);         // creates with no properties
Object obj2 = info[2].ToObject();       // creates from parameter
return Object::Object::New(env);        // returns Object with no properties
return obj1;                            // returns Object
```
### check property
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``Has(const char*)``|check for property with key const char*|
|``bool``|``Has(const std::string&)``|check for property with key std::string|
|``bool``|``Has(uint32_t)``|check for property with index uint32_t (used also in **Array**)|
|``bool``|``HasOwnProperty(const char*)``|check for own property with key const char*|
|``bool``|``HasOwnProperty(const std::string&)``|check for own property with key std::string|
|``bool``|``HasOwnProperty(uint32_t)``|check for own property with index uint32_t (used also in **Array**)|
|``Array``|``GetPropertyNames()``|get all Object property names as Array of strings|

### example for check property
```c++
if (info[2].ToObject().Has("key1")) // check parameter for property with key "key1"
    ...

if (obj2.HasOwnProperty("name"))    // check for own property with key "name"
    ...

Array names = obj2.GetPropertyNames(); // get all Object property names
```

### get property
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Value``|``Get(const char*)``|get property with key const char*|
|``Value``|``Get(const std::string&)``|get property with key std::string|
|``Value``|``Get(uint32_t)``|get property with index uint32_t (used also in **Array**)|
|``Value``|``[const char*]``|(operator) get property with key const char*|
|``Value``|``[const std::string&()]``|(operator) get property with key std::string|
|``Value``|``[uint32_t]``|(operator) get property with index uint32_t (used also in **Array**)|

If property not found, returned ***Value*** is ***undefined***.<br> 
### example get property
```c++
Value val1 = info[2].ToObject()["num"];      // get parameter Value property with key "num"
Value val2 = obj2["count"];                  // get Value property with key "count"
Value val3 = obj2[uint32_t(0)];              // get Value property with index 0
Number num = obj1.Get("key1").ToNumber();    // get Number property with key "key1"
String str = obj2["count"].As<String>();     // get String property with key "count"
String str = obj2[uint32_t(1)].As<String>(); // get String property with index 1
uint32_t max = obj2["num"].ToNumber();       // get uint32_t cast from Number property with key "num
bool b_run = obj1["run"].ToBoolean();        // get bool from property with key "run"
std::string col = obj2["col"].ToString();    // get std::string from property with key "col" (use cast)
uint32_t = info[0].ToObject()["count"].ToNumber(); // get uint32_t from parameter with key "count" (use cast)
```

### set property
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``Set(KeyType, ValueType)``|set property with key ***KeyType*** to value ***ValueType***|
|``bool``|``[KeyType] = ValueType``|(operator) set property with key ***KeyType*** to value ***ValueType***| 

Where ``KeyType`` is:<br>
```c++
const char*, const std::string&, uint32_t
```
Where ``ValueType`` is:<br>
```c++
bool, IntType, float, double, const char*, const char16_t*, std::string, std::u16string, Value 
```
Where ``IntType`` is:<br>
```c++
uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, int64_t, size_t
```
Returns true if set successful.<br>
Property is added if not exist.<br> 
### examples set property
```c++
obj1.Set("run", false);             // set property with key "run" to false
obj2["color"] = "blue";             // set property with key "color" to "blue"
obj2["color"] = Number::New(env, 12); // change property with key "color" to Number
obj1.Set("run", info[0]);            // set property with key "run" from parameter
```

### delete property
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``bool``|``Delete(const char*)``|delete property with key const char*|
|``bool``|``Delete(const std::string&)``|delete property with key std::string|
|``bool``|``Delete(uint32_t)``|delete property with index uint32_t (used also in **Array**)|

Returns true if delete successful.<br>

### examples delete property
```c++
obj1.Delete("run");             // delete property with key "run"
obj2.Delete(uint32_t(0));       // delete property with index 0
```
## ```Array```<br>
***Array*** is derived from Value::Object.<br>
***Array*** elements are accessed with index uint32_t<br> 
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Array``|``Array::New(Env)``|(static) creates with no elements|
|``Array``|``Array::New(Env, size_t)``|(static) creates with number of empty elements|

### example for create
```c++
Array arr0;                       // creates empty
Array arr1 = Array::New(env);     // creates with no elements
Array arr2 = Array::New(env, 5);  // creates with 5 empty elements
Array arr3 = info[2].As<Array>(); // creates from parameter
return Object::New(env);          // returns Array with no elements
return arr2;                      // returns Array
```
### get length
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``uint32_t``|``Length()``|Get length (count of elements) as uint32_t|

### get length example 
```c++
uint32_t len = arr2.Length(); // Get length (count of elements)
```
### using methods derived from Object
|**Returns**|**Method**|**Description**|
|:---|:---|:---|
|``Value``|``Get(uint32_t)``|get get element with index uint32_t|
|``Value``|``[uint32_t]``|(operator) get element with index uint32_t|
|``bool``|``Set(uint32_t, ValueType)``|set element to value ***ValueType***|
|``bool``|``[uint32_t] = ValueType``|(operator) set element to value ***ValueType***|
|``bool``|``Delete(uint32_t)``|delete element with index uint32_t|

Where ``ValueType`` is:<br>
```c++
bool, IntType, float, double, const char*, const char16_t*, std::string, std::u16string, Value 
```
Where ``IntType`` is:<br>
```c++
uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, int64_t, size_t
```
If element not found on get, returned ***Value*** is ***undefined***.<br> 
Returns true if set or delete successful.<br>
Element is added if not exist and gap is filled with empty ***Value***.<br> 

### example using methods derived from Object
```c++
Number num = arr1.Get(uint32_t(5)).ToNumber(); // get element with index 5 as Number
String str = arr2[uint32_t(3)].As<String>();   // get element with index 3 as String
uint32_t = info[2].As<Array>()[1].ToNumber();  // get uint32_t from parameter with index 1 (use cast)

arr1[uint32_t(5)] = 15.23;                     // set element with index 5 with number
arr2.Set(uint32_t(3), "abc");                  // set element with index 3 with string

arr2.Delete(uint32_t(0));                      // delete element with index 0
```
```to be continued```
