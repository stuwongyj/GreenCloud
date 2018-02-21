/*
 * roundrobinscheduler.cc
 *
 *  	@date Jan 8, 2014
 *      @author Guzek:Mateusz
 */

#include "roundrobinscheduler.h"
#include "dchost.h"

RoundRobinsScheduler::RoundRobinsScheduler() {


}

RoundRobinsScheduler::~RoundRobinsScheduler() {

}

TskComAgent* RoundRobinsScheduler::scheduleTask(CloudTask* task, std::vector<ResourceProvider* > providers){
	std::vector<ResourceProvider* >::iterator iter;
//	for(iter = providers.begin() ; iter != providers.end(); iter++){
//		std::cout << ((DcHost*)(*iter))->eConsumed_ << std::endl;
//	}

	int j = task->id_ % providers.size();
	if(providers.at(j)->resource_utilization[Computing] >= 0.4){
	std::cout << "j= " << j << " util= " << providers.at(j)->resource_utilization[Computing]  <<  std::endl;}
	return (providers.at(j)->getTskComAgent());
}
