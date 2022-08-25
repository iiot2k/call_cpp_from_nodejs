# Parameters on call of native function 
🏠[To Home Page](README.md)

Next example explains parameters on call of native function.<br>
This example receives parameters from JavaScript, change it and returns.<br>
The source code is in folder ***parameters***.<br>
I explain only the differences to example ***sayhello***.<br>

```parameters.cpp```
```c++
#include <napi.h>

using namespace Napi;

// function parameters
Value parameters(const CallbackInfo &info)
{
    // get environment
    Env env = info.Env();

    // check if parameter count is valid
    if ( info.Length() != 3 )
        return String::New(env, "Invalid parameter count");

    // check parameters type
    if ( !info[0].IsBoolean() || !info[1].IsNumber() || !info[2].IsArray() )
        return String::New(env, "Invalid parameter type");

    // get parameters
    bool v_bool = info[0].As<Boolean>();
    uint32_t v_number = info[1].As<Number>().Uint32Value();
    Array v_array = info[2].As<Array>();

    // change and add array elements
    v_array[uint32_t(0)] = Number::New(env, v_number);
    v_array[uint32_t(1)] = String::New(env, "Set string element");
    v_array[uint32_t(2)] = Boolean::New(env, !v_bool);
    v_array[uint32_t(4)] = String::New(env, "Add string element to array");
    
    // return changed array
    return v_array;
}

#define SETFN(fn) exports.Set(#fn, Function::New(env, fn))

// function adds symbols to export list
Object Init(Env env, Object exports)
{
    SETFN(parameters);
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
```
What means the code lines ?
```c++
using namespace Napi;
```
In ***sayhello*** example we use ```Napi::``` as namespace prefix.<br>
We tell them compiler look in header files and add the namespace prefix to the symbol if found.<br>
```String``` is changed to ```Napi::String```.   
```c++
Env env = info.Env();
```
Store the environment to a variable **env**.<br>
This prevents always call to ```info.Env()```.<br>
```c++
if ( info.Length() != 3 )
    return String::New(env, "Invalid parameter count");
```
Here we check the count of parameter.<br>
If the count of parameter not 3 then return an error text.<br>
We can also trow a exception, but later in chapter ***Exception***.<br>
```c++
if ( !info[0].IsBoolean() || !info[1].IsNumber() || !info[2].IsArray() )
    return String::New(env, "Invalid parameter type");
```
We must also check the type of the parameters.<br>
```info[0]``` is the first parameter. ```info[1]``` the second parameter and so on.<br> 
If the type of parameters not correct then return an error text.<br>
```c++
bool v_bool = info[0].As<Boolean>();
uint32_t v_number = info[1].As<Number>().Uint32Value();
Array v_array = info[2].As<Array>();
```
First line converts first parameter to a C++ ```bool```.<br>
Second line converts second parameter to a C++ 32bit unsigned integer.<br>
Third line assigns from third parameter the reference to a ***node-addon-api*** Array.<br>
If the parameters type are different on converting, ***node-addon-api*** throws a exception.<br>
```c++
v_array[uint32_t(0)] = Number::New(env, v_number);
v_array[uint32_t(1)] = String::New(env, "Set string element");
v_array[uint32_t(2)] = Boolean::New(env, !v_bool);
v_array[uint32_t(4)] = String::New(env, "Add string element to array");
```
With this lines we change the contents of the array.<br>
```[uint32_t(0)]``` access the index 0 of array and change it to a number.<br>
```[uint32_t(1)]``` access the index 1 of array and change it to a string.<br>
```[uint32_t(2)]``` access the index 2 of array and change it to a boolean.<br>
```[uint32_t(4)]``` adds the index 4 to array and set it to a string.<br>
Index 3 is in this case set to empty.<br>
The index type of array has many data types.<br>
With ```uint32_t(4)``` we say it is a unsigned integer constant.<br>
```c++
return v_array;
```
Returns the changed array.
```c++
#define SETFN(fn) exports.Set(#fn, Function::New(env, fn))
```
This macro creates the function call with one parameter.<br>
```SETFN(parameters);``` is expanded to ```exports.Set("parameters", Function::New(env, parameters));```<br>

