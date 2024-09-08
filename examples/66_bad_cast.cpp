#include <iostream>

using namespace std;

class base_Class{
    public:
        virtual void showInfo(){
            cout<<"This is base_Class"<<endl;
        }
};
class derived_Class : public base_Class{
    public:
        void showInfo(){
            cout<<"This is derived_Class"<<endl;
        }
};

int main() {
    base_Class bClass;
    base_Class& ref = bClass;
    
    try{
        derived_Class& dClass = dynamic_cast<derived_Class&>(ref);
        dClass.showInfo();
    }
    catch(bad_cast expn){
        cout<<expn.what()<<endl;
    }
    return 0;
}
