# Setup Build Environment
🏠[To Home Page](README.md)

We use Raspberry Pi as development environment.<br>
For setup we need a working internet access.<br>
You can use any Raspberry Pi computer and OS (32/64bit).<br>
But a fast Raspberry Pi is nice, when you compile large programs.<br>

Its now time to open command line window on Raspberry Pi.<br>

For compile C++ programs we need Python, C++ compiler and make program.<br>
This is mostly preinstalled on Raspberry Pi OS.<br>
Check with this commands:<br>

```
python -V
gcc -v
make -v
```
⚠️The compile environment are only needed to build the native modules.

We require **Node.js**.<br>
The easiest way is to install Node-Red.<br>
Node.js and npm is then also installed.
[How look here.📌](https://nodered.org/docs/getting-started/raspberrypi)<br>
The ***Node-API*** header files are also installed on folder ```/usr/include/node```.

Don't worry, you don't have to learn<br>
the many parameters of C++ compiler and complex makefile syntax now.<br>

Smart people writes a python script [node-gyp📌](https://github.com/nodejs/node-gyp) that makes all for you.<br>
Enter this command to install this tool:<br> 

```
sudo npm install -g node-gyp
```

Alternatively, if you are familiar with CMake, you can also use [CMake.js📌](https://github.com/cmake-js/cmake-js).

We need also the C++ wrapper library ***node-addon-api***.<br>
This command installs it to global folder */usr/lib/node_modules/node-addon-api*<br>

```
sudo npm install -g node-addon-api
```

Next we need also an editor.<br> 
You can use any editor but I recommend Visual Studio Code.

```
sudo apt update
sudo apt install code
```

Open Visual Studio Code (Left-Top Raspberry->Programming->Visual Studio Code).<br>
On first start of Visual Studio Code enter settings or skip.<br>
On Left-Top side of Visual Studio Code you see four rectangle. One flees.<br>
Here you can install Visual Studio Code extensions.<br>
Install Microsoft extension for C/C++.<br>

![VSC Extension](/images/vsextension.png "VSC Extension")

## Setup IntelliSense in VSC
Visual Studio Code has a powerful IntelliSense feature.<br>
Next setup the IntelliSense Configuration.<br>
The editor runs in background a C++ compiler for syntax check.<br>
We tell IntelliSense where the ***Node-API*** and ***node-addon-api*** include files are stored.<br>

In Visual Studio Code select menu ***View->Command Palette...***.<br>
On list select ***C/C++: Edit Configurations (UI)***.<br>
A new window with C/C++ ***IntelliSense Configuration*** opens.<br>
Scroll down list until you see section ***Include path***.<br>
Add these lines:
```
/usr/lib/node_modules/node-addon-api
/usr/include/node
```
In section ***Defines*** add this lines:
```
NAPI_DISABLE_CPP_EXCEPTIONS
```
Save the settings with ***File->Save*** and close settings windows.<br>

```/usr/lib/node_modules/node-addon-api``` is the path to ***node-addon-api*** header files.<br>
```/usr/include/node```  is the path to ***Node-API*** header files.<br>
```NAPI_DISABLE_CPP_EXCEPTIONS``` is a C++ definition to turn off C++ exceptions.<br>
I explain later the meaning of exceptions.<br>

📍Tip: Visual Studio Code creates a folder with name ***.vscode*** on working folder.<br>
The settings above are valid only for actual workspace and are stored in file<br>
***c_cpp_properties.json***<br>
You can also edit this file with an editor.<br>
If you create a new workspace, create a subfolder ***.vscode***<br>
and copy ***c_cpp_properties.json*** file to that folder.<br>
All settings are then valid for the new workspace.<br>

You can also set this settings globally with ***File->Preferences->Settings***<br>
Expand ***Extensions*** and select ***C/C++***.<br>
Search for ***Include Path*** and ***Defines*** and enter paths and defines.<br>

I prefer settings per workspace.<br>
This prevents confusion with different project types.<br> 

[🧾Next: Create Native Code Example sayhello ](create.md)
