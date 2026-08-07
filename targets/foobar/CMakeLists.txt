cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME foobar)
add_library(${TARGET_NAME})

set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_SCAN_FOR_MODULES ON
)

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PRIVATE libcxx)
target_link_libraries(${TARGET_NAME} PUBLIC fmt-modules)
target_link_libraries(${TARGET_NAME} PUBLIC range-v3-modules)
target_link_libraries(${TARGET_NAME} PUBLIC unifex-modules)
if(ENABLE_CUDA)
  target_link_libraries(${TARGET_NAME} PUBLIC cuda-modules)
endif()

target_include_directories(${TARGET_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_sources(${TARGET_NAME} PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  FILES
    src/foo.cppm
    src/bar.cppm
    src/cycle.cppm
    src/cycle.fwd.cppm
    src/cycle.A.cppm
    src/cycle.B.cppm
    src/fibonacci.cppm
)

if(ENABLE_CUDA)
  target_sources(${TARGET_NAME} PUBLIC
    src/cuda_hello.cu
  )
  target_sources(${TARGET_NAME} PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
      ${CMAKE_CURRENT_SOURCE_DIR}/src
    FILES
      src/cuda_hello.cppm
  )
endif()

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()