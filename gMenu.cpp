#include "gMenu.h"

gMenu::gMenu(){
    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    click = Mix_LoadWAV(click_path.c_str());
    menuMusic = Mix_LoadWAV(menuMusic_path.c_str());
}

void gMenu::display(){
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
}

void gMenu::clickSound(){
    Mix_PlayChannel(-1, click, 0);
}

void gMenu::menuSound(){
    Mix_PlayChannel(-1, menuMusic, 0);
    
}

void gMenu::freeSound(){
    Mix_FreeChunk(menuMusic);
    //Mix_Quit();
}
void gMenu::render_bgStart(){
    gUtils image;
    image.Load_Img(menu_path);
    image.Render_Img(0, 0);
    image.free();
}

bool gMenu::checkStart(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > 326 && x < 326 + 190 && y > 231 && y < 231 + 41) return true;
    return false;
}

bool gMenu::checkQuit_Start(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > 326 && x < 326 + 190 && y > 274 && y < 274 + 41) return true;
    return false;
}

bool gMenu::checkHowToPlay(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > 326 && x < 326 + 190 && y > 317 && y < 317 + 41) return true;
    return false;
}


void gMenu::renderHowToPlay(){
    gUtils image;
    image.Load_Img("image/howToPlay.png");
    image.Render_Img(0, 0);
    image.free();
}

bool gMenu::checkBack(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 240 && y < 240 + 41) return true;
    return false;
}

// void gMenu::renderBirdList(){
//     gUtils image;
//     image.Load_Img("image/birdList.png");
//     image.Render_Img(0, 0);
//     image.free();
// }