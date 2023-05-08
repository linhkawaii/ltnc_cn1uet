#include "gUtils.h"
#include <iostream>

bool gUtils::quit = false;
bool gUtils::die = true;
int gUtils::score = 0;
SDL_Window* gUtils::gWindow = NULL;
SDL_Renderer* gUtils::gRenderer = NULL;
SDL_Event gUtils::event;

gUtils::gUtils(){
	gTexture = NULL;
}

int gUtils::getWidth(){
	return tWidth;
}

int gUtils::getHeight(){
	return tHeight;
}

void gUtils::free(){
	if( gTexture != NULL ){
		SDL_DestroyTexture( gTexture );
		gTexture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

void gUtils::Render_Img(int x, int y, int angle, SDL_Rect* clip, SDL_RendererFlip flip){
	SDL_Rect Rec_Render = { x, y, tWidth, tHeight };
    if( clip != NULL )	{
		Rec_Render.w = clip->w ;
		Rec_Render.h = clip->h ;
	}
    SDL_RenderCopyEx( gRenderer, gTexture, clip, &Rec_Render, angle, NULL, flip );
}

bool gUtils::Load_Img(string path){
	free();
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )	{
        return false;
	} else {
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );
        gTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( gTexture == NULL ){
            return false;
		}else{
			tWidth = (loadedSurface->w);
			tHeight = (loadedSurface->h);
		}
		SDL_FreeSurface( loadedSurface );
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); // white 
	return gTexture != NULL;
}

bool gUtils::isNULL(){
    if (gTexture == NULL) return true;
    return false;
}

void Position::getPos(const int x, const int y){
    this->x = x;
    this->y = y;
}

void gUtils::initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return ;

    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) return;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) return;

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
        return;
    }
    
    if( TTF_Init() == -1 ){
        return;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
}

void gUtils::quitSDL(SDL_Window* window, SDL_Renderer* renderer){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}