/*
 * temperaturemodel.h
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */

#ifndef TEMPERATUREMODEL_H_
#define TEMPERATUREMODEL_H_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

class TemperatureModel{
public:

	TemperatureModel();
	virtual ~TemperatureModel();
	static std::vector<double> getTemperature(int providers_size);
	static void update(ResourceProvider* providers, double eConsumptionRate);
};



#endif /* TEMPERATUREMODEL_H_ */
