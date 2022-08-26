# Create Native Code Example sayhello

🏠[To Home Page](README.md)

Open Visual Studio Code (if not already open). <br>
At first start of Visual Studio Code the folder ***/home/pi/*** is selected.<br>
For our new native C++ code we create the working folder ***sayhello***.

Select menu ***File->Open Folder ...***<br> 
Folder dialog opens. On right top click folder icon with plus sign.<br>
Enter name for new folder, in our case ***sayhello*** and click ***Create*** button.<br>
Close folder dialog with click ***Open***.<br>
Our working folder is now ***/home/pi/sayhello***<br>

We are now ready to write our first native code.<br>

First we create the C++ file.<br>
The source code is in folder ***sayhello***, but for learning I recommend to type it.<br>
Select menu ***File->New File ...***<br>
Enter ***sayhello.cpp*** and press **enter** key then ***Create*** button.<br>
We write a C++ function that returns a string "Hello" on call from node.js.<br>
```sayhello.cpp```
```c++
#include <napi.h>

// function sayhello
Napi::Value sayhello(const Napi::CallbackInfo &info)
{
    return Napi::String::New(info.Env(), "Hello");
}

// function adds symbols to export list
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("sayhello", Napi::Function::New(env, sayhello));
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
```

Save File with ***File->Save***.

What this lines of code means ?<br>
```c++
#include <napi.h>
```
This includes the ***node-addon-api*** header file **napi.h** on compile.<br>
The file contains C++ wrapper interface to **Node-API**.<br>
To use elements of **napi.h** you must use the namespace name ```Napi::```<br>
For example to create a String ```Napi::String```<br>

```c++
Napi::Value sayhello(const Napi::CallbackInfo &info)
```
This function is called from Node.js.<br> 
Node.js stores parameters and other data in ```CallbackInfo &info```.<br>
The function ```sayhello``` has no parameters, therefore we don't use it.<br>
I explain parameters later in detail.<br>
```c++
    return Napi::String::New(info.Env(), "Hello");
```
The function ***sayhello*** returns a ```Value```.<br>
```Value``` is the topmost class of all other datatypes.<br> 
We create and return a Node.js ```String``` with string constant ***"Hello"***.<br>
```info.Env()``` is the environment variable of **Node.js**.<br> 
I explain return values later in detail.<br>
```c++
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("sayhello", Napi::Function::New(env, sayhello));
    return exports;
}
```
This function adds a C++ function ```sayhello``` with Node.js name ***"sayhello"*** to exports list.<br>
```c++
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
```
This macro calls the function ```Init``` on load of native module.<br>
The symbol ```NODE_GYP_MODULE_NAME``` are defined on build with ***node-gyp***.<br>

[🧾Next: Build Native Code Example sayhello ](build_sayhello.md)







