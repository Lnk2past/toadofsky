#pragma once

#include "model.hpp"
#include "subscriber.hpp"

struct ModelA : Model, Subscriber
{
    ModelA() = default;
    ~ModelA() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> void override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;
};
