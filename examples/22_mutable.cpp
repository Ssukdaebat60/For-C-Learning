#include <iostream>

using namespace std;

class mutClass{
    private:
        int num1;
        mutable int num2;
    public:
        mutClass(int n1, int n2) : num1(n1), num2(n2){
        }
        void showInfo() const{
            cout<<"num1 = "<<num1<<endl;
            cout<<"num2 = "<<num2<<endl<<endl;
        }
        void copyNum2() const{
            num2 = num1;
        }
};

int main() {
    mutClass obj(1, 2);
    obj.showInfo();
    obj.copyNum2();
    obj.showInfo();
    return 0;
}
