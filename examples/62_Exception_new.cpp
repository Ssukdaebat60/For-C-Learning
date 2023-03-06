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
    long size = 100000000000000;
    new_handler handler = set_new_handler(newhandler);
    while(1){
        try{
            num++;
            cout<<num<<"time(s) trying"<<endl;
            new int[size];
            cout<<"___memory allocation successfull___"<<endl;
            break;
        }
        catch(bad_alloc &bad){
            size -= 1000000000000;
        cout<<bad.what()<<endl;
        }
    }
    set_new_handler(handler);
    cout<<"end of main _ size : "<<size<<endl;
    return 0;
}
