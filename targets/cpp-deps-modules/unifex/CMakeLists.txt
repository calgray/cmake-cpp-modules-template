cmake_minimum_required(VERSION 3.26)

set(UNIFEX_SUBMODULE OFF)
if(UNIFEX_SUBMODULE)
  set(unifex_DIR "${PROJECT_SOURCE_DIR}/resources/unifex")
  find_package(unifex REQUIRED)
else()
  find_package(unifex CONFIG REQUIRED)
endif()

set(TARGET_NAME unifex-modules)
add_library(${TARGET_NAME})

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PUBLIC unifex::unifex)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${SRCS}
)


# HEADER PATCHES
set(UNIFEX_PATCH
  ${CMAKE_CURRENT_SOURCE_DIR}/patches/patch_unifex_with_scheduler_affinity.patch
)

set(UNIFEX_PATCH_STAMP
  ${CMAKE_CURRENT_BINARY_DIR}/unifex-patch.stamp
)

get_target_property(UNIFEX_LIB_DIR unifex::unifex INTERFACE_INCLUDE_DIRECTORIES)
add_custom_command(
    OUTPUT ${UNIFEX_PATCH_STAMP}
    COMMAND
        patch -N -d ${UNIFEX_LIB_DIR} -p1 < ${UNIFEX_PATCH}
        || patch -R --dry-run -d ${UNIFEX_LIB_DIR} -p1 < ${UNIFEX_PATCH}
    COMMAND
        ${CMAKE_COMMAND} -E touch ${UNIFEX_PATCH_STAMP}
    COMMAND_EXPAND_LISTS
    DEPENDS ${UNIFEX_PATCH}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    VERBATIM
)

add_custom_target(unifex-patch DEPENDS ${UNIFEX_PATCH_STAMP})
add_dependencies(unifex-modules unifex-patch)
