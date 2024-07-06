#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include<boost/algorithm/string.hpp>
#include "SDT_R004_Factory.h"
#include "SDT_R005_Factory.h"
#include "SDT_R006_Factory.h"
#include "SDT_R007_Factory.h"
#include "SDT_R008_Factory.h"
#include "SDT_R009_Factory.h"
#include "SDT_R010_Factory.h"
using namespace std;
using namespace boost;



SDT_Factory SDT_Factory::instance;
SDT_Factory::SDT_Factory() {

}

P_SDT_genertor SDT_Factory::getSDT_genertor(const string &key) {



	if (key.find("R004_") == 0) {
		return SDT_R004_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R005_") == 0){
		return SDT_R005_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R006_") == 0) {
		return SDT_R006_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R007_") == 0) {
		return SDT_R007_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R008_") == 0) {
		return SDT_R008_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R009_") == 0) {
		return SDT_R009_Factory::instance.getSDT_genertor(key);
	}
	else if (key.find("R010_") == 0) {
		return SDT_R010_Factory::instance.getSDT_genertor(key);
	}

}
SDT_Factory::~SDT_Factory() {}


