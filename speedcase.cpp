 //* beagle_main.cpp
 //*
 //*  Created on: Jul 22, 2016
 //*      Author: aina
 //*/
//C++ program
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <string>

#include "BlackCore.h"
#include "BlackDef.h"
#include "BlackErr.h"
#include "BlackLib.h"
#include "BlackADC/BlackADC.h"
#include "BlackDirectory/BlackDirectory.h"
#include "BlackGPIO/BlackGPIO.h"
#include "BlackI2C/BlackI2C.h"
#include "BlackPWM/BlackPWM.h"
#include "BlackSPI/BlackSPI.h"
#include "BlackTime/BlackTime.h"
#include "BlackUART/BlackUART.h"

using namespace std;
using namespace BlackLib;

int main() {

	    float percent = 90;
	    std::string currentDuty;
	    std::string currentPeriod;
	    std::string currentPercentValue;
	    std::string currentPolarity;
	    std::string currentRun;
	    int click=1,speedbutton;

	    BlackLib::BlackPWM    pwmLed(BlackLib::EHRPWM2A);
	    BlackLib::BlackGPIO   speedbutton1(BlackLib::GPIO_45,BlackLib::input);


	    pwmLed.setDutyPercent(10);
	    pwmLed.setPeriodTime(500000);

	    while( ! pwmLed.fail(BlackLib::BlackPWM::outOfRangeErr) )
	    	    {
	    	while(1){
	    		speedbutton=speedbutton1.getNumericValue();
	    		if(speedbutton==high){
	    			sleep(3);
	    			click++;
	    			cout<<click<<endl;
	    			if(click>3){
	    				click=0;
	    			}
	    		}
	    		switch(click){
	    		case 1: pwmLed.setDutyPercent(10);
	    		cout<<click<<endl;
	    		break;
	    		case 2: pwmLed.setDutyPercent(40);
	    		cout<<click<<endl;
	    		break;
	    		case 3: pwmLed.setDutyPercent(60);
	    		cout<<click<<endl;
	    		break;
	    		}

	    	}

//	    	    	for(;;){
//	    	        pwmLed.setDutyPercent(percent);
//	    	        std::cout << std::endl << "New percent value: " << percent << std::endl;
//
//	    	        if(speedbutton1.getNumericValue() == 1){
//	    	           percent=10;
//	    	          }
//	    	        else{
//}
//
//	    	    	}
//	    	        sleep(5);
//	    	        std::cout << "Percent value is out of range." << std::endl;
//	    	    	}
	    	    }
	    return 0;
}
