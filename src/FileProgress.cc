#include <napi.h>
#include "FileProgress.h"
#include "Progress.h"

using namespace Napi;

Napi::FunctionReference FileProgress::constructor;

Napi::Object FileProgress::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "FileProgress", {
        InstanceMethod("update", &FileProgress::UpdateProgress),
        InstanceMethod("cancel", &FileProgress::CancelProgress),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("FileProgress", func);
    return exports;
};


FileProgress::FileProgress(const Napi::CallbackInfo& info): Napi::ObjectWrap<FileProgress>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    std::string path = info[0].As<Napi::String>().ToString();
    int64_t total = info[1].As<Napi::Number>().Int64Value();
    this->progress_ = createProgress(path, total);
};


Napi::Object FileProgress::NewInstance(Napi::Env env, Napi::Value arg) {
    Napi::EscapableHandleScope scope(env);
    Napi::Object obj = constructor.New({ arg });
    return scope.Escape(napi_value(obj)).ToObject();
};

void FileProgress::UpdateProgress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    int64_t current = info[0].As<Napi::Number>().Int64Value();
    updateProgress(this->progress_, current);
};

void FileProgress::CancelProgress(const Napi::CallbackInfo& info) {

};
