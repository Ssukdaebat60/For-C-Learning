#include <iostream>
#include <cstring>

using namespace std;

class boss{
    private:
        int workerNum;
        char * name;
    public:
        boss(const char * bName) : workerNum(0){
            name = new char[strlen(bName)+1];
            strcpy(name, bName);
        }
        void setWorkerNum(int n){
            workerNum = n;
        }
        int getWorkerNum() const{
            return workerNum;
        }
        char* getName() const{
            return name;
        }
        void showBossInfo() const{
            cout<<"======Boss====="<<endl;
            cout<<"the number of workers : "<<workerNum<<endl<<endl;
        }
};
class worker{
    private:
        char * name;
        char * boss;
    public:
        worker(const char * wName) {
            name = new char[strlen(wName)+1];
            strcpy(name, wName);
        }
        void setBoss(const char * bName){
            boss = new char[strlen(bName)+1];
            strcpy(boss, bName);
        }
        const char * getBoss() const{
            if (boss){
                return boss;
            }
            else
                return "None";
        }
        char* getName() const{
            return name;
        }
        void showWorkerInfo() const{
            cout<<"=====Worker====="<<endl;
            cout<<"Boss : "<<worker::getBoss()<<endl<<endl;
        }
};
class Controller{
    private:
    public:
        void hire(boss &B, worker &W){
            B.setWorkerNum(B.getWorkerNum()+1);
            W.setBoss(B.getName());
            cout<<B.getName()<<" hired "<<W.getName()<<endl;
        }
};
int main() {
    boss B1("James");
    worker W1("Tom");
    worker W2("Jessica");
    worker W3("Sally");
    Controller C1;
    
    C1.hire(B1, W1);
    C1.hire(B1, W2);
    
    cout<<endl;
    B1.showBossInfo();
    W1.showWorkerInfo();
    W2.showWorkerInfo();
    W3.showWorkerInfo();
    
    return 0;
}
