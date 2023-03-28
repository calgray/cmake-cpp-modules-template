module;
#include <cppcoro/task.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/generator.hpp>
#include <cppcoro/async_generator.hpp>
#include <cppcoro/async_mutex.hpp>

export module cppcoro;

export namespace cppcoro
{
    using cppcoro::task;
    using cppcoro::shared_task;
    using cppcoro::generator;
    using cppcoro::async_generator;
    using cppcoro::async_mutex;
};
