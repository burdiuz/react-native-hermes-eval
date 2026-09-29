#import <Foundation/Foundation.h>
#import "ReactNativeHermesEvalImpl.h"
#import <ReactCommon/CxxTurboModuleUtils.h>

@interface ReactNativeHermesEvalOnLoad : NSObject
@end

@implementation ReactNativeHermesEvalOnLoad

using namespace facebook::react;

+ (void)load
{
  registerCxxModuleToGlobalModuleMap(
    std::string(ReactNativeHermesEvalImpl::kModuleName),
    [](std::shared_ptr<CallInvoker> jsInvoker) {
      return std::make_shared<ReactNativeHermesEvalImpl>(jsInvoker);
    }
  );
}

@end
