#include "gGame.h"

void gGame::takeInput(){
    while(SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            userInput.Type = input::QUIT;
            quit = true;
        } else if (event.type == SDL_MOUSEBUTTONDOWN || (event.type == SDL_KEYDOWN && 
		(event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0 )){
            userInput.Type = input::PLAY;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0){
			userInput.Type = input::PAUSE;
		}
    }
}

gGame::gGame(){
    //initGraphic();
    tree.init();
    background.init();
    sound.loadSound();
}

gGame::~gGame(){
    bird.Free();
    tree.Free();
    background.Free();
    sound.closeSound();
    free();
    releaseGraphic();
}

void gGame::releaseGraphic(){
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_DestroyRenderer( gRenderer );
    gRenderer = NULL;
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

// bool gGame::initGraphic(){
// 	bool success = true;

// 	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
// 		success = false;
// 	}else{
// 		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
// 		}

// 		gWindow = SDL_CreateWindow( "Fly Birdie", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

// 		if( gWindow == NULL ){
// 			success = false;
// 		}else{
// 			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
// 			if( gRenderer == NULL )	{
// 				success = false;
// 			}else{
// 				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

// 				int imgFlags = IMG_INIT_PNG;
// 				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
// 					success = false;
// 				}

// 				if( TTF_Init() == -1 ){
// 					success = false;
// 				}
// 			}
// 		}
// 	}

// 	return success;
// }

void gGame::setDie(bool tmp){
    die = tmp;
}

void gGame::display(){
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
}

void gGame::renderReady(){
	gUtils image;
	image.Load_Img("image/ready.png");
	image.Render_Img((SCREEN_WIDTH - image.getWidth()) / 2, 80);
	image.free();
}

void gGame::renderTextScore(){
    gScore.render(score);
}

void gGame::renderYourScore(){
    gScore.render_yourscore(score);
}

void gGame::renderBestScore(){
    // đọc giá trị từ file
	ifstream fin("bestSCore/bestScore.txt");
	fin >> bestScore; 

    //cập nhât best score mới
	ofstream fout("bestScore/bestScore.txt", ios::trunc);
    if (score > bestScore) bestScore = score;

    gScore.render_bestscore(bestScore);

    fout << bestScore;
    fin.close();
    fout.close();
}

void gGame::renderPauseTab(){
	gUtils image;
	image.Load_Img("image/pauseTab.png");
	image.Render_Img(0, 0);
	image.free();
}

void gGame::renderGameOver(){
	gUtils image;
	image.Load_Img("image/gameOver.png");
	image.Render_Img(0, 0);
	image.free();
}

bool gGame::checkResume(){
	int x, y;
	SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 116 && y < 116 + 41) return true;
	return false;
}

bool gGame::checkReplay(){
	int x, y;
	SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 231 && y < 231 + 41) return true;
	return false;
}

bool gGame::checkQuit_Paused(){
	int x, y;
	SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 203 && y < 203 + 41) return true;
	return false;
}

bool gGame::checkRestart(){
	int x, y;
	SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 159 && y < 159 + 41) return true;
	return false;
}

bool gGame::checkQuit_GameOver(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > 205 && x < 205 + 190 && y > 273 && y < 273 + 41) return true;
    return false;
}

void gGame::Restart(){
    die = false;
    score = 0;
    bird.resetTime();
}

// void gGame::render_bgStart(){
//     gUtils image;
//     image.Load_Img("image/bg_start.png");
//     image.Render_Img(0, 0);
//     image.free();
// }

// bool gGame::checkStart(){
//     int x, y;
//     SDL_GetMouseState(&x, &y);
//     if (x > 322 && x < 322 + 190 && y > 212 && y < 212 + 41) return true;
//     return false;
// }

// bool gGame::checkQuit_Start(){
//     int x, y;
//     SDL_GetMouseState(&x, &y);
//     if (x > 322 && x < 322 + 190 && y > 255 && y < 255 + 41) return true;
//     return false;
// }

// bool gGame::checkHowToPlay(){
//     int x, y;
//     SDL_GetMouseState(&x, &y);
//     if (x > 322 && x < 322 + 190 && y > 298 && y < 298 + 41) return true;
//     return false;
// }

// void gGame::renderHowToPlay(){
//     gUtils image;
//     image.Load_Img("image/howToPlay.png");
//     image.Render_Img(0, 0);
//     image.free();
// }

// bool gGame::checkBack(){
//     int x, y;
//     SDL_GetMouseState(&x, &y);
//     if (x > 204 && x < 204 + 190 && y > 254 && y < 254 + 41) return true;
//     return false;
// }