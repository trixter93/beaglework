/*
 * Speedbutton.cpp
 *
 *  Created on: Aug 19, 2016
 *      Author: Bella559
 */
#include "Speedbutton.h"

using namespace BlackLib;
using namespace std;

Speedbutton::Speedbutton(){
	speedbutton1 = new BlackGPIO (GPIO_45,input);
    pwmLed = new BlackPWM (EHRPWM2A);
    }
Speedbutton::~Speedbutton(){

}

int Speedbutton::getStatus(){
    //read PWM value
	float percent = 90;
	int click=1;

	while(1);
		    int speedbutton=speedbutton1->getNumericValue();

		    if(speedbutton==high){
		    	sleep(3);
		    	click++;

		    if(click>3){
		    	click=0;
		    }
	}
		    switch(click){
	    		case 1: pwmLed->setDutyPercent(10);
	    		break;
	    		case 2: pwmLed->setDutyPercent(40);
	    		break;
	    		case 3: pwmLed->setDutyPercent(60);
	    		break;
		    }
	}


int Speedbutton::Stop(){
	float percent = Speedbutton::getStatus();

		if (percent == 90){
			cout << "STOP" << endl;
			}
		else{

			return 0;

			}

}






