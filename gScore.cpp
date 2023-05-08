#include "gScore.h"

using namespace std;

bool gScore::init(){
    textColor = {0, 0, 0};
    m_rect = {10, 5, 80, 50};
    m_rect1 = {345, 140, 10, 20};
    m_rect2 = {345, 185, 10, 20};

    m_font = TTF_OpenFont("font/Southern.ttf", 25);
    if (!m_font) return false;
    return true;
}

void gScore::Free(){
    free();
}

void gScore::render(int score){
    string scoreStr = "Score: " + to_string(score);

    if (gTexture){
        SDL_DestroyTexture(gTexture);
    }

    SDL_Surface* surface = nullptr;

    surface = TTF_RenderText_Solid(m_font, scoreStr.c_str(), textColor);
    if (surface == nullptr) return;
    
    gTexture = SDL_CreateTextureFromSurface(gRenderer, surface);

    SDL_QueryTexture(gTexture, nullptr, nullptr, &m_rect.w, &m_rect.h);

    SDL_RenderCopy(gRenderer, gTexture, nullptr, &m_rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(gTexture);
}

void gScore::render_yourscore(int score){
    string yourscore = to_string(score);

    if (gTexture){
        SDL_DestroyTexture(gTexture);
    }

    SDL_Surface* surface = TTF_RenderText_Solid(m_font, yourscore.c_str(), textColor);
    if (surface == NULL) return;

    gTexture = SDL_CreateTextureFromSurface(gRenderer, surface);

    SDL_QueryTexture(gTexture, nullptr, nullptr, &m_rect1.w, &m_rect1.h);

    SDL_RenderCopy(gRenderer, gTexture, nullptr, &m_rect1);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(gTexture);
}

void gScore::render_bestscore(int score){
    string bestscore = to_string(score);

    if (gTexture){
        SDL_DestroyTexture(gTexture);
    }

    SDL_Surface* surface = TTF_RenderText_Solid(m_font, bestscore.c_str(), textColor);
    if (surface == NULL) return;

    gTexture = SDL_CreateTextureFromSurface(gRenderer, surface);

    SDL_QueryTexture(gTexture, nullptr, nullptr, &m_rect2.w, &m_rect2.h);

    SDL_RenderCopy(gRenderer, gTexture, nullptr, &m_rect2);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(gTexture);
}