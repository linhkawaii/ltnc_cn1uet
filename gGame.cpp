#include "gGame.h"
#include "gUtils.h"
void gGame::takeInput(){
    while(SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            userInput.Type = input::QUIT;
            quit = true;
        } else if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0 ){
            userInput.Type = input::PLAY;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0){
			userInput.Type = input::PAUSE;
		} else if (event.type == SDL_MOUSEBUTTONDOWN){
            userInput.Type = input::CLICK;
        }
    }
}

gGame::gGame(){
    tree.init();
    //background.init();
    sound.loadSound();
}

gGame::~gGame(){
    bird.Free();
    tree.Free();
    //background.Free();
    sound.closeSound();
    quitSDL(gWindow, gRenderer);
}

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

void gGame::close(){
    quitSDL(gWindow, gRenderer);
}

void gGame::run(bool running, bool isMenu, bool isPause, bool isSound){
    int fps = 60;
    int framedelay = 1000 / fps;
    Uint32 framestart;
    int frametime;
    if (running){
        while(!quit){
            framestart = SDL_GetTicks();

            if(die){
                if (isMenu){
                    sound.playDie();
                    bird.render();
                }
                userInput.Type = input::NONE;
                while (die && !quit){
                    takeInput();
                    if (isMenu && userInput.Type == input::CLICK){
                        if(checkReplay()){
                            if (isSound) sound.playClick();
                            isMenu = 0;
                        } else if (checkQuit_GameOver()){
                            if (isSound) sound.playClick();
                            SDL_Delay(300);
                            return;
                        }
                        userInput.Type = input::NONE;
                    }
                    background.render();
                    tree.render();

                    if (isMenu){
                        bird.render();
                        renderGameOver();
                        renderYourScore();
                        renderBestScore();
                    } else {
                        tree.init();
                        bird.init();
                        bird.render();
                        renderReady();
                        if (userInput.Type == input::PLAY){
                            Restart();
                            isMenu = 1;
                            userInput.Type = input::NONE;
                        }
                        background.moveBackground();
                    }
                    display();
                }
                tree.init();

            } else {
                takeInput();

                if (userInput.Type == input::PAUSE){
                    isPause = !isPause;
                    userInput.Type = input::NONE;
                }

                if (isPause == 0 && userInput.Type == input::PLAY){
                    if (isSound) sound.playPress();
                    bird.resetTime();
                    userInput.Type = input::NONE;
                }

                

                background.render();
                tree.render();
                bird.render();
                renderTextScore();

                if (!isPause){
                    sound.renderSound();
                    bird.update();
                    background.moveBackground();
                    tree.update();
                } else {
                    renderPauseTab();
                    sound.renderSound();
                    if (userInput.Type == input::CLICK){
                        if (checkResume()){
                            if (isSound) sound.playClick();
                            isPause = 0;
                        } else if (sound.checkSound()){
                            if (isSound) sound.playClick();
                            isSound = !isSound;
                        } else if (checkQuit_Paused()){
                            if (isSound) sound.playClick();
                            SDL_Delay(300);
                            return;
                        } else if (checkRestart()){
                            if (isSound) sound.playClick();
                            isMenu = 0;
                            isPause = 0;
                            setDie(1);
                        }
                        userInput.Type = input::NONE;
                    }
                }
                display();
            }

        
        }
    }
}