export module bar;

#ifndef STD_HEADER_UNITS
//import fmt.core;
import stdcxx;
#else
import <iostream>;
import <memory>;
#endif

export class bar
{
public:
  bar() = default;
  ~bar() = default;
  std::string name() const { return "bar"; }
  void print();
};

void bar::print()
{
  auto a = std::make_shared<int>(1);
  std::weak_ptr<int> b = a;
  // fmt::print("bar {}\n", *a);
  std::cout << "bar\n";
}