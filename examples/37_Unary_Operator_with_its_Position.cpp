#include <iostream>

using namespace std;

class Point{
    private:
        int xpos;
        int ypos;
    public:
        friend Point& operator--(Point &ref);
        friend const Point& operator--(Point &ref, int);
        Point(int x = 0, int y = 0) : xpos(x), ypos(y){
        }
        void showPosition() const{
            cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
        }
        Point& operator++() {
            xpos+=1;
            ypos+=1;
            return *this;
        }
        const Point operator++(int){
            const Point obj(xpos, ypos);
            xpos+=1;
            ypos+=1;
            return obj;
        }
};

Point& operator--(Point &ref) {
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}
const Point& operator--(Point &ref, int){
    const Point obj(ref);
    ref.xpos-=1;
    ref.ypos-=1;
    return obj;
}

int main() {
    Point pos1(1,1);
    Point pos2(2,2);
    
    cout<<"======pos1======"<<endl;
    pos1.showPosition();
    pos1++;
    pos1.showPosition();
    
    cout<<"======pos2======"<<endl;
    pos2.showPosition();
    pos2--;
    pos2.showPosition();
    
    //(pos1++)++; error
    //(pos2--)--; error
    ++(++pos1); // it works
    --(--pos2); // it works
    cout<<"====pos1&pos2===="<<endl;
    pos1.showPosition();
    pos2.showPosition();
    
    return 0;
}
