#pragma once

#include "gUtils.h"

using namespace std;

class gSound : gUtils{
public:
    bool loadSound();
    void closeSound();
    void playDie();
    void playMenuSound();
    void renderSound();
    bool checkSound();

private:
    Position posSound;
    bool isPlay = 0;

    Mix_Chunk* die = NULL;
    Mix_Chunk* menu_sound = NULL;
    SDL_Rect Off ;
    SDL_Rect On ;
};