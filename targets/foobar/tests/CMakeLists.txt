cmake_minimum_required(VERSION 3.26)

# ========================
# Non-Performance Tests
# ========================

set(TARGET_NAME foobar-tests)
add_executable(${TARGET_NAME})

set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_SCAN_FOR_MODULES ON
)

target_link_libraries(${TARGET_NAME} PRIVATE libcxx)
target_link_libraries(${TARGET_NAME} PRIVATE unifex-modules)
target_link_libraries(${TARGET_NAME} PRIVATE foobar)
target_link_libraries(${TARGET_NAME} PRIVATE boost-ext-ut-modules)

target_sources(${TARGET_NAME} PUBLIC
  main.cxx
  unit/test_foo_ranges.cxx
  unit/test_bar.cxx
  unit/test_cycle.cxx
  unit/test_bdd.cxx
  unit/test_fibonacci.cxx
  unit/test_headers.cxx
)
if(ENABLE_EIGEN)
  target_link_libraries(${TARGET_NAME} PUBLIC eigen-modules)
  target_sources(${TARGET_NAME} PUBLIC
    unit/test_eigen_dense.cxx
    unit/test_eigen_tensor.cxx
  )
endif()
if(ENABLE_CUDA)
  target_link_libraries(${TARGET_NAME} PUBLIC cuda-modules)
  target_sources(${TARGET_NAME} PUBLIC
    unit/test_cuda_hello.cxx
  )
endif()

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})

# ========================
# Performance Tests
# ========================

set(TARGET_NAME foobar-performance-tests)
add_executable(${TARGET_NAME})

set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_SCAN_FOR_MODULES ON
)

# set_property(TARGET ${TARGET_NAME} PROPERTY CXX_MODULE_STD ON)
target_link_libraries(${TARGET_NAME} PRIVATE libcxx)
target_link_libraries(${TARGET_NAME} PRIVATE foobar)
target_link_libraries(${TARGET_NAME} PRIVATE boost-ext-ut-modules)
target_link_libraries(${TARGET_NAME} PRIVATE nanobench-modules)

target_sources(${TARGET_NAME} PUBLIC
  performance/main.cxx
  performance/benchmark_example.cxx
  performance/benchmark_unifex.cxx
)

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
