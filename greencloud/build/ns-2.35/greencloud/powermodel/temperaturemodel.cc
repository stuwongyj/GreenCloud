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

std::vector<double> TemperatureModel::getTemperature() {
	std::system("cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f Intel_Core1.flp -p core1.ptrace "
				"-steady_file gcc1.steady >core1.steady");
	std::system("cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f Intel_Core2.flp -p core2.ptrace "
					"-steady_file gcc2.steady >core2.steady");
	std::system("cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f Intel_Core3.flp -p core3.ptrace "
					"-steady_file gcc3.steady >core3.steady");
	std::system("cd ~/Documents/HotSpot-6.0 ; ./hotspot -c hotspot.config -f Intel_Core4.flp -p core4.ptrace "
					"-steady_file gcc4.steady >core4.steady");
	std::string line;
	std::vector<double> temperature;
	std::ifstream core1("/home/wong0903/Documents/HotSpot-6.0/gcc1.steady");
	std::ifstream core2("/home/wong0903/Documents/HotSpot-6.0/gcc2.steady");
	std::ifstream core3("/home/wong0903/Documents/HotSpot-6.0/gcc3.steady");
	std::ifstream core4("/home/wong0903/Documents/HotSpot-6.0/gcc4.steady");

	if(getline(core1,line)){
		std::istringstream tokenizer(line);
		std::string token;
		getline(tokenizer, token, '	');
		getline(tokenizer, token, '	');
		std::istringstream double_iss(token);
		double d;
		double_iss >> d;
		temperature.push_back(d);
	}

	if(getline(core2,line)){
		std::istringstream tokenizer(line);
		std::string token;
		getline(tokenizer, token, '	');
		getline(tokenizer, token, '	');
		std::istringstream double_iss(token);
		double d;
		double_iss >> d;
		temperature.push_back(d);
	}

	if(getline(core3,line)){
		std::istringstream tokenizer(line);
		std::string token;
		getline(tokenizer, token, '	');
		getline(tokenizer, token, '	');
		std::istringstream double_iss(token);
		double d;
		double_iss >> d;
		temperature.push_back(d);
	}

	if(getline(core4,line)){
		std::istringstream tokenizer(line);
		std::string token;
		getline(tokenizer, token, '	');
		getline(tokenizer, token, '	');
		std::istringstream double_iss(token);
		double d;
		double_iss >> d;
		temperature.push_back(d);
	}
	return temperature;
}

void TemperatureModel::update(std::vector<ResourceProvider* > providers){
	std::vector <ResourceProvider*>::iterator iter;
	std::vector <double> power;
	std::ofstream core1("/home/wong0903/Documents/HotSpot-6.0/core1.ptrace");
	std::ofstream core2("/home/wong0903/Documents/HotSpot-6.0/core2.ptrace");
	std::ofstream core3("/home/wong0903/Documents/HotSpot-6.0/core3.ptrace");
	std::ofstream core4("/home/wong0903/Documents/HotSpot-6.0/core4.ptrace");

	for (iter = providers.begin(); iter!=providers.end(); iter++){
		 power.push_back(((DcHost*)(*iter))->eCurrentConsumption_);
	}
//	std::cout << power.at(0) << ' ' << power.at(1) << ' ' << power.at(2) << ' ' << power.at(3) << std::endl;
//	std::cout << "-----------------" << std::endl;

		if(core1.is_open()){
			core1 << "Core1\n";
			core1 << power.at(0) << "\n";
		}
		core1.close();

		if(core2.is_open()){
				core2 << "Core1\n";
				core2 << power.at(1) << "\n";
			}
		core2.close();

		if(core3.is_open()){
				core3 << "Core1\n";
				core3 << power.at(2) << "\n";
			}
		core3.close();

		if(core4.is_open()){
				core4 << "Core1\n";
				core4 << power.at(3) << "\n";
			}
		core4.close();

}


