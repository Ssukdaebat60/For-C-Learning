#include <iostream>
#include <new>

using namespace std;

void divide(int num1, int num2){
    try{
        if(num2==0){
            throw 0;
        }
        cout<<num1/num2<<endl;
    }
    catch(...){
        cout<<"divide() : Error Occurs!"<<endl;
        throw;
    }
}

int main() {
    try{
        divide(4, 2);
        divide(1, 0);
    }
    catch(...){
        cout<<"main() : Error Occurs!"<<endl;
    }
    return 0;
}
