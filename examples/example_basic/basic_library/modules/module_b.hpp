#pragma once

#include "models/model_b.hpp"

#include "toadofsky/broker/subscriber.hpp"
#include "toadofsky/module/module.hpp"

struct ModuleB : toadofsky::Module, toadofsky::Subscriber
{
    ModuleB() = default;
    ~ModuleB() = default;
    auto initialize(toadofsky::Broker &broker) -> void override;
    auto update(toadofsky::Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override;
    auto finalize() -> void override;

    ModelB model{};
};
