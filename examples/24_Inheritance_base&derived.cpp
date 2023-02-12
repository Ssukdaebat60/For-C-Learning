#include <iostream>

using namespace std;

class baseClass{
    private:
        int num;
    public:
        baseClass() : num(20){
            cout<<"baseClass()"<<endl;
        }
        baseClass(int n) : num(n){
            cout<<"baseClass(int n)"<<endl;
        }
        void showBaseInfo(){
            cout<<num<<endl;
        }
};
class derivedClass : public baseClass {
    private:
        int num;
    public:
        derivedClass() : num(30){
            cout<<"derivedClass()"<<endl;
        }
        derivedClass(int n1) : num(n1){
            cout<<"derivedClass(int n1)"<<endl;
        }
        derivedClass(int n1, int n2) : baseClass(n1), num(n2) {
            cout<<"derivedClass(int n1, int n2)"<<endl;
        }
        void showDerivedInfo(){
            showBaseInfo();
            cout<<num<<endl;
        }
};

int main() {
    
    derivedClass dr1;
    dr1.showDerivedInfo();
    cout<<endl;
    
    derivedClass dr2(12);
    dr2.showDerivedInfo();
    cout<<endl;
    
    derivedClass dr3(23, 24);
    dr3.showDerivedInfo();
    cout<<endl;
    
    derivedClass().showDerivedInfo();
    
    return 0;
}
