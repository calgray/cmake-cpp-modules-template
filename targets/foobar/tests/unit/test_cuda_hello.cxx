
import boost.ut;
import fmt.core;
import cuda_hello;
import cuda;

import std.compat;

using namespace boost::ut;

suite<"cuda"> cuda_suite = [] {
    "cuda_hello"_test = [] {
        int in = 2;
        int out = cuda_hello(in);
        fmt::print("{}->{}\n", in, out);
        expect(out == 10_i);
    };

    // Only useful for C style kernel launching
    "module"_test = [] {
        int* dptr;
        expect(cuda::cudaMalloc(&dptr, 10) == 0);
        cuda::cudaFree(&dptr);
    };
};