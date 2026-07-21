export module cmake_cpp_modules_template.foobar.fibonacci;

import range_v3;
import std;


export template<typename T>
ranges::experimental::generator<T> fibonacci()
{
    // Largest index of a fibonacci number not greater than F is:
    // n(F) := floor(log(sqrt(5)(F + 0.5)) / log(phi))
    // = floor((log(F+0.5) + log(sqrt(5)) / log(phi))
    /*constexpr*/ int n_max =
        (std::log2(std::numeric_limits<T>::max()) + std::log2(std::sqrt(5.0)))
        / std::log2(std::numbers::phi_v<double>) - 1;

    T a=0, b=1;
    co_yield a;
    co_yield b;
    for (auto n : ranges::views::iota(0, n_max))
    {
        T s = a + b;
        co_yield s;
        a = b;
        b = s;
    }
}

