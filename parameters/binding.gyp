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
