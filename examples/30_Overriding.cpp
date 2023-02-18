#include <iostream>
#include <cstring>

using namespace std;

class Employee{
    private:
        char * name;
    public:
        Employee(char * EName){
            name = new char[strlen(EName+1)];
            strcpy(name, EName);
        }
        void showName() const{
            cout<<"Name : "<<name<<endl;
        }
};
class PermanentWorker : public Employee{
    private:
        int salary;
    public:
        PermanentWorker(char * name, int money) : Employee(name), salary(money){}
        int getPay() const{
            return salary;
        }
        void showSalaryInfo() const{
            showName();
            cout<<"salary: "<<getPay()<<endl<<endl;
        }
};
class SalesWorker : public PermanentWorker{
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(char * name, int money, double bRatio) : PermanentWorker(name, money), bonusRatio(bRatio), salesResult(0){}
        void addResult(int value){
            salesResult += value;
        }
        int getPay(){
            return PermanentWorker::getPay() + (int)(salesResult*bonusRatio);
        }
        void showSalaryInfo(){
            showName();
            cout<<"salary: "<<getPay()<<endl<<endl;
        }
};
int main() {
    SalesWorker sw1("James", 10000, 0.2);
    sw1.addResult(1000);
    sw1.showSalaryInfo();
    return 0;
}
