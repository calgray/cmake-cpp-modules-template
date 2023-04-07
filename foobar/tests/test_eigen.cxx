
import boost.ut;
import stdcxx;
import eigen.dense;


using namespace boost::ut;

suite eigen_suite = [] {
    "vector"_test = [] {
        auto m = Eigen::Vector2f(1.0, 2.0);
        expect(m.x() == 1.0);
        expect(m.y() == 2.0);
    };

    "matrix"_test = [] {
        auto m = Eigen::Vector2f(1.0, 2.0);
        expect(m.x() == 1.0);
        expect(m.y() == 2.0);
    };
};