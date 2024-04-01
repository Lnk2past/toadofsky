#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "models/model_b.hpp"

auto ModelB::initialize(Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModelB::update(Broker &) -> void
{
    for (auto message : get_messages())
    {
        if (message->topic == "BAR")
        {
            fmt::print("Got a BAR! {}\n", std::dynamic_pointer_cast<MessagePayload<int, double>>(message)->payload);
        }
    }
}

auto ModelB::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto ModelB::finalize() -> void
{
}
