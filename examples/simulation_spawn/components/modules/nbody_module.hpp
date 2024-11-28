#pragma once

#include "broker/subscriber.hpp"
#include "models/nbody.hpp"
#include "modules/module.hpp"

struct NBodyModule : Module, Subscriber
{
    NBodyModule() = default;
    NBodyModule(const double dt_) : dt{dt_} {}
    ~NBodyModule() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;

    NBody model{};
    double time{};
    double dt{0.1};
};
