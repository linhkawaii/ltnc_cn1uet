#include "gBird.h"

bool gBird::init(){
    string bird_path = "image/shiba.png";
    if (saved_path == bird_path){
        posBird.getPos(75 , SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != bird_path){
        saved_path = bird_path;
        if ( Load_Img(bird_path.c_str())) return true;
        else return false;
    }
    return false;
}

void gBird::Free(){
    free();
}


void gBird::render(){
    Render_Img(posBird.x, posBird.y, angle);
}

void gBird::update(int treeWidth, int treeHeight){
    if (!die) {
        if (time == 0){
            x0 = posBird.y;
            angle = -25;
        } else if (angle < 70 && time > 30) {
            angle += 3;
        }

        if (time >= 0) {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ( (posBird.x + getWidth() > posTree[ahead].x + 5) && (posBird.x + 0 < posTree[ahead].x + treeWidth) &&
             (posBird.y + 5 < posTree[ahead].y + treeHeight || posBird.y  + getHeight() > posTree[ahead].y + treeHeight + tree_space + 5) ) {
            die = true;
        } else if (posBird.x > posTree[ahead].x + treeWidth ) {
            ahead = ( ahead + 1 ) % tree_total;
            score++;        
        }

        if (posBird.y > SCREEN_HEIGHT -  bird_height || posBird.y < - 10 ) {
            die = true;
        }
    }
}