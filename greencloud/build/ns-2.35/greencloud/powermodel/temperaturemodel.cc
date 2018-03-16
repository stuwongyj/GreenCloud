/*
 * temperaturemodel.cc
 *
 *  Created on: Jan 26, 2018
 *      Author: wong0903
 */

#include "dchost.h"
#include "temperaturemodel.h"

TemperatureModel::TemperatureModel(){

}

TemperatureModel::~TemperatureModel(){

}

std::vector<double> TemperatureModel::getTemperature(int providers_size) {
	std::string line;
	std::vector<double> temperature;
	std::stringstream sstm;
	std::string s1 = "cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f Intel_Core";
	std::string s2 = ".flp -p core";
	std::string s3 = ".ptrace -steady_file gcc";
	std::string s4 = ".steady >core";
	std::string s5 = ".steady";
	std::string s6 = "/home/wong0903/Documents/HotSpot-6.0/gcc";
	for(int i = 1; i <= 50; i++){
		sstm << s1 << i << s2 << i << s3 << i << s4 << i << s5;
		std::string result = sstm.str();
		std::system(result.c_str());
		sstm.str("");
		sstm << s6 << i << s5;
		result = sstm.str();
		std::ifstream core1(result.c_str());
		if(getline(core1,line)){
			std::istringstream tokenizer(line);
			std::string token;
			getline(tokenizer, token, '	');
			getline(tokenizer, token, '	');
			std::istringstream double_iss(token);
			double d=0;
			double_iss >> d;
			temperature.push_back(d);
		}
		sstm.str("");
	}
	return temperature;
}

void TemperatureModel::update(ResourceProvider*  providers, double eConsumptionRate){
	std::vector <ResourceProvider*>::iterator iter;
	std::stringstream sstm;
	std::string line;
	std::string s1 = "/home/wong0903/Documents/HotSpot-6.0/core";
	std::string s2 = ".ptrace";
	sstm << s1 << (providers->id_)+1 << s2;
	std::string result = sstm.str();
	std::ofstream ptrace(result.c_str());
	sstm.str("");
	if(ptrace.is_open()){
		ptrace << "Core1\n";
		ptrace << eConsumptionRate << "\n";
	}
	ptrace.close();
}


