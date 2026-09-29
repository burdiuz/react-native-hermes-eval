import ReactNativeHermesEval from './NativeReactNativeHermesEval';

declare const global: {
  __hermesEval?: (source: string, sourceURL?: string) => unknown;
};

let installed = false;

export function installHermesEval(): boolean {
  if (!installed) {
    installed = ReactNativeHermesEval.install();
  }

  return installed;
}

export function evaluateJavaScript(
  source: string,
  sourceURL?: string
): unknown {
  if (!installHermesEval() || typeof global.__hermesEval !== 'function') {
    throw new Error(
      "'@actualwave/react-native-hermes-eval' failed to install the Hermes eval bridge."
    );
  }

  return global.__hermesEval(source, sourceURL);
}
