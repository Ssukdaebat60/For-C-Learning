#include <iostream>
#include <new>

using namespace std;

void newhandler()
{
	cout << "This memory allocation code can't execute!" << endl;
	throw bad_alloc();
	return;
}

int main() {
    int num=0;
    new_handler handler = set_new_handler(newhandler);
    try{
        while(1){
            num++;
            cout<<num<<"time(s) trying"<<endl;
            new int[1000000000000000];
        }
    }
    catch(bad_alloc &bad){
        cout<<bad.what()<<endl;
        cout<<"no more allocation"<<endl;
    }
    
    set_new_handler(handler);
    cout<<"end of main"<<endl;
    return 0;
}
