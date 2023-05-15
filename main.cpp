#include "gGame.h"
#include "gMenu.h"

int main(int argc, char** argv){
    SDL_Event e;
    gMenu menu;
    bool isTab = 0;
    bool isPause = 0;  
    bool isSound = 1;
    bool running = false;
    bool Menu = true;
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

    gGame game;
    game.run(running, isTab, isPause, isSound);
    game.close();
    return 0;

}