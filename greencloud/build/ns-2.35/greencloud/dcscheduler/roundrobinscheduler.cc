/*
 * roundrobinscheduler.cc
 *
 *  	@date Jan 8, 2014
 *      @author Guzek:Mateusz
 */

#include "roundrobinscheduler.h"
#include "dchost.h"
#include "powermodel/temperaturemodel.h"


RoundRobinsScheduler::RoundRobinsScheduler() {


}

RoundRobinsScheduler::~RoundRobinsScheduler() {

}

TskComAgent* RoundRobinsScheduler::scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers){
	std::vector <ResourceProvider*>::iterator iter;
	int i = 0;
	//int result[50] = {};
	//round_temperature_list = TemperatureModel::getTemperature(providers.size());
	//for(iter = providers.begin(); iter!=providers.end(); iter++){
			//(*iter)->currentTemperature_ = round_temperature_list.at(i);
			//result[i%50] += (*iter)->getResTypeUtil(Computing);
			//std::cout << "temperature" << i << "= " << (*iter)->currentTemperature_ << std::endl;
			//i++;
	//}
//	for(int z=0; z<50; z++){
//		result[z] /= 2.0;
//	}

	int j = task->id_ % providers.size();
	//std::ofstream fs("Round(144VMs,144host,0.8,2s).csv", std::ios_base::app | std::ios_base::out);
	//fs << j << "," << providers.at(j)->currentTemperature_ << std::endl;
	//fs.close();
	return (providers.at(j)->getTskComAgent());
}
