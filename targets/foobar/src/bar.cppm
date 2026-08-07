module;

#include <typeinfo>

export module cmake_cpp_modules_template.foobar.bar;

import std;

export class bar
{
private:
  std::shared_ptr<int> value = std::make_shared<int>(1);
public:
  bar() = default;
  ~bar() = default;

  std::string name() const { return "bar"; }

  int get() const
  {
    return *value;
  }

  std::shared_ptr<int> get_ptr()
  {
    return value;
  }
};
