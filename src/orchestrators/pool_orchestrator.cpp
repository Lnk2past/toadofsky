#include <chrono>
#include <functional>
#include <thread>

#include <fmt/format.h>

#include "broker/broker.hpp"
#include "modules/module.hpp"
#include "orchestrators/pool_orchestrator.hpp"

using namespace std::chrono_literals;

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
