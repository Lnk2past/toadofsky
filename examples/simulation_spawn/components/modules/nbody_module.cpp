#include <fmt/format.h>
#include <fmt/ranges.h>

#include "broker/broker.hpp"
#include "broker/message.hpp"
#include "modules/nbody_module.hpp"

auto NBodyModule::initialize(Broker &broker) -> void
{
    // model.bodies.emplace_back(std::array<double, 2>{10.0, 0.0});
    // model.bodies.emplace_back(std::array<double, 2>{-10.0, 0.0});
    // model.bodies.emplace_back(std::array<double, 2>{0.0, 10.0 * std::sqrt(3.0)});
    broker.subscribe("NEW_ENTITY", this);
}

auto NBodyModule::update(Broker &) -> bool
{
    for (auto message : get_messages())
    {
        if (message->topic == "NEW_ENTITY")
        {
            model.bodies.push_back(std::get<0>(std::dynamic_pointer_cast<MessagePayload<Body>>(message)->payload));
            fmt::println("New entity! Now there are {} of them; newest ID={}", model.bodies.size(), model.bodies.back().id);
        }
    }
    model.update(dt);
    time += dt;
    return time < 10.0;
}

auto NBodyModule::run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void
{
    latch.arrive_and_wait();
    while (!stop_token.stop_requested())
    {
        update(broker);
    }
}

auto NBodyModule::finalize() -> void
{
}
