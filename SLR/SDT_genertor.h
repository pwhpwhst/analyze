#pragma once
#include<string>
#include<vector>
#include<set>
#include<sstream>
#include "NodeValue.h"
#include "../symbols/Env.h"
using namespace std;
class SDT_genertor {
public: SDT_genertor();
public: virtual P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) = 0;
public: virtual ~SDT_genertor();
protected: string child(const P_NodeValue &nodeValue, int index, int value_type);
protected: string own(const P_NodeValue &nodeValue, int value_type);
protected: ostringstream os;
};

typedef std::shared_ptr<SDT_genertor> P_SDT_genertor;


