#include <chrono>
#include <functional>
#include <thread>

#include <fmt/format.h>

#include "broker/broker.hpp"
#include "modules/module.hpp"
#include "orchestrator/pool_orchestrator.hpp"

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

    threadpool.schedule({std::chrono::high_resolution_clock::now() + 1s, std::bind_front(&Module::update, models[2].get(), std::ref(broker))});
    threadpool.schedule({std::chrono::high_resolution_clock::now() + 3s, std::bind_front(&Module::update, models[0].get(), std::ref(broker))});
    threadpool.schedule({std::chrono::high_resolution_clock::now() + 5s, std::bind_front(&Module::update, models[1].get(), std::ref(broker))});

    threadpool.schedule({std::chrono::high_resolution_clock::now() + 5500ms, []
                         { fmt::println("Final Task!"); }});

    std::this_thread::sleep_for(6s);
}
