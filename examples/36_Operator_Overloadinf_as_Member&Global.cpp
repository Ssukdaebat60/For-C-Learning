#include <iostream>

using namespace std;

class Point{
    private:
        int xpos;
        int ypos;
    public:
        friend  Point operator-(const Point &pos1, const Point &pos2);
        Point(int x = 0, int y = 0) : xpos(x), ypos(y){
        }
        void showPosition() const{
            cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
        }
        Point operator+(const Point &ref) const{
            return Point(xpos+ref.xpos, ypos+ref.ypos);
        }
};

Point operator-(const Point &pos1, const Point &pos2) { //why const occurs error?
    return Point(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
}

int main() {
    Point pos1(1,1);
    Point pos2(2,2);
    Point pos3 = pos1+pos2;
    pos3.showPosition();
    Point pos4 = pos2-pos1;
    pos4.showPosition();
    return 0;
}
