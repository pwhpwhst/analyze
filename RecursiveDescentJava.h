#pragma once
#include <string>
#include"symbols\PrimarySymbolConverter.h"
#include <boost/algorithm/string.hpp>
#include"SLR\NodeValue.h"
#include"SLR\Rule.h"
#include "Parser.h"
class RecursiveDescentJava :virtual public Parser {


public: RecursiveDescentJava();
public: virtual ~RecursiveDescentJava();
public: int init(string rule_file);
public: Node* slr(Env &env, string rootSymbol, int wordListBegId);

private:Node* createTerminateNode(P_Lex_Word &p);
public: void findFirstAndLastRules(string symbol, unordered_map<string, int> &map);
public: Node* createNode(P_Rule &rule);

};


















