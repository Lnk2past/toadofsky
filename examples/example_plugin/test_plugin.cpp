#include "toadofsky/toadofsky.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

#include <memory>

struct TestLib : toadofsky::Module, toadofsky::Subscriber
{
    auto initialize(toadofsky::Broker &broker) -> void override
    {
        broker.subscribe("FOO", this);
    }

    auto update(toadofsky::Broker &) -> bool override
    {
        for (auto message : get_messages())
        {
            if (message->topic == "FOO")
            {
                fmt::println(
                    "Got a FOO! {}",
                    fmt::join(toadofsky::message_cast<int>(message)->payload, ", "));
            }
        }
        return true;
    }

    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override
    {
        latch.arrive_and_wait();
        fmt::println("Test plugin is going!...");
        while (!stop_token.stop_requested())
        {
            update(broker);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    auto finalize() -> void override
    {
    }
};

extern "C"
{
    auto make_test_lib() -> std::unique_ptr<toadofsky::Module>
    {
        return std::make_unique<TestLib>();
    }
}
