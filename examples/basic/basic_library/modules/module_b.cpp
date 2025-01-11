#include "modules/module_b.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

auto ModuleB::initialize(toadofsky::Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModuleB::update(toadofsky::Broker &) -> bool
{
    for (auto message : get_messages())
    {
        if (message->topic == "BAR")
        {
            model.update();
            fmt::print("Got a BAR! {}\n", std::dynamic_pointer_cast<toadofsky::MessagePayload<int, double>>(message)->payload);
        }
    }
    return true;
}

auto ModuleB::run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void
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
