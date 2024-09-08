#include <iostream>
#include <cstring>

using namespace std;

class deepPerson{
    private:
        char * name;
        int age;
    public:
        deepPerson(char * myname, int myage) : age(myage) {
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        explicit deepPerson(deepPerson &copy) : age(copy.age) {
            name = new char[strlen(copy.name)+1];
            strcpy(name, copy.name);
        }
        void showPersonInfo(){
            cout<<name<<endl<<age<<endl;
        }
        ~deepPerson(){
            delete []name;
            cout<<"called destructor"<<endl;
        }
};

int main() {
    deepPerson P1("James", 25);
    P1.showPersonInfo();
    deepPerson P2(P1);
    P2.showPersonInfo();
    return 0;
}
