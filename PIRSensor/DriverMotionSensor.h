/*
 * DriverMotionSensor.h
 *
 *  Created on: Aug 10, 2016
 *      Author: trixter93
 */

#ifndef DRIVERMOTIONSENSOR_H_
#define DRIVERMOTIONSENSOR_H_

#include <iostream>
#include "BlackGPIO/BlackGPIO.h"
#include <string>

using namespace std;
using namespace BlackLib;

class DriverMotionSensor{
public:
	DriverMotionSensor();
	bool setPin(gpioName pin1);
	int getStatus();
	//give status of the driver, 0=absent, 1=presence, 3=not sure.

private:
	volatile gpioName pin=GPIO_11;
};


#endif /* DRIVERMOTIONSENSOR_H_ */
