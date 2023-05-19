#pragma once

#include "gUtils.h"

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
    // int space = rand() % (treeMax - treeMin + 1) + treeMin;
    const int treeMin = -tree_height + 30;
    const int treeMax = SCREEN_HEIGHT - tree_height - tree_space - 30;
    

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
    void resetFrame(){
        frame = 0;
    }
    void update();

private:
    int angle, frame, y_;
    int ahead = 0;
    string saved_path = "";
    Position posBird;
};