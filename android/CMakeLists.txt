cmake_minimum_required(VERSION 3.4.1)
project(ReactNativeHermesEval)

set (CMAKE_VERBOSE_MAKEFILE ON)

add_library(
    actualwave-react-native-hermes-eval    STATIC
    ../cpp/ReactNativeHermesEvalImpl.cpp
)

set_target_properties(
    actualwave-react-native-hermes-eval PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(
    actualwave-react-native-hermes-eval    PUBLIC
    ../cpp
)

target_link_libraries(
    actualwave-react-native-hermes-eval    jsi
    reactnative
    react_codegen_ReactNativeHermesEvalSpec
)
