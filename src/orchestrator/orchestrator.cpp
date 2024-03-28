#include <chrono>
#include <functional>

#include "model_a.hpp"
#include "model_b.hpp"
#include "orchestrator.hpp"

using namespace std::chrono_literals;

Orchestrator::Orchestrator()
{
    models.push_back(std::make_unique<ModelA>());
    models.push_back(std::make_unique<ModelB>());
    threads.reserve(2);
}

auto Orchestrator::run() -> void
{
    auto cv = std::condition_variable{};

    threads.emplace_back(std::bind_front(&Model::run, models[0].get()), std::ref(cv));
    threads.emplace_back(std::bind_front(&Model::run, models[1].get()), std::ref(cv));
    std::this_thread::sleep_for(2s);
    cv.notify_all();
    std::this_thread::sleep_for(2s);
}
