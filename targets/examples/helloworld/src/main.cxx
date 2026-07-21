import cmake_cpp_modules_template.foobar.foo;
import cmake_cpp_modules_template.foobar.bar;
import fmt.core;
import std;
import range_v3;

#if ENABLE_EIGEN
import eigen.dense;
#endif // ENABLE_EIGEN

int main(int argc, char** argv)
{
    auto s = std::make_unique<int>(2);
    std::printf("Hello World!\n");

#if ENABLE_EIGEN
    auto m = Eigen::Vector2f(1.2, 2.3);
    std::print("{} {}!\n", m.x(), m.y());
#endif // ENABLE_EIGEN

    cmake_cpp_modules_template::foobar::foo f;
    std::print("foo: {}\n", f.fibonacci_str<long>(10));
    bar b;
    fmt::print("bar: {}\n", b.get());
    return 0;
}
