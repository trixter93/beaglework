/*
 * DriverMotionSensor.cpp
 *
 *  Created on: Aug 10, 2016
 *      Author: trixter93
 */
#include <DriverMotionSensor.h>

DriverMotionSensor::DriverMotionSensor(){
	PIRpin = new BlackGPIO(GPIO_65,input);
}

DriverMotionSensor::DriverMotionSensor(gpioName pin){
	PIRpin = new BlackGPIO(pin,input);
}


int DriverMotionSensor::getStatus(){

	int pin = PIRpin->getNumericValue();
	int pin2 = PIRpin->getNumericValue();
	if (pin==1&&pin2==1){
		return 0;
	}else{
		if (pin==0&&pin2==0){
			return 1;
		}else{
			return 2;
		}
	}
}

