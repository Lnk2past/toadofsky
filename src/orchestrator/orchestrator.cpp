#include <chrono>
#include <functional>
#include <latch>

#include <fmt/format.h>

#include "broker/broker.hpp"
#include "models/model.hpp"
#include "orchestrator/orchestrator.hpp"

using namespace std::chrono_literals;

auto Orchestrator::register_model(Model *model) -> void
{
    models.emplace_back(model);
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
