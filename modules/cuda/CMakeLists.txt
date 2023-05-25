cmake_minimum_required(VERSION 3.26)

find_package(CUDAToolkit REQUIRED)
enable_language(CUDA)

set(TARGET_NAME cuda-modules)
add_library(${TARGET_NAME})
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
target_compile_definitions(${TARGET_NAME} PRIVATE __cpp_modules=1)
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)
target_link_libraries(${TARGET_NAME} PUBLIC CUDA::cudart)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)
