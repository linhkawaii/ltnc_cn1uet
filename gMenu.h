#pragma once

#include "gUtils.h"
#include "gSound.h"

class gMenu : public gUtils{
private:
    Position posMenu;
    string menu_path = "image/bg_start.png";
    gSound menu_sound;
public:
    gMenu();

    void render_bgStart();

    bool checkStart();

    bool checkQuit_Start();

    bool checkHowToPlay();

    void renderHowToPlay();

    bool checkBack();

    void playMenuSound();

    void display();

    void displayy();
    
};