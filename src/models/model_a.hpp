#pragma once

#include "model.hpp"

struct ModelA : Model
{
    ModelA() = default;
    auto initialize() -> void override;
    auto update() -> void override;
    auto run(std::stop_token stop_token, std::condition_variable &cv) -> void override;
    auto finalize() -> void override;
};
