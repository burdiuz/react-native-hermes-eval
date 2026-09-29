#include "ReactNativeHermesEvalImpl.h"

#include <string>
#include <utility>

namespace facebook::react {

ReactNativeHermesEvalImpl::ReactNativeHermesEvalImpl(
  std::shared_ptr<CallInvoker> jsInvoker
)
  : NativeReactNativeHermesEvalCxxSpec(std::move(jsInvoker)) {}

// Installs a global `__hermesEval(source, sourceURL?)` function that compiles
// and runs a JS source string via jsi::Runtime::evaluateJavaScript(), the same
// primitive React Native itself uses to load the JS bundle. Hermes blocks
// JS-level eval()/new Function(), but does not restrict this JSI entry point.
bool ReactNativeHermesEvalImpl::install(jsi::Runtime& rt) {
  auto evalFn = jsi::Function::createFromHostFunction(
    rt,
    jsi::PropNameID::forAscii(rt, "__hermesEval"),
    2,
    [](jsi::Runtime& innerRt,
       const jsi::Value& /* thisVal */,
       const jsi::Value* args,
       size_t count) -> jsi::Value {
      if (count < 1 || !args[0].isString()) {
        return jsi::Value::undefined();
      }

      auto source = args[0].asString(innerRt).utf8(innerRt);
      auto buffer = std::make_shared<jsi::StringBuffer>(std::move(source));

      std::string sourceURL = "user_code.js";
      if (count >= 2 && args[1].isString()) {
        sourceURL = args[1].asString(innerRt).utf8(innerRt);
      }

      return innerRt.evaluateJavaScript(buffer, sourceURL);
    }
  );

  rt.global().setProperty(rt, "__hermesEval", std::move(evalFn));
  return true;
}

}
