#pragma once
#include <memory>
#include <string>
#include<unordered_map>
using namespace std;



class Config {


public: static shared_ptr<Config> instance;
public: unordered_map<string,string> config_map;


public: Config();
public: virtual ~Config();

public: static shared_ptr<Config> getInstance();
private: void ConfigFileRead(); 

};

typedef std::shared_ptr<Config> P_Config;