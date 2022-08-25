# Call native module sayhello.node from JavaScript

🏠[To Home Page](README.md)

We build the native module ***sayhello.node*** and now we call it from JavaScript. <br>

Select menu ***File->New File ...***<br>
Enter ***sayhello.js*** and press **enter** key then ***Create File*** button.<br>

Enter this JavaScript program:<br>

```javascript
"use strict";

// load sayhello.node native module
const mylib = require("./build/Release/sayhello.node");

// list all exports in sayhello.node
console.log( "Module exports: ", mylib );

// call function sayhello in module sayhello.node
console.log( mylib.sayhello() );
```

Save File with ***File->Save***.<br>

Open command line windows if not open (Menu ***Terminal->New Terminal***).<br>

Enter command:
```
node sayhello.js
```
If you get errors, you have mistyped in ***sayhello.js*** file,<br>
else this is the output:<br>
```
Module exports: { sayhello: [Function (anonymous)]}
Hello
```

[🧾Next: Parameters on call of native function ](parameters.md)<br>

