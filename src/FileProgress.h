#ifndef FILEPROGRESS_H
#define FILEPROGRESS_H

#include <napi.h>

using namespace Napi;

class FileProgress : public Napi::ObjectWrap<FileProgress> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        static Napi::Object NewInstance(Napi::Env env, Napi::Value arg);
        FileProgress(const Napi::CallbackInfo& info);

    private:
        static Napi::FunctionReference constructor;
        void UpdateProgress(const Napi::CallbackInfo& info);
        void CancelProgress(const Napi::CallbackInfo& info);
        void* progress_;
};

#endif
