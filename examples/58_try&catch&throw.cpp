#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    cout<<"enter two numbers : ";
    cin>>num1>>num2;
    try{
        if(num2==0){
            throw num2;
        }
        cout<<"division result : "<<num1/num2<<endl;
        cout<<"division rest : "<<num1%num2<<endl;
    }
    catch(int expn){
        cout<<"error : zero division"<<endl;
    }
    cout<<"end of main"<<endl;
    return 0;
}
