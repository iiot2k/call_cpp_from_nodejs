# Call C++ from Node.js (Node-Red)
[![platform](https://img.shields.io/badge/platform-Node.js-green)](https://nodejs.org/en/)
[![platform](https://img.shields.io/badge/platform-Node--RED-red)](https://nodered.org)
[![platform](https://img.shields.io/badge/platform-Raspberry--Pi-ff69b4)](https://www.raspberrypi.com/)
[![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZDRCZBQFWV3A6)

This little tutorial will tell you how to get started with using C++ programs with ***Node.js***.<br>
The prerequisite is programming knowledge in C++ and JavaScript.<br>

***Node.js*** programs are written with JavaScript programming language.<br>
***Node-Red*** is based on ***Node.js***.<br>
***Node.js*** offers a [Node-API📌](https://nodejs.org/api/n-api.html) for calling C/C++ programs from JavaScript.<br>
This is a pure C header only files with calls to underlying ***Node.js*** subsystem.<br>
***Node-API*** follows [ABI📌](https://nodejs.org/en/docs/guides/abi-stability/) definitions.<br>
Parts of ***Node.js*** are written in [C++📌](https://github.com/nodejs/node/tree/main/deps).<br>

But ***Node-API*** isn't easy to use and difficult.<br>
Therefore we use [node-addon-api📌](https://github.com/nodejs/node-addon-api).<br>
***node-addon-api*** is a pure C++ wrapper header only files that use<br>
the object oriented logic of C++ with ***Node-API***.<br>

⚠️***node-addon-api*** are only needed to build the native modules.<br> 

To call C++ programs from ***Node.js***, you write a C++ program<br>
and build it with a C++ compiler to a binary file.<br>
This binary file (native module) is a shared library on linux ```.so```<br>
and dynamic link library on Windows ```.dll```.<br>
But native modules in ***Node.js*** use the file extension ```.node```.<br>
***Node.js*** recognizes from the file extension ```.node``` that it is a native module.<br>

The JavaScript command **require** loads the native module.<br>
This example loads the native module **mynode.node** <br>
in folder ./lib and calls the function ***myfunction*** in native module.

```javascript
const mylib = require("./lib/mynode.node");

mylib.myfunction();
```
Sounds complicated, but this tutorial shows how to do it easy.<br>

### Advantages of native nodes:
- Very fast execution and load because precompiled optimized machine code.
- Easy access to system and hardware.
- Add lot of C/C++ libraries to Node.js (Node-Red).
- No external dependencies.

### Disadvantages of native nodes:
- Compiled native code runs only for the compiled target cpu and os.
- Debug of native code isn't easy.
- JavaScript debugger can't handle c++ code.
- User must install build programs if node-gyp is used in distribution.

Enough theory, now let's move on to the practical part.<br>

[🧾Next: Setup Build Environment](setup.md)<br>

### Chapters
[🧾Setup Build Environment](setup.md)<br>
[🧾Create Native Code Example sayhello](sayhello.md)<br>
[🧾Build Native Code Example sayhello ](build_sayhello.md)<br>
[🧾Call native module sayhello.node from JavaScript ](call_sayhello.md)<br>
[🧾Create Native Code Example parameters ](parameters.md)<br>
[🧾Build Native Code Example parameters ](build_parameters.md)
[🧾Call native module parameters.node from JavaScript ](call_parameters.md)
