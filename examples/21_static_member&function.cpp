#include <iostream>
#include <cstring>

using namespace std;

class stcMemb{
    private:
    public:
        static int objCnt;
        static void showInfo(){
            cout<<++objCnt<<" stcMem classes are declared"<<endl;
        }
};
int stcMemb::objCnt=0;

int main() {
    cout<<stcMemb::objCnt<<" stcMem classes are declared"<<endl; // if a static member is private -> error
    stcMemb class1;
    class1.showInfo();
    stcMemb class2;
    class2.showInfo();
    stcMemb class3;
    class3.showInfo();
    stcMemb class4;
    class4.showInfo();
    return 0;
}
