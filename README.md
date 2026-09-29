# @actualwave/react-native-hermes-eval

Runs untrusted/dynamic JS source on Hermes at runtime via jsi::Runtime::evaluateJavaScript(), bypassing Hermes' JS-level eval()/new Function() restriction.

## Installation


```sh
npm install @actualwave/react-native-hermes-eval
```


## Usage


```js
import { multiply } from '@actualwave/react-native-hermes-eval';

// ...

const result = multiply(3, 7);
```


## Contributing

- [Development workflow](CONTRIBUTING.md#development-workflow)
- [Sending a pull request](CONTRIBUTING.md#sending-a-pull-request)
- [Code of conduct](CODE_OF_CONDUCT.md)

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
