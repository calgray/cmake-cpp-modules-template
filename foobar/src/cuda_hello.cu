#include "cuda_hello.h"

#include <cuda.h>
#include <cstdio>

__global__ void g_cuda_hello(int* v)
{
    std::printf("Hello from Cuda! %i\n", *v);
    *v = 10;
}

__host__ int cuda_hello(int v)
{
    int h_v = v;
    int* d_v = nullptr;
    cudaMalloc((void**)&d_v, sizeof(int));
    cudaMemcpy(d_v, &h_v, sizeof(int), cudaMemcpyKind::cudaMemcpyHostToDevice);

    g_cuda_hello<<<1,1>>>(d_v);

    cudaMemcpy(&h_v, d_v, sizeof(int), cudaMemcpyKind::cudaMemcpyDeviceToHost);
    cudaFree(d_v);

    return h_v;
}