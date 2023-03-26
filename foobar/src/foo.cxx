// Global module fragment where #includes can happen
module;
#include <unistd.h>

// first thing after the Global module fragment must be a module command
export module foo;

import <string>;
import <iostream>;


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