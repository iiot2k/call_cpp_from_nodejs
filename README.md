# Call C++ from Node.js (Node-Red)
[![platform](https://img.shields.io/badge/platform-Node--RED-red)](https://nodered.org)
[![platform](https://img.shields.io/badge/platform-Raspberry--Pi-ff69b4)](https://www.raspberrypi.com/)
[![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZDRCZBQFWV3A6)

This little tutorial will show you how to get started with using C++ programs with ***Node.js***.<br>

It's possible to call C++ functions from Node.js directly.<br>
[More Info here📌](https://nodejs.org/api/n-api.html)<br>
Parts of [Node.js📌](https://github.com/nodejs/node/tree/main/deps) are written in C/C++.<br>

The C++ functions are compiled as binary with **Node.js** interface.<br>
The native modules has the file extension ***.node***.<br>
The JavaScript command **require** loads the native module.<br>
The native module is loaded once and unloaded when Node.js exits.  

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
- 

### Chapters
[🧾Setup](setup.md)<br>
[🧾Create Native Code Example sayhello](create.md)<br>
[🧾Build Native Code Example sayhello ](build.md)<br>
[🧾Call native code sayhello.node from Node.js ](call.md)<br>
[🧾Parameters on call of native function ](parameters.md)<br>