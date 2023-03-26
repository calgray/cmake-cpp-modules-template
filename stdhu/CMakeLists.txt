cmake_minimum_required(VERSION 3.25)


# TODO: CMAKE doesnt fully support CXX_MODULE_HEADER_UNITS
# add_library(stdcxx_header_units OBJECT)
# set_target_properties(stdcxx_header_units PROPERTIES LINKER_LANGUAGE CXX)
# target_compile_features(stdcxx_header_units PUBLIC cxx_std_20)
# target_sources(stdcxx_header_units PUBLIC
#     FILE_SET cxx_header_units TYPE CXX_MODULE_HEADER_UNITS
#     BASE_DIRS
#         /usr/include/c++/12.2.1
#         ${CMAKE_CURRENT_SOURCE_DIR}
#     FILES
#         /usr/include/c++/12.2.1/vector
#         /usr/include/c++/12.2.1/iostream
# )


set(STD_MODULES
    coroutine
    string
    iostream
    numeric
    vector
    thread
    chrono
    map
    mutex
    atomic
    random
    fstream
    memory
    exception
    stdexcept
    utility
    algorithm
    array
    functional
    type_traits
    iterator
    list
    condition_variable
    queue
    tuple
    initializer_list
    limits
    cctype
    cfenv
    cinttypes
    clocale
    #cmath
    csetjmp
    csignal
    cstdarg
    cstddef
    cstdint
    cstdio
    cstdlib
    cstring
    ctime
    cuchar
    cwchar
    cwctype
)
add_custom_target(std_header_units ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Building standard library header units"
    COMMAND
        ${CMAKE_CXX_COMPILER}
        -std=c++20
        -c -x c++-system-header ${STD_MODULES}
        # --precompile
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_library(stdhu OBJECT)
target_compile_features(stdhu PUBLIC cxx_std_20)
add_dependencies(stdhu std_header_units)
target_compile_options(stdhu PUBLIC
    -fmodule-file=iostream.pcm
    -fmodule-file=cstdio.pcm
    -fmodule-file=coroutine.pcm
    -fmodule-file=string.pcm
    -fmodule-file=iostream.pcm
    -fmodule-file=numeric.pcm
    -fmodule-file=vector.pcm
    -fmodule-file=thread.pcm
    -fmodule-file=chrono.pcm
    -fmodule-file=map.pcm
    -fmodule-file=mutex.pcm
    -fmodule-file=atomic.pcm
    -fmodule-file=random.pcm
    -fmodule-file=fstream.pcm
    -fmodule-file=memory.pcm
    -fmodule-file=exception.pcm
    -fmodule-file=stdexcept.pcm
    -fmodule-file=utility.pcm
    -fmodule-file=algorithm.pcm
    -fmodule-file=array.pcm
    -fmodule-file=functional.pcm
    -fmodule-file=type_traits.pcm
    -fmodule-file=iterator.pcm
    -fmodule-file=list.pcm
    -fmodule-file=condition_variable.pcm
    -fmodule-file=queue.pcm
    -fmodule-file=tuple.pcm
    -fmodule-file=initializer_list.pcm
    -fmodule-file=limits.pcm
    -fmodule-file=cctype.pcm
    -fmodule-file=cfenv.pcm
    -fmodule-file=cinttypes.pcm
    -fmodule-file=clocale.pcm
    #-fmodule-file=cmath.pcm
    -fmodule-file=csetjmp.pcm
    -fmodule-file=csignal.pcm
    -fmodule-file=cstdarg.pcm
    -fmodule-file=cstddef.pcm
    -fmodule-file=cstdint.pcm
    -fmodule-file=cstdio.pcm
    -fmodule-file=cstdlib.pcm
    -fmodule-file=cstring.pcm
    -fmodule-file=ctime.pcm
    -fmodule-file=cuchar.pcm
    -fmodule-file=cwchar.pcm
    -fmodule-file=cwctype.pcm
)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(stdhu PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/stdhu.cppm
)

