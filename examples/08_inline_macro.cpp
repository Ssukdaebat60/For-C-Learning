#include <iostream>
#define SQUARE(x) ((x)*(x))

using namespace std;

inline int inSquare(int x){
    return x*x;
}

int main() {
    cout<<SQUARE(5)<<endl;
    cout<<SQUARE(3.14)<<endl;
    cout<<inSquare(5)<<endl;
    return 0;
}
