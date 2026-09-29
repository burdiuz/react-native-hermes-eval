#pragma once

#include <ReactNativeHermesEvalSpecJSI.h>

#include <memory>

namespace facebook::react {

class ReactNativeHermesEvalImpl
  : public NativeReactNativeHermesEvalCxxSpec<ReactNativeHermesEvalImpl> {
public:
  ReactNativeHermesEvalImpl(std::shared_ptr<CallInvoker> jsInvoker);

  bool install(jsi::Runtime& rt);
};

}
