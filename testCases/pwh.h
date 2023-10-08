#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../symbols/Env.h"
using namespace std;
class pwh {

public:	pwh();
public:	~pwh();
public:	int test1(string i_rule_file, string i_testCaseFolder, string i_test_file, Env &env);
};