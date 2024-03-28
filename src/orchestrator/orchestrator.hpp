#pragma once

#include <memory>
#include <thread>
#include <vector>

#include "model.hpp"

struct Orchestrator
{
    Orchestrator();

    auto run() -> void;

    std::vector<std::unique_ptr<Model>> models{};
    std::vector<std::jthread> threads{};
};
