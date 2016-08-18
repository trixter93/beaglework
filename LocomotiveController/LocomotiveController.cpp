/*
 * LocomotiveController.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: bella559
 */

#include "LocomotiveController.h"


LocomotiveController::LocomotiveController() {
	SPEEDpin = new BlackGPIO (GPIO_48,input);
}

LocomotiveController::~LocomotiveController() {

}

float LocomotiveController::getStatus() {
	// read status of the driver
	int speedhigh,speedlow;
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
			if(counter1>2){
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
			if(counter>10){
				speed=(90/elapsedTime)*60000000;
				speedhigh=speed*1.001;
				speedlow=speed*0.999;
				counter=0;
				if (speed<speedhigh&&speed>speedlow){
				block=5;
				}else{
					block=2;
					speed=0;
					elapsedTime=0;
				}
			}
			break;
		}//switch case
	}//while case
	return speed;
}
int LocomotiveController::getStatusOverSpeed() {
	float speed = LocomotiveController::getStatus();
	int maxspeed = 67500; //the speed is over limit ; reference speed:67500 rev/m
	cout << speed << endl;
	if (speed < maxspeed){
			return 0;
		}
	else{

			return 1;

		}
		speed=0;
}

