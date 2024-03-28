#include <fmt/format.h>
#include "model_a.hpp"

auto ModelA::initialize() -> void
{
    fmt::print("Initializing Model A\n");
}

auto ModelA::update() -> void
{
    fmt::print("Updating Model A\n");
}

auto ModelA::run(std::stop_token stop_token, std::condition_variable &cv) -> void
{
    auto m = std::mutex{};
    auto lk = std ::unique_lock(m);
    cv.wait(lk);
    while (!stop_token.stop_requested())
    {
        update();
    }
}

auto ModelA::finalize() -> void
{
    fmt::print("Finalizing Model A\n");
}