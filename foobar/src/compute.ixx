module;
#include <cuda_runtime.h>
__host__ int cuda_hello(int v);

export module cuda_hello;

export using ::cuda_hello;