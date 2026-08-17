cmake_minimum_required(VERSION 3.26)

find_package(Eigen3 CONFIG REQUIRED)

add_library(eigen-modules)
target_link_libraries(eigen-modules PUBLIC Eigen3::Eigen)
target_link_libraries(eigen-modules PUBLIC libcxx)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(eigen-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

# cppm is non-standard by gcc
set_source_files_properties(${SRCS} PROPERTIES LANGUAGE CXX)

# HEADER PATCHES
set(EIGEN_PATCH
    ${CMAKE_CURRENT_SOURCE_DIR}/patches/patch_eigen_5_0_1_static.patch
)
set(EIGEN_PATCH_STAMP
    ${CMAKE_CURRENT_BINARY_DIR}/eigen-patch.stamp
)

get_target_property(EIGEN_LIB_DIR Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
add_custom_command(
    OUTPUT ${EIGEN_PATCH_STAMP}
    COMMAND
        patch -N -d ${EIGEN_LIB_DIR} -p2 < ${EIGEN_PATCH}
        || patch -R --dry-run -d ${EIGEN_LIB_DIR} -p2 < ${EIGEN_PATCH}
    COMMAND
        ${CMAKE_COMMAND} -E touch ${EIGEN_PATCH_STAMP}
    COMMAND_EXPAND_LISTS
    DEPENDS ${EIGEN_PATCH}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    VERBATIM
)

add_custom_target(eigen-patch DEPENDS ${EIGEN_PATCH_STAMP})
add_dependencies(eigen-modules eigen-patch)
