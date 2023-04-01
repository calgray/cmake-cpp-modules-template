module;
#include <cuchar>
export module stdcxx:cuchar;

export namespace std {
  using std::mbstate_t;
  using std::mbrtoc16;
  using std::c16rtomb;
  using std::mbrtoc32;
  using std::c32rtomb;
}
