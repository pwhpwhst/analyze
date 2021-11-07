#include "Config.h"
#include <iostream>
#include <fstream>
using namespace std;

P_Config Config::instance = nullptr;

void Config::ConfigFileRead()
{
	ifstream configFile;
	string path = "../../resources/setting.conf";
	configFile.open(path.c_str());
	string strLine;
	if (configFile.is_open())
	{
		while (!configFile.eof())
		{
			getline(configFile, strLine);
			size_t pos = strLine.find('=');
			string key = strLine.substr(0, pos);
			string value = strLine.substr(pos + 1);
			config_map[key] = value;
		}
	}
}

P_Config  Config::getInstance() {
	if (Config::instance==nullptr) {
		Config::instance = P_Config(new Config);
	}
	return Config::instance;
};

Config::Config() {
	ConfigFileRead();
}

Config::~Config() {
}




