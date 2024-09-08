#include <iostream>
#include <stdio.h>

using namespace std;

class AAA{
    public:
        virtual void Func1() {cout<<"Func1"<<endl;}
        virtual void Func2() {cout<<"Func2"<<endl;}
};
class BBB: public AAA{
    public:
        virtual void Func1() {cout<<"BBB::Func1"<<endl;}
        void Func3() {cout<<"Func3"<<endl;}
};

int main() {
    AAA * A = new AAA();
    BBB * B = new BBB();
    A->Func1();
    printf("%p\n\n", &AAA::Func1);
    A->Func2();
    printf("%p\n\n", &AAA::Func2);
    B->Func1();
    printf("%p\n\n", &BBB::Func1);
    B->Func2();
    printf("%p\n\n", &BBB::Func2);  
    B->Func3();
    printf("%p\n\n", &BBB::Func3);
    return 0;
}
