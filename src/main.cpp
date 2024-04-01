#include "broker/broker.hpp"
#include "orchestrator/orchestrator.hpp"
#include "models/model_a.hpp"
#include "models/model_b.hpp"
#include "models/model_c.hpp"

auto main() -> int
{
    auto broker = Broker{};
    auto orchestrator = Orchestrator{};
    orchestrator.register_model(new ModelA);
    orchestrator.register_model(new ModelB);
    orchestrator.register_model(new ModelC);
    orchestrator.run(broker);
}
