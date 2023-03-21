#include <iostream>

import foo;
import bar;

int main()
{
  std::cout << "helloworld\n";
  foo f;
  f.print();
  bar b;
  b.print();
  return 0;
}