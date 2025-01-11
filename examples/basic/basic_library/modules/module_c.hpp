#pragma once

#include "models/model_c.hpp"

#include "toadofsky/broker/subscriber.hpp"
#include "toadofsky/module/module.hpp"

struct ModuleC : toadofsky::Module, toadofsky::Subscriber
{
    ModuleC() = default;
    ~ModuleC() = default;
    auto initialize(toadofsky::Broker &broker) -> void override;
    auto update(toadofsky::Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelC model{};
};
