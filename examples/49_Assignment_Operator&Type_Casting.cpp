#include <iostream>

using namespace std;

class Number{
    private:
        int num;
    public:
        Number(int n =0) : num(n){
            cout<<"Number(int n=0)"<<endl;
        }
        Number& operator=(const Number& ref){
            cout<<"operator=()"<<endl;
            num=ref.num;
            return *this;
        }
        operator int (){
            return num;
        }
        void showNum(){
            cout<<num<<endl;
        }
};

int main() {
    Number n1;
    n1=30;
    Number n2 = n1+20;
    n2.showNum();
    return 0;
}
