import boost.ut;
import cmake_cpp_modules_template.foobar.foo;
import std;

using namespace boost::ut;
using namespace cmake_cpp_modules_template::foobar;

suite<"foo_ranges"> foo_ranges_suite = [] {
  const foo f;

  "simple"_test = [&] {
    expect(1 == 1_i);
  };
  "name"_test = [&] {
    expect(f.name() == "foo");
  };
  "std_iota_str"_test = [&] {
    expect(f.std_iota_str(0,5) == "[0,1,2,3,4]");
  };
  "ranges_iota_str"_test = [&] {
    expect(f.ranges_iota_str(0,5) == "[0,1,2,3,4]");
  };
  "ranges_trange_str"_test = [&] {
    expect(
      f.ranges_range_str(std::vector<float>{0,0.5,1,1.5,2})
        == "[0,0.5,1,1.5,2]"
    );
  };
  "fibonacci_str"_test = [&] {
    expect(f.fibonacci_str<long>(5) == "[0,1,1,2,3]");
  };
};
