#pragma once

#include "broker/subscriber.hpp"
#include "models/model_c.hpp"
#include "modules/module.hpp"

struct ModuleC : Module, Subscriber
{
    ModuleC() = default;
    ~ModuleC() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> void override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelC model{};
};
