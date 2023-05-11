#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace std;

// screen dimensions
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

//tree size
const int tree_space = 160;
const int tree_total = 4;
const int tree_distance = 220;
const int tree_width = 65;
const int tree_height = 373;

//bird size
const int bird_width = 60;
const int bird_height = 48;


class Position{
public:
    int x, y, angle;
    int direction = 1;
    void getPos(const int x, const int y);
};

class gUtils {
public:
    gUtils();

    ~gUtils() {}

    bool Load_Img(string path);

    int getWidth();
    int getHeight();

    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
        int screenWidth, int screenHeight, const char* windowTitle);

    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    
    void free();
    void Render_Img(int x, int y, int angle = 0,
                SDL_Rect* clip = NULL,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

    SDL_Texture* gTexture;

    int tWidth;
    int tHeight;
    static SDL_Renderer* gRenderer;
    static SDL_Window* gWindow;
    static SDL_Event event;
    static bool quit;
    static bool die;
    static int score;
};

