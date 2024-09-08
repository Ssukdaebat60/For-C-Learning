#include <iostream>

using namespace std;

class baseClass{
    private:
        int privNum;
    protected:
        int prtcNum;
    public:
        int publNum;
    public:
        baseClass() : privNum(1), prtcNum(2), publNum(3){
        }
        void showPriv(){
            cout<<privNum<<endl;
        }
};
class derivedClass : public baseClass{
    public:
        void showPrtc1(){
            cout<<prtcNum<<endl;
        }
};
class deDerivedClass : protected derivedClass{
    public:
        void showPriv2(){
            showPriv();
        }
        void showPrtc2(){
            showPrtc1();
        }
        void showPubl2(){
            cout<<publNum<<endl;
        }
};
class deDeDerivedClass : private deDerivedClass{
};

int main() {
    derivedClass D1;
    deDeDerivedClass D3;
    
    cout<<D1.publNum<<endl;
    D1.showPrtc1();
    D1.showPriv();
    //cout<<D1.prtcNum<<endl;
    //cout<<D1.privNum<<endl;
    
    deDerivedClass D2;
    D2.showPubl2();
    D2.showPrtc2();
    D2.showPriv2();
    //cout<<D2.publNum<<endl;
    //cout<<D2.prtcNum<<endl;
    //cout<<D2.privNum<<endl;
    
    //cout<<D3.publNum<<endl;
    //cout<<D3.prtcNum<<endl;
    //cout<<D3.privNum<<endl;
    return 0;
}
