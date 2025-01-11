#include "toadofsky/broker/broker.hpp"
#include "toadofsky/module/module.hpp"
#include "toadofsky/orchestrator/orchestrator.hpp"

#include <fmt/format.h>

#include <functional>
#include <latch>

using namespace std::chrono_literals;

namespace toadofsky
{
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
}