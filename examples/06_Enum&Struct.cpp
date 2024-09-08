#include <iostream>

using namespace std;

namespace CAR_CONST{
    enum{
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
    };
}

struct Car{
    int fuelGauge;
    int curSpeed;
   
    void showCarState();
    void Accel();
};

void Car::showCarState(){
    cout<<"Fuel: "<<fuelGauge<<"%"<<endl;
    cout<<"Speed: "<<curSpeed<<"km/h"<<endl<<endl;
}

void Car::Accel(){
    if (fuelGauge <= 0){
        cout<<">>>no fuel<<<"<<endl<<endl;
        return;
    }
    else
       fuelGauge -= CAR_CONST::FUEL_STEP;
           
    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
        curSpeed = CAR_CONST::MAX_SPD;
    else
        curSpeed += CAR_CONST::ACC_STEP;
    return;
}

int main() {
    Car race99 = {2, 100};
    race99.showCarState();
    race99.Accel();
    race99.showCarState();
    race99.Accel();
    race99.showCarState();
    return 0;
}
