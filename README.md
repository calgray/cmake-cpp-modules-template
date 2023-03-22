# CMake Modules C++20

Example project for C++20 module support in CMake. For more information see https://www.kitware.com/import-cmake-c20-modules/.

## Requirements

* cmake>=3.26
* ninja>=1.11.0
* clang>=16.0.0
* gcc>=13.0.0 (future work)

## Build Command
```
cmake -B build -G Ninja -DCMAKE_CXX_COMPILER=/opt/clang/16.0.0/bin/clang++
cmake --build build
```