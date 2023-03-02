#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string str1 = "I like ";
    string str2 = "sting class";
    char char1[20] = "I like ";
    char char2[20] = "char array";
    
    if (str1 != str2){
        cout<<"str1!=str2 : str1 and str2 are different"<<endl;
    }
    cout<<"str1+str2 : "<<str1+str2<<endl;
    str1=str2;
    cout<<"str1=str2 : "<<str1<<endl;
    cout<<endl;
    
    if (strcmp(char1, char2)){
        cout<<"strcmp(char1, char2) : char1 and char2 are different"<<endl;
    }
    cout<<"strcat(char1, char2) : "<<strcat(char1, char2)<<endl;
    strcpy(char1, char2);
    cout<<"strcpy(char1, char2) : "<<char1<<endl;
    
    return 0;
}
