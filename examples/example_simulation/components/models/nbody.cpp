#include "models/nbody.hpp"

auto NBody::update(const double dt) -> void
{
    time += dt;
    for (auto &b1 : bodies)
    {
        for (auto &b2 : bodies)
        {
            if (&b1 == &b2)
            {
                continue;
            }
            b1.get_force(b2);
        }
    }
    for (auto &b1 : bodies)
    {
        b1.update(dt);
    }
}
