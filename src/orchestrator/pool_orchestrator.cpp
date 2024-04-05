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

    auto now = std::chrono::high_resolution_clock::now();

    threadpool.schedule({now + 1000ms, std::bind_front(&Module::update, modules[2].get(), std::ref(broker))});
    threadpool.schedule({now + 1500ms, std::bind_front(&Module::update, modules[0].get(), std::ref(broker))});
    threadpool.schedule({now + 2000ms, std::bind_front(&Module::update, modules[1].get(), std::ref(broker))});
    threadpool.schedule({now + 2500ms, std::bind_front(&Module::update, modules[2].get(), std::ref(broker))});
    threadpool.schedule({now + 3000ms, std::bind_front(&Module::update, modules[0].get(), std::ref(broker))});
    threadpool.schedule({now + 3500ms, std::bind_front(&Module::update, modules[1].get(), std::ref(broker))});

    threadpool.schedule({std::chrono::high_resolution_clock::now() + 5500ms, []
                         { fmt::println("Final Task!"); }});

    std::this_thread::sleep_for(6s);
}
