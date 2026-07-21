set(CMake_TEST_CXXModules_UUID "a246741c-d067-4019-a8fb-3d16b0c9d1d3")

set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "clang-scan-deps" CACHE STRING "")
    set(CMAKE_CXX_COMPILER_CLANG "clang++" CACHE STRING "")
    string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
        "${CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS}"
        " -format=p1689"
        " --"
        " ${CMAKE_CXX_COMPILER_CLANG} <DEFINES> <INCLUDES> <FLAGS> -stdlib=libstdc++"
        " -x c++ <SOURCE> -c -o <OBJECT> -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
        " > <DYNDEP_FILE>"
    )

    set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG
        "-fmodules-ts -fmodule-mapper=<MODULE_MAP_FILE> -Mno-modules"
    )
endif()
