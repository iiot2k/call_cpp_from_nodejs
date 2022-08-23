# Call C++ from Node.js (Node-Red)
[![platform](https://img.shields.io/badge/platform-Node--RED-red)](https://nodered.org)
[![platform](https://img.shields.io/badge/platform-Raspberry--Pi-ff69b4)](https://www.raspberrypi.com/)
[![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZDRCZBQFWV3A6)

This little tutorial will tell you how to get started with using C++ programs with ***Node.js***.<br>
The prerequisite for this introduction is programming knowledge in C++ and JavaScript.<br>

Node-Red is based on ***Node.js***.<br>
Parts of ***Node.js*** is written in C++ [Here more info📌](https://github.com/nodejs/node/tree/main/deps).<br>
***Node.js*** use the Google V8 JavaScript engine written in C++.<br>
This engine compiles your JavaScript program in machine code and runs.<br>

The ***Node.js*** has released a [N-API📌](https://nodejs.org/api/n-api.html) 
interface for Node.js.<br>
This interface is written for C as header file.<br>
It's possible to call C/C++ functions from Node.js directly with N-API.<br>
You can write C programs with ***N-API***, but isn't easy to use.<br>
Therefore we use the C++ wrapper library ***node-addon-api***.<br>
***node-addon-api*** use object oriented logic of C++.<br>

Here a picuture that describe the structure.<br>

![Nodejs struct](/images/nodejs_struct.png "Nodejs struct")

The C/C++ functions are compiled as binary with **Node.js** api interface.<br>
This native modules is a shared object (.so) on linux<br>
and dynamic link library on Windows (.dll).<br>
But native modules use the file extension ***.node***.<br>
The native module is loaded once and unloaded when Node.js exits.

The JavaScript command **require** loads the native module.<br>
This example loads the native module **mynode.node** in folder ./lib and calls the function ***myfunction***.

```javascript
const mylib = require("./lib/mynode.node");

mylib.myfunction();
```

### Advantages of native nodes:
- Very fast execution and load because precompiled optimized machine code.
- Easy access to system and hardware.
- Add lot of C/C++ libraries to Node.js (Node-Red).
- No external dependencies.

### Disadvantages of native nodes:
- Precompiled native code runs only for the compiled target cpu and os.
- Debug of native code isn't easy.
- JavaScript debugger can't handle c++ code.
- User must install build programs if node-gyp is used in distribution.


### Chapters
[🧾Setup Build Environment](setup.md)<br>
[🧾Create Native Code Example sayhello](create.md)<br>
[🧾Build Native Code Example sayhello ](build.md)<br>
[🧾Call native code sayhello.node from Node.js ](call.md)<br>
[🧾Parameters on call of native function ](parameters.md)<br>