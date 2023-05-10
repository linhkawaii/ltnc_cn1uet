#pragma once

#include "gUtils.h"

class gMenu : public gUtils{
private:
    Position posMenu;
    string menu_path = "image/bg_start.png";
    SDL_Texture* menuScreen;
public:
    gMenu();
    
    void render_bgStart();
    bool checkStart();
    bool checkQuit_Start();
    bool checkHowToPlay();
    void renderHowToPlay();
    bool checkBack();
    void display();
};