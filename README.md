# CMake C++20 Modules Template

Template project for C++20 module support in CMake. For more information see https://www.kitware.com/import-cmake-c20-modules/.

## Features

* Conan support and profiles
* Modularized library targets for common libraries
* Sample unit tests

## Libraries

| Library     |   Import Name | CMake Target         |
|:------------|:--------------|:---------------------|
| std         | stdcxx        | stdcxx               |
| fmt         | fmt.core      | fmt-modules          |
| range-v3    | range_v3      | range-v3-modules     |
| cppcoro     | cppcoro       | cppcoro-modules      |
| boost-ex-ut | boost.ut      | boost-ext-ut-modules |


## Requirements

* cmake>=3.26
* ninja>=1.11.0
* clang>=16.0.0
* gcc>=13.0.0 (future work)

## Build Command (Ninja+Clang)
```
mkdir build
conan install . -g cmake_multi -if build -s build_type=Debug --build=missing --profile=profile.txt
conan install . -g cmake_multi -if build -s build_type=Release --build=missing --profile=profile.txt
cmake -B build -G "Ninja Multi-Config" -DCMAKE_CXX_COMPILER=/opt/clang/16.0.0/bin/clang++ -DCONAN_COMPILER=clang
cmake --build build --config Release

./build/helloworld/Release/helloworld
```

## Notes

Clang supports either:

* GNU std library (-stdlib=libstdc++) which can ONLY be exported via header units. See `stdhu`.
* Clang 16 std library (-stdlib=libc++) which can ONLY be exported via a std module. Use `stdcxx` and `foobar`

The later is better for now in preparing libraries for modules.



## Testing
```
./build/foobar/tests/Release/foobar_tests
```
