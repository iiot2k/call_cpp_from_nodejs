# Setup
🏠[To Home Page](README.md)

We use Raspberry Pi as developement enviroment (you need also internet).<br>
But it is possible to develope on other platforms (e.g. Windows).<br>
You can use any Raspberry Pi computer and OS (32/64bit).<br>
But a fast Raspberry Pi is nice, when you compile large programs.<br>

Its now time to open command line window on Raspi.<br>


To compile C++ programs for node.js we need Python, C++ compiler and make.<br>
This is mostly preinstalled on Raspi OS.<br>
Check with commands:<br>

```
python -V
gcc -v
make -v
```

We require **Node.js**<br>
The easyiest way is to install Node-Red.<br>
Node.js and npm is then also installed.
[How look here.📌](https://nodered.org/docs/getting-started/raspberrypi)

Smart people writes a python script [node-gyp📌](https://github.com/nodejs/node-gyp) to compile C++ programs for Node.js.<br>
Enter this command to install:<br> 

```
sudo npm install -g node-gyp
```

Other smart people writes C++ wrapper header files for native modules.<br> 
This command installs the [node-addon-api📌](https://github.com/nodejs/node-addon-api) header files in folder<br>
*/usr/lib/node_modules/node-addon-api*<br>
```
sudo npm install -g node-addon-api
```
**node-gyp** and ***node-addon-api*** are maintained by Node.js team.<br>

We need also an editor.<br> 
You can use any editor but I recommend Visual Studio Code.

```
sudo apt update
sudo apt install code
```

Open Visual Studio Code (Left-Top Raspberry->Programming->Visual Studio Code).<br>
On first start of Visual Studio Code enter settings or skip.<br>
On Left-Top side on Visual Studio Code you see four rectangle. One flees.<br>
Here you can install Visual Studio Code extenstions.<br>
Install Microsoft extension for C/C++.<br>

![VSC Extension](/images/vsextension.png "VSC Extension")

## Setup IntelliSense in VSC
Visual Studio Code has a powerfull IntelliSense feature.<br>
Next setup the IntelliSense Configuration.<br>
The editor runs in background a C++ compiler for syntax check.<br>
We tell IntelliSense where the include files are stored.<br>

In Visual Studio Code select menu ***View->Command Palette...***.<br>
On list select ***C/C++: Edit Configurations (UI)***.<br>
A new window with C/C++ ***IntelliSense Configuration*** opens.<br>
Scroll down list until you see section ***Include path***.<br>
Add this lines:
```
/usr/lib/node_modules/node-addon-api
/usr/include/node
```
In section ***Defines*** add this lines:
```
NAPI_DISABLE_CPP_EXCEPTIONS
```
Save the settings with ***File->Save*** and close settings windows.<br>


[🧾Next: Create Native Code Example sayhello ](create.md)
