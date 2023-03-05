#include <iostream>
#include <cstring>

using namespace std;

class AccountException{
    public:
        virtual void ShowException() = 0;
};
class DepositException : public AccountException{
    private:
        int reqDep;
    public:
        DepositException(int money) : reqDep(money){
        }
        void ShowException(){
            cout<<"Error : "<<reqDep<<" can not be deposited"<<endl;
        }
};
class WithdrawException : public AccountException{
    private:
        int balance;
    public:
        WithdrawException(int money) : balance(money){
        }
        void ShowException(){
            cout<<"Error : "<<balance<<" not enough money"<<endl;
        }
};
class Account{
    private:
        char accNum[50];
        int balance;
    public:
        Account(const char * acc, int money) : balance(money){
            strcpy(accNum, acc);
        }
        void Deposit(int money){
            if (money<0){
                throw DepositException(money);
            }
            balance+=money;
        }
        void Withdraw(int money){
            if (money>balance){
                throw WithdrawException(balance);
            }
            balance -= money;
        }
        void showMoney(){
            cout<<"Balance : "<<balance<<endl<<endl;
        }
};

int main() {
    Account myAcc("2001-761583", 500);
    try{
        myAcc.Deposit(500);
        myAcc.Deposit(-300);
    }
    catch (AccountException &expn){
        expn.ShowException();
    }
    myAcc.showMoney();
    try{
        myAcc.Withdraw(600);
        myAcc.Withdraw(600);
    }
    catch (AccountException &expn){
        expn.ShowException();
    }
    myAcc.showMoney();
    return 0;
}
