#include <iostream>

using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0);
        void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y){}

template <typename T>
void Point<T>::ShowPosition() const{
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
}

int main() {
    Point<int> P1(1,1); // it must be clear about template type definition
    P1.ShowPosition();
    Point<double> P2(1.4, 1.5);
    P2.ShowPosition();
    Point<char> P3('X', 'Y');
    P3.ShowPosition();
    return 0;
}
