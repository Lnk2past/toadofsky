#pragma once

#include <memory>
#include <vector>

#include "orchestrator/threadpool.hpp"

struct Broker;
struct Model;
struct PoolOrchestrator
{
    auto register_model(Model *model) -> void;

    auto run(Broker &broker) -> void;

    std::vector<std::unique_ptr<Model>> models;
    ThreadPool<3> threadpool{};
};
