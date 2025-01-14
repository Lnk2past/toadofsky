#pragma once

#include "toadofsky/broker/subscriber.hpp"
#include "toadofsky/module/module.hpp"

#include <chrono>
#include <random>

using namespace std::chrono_literals;

struct SpawnModule : toadofsky::Module,
                     toadofsky::Subscriber
{
    SpawnModule() = default;
    ~SpawnModule() = default;
    auto initialize(toadofsky::Broker &broker) -> void override;
    auto update(toadofsky::Broker &broker) -> bool override;
    auto run(std::stop_token stop_token, std::latch &latch, toadofsky::Broker &broker) -> void override;
    auto finalize() -> void override;

    std::chrono::seconds spawn_timer{1s};
    std::chrono::time_point<std::chrono::high_resolution_clock> time = std::chrono::high_resolution_clock::now();

    std::mt19937 eng{1337};
    std::uniform_real_distribution<double> dis{-5.0, 5.0};
};
