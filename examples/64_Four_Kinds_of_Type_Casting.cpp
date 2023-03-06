#include <iostream>

using namespace std;

class Car{
    private:
        int fuelGauge;
    public:
        Car(int fuel) : fuelGauge(fuel){
        }
        void showCarState(){
            cout<<"rest fuel : "<<fuelGauge<<endl;
        }
};
class Truck : public Car{
    private:
        int freightWeight;
    public:
        Truck(int fuel, int weight) : Car(fuel), freightWeight(weight){
        }
        void showTruckState(){
            showCarState();
            cout<<"weight of freight : "<<freightWeight<<endl;
        }
};

int main() {
    Truck * truck1 = new Truck(80, 200);
    Car * car1 = dynamic_cast<Car*>(truck1); // _from_ pointer of derived class _to_ pointer of base class
    
    Car * car2 = new Truck(70, 190);
    Truck * truck2 = static_cast<Truck*>(car1); // _from_ pointer of base class _to_ pointer of derived class
    
    const char * constStr = "helloworld";
    char * Str = const_cast<char*>(constStr); // remove constant of pointer declared as const
    
    int num = 0x010203;
    char * ptr = reinterpret_cast<char*>(&num); // anything related pointer
    for(int i=0; i<sizeof(num); i++) 
        cout<< static_cast<int>(*(ptr+i))<<endl;
    
    return 0;
}
