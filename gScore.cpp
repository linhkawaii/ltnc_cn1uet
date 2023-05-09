#include "gScore.h"

using namespace std;

gScore::gScore(){
    textColor = {0, 0, 0};
    m_rect = {10, 5, 80, 50};
    m_rect1 = {345, 140, 10, 20};
    m_rect2 = {345, 185, 10, 20};
    m_font = TTF_OpenFont("font/Southern.ttf", 25);
}

gScore::~gScore(){
    free();
    TTF_CloseFont(m_font);
    TTF_Quit();
}

void gScore::loadFont(string text, SDL_Rect rect){
    if (gTexture){
        SDL_DestroyTexture(gTexture);
    }

    SDL_Surface* surface = nullptr;

    surface = TTF_RenderText_Solid(m_font, text.c_str(), textColor);
    if (surface == nullptr) return;
    
    gTexture = SDL_CreateTextureFromSurface(gRenderer, surface);

    SDL_QueryTexture(gTexture, nullptr, nullptr, &rect.w, &rect.h);

    SDL_RenderCopy(gRenderer, gTexture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(gTexture);
}

void gScore::render(int score){
    string scoreStr = "Score: " + to_string(score);
    loadFont(scoreStr, m_rect);
}

void gScore::render_yourscore(int score){
    string yourscore = to_string(score);
    loadFont(yourscore, m_rect1);
}

void gScore::render_bestscore(int score){
    string bestscore = to_string(score);
    loadFont(bestscore, m_rect2);
}