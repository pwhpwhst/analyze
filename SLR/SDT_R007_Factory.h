#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include "SDT_genertor.h"

using namespace std;
class SDT_R007_Factory {
public: static SDT_R007_Factory instance;
public: SDT_R007_Factory();
private: map<string, int> control_Param;
public: virtual ~SDT_R007_Factory();
public: unordered_map<string, P_SDT_genertor> factory;
public: P_SDT_genertor getSDT_genertor(const string &key);
};


