#include "broker/broker.hpp"
#include "orchestrator/orchestrator.hpp"

auto main() -> int
{
    auto orchestrator = Orchestrator{};
    auto broker = Broker{};
    orchestrator.run(broker);
}
