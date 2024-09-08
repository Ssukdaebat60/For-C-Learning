#include <iostream>

using namespace std;

class Point{
    private:
        int posx;
        int posy;
    public:
        Point(int x = 0, int y = 0) : posx(x), posy(y){
        }
        void showPosition() const{
            cout<<"["<<posx<<","<<posy<<"]"<<endl;
        }
        friend ostream& operator<<(ostream& os, const Point & pos);
};

ostream& operator<<(ostream& os, const Point & pos){
    os<<"["<<pos.posx<<","<<pos.posy<<"]"<<endl;
    return os;
}

int main() {
    Point pos1(1,3);
    pos1.showPosition();
    cout<<pos1;
    return 0;
}
