//It is designed for testing purposes only.
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int FuncOne(char * str1);
int FuncTwo(char * str2);
int FuncThree(char * str3);

int main() {
    char str1[100];
    char str2[100];
    while(1){
        cout<<"enter two even numbers"<<endl;
        cin>>str1>>str2;
        try{
            cout<<str1<<" + "<<str2<<" = "<<endl<<FuncOne(str1)+FuncOne(str2)<<endl;
            break;
        }
        catch(int expn){
            cout<<"You cannot enter a number that starts with 0"<<endl;
        }
        catch(double expn){
            cout<<"You cannot enter an odd number"<<endl;
        }
    }
    return 0;
}

int FuncOne(char * str1){
    cout<<"FuncOne() is called"<<endl;
    return FuncTwo(str1);
}
int FuncTwo(char * str2){
    cout<<"FuncTwo() is called"<<endl;
    return FuncThree(str2);
}
int FuncThree(char * str3){
    cout<<"FuncThree() is called"<<endl;
    int len=strlen(str3);
    try{
        if(len!=0 && str3[0]=='0'){
            throw 0;
        }
        for(int i=0; i<len; i++){
            if (str3[i]<'0' || str3[i]>'9'){
                throw str3[i];
            }
        }
        if(atoi(str3)%2==1){
            throw 0.5;
        }
        return atoi(str3);
    }
    catch (char expn){
        cout<<expn<<" is wrong input. exit(0)..."<<endl;
        exit(0);
    }
}
