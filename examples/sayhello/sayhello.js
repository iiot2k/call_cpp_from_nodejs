"use strict";

// load sayhello.node native module
const mylib = require( "./build/Release/sayhello.node" );

// list all exports in sayhello.node
console.log( "Module exports: ", mylib );

// call function sayhello in module sayhello.node
console.log( mylib.sayhello() );