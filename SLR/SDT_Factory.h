#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include "SDT_genertor.h"

using namespace std;
class SDT_Factory {
public: static SDT_Factory instance;
public: SDT_Factory();
public: virtual ~SDT_Factory();
public: P_SDT_genertor getSDT_genertor(const string &key);
};


