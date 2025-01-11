#include "modules/module_a.hpp"
#include "modules/module_b.hpp"
#include "modules/module_c.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/orchestrator/orchestrator.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

auto main() -> int
{
    auto module_a = ModuleA{};
    auto module_b = ModuleB{};
    auto module_c = ModuleC{};

    auto broker = toadofsky::Broker{};
    auto orchestrator = toadofsky::Orchestrator{};
    orchestrator.register_model(&module_a);
    orchestrator.register_model(&module_b);
    orchestrator.register_model(&module_c);
    orchestrator.run(broker);
    std::this_thread::sleep_for(6s);
}
