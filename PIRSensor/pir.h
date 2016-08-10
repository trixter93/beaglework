/*
 * pir.h
 *
 *  Created on: Aug 10, 2016
 *      Author: trixter93
 */

#ifndef PIR_H_
#define PIR_H_

#include <iostream>
#include "BlackGPIO/BlackGPIO.h"
#include <string>

using namespace std;
using namespace BlackLib;

bool getDriverStatus(gpioName pin);

#endif /* PIR_H_ */
