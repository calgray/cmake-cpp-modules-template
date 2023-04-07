module;
#include <cinttypes>
export module stdcxx:cinttypes;

export namespace std {
  using std::imaxdiv_t;

  using std::imaxabs;
  using std::imaxdiv;
  using std::strtoimax;
  using std::strtoumax;
  using std::wcstoimax;
  using std::wcstoumax;
}
