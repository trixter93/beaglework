/*
 * DriverMotionSensor.cpp
 *
 *  Created on: Aug 10, 2016
 *      Author: trixter93
 */
#include <DriverMotionSensor.h>

DriverMotionSensor::DriverMotionSensor(){
}

bool DriverMotionSensor::setPin(gpioName pin1){
	pin = pin1;
	return true;
}

int DriverMotionSensor::getStatus(){
	BlackGPIO PIRpin(pin,input);
	int pin = PIRpin.getNumericValue();
	int pin2 = PIRpin.getNumericValue();
	if (pin==1&&pin2==1){
		return 1;
	}else{
		if (pin==0&&pin2==0){
			return 0;
		}else{
			return 3;
		}
	}
}

