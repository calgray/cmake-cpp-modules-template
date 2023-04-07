module;

#include <Eigen/Dense>

export module eigen.dense;

import stdcxx;

export namespace Eigen
{
    using Eigen::Matrix;
    using Eigen::Matrix2f;
    using Eigen::Matrix2d;
    using Eigen::MatrixXf;
    using Eigen::MatrixXd;

    using Eigen::Vector2f;
    using Eigen::Vector2d;
    using Eigen::Vector3f;
    using Eigen::Vector3d;
    
    using Eigen::RowVector;
}
