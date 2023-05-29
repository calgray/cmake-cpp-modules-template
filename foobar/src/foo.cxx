export module foo;

import range_v3;
import stdcxx;

template<std::integral T>
ranges::experimental::generator<T> fibonacci()
{
    // a:b tends to the golden ratio,
    // t.f. max_n ~= log_phi(numeric_max)
    T max_n = 1 + std::log2(std::numeric_limits<T>::max())
                    / std::log2(std::numbers::phi_v<float>);

    T a=0, b=1;
    co_yield a;
    co_yield b;
    for (auto n : ranges::iota_view(0, max_n))
    {
        T s=a+b;
        co_yield s;
        a=b;
        b=s;
    }
}

export class foo
{
public:
  foo() = default;
  ~foo() = default;
  std::string name() const { return "foo"; }
  void print();
};

void foo::print()
{
  //const std::regex pattern = std::regex("");
  // // std ranges doesn't work in as many places as ranges-v3
  // for (auto x : std::views::iota(0,10) | std::views::take(5))
  // {
  //   std::cout << x;
  // }
  // std::cout << "\n";

  // // Ranges-v3
  std::vector<int> v {1,2,3,4};
  std::cout << ranges::views::all(v) << "\n";
  
  for (auto x : ranges::views::iota(0,10) | ranges::views::take(5))
  {
    std::cout << x;
  }
  std::cout << "\n";
  std::cout << ranges::views::iota(0,10) << "\n";

  // // Ranges-v3 Generator
  for (auto i : fibonacci<long long>() | ranges::views::take(100))
  {
      std::cout << i << " ";
  }
  std::cout << "\n";
}