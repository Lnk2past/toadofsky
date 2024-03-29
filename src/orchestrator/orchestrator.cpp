#include <chrono>
#include <functional>
#include <latch>

#include <fmt/format.h>

#include "broker.hpp"
#include "model_a.hpp"
#include "model_b.hpp"
#include "model_c.hpp"
#include "orchestrator.hpp"

using namespace std::chrono_literals;

Orchestrator::Orchestrator()
{
    models.reserve(3);
    models.push_back(std::make_unique<ModelA>());
    models.push_back(std::make_unique<ModelB>());
    models.push_back(std::make_unique<ModelC>());
}

auto Orchestrator::run(Broker &broker) -> void
{
    for (auto &model : models)
    {
        model->initialize(broker);
    }
    threads.reserve(models.size());

    auto latch = std::latch{3};

    for (auto &model : models)
    {
        threads.emplace_back(std::bind_front(&Model::run, model.get()), std::ref(latch), std::ref(broker));
    }
    std::this_thread::sleep_for(5s);
}
