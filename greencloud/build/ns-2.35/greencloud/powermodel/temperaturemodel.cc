/*
 * temperaturemodel.cc
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */


#include "temperaturemodel.h"
#include "dchost.h"

TemperatureModel::TemperatureModel(){

}

TemperatureModel::~TemperatureModel(){

}

std::vector<double> TemperatureModel::getTemperature(int count) {
	system("cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f test.flp -p test.ptrace "
			"-steady_file gcc.steady >test.steady");
	std::string line;
	std::vector<double> temperature;
	std::ifstream infile("/home/wong0903/Documents/HotSpot-6.0/gcc.steady");
	int i = 0;
	while(getline(infile,line) && i < count){
		std::istringstream tokenizer(line);
		std::string token;
		getline(tokenizer, token, '	');
		getline(tokenizer, token, '	');
		std::istringstream float_iss(token);
		float f;
		float_iss >> f;
		temperature.push_back(f);
		i++;
	}
	return temperature;
}

//void TemperatureModel::update(float temperature, std::vector<float>& temperature_model_list){
////	std::vector <ResourceProvider*>::iterator iter;
////	std::vector <double> power;
////	std::ofstream ptrace("/home/wong0903/Documents/HotSpot-6.0/test.ptrace");
////
////	for (iter = providers.begin(); iter!=providers.end(); iter++){
////		 power.push_back(((DcHost*)(*iter))->eCurrentConsumption_);
////		 //std::cout << ((DcHost*)(*iter))->eConsumed_ << std::endl;
////		 std::cout<< providers.size() << std::endl;
////	}
////	if(ptrace.is_open()){
////		ptrace << "Core1\tCore2\tCore3\tCore4\n";
////		ptrace << power.at(0) << '\t' << power.at(1)
////				<< '\t' << power.at(2) << '\t' << power.at(3) << '\n';
////	}
//	std::vector<float>::iterator iter;
//	for(int i=0; i<temperature_model_list.size();i++){
//		if(temperature_model_list.at(i)==*std::min_element(temperature_model_list.begin(),temperature_model_list.end())){
//			temperature_model_list.at(i) = temperature;
//			std::cout<<"asdf=" << temperature_model_list.at(i)<<std::endl;
//			return;
//			}
//		}
//}


