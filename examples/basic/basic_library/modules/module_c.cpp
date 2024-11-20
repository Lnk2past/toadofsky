#include <chrono>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "modules/module_c.hpp"

using namespace std::chrono_literals;

auto ModuleC::initialize(Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModuleC::update(Broker &broker) -> void
{
    model.update();
    broker.publish<int>("FOO", model.data);
}

auto ModuleC::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
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
