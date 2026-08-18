#include <unifex/task.hpp>

import boost.ut;
import std;
import unifex;
import range_v3;
import nanobench;

namespace nanobench = ankerl::nanobench;
namespace ut = boost::ut;
namespace ex = unifex;

using namespace boost::ut::literals;
using namespace std::chrono_literals;

namespace unifex
{
    using unifex::static_thread_pool;
    using unifex::timed_single_thread_context;

#if defined(__linux)
    namespace linuxos {
        using unifex::linuxos::io_uring_context;

        class io_uring_thread_context
        {
            unifex::linuxos::io_uring_context _io_ctx;
            unifex::inplace_stop_source _io_stopSource;
            std::thread _io_thread;

        public:
            io_uring_thread_context()
                : _io_thread([this] {
                    _io_ctx.run(_io_stopSource.get_token());
                })
            {
            }

            ~io_uring_thread_context()
            {
                _io_stopSource.request_stop();
                if (_io_thread.joinable())
                {
                    _io_thread.join();
                }
            }

            inline auto get_scheduler() noexcept
            {
                return _io_ctx.get_scheduler();
            }
        };
    }
#endif // __linux__
}

ut::suite<"unifex"> unifex_suite = [] {
    "parallel_sleep"_test = [&] {
        nanobench::Bench b;
        b.title("Parallel Sleep")
            .unit("op")
            .warmup(0)
            .relative(true);
        b.performanceCounters(true);

        {
            ex::timed_single_thread_context timerCtx;
            auto timerSched = timerCtx.get_scheduler();
            b.run("timer-100", [&]() {
                auto all = ex::when_all_range(
                    ranges::views::iota(0, 100)
                    | ranges::views::transform([&](int id) -> ex::task<void> {
                        co_await ex::schedule_after(timerSched, 1ms);
                    })
                    | ranges::to<std::vector<ex::task<void>>>()
                );
                ex::sync_wait(std::move(all));
            });
        }

#if defined(__linux__)
        {
            ex::linuxos::io_uring_thread_context io_ctx;
            auto ioSched = io_ctx.get_scheduler();
            ex::inplace_stop_source stopSource;
            b.run("uring-100", [&]() {
                auto all = ex::when_all_range(
                    ranges::views::iota(0, 100)
                    | ranges::views::transform([&](int id) -> ex::task<void> {
                        co_await ex::schedule_at(ioSched, ioSched.now() + 1ms);
                    })
                    | ranges::to<std::vector<ex::task<void>>>()
                );
                ex::sync_wait(std::move(all));
            });
        }
#endif // __linux__
    };
};