/*
 * SoundSystem.h
 *
 *  Created on: Aug 12, 2016
 *      Author: trixter93
 */

#ifndef SOUNDSYSTEM_H_
#define SOUNDSYSTEM_H_

#include <iostream>
#include <unistd.h>
#include "BlackPWM/BlackPWM.h"

using namespace BlackLib;
using namespace std;

class SoundSystem{
public:
	SoundSystem();
	SoundSystem(pwmName pwm);
	int setSound(int level);
private:
	BlackPWM *myBuzzer;
};



#endif /* SOUNDSYSTEM_H_ */
