#pragma once

#include "gUtils.h"

class gBackground : gUtils{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    Position posBackground;
};