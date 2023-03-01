#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){
            cout<<"Point constructor called"<<endl;
        }
        void SetPos(int x, int y){
            xpos = x;
            ypos = y;
        }
        ~Point(){
            cout<<"Point destructor called"<<endl;
        }
        friend ostream& operator<<(ostream& os, const Point & pos);
};

ostream& operator<<(ostream& os, const Point & pos){
    os<<"["<<pos.xpos<<","<<pos.ypos<<"]"<<endl;
    return os;
}


class sPtr{
    private:
        Point * ptr;
    public:
        sPtr(Point * p) : ptr(p){
            cout<<"sPtr constructor called"<<endl;
        }
        Point& operator*() const{ 
            return *ptr;
        }
        Point* operator->() const{
            return ptr;
        }
        ~sPtr(){
            cout<<"sPtr destructor called"<< endl;
            delete ptr;
        }
};

int main()
{
    sPtr p1(new Point(3,4));
    cout<<*p1;
    p1->SetPos(30, 40);
    cout<<*p1;
    return 0;
}
