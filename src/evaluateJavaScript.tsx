export function installHermesEval(): boolean {
  throw new Error(
    "'@actualwave/react-native-hermes-eval' is only supported on native platforms."
  );
}

export function evaluateJavaScript(
  _source: string,
  _sourceURL?: string
): unknown {
  throw new Error(
    "'@actualwave/react-native-hermes-eval' is only supported on native platforms."
  );
}
