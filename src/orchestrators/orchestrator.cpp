#include <functional>
#include <latch>

#include <fmt/format.h>

#include "broker/broker.hpp"
#include "modules/module.hpp"
#include "orchestrators/orchestrator.hpp"

using namespace std::chrono_literals;

auto Orchestrator::register_model(Module *module) -> void
{
    modules.emplace_back(module);
}

auto Orchestrator::run(Broker &broker) -> void
{
    for (auto &module : modules)
    {
        module->initialize(broker);
    }

    threads.reserve(modules.size());

    auto latch = std::latch{static_cast<std::ptrdiff_t>(modules.size())};
    for (auto &module : modules)
    {
        threads.emplace_back(std::bind_front(&Module::run, module), std::ref(latch), std::ref(broker));
    }
    latch.wait();
}
