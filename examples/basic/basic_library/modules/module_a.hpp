#pragma once

#include "models/model_a.hpp"

#include "toadofsky/broker/subscriber.hpp"
#include "toadofsky/module/module.hpp"

struct ModuleA : toadofsky::Module, toadofsky::Subscriber
{
    ModuleA() = default;
    ~ModuleA() = default;
    auto initialize(toadofsky::Broker &broker) -> void override;
    auto update(toadofsky::Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelA model;
};
