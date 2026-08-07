module;

// Tensor needs patching
#if 0 && __has_include(<unsupported/Eigen/CXX11/Tensor>)
#include <unsupported/Eigen/CXX11/Tensor>
#endif

export module eigen.tensor;

#if 0 && __has_include(<unsupported/Eigen/CXX11/Tensor>)
import std;

export namespace Eigen
{
    using Eigen::Tensor;
}
#endif
