#include <iostream>

using namespace std;

template <typename T=int, int len=5>
class SimpleArr{
    private:
        T arr[len];
    public:
        T& operator[](int idx){
            return arr[idx];
        }
};

int main() {
    SimpleArr<int, 5> arr1;
    for (int i=0; i<5; i++){
        arr1[i] = i;
    }
    SimpleArr<> arr2 = arr1;
    for (int i=0; i<5; i++){
        cout<<arr1[i]<<endl;
    }
    cout<<endl;
    SimpleArr<double, 7> arr3;
    for (int i=0; i<7; i++){
        arr3[i] = i*1.1;
    }
    SimpleArr<double, 7> arr4 = arr3;
    for (int i=0; i<7; i++){
        cout<<arr4[i]<<endl;
    }
    cout<<endl;
    
    return 0;
}
