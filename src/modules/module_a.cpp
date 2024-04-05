#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "modules/module_a.hpp"

auto ModuleA::initialize(Broker &broker) -> void
{
    broker.subscribe("FOO", this);
}

auto ModuleA::update(Broker &broker) -> void
{
    for (auto message : get_messages())
    {
        if (message->topic == "FOO")
        {
            model.update();
            fmt::print("Got a FOO! {}\n", std::dynamic_pointer_cast<MessagePayload<int>>(message)->payload);
            broker.publish<int, double>("BAR", model.data1, model.data2);
        }
    }
}

auto ModuleA::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto ModuleA::finalize() -> void
{
}
