#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){ }
        void * operator new (size_t size){ //keyword 'new' can be only overloaded in the following form
            cout<<"operator new : "<<size<<endl;
            void * adr = new char [size];
            return adr;
        }
        void operator delete (void * adr){
            cout<<"operator delete()"<<endl;
            delete []adr;
        }
        void showData() const{
            cout<<xpos<<", "<<ypos<<endl;
        }
};

int main() {
    Point * ptr = new Point(3, 4);
    ptr->showData();
    delete ptr;
    return 0;
}
