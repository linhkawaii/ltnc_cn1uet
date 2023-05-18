#include "gSound.h"


bool gSound::loadSound(){
    string click_path = "sound/click_music.wav";
    string press_path = "sound/press_music.wav";
    string die_path = "sound/die_music.wav";
    string menu_path = "sound/background_music.wav";
    string sound_path = "image/sound.png";
    posSound.getPos(560, 10);
    bool success = true;
 
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0){
        success = false;
    } else {

        if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {
            success = false;
        }
        click = Mix_LoadWAV(click_path.c_str());
        if (click == NULL){
            success = false;
        }
        press = Mix_LoadWAV(press_path.c_str());
        if (press == NULL){
            success = false;
        }
        die = Mix_LoadWAV( die_path.c_str() );
        if (die == NULL) {
            success = false;
        }
        if (!Load_Img(sound_path)){
            return false;
        }
        On = {0, 0, 32, 24};
        Off = {0, 24, 32, 24};
        isPlay = true;
    }
    return success;
}

void gSound::setisPlay(bool tmp){
    isPlay = tmp;
}

void gSound::closeSound(){
    free();
    //release memory type Mix_Chunk
    Mix_FreeChunk(die);
    Mix_FreeChunk(press);
    Mix_FreeChunk(click);
    die = NULL;
    press = NULL;
    click = NULL;
    Mix_Quit();
}

void gSound::playClick(){
    if (isPlay){
        // play sound once
        Mix_PlayChannel(-1, click, 0);
    }
}

void gSound::playPress(){
    if (isPlay){
        Mix_PlayChannel(-1, press, 0);
    }
}

void gSound::playDie(){
    if (isPlay){
        Mix_PlayChannel(-1, die, 0);
    }
}

void gSound::renderSound(){
    if (isPlay){
        Render_Img(posSound.x, posSound.y, 0, &On);
    } else{
        Render_Img(posSound.x, posSound.y, 0, &Off);
    }
}

bool gSound::checkSound(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > posSound.x && x < posSound.x + getWidth() && y > posSound.y && y < posSound.y + getHeight()) {       
            isPlay = !isPlay;
            return true;
    }
    return false;
}