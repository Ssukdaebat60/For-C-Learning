#include <iostream>

using namespace std;

class First{
    private:
        int num1, num2;
    public:
        First(int n1=0, int n2=0) : num1(n1), num2(n2){
        }
        void showData(){
            cout<<num1<<", "<<num2<<endl;
        }
        First& operator=(const First& ref){
            cout<<"First& operator=()"<<endl;
            num1 = ref.num1;
            num2 = ref.num2;
            return *this;
        }
};

class Second : public First{
    private:
        int num3, num4;
    public:
        Second(int n1=0, int n2=0, int n3=0, int n4=0) : First(n1, n2), num3(n3), num4(n4){
        }
        void showData(){
            First::showData();
            cout<<num3<<", "<<num4<<endl;
        }
        Second& operator=(const Second& ref){
            First::operator=(ref); // without line 34, the 'operator=' of its base class is not called it needs to be defined explicitly
            cout<<"Second& operator=()"<<endl;
            num3=ref.num3;
            num4=ref.num4;
            return *this;
        }
};

int main() {
    Second S1(1,2,3,4);
    Second S2(0,0,0,0);
    S2 = S1;
    S2.showData();
    return 0;
}
