#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0) : xpos(x), ypos(y){
        }
        void showPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
            cout<<"Point<T>"<<endl;
        }
        template <typename T1>
        friend Point<T1> operator*(const Point<T1>& pos1, int num1);
};
template <>
class Point<char*>{
    private:
        char * xpos = new char;
        char * ypos = new char;
    public:
        Point(const char * x = "x", const char * y ="y") {
            strcpy(xpos, x);
            strcpy(ypos, y);
        }
        void showPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
            cout<<"Point<char*>"<<endl;
        }
        friend Point<char*> operator*(Point<char*>& pos1, int num1);
};

template <typename T>
Point<T> operator*(const Point<T>& pos1, int num1){
    return Point<T>(pos1.xpos*num1, pos1.ypos*num1);
}
Point<char*> operator*(Point<char*>& pos1, int num1){
    if (num1<=0){
        return pos1;
    }
    Point<char*> temp;
    strcpy(temp.xpos, pos1.xpos);
    strcpy(temp.ypos, pos1.ypos);
    for(int i = 1; i<num1; i++){
        strcat(temp.xpos, pos1.xpos);
        strcat(temp.ypos, pos1.ypos); 
    }
    return temp;
}
template <typename T>
T multiple(T t1, int num1){
    return t1*num1;
}

int main() {
    Point<int> pos1(3,4);
    multiple(pos1, 2).showPosition();
    
    Point<double> pos2(3.14, 4.14);
    multiple(pos2, 2).showPosition();
    
    Point<char*> pos3("A", "B");
    multiple(pos3, 2).showPosition();
    
    Point<char*> pos4;
    multiple(pos4, 5).showPosition();
    
    return 0;
}
