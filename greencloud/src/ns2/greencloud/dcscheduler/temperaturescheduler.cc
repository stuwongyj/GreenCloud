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
	int i=0 ,j=0, z=0;
	double result1=0,result2=0,result3=0,result4=0;
	//Temperature in Kelvin;
	temperature_model_list = TemperatureModel::getTemperature();
	for(iter = providers.begin(); iter!=providers.end(); iter++){
		(*iter)->currentTemperature_ = temperature_model_list.at(i%4);
		//std::cout << temperature_model_list.at(i) << std::endl;
//		std::cout << "temperature= " << (*iter)->currentTemperature_ << " utilization= " << (*iter)->getResTypeUtil(Computing)
//				<< " vms= " << j << std::endl;
		if(i%4 == 0){
			result1+=(*iter)->getResTypeUtil(Computing);
		}else if(i%4 == 1){
			result2+=(*iter)->getResTypeUtil(Computing);
		}else if(i%4 == 2){
			result3+=(*iter)->getResTypeUtil(Computing);
		}else
			result4+=(*iter)->getResTypeUtil(Computing);
		i++;
		//j++;
	}
	result1 /= 20.0;
	result2 /= 20.0;
	result3 /= 20.0;
	result4 /= 20.0;
	//std::cout << "----------------" << std::endl;
//	std::cout << "result1= " << result1<< " result2= " << result2
//				<< "result3= " << result3 << " result4= " << result4 << std::endl;
	for (iter = providers.begin(); iter!=providers.end(); iter++){
		if ((*iter)->currentTemperature_ == (*std::min_element(temperature_model_list.begin(),temperature_model_list.end()))){
//			std::cout << "vms= " << z << " temperature= " << (*iter)->currentTemperature_ << " " ;
//			if(z%4 == 0){
//				std::cout << "result1 = " << result1 << std::endl;
//			}else if(z%4 == 1){
//				std::cout << "result2 = " << result2 << std::endl;
//			}else if(z%4 == 2){
//				std::cout << "result3 = " << result3 << std::endl;
//			}else
//				std::cout << "result4 = " << result4 << std::endl;
//			std::cout << "--------------------" <<  std::endl;
			return (*iter)->getTskComAgent();
		}
		z++;
	}


	return NULL;
}

