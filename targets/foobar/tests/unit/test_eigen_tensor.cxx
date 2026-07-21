
// Tensor as module not yet supported
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>

import boost.ut;
// import std;
// import eigen.dense;
// import eigen.tensor;


using namespace boost::ut;

suite<"eigen_tensor"> eigen_tensor_suite = [] {
    "tensor"_test = [] {
        auto t = Eigen::Tensor<float, 3>(1, 1, 1);
        t.setConstant(1.f);
        expect(t(0, 0, 0) == 1.f);
    };
};