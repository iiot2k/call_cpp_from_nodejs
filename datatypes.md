# Datatypes and Methods in node-addon-api
🏠[To Home Page](README.md)

I list here the most important ***node-addon-api*** classes and methods.<br>
For complete detail, look in [node-addon-api📌](https://github.com/nodejs/node-addon-api) documentation.<br>

Assumption for examples:<br>
- With ```using namespace Napi;```
- Using ```CallbackInfo &info```
- Using ```Env env = info.Env();```

The ***Env*** and ***CallbackInfo*** are helper classes for handle calls,<br>
exceptions and environment context.<br> 

## ```Env```<br>
*Env* is the environment context of caller JavaScript.<br>

|**Method**|**Description**|
|:---|:---|
|```Value Null()```|returns an null Value|
|```Value Undefined()```|returns an undefined Value|
|```bool IsExceptionPending()```|returns true if pending exception made|
|``Error GetAndClearPendingException()``|returns Error object and clear pending exception|
|``Value RunScript(const char* script)``|executes JavaScript code and returns Value|

#### examples
```c++
Value val1 = env.Null();             // creates null Value
Value val1 = env.RunScript("3 * 5"); // executes JavaScript code
return env.Undefined();              // returns undefined Value
```
## ```CallbackInfo```<br>
***CallbackInfo*** contain all parameters and environment context<br>
stored on call from JavaScript.
<br>
```c++
// methods
Env Env()        // gets the environment context
size_t Length()  // gets the count of parameters as unsigned integer
Value [size_t]   // gets the parameter with unsigned integer as index

// examples 
Env env = info.Env();   // get environment context from CallbackInfo
if (info.Length() != 3) // checks the count of parameters
    ...
Value v1 = info[0];     // gets the first parameter as Value
```

## ```Value```<br>
**Value** is the base class of all JavaScript datatypes.<br>
Derived classes also inherit the properties and methods of *Value*.<br>
**Value** can contain any JavaScript datatypes ***Null***, ***Undefined***, ***Boolean***, ***Number***..<br>
```c++
// create
Value Value::From(Env, <ValueType>) // creates from type

// Where
<ValueType> 
    bool, <IntType>, float, double 
    const char*, const char16_t*, std::string, std::u16string, Value 

<IntType>
    uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, int64_t, size_t

// examples for create
Value val0;                                   // creates empty
Value txt1 = Value::From(env, "string");      // creates from string UTF-8
Value txt2 = Value::From(env, u"caractères"); // creates from string UTF-16
Value pi = Value::From(env, 3.14);            // creates from double
Value count = Value::From(env, uint32_t(8));  // creates from uint32_t
return Value::From(env, true);                // returns with bool
return Value::From(env, "ok");                // returns with const char* UTF-8

// compare
bool (Value1 == Value2)   // compares for strict equals
bool (Value1 != Value2)   // compares for not strict equals
bool StrictEquals(Value2) // compares for strict equals

// examples for compare
if (txt1 != txt2) // compares for not strict equals (here true)
    ...

if (pi.StrictEquals(txt2)) // compares for strict equals (here false)
    ...

// check datatype
bool IsEmpty()       // checks for Empty (uninitialized)
bool IsUndefined()   // checks for Undefined  
bool IsNull()        // checks for Null
bool IsBoolean()     // checks for Boolean
bool IsNumber()      // checks for Number
bool IsString()      // checks for String
bool IsObject()      // checks for Object
bool IsArray()       // checks for Array
bool IsBuffer()      // checks for Buffer
bool IsArrayBuffer() // checks for ArrayBuffer
bool IsFunction()    // checks for Function

napi_valuetype Type() // returns the datatype as napi_valuetype
// for napi_valuetype look here https://nodejs.org/api/n-api.html#napi_valuetype

// example for check datatype
if (!info[0].IsBoolean() || !info[1].IsNumber()) // check parameters datatype
    ...

switch(info[1].Type()) // execute code depends of datatype of parameter
{
    case napi_valuetype::napi_boolean: // Boolean
        ...
}

// coerces to derived class 
Boolean ToBoolean()  // coerces to Boolean
Number ToNumber()    // coerces to Number
String ToString()    // coerces to String
Object ToObject()    // coerces to Object

Boolean As<Boolean>()  // coerces to Boolean
Number As<Number>()    // coerces to Number
String As<String>()    // coerces to String
Object As<Object>()    // coerces to Object
Array As<Array>()      // coerces to Array
Buffer As<Buffer>()    // coerces to Buffer
ArrayBuffer As<ArrayBuffer>() // coerces to ArrayBuffer
Function As<Function>() // coerces to Function

// examples for coerces to derived class
Boolean isok = info[0].ToBoolean(); // coerces parameter to Boolean
Number cnt = info[1].As<Number>();  // coerces parameter to Number
String str1 = txt1.ToString();      // coerces Value to String 
```
## ```Boolean```<br>
***Boolean*** is derived from Value.<br>
```c++
// create
Boolean Boolean::New(Env, bool) // creates initialized with bool

// example for create
Boolean bval0;                           // creates empty
Boolean bval1 = Boolean::New(env, true); // creates with bool
Boolean bval2 = info[1].As<Boolean>();   // creates from parameter
return Boolean::New(env, false);         // returns with bool
return bval1;                            // returns Boolean

// get value
bool Value() // get bool
(bool)       // cast to get bool

// example for get value
bool b1 = info[0].As<Boolean>().Value(); // get parameter as bool
bool b2 = info[1].ToBoolean().Value();   // get parameter as bool
bool b3 = info[2].ToBoolean();           // get parameter as bool with cast
bool b4 = bval1.Value();                 // get as bool
bool b4 = bval1;                         // get as bool with cast
```
## ```Number```<br>
***Number*** is derived from Value.<br>
```c++
// create
Number Number::New(Env, double)  // create with double

// example create
Number val0;                          // creates empty
Number val1 = Number::New(env, 3.14); // creates with double constant
Number val2 = info[1].As<Number>();   // creates from parameter
Number Val3 = info[2].ToNumber();     // creates from parameter
return Number::New(env, 0.15);        // returns with double constant
return val1;                          // returns Number

// get value
int32_t Int32Value()   // get as int32_t
uint32_t Uint32Value() // get as uint32_t
int64_t Int64Value()   // get as int64_t
float FloatValue()     // get as float
double DoubleValue()   // get as double

(int32_t)  // cast to get as int32_t
(uint32_t) // cast to get as uint32_t
(int64_t)  // cast to get as int64_t
(float)    // cast to get as float
(double)   // cast to get as double

// example get value
uint32_t n1 = info[0].As<Number>().Uint32Value(); // get parameter as uint32_t
double n2 = info[1].ToNumber().DoubleValue();     // get parameter as double 
double n3 = info[2].ToNumber();                   // get parameter as double with cast
uint32_t n4 = info[3].As<Number>();               // get parameter as uint32_t with cast
int32_t n5 = val1.Int32Value();                   // get as int32_t
double n6 = val1;                                 // get as double with cast
```
## ```String```<br>
***String*** is derived from Value::Name.<br>
**String** can handle [std::string](https://cplusplus.com/reference/string/string/) (UTF-8)
and [std::u16string](https://cplusplus.com/reference/string/u16string/) (UTF-16).<br>
```c++
// create
String String::New(Env, const char*)           // creates with const char* (UTF-8)
String String::New(Env, const char16_t*)       // creates with const char16_t* (UTF-16)
String String::New(Env, const std::string&)    // creates with std::string (UTF-8)
String String::New(Env, const std::u16string&) // creates with std::u16string (UTF-16)

// example create
String str0;                                   // creates empty 
String str1 = String::New(env, "string");      // creates with const char* (UTF-8)
String str2 = String::New(env, u"caractères"); // creates with const char16_t* (UTF-16)
String str3 = info[1].As<String>();            // creates from parameter 
String str4 = info[2].ToString();              // creates from parameter
return String::New(env, "Error");              // returns with const char* (UTF-8)
return str2;                                   // returns String

// get value
std::string Utf8Value()      // get as std::string (UTF-8)
std::u16string Utf16Value()  // get as std::u16string (UTF-16)

(std::string())              // cast to get as std::string (UTF-8)
(std::u16string())           // cast to get as std::u16string (UTF-16)

// examples get value
std::string std_str1 = info[1].As<String>().Utf8Value();   // get parameter as std::string
std::u16string std_str2 = info[2].ToString().Utf16Value(); // get parameter as std::u16string
std::string std_str3 = info[3].As<String>();               // get parameter as std::string with cast
std::u16string std_str4 = info[4].ToString();              // get parameter as std::u16string with cast
std::string std_str3 = str1.Utf8Value();                   // get std::string
std::u16string std_str4 = str2;                            // get std::u16string with cast

// get string pointer from std::string and std::u16string methods
const char* Utf8Value().c_str()      // get const char* (UTF-8)
const char16_t* Utf16Value().c_str() // get const char16_t* (UTF-16)

// examples get string from std::string and std::u16string methods
const char* pstr1 = info[1].ToString().Utf8Value().c_str();      // get parameter as string pointer (UTF-8)
const char16_t* pstr2 = info[2].ToString().Utf16Value().c_str(); // get parameter as string pointer (UTF-16)
const char* pstr3 = str1.Utf8Value().c_str();                    // get const char* (UTF-8)
const char16_t* pstr4 = str2.Utf16Value().c_str();               // get const char16_t* (UTF-16) 
```
## ```Object```<br>
***Object*** is derived from Value.<br>
**Object** is the base class of JavaScript datatypes **Array, ArrayBuffer and Function**.<br> 
The derived class also inherit the properties and methods of *Object*.<br>
```c++
// create
Object Object::New(Env); // creates with no properties

// example for create
Object obj0;                            // creates empty
Object obj1 = Object::New(env);         // creates with no properties
Object obj2 = info[2].ToObject();       // creates from parameter
return Object::Object::New(env);        // returns Object with no properties
return obj1;                            // returns Object

// check property
bool Has(const char*)                    // check for property with key const char*
bool Has(const std::string&)             // check for property with key std::string
bool Has(uint32_t)                       // check for property with index uint32_t
bool HasOwnProperty(const char*)         // check for own property with key const char*
bool HasOwnProperty(const std::string&)  // check for own property with key std::string
bool HasOwnProperty(uint32_t)            // check for own property with index uint32_t

Array GetPropertyNames()                 // get all Object property names as Array of strings

// example for check property
if (info[2].ToObject().Has("key1")) // check parameter for property with key "key1"
    ...

if (obj2.HasOwnProperty("name"))    // check for own property with key "name"
    ...

Array names = obj2.GetPropertyNames(); // get all Object property names

// get property
Value Get(const char*)         // get property with key const char*
Value Get(const std::string&)  // get property with key std::string
Value Get(uint32_t)            // get property with index uint32_t

Value [const char*]            // get property with key const char* as operator[]
Value [const std::string&]     // get property with key std::string as operator[]
Value [uint32_t]               // get property with index uint32_t as operator[]

// example get property
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

// set property
bool Set(<KeyType>, <ValueType>) // set property with key <KeyType> to value <ValueType>
Object[<KeyType>] = <ValueType>  // set property with key <KeyType> to value <ValueType> as [] operator

// where
<KeyType>
    const char*, const std::string&, uint32_t
  
<ValueType> 
    bool, <IntType>, float, double,
    const char*, const char16_t*, std::string, std::u16string, Value 

<IntType>
    uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, int64_t, size_t

// examples set property
obj1.Set("run", false);             // set property with key "run" to false
obj2["color"] = "blue";             // set property with key "color" to "blue"
obj2["color"] = Number::New(env, 12); // change property with key "color" to Number
obj1.Set("run", info[0]);            // set property with key "run" from parameter

// delete property
bool Delete(const char*)         // delete property with key const char*
bool Delete(const std::string&)  // delete property with key std::string
bool Delete(uint32_t)            // delete property with index uint32_t

// examples delete property
obj1.Delete("run");             // delete property with key "run"
obj2.Delete(uint32_t(0));       // delete property with index 0
```
## ```Array```<br>
***Array*** is derived from Value::Object.<br>
***Array*** elements are accessed with index uint32_t<br> 
```c++
// create
Array Array::New(Env);         // creates with no elements
Array Array::New(Env, size_t); // creates with empty elements

// example for create
Array arr0;                       // creates empty
Array arr1 = Array::New(env);     // creates with no elements
Array arr2 = Array::New(env, 5);  // creates with 5 empty elements
Array arr3 = info[2].As<Array>(); // creates from parameter
return Object::New(env);          // returns Array with no elements
return arr2;                      // returns Array

// get length
uint32_t Length() // Get length (count of elements) as uint32_t

// get length example 
uint32_t len = arr2.Length(); // Get length (count of elements)

// meaningful methods derived from Object
bool Has(uint32_t)              // check for index with uint32_t
bool HasOwnProperty(uint32_t)   // check for index with uint32_t

Value Get(uint32_t)             // get element with index uint32_t
Value [uint32_t]                // get property with index uint32_t with operator[] 

bool Set(uint32_t, <ValueType>) // set element with index uint32_t
Array[uint32_t] = <ValueType>   // set element with index uint32_t to with [] operator

bool Delete(uint32_t)           // delete element with index uint32_t

// example meaningful methods derived from Object
Number num = arr1.Get(uint32_t(5)).ToNumber(); // get element with index 5 as Number
String str = arr2[uint32_t(3)].As<String>();   // get element with index 3 as String

uint32_t = info[2].As<Array>()[1].ToNumber(); // get uint32_t from parameter with index 2 (use cast)

arr1[uint32_t(5)] = 15.23;                     // set element with index 5 with number
arr2.Set(uint32_t(3), "abc");                  // set element with index 3 with string

arr2.Delete(uint32_t(0));                      // delete element with index 0
```
