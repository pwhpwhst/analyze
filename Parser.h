#pragma once
#include <string>
#include"symbols\PrimarySymbolConverter.h"
#include <boost/algorithm/string.hpp>
#include"SLR\NodeValue.h"
#include"SLR\Rule.h"




class Parser {
public: Parser();
public: virtual ~Parser();
public:bool logSwitch = false;

public: virtual int init(string rule_file)=0;
private: string compile_file = "";
public: virtual void init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter);
public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter, int beginIndex, int endIndex);
public: void gen_middle_code(Env &env, Node* &node_tree, unordered_map<string, string> &imfo_map);
public: virtual Node* slr(Env &env, string rootSymbol, int wordListBegId)=0;

protected:vector<P_Rule> ruleList;
protected:vector<P_Lex_Word>  _total_lex_word_list;
protected:vector<P_Lex_Word>  total_lex_word_list;
protected:string ruleFileName;
protected:void log(const string& s);
protected:void paresOrders(const string& rule_file, vector<string>& orders);
protected:void paresOrders(const string& rule_file, vector<string>& orders, vector<vector<string>*> &solveConflictList);
protected:string replaceAll(string str, string sub, string replacement);
protected: int startsWith(const string& s, const string& sub);
protected: int endsWith(const string& s, const string& sub);
protected:unordered_map<int, int> ruleIdToSubId;
};