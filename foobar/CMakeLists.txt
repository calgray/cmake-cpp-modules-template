cmake_minimum_required(VERSION 3.25)

add_library(foobar)
target_compile_features(foobar PUBLIC cxx_std_20)
# target_link_libraries(foobar PUBLIC stdhu)
target_link_libraries(foobar PUBLIC stdcxx)
# target_link_libraries(foobar PUBLIC fmtm)
target_link_libraries(foobar PUBLIC rangev3)
target_link_libraries(foobar PUBLIC cppcoro)

target_sources(foobar PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    FILES
        src/foo.cxx
        src/bar.cxx
        src/cycle.cxx
        src/cycleA.cxx
        src/cycleB.cxx
)
add_subdirectory(tests)
