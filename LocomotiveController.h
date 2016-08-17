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
	float getStatus(); //give status of the driver; 0=BLOCKED,1=NON-BLOCK.



private:
    BlackGPIO *SPEEDpin;

};


#endif /* LOCOMOTIVECONTROLLER_H_ */
