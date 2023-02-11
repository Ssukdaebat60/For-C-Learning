#include <iostream>
#include <cstring>

using namespace std;

class stcMemb{
    private:
        static int objCnt;
    public:
        stcMemb(){
            cout<<++objCnt<<" stcMem classes are declared"<<endl;
        }
};
int stcMemb::objCnt=0;

int main() {
    stcMemb class1;
    stcMemb class2;
    stcMemb class3;
    stcMemb class4;
    return 0;
}
