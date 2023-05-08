#pragma once

#include "gUtils.h"

using namespace std;

class gSound : gUtils{
public:
    bool init();

    void Free();

    void playBreath();

    void playDie();

    void playPoint();

    void playMenuSound();

    void renderSound();

    bool checkSound();

private:
    const int POS_X = SCREEN_WIDTH - 80; 
    const int POS_Y = 10;
    bool isPlay = 0;

    //mẫu âm thanh được tải vào bộ nhớ
    Mix_Chunk* breath = NULL;
    Mix_Chunk* die = NULL;
    Mix_Chunk* point = NULL;
    Mix_Chunk* menu_sound = NULL;
    SDL_Rect Mute ;
    SDL_Rect Active ;
};