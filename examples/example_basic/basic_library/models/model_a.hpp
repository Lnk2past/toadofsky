#pragma once

#include "models/model.hpp"

struct ModelA : Model
{
    auto update() -> void override;

    int data1{};
    double data2{};
};
