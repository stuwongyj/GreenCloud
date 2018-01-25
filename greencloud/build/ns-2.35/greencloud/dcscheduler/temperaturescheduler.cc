/*
 * temperaturescheduler.cc
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */



#include "temperaturescheduler.h"

TemperatureScheduler::TemperatureScheduler():scheduledTemp(15){

}

TemperatureScheduler::~TemperatureScheduler() {

}

TskComAgent* TemperatureScheduler::scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers){
	std::vector <ResourceProvider*>::iterator iter;
	//float* minTemperature;
	//Temperature in Kelvin;
	temperature_model_list = TemperatureModel::getTemperature(providers.size());

	for (iter = providers.begin(); iter!=providers.end(); iter++){
		if ((*iter)->currentTemperature_ == (*std::min_element(temperature_model_list.begin(),temperature_model_list.end()))){
			//288.15K = 15celsius
			(*iter)->currentTemperature_ += scheduledTemp;
			//TemperatureModel::update((*iter)->currentTemperature_, temperature_model_list);
			std::cout << "fd= " << temperature_model_list.at(0) << std::endl;
			//return (*iter)->getTskComAgent();
			}
		}
		for (iter = providers.begin(); iter!=providers.end(); iter++)
		{
			if ((*iter)->trySchedulingTsk(task))
				return (*iter)->getTskComAgent();
		}

	return NULL;
}

