#include <iostream>

using namespace std;

class tmpObj{
    private:
    public:
        tmpObj(){
        }
        tmpObj(const tmpObj &copy) {
            cout<<"copy constructor is called"<<endl;
        }
        tmpObj reVal(tmpObj ob){
            cout<<"reVal_return : ";
            return ob;
        }
        tmpObj* reRef(tmpObj ob){
            cout<<"reRef_return : ";
            return &ob;
        }
        void showInfo(){
            cout<<this<<endl;
        }
};

int main() {
    tmpObj A;
    tmpObj B(A);
    A.showInfo();
    B.showInfo();
    cout<<endl;
    A.reVal(B); // Temporary_Object
    A.reRef(B);
    return 0;
}
