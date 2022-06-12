#pragma once
#include "SmbolInfo.h"
#include <unordered_map>
using namespace std;






class Env{


//private: unordered_map<string, unordered_map<string,string>> table;
//protected: Env *prev;
//
//protected: vector<Env*> childList;

public: P_Token list;

public: Env();

public: virtual ~Env();

};

