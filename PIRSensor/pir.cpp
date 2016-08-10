/*
 * pir.cpp
 *
 *  Created on: Aug 10, 2016
 *      Author: trixter93
 */
#include "pir.h"

//set which pin the PIR will attach to
bool getDriverStatus(gpioName pin){
	BlackGPIO myGPIO(pin,input);
	myGPIO.getNumericValue();
	if(myGPIO.getNumericValue()==high){
		cout<<"The Operator is currently active"<<endl;
		return true;
	}else{
		cout<<"The Operator is unable to be detected"<<endl;
		return false;
	}
}





