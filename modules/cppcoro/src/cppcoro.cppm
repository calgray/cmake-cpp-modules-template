module;
#include <new>
#include <cppcoro/task.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/generator.hpp>
#include <cppcoro/async_generator.hpp>
#include <cppcoro/async_mutex.hpp>
#include <cppcoro/single_consumer_event.hpp>

// NOTE: cppcoro uses ' in its MSVC version literals
// that clang preprocessor does not suppport. Manual
// header modification is a workaround.
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all_ready.hpp>

export module cppcoro;

import stdcxx;

export namespace cppcoro
{
    using cppcoro::task;
    using cppcoro::shared_task;
    using cppcoro::generator;
    using cppcoro::async_generator;
    using cppcoro::async_mutex;

    using cppcoro::single_consumer_event;

    using cppcoro::sync_wait;
    using cppcoro::when_all_ready;
    using cppcoro::detail::when_all_task;
};