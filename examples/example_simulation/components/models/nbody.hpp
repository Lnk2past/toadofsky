#pragma once

#include "models/body.hpp"

#include <vector>

struct NBody
{
    auto update(const double dt) -> void;

    double time{};
    std::vector<Body> bodies;
};
