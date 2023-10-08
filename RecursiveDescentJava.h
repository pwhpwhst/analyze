#pragma once
#include <string>
#include"symbols\PrimarySymbolConverter.h"
#include <boost/algorithm/string.hpp>
#include"SLR\NodeValue.h"
#include"SLR\Rule.h"
class RecursiveDescentJava {


public: RecursiveDescentJava();

private:vector<P_Rule> ruleList;

public: virtual ~RecursiveDescentJava();
public: void log(const string& s);
public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, set<string> &endSymbolSet);
private:vector<P_Lex_Word>  total_lex_word_list;
private:Node* createTerminateNode(P_Lex_Word &p);
public: Node* slr(Env &env, string rootSymbol);

public: void findFirstAndLastRules(string symbol, unordered_map<string, int> &map);
public: int startsWith(const string& s, const string& sub);
public: int endsWith(const string& s, const string& sub);
public: void paresOrders(const string& rule_file, vector<string>& orders);
public: void init(string rule_file);
public: Node* createNode(P_Rule &rule);
};


















