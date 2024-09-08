#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <typename T>
T add(T num1, T num2) {
    cout<<"T add()"<<endl;
    return num1+num2;
}
template <>
const char* add(const char* a, const char* b){
    cout<<"const char * add()"<<endl<<"_specialization_"<<endl;
    string c = string(a) + string(b);
    return c.c_str();
}
int add(int num1, int num2) {
    cout<<"int add()"<<endl;
    return num1+num2;
}
double add(double num1, double num2){
    cout<<"double add()"<<endl;
    return num1+num2;
}
template <typename D1, typename D2>
void showData(D1 d1, D2 d2){
    cout<<"("<<d1<<", "<<d2<<")  ";
}

int main() {
    showData(1,1);
    cout<<add(1, 1)<<endl;
    
    showData(1.1, 1.5);
    cout<<add(1.1, 1.5)<<endl;
    
    showData(1.5,1);
    cout<<add<int>(1.5, 1)<<endl;
    
    showData(1.5,1.0);
    cout<<add<double>(1.5, 1.0)<<endl;
    
    showData("hello ", "world!");
    cout<<add("hello ", "world!")<<endl; // add<const char *>(_, _);
    
    return 0;
}
