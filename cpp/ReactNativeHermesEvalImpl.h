#pragma once

#include <ReactNativeHermesEvalSpecJSI.h>

#include <memory>

namespace facebook::react {

class ReactNativeHermesEvalImpl
  : public NativeReactNativeHermesEvalCxxSpec<ReactNativeHermesEvalImpl> {
public:
  ReactNativeHermesEvalImpl(std::shared_ptr<CallInvoker> jsInvoker);

  double multiply(jsi::Runtime& rt, double a, double b);
};

}
