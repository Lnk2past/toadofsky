#pragma once

#include <memory>
#include <thread>
#include <vector>

struct Broker;
struct Model;
struct Orchestrator
{
    auto register_model(Model *model) -> void;

    auto run(Broker &broker) -> void;

    std::vector<std::unique_ptr<Model>> models;
    std::vector<std::jthread> threads;
};
