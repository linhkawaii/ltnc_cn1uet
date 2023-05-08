#include "gSound.h"


bool gSound::init(){
    string breath_path = "sound/sfx_breath.wav";
    string die_path = "sound/sfx_die.wav";
    string point_path = "sound/sfx_point.wav";
    string menu_path = "sound/sfx_menu.wav";
    string sound_path = "image/sound.png";

    bool success = true;
 
    if (SDL_Init(SDL_INIT_AUDIO) < 0)    {
        success = false;
    } else {
        if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {
            success = false;
        }

        breath = Mix_LoadWAV( breath_path.c_str() );
        if ( breath == NULL ) {
            success = false;
        }

        die = Mix_LoadWAV( die_path.c_str() );
        if (die == NULL) {
            success = false;
        }
        point = Mix_LoadWAV( point_path.c_str() );
        if ( point == NULL ) {
            success = false;
        }

        menu_sound = Mix_LoadWAV( menu_path.c_str());
        if ( menu_sound == NULL ) {
            success = false;
        }
        

        if (!Load_Img(sound_path)){
            return false;
        }



        Active.x = 0;
        Active.y = 0;
        Active.w = getWidth();
        Active.h = getHeight() / 2;


        Mute.x = 0;
        Mute.y = getHeight() / 2;
        Mute.w = getWidth();
        Mute.h = getHeight() / 2;


        isPlay = true;
    }
    return success;
}

void gSound::Free(){
    free();
    Mix_FreeChunk(breath);
    breath = NULL;
    Mix_FreeChunk(die);
    die = NULL;
    Mix_FreeChunk(point);
    point = NULL;
    Mix_Quit();
}

void gSound::playBreath(){
    if (isPlay) {
        Mix_PlayChannel( -1, breath, 0 );
    }
}

void gSound::playDie(){
    if (isPlay){
        Mix_PlayChannel(-1, die, 0);
    }
}

void gSound::playPoint(){
    if (isPlay) {
        Mix_PlayChannel(-1, point, 0);
    }
}

void gSound::playMenuSound(){
    Mix_PlayChannel(-1, menu_sound, 0);
}

void gSound::renderSound(){
    if (isPlay){
        Render_Img(POS_X, POS_Y, 0, &Active);
    } else{
        Render_Img(POS_X, POS_Y, 0, &Mute);
    }
}

bool gSound::checkSound(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > POS_X && x < POS_X + getWidth() &&
        y > POS_Y && y < POS_Y + getHeight()) {       
            isPlay = !isPlay;
            return true;
    }
    return false;
}