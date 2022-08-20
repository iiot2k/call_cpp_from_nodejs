# Build Native Code Example sayhello
🏠[To Home Page](README.md)

On previous chapter we create the C++ vative code example ***sayhello.cpp***.<br>
Now we build the sayhello.cpp C++ code.<br>
Compiling C/C on commandline is very complicated.<br>
Therefore we use the python script ***node-gyp***.<br>
***node-gyp*** needs a JSON file with name ***binding.gyp***.<br>
It creates the makefile and compiles the C++ native code.

Select menu ***File->New File ...***<br>
Enter ***binding.gyp*** and press **enter** key then ***Create*** button.<br>

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

To create the compile enviroment, enter on command line:<br>
```
node-gyp configure
```
This reads the ***binding.gyp*** file and creates the compile folder,<br>
download the Node.js header files and creates the makefile.<br>
If you get errors, you have mistyped in ***binding.gyp*** file,<br>
else node-gyp prompts with ```gyp info ok```.<br>

Now we compile the native code, enter on command line:
```
node-gyp build
```
If you get errors, you have mistyped in ***sayhello.cpp*** file,<br>
else node-gyp prompts with ```gyp info ok```.<br>

Tadaa, we have now our first native code ***sayhello.node*** in folder<br>
*/home/pi/sayhello/build/Release/*

***node-gyp*** has other helpfull commands:

To delete the build folder:<br>
```
node-gyp clean
```
To execute clean, configure and build in one command:<br>
```
node-gyp rebuild
```
For all commands and parameters of ***node-gyp*** [look here. 📌](https://github.com/nodejs/node-gyp)

What means the lines in the ***binding.gyp*** file ?

```
"target_name": "sayhello",
```
Name of the output file (without extension **.node**).
```
"cflags!": [ "-fno-exceptions" ],
"cflags_cc!": [ "-fno-exceptions" ],
```
C and C++ compile flags for disable and don't generate code for exceptions.<br>
```
"sources": [ "sayhello.cpp" ],
```
The source files to compile. You can add more files separated with comma.<br>
```
"include_dirs": [ "/usr/lib/node_modules/node-addon-api" ],
```
The include files folders where the compiler looks (e.g **napi.h** file).  
```
"defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
```
C/C++ preprocessor definitions. This definition disables n-api code for C++ exeptions.<br>

This is a very basic ***binding.gyp*** file.<br>
You can extend the ***binding.gyp*** file for different cpu and os.<br>
The documentation of GYP is [here📌](https://gyp.gsrc.io/docs/UserDocumentation.md).<br>

[🧾Next: Call native code sayhello.node from Node.js ](call.md)
