#pragma once

#include "gUtils.h"

using namespace std;

class gSound : gUtils{
public:
    bool loadSound();
    void closeSound();
    void playPress();
    void playDie();
    void playClick();
    void playMenuSound();
    void renderSound();
    bool checkSound();
    void setisPlay(bool tmp);

private:
    Position posSound;
    bool isPlay;

    // sound file
    Mix_Chunk* click = NULL;
    Mix_Chunk* press = NULL;
    Mix_Chunk* die = NULL;
    SDL_Rect Off ;
    SDL_Rect On ;
};