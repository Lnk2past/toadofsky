#pragma once

#include <latch>
#include <thread>

struct Broker;
struct Module
{
    virtual ~Module() = default;
    virtual auto initialize(Broker &) -> void = 0;
    virtual auto update(Broker &) -> bool = 0;
    virtual auto run(std::stop_token, std::latch &, Broker &) -> void = 0;
    virtual auto finalize() -> void = 0;
};
