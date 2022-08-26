# Call native module parameters.node from JavaScript
🏠[To Home Page](README.md)

```parameters.js```
```javascript
"use strict";

// load parameters.node native module
const mylib = require( "bindings" )( "parameters.node" );

let v_bool = true; // bool
let v_number = 15; // number
let v_array = [2, 10, 5]; // array

// print array
console.log( "Array before: ", v_array );

// call with invalid count of parameters
console.log( mylib.parameters( v_bool ) );

// call with invalid type of parameters
console.log( mylib.parameters( v_array, v_number, v_bool) );

// print changed array as return value
console.log( "Array after return value: ", mylib.parameters( v_bool, v_number, v_array ) );

// print array 
console.log( "Array after: ", v_array );
```
Run this JavaScript program on command line:<br>

```
node ./
```
I omit the explanation of this JavaScript code.<br>
You are all JavaScript experts.<br>
But this line needs explanation:
```
const mylib = require( "bindings" )( "parameters.node" );
```
This line loads the native module ***parameters.node***.<br>
The ***bindings*** JavaScript module search the native module ***parameters.node***<br>
and returns the path.<br>
This module is installed during build in subfolder ```node_modules```.<br> 

This is the output of JavaScript program:
```
Array before:  [ 2, 10, 5 ]
Invalid parameter count
Invalid parameter type
Array after return value:  [
  15,
  'Set string element',
  false,
  <1 empty item>,
  'Add string element to array'
]
Array after:  [
  15,
  'Set string element',
  false,
  <1 empty item>,
  'Add string element to array'
]
```
Please look at the last two ```console.log``` outputs.<br>
First outputs is the in native module changed array.<br>
Seconds outputs is the array in the JavaScript program.<br>
Both are same.<br>
All JavaScript variables are transferred as reference in parameters.<br>
The native module has changed the JavaScript array.<br>


```to be continued```

