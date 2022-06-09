#include "funcinfo.h"

using namespace v8;

NAN_METHOD(FuncInfo) {
    Local<Function> fn = Local<Function>::Cast(info[0]);

    Local<Object> obj = Nan::New<Object>();
    Local<Value> resourceName = fn->GetScriptOrigin().ResourceName();

    if (!resourceName.IsEmpty()) {
        // file
        Nan::Set(obj, Nan::New<String>("file").ToLocalChecked(), resourceName);

        // lineNumber
        Nan::Set(obj,
                 Nan::New<String>("lineNumber").ToLocalChecked(),
                 Nan::New<Integer>(fn->GetScriptLineNumber()));
    }

    info.GetReturnValue().Set(obj);
}
