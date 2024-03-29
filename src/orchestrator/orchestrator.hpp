#pragma once

#include <memory>
#include <thread>
#include <vector>

#include "model.hpp"

struct Broker;
struct Orchestrator
{
    Orchestrator();

    auto run(Broker &broker) -> void;

    std::vector<std::unique_ptr<Model>> models{};
    std::vector<std::jthread> threads{};
};
