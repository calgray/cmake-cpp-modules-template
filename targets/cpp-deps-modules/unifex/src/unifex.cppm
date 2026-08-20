module;

#include <iostream>

#include <unifex/task.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/when_all.hpp>
#include <unifex/when_all_range.hpp>
#include <unifex/via.hpp>
#include <unifex/let_done.hpp>
#include <unifex/for_each.hpp>
#include <unifex/just_void_or_done.hpp>
#include <unifex/done_as_optional.hpp>
#include <unifex/stop_when.hpp>


#include <unifex/range_stream.hpp>
#include <unifex/adapt_stream.hpp>
#include <unifex/transform_stream.hpp>
#include <unifex/never.hpp>

#include <unifex/static_thread_pool.hpp>
#include <unifex/timed_single_thread_context.hpp>

#include <unifex/with_scheduler_affinity.hpp>
#include <unifex/with_query_value.hpp>

#if defined(__linux__)
#include "io_uring_context.hpp"
// #include <unifex/linux/io_uring_context.hpp>
#endif // __linux__

export module unifex;


export namespace unifex {

  using unifex::sender_traits;
  using unifex::sender_value_types_t;
  using unifex::sender_error_types_t;

  // concepts
  using unifex::scheduler;

  //task
  using unifex::continuation_handle;
  using unifex::any_scheduler;
  using unifex::inplace_stop_token;
  using unifex::inline_scheduler;
  using unifex::task;
  using unifex::nothrow_task;
  using unifex::just;
  using unifex::just_done;
  using unifex::just_void_or_done;
  using unifex::then;
  using unifex::defer;
  using unifex::let_value;
  using unifex::let_done;
  using unifex::as_sender;
  using unifex::on;
  using unifex::via;

  //sender
  using unifex::done_as_optional;
  using unifex::stop_when;
  using unifex::unit;

  // stream
  using unifex::range_stream; // use iota
  using unifex::transform_stream;
  using unifex::adapt_stream;
  using unifex::never_stream;

  // events
  using unifex::inplace_stop_source;

  using unifex::schedule;
  using unifex::schedule_after;
  using unifex::schedule_at;
  using unifex::when_all;
  using unifex::when_all_range;
  using unifex::sync_wait;
  using unifex::for_each;
  using unifex::sequence;

  using unifex::static_thread_pool;
  using unifex::timed_single_thread_context;

  // using unifex::get_env;
  using unifex::get_scheduler;
  using unifex::current_scheduler;
  using unifex::with_query_value;
  // using unifex::continuation_handle;
  // using unifex::any_scheduler;
  // using unifex::tag_invoke;

  using unifex::tag_t;

  namespace _await {
    using unifex::_await::_sender_task;
    using unifex::_await::sender_task;
    using unifex::_await_cpo::_fn;
  }

  namespace _task {
    using unifex::_task::_promise_base;
    using unifex::_task::_sr_thunk_promise;
  }

  namespace _await_tfx {
    using unifex::_await_tfx::_awaitable;
    using unifex::_await_tfx::_awaitable_base;
    // using unifex::_await_tfx::is_resumer_promise;
  }

  namespace _wsa
  {
    using unifex::_wsa::_wsa_sender_wrapper;
  }

#if defined(__linux)
  namespace linuxos {
    using unifex::linuxos::io_uring_context;
  }
#endif // __linux__

} // namespace unifex
