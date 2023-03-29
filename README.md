# CMake Modules C++20

Example project for C++20 module support in CMake. For more information see https://www.kitware.com/import-cmake-c20-modules/.

## Requirements

* cmake>=3.26
* ninja>=1.11.0
* clang>=16.0.0
* gcc>=13.0.0 (future work)

## Build Command
```
mkdir build
conan install . -g cmake_multi -if build -s build_type=Release --build=missing
conan install . -g cmake_multi -if build -s build_type=Debug --build=missing
cmake -B build -G "Ninja Multi-Config" -DCMAKE_CXX_COMPILER=/opt/clang/16.0.0/bin/clang++ -DCONAN_COMPILER=clang
cmake --build build --config Release

./build/helloworld/Release/helloworld
```

# Notes

* Clang supports both:

GNU std library (-stdlib=libstdc++) which
can ONLY be exported via header units. Use
`stdhu` with `minimal`

or 

Clang 16 std library (-stdlib=libc++) which
can ONLY be exported via a std module. Use
`stdcxx` and `foobar`

The later is better in preparing libraries for
module exporting.



## Testing
```
./build/foobar/tests/Release/foobar_tests
```
