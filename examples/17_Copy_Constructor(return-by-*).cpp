#include <iostream>

using namespace std;

class reThis{
    private:
    public:
        reThis(){
        }
        reThis(const reThis &copy) {
            cout<<"copy constructor is called"<<endl;
        }
        reThis reVal(reThis ob){
            cout<<"reVal_return : ";
            return ob;
        }
        reThis* reRef(reThis ob){
            cout<<"reRef_return : ";
            return &ob;
        }
        void showInfo(){
            cout<<this<<endl;
        }
};

int main() {
    reThis A;
    reThis B(A);
    A.showInfo();
    B.showInfo();
    cout<<endl;
    A.reVal(B); // Temporary_Object
    A.reRef(B);
    return 0;
}
