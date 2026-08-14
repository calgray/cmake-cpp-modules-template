# CMake C++ Modules Template

Template project for C++20/23 module support in CMake. For more information see <https://www.kitware.com/import-cmake-c20-modules/>.

> [!NOTE]
> This template is work-in-progress with code and test examples rather than configurable template generation as compile features arrive.

## Requirements

### Tools

* cmake>=3.26
* ninja>=1.11.1

### Compilers

One of:

* clang>=17.0.0
* gcc>=15.0.0
* msvc>=2023

## Structure

```shell
<project-name>  # root folder/repo name
├── README.md  # project readme
├── profile-<my-profile>.txt  # conan toolchain profile
├── conanfile.txt  # conan cmake generator configuration
├── CMakeLists.txt  # cmake root project configuration
├── cmake/  # cmake scripts
│   ├── CPM.cmake  # extra package management
│   ├── cpp_modules.cmake
│   └── <cpp-target-0>Config.cmake.in
└── targets/  # project targets folder (can organize targets with any folder naming)
    ├── CMakeLists.txt
    ├── modules/  # C++ dependencies requiring a module wrapper
    │   ├── libcxx/  # std library wrapper module
    │   │   ├── CMakeLists.txt
    │   │   ...
    │   ├── <wrapper-lib-1>/
    │   ├── <wrapper-lib-2>/
    │   └── <wrapper-lib-3>/
    ├── <cpp-target-0>/  # executable or library target
    │   ├── CMakeLists.txt  # cpp-target-0 cmake target configuration
    │   ├── include/  # public headers (optional)
    │   ├── src/  # source files and private headers
    │   └── tests/  # test source
    ├── <cpp-target-1>/  # executable or library target
    │   ├── CMakeLists.txt  # cpp-target-1 cmake target configuration
    │   ├── include/
    │   ├── src/
    │   └── tests/
    ├── <cpp-target-2>/  # executable or library target
    │   ├── CMakeLists.txt  # cpp-target-2 cmake target configuration
    │   ├── include/
    │   ├── src/
    │   └── tests/
    ...
```

## Features

* C++20 modules, concepts, ranges, and coroutines examples and tests.
* C++23 std module, `std::print` and `std::println` examples and tests.
* Unifex precursor to C++26 `std::execution`.
* Dependency resolution hierarchy support:
  * Conan
  * CPM
  * Git Submodule
  * System Environment

* Modularized library targets for common core libraries:

| Library     | Import Name   | CMake Target         | Tested |
|:------------|:--------------|:---------------------|:-------|
| std         | std           | libcxx               | true   |
| fmt         | fmt.core      | fmt-modules          | true   |
| range-v3    | range_v3      | range-v3-modules     | true   |
| Eigen       | eigen         | eigen-modules        | true   |
| cli11       |  cli11        | cli11-modules        | true   |
| libunifex   | unifex        | unifex-modules       | true   |
| boost-ex-ut | boost.ut      | boost-ext-ut-modules | true   |
| nanobench   | nanobench     | nanobench-modules    | true   |
| Cuda (experimental) | cuda  | cuda-modules         | false  |

## Build and Test

### Clang

```bash
export CONAN_PROFILE=profile-clang-<machine-name>.txt

# conan deps
conan install -of build/clang -s build_type=Debug -b=missing -pr:h=${CONAN_PROFILE} -pr:b=${CONAN_PROFILE} .
conan install -of build/clang -s build_type=Release -b=missing -pr:h=${CONAN_PROFILE} -pr:b=${CONAN_PROFILE} .
# generate
cmake -B build/clang --preset=conan-clang-x86_64
# build
cmake --build build/clang --config Release -j8
# test
ctest -preset=${CONAN_PROFILE} --no-compress-output --verbose
```

### GNU

```bash
export CONAN_PROFILE=profile-gcc-<machine-name>.txt

# conan deps
conan install -of build/gcc -s build_type=Debug -b=missing -pr:h=${CONAN_PROFILE} -pr:b=${CONAN_PROFILE} .
conan install -of build/gcc -s build_type=Release -b=missing -pr:h=${CONAN_PROFILE} -pr:b=${CONAN_PROFILE} .
# generate
cmake -B build/gcc --preset=conan-gcc-x86_64
# build
cmake --build build/gcc --config Release -j8
# test
ctest -preset=${CONAN_PROFILE} --no-compress-output --verbose
```

## Dockerfile

### Clang

```bash
# build
docker build -t cmake-cpp-modules-template-clang -f docker/Dockerfile-clang .
# test
docker run --security-opt seccomp=unconfined -it --rm cmake-cpp-modules-template-clang
```

### GNU

```bash
# build
docker build -t cmake-cpp-modules-template-gcc -f docker/Dockerfile-gcc .
# test
docker run --security-opt seccomp=unconfined -it --rm cmake-cpp-modules-template-gcc
```
