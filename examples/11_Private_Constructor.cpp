#include <iostream>
#include <typeinfo>

using namespace std;

class AAA{
    private:
        int num;
    public:
        AAA() : num(0) {}
        AAA & CreateObjPtr(int n){
            AAA * ptr = new AAA(n);
            return *ptr;
        }
        AAA CreateObjJust(int n){
            AAA just = AAA(n);
            return just;
        }
        void showNum() const {
            cout<<num<<endl;
        }
    private:
        AAA(int n) : num(n) {}
};

int main() {
    AAA A;
    A.showNum();
    AAA obj1 = A.CreateObjPtr(2);
    obj1.showNum();
    AAA obj2 = A.CreateObjJust(5);
    obj2.showNum();
    AAA &obj3 = A.CreateObjPtr(10);
    obj3.showNum();
    
    cout<<endl;
    cout<<typeid(A).name()<<endl;
    cout<<typeid(obj1).name()<<endl;
    cout<<typeid(obj2).name()<<endl;
    cout<<typeid(obj3).name()<<endl;
    
    return 0;
}
