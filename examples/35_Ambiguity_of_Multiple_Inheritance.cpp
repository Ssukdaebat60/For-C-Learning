#include <iostream>

using namespace std;

class Base{
    public:
        Base() {cout<<"Base Constructor"<<endl;}
        void SimpleFunc() {cout<<"BaseOne"<<endl;}
};
class MiddleDerivedOne : virtual public Base{
    public:
        MiddleDerivedOne() : Base(){
            cout<<"MiddleDerivedOne Constructor"<<endl;
        }
        void MiddleFuncOne(){
            cout<<"MiddleDerivedOne"<<endl;
        }
        void Middle(){
            cout<<"One::Middle"<<endl;
        }
};
class MiddleDerivedTwo : virtual public Base{
    public:
        MiddleDerivedTwo() : Base(){
            cout<<"MiddleDerivedTwo Constructor"<<endl;
        }
        void MiddleFuncTwo(){
            cout<<"MiddleDerivedTwo"<<endl;
        }
        void Middle(){
            cout<<"Two::Middle"<<endl;
        }
};
class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{
    public:
        LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo(){
            cout<<"LastDerived Constructor"<<endl;
        }
        void ComplexFunc(){
            SimpleFunc();
            MiddleFuncOne();
            MiddleDerivedOne::Middle();
            MiddleFuncTwo();
            MiddleDerivedTwo::Middle();
        }
};

int main() {
    LastDerived ldr;
    cout<<"========="<<endl;
    ldr.ComplexFunc();
    return 0;
}
