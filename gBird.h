#pragma once

#include "gUtils.h"
#include "gTree.h"

class gBird : gUtils{
public:
    bool init();

    void render();

    void Free();

    void resetTime() {
        time = 0;
    }

    void fall();

    void update(int treeWidth, int treeHeight);
private:

    //time : biểu thị thời gian đã trôi qua kể từ lần cuối cùng con chim được nhảy. Được sử dụng để tính toán vị trí của con chim trên trục y khi điều khiển di chuyển của nó
    //x0: là giá trị tọa độ y của con chim (chỉ số đơn vị pixel) lúc nó bắt đầu rơi xuống hoặc nhảy lên.
    int angle, time, x0;
    int ahead = 0;
    string saved_path = "";
    Position posBird;
};