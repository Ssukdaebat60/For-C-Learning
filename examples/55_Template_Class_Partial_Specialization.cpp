#include <iostream>

using namespace std;

template <typename T1, typename T2>
class MySimple{
    public:
        void showData() const{
            cout<<"size of T1 : "<<sizeof(T1)<<endl;
            cout<<"size of T2 : "<<sizeof(T2)<<endl;
            cout<<"<typename T1, typename T2>"<<endl<<endl;
        }
};
template<typename T1>
class MySimple<T1, double>{
    public:
        void showData() const{
            cout<<"size of T1 : "<<sizeof(T1)<<endl;
            cout<<"size of double : "<<sizeof(double)<<endl;
            cout<<"<typename T1, typename double>"<<endl<<endl;
        }
};
template<>
class MySimple<int, double>{
    public:
        void showData() const{
            cout<<"size of int : "<<sizeof(int)<<endl;
            cout<<"size of double : "<<sizeof(double)<<endl;
            cout<<"<typename int, typename double>"<<endl<<endl;
        }
};

int main() {
    MySimple<char, int>().showData();
    MySimple<char, double>().showData();
    MySimple<int, double>().showData();
    
    return 0;
}
