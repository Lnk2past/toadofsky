#include <condition_variable>
#include <mutex>
#include <fmt/format.h>
#include "model_b.hpp"

auto ModelB::initialize() -> void
{
    fmt::print("Initializing Model B\n");
}

auto ModelB::update() -> void
{
    fmt::print("Updating Model B\n");
}

auto ModelB::run(std::stop_token stop_token, std::condition_variable &cv) -> void
{
    auto m = std::mutex{};
    auto lk = std ::unique_lock(m);
    cv.wait(lk);
    while (!stop_token.stop_requested())
    {
        update();
    }
}

auto ModelB::finalize() -> void
{
    fmt::print("Finalizing Model B\n");
}