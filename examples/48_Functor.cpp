#include <iostream>

using namespace std;

class SortRule{
    public:
        virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule{
    public:
        bool operator()(int num1, int num2) const{
            if (num1>num2)
                return true;
            else
                return false;
        }
};

class DescendingSort : public SortRule{
    public:
        bool operator()(int num1, int num2) const{
            if (num2>num1)
                return true;
            else
                return false;
        }
};

void SortData(int * arr, const SortRule& functor = AscendingSort()){
    //int size = sizeof(arr)/sizeof(*arr);
    int size = 10;
    for (int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if (functor(arr[j], arr[j+1])){
                int temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[10] = {7,6,8,4,2,5,9,1,10,3};
    SortData(arr, AscendingSort());
    for (int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
