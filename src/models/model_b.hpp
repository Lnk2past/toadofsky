#pragma once

#include "models/model.hpp"
#include "broker/subscriber.hpp"

struct ModelB : Model, Subscriber
{
    ModelB() = default;
    ~ModelB() = default;
    auto initialize(Broker &broker) -> void override;
    auto update(Broker &broker) -> void override;
    auto run(std::stop_token stop_token, std::latch &latch, Broker &broker) -> void override;
    auto finalize() -> void override;
};
