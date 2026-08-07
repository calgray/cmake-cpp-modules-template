#include "cuda_hello.h"

#include <cuda.h>

#include <iostream>
#include <cstdio>

__global__ void g_cuda_hello(int* data)
{
    std::printf("Hello from Cuda! %i\n", *data);
    *data = 10;
}

__host__ int cuda_hello(int data)
{
    int h_data = data;
    int* d_data = nullptr;
    cudaMalloc((void**)&d_data, sizeof(int));
    cudaMemcpy(d_data, &h_data, sizeof(int), cudaMemcpyKind::cudaMemcpyHostToDevice);

    g_cuda_hello<<<1,1>>>(d_data);

    cudaMemcpy(&h_data, d_data, sizeof(int), cudaMemcpyKind::cudaMemcpyDeviceToHost);
    cudaFree(d_data);

    return h_data;
}