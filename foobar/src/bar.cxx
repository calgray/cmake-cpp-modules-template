// Global module fragment where #includes can happen
module;
#include <iostream>

// first thing after the Global module fragment must be a module command
export module bar;

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
  std::cout << "bar\n";
}