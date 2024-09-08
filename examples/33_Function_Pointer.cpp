#include <iostream>

using namespace std;

void printNum(int num, void (*changeNum)(int *) = NULL){
    if (changeNum != NULL){
        (*changeNum)(&num);
    }
    cout<<num<<endl;
}

void add(int *num){
    *num += 1;
}

void sub(int *num){
    *num -= 1;
}

int main() {
    printNum(5);
    printNum(5, add);
    printNum(5, sub);
    return 0;
}
