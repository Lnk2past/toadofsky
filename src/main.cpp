#include "broker/broker.hpp"
#include "orchestrator/orchestrator.hpp"
#include "orchestrator/pool_orchestrator.hpp"
#include "modules/module_a.hpp"
#include "modules/module_b.hpp"
#include "modules/module_c.hpp"

auto main() -> int
{
    {
        auto broker = Broker{};
        auto orchestrator = Orchestrator{};
        orchestrator.register_model(new ModuleA);
        orchestrator.register_model(new ModuleB);
        orchestrator.register_model(new ModuleC);
        orchestrator.run(broker);
    }
    {
        auto broker = Broker{};
        auto orchestrator = PoolOrchestrator{};
        orchestrator.register_model(new ModuleA);
        orchestrator.register_model(new ModuleB);
        orchestrator.register_model(new ModuleC);
        orchestrator.run(broker);
    }
}
