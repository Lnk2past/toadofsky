#pragma once
#include <condition_variable>
#include <mutex>
#include <thread>

struct Model
{
    virtual ~Model() = default;
    virtual auto initialize() -> void = 0;
    virtual auto update() -> void = 0;
    virtual auto run(std::stop_token, std::condition_variable &) -> void = 0;
    virtual auto finalize() -> void = 0;
};
