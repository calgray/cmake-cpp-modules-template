
import boost.ut;
import fmt.core;
import cuda_hello;

using namespace boost::ut;

suite cuda_suite = [] {
    "cuda_hello"_test = [] {
        int in = 2;
        int out = cuda_hello(in);
        fmt::print("{}->{}\n", in, out);
        expect(out == 10_i);
    };
};