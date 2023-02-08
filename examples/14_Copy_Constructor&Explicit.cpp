#include <iostream>
#include <typeinfo>

using namespace std;

class copyClass{
    private:
        int num1;
        int num2;
    public:
        copyClass(int num1, int num2) : num1(num1), num2(num2) {}
        
        explicit copyClass(copyClass &copy) : num1(copy.num1), num2(copy.num2) {}
        
        void showNum() {cout<<typeid(this).name()<<endl<<num1<<endl<<num2<<endl;}
};

int main() {
    copyClass copy1(1,1);
    copy1.showNum();
    //copyClass copy2 = copy1; -> Error because of "explicit"
    copyClass copy2(copy1);
    copy2.showNum();
    return 0;
}
