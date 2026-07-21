cmake_minimum_required(VERSION 3.26)

set(NANOBENCH_LOCATION "CONAN")
if(NANOBENCH_LOCATION STREQUAL "SUBMODULE")
  set(nonobench_DIR "${PROJECT_SOURCE_DIR}/resources/nanobench")
  find_package(nanobench REQUIRED)
else()
  find_package(nanobench CONFIG REQUIRED)
endif()

set(TARGET_NAME nanobench-modules)
add_library(${TARGET_NAME})

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PUBLIC nanobench::nanobench)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${SRCS}
)
