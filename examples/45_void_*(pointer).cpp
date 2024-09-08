#include <iostream>
#include <typeinfo>

using namespace std;
 
int main()
{
    int a = 10;
    char b = 'x';
     
    void* p = &a; //A pointer type that does not specify the type of object when declaring
    cout<<p<<" "<<typeid(p).name()<<" "<<*(int *)p<<endl;
    
    p = &b;
    cout<<p<<" "<<typeid(p).name()<<" "<<*(char *)p<<endl;
    
    return 0;
}
