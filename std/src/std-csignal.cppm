module;
#include <csignal>
export module clangstd:csignal;

export namespace std {
  using std::sig_atomic_t;
  using std::signal;
  using std::raise;
}
