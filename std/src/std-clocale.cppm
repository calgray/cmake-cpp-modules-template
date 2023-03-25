module;
#include <clocale>
export module clangstd:clocale;

export namespace std {
  using std::lconv;

  using std::setlocale;
  using std::localeconv;
}
