#include "toadofsky/broker/broker.hpp"
#include "toadofsky/module/module.hpp"
#include "toadofsky/orchestrator/pool_orchestrator.hpp"

#include <fmt/format.h>

#include <chrono>
#include <functional>
#include <thread>

using namespace std::chrono_literals;

namespace toadofsky
{
    auto PoolOrchestrator::register_model(Module *module) -> void
    {
        modules.emplace_back(module);
    }

    auto PoolOrchestrator::run(Broker &broker) -> void
    {
        for (auto &module : modules)
        {
            module->initialize(broker);
        }
    }
}
