#include <iostream>
#include <cstring>

using namespace std;

class frndClass;
class superClass1;
class superClass2{
    public:
        superClass2 adder(frndClass &frn);
        void showInfo(const frndClass &frn);
};

void showFrndInfo(const frndClass &frn);

class frndClass{
    private:
        char * name;
        int age;
        friend class superClass1;
        friend void superClass2::showInfo(const frndClass&);
        friend superClass2 superClass2::adder(frndClass&);
        friend void showFrndInfo(const frndClass&);
    public:
        frndClass(const char * myname, int myage) : age(myage) {
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        ~frndClass(){
            delete []name;
        }
};

class superClass1{
    public:
        void showInfo(const frndClass &frn){
            cout<<"superClass1"<<endl;
            cout<<"name : "<<frn.name<<" age : "<<frn.age<<endl<<endl;
        }
};

superClass2 superClass2::adder(frndClass &frn){
    cout<<"add "<<frn.name<<"'s age"<<endl<<endl;
    frn.age += 1;
    return *this;
}
void superClass2::showInfo(const frndClass &frn){
    cout<<"superClass2"<<endl;
    cout<<"name : "<<frn.name<<" age : "<<frn.age<<endl<<endl;
}


void showFrndInfo(const frndClass &frn){
    cout<<"Func_with_Frnd"<<endl;
    cout<<"name : "<<frn.name<<" age : "<<frn.age<<endl<<endl;
}

int main() {
   
   frndClass frnd("James", 25);
   superClass1 sC1;
   superClass2 sC2;
   sC1.showInfo(frnd);
   sC2.adder(frnd).showInfo(frnd);
   showFrndInfo(frnd);
   
    return 0;
}
