/*
 * temperature.h
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "dcscheduler.h"
#include "powermodel/temperaturemodel.h"

class TemperatureScheduler : public DcScheduler{
public:
	TemperatureScheduler();
	virtual ~TemperatureScheduler();
	virtual TskComAgent* scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers);
	std::vector<double> temperature_model_list;
	const double scheduledTemp;

};


#endif /* TEMPERATURE_H_ */
