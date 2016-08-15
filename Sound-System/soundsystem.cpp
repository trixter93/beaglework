/*
 * SoundSystem.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: trixter93
 */
#include "SoundSystem.h"

SoundSystem::SoundSystem(){
	myBuzzer = new BlackPWM(P9_14);
}

SoundSystem::SoundSystem(pwmName pwm){
	myBuzzer = new BlackPWM(pwm);
}

int SoundSystem::setSound(int level){
		int percent = 90;
		switch(level){
		case 0: if(level==0){
			level = 1;
		}
			break;
		case 1: if(level==1){
			myBuzzer->setDutyPercent(percent);
			myBuzzer->setPeriodTime(500000);
			usleep(20000);
			myBuzzer->setDutyPercent(100);
			usleep(250000);
			myBuzzer->setDutyPercent(percent);
			usleep(20000);
			myBuzzer->setDutyPercent(100);
			usleep(500000);
		}
		level=2;
		break;
		case 2: if(level==2){
			myBuzzer->setDutyPercent(percent);
			myBuzzer->setPeriodTime(500000);
			usleep(20000);
			myBuzzer->setDutyPercent(100);
			usleep(250000);
			myBuzzer->setDutyPercent(percent);
			usleep(20000);
			myBuzzer->setDutyPercent(100);
			usleep(5000);
		}//case 2 if statement
		level=0;
		break;
	}//switch statement
	return 0;
}


