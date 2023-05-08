#pragma once

#include "gUtils.h"

using namespace std;

extern vector<Position> posTree;

class gTree : gUtils{
private:
    // random pipe verticly position
    const int treeMin = -373 + 30;
    const int treeMax = SCREEN_HEIGHT - 373 - tree_distance - 30;
public:
    bool init();

    void Free();

    void render();

    void update();

    int width() {return getWidth();}

    int height() {return getHeight();}
};