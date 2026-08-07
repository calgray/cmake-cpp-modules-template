import boost.ut;
import cmake_cpp_modules_template.foobar.fibonacci;
import std;
import range_v3;


using namespace boost::ut;
using namespace boost::ut::literals;

template<typename T>
void test_fibonacci(int expected_count, T expected_max) {
    T first, last;
    auto v = fibonacci<T>() | ranges::views::take(1) | ranges::to<std::vector<T>>();
    first = ranges::front(v);
    for(auto i : fibonacci<T>()) { last = i; }

    expect(first == detail::value<T>(0));
    expect(last == detail::value<T>(expected_max));
    expect(ranges::distance(fibonacci<T>()) == detail::value<int>(expected_count));
    expect(ranges::is_sorted(fibonacci<T>() | ranges::to<std::vector<T>>()));
};


suite<"fibonacci"> fibonacci_suite = [] {
    "int8"_test = [] {
        expect(0 == 0_i);
        test_fibonacci<std::int8_t>(12, 89);
    };
    "uint8"_test = [] {
        test_fibonacci<std::uint8_t>(14, 233);
    };
    "int16"_test = [] {
        test_fibonacci<std::int16_t>(24, 28657);
    };
    "uint16"_test = [] {
        test_fibonacci<std::uint16_t>(25, 46368);
    };
    "int32"_test = [] {
        test_fibonacci<std::int32_t>(47, 1836311903);
    };
    "uint32"_test = [] {
        test_fibonacci<std::uint32_t>(48, 2971215073);
    };
    "int64"_test = [] {
        test_fibonacci<std::int64_t>(93, 7540113804746346429l);
    };
    "uint64"_test = [] {
        test_fibonacci<std::uint64_t>(94, 12200160415121876738ul);
    };
};
