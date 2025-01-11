#pragma once

#include "toadofsky/orchestrator/threadpool.hpp"

#include <memory>
#include <vector>

namespace toadofsky
{
    struct Broker;
    struct Module;
    struct PoolOrchestrator
    {
        auto register_model(Module *module) -> void;

        auto run(Broker &broker) -> void;

        std::vector<Module *> modules;
        ThreadPool threadpool{3};
    };
}
