#include "ReactNativeHermesEvalImpl.h"

namespace facebook::react {

ReactNativeHermesEvalImpl::ReactNativeHermesEvalImpl(
  std::shared_ptr<CallInvoker> jsInvoker
)
  : NativeReactNativeHermesEvalCxxSpec(std::move(jsInvoker)) {}

double ReactNativeHermesEvalImpl::multiply(
  jsi::Runtime& rt,
  double a,
  double b
) {
  return a * b;
}

}
