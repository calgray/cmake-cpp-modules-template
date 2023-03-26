add_library(ut)
target_compile_features(ut PUBLIC cxx_std_20)
target_sources(ut PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        src/ut.cxx
)
# target_link_libraries(ut PUBLIC stdcxx)
target_link_libraries(ut PUBLIC stdhu)
target_link_libraries(ut PRIVATE CONAN_PKG::boost-ext-ut)

target_compile_options(ut PRIVATE
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
    -fmodule-file=compare.pcm
    -fmodule-file=queue.pcm
    -fmodule-file=tuple.pcm
    -fmodule-file=initializer_list.pcm
    -fmodule-file=limits.pcm
    -fmodule-file=cctype.pcm
    -fmodule-file=cfenv.pcm
    -fmodule-file=cinttypes.pcm
    -fmodule-file=clocale.pcm
    # -fmodule-file=cmath.pcm
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