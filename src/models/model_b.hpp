#pragma once

#include "models/model.hpp"

struct ModelB : Model
{
    auto update() -> void override;
};
