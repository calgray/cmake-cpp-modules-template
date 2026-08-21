cmake_minimum_required(VERSION 3.26)

# std module; check specific cmake releases at
# https://github.com/Kitware/CMake/blob/v4.3.2/Help/dev/experimental.rst#c-import-std-support
message("cmake: ${CMAKE_VERSION}")
if (CMAKE_VERSION VERSION_LESS "4.0.3")
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
elseif (CMAKE_VERSION VERSION_LESS "4.3.0")
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
elseif (CMAKE_VERSION VERSION_LESS "4.4.0")
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
else()
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
endif()

# Project + Language
project(cmake_cpp_modules_template C CXX)

# automatic for CXX_MODULES file sets
# set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# MSVC and Clang have good C++23 stdlib module support
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # Disable linking to compiler included std library module
  # will instead link std to libcxx wrapper
  set(CMAKE_CXX_MODULE_STD OFF)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # problematic in github CI
  set(CMAKE_CXX_MODULE_STD OFF)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  # not supported
  set(CMAKE_CXX_MODULE_STD OFF)
else()
  set(CMAKE_CXX_MODULE_STD ON)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Options
option(ENABLE_EIGEN      "Add Eigen support?" OFF)
option(ENABLE_CUDA      "Add Cuda support?" OFF)
option(BUILD_TESTING    "Enable Testing?" ON)


if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16.0)
  message(FATAL_ERROR "Only Clang 16.0.0 and greater supported for modules")
endif()
include(cmake/cpp_modules.cmake)

# Ninja has a bug where color terminal isnt detected when piping
if (CMAKE_GENERATOR STREQUAL "Ninja Multi-Config")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
  endif()
endif()

if(ENABLE_CUDA)
  # NOTE: put these in a toolchain
  # set(CMAKE_CUDA_HOST_COMPILER clang)
  # set(CMAKE_CUDA_ARCHITECTURES 86 CACHE STRING "CUDA architectures")
  # set(CMAKE_CUDA_STANDARD 20 CACHE STRING "CUDA standard")
  # set(CMAKE_CUDA_STANDARD $ENV{CMAKE_CUDA_STANDARD})
  # set(CMAKE_CUDA_ARCHITECTURES $ENV{CMAKE_CUDA_ARCHITECTURES})
  enable_language(CXX CUDA)
else()
  enable_language(CXX)
endif()

if(BUILD_TESTING)
  enable_testing()
endif()

add_subdirectory(targets)
