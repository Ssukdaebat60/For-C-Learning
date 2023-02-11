#include <iostream>
#include <cstring>

using namespace std;

class stcMemb{
    private:
    public:
        static int objCnt;
        stcMemb(){
            cout<<++objCnt<<" stcMem classes are declared"<<endl;
        }
};
int stcMemb::objCnt=0;

int main() {
    cout<<stcMemb::objCnt<<" stcMem classes are declared"<<endl; // if a static member is private -> error
    stcMemb class1;
    stcMemb class2;
    stcMemb class3;
    stcMemb class4;
    return 0;
}
