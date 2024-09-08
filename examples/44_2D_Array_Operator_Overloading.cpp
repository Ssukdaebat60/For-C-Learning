#include <iostream>

using namespace std;

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray& arr){ }
        BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){ }
    public:
        BoundCheckIntArray(int len) : arrlen(len) {arr = new int[len];}
        int& operator[](int idx){
            if(idx<0||idx>=arrlen){
                cout<<"Exception : out of index"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int& operator[](int idx) const{
            if(idx<0||idx>=arrlen){
                cout<<"Exception : out of index"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const {return arrlen;}
        ~BoundCheckIntArray(){delete []arr;}
};

class BoundCheck2DArr{
    private:
        BoundCheckIntArray **arr;
        int arrlen;
        BoundCheck2DArr(const BoundCheck2DArr& arr){ }
        BoundCheck2DArr& operator=(const BoundCheck2DArr&arr){ }
    public:
        BoundCheck2DArr(int row, int col) : arrlen(row){
            arr = new BoundCheckIntArray *[row];
            for(int i=0; i<row; i++){
                arr[i] = new BoundCheckIntArray(col);
            }
        }
        BoundCheckIntArray& operator[] (int idx){
            if(idx<0||idx>arrlen){
                cout<<"Error : out of index"<<endl;
                exit(1);
            }
            return *(arr[idx]);
        }
        ~BoundCheck2DArr(){
            for(int i=0; i<arrlen; i++){
                delete arr[i];
            }
            delete []arr;
        }
};

int main() {
    BoundCheck2DArr arr(3,4);
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            arr[i][j] = i*10+j;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
