#include <iostream>
#include <cstring>

using namespace std;

class Employee{
    private:
        char * name;
    protected:
        Employee(char * EName){
            name = new char[strlen(EName+1)];
            strcpy(name, EName);
        }
    public:
        virtual void showName() const{
            cout<<"Name : "<<name<<endl;
        }
        virtual int getPay() const = 0;
        virtual void showSalaryInfo() const = 0;
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
        int getPay() const{
            return PermanentWorker::getPay() + (int)(salesResult*bonusRatio);
        }
        void showSalaryInfo() const{
            showName();
            cout<<"salary: "<<getPay()<<endl<<endl;
        }
};
class EmployeeController{
    private:
        Employee * empList[50];
        int empNum;
    public:
        EmployeeController() : empNum(0){}
        void addEmployee(Employee * emp){
            empList[empNum] = emp;
            empNum += 1;
        }
        void showAllSalaryInfo() const{
            for(int i=0; i<empNum; i++){
                empList[i]->showSalaryInfo();
            }
        }
};
int main() {
    EmployeeController controller;
    
    controller.addEmployee(new PermanentWorker("Jamees", 1000));
    controller.addEmployee(new PermanentWorker("Sally",  800));
    
    SalesWorker * sales = new SalesWorker("Janet", 1000, 0.2);
    sales->addResult(1000);
    controller.addEmployee(sales);
    
    controller.showAllSalaryInfo();
    return 0;
}
