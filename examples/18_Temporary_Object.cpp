
#include <iostream>

using namespace std;

class tmpObj{
    private:
    public:
        tmpObj(){
            cout<<"tmpObj is constructed"<<endl;
            cout<<"New Object : "<<this<<endl;
        }
        tmpObj(const tmpObj &copy){
            cout<<"New Copy obj : "<<this<<endl;
        }
        ~tmpObj(){
            cout<<"Destroy obj : "<<this<<endl;
        }
        void showInfo(){
            cout<<"showInfo : "<<this<<endl;
        }
};

tmpObj tmpFunc(tmpObj ob){
    cout<<"Parm ADR : "<<&ob<<endl;
    return ob;
}

int main() {
    tmpObj();
    cout<<endl;
    
    tmpObj().showInfo();
    cout<<endl;
    
    tmpObj obj;
    tmpFunc(obj);
    cout<<endl;
    
    tmpObj tmpRef = tmpFunc(obj);
    cout<<"Retrun Obj : "<<&tmpRef<<endl<<endl;
    
    cout<<"====end of main===="<<endl;
    return 0;
}
