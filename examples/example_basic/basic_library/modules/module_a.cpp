#include "modules/module_a.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

auto ModuleA::initialize(toadofsky::Broker &broker) -> void
{
    broker.subscribe("FOO", this);
}

auto ModuleA::update(toadofsky::Broker &broker) -> bool
{
    for (auto message : get_messages())
    {
        if (message->topic == "FOO")
        {
            model.update();
            fmt::print("Got a FOO! {}\n", toadofsky::message_cast<int>(message)->payload);
            broker.publish("BAR", model.data1, model.data2);
        }
    }
    return true;
}

auto ModuleA::run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void
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
