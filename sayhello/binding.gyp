{
    "targets": [
        {
            "target_name": "sayhello",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "sources": [ "sayhello.cpp" ],
            "include_dirs": [ "/usr/lib/node_modules/node-addon-api" ],
            "defines": [ "NAPI_DISABLE_CPP_EXEPTIONS" ],
        }
    ]
}