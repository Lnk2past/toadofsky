#include "modules/module_a.hpp"
#include "modules/module_b.hpp"
#include "modules/module_c.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/orchestrator/pool_orchestrator.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

auto main() -> int
{
    auto module_a = ModuleA{};
    auto module_b = ModuleB{};
    auto module_c = ModuleC{};

    auto broker = toadofsky::Broker{};
    auto orchestrator = toadofsky::PoolOrchestrator{};
    orchestrator.register_model(&module_a);
    orchestrator.register_model(&module_b);
    orchestrator.register_model(&module_c);
    orchestrator.run(broker);

    auto now = std::chrono::high_resolution_clock::now();
    orchestrator.threadpool.schedule({now + 1000ms, std::bind_front(&toadofsky::Module::update, &module_c, std::ref(broker))});
    orchestrator.threadpool.schedule({now + 1500ms, std::bind_front(&toadofsky::Module::update, &module_a, std::ref(broker))});
    orchestrator.threadpool.schedule({now + 2000ms, std::bind_front(&toadofsky::Module::update, &module_b, std::ref(broker))});
    orchestrator.threadpool.schedule({now + 2500ms, std::bind_front(&toadofsky::Module::update, &module_c, std::ref(broker))});
    orchestrator.threadpool.schedule({now + 3000ms, std::bind_front(&toadofsky::Module::update, &module_a, std::ref(broker))});
    orchestrator.threadpool.schedule({now + 3500ms, std::bind_front(&toadofsky::Module::update, &module_b, std::ref(broker))});
    orchestrator.threadpool.schedule({std::chrono::high_resolution_clock::now() + 5500ms, []
                                      { fmt::println("Final Task!"); }});

    std::this_thread::sleep_for(6s);
}
