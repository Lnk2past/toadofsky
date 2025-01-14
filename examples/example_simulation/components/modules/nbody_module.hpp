#pragma once

#include "models/nbody.hpp"

#include "toadofsky/broker/subscriber.hpp"
#include "toadofsky/module/module.hpp"

struct NBodyModule : toadofsky::Module, toadofsky::Subscriber
{
    NBodyModule() = default;
    NBodyModule(const double dt_) : dt{dt_} {}
    ~NBodyModule() = default;
    auto initialize(toadofsky::Broker &broker) -> void override;
    auto update(toadofsky::Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override;
    auto finalize() -> void override;

    NBody model{};
    double time{};
    double dt{0.1};
};
