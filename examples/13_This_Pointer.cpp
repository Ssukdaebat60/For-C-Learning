#include <iostream>
#include <typeinfo>

using namespace std;

class thisClass{
    private:
        int num;
    public:
        thisClass(int num){
            this->num = num;
        }
        thisClass & showThis(){
            cout<<num<<endl;
            cout<<this<<endl;
            return * this;
        }
        thisClass & adder(int num){
            this->num += num;
            return * this;
        }
};

int main() {
    thisClass ThisA(5);
    ThisA.showThis().adder(5).showThis();
    return 0;
}
