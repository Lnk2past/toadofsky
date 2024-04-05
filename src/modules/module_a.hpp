#pragma once

#include "broker/subscriber.hpp"
#include "models/model_a.hpp"
#include "modules/module.hpp"

struct ModuleA : Module, Subscriber
{
    ModuleA() = default;
    ~ModuleA() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> void override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelA model;
};
