#include <iostream>

int numInt = 3;
float numFloat = 3.14;

using namespace std;

namespace AAA{
    namespace BBB{
        namespace CCC{
            int sum(int n){
                int numInt = n;
                return numInt + ::numInt;
            }
            double sum(double n){
                float numFloat = n;
                return numFloat + ::numFloat;
            }
        }
    }
}

int main() {
    namespace ABC = AAA::BBB::CCC;
    cout<<ABC::sum(3)<<endl;
    cout<<ABC::sum(3.14);
}
