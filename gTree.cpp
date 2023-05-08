#include "gTree.h"

vector<Position> posTree;

bool gTree::init(){
    posTree.clear();
    for (signed char i = 0; i < tree_total; i++) {
        Position temp;
        temp.getPos(SCREEN_WIDTH + i * tree_distance + 350, (rand() % (treeMax - treeMin + 1)) + treeMin);
        posTree.push_back(temp);
    }
    if (isNULL()) {
        if (Load_Img( "image/pipe.png")){
            return true;
        }
    }
    return false;
}

void gTree::Free(){
    free();
}

void gTree::render(){
    for (signed char i = 0; i < tree_total; i++) {

        //vẽ ống trên
        if (posTree[i].x <= SCREEN_WIDTH && posTree[i].x > -getWidth()) {
            Render_Img(posTree[i].x, posTree[i].y);
        }

        // vẽ ống dưới
        Render_Img(posTree[i].x, posTree[i].y + getHeight() + tree_space, 180);
    }
}

void gTree::update(){
    if (!die){
        for (signed char i = 0; i < tree_total; i++){
            if (posTree[i].x < - getWidth()) {
                posTree[i].y = (rand() % (treeMax - treeMin + 1)) + treeMin;
                posTree[i].x = posTree[(i + tree_total - 1) % tree_total].x + tree_distance;
            } else {
                posTree[i].x -= 3;
            }
        }
    }
}