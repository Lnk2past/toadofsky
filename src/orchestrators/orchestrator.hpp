#pragma once

#include <memory>
#include <thread>
#include <vector>

struct Broker;
struct Module;
struct Orchestrator
{
    auto register_model(Module *model) -> void;

    auto run(Broker &broker) -> void;

    std::vector<Module *> modules;
    std::vector<std::jthread> threads;
};
