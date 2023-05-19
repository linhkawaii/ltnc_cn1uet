#pragma once

#include "gutils.h"

class gScore : gUtils{
private:
    TTF_Font* m_font;
    SDL_Rect m_rect;
    SDL_Rect m_rect1;
    SDL_Rect m_rect2;
    SDL_Color textColor;

public:
    gScore();
    ~gScore();
    void render(int score);
    void render_yourscore(int score);
    void render_bestscore(int score);
    
    void loadFont(string text, SDL_Rect rect);
};