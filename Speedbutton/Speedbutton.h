/*
 * Speedbutton.h
 *
 *  Created on: Aug 16, 2016
 *      Author: Bella559
 */

#ifndef SPEEDBUTTON_H_
#define SPEEDBUTTON_H_

#include <iostream>
#include <string>

#include "BlackCore.h"
#include "BlackDef.h"
#include "BlackErr.h"
#include "BlackLib.h"
#include "BlackDirectory/BlackDirectory.h"
#include "BlackGPIO/BlackGPIO.h"
#include "BlackPWM/BlackPWM.h"


using namespace std;
using namespace BlackLib;

class Speedbutton {

    public:
    Speedbutton();
    virtual ~Speedbutton();
    int getStatus(); // give status of driver; SLOW=60%, OPTIMUM=40%, FAST=10%.
    int Stop(); // when STOP, pwm = 100%.


    private:
    BlackGPIO *speedbutton1;
    BlackPWM  *pwmLed;


};

#endif /* SPEEDBUTTON_H_ */



