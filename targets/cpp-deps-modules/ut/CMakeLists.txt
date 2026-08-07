cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME boost-ext-ut-modules)

# set(UT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/resources/ut/include)
find_package(ut CONFIG REQUIRED)
add_library(${TARGET_NAME})

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PRIVATE libcxx)
target_link_libraries(${TARGET_NAME} PUBLIC Boost::ut)

# target_include_directories(${TARGET_NAME} PRIVATE src)
# target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/resources/ut/include)

# target_compile_definitions(${TARGET_NAME} PRIVATE __cpp_modules=1)
# target_compile_definitions(${TARGET_NAME} PRIVATE __cpp_lib_string_view)
# target_compile_definitions(${TARGET_NAME} PRIVATE BOOST_UT_IMPLEMENTATION=1)

target_sources(${TARGET_NAME} PUBLIC
  FILE_SET cxx_modules TYPE CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    src/boost/ut.cppm
)

# cppm is non-standard by gcc
set_source_files_properties(src/ut.cppm PROPERTIES LANGUAGE CXX)