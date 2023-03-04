#include <iostream>

using namespace std;

template <typename T>
class SimpleStatic{
    private:
        static T mem;
    public:
        void add(T num){
            mem+=num;
        }
        T getMem() const{
            return mem;
        }
};

template <typename T>
T SimpleStatic<T>::mem = 1;
template <>
double SimpleStatic<double>::mem=-1;

int main() {
    SimpleStatic<int> s1;
    SimpleStatic<int> s2;
    s1.add(3);
    s2.add(3);
    cout<<s2.getMem()<<endl;
    
    SimpleStatic<double> s3;
    SimpleStatic<double> s4;
    s3.add(100.9);
    cout<<s4.getMem()<<endl;
    
    return 0;
}
