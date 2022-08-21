"use strict";

// load moreparameters.node native module
const mylib = require("./build/Release/moreparameters.node");

var v_bool = true; // bool
var v_number = 15; // number
var v_array = [2,10,5]; // array

// print array
console.log("Array before: ", v_array);

// call with invalid count of parameter
console.log(mylib.moreparameters(v_bool));

// print changed array
console.log("Array after: ", mylib.moreparameters(v_bool, v_number, v_array));

