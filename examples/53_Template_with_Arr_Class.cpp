#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        friend ostream& operator<<(ostream& os, const Point& pos);
        friend ostream& operator<<(ostream& os, const Point * pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
ostream& operator<<(ostream& os, const Point* pos){
    os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
    return os;
}

template <typename T>
class BoundCheckArray{
    private:
        T * arr;
        int arrlen;
        BoundCheckArray(const BoundCheckArray& arr){ }
        BoundCheckArray& operator=(const BoundCheckArray& arr){ }
    public:
        BoundCheckArray(int len) : arrlen(len) {arr = new T[len];}
        T& operator[](int idx){
            if(idx<0||idx>=arrlen){
                cout<<"Exception : out of index"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        T& operator[](int idx) const{
            if(idx<0||idx>=arrlen){
                cout<<"Exception : out of index"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const {return arrlen;}
        ~BoundCheckArray(){delete []arr;}
};

template <typename T>
void showAllData(const BoundCheckArray<T>& ref){
    int len=ref.GetArrLen();
    for(int idx=0; idx<len; idx++)
        cout<<ref[idx]<<endl;
}

int main() {
    BoundCheckArray<int> arr1(5);
    for (int i=0; i<5; i++)
        arr1[i] = (i+1);
    showAllData(arr1);
    
    BoundCheckArray<Point> arr2(5);
    for (int i=0; i<5; i++)
        arr2[i] = Point(i, i+1);
    showAllData(arr2);
    
    typedef Point * POINT_PTR;
    
    BoundCheckArray<POINT_PTR> arr3(5);
    for (int i=0; i<5; i++)
        arr3[i] = new Point(i, i+1);
    showAllData(arr3);
    
    return 0;
}
