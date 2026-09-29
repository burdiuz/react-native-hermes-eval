import { Text, View, StyleSheet } from 'react-native';
import { evaluateJavaScript } from '@actualwave/react-native-hermes-eval';

const result = evaluateJavaScript('1 + 2 + 3 + 4', 'example.js');

export default function App() {
  return (
    <View style={styles.container}>
      <Text>Result: {String(result)}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
