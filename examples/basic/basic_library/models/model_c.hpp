#pragma once

#include "models/model.hpp"

struct ModelC : Model
{
    auto update() -> void override;

    int data{};
};
