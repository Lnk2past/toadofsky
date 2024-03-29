#include <chrono>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker.hpp"
#include "message.hpp"
#include "model_c.hpp"

using namespace std::chrono_literals;

auto ModelC::initialize(Broker &broker) -> void
{
    broker.subscribe("BAR", this);
}

auto ModelC::update(Broker &broker) -> void
{
    broker.publish<int>("FOO", 1337);
    std::this_thread::sleep_for(2s);
}

auto ModelC::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto ModelC::finalize() -> void
{
}
