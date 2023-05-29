cmake_minimum_required(VERSION 3.26)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED) # NumPy

set(TARGET_NAME pybind11-modules)
add_library(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PUBLIC Python3::Python)
# target_link_libraries(${TARGET_NAME} PUBLIC Python3::Numpy)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::eigen)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::pybind11)
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

# cppm is non-standard by gcc
set_source_files_properties(${SRCS} PROPERTIES LANGUAGE CXX)
