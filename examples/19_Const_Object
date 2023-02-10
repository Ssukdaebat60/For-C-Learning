#include <iostream>

using namespace std;

class constObj{
    private:
        int num;
    public:
        constObj(int n) : num(n){
        }
        void showInfo(){
            cout<<"Normal Obj -- "<<num<<endl;
        }
        void showInfo() const{
            cout<<"Const Obj -- "<<num<<endl;
        }
};

int main() {
    constObj obj1(5);
    const constObj obj2(10);
    
    obj1.showInfo();
    obj2.showInfo();
    
    return 0;
}
