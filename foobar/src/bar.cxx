// Global module fragment where #includes can happen
module;
#include <fmt/core.h>

// first thing after the Global module fragment must be a module command
export module bar;
import <string>;
import <iostream>;

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
  fmt::print("bar\n");
  std::cout << "bar\n";
}