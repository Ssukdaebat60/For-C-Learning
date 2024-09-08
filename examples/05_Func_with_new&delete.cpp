#include <iostream>

using namespace std;

typedef struct _Point{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point * pntadder = new Point;
    pntadder->xpos = p1.xpos + p2.xpos;
    pntadder->ypos = p1.ypos + p2.ypos;
    return * pntadder;
}

int main() {
    Point * pntarr = new Point[2];
    pntarr[0].xpos = 0;
    pntarr[0].ypos = 1;
    pntarr[1].xpos = 0;
    pntarr[1].ypos = 1;
    Point &sum = PntAdder(pntarr[0], pntarr[1]);
    cout << sum.xpos << ','<< sum.ypos;
    delete pntarr;
    delete &sum;
    return 0;
}
