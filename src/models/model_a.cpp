#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "models/model_a.hpp"

auto ModelA::initialize(Broker &broker) -> void
{
    broker.subscribe("FOO", this);
}

auto ModelA::update(Broker &broker) -> void
{
    for (auto message : get_messages())
    {
        if (message->topic == "FOO")
        {
            fmt::print("Got a FOO! {}\n", std::dynamic_pointer_cast<MessagePayload<int>>(message)->payload);
            broker.publish<int, double>("BAR", 9000, 3.14159265359);
        }
    }
}

auto ModelA::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto ModelA::finalize() -> void
{
}
