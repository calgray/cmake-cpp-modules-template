module;

#if __has_include(<eigen3/unsupported/CXX11/Tensor>)
#include <eigen3/unsupported/CXX11/Tensor>
#endif

export module eigen.tensor;

#if __has_include(<eigen3/unsupported/CXX11/Tensor>)
import stdcxx;

export namespace Eigen
{
    using Eigen::Tensor;
}
#endif
