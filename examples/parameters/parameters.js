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
