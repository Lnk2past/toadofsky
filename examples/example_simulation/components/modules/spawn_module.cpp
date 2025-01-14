#include <chrono>

#include "models/body.hpp"
#include "modules/spawn_module.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"

using namespace std::chrono_literals;

auto SpawnModule::initialize(toadofsky::Broker &) -> void
{
}

auto SpawnModule::update(toadofsky::Broker &broker) -> bool
{
    if (std::chrono::high_resolution_clock::now() >= time + spawn_timer)
    {
        broker.publish("NEW_ENTITY", Body{dis(eng), dis(eng)});
        time = std::chrono::high_resolution_clock::now();
    }
    return true;
}

auto SpawnModule::run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
        std::this_thread::sleep_for(2s);
    }
}

auto SpawnModule::finalize() -> void
{
}
