#include <napi.h>

using namespace Napi;

// function parameters
Value parameters(const CallbackInfo &info)
{
    // get environment
    Env env = info.Env();

    // check if parameter count is valid
    if ( info.Length() != 3 )
        return String::New(env, "Invalid parameter count");

    // check parameters type
    if ( !info[0].IsBoolean() || !info[1].IsNumber() || !info[2].IsArray() )
        return String::New(env, "Invalid parameter type");

    // get parameters
    bool v_bool = info[0].As<Boolean>();
    uint32_t v_number = info[1].As<Number>().Uint32Value();
    Array v_array = info[2].As<Array>();

    // change and add array elements
    v_array[uint32_t(0)] = Number::New(env, v_number);
    v_array[uint32_t(1)] = String::New(env, "Set string element");
    v_array[uint32_t(2)] = Boolean::New(env, !v_bool);
    v_array[uint32_t(4)] = String::New(env, "Add string element to array");
    
    // return changed array
    return v_array;
}

#define SETFN(fn) exports.Set(#fn, Function::New(env, fn))

// function adds symbols to export list
Object Init(Env env, Object exports)
{
    SETFN(parameters);
    return exports;
}

// macro exports all symbols
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);


