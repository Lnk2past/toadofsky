#include "toadofsky/module/module.hpp"
#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"
#include "toadofsky/broker/subscriber.hpp"

#include <chrono>
#include <format>
#include <iostream>
#include <latch>
#include <memory>
#include <stop_token>

struct TestLib : toadofsky::Module, toadofsky::Subscriber
{
    auto initialize(toadofsky::Broker &broker) -> void override
    {
    }

    auto update(toadofsky::Broker &broker) -> bool override
    {
        broker.publish<int>("FOO", 1);
        return true;
    }

    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override
    {
        latch.arrive_and_wait();
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
