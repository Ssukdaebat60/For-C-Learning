#include <iostream>

using namespace std;

class Person{
    public:
        void sleep(){
            cout<<"sleep Zzz.."<<endl;
        }
        void Func(){
            cout<<"Person Func"<<endl;
        }
};
class Student : public Person{
    public:
        void study(){
            cout<<"study !!!"<<endl;
        }
        void Func(){
            cout<<"Student Func"<<endl;
        }
};
class PartTimeStudent : public Student{
    public:
        void work(){
            cout<<"work ;;;"<<endl;
        }
        void Func(){
            cout<<"PartTimeStudent Func"<<endl;
        }
};

int main() {
    Person *pers1 = new Student();
    Person *pers2 = new PartTimeStudent();
    Student *stnt1 = new PartTimeStudent();
    Person *pers3 = stnt1;
    PartTimeStudent ptst1;
    Person & pers4 = ptst1;
    //Student *stnt2 = pers1;

    pers1->sleep();
    //pers1->study();
    pers1->Func();
    cout<<endl;
    
    pers2->sleep();
    //pers2->work();
    pers2->Func();
    cout<<endl;
    
    stnt1->sleep();
    stnt1->study();
    //stnt1->work();
    stnt1->Func();
    cout<<endl;
    
    pers3->sleep();
    //pers3->study();
    pers3->Func();
    cout<<endl;
    
    ptst1.sleep();
    ptst1.study();
    ptst1.work();
    ptst1.Func();
    
    pers4.sleep();
    //pers4.study();
    //pers4.work();
    pers4.Func();
    cout<<endl;
    
    delete pers1; delete pers2; delete stnt1; //delete pers3 -> Error

    return 0;
}
