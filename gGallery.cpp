#include "gGallery.h"

gBackground::gBackground(){
    posBackground.getPos(0, 0);
    string back_path = "image/sky.png";
    Load_Img( back_path.c_str());
}

gBackground::~gBackground(){
    free();
}

void gBackground::render(){
    if (posBackground.x > 0) {
        Render_Img(posBackground.x, posBackground.y);
    } else if (posBackground.x > -1105 && posBackground.x <= 0){
        Render_Img(posBackground.x, posBackground.y);
        Render_Img(posBackground.x + 1105, posBackground.y, 0, NULL);
    } else {
        posBackground.getPos(0, 0);
        Render_Img(posBackground.x, posBackground.y);
    }
}


void gBackground::moveBackground(){
    posBackground.x -= 3; 
}

vector<Position> posTree;

bool gTree::init(){
    posTree.clear();
    for (int i = 0; i < tree_total; i++) {
        Position temp;
        temp.getPos(SCREEN_WIDTH + i * tree_distance + 350, (rand() % (treeMax - treeMin + 1)) + treeMin);
        posTree.push_back(temp);
    }
    if (Load_Img( "image/tree.png")){
            return true;
        }
    
    return false;
}

void gTree::Free(){
    free();
}

void gTree::render(){
    for (int i = 0; i < tree_total; i++) {

        // draw up-tree
        if (posTree[i].x <= SCREEN_WIDTH && posTree[i].x > -65) {
            Render_Img(posTree[i].x, posTree[i].y);
        }

        // draw down-tree
        Render_Img(posTree[i].x, posTree[i].y + 373 + tree_space, 180);
    }
}

void gTree::update(){
    if (!die){
        for (int i = 0; i < tree_total; i++){

            // when tree move out of screen
            if (posTree[i].x < - 65) {

                // random tree.y
                posTree[i].y = (rand() % (treeMax - treeMin + 1)) + treeMin;

                // tree.x = prev tree.x + tree_distance
                posTree[i].x = posTree[(i + tree_total - 1) % tree_total].x + tree_distance;

                // update tree's direction
                posTree[i].direction = (rand() % 2 == 0) ? -1 : 1;

            } else {
                posTree[i].x -= 3;

                // change direction
                if (posTree[i].y <= treeMin || posTree[i].y >= treeMax){
                    posTree[i].direction *= -1;
                }
                posTree[i].y += posTree[i].direction * 1;
            }
        }
    }
}


bool gBird::init(){
    string bird_path = "image/bird.png";
    if (saved_path == bird_path){
        posBird.getPos(100 , SCREEN_HEIGHT / 2.5);
        ahead = 0;
        angle = 0;
    }
    if (saved_path != bird_path){
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

void gBird::update(){
    if (!die) {
        if (time == 0){
            x0 = posBird.y;
            angle = -20;
        } else if (angle < 70 && time > 30) {
            angle += 3;
        }

        if (time >= 0) {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        // when the bird touch the tree
        if ( (posBird.x + bird_width > posTree[ahead].x + 5) && (posBird.x + 5 < posTree[ahead].x + tree_width) &&
             (posBird.y + 5 < posTree[ahead].y + tree_height || posBird.y  + bird_height > posTree[ahead].y + tree_height + tree_space + 5) ) {
            die = true;

        // when the bird fly pass the tree
        } else if (posBird.x > posTree[ahead].x + tree_width ) {
            ahead = ( ahead + 1 ) % tree_total;
            score++;        
        }

        // when the bird fly out of the screen
        if (posBird.y > SCREEN_HEIGHT -  bird_height || posBird.y < - 10 ) {
            die = true;
        }
    }
}
