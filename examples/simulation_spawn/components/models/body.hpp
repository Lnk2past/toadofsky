#pragma once

#include <array>
#include <cmath>

static constexpr auto G = 6.67430e-11;
static auto body_id = int{};

struct Body
{
    std::array<double, 2> position{};
    std::array<double, 2> velocity{};
    std::array<double, 2> acceleration{};
    double mass{5e9};
    int id{body_id++};

    auto get_force(const Body &o)
    {
        auto dx = o.position[0] - position[0];
        auto dy = o.position[1] - position[1];
        auto d = std::sqrt(dx * dx + dy * dy);
        auto f = G * o.mass / (d * d); // no need to multiply by mass
        auto t = std::atan2(dy, dx);
        acceleration[0] += f * std::cos(t);
        acceleration[1] += f * std::sin(t);
    }

    auto update(const double dt)
    {
        velocity[0] += acceleration[0] * dt;
        velocity[1] += acceleration[1] * dt;
        position[0] += velocity[0] * dt + 0.5 * acceleration[0] * dt * dt;
        position[1] += velocity[1] * dt + 0.5 * acceleration[1] * dt * dt;
        acceleration = {};
    }
};
