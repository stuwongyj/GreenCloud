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
	int i=0,z=0;
	int size = providers.size();

	//Temperature in Kelvin;
	temperature_model_list = TemperatureModel::getTemperature(size);

	for(iter = providers.begin(); iter!=providers.end(); iter++){
		(*iter)->currentTemperature_ = temperature_model_list.at(i%50);
		i++;
	}


	for (iter = providers.begin(); iter!=providers.end(); iter++){
		//std::ofstream fs("Temperature(144Vms,144host,0.5,2).csv",std::ios_base::app | std::ios_base::out);
		//Selects the VM with the lowest temperature
		if ((*iter)->currentTemperature_ == (*std::min_element(temperature_model_list.begin(),temperature_model_list.end()))){
			//Check if the current VM has available MIPS to execute the task
			if ((*iter)->trySchedulingTsk(task)){
				//fs <<  z  << "," <<  (*iter)->currentTemperature_  << std::endl;
				//fs.close();
				return (*iter)->getTskComAgent();
			}
		}
		z++;
	}
	return NULL;
}

