#include <iostream>
#include <cstring>

using namespace std;

int checkNum(char * str){
    int len=strlen(str);
    for(int i=0; i<len; i++){
        if (str[i]<'0' || str[i]>'9'){
            throw str[i];
        }
    }
    return atoi(str);
}

int main() {
    char str1[100];
    char str2[100];
    
    while(1){
        cout<<"enter two numbers : ";
        cin>>str1>>str2;
        try{
            cout<<"Sum : "<<checkNum(str1)+checkNum(str2)<<endl;
            break;
        }
        catch(char expn){
            cout<<expn<<" is wrong input. try again, please."<<endl;
        }
    }
    cout<<"end of main"<<endl;
    return 0;
}
