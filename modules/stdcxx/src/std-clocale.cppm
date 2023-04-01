module;
#include <clocale>
export module stdcxx:clocale;

export namespace std {
  using std::lconv;

  using std::setlocale;
  using std::localeconv;
}
