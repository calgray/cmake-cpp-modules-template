// Global module fragment where #includes can happen
module;
#include <unistd.h>
#include <string>
#include <iostream>
#include <fmt/core.h>

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
  //fmt::print("bar");
  std::cout << "bar\n";
}