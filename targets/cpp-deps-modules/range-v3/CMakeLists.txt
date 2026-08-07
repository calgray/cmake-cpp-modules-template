cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME range-v3-modules)
find_package(range-v3 CONFIG REQUIRED)

add_library(${TARGET_NAME})

# target_compile_definitions(${TARGET_NAME} PRIVATE __cpp_lib_string_view=1)
target_compile_definitions(${TARGET_NAME} PRIVATE __cpp_coroutines=202000L)

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PUBLIC range-v3::range-v3)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${SRCS}
)
