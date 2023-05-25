cmake_minimum_required(VERSION 3.26)
project(std_module_example C CXX)

# C++ Modules
# CMake 3.25
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "3c375311-a3c9-4396-a187-3227ef642046")
# CMake 3.26
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16.0)
    message(FATAL_ERROR "Only Clang 16.0.0 and greater supported for modules")
  endif()
  include(cmake/clang_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(cmake/gcc_modules.cmake)
endif()

# Ninja has a bug where color terminal isnt detected when piping
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
endif()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_HOST_COMPILER clang)
set(CMAKE_CUDA_ARCHITECTURES 86)
enable_language(CXX CUDA)

# Conan
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(isMultiConfig)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake) # Include Conan-generated file
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
endif()
conan_basic_setup(TARGETS) # Introduce Conan-generated targets


add_subdirectory(modules/stdcxx)
add_subdirectory(modules/range-v3)
add_subdirectory(modules/cppcoro)
add_subdirectory(modules/fmt)
add_subdirectory(modules/eigen)
add_subdirectory(modules/cuda)
add_subdirectory(modules/ut)

add_subdirectory(foobar)
add_subdirectory(helloworld)
