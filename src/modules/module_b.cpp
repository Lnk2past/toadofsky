#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "modules/module_b.hpp"

auto ModuleB::initialize(Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModuleB::update(Broker &) -> void
{
    for (auto message : get_messages())
    {
        if (message->topic == "BAR")
        {
            model.update();
            fmt::print("Got a BAR! {}\n", std::dynamic_pointer_cast<MessagePayload<int, double>>(message)->payload);
        }
    }
}

auto ModuleB::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto ModuleB::finalize() -> void
{
}
