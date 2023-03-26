module;
#include <csignal>
export module stdcxx:csignal;

export namespace std {
  using std::sig_atomic_t;
  using std::signal;
  using std::raise;
}
