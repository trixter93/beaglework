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
	DriverMotionSensor(gpioName pin);
	int getStatus();
	//give status of the driver, 0=absent, 1=presence, 3=not sure.

private:
	BlackGPIO *PIRpin;
};


#endif /* DRIVERMOTIONSENSOR_H_ */
