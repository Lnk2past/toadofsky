#include "broker/broker.hpp"
#include "models/model_a.hpp"
#include "models/model_b.hpp"
#include "orchestrator/orchestrator.hpp"

auto main() -> int
{
    auto orchestrator = Orchestrator{};
    orchestrator.run();
}
