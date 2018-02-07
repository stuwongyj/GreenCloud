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
//	std::cout << "----------" << std::endl;
	int j = task->id_ % providers.size();

	return (providers.at(j)->getTskComAgent());
}
