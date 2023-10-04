#pragma once
#include <unordered_map>
#include "Token.h"
using namespace std;






class Env{


//private: unordered_map<string, unordered_map<string,string>> table;
//protected: Env *prev;
//
//protected: vector<Env*> childList;

public: vector<P_Token> list;

public: Env();

public: virtual ~Env();

};

