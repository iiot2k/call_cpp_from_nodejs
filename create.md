# Create Native Code Example sayhello

🏠[To Home Page](README.md)

Open Visual Studio Code (if not already open). <br>
At first start of Visual Studio Code the folder ***/home/pi/*** is selected.<br>
For our new native code we create the working folder ***sayhello***.

Select menu ***File->Open Folder ...***<br> 
Folder dialog opens. On right top click folder icon with plus sign.<br>
Enter name for new folder, in our case ***sayhello*** and click ***Create*** button.<br>
Close folder dialog with click ***Open***.<br>
Our working folder is now ***/home/pi/sayhello***<br>

We are now ready to write our first native code.<br>

First we create the C++ file.<br>
All files are in the Github repository, but for learning I recommend to type it.<br>
Select menu ***File->New File ...***<br>
Enter ***sayhello.cpp*** and press **enter** key then ***Create*** button.<br>
We write a C++ function that returns a string "Hello" on call from node.js.<br>
Type this program in editor:
```c++
#include <napi.h>

// function sayhello
Napi::Value sayhello(const Napi::CallbackInfo &info)
{
    return Napi::String::New(info.Env(), "Hello");
}

// function adds symbols to export list
Napi::Object export_all(Napi::Env env, Napi::Object exports)
{
    exports.Set("sayhello", Napi::Function::New(env, sayhello));
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, export_all);
```

Save File with ***File->Save***.

What this lines of code means ?<br>
```c++
#include <napi.h>
```
This includes the **napi.h** file on compile.<br>
The file contains C++ wrapper interface elements to **node.js**.<br>
To use elements of **napi.h** you must use the namespace ```Napi::```<br>
For example to create a String ```Napi::String```<br>
In second example I show how prevent this.<br> 

```c++
Napi::Value sayhello(const Napi::CallbackInfo &info)
```
This function is called from Node.js.<br> 
Parameters and other data are stored in ```CallbackInfo &info```.<br>
```c++
    return Napi::String::New(info.Env(), "Hello");
```
The function ***sayhello*** returns a ```Value```.<br>
This is the topmost class of all node.js C++ datatypes.<br> 
We create and return a ```String```.<br>
This elements are explained later in detail.<br>
```c++
Napi::Object export_all(Napi::Env env, Napi::Object exports)
{
    exports.Set("sayhello", Napi::Function::New(env, sayhello));
    return exports;
}
```
The function ***export_all*** is called from macro ```NODE_API_MODULE``` defined in napi.h.<br>
A ***exports*** list with symbols are init and returned.<br>
We export a C++ function ***sayhello*** to Node.js with name "sayhello".<br>  
```c++
NODE_API_MODULE(NODE_GYP_MODULE_NAME, export_all);
```
This macro exports all symbols created in function ***export_all***.<br>
The symbol NODE_GYP_MODULE_NAME are defined later on compile by node-gyp.<br>
You can ignore the "not found" error in Editor.<br> 

[🧾Next: Build Native Code Example sayhello ](build.md)







