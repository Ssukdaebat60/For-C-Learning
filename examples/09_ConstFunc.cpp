#include <iostream>

using namespace std;

class ExClass{
    int num;
    public:
        void setNum(int n){
            num = n;
        }
        int getNum() const{
            return num;
        }
        void showNum() const{
            cout<<getNum()<<endl;
        }
};

class OtherClass{
    int num;
    public:
        int getNum(const ExClass &ex){
            num = ex.getNum();
            return num;
        }
};


int main() {
    ExClass exA;
    exA.setNum(1);
    exA.showNum();
    OtherClass exB;
    cout<<exB.getNum(exA);
    return 0;
}
