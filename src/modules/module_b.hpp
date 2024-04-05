#pragma once

#include "broker/subscriber.hpp"
#include "models/model_b.hpp"
#include "modules/module.hpp"

struct ModuleB : Module, Subscriber
{
    ModuleB() = default;
    ~ModuleB() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> void override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelB model{};
};
