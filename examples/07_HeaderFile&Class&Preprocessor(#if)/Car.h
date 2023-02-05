//Declare of Class
#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST{
    enum{
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
    };
}

class Car{
    int fuelGauge;
    int curSpeed;
    void showCarState();
    void Accel();
}

#endif
