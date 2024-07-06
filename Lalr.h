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

#include"symbols\PrimarySymbolConverter.h"
#include"SLR\Item.h"
#include"SLR\Node.h"
#include"SLR\Lex_Word.h"
#include"symbols\Env.h"
#include"SLR\Rule.h"
#include "Parser.h"
//#include"SDT\SDT_generator.h"



class Lalr :virtual public Parser {

/*
public: int init(string rule_file);
public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, set<string> &endSymbolSet);O
public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, int beginIndex, int endIndex);O
public: void gen_middle_code(Env &env, Node* &node_tree, unordered_map<string, string> &imfo_map); O
public: Node* slr(Env &env); O

private:vector<P_Rule> ruleList; O
private:vector<P_Lex_Word>  total_lex_word_list; O
private:vector<P_Lex_Word>  total_lex_word_list; O
public:string ruleFileName; O
private: void log(const string& s); O
private: void paresOrders(const string& rule_file, vector<string>& orders, unordered_map<string, string> &temp_forecast_map); O
public: string replaceAll(string str, string sub, string replacement); O
public: int startsWith(string s, string sub); O
public: int endsWith(string s, string sub); O
public:unordered_map<int, int> ruleIdToSubId; O
*/

public: Lalr();
public: virtual ~Lalr();
public: int init(string rule_file);
public: Node* slr(Env &env, string rootSymbol, int wordListBegId);


	class P_Item_Cmp
	{
	public: bool operator ()(const P_Item &c1, const P_Item &c2) const {
		if (c1->rule < c2->rule) {
			return true;
		}
		else if (c2->rule < c1->rule) {
			return false;
		}
		else {
			if (c1->status < c2->status) {
				return true;
			}
			else if (c2->status < c1->status) {
				return false;
			}
			else {
				if (c1->end_for_symbol < c2->end_for_symbol) {
					return true;
				}
				else {
					return false;
				}
			}
		}

	}
	};


	class P_Item_Cmp2
	{
	public: bool operator ()(const P_Item &c1, const P_Item &c2) const {
		if (c1->rule < c2->rule) {
			return true;
		}
		else if (c2->rule < c1->rule) {
			return false;
		}
		else {
			return c1->status < c2->status;
		}

	}
	};

	class Map_Cmp
	{
	public: bool operator ()(const unordered_map<string, int> &c1, const unordered_map<string, int> &c2) const {
		if (c1.at("itemId") < c2.at("itemId")) {
			return true;
		}
		else if (c2.at("itemId") < c1.at("itemId")) {
			return false;
		}
		else {
			if (c1.at("ruleId") < c2.at("ruleId")) {
				return true;
			}
			else if (c2.at("ruleId") < c1.at("ruleId")) {
				return false;
			}
			else {
				return c1.at("statusId") < c2.at("statusId");
			}
		}

	}
	};


public:bool switchParseProcess;
public:bool switchNotSilent;
public:bool switchAllowIllegalInput;


private:string md5;

private:set<string> terminator;
private:set<string> non_terminator;



private: vector<string> ordered_symbols;
private: unordered_map<string, int> symbol_to_id;
private: vector<int>move_table;
private: vector< unordered_map< int, string>> forecast_list;
private: unordered_map<string, set<string>> f_first;

public:vector<vector<P_Item>> items_list;
private:unordered_map<int, unordered_map<string, int>> convert_map;

public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter, set<string> &endSymbolSet);
public: void init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter, int beginIndex, int endIndex);


private: void parse_all_symbol(set<string> &terminator,set<string> &non_terminator,set<string> &zero_terminator,const vector<P_Rule> &ruleList);

private: void get_items_list_and_convert_map(vector<vector<P_Item>> &items_list_temp,
	const set<string> &non_terminator, const set<string> &zero_terminator,unordered_map<string,set<string>> &f_first,const vector<P_Rule> &ruleList,const string start_symbol);

private: void calculate_f_first(unordered_map<string,set<string>> &f_first,const vector<P_Rule> &ruleList,const set<string> &terminator,const set<string> &non_terminator);

private: void calculate_f_follow(unordered_map<string,set<string>> &f_follow, unordered_map<string,set<string>> &f_first,set<string> &zero_terminator,
	const vector<P_Rule> &ruleList,const set<string> &non_terminator,const set<string> &terminator,string start_symbol);

private: void calculate_forecast_list(const vector<vector<P_Item>> &items_list,const set<string> &terminator, vector<P_Rule> &ruleList, unordered_map<P_Rule,int> &rule_map,
	 unordered_map<int,unordered_map<string,int>> &convert_map, unordered_map<string,set<string>> &f_follow);

private: void printStack(Node* &node_tree);

public: void printStackTree(Node* &node_tree,string ignore_file_path);


public: void printGraph(set<int> &itemSet);

public: void printGraph(vector<vector<P_Item>> &items_list,
unordered_map<int,unordered_map<string,int>> &convert_map);

public: void printGraph(vector<vector<P_Item>> &items_list,
	unordered_map<int, unordered_map<string, int>> &convert_map, set<int> &itemSet, bool printAll);

private: void calEndForSymbol(string itemIndex, vector<P_Item> &_items, set<P_Item> &has_calculated_end_for_symbol_set, unordered_map<string, set<P_Item>> &from_map,
	vector<string> &first_input, set<string> _first_set,  unordered_map<string, set<string>> &f_first);
		 

private: Node* syntax_analyze(const vector<P_Rule> &ruleList, set<string> &terminator, set<string> &non_terminator,
	unordered_map<int,unordered_map<string,int>> &convert_map);

private: Node* syntax_analyze(const vector<P_Rule> &ruleList, set<string> &terminator, set<string> &non_terminator,
	unordered_map<int, unordered_map<string, int>> &convert_map, vector<P_Lex_Word> &_total_lex_word_list);
		 

private: bool detect_ambigulous( const vector<P_Rule> &ruleList,const vector<vector<P_Item>> items_list);











private: void calculate_first_set(const vector<string> &strArr, set<string> &result_set, unordered_map<string, set<string>> &f_first);

private: bool is_P_Item_equal(const P_Item & c1, const P_Item & c2);

private: bool shouldBeIgnore(const set<string> &ignore_symbol_set, Node *node, int level);

//	打印 symbol 可能代表的
public: int calculate_f_terminate(string symbol, string rule_file);

private: void calculate_f_terminate_inline(string symbol, const vector<P_Rule> &ruleList,
	const set<string> &terminator, const set<string> &non_terminator);


private: void calClosure(vector<P_Item> &_items, set<string> &rule_name_set, const vector<P_Rule> &ruleList,
	const set<string> &non_terminator, unordered_map<string, set<P_Item>> &from_map, set<P_Item, P_Item_Cmp> &_items_set,
	set<P_Item, P_Item_Cmp> &_visited_items_set, const set<string> &zero_terminator);

//private:bool refreshEndForSymbolFlow(vector<vector<P_Item>> &items_list_temp , unordered_map<string, set<string>> &f_first, int items_list_index);

private:void refreshEndForSymbolFlow(vector<vector<P_Item>> &items_list_temp);

private:void simplifyMap(unordered_map<int, string> &map);

private:bool is_map_same(unordered_map<int, string> &map1, unordered_map<int, string> &map2);

private: Node* create_empty_tree(string & symbol, int index0, int lineNum);
};

