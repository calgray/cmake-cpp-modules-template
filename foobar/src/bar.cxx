module;
#include <iostream>
#include <memory>


export module bar;
// import fmt.core;
// export import <iostream>;
// export import <memory>;

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
  fmt::print("bar {}\n", *a);
  std::cout << "bar\n";
}