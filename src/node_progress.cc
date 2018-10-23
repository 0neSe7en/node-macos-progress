#include <napi.h>
#include "FileProgress.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    return FileProgress::Init(env, exports);
}

NODE_API_MODULE(macos_progress, InitAll)
