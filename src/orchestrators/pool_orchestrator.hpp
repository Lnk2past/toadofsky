#pragma once

#include <memory>
#include <vector>

#include "orchestrators/threadpool.hpp"

struct Broker;
struct Module;
struct PoolOrchestrator
{
    auto register_model(Module *module) -> void;

    auto run(Broker &broker) -> void;

    std::vector<Module *> modules;
    ThreadPool<3> threadpool{};
};
