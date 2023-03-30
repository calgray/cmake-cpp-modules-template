module;
#include <new>
#include <cppcoro/task.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/generator.hpp>
#include <cppcoro/async_generator.hpp>
#include <cppcoro/async_mutex.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all_ready.hpp>
#include <cppcoro/single_consumer_event.hpp>

export module cppcoro;

import stdcxx;

export namespace cppcoro
{
    using cppcoro::task;
    using cppcoro::shared_task;
    using cppcoro::generator;
    using cppcoro::async_generator;
    using cppcoro::async_mutex;

    using cppcoro::sync_wait;
    using cppcoro::when_all_ready;

    using cppcoro::single_consumer_event;
};
