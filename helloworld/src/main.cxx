#include <iostream>

import foo;
import bar;

int main(int argc, char** argv)
{
  std::cout << "helloworld\n";
  foo f;
  f.print();
  bar b;
  b.print();
  return 0;
}