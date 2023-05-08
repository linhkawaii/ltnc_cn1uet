#include "gBackground.h"

bool gBackground::init(){
    posBackground.getPos(0, 0);
    string back_path = "image/sky.png";
    if (isNULL()){
        if ( Load_Img( back_path.c_str()) ) return true;
        else return false;
    }
    return false;
}

void gBackground::Free(){
    free();
}

void gBackground::render(){
    if (posBackground.x > 0) {
        Render_Img(posBackground.x, posBackground.y);
    } else if (posBackground.x > -1105 && posBackground.x <= 0){
        Render_Img(posBackground.x, posBackground.y);
        Render_Img(posBackground.x + 1105, posBackground.y, 0, NULL);
    } else {
        posBackground.getPos(0, 0 );
        Render_Img(posBackground.x, posBackground.y);
    }
}


void gBackground::update(){
    posBackground.x -= 3; 
}
