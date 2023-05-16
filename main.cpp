#include "gGame.h"
#include "gMenu.h"

int main(int argc, char** argv){
    SDL_Event e;
    gMenu menu;
    bool isTab = 0;
    bool isPause = 0;  
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
                    // cout << "click quit" << endl;
                    menu.clickSound();
                    SDL_Delay(300);
                    Menu = false;
                    running = false;
                    exit(0);
                }

                if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkHowToPlay()){
                    // cout << "click howToPlay" << endl;
                    menu.clickSound();
                    Menu = false;
                    check = true;
                    break;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkStart()){
                    // cout << "click start" << endl;
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
                while (SDL_PollEvent(&e)){
                    if (e.type == SDL_QUIT){
                        return 0;
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN && menu.checkBack()){
                        // cout << "click back" << endl;
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
    game.run(running, isTab, isPause);
    game.close();
    return 0;

}