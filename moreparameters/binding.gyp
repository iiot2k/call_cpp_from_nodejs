{
    "targets": [
        {
            "target_name": "moreparameters",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "sources": [ "moreparameters.cpp" ],
            "include_dirs": [ "/usr/lib/node_modules/node-addon-api" ],
            "defines": [ "NAPI_DISABLE_CPP_EXEPTIONS" ],
        }
    ]
}