#include <napi.h>

using namespace Napi;

// function sayhello
Value sayhello(const CallbackInfo &info)
{
    return String::New(info.Env(), "Hello");
}

// function adds symbols to export list
Object export_all(Env env, Object exports)
{
    exports.Set("sayhello", Function::New(env, sayhello));
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, export_all);


