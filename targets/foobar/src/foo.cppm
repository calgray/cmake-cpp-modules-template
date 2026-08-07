export module cmake_cpp_modules_template.foobar.foo;

import cmake_cpp_modules_template.foobar.fibonacci;
import range_v3;
import std;

namespace cmake_cpp_modules_template::foobar
{
// See https://www.walletfox.com/course/quickref_range_v3.php
export class foo
{
public:
  foo() = default;
  ~foo() = default;

  std::string name() const { return "foo"; }

  std::string std_iota_str(int start, int end) const
  {
    std::stringstream ss;
    auto iota = std::views::iota(start, end);
    ss << "[";
    for (auto x : std::ranges::subrange(iota.begin(), --iota.end()))
    {
      ss << x << ",";
    }
    ss << iota.back();
    ss << "]";
    return ss.str();
  }

  std::string ranges_iota_str(int start, int end) const
  {
    std::stringstream ss;
    ss << ranges::views::iota(start, end);
    return ss.str();
  }

  template<ranges::forward_range T>
  std::string ranges_range_str(const T& range) const
  {
    std::stringstream ss;
    ss << (range | ranges::views::all);
    return ss.str();
  }

  template<typename T>
  std::string fibonacci_str(int count) const
  {
    std::stringstream ss;
    auto fibrange = fibonacci<T>()
    | ranges::views::take(count)
    | ranges::to<std::vector<T>>();
    ss << (fibrange | ranges::views::all);
    return ss.str();
  }
};
} // namespace cmake_cpp_modules_template::foobar