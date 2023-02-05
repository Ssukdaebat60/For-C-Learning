#include <iostream>
#include "Car.h"
using namespace std;

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
