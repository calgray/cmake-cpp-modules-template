// Global module fragment where #includes can happen
module;
#include <iostream>

// first thing after the Global module fragment must be a module command
export module foo;

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
  std::cout << "foo\n";
}