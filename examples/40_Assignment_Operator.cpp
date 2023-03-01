#include <iostream>
#include <cstring>

using namespace std;

class Person{
    private:
        char* name;
        int age;
    public:
        Person(char* myname, int myage) : age(myage){
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
            age = myage;
        }
        void showPersonInfo() const{
            cout<<"Name : "<<name<<" Age : "<<age<<endl;
        }
        Person& operator=(const Person& ref){
            delete []name;
            name = new char[strlen(ref.name)+1];
            strcpy(name, ref.name);
            age = ref.age;
            return *this; // why return??
        }
        ~Person(){
            delete []name;
            cout<<"called destructor"<<endl;
        }
};

int main() {
    Person p1("James", 20);
    Person p2("Sara", 22);
    p2 = p1;
    p1.showPersonInfo();
    p2.showPersonInfo();
    return 0;
}
