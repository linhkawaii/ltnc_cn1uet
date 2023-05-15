#pragma once

#include "gUtils.h"

class gMenu : public gUtils{
private:
    Position posMenu;
    string menu_path = "image/bg_start.png";
    Mix_Chunk* click = NULL;
    Mix_Chunk* menuMusic = NULL;
    string click_path = "sound/click_music.wav";
    string menuMusic_path = "sound/menu_music.wav";
    
public:
    gMenu();
    void clickSound();
    void menuSound();
    void freeSound();
    void render_bgStart();
    bool checkStart();
    bool checkQuit_Start();
    bool checkHowToPlay();
    void renderHowToPlay();
    bool checkBack();
    void display();
};