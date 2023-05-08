#pragma once

#include "gUtils.h"
#include "gBird.h"
#include "gTree.h"
#include "gBackground.h"
#include "gSound.h"
#include "gScore.h"

class gGame : gUtils{
public:
    struct input {
        enum type { QUIT, PLAY, NONE, PAUSE};
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

    bool initGraphic();

    bool isQuit() {
        return quit; 
    }

    bool isDie() {
        return die;
    }

    int getPipeWidth() {
        return tree.width();
    }

    int getPipeHeight() {
        return tree.height();
    }

    void takeInput();

    void display();

    void releaseGraphic();

    void renderReady();

    void renderTextScore();

    void renderYourScore();

    void renderBestScore();

    void resume();

    void pause();

    void renderPauseTab();

    void renderGameOver();

    bool checkResume();

    bool checkRestart();

    bool checkQuit_Paused();
    
    bool checkReplay();

    bool checkQuit_GameOver();

    void Restart();


private: 
    int bestScore;
};