#include <iostream>

using namespace std;

class Sum{
    private:
        int int1;
        int int2;
        double dou1;
        double dou2;
    
    public:
        Sum(int n1, int n2 = 0) : int1(n1), int2(n2) {
            cout<<int1+int2<<endl;
        }
        Sum(double n1, double n2 = 0) : dou1(n1), dou2(n2) {
            cout<<dou1+dou2<<endl;
        }
};

int main() {
    
    Sum(1,1);
    Sum(3.14, 3.14);
    Sum(3.14);
    return 0;
}
