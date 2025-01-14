#include "modules/module_c.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"

#include <chrono>

using namespace std::chrono_literals;

auto ModuleC::initialize(toadofsky::Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModuleC::update(toadofsky::Broker &broker) -> bool
{
    model.update();
    broker.publish("FOO", model.data);
    return true;
}

auto ModuleC::run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
        std::this_thread::sleep_for(2s);
    }
}

auto ModuleC::finalize() -> void
{
}
