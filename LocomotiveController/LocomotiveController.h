/*
 * LocomotiveController.h
 *
 *  Created on: Aug 15, 2016
 *      Author: bella559
 */

#ifndef LOCOMOTIVECONTROLLER_H_
#define LOCOMOTIVECONTROLLER_H_

#include <iostream>
#include "BlackGPIO/BlackGPIO.h"
#include <string>
#include <time.h>
#include <sys/time.h>

using namespace std;
using namespace BlackLib;

class LocomotiveController {
public:

	LocomotiveController();
	virtual ~LocomotiveController();
	float getStatus(); //give status of the driver; return speed of wheel.
	int getStatusOverSpeed(); // give the status of the speed; 1=over-speed, 0=NONoverspeed


private:
    BlackGPIO *SPEEDpin;

};


#endif /* LOCOMOTIVECONTROLLER_H_ */
