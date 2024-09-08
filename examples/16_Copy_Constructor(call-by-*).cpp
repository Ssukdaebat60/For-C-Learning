#include <iostream>

using namespace std;

class callThis{
    private:
        int num;
        callThis * adr;
    public:
        callThis(int n){
            num = n;
            adr = this;
        }
        callThis(const callThis &copy) : num(copy.num), adr(copy.adr){
            cout<<"called Copy Constructor"<<endl<<endl;
        }
        void showInfo(){
            cout<<num<<endl;
            cout<<"Original adr : "<<adr<<endl;
        }
        callThis * getThis(){
            return this;
        }
};

void callByVal(callThis ob){
    cout<<"obj-by-value : ";
    ob.showInfo();
    cout<<"this adr : "<<ob.getThis()<<endl;
}

void callByRef(callThis * ob){
    cout<<"obj-by-reference : ";
    ob->showInfo();
    cout<<"this adr : "<<ob->getThis()<<endl;
}

int main() {
    callThis obj(5);
    cout<<"obj : ";
    obj.showInfo();
    cout<<endl;
    callByVal(obj);
    callByRef(&obj);

    return 0;
}
