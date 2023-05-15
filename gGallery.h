#pragma once

#include "gUtils.h"
#include "gMenu.h"

class gBackground : gUtils{
public:
    gBackground();
    ~gBackground();
    void render();
    void moveBackground();

private:
    Position posBackground;
};


extern vector<Position> posTree;

class gTree : gUtils{
private:
    // random pipe verticly position
    const int treeMin = -373 + 20;
    const int treeMax = SCREEN_HEIGHT - 373 - tree_distance - 20;
    

public:
    bool init();
    void Free();
    void render();
    void update();
};


class gBird : gUtils{
public:
    bool init();
    void render();
    void Free();
    void resetTime(){
        time = 0;
    }
    void update();
    void chooseBird();

private:
    int angle, time, x0;
    int ahead = 0;
    string saved_path = "";
    Position posBird;
};