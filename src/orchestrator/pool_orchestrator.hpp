#pragma once

#include <memory>
#include <vector>

#include "orchestrator/threadpool.hpp"

struct Broker;
struct Module;
struct PoolOrchestrator
{
    auto register_model(Module *module) -> void;

    auto run(Broker &broker) -> void;

    std::vector<std::unique_ptr<Module>> modules;
    ThreadPool<3> threadpool{};
};
