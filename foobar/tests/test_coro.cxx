import boost.ut;
import stdcxx;
import cppcoro;

using namespace boost::ut;
using namespace std::literals::chrono_literals;

template <typename DurationT>
cppcoro::task<> asleep(const DurationT& d) {
    std::this_thread::sleep_for(d);
}

suite coro_suite = [] {
    "task"_test = [] {

        bool before, after = false;
        cppcoro::single_consumer_event event;

        auto t1 = [&]() -> cppcoro::task<int> {
            std::this_thread::sleep_for(
                std::chrono::nanoseconds(100)
            );
            before = true;
            event.set();
            co_return 5;
        };
        auto t2 = [&]() -> cppcoro::task<int> {
            std::this_thread::sleep_for(
                std::chrono::nanoseconds(100)
            );
            co_await event;
            after = true;
            co_return 5;
        };

        int res = cppcoro::sync_wait([&]() -> cppcoro::task<int>
        {
            auto [res1, res2] = co_await cppcoro::when_all_ready(
                t2(),
                t1()
            );
            expect(res1.result() == 5);
            expect(res2.result() == 5);
            co_return res1.result() + res2.result();
        }());
        expect(res == 10);
        expect(before);
        expect(after);
    };
};
