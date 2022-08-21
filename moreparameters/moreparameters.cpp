#include <napi.h>

using namespace Napi;

// function moreparameters
Value moreparameters(const CallbackInfo &info)
{
    // check if parameter count is valid
    if (info.Length() != 3)
        return String::New(info.Env(), "Invalid call");

    // get parameters
    bool v_bool = info[0].As<Boolean>();
    uint32_t v_number = info[1].As<Number>().Uint32Value();
    Array v_array = info[2].As<Array>();

    // change array elements
    v_array[uint32_t(0)] = Number::New(info.Env(), v_number);
    v_array[uint32_t(1)] = String::New(info.Env(), "String element");
    v_array[uint32_t(2)] = Boolean::New(info.Env(), !v_bool);
    
    // return changed array
    return v_array;
}

// function adds symbols to export list
Object export_all(Env env, Object exports)
{
    exports.Set("moreparameters", Function::New(env, moreparameters));
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, export_all);


