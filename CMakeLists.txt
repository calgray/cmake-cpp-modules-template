cmake_minimum_required(VERSION 3.26)
project(std_module_example CXX)

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

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(foobar)
add_subdirectory(helloworld)