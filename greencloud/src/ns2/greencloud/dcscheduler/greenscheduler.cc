/*
 * greenscheduler.cc
 *
 *  	@date Jan 8, 2014
 *      @author Guzek:Mateusz
 */

#include "greenscheduler.h"
#include "powermodel/temperaturemodel.h"



GreenScheduler::GreenScheduler() {


}

GreenScheduler::~GreenScheduler() {

}

TskComAgent* GreenScheduler::scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers){
	std::vector <ResourceProvider*>::iterator iter;
	int z=0, i=0;
	int result[50] = {};
	//Temperature in Kelvin;
	//green_temperature_list = TemperatureModel::getTemperature(providers.size());

	//Adding the current load of each VMs to get the utilisation for each server
	//Each server has 10 VMs
//	for(iter = providers.begin(); iter!=providers.end(); iter++){
//		(*iter)->currentTemperature_ = green_temperature_list.at(i);
//		//result[i%20] += (*iter)->getResTypeUtil(Computing);
//		i++;
//	}

//	for(int j=0; j<50; j++){
//		result[j]/=2.0;
//	}

	//std::ofstream fs("Green(144Vms,144host,0.8,3).csv",std::ios_base::app | std::ios_base::out);
	for (iter = providers.begin(); iter!=providers.end(); iter++)
	{
		if ((*iter)->trySchedulingTsk(task)){
//			fs <<  z << ","  << (*iter)->currentTemperature_ <<  std::endl;
//			fs.close();
			return (*iter)->getTskComAgent();
		}
		//z++;
	}
	return NULL;
}

