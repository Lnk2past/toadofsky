#pragma once

struct Model
{
    virtual ~Model() = default;
    virtual auto update() -> void = 0;
};
