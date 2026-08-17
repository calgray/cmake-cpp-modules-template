# The headers of Table 24: C++ library headers [tab:headers.cpp]
# and the headers of Table 25: C++ headers for C library facilities [tab:headers.cpp.c]
cmake_minimum_required(VERSION 3.26)

# Library from https://github.com/ChuanqiXu9/stdmodules
# and https://github.com/llvm/llvm-project/blob/main/libcxx/modules/std
set(TARGET_NAME libcxx)
add_library(${TARGET_NAME})

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(${TARGET_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-stdlib=libc++>)
  target_link_options(${TARGET_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-stdlib=libc++>)
  target_compile_options(${TARGET_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wmodule-conflict>)
endif()

target_compile_definitions(${TARGET_NAME} PRIVATE CXX_MODULE_STD=$<BOOL:${CMAKE_CXX_MODULE_STD}>)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_USING_IF_EXISTS=)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_STD_VER=23)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_HAS_LOCALIZATION=1)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_HAS_WIDE_CHARACTERS=1)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_HAS_THREADS=1)
target_compile_definitions(${TARGET_NAME} PRIVATE _LIBCPP_HAS_RANDOM_DEVICE=1)

target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    std.cppm
    std.compat.cppm
)