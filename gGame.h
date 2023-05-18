#pragma once

#include "gUtils.h"
#include "gGallery.h"
#include "gSound.h"
#include "gScore.h"

class gGame : gUtils{
public:
    struct input {
        enum type { QUIT, PLAY, NONE, PAUSE, CLICK};
        type Type;
    };
    input userInput;
    gBird bird;
    gTree tree;
    gSound sound;
    gBackground background;
    gScore gScore;

    
    gGame();
    ~gGame();
    void setDie(bool tmp);
    void takeInput();
    void display();
    void releaseGraphic();
    void renderReady();
    void renderTextScore();
    void renderYourScore();
    void renderBestScore();
    void renderPauseTab();
    void renderGameOver();
    bool checkResume();
    bool checkRestart();
    bool checkQuit_Paused();
    bool checkReplay();
    bool checkQuit_GameOver();
    void Restart();
    void run(bool running, bool isMenu, bool isPause);
    void close();

private: 
    int bestScore;
};