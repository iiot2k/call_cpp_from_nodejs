#include <napi.h>

// function sayhello
Napi::Value sayhello(const Napi::CallbackInfo &info)
{
    return Napi::String::New(info.Env(), "Hello");
}

// function adds symbols to export list
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("sayhello", Napi::Function::New(env, sayhello));
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);


