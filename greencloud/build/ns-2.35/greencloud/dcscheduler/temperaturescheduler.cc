/*
 * temperaturescheduler.cc
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */



#include "temperaturescheduler.h"

TemperatureScheduler::TemperatureScheduler(){

}

TemperatureScheduler::~TemperatureScheduler() {

}



TskComAgent* TemperatureScheduler::scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers){
	std::vector <ResourceProvider*>::iterator iter;
	std::vector <double>::iterator h;
	int i=0,j=0;
	//Temperature in Kelvin;
	temperature_model_list = TemperatureModel::getTemperature(providers.size());
	for(iter = providers.begin(); iter!=providers.end(); iter++){
		(*iter)->currentTemperature_ = temperature_model_list.at(i);
		std::cout << temperature_model_list.at(i) << std::endl;
		i++;
	}


	for (iter = providers.begin(); iter!=providers.end(); iter++){;
		if ((*iter)->currentTemperature_ == (*std::min_element(temperature_model_list.begin(),temperature_model_list.end()))){
			//update(providers);
			std::cout<< "current= " << (*iter)->currentTemperature_ << std::endl;
			std::cout << "----------------" << std::endl;
			return (*iter)->getTskComAgent();

		}
	}

	return NULL;
}

