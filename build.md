# Build Native Code Example sayhello
🏠[To Home Page](README.md)

On previous chapter we create the C++ native code example ***sayhello.cpp***.<br>
We build the sayhello.cpp C++ code with script ***node-gyp***.<br>
***node-gyp*** needs a JSON file with name ***binding.gyp*** as input.<br>

Select menu ***File->New File ...***<br>
Enter ***binding.gyp*** and press **enter** key then ***Create File*** button.<br>

Type this JSON definition in editor:

```JSON
{
    "targets": [
        {
        "target_name": "sayhello",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [ "sayhello.cpp" ],
        "include_dirs": [ "/usr/lib/node_modules/node-addon-api" ],
        "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
        }
    ]
}
```
Save File with menu ***File->Save***.

Visual Studio Code has own command line window.<br>
Menu ***Terminal->New Terminal*** opens the command line on bottom<br>
and sets to working folder.<br>
Here you can enter any linux commands.<br>

To create the compile environment, enter here:<br>
```
node-gyp configure
```
This reads the ***binding.gyp*** file and creates the compile folder,<br>
downloads if needed the ***Node-API*** header files and creates the makefile.<br>
If you get errors, you have mistyped in ***binding.gyp*** file,<br>
else ***node-gyp prompts*** with ```gyp info ok```.<br>

Now we build the native code, enter on command line:
```
node-gyp build
```
If you get errors, you have mistyped in ***sayhello.cpp*** file,<br>
else node-gyp prompts with ```gyp info ok```.<br>

We have now our first native code ***sayhello.node*** in folder<br>
*/home/pi/sayhello/build/Release/*

For all commands and parameters of [node-gyp📌](https://github.com/nodejs/node-gyp)

What means the lines in the ***binding.gyp*** file ?

```
"target_name": "sayhello",
```
Name of the output file (without extension **.node**).
```
"cflags!": [ "-fno-exceptions" ],
"cflags_cc!": [ "-fno-exceptions" ],
```
C and C++ compile flags for disable and don't generate code for C/C++ exceptions.<br>
```
"sources": [ "sayhello.cpp" ],
```
The source files to compile.<br>
```
"include_dirs": [ "/usr/lib/node_modules/node-addon-api" ],
```
The ***node-addon-api*** include path.  
```
"defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
```
C/C++ preprocessor definitions.<br>

This is a very basic ***binding.gyp*** file.<br>
You can extend the ***binding.gyp*** file for different cpu and os.<br>
The documentation of GYP is [here📌](https://gyp.gsrc.io/docs/UserDocumentation.md).<br>

Stop, where is the file ***package.json*** ?<br>
We don't use it now and add ***package.json*** later in examples.<br>

[🧾Next: Call native module sayhello.node from JavaScript ](call.md)
