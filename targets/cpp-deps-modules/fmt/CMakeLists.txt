cmake_minimum_required(VERSION 3.26)

set(FMT_SUBMODULE OFF)
if(FMT_SUBMODULE)
  set(fmt_DIR "${PROJECT_SOURCE_DIR}/resources/fmt")
  find_package(fmt REQUIRED)
else()
  find_package(fmt CONFIG REQUIRED)
endif()

set(TARGET_NAME fmt-modules)
add_library(${TARGET_NAME})

# set_target_properties(TARGET ${TARGET_NAME} PROPERTIES CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PUBLIC fmt::fmt)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${SRCS}
)
