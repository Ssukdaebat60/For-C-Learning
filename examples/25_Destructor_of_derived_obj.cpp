#include <iostream>
#include <cstring>

using namespace std;

class Person{
    private:
        char * name;
    public:
        Person(char * myname){
            cout<<"Person()"<<endl;
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        void showPersonInfo() const{
            cout<<"Name is "<<name<<endl;
        }
        ~Person(){
            cout<<"~Person()"<<endl;
            delete []name;
        }
};
class Student : public Person{
    private:
        char * major;
    public:
        Student(char * myname, char * mymajor) : Person(myname){
            cout<<"Student()"<<endl;
            major = new char[strlen(mymajor)];
            strcpy(major, mymajor);
        }
        ~Student(){
            cout<<"~Student()"<<endl;
            delete []major;
        }
        void showStudentInfo() const{
            showPersonInfo();
            cout<<"Major is "<<major<<endl;
        }
};

int main() {
    Student S1("James", "Computer Eng.");
    S1.showStudentInfo();
    
    return 0;
}
