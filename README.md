# CMake C++20 Modules Template

Template project for C++20 module support in CMake. For more information see https://www.kitware.com/import-cmake-c20-modules/.

## Features

* Conan support and profiles
* Modularized library targets for common libraries
* Sample unit tests

## Libraries

| Library     | Import Name   | CMake Target         |
|:------------|:--------------|:---------------------|
| std         | stdcxx        | stdcxx               |
| fmt         | fmt.core      | fmt-modules          |
| range-v3    | range_v3      | range-v3-modules     |
| cppcoro     | cppcoro       | cppcoro-modules      |
| Eigen       | eigen         | eigen-modules        |
| boost-ex-ut | boost.ut      | boost-ext-ut-modules |

(module std is reserved for future standards)

## Requirements

* cmake>=3.26
* ninja>=1.11.0
* clang>=16.0.0
* gcc>=13.0.0 (future work)

## Building with Ninja + Clang
```
mkdir -p build/clang
conan install . -g cmake_multi -if build/clang -s build_type=Debug --build=missing --profile=profile-clang.txt
conan install . -g cmake_multi -if build/clang -s build_type=Release --build=missing --profile=profile-clang.txt
cmake -B build/clang -G "Ninja Multi-Config" -DCMAKE_CXX_COMPILER=/opt/clang/16.0.0/bin/clang++ -DCONAN_COMPILER=clang -DCONAN_COMPILER_VERSION=16
cmake --build build/clang --config Release -j8
```

## Build with Ninja + GCC (Experimental)
```
mkdir -p build/gcc
conan install . -g cmake_multi -if build/gcc -s build_type=Debug --build=missing --profile=profile-gcc.txt
conan install . -g cmake_multi -if build/gcc -s build_type=Release --build=missing --profile=profile-gcc.txt
cmake -B build/gcc -G "Ninja Multi-Config"
```

## Notes

GCC not fully supported due to not recognizing `using` alias re-exports. Header unit modules are often prefered by gcc tutorials.

Clang supports either:

* Clang 16 std library (-stdlib=libc++) which can ONLY be exported via a std module. Use `profile-clang.txt`
* GNU std library (-stdlib=libstdc++) Using `profile-stdclang.txt`


## Testing
```
./build/foobar/clang/tests/Release/foobar_tests
```
