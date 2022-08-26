# Build Native Code Example parameters
🏠[To Home Page](README.md)

In ***sayhello*** example we build the native module on command line with ***node-gyp*** commands.<br>
We build the the example ***parameters*** with [npm📌](https://docs.npmjs.com/cli/v8/commands) command line tool.<br>
***npm*** needs a [package.json📌](https://docs.npmjs.com/cli/v8/configuring-npm/package-json) JSON file as input.

```package.json```
```JSON
{
    "name": "parameters",
    "version": "1.0.0",
    "description": "Node.js Addons Parameters Example",
    "main": "parameters.js",
    "private": true,
    "dependencies": {
        "node-addon-api": "*",
        "bindings": "*" 
    },
    "gypfile": true
}
```

What means these lines in the ***package.json*** file ?
```JSON
"name": "parameters",
```
The name of package (required). This is important, when you publish your package.
```JSON
    "version": "1.0.0",
```
The package version of package(required). This is also important, when you publish your package.
```JSON
    "description": "Node.js Addons Parameters Example",
```
Describe what your package do.<br>
```JSON
    "main": "parameters.js",
```
Which main JavaScript program is called.
```JSON
    "private": true,
```
This prevents that your package published on internet (npm).
```JSON
    "dependencies": {
        "node-addon-api": "*",
        "bindings": "*" 
```
npm gets the required packages before it builds.<br>
***node-addon-api*** is the C++ wrapper header files.<br>
***bindings*** is a JavaScript tool for resolve file paths (see later in action).<br>
The ```"*"``` means you can install any version.<br>
```JSON
    "gypfile": true
```
We tell npm to use ***node-gyp*** for build.

We use ***node-gyp***, also we need a ***binding.gyp*** file.<br>

```binding.gyp```
```JSON
{
    "targets": [
        {
            "target_name": "parameters",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "sources": [ "parameters.cpp" ],
            "include_dirs": [ "<!@(node -p \"require('node-addon-api').include\")" ],
            "defines": [ "NAPI_DISABLE_CPP_EXEPTIONS" ],
        }
    ]
}
```
```JSON
"include_dirs": [ "<!@(node -p \"require('node-addon-api').include\")" ],
```
In sayhello example we used absolute path for ***node-addon-api***.<br>
***npm*** installs ***node-addon-api*** and ***bindings*** on subfolder ```node_modules```.<br>
This cryptic line calls Node.js for resolve the path of ***node-addon-api***.<br>

We can build now the ***parameters*** example automatically with ***npm***:<br>
```
npm install
```
[🧾Next: Call native module parameters.node from JavaScript ](call_parameters.md)

