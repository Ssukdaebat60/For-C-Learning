#include <iostream>
#include <cstring>

using namespace std;

class Person{
    private:
        char * name;
        int age;
    public:
        Person(char * myname, int myage){
            int len = strlen(myname);
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        void showPersonInfo() const{
            cout<<endl;
            cout<<name<<endl;
            cout<<age<<endl;
            cout<<endl;
        }
        ~Person(){
            delete []name;
            cout<<"called destructor"<<endl;
        }
};

int main() {
    Person P("James", 25);
    P.showPersonInfo();
    return 0;
}
