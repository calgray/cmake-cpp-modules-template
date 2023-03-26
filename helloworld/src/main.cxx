
// TODO: For some reason explicit includes are still needed
// in this compilation unit with the header module units to
// avoid segmentation faults.

// Maybe use an intermediate main module?

#include <string>
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
