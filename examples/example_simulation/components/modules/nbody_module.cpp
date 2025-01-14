#include "modules/nbody_module.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/broker/message.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

auto NBodyModule::initialize(toadofsky::Broker &broker) -> void
{
    // model.bodies.emplace_back(std::array<double, 2>{10.0, 0.0});
    // model.bodies.emplace_back(std::array<double, 2>{-10.0, 0.0});
    // model.bodies.emplace_back(std::array<double, 2>{0.0, 10.0 * std::sqrt(3.0)});
    broker.subscribe("NEW_ENTITY", this);
}

auto NBodyModule::update(toadofsky::Broker &) -> bool
{
    for (auto message : get_messages())
    {
        if (message->topic == "NEW_ENTITY")
        {
            model.bodies.push_back(std::get<0>(std::dynamic_pointer_cast<toadofsky::MessagePayload<Body>>(message)->payload));
            fmt::println("New entity! Now there are {} of them; newest ID={}", model.bodies.size(), model.bodies.back().id);
        }
    }
    model.update(dt);
    time += dt;
    return time < 10.0;
}

auto NBodyModule::run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void
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
