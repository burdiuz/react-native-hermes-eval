# @actualwave/react-native-hermes-eval

Runs untrusted/dynamic JS source on Hermes at runtime via jsi::Runtime::evaluateJavaScript(), bypassing Hermes' JS-level eval()/new Function() restriction.

## Installation


```sh
npm install @actualwave/react-native-hermes-eval
```


## Usage

```js
import { evaluateJavaScript } from '@actualwave/react-native-hermes-eval';

const result = evaluateJavaScript('1 + 2 + 3', 'my-source.js');
// result === 6
```

`evaluateJavaScript(source, sourceURL?)` compiles and runs a JS source string
directly on Hermes via `jsi::Runtime::evaluateJavaScript()` — the same
primitive React Native itself uses to load the JS bundle. This bypasses
Hermes' restriction on JS-level `eval()`/`new Function()`. `sourceURL`
(default `"user_code.js"`) is used for stack traces and source maps.

The underlying native bridge is installed lazily on first use. To install it
explicitly (e.g. ahead of time, or to check whether installation succeeded),
call `installHermesEval(): boolean`:

```js
import { installHermesEval } from '@actualwave/react-native-hermes-eval';

const ok = installHermesEval();
```


## Contributing

- [Development workflow](CONTRIBUTING.md#development-workflow)
- [Sending a pull request](CONTRIBUTING.md#sending-a-pull-request)
- [Code of conduct](CODE_OF_CONDUCT.md)

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
