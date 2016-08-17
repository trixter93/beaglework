/*
 * LocomotiveController.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: pc2
 */

#include "LocomotiveController.h"


LocomotiveController::LocomotiveController() {
	SPEEDpin = new BlackGPIO (GPIO_48,input);
}

LocomotiveController::~LocomotiveController() {

}

float LocomotiveController::getStatus() {
	// read status of the driver
	int counter1=0;
    struct timeval t1,t2;
    double elapsedTime;
    float speed;
    string oldValue = "1";
    int counter =0;

	volatile int block =1;
	while(block<5){
		int newValue = SPEEDpin->getNumericValue();
		switch(block){
		case 0: if(newValue==low){
			block=1;
		}
		break;
		case 1: if(newValue==low){
			block=0;
			counter1+=1;
			if(counter1>3){
				block=2;
				counter1=0;
			}
		}
		break;
		case 2:
			if(newValue==low){
			gettimeofday(&t1,NULL);
			block=3;
			}
			break;
		case 3:
			if(newValue ==high){
			gettimeofday(&t2,NULL);
			block=4;
			}
			break;
		case 4:
			elapsedTime+=(t2.tv_usec-t1.tv_usec);
			block=2;
			counter+=1;
			if(counter>20){
				speed=(2/(elapsedTime/5))*10000;
				block=5;
			}
			break;
		}//switch case
	}//while case
	return speed;
}
