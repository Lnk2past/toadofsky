#include "components/modules/nbody_module.hpp"
#include "components/modules/spawn_module.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/orchestrator/orchestrator.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

auto main() -> int
{
    auto nbody_module = NBodyModule{};
    auto spawn_module = SpawnModule{};

    auto broker = toadofsky::Broker{};
    auto orchestrator = toadofsky::Orchestrator{};
    orchestrator.register_model(&nbody_module);
    orchestrator.register_model(&spawn_module);
    orchestrator.run(broker);
    std::this_thread::sleep_for(6s);
}
