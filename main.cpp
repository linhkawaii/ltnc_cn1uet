#include "gGame.h"
#include "gMenu.h"

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int argc, char** argv){
    Uint32 frameStart;
    int frameTime;
    bool isMenu = 0;
    bool isPause = 0;  
    bool isSound = 1;

    bool running = false;
    bool Menu = true;
    SDL_Event e;
    gMenu menu;
    bool check = false;
    bool checkback = false;
    while (1){
        menu.menuSound();
        while(Menu){
            menu.render_bgStart();
            menu.display();
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT ){
                    Menu = false;
                    running = false;
                    exit(0);
                }

                if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkQuit_Start()){
                    menu.clickSound();
                    SDL_Delay(500);
                    Menu = false;
                    running = false;
                    exit(0);
                }

                if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkHowToPlay()){
                    menu.clickSound();
                    Menu = false;
                    check = true;
                    break;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkStart()){
                    menu.clickSound();
                    running = true;
                    Menu = false;
                }

            }
            if(check){
                break;
            }
        }

        if (check == true){
            while (1){
                menu.renderHowToPlay();
                menu.display();
                SDL_Event E;
                while (SDL_PollEvent(&E)){
                    if (E.type == SDL_QUIT){
                        return 0;
                    }
                    if (E.type == SDL_MOUSEBUTTONDOWN && menu.checkBack()){
                        menu.clickSound();
                        Menu = true;
                        check=false;
                        checkback = true;
                        break;
                    }
                }
                if(checkback){
                    break;
                }
            }
        }
        if (running == true){
            menu.freeSound();
            break;
        }
    }


    if (running == true){
        gGame g;
        while(!g.isQuit()) {
            if (g.isDie()) { 
                
                if (isMenu) {
                    g.sound.playDie();
                    g.bird.render();
                }
                g.userInput.Type = gGame::input::NONE;
                while(g.isDie() && !g.isQuit()) {
                    g.takeInput();
                    if (isMenu == 1 && g.userInput.Type == gGame::input::PLAY) {
                        if (g.checkReplay()){
                            menu.clickSound();
                            isMenu = 0;

                        } else if (g.checkQuit_GameOver()){
                            menu.clickSound();
                            SDL_Delay(500);
                            return 0;
                        }
                        g.userInput.Type = gGame::input::NONE;
                    }
                    g.background.render();
                    g.tree.render();

                    if (isMenu) {
                        g.bird.render();
                        g.renderGameOver();
                        g.renderYourScore();
                        g.renderBestScore();

                    } else {
                        g.tree.init();
                        g.bird.init(); 
                        g.bird.render();
                        g.renderReady();  
                        if (g.userInput.Type == gGame::input::PLAY) {
                            g.Restart();
                            isMenu = 1;
                            g.userInput.Type = gGame::input::NONE;
                        }
                        g.background.moveBackground();
                    }
                    g.display();
                }
                g.tree.init();


            } else {
                
                g.takeInput();

                if (g.userInput.Type == gGame::input::PAUSE) {
                    isPause =  !isPause; 
                    g.userInput.Type = gGame::input::NONE;
                }

                if (isPause == 0 && g.userInput.Type == gGame::input::PLAY) {
                    //if (isSound == 1) g.sound.playMenuSound();
                    g.bird.resetTime(); 
                    g.userInput.Type = gGame::input::NONE;
                }

                g.background.render();
                g.tree.render();
                g.bird.render();
                g.renderTextScore();

                if (!isPause) {
                    g.sound.renderSound();
                    g.bird.update();
                    g.background.moveBackground();
                    g.tree.update();
                } else {
                    g.renderPauseTab(); 
                    g.sound.renderSound();
                    if (g.userInput.Type == gGame::input::PLAY) {
                        if (g.checkResume()){
                            menu.clickSound();
                            isPause = 0;
                        } else if (g.sound.checkSound()){
                            menu.clickSound();
                            isSound = !isSound;
                        } else if (g.checkQuit_Paused()){
                            menu.clickSound();
                            SDL_Delay(500);
                            return 0;
                        } else if (g.checkRestart()){
                            menu.clickSound();
                            isMenu = 0;
                            isPause = 0;
                            g.setDie(1);

                        }
                        g.userInput.Type = gGame::input::NONE;
                    }
                }
                g.display();
            }
            

            frameTime = SDL_GetTicks() - frameStart;
            if (frameDelay > frameTime) {
                SDL_Delay(frameDelay - frameTime);
            }
        }        
    }

    return 0;

}