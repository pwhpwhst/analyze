//#define __PRINT_SYMBOL
//#define __PRINT_F_FIRST
//#define __PRINT_F_FOLLOW
//#define __PRINT_FORECAST
//#define __PRINT_GRAPH
#define __CHECK_CONFILCT
//#define __PRINT_LEX_WORD_LIST
#define __PRINT_PARSE_PROCESS
#define __PRINT_NOT_SILENT
//#define __ALLOW_AMBIGULOUS

#include "Lalr.h"
#include"symbols\PrimarySymbolConverter.h"
#include "Util/Util.h"
#include <algorithm>
#include <string>
#include "MD5.h"
#include "dao/TFileMD5Dao.h"
#include "dao/TItemDao.h"
#include "dao/TConvertMapDao.h"
#include "dao/TShortCodeDao.h"
#include "dao/TMoveTableDao.h"
#include "dao/TForecastDao.h"
#include "dao/TForecast2Dao.h"
#include "dao/TRuleDao.h"
#include"SLR\NodeValue.h"
#include"SLR\SDT_Factory.h"

using namespace std;
using namespace boost;


std::string pointerToString(void* ptr) {
	return std::to_string(reinterpret_cast<uintptr_t>(ptr));
}

int Lalr::calculate_f_terminate(string symbol, string rule_file) {
	ruleList.clear();
	terminator.clear();
	non_terminator.clear();

	//初始化
	string start_symbol = "ele_begin";

	//
	log("生成ruleListing");
	ifstream input_file;
	input_file.open(rule_file.data());
	string rule_str;
	ostringstream sb;

	vector<string> orders;
	vector<vector<string>*> solveConflictList;
	paresOrders(rule_file, orders, solveConflictList);
	for (const auto &e : orders) {
		ruleList.push_back(P_Rule(new Rule(e)));
	}


	vector <string> string_list;

	unordered_map<P_Rule, int> rule_map;
	for (int i1 = 0; i1 < ruleList.size(); i1++) {
		rule_map[ruleList[i1]] = i1;
	}


	//划出所有的终结符号和非终结符号
	log("划出所有的终结符号和非终结符号");
	set<string> zero_terminator;
	parse_all_symbol(terminator, non_terminator, zero_terminator, ruleList);


	//计算first函数
	log("计算first函数");

	calculate_f_terminate_inline(symbol, ruleList, terminator, non_terminator);
	return 0;
}


string replaceAll(string str, const string &sub, const string &replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}


string getMD5(string fileName) {
	string oriFileName = fileName;
	fileName = replaceAll(fileName, "\\", "&&");
	fileName = replaceAll(fileName, "&&", "\\\\");
	ifstream input_file;
	input_file.open(fileName.data());
	string str;
	ostringstream os;
	while (getline(input_file, str)) {
		os << str << endl;
	}
	MD5 test;
	string md5 = test.encode(os.str());
	return md5;
}


int Lalr::init(string rule_file) {

	vector <string> strs;
	split(strs, rule_file, is_any_of("\\"));


	ruleFileName = strs[strs.size() - 1];
	ruleFileName = replaceAll(ruleFileName, ".txt", "");
	string md5=getMD5(rule_file);

	P_TFileMD5Dao tFileMD5Dao = TFileMD5Dao::getInstance();



	unordered_map<string, string> transfer_map;
	string rule_file2 = replaceAll(replaceAll(rule_file, "\\", "&"), "&", "\\\\");

	transfer_map["fileName"] = rule_file2;
	vector<unordered_map<string, string>> result_list;

	bool isChanged = false;

	string oriMD5 = "0";
	tFileMD5Dao->queryList(transfer_map, result_list);
	if (result_list.size() == 0) {
		isChanged = true;
	}
	else if (result_list[0]["md5"] != md5) {
		isChanged = true;
		oriMD5 = result_list[0]["md5"];
	}
	else {
		oriMD5 = result_list[0]["md5"];
	}



	ruleList.clear();
	terminator.clear();
	non_terminator.clear();
	symbol_to_id.clear();
	move_table.clear();
	forecast_list.clear();
	ordered_symbols.clear();

	convert_map.clear();

	//初始化
	string start_symbol = "ele_begin";

	//
	log("生成ruleListing");
	ifstream input_file;
	input_file.open(rule_file.data());
	string rule_str;
	ostringstream sb;

	vector<string> orders;
	vector<vector<string>*> solveConflictList;
	paresOrders(rule_file, orders, solveConflictList);

	unordered_map<string, int> ruleNameCountMap;
	ruleIdToSubId.clear();
	for (const auto &e : orders) {
		ruleList.push_back(P_Rule(new Rule(e)));
		ruleList.back()->index = ruleList.size() - 1;

		int num = 0;
		if (ruleNameCountMap.count(ruleList.back()->rule_name) != 0) {
			num = ruleNameCountMap[ruleList.back()->rule_name];
		}
		ruleIdToSubId[ruleList.back()->index] = num;
		ruleNameCountMap[ruleList.back()->rule_name] = num + 1;

	}


	vector <string> string_list;

	unordered_map<P_Rule, int> rule_map;
	for (int i1 = 0; i1 < ruleList.size(); i1++) {
		rule_map[ruleList[i1]] = i1;
	}


	//划出所有的终结符号和非终结符号
	log("划出所有的终结符号和非终结符号");
	set<string> zero_terminator;
	parse_all_symbol(terminator, non_terminator, zero_terminator, ruleList);
	for (auto it = terminator.begin(); it != terminator.end(); ++it) {
		ordered_symbols.push_back(*it);
	}
	sort(ordered_symbols.begin(), ordered_symbols.end());
	for (int i1 = 0; i1 < ordered_symbols.size();i1++) {
		symbol_to_id[ordered_symbols[i1]] = i1;
	}

	//计算first函数
	log("计算first函数");
	calculate_f_first(f_first, ruleList, terminator, non_terminator);


	//计算follow函数
	log("计算follow函数");
	unordered_map<string, set<string>> f_follow;
	calculate_f_follow(f_follow, f_first, zero_terminator, ruleList, non_terminator, terminator, start_symbol);



	//构建 LR（0）算法的状态机

	log("构建 LR（0）算法的状态机 begin");
	P_TItemDao tItemDao = TItemDao::getInstance();
	P_TConvertMapDao tConvertMapDao = TConvertMapDao::getInstance();
	if (isChanged) {
		get_items_list_and_convert_map(items_list, non_terminator, zero_terminator, f_first, ruleList, start_symbol);

		vector<unordered_map<string, string>> itemList;
		ostringstream os;
		for (int i1 = 0; i1 < items_list.size();i1++) {
			for (const auto &e:items_list[i1]) {
				itemList.push_back(unordered_map<string, string>());
				itemList.back()["md5"] = md5;
				itemList.back()["itemId"] = std::to_string(i1);
				itemList.back()["ruleId"] = std::to_string(e->rule->index);
				itemList.back()["status"] = std::to_string(e->status);
				
				os.str("");
				auto it=e->end_for_symbol.begin();
				while (it != e->end_for_symbol.end()) {
					os << (*it);
					++it;
					if (it != e->end_for_symbol.end()) {
						os << ",";
					}
				}

				string str = os.str();
				str=replaceAll(str, "'", "&&");
				itemList.back()["endForSymbol"] = replaceAll(str, "&&", "\\'");
				
			}

		}

		vector<unordered_map<string, string>> itemTempList;
		for (int i1 = 0; i1 < itemList.size();i1++) {
			itemTempList.push_back(itemList[i1]);
			if (itemTempList.size()==100) {
				tItemDao->insertList(itemTempList);
				itemTempList.clear();
			}
		}
		if (itemTempList.size()>0) {
			tItemDao->insertList(itemTempList);
			itemTempList.clear();
		}

		vector<unordered_map<string, string>> convertMapList;
		for (const auto &e : convert_map) {
			for (const auto &e2:e.second) {
				convertMapList.push_back(unordered_map<string, string>());
				convertMapList.back()["md5"] = md5;
				convertMapList.back()["srcItem"] = std::to_string(e.first);
				string str = replaceAll(e2.first, "'", "&&");
				convertMapList.back()["move"] = replaceAll(str, "&&", "\\'");
				convertMapList.back()["descItem"] = std::to_string(e2.second);
			}
		}

		vector<unordered_map<string, string>> convertMapTempList;
		for (int i1 = 0; i1 < convertMapList.size(); i1++) {
			convertMapTempList.push_back(convertMapList[i1]);
			if (convertMapTempList.size() == 100) {
				tConvertMapDao->insertList(convertMapTempList);
				convertMapTempList.clear();
			}
		}
		if (convertMapTempList.size() > 0) {
			tConvertMapDao->insertList(convertMapTempList);
			convertMapTempList.clear();
		}


		transfer_map.clear();
		transfer_map["md5"] = oriMD5;
		tItemDao->deleteRecord(transfer_map);
		tConvertMapDao->deleteRecord(transfer_map);


		unordered_map<string, string> map;
		map["fileName"] = rule_file2;
		map["md5"] = md5;

		if (oriMD5 == "0") {
			vector<unordered_map<string, string>> list;
			list.push_back(map);
			tFileMD5Dao->insertList(list);
		}
		else {
			tFileMD5Dao->update(map);
		}

	}
	else {
		transfer_map.clear();
		transfer_map["md5"] = md5;
		result_list.clear();

		tConvertMapDao->queryList(transfer_map, result_list);
		for (auto &e : result_list) {
			int srcItem = atoi(e["srcItem"].c_str());
			string move = e["move"];
			int descItem = atoi(e["descItem"].c_str());
			if (convert_map.count(srcItem) == 0) {
				convert_map[srcItem] = unordered_map<string, int>();
			}
			convert_map[srcItem][move] = descItem;
		}
	}
	
	log("构建 LR（0）算法的状态机 end");

	for (auto e: items_list) {
		sort(e.begin(),e.end(), P_Item_Cmp2());
	}


	log("构建预测表");

	P_TShortCodeDao tShortCodeDao = TShortCodeDao::getInstance();
	P_TMoveTableDao tMoveTableDao = TMoveTableDao::getInstance();
	P_TForecastDao tForecastDao = TForecastDao::getInstance();
	P_TForecast2Dao tForecast2Dao = TForecast2Dao::getInstance();
	P_TRuleDao tRuleDao = TRuleDao::getInstance();

	
	if (isChanged) {
		calculate_forecast_list(items_list, terminator, ruleList, rule_map, convert_map, f_follow);

		vector<unordered_map<string, string>> shortCodeList;
		for (int i1 = 0; i1 < ordered_symbols.size(); i1++) {
			shortCodeList.push_back(unordered_map<string, string>());
			shortCodeList.back()["md5"] = md5;
			shortCodeList.back()["symbol"] = replaceAll(replaceAll(ordered_symbols[i1], "'", "&&"), "&&", "\\'");
			shortCodeList.back()["shortCode"] = std::to_string(i1);
		}

		vector<unordered_map<string, string>> shortCodeTempList;
		for (int i1 = 0; i1 < shortCodeList.size(); i1++) {
			shortCodeTempList.push_back(shortCodeList[i1]);
			if (shortCodeTempList.size() == 100) {
				tShortCodeDao->insertList(shortCodeTempList);
				shortCodeTempList.clear();
			}
		}
		if (shortCodeTempList.size() > 0) {
			tShortCodeDao->insertList(shortCodeTempList);
			shortCodeTempList.clear();
		}


		vector<unordered_map<string, string>> moveTableList;
		for (int i1 = 0; i1 < move_table.size(); i1++) {
			moveTableList.push_back(unordered_map<string, string>());
			moveTableList.back()["md5"] = md5;
			moveTableList.back()["itemId"] = std::to_string(i1);
			moveTableList.back()["interalId"] = std::to_string(move_table[i1]);
		}
		vector<unordered_map<string, string>> moveTableTempList;
		for (int i1 = 0; i1 < moveTableList.size(); i1++) {
			moveTableTempList.push_back(moveTableList[i1]);
			if (moveTableTempList.size() == 100) {
				tMoveTableDao->insertList(moveTableTempList);
				moveTableTempList.clear();
			}
		}
		if (moveTableTempList.size() > 0) {
			tMoveTableDao->insertList(moveTableTempList);
			moveTableTempList.clear();
		}

		vector<unordered_map<string, string>> forecastList;
		for (int i1 = 0; i1 < forecast_list.size(); i1++) {
			for (const auto &e : forecast_list[i1]) {
				forecastList.push_back(unordered_map<string, string>());
				forecastList.back()["md5"] = md5;
				forecastList.back()["interalId"] = std::to_string(i1);
				forecastList.back()["shortCode"] = std::to_string(e.first);
				forecastList.back()["action"] = e.second;
			}

		}
		vector<unordered_map<string, string>> forecastTempList;
		for (int i1 = 0; i1 < forecastList.size(); i1++) {
			forecastTempList.push_back(forecastList[i1]);
			if (forecastTempList.size() == 100) {
				tForecastDao->insertList(forecastTempList);
				forecastTempList.clear();
			}
		}
		if (forecastTempList.size() > 0) {
			tForecastDao->insertList(forecastTempList);
			forecastTempList.clear();
		}

		
		vector<unordered_map<string, string>> ruleList0;
		for (int i1 = 0; i1 < ruleList.size(); i1++) {
			ruleList0.push_back(unordered_map<string, string>());
			ruleList0.back()["md5"] = md5;
			ruleList0.back()["id"] = std::to_string(i1);
			sb.str("");
			for (const auto &e: ruleList[i1]->symbols) {
				sb << e << " ";
			}
			ruleList0.back()["ruleName"] = ruleList[i1]->rule_name;
			ruleList0.back()["rule"] = replaceAll(replaceAll(sb.str(), "'", "&&"), "&&", "\\'");
		}

		if (ruleList0.size() > 0) {
			tRuleDao->insertList(ruleList0);
			ruleList0.clear();
		}
		


		transfer_map.clear();
		transfer_map["md5"] = oriMD5;
		tShortCodeDao->deleteRecord(transfer_map);
		tMoveTableDao->deleteRecord(transfer_map);
		tForecastDao->deleteRecord(transfer_map);
		tForecast2Dao->deleteRecord(transfer_map);
		tRuleDao->deleteRecord(transfer_map);

	}
	else {

		transfer_map.clear();
		transfer_map["md5"] = md5;
		result_list.clear();
		tMoveTableDao->queryList(transfer_map, result_list);
		for (const auto &e : result_list) {
			move_table.push_back(atoi(e.at("interalId").c_str()));
		}
		
		transfer_map.clear();
		transfer_map["md5"] = md5;
		result_list.clear();
		tForecastDao->queryList(transfer_map, result_list);
		for (const auto &e : result_list) {
			if (atoi(e.at("interalId").c_str()) != (forecast_list.size()-1)) {
				int num=atoi(e.at("interalId").c_str()) - (forecast_list.size() - 1);
				for (int i1 = 0; i1 < num;i1++) {
					forecast_list.push_back(unordered_map<int, string>());
				}
			}
			forecast_list.back()[atoi(e.at("shortCode").c_str())] = e.at("action");
		}

	}

	vector<unordered_map<string, string>> solveConflictTableList;
	if (isChanged) {
		
		vector <string> string_list;
		set<string> interalId_set;
		set<string> temp_interalId_set;


		if (solveConflictList.size() > 0) {
			for (const auto &e : solveConflictList) {
				interalId_set.clear();
				string move = "";
				int shortCode = -1;
				
				bool isFirst = true;
				for (const auto &e2 : *e) {
					temp_interalId_set.clear();
					if (startsWith(e2, "s") == 1) {
						string_list.clear();
						transfer_map.clear();
						result_list.clear();
						split(string_list, e2, is_any_of(":"));
						transfer_map["md5"] = md5;
						transfer_map["status"] = std::to_string(atoi(string_list[1].c_str())+1);
						transfer_map["move"] = trim_left_copy(trim_right_copy(string_list[2]));
						transfer_map["move"] = replaceAll(transfer_map["move"], "'", "#");
						transfer_map["move"] = replaceAll(transfer_map["move"], "#", "\\'");
						if (move=="") {
							move = transfer_map["move"];
							shortCode = symbol_to_id[trim_left_copy(trim_right_copy(string_list[2]))];
						}
						transfer_map["ruleName"] = trim_left_copy(trim_right_copy(string_list[3]));
						transfer_map["rule"] = trim_left_copy(trim_right_copy(string_list[4]));
						transfer_map["rule"] = replaceAll(transfer_map["rule"], "'", "#");
						transfer_map["rule"] = replaceAll(transfer_map["rule"], "#", "\\'");
						tForecast2Dao->queryByS(transfer_map, result_list);
						for (auto &e3 : result_list) {
							temp_interalId_set.insert(e3["interalId"]);
						}
					}
					else if (startsWith(e2, "r") == 1) {
						string_list.clear();
						transfer_map.clear();
						result_list.clear();
						split(string_list, e2, is_any_of(":"));
						transfer_map["md5"] = md5;
						transfer_map["move"] = trim_left_copy(trim_right_copy(string_list[1]));
						transfer_map["move"] = replaceAll(transfer_map["move"], "'", "#");
						transfer_map["move"] = replaceAll(transfer_map["move"], "#", "\\'");
						if (move == "") {
							move = transfer_map["move"];
							shortCode = symbol_to_id[trim_left_copy(trim_right_copy(string_list[1]))];
						}
						transfer_map["ruleName"] = trim_left_copy(trim_right_copy(string_list[2]));
						transfer_map["rule"] = trim_left_copy(trim_right_copy(string_list[3]));
						transfer_map["rule"] = replaceAll(transfer_map["rule"], "'", "#");
						transfer_map["rule"] = replaceAll(transfer_map["rule"], "#", "\\'");
						tForecast2Dao->queryByR(transfer_map, result_list);
						for (auto &e3 : result_list) {
							temp_interalId_set.insert(e3["interalId"]);
						}
					}

					if (isFirst) {
						for (auto &e3 : temp_interalId_set) {
							interalId_set.insert(e3);
						}
						isFirst = false;
					}else {

						set<string> del_interalId_set;
						for (auto &e3 : interalId_set) {
							if (temp_interalId_set.count(e3) == 0) {
								del_interalId_set.insert(e3);
							}
						}

						for (auto &e3 : del_interalId_set) {
							interalId_set.erase(e3);
						}

					}


				}
				
				
				for (const auto &e3 : interalId_set) {
					//solveConflictTableList
					ostringstream os;
					solveConflictTableList.push_back(unordered_map<string, string>());
					solveConflictTableList.back()["md5"]= md5;
					solveConflictTableList.back()["interalId"] = e3;
					solveConflictTableList.back()["shortCode"] = std::to_string(shortCode);
					for (const auto &e2 : *e) {
						if (startsWith(e2, "s") == 1) {
							result_list.clear();
							transfer_map.clear();
							transfer_map["md5"] = md5;
							transfer_map["move"] = move;
							transfer_map["interalId"] = e3;
							tForecast2Dao->queryByDescOfS(transfer_map, result_list);


							if (result_list.size()>0) {
								if (os.str() == "") {
									os << "s" << result_list[0]["descItem"];
								}
								else {
									os<<"," << "s" << result_list[0]["descItem"];
								}
							}
						}


						if (startsWith(e2, "r") == 1) {
							result_list.clear();
							transfer_map.clear();
							string_list.clear();
							split(string_list, e2, is_any_of(":"));

							transfer_map["md5"] = md5;
							transfer_map["ruleName"] = trim_left_copy(trim_right_copy(string_list[2]));
							transfer_map["rule"] = trim_left_copy(trim_right_copy(string_list[3]));
							transfer_map["rule"] = replaceAll(transfer_map["rule"], "'", "#");
							transfer_map["rule"] = replaceAll(transfer_map["rule"], "#", "\\'");
							tRuleDao->queryList(transfer_map, result_list);

							if (result_list.size() > 0) {
								if (os.str() == "") {
									os << "r" << result_list[0]["id"];
								}
								else {
									os << "," << "r" << result_list[0]["id"];
								}

							}
						}



					}
					solveConflictTableList.back()["action"] = os.str();
				}

			}
		}

		if (solveConflictTableList.size() > 0) {
			tForecast2Dao->insertList(solveConflictTableList);
			solveConflictTableList.clear();
		}
	}
	else {
		transfer_map.clear();
		transfer_map["md5"] = md5;
		tForecast2Dao->queryList(transfer_map, solveConflictTableList);
	}

	for ( auto &e : solveConflictTableList) {
		forecast_list[atoi(e["interalId"].c_str())][atoi(e["shortCode"].c_str())]= e["action"];
	}

	


	//解决移入-规约冲突
	log("解决移入-规约冲突");


	//if (detect_ambigulous(ruleList, items_list)) {
	//	return -1;
	//}


	return 0;
}

void Lalr::init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter, set<string> &endSymbolSet) {
	Parser::init_total_lex_word_list(compile_file, primarySymbolConverter);

}


void Lalr::init_total_lex_word_list(string compile_file, PrimarySymbolConverter *primarySymbolConverter, int beginIndex, int endIndex) {
	Parser::init_total_lex_word_list(compile_file, primarySymbolConverter, beginIndex, endIndex);

}


Node* Lalr::slr(Env& env, string rootSymbol, int wordListBegId) {

	//vector<P_Lex_Word>  lex_word_list;

	//int wordListId = wordListBegId;
	//for (int i1 = wordListId; i1 < total_lex_word_list.size();i1++) {
	//	const auto &e = total_lex_word_list[i1];
	//	lex_word_list.push_back(e);
	//	if (e->type == "'end'") {
	//		//构造语法树
	//		lex_word_list.pop_back();

	//		Node *node_tree = syntax_analyze(ruleList, terminator, non_terminator, convert_map, lex_word_list);

	//		lex_word_list.clear();
	//		return node_tree;
	//	}
	//}


	return syntax_analyze(ruleList, terminator, non_terminator, convert_map);

}


void Lalr::calculate_f_first(unordered_map<string, set<string>> &f_first, const vector<P_Rule> &ruleList,
	const set<string> &terminator, const set<string> &non_terminator) {
	// 计算first函数

	set<P_Rule> has_calculate_first_set;
	vector<P_Rule> rule_stack;
	set<string> symbol_temp_set;
	set<P_Rule> in_stack_rules;
	for (auto &e : ruleList) {
		if (has_calculate_first_set.count(e) == 0) {

			rule_stack.push_back(e);
			in_stack_rules.insert(e);
			while (rule_stack.size() > 0) {
				P_Rule rule = rule_stack.back();
				bool has_calculate = true;
				P_Rule un_calculate_rule = nullptr;
				symbol_temp_set.clear();



				for (int i1 = 0; i1 < rule->symbols.size(); i1++) {

					if (terminator.count(rule->symbols[i1]) > 0) {
						symbol_temp_set.insert(rule->symbols[i1]);
					}
					else {
						for (auto &e2 : ruleList) {
							if (in_stack_rules.count(e2) == 0 && e2->rule_name == rule->symbols[i1]) {
								if (has_calculate_first_set.count(e2) == 0) {
									has_calculate = false;
									un_calculate_rule = e2;
									break;
								}
								else {
									for (const auto &e3 : e2->first) {
										symbol_temp_set.insert(e3);
									}
								}
							}
						}
					}




					if (!has_calculate) {
						break;
					}

					if (symbol_temp_set.count("0") > 0) {
						if (i1 != (rule->symbols.size() - 1)) {
							symbol_temp_set.erase("0");
						}
					}
					else {
						break;
					}

				}


				if (has_calculate) {
					for (const auto &e3 : symbol_temp_set) {
						rule->first.push_back(e3);
					}
					has_calculate_first_set.insert(rule);
					rule_stack.pop_back();
					in_stack_rules.erase(rule);
				}
				else {
					if (in_stack_rules.count(un_calculate_rule) == 0) {

						for (auto &e2 : ruleList) {
							if (e2->rule_name == un_calculate_rule->rule_name) {
								rule_stack.push_back(e2);
								in_stack_rules.insert(e2);
							}
						}

					}
				}

			}

		}
	}


	for (auto rule : ruleList) {
		f_first[rule->rule_name] = set<string>();
	}

	for (auto rule : ruleList) {
		for (auto s : rule->first) {
			f_first[rule->rule_name].insert(s);
		}
	}

	
#ifdef __PRINT_F_FIRST
	Util::log("f_first");
	for (const auto result : f_first) {
		Util::log(result.first + ":");
		ostringstream tempOS;
		for (auto it = result.second.begin(); it != result.second.end(); ++it) {
			tempOS << *it << ",";
		}
		Util::log(tempOS.str());
	}
	for (const auto &e : non_terminator) {
		if (f_first.find(e) == f_first.end()) {
			Util::log("不存在:" + e);
		}
	}
#endif
}


void Lalr::calculate_f_terminate_inline(string symbol, const vector<P_Rule> &ruleList,
	const set<string> &terminator, const set<string> &non_terminator) {
	set<P_Rule> has_calculate_symbol_set;
	vector<P_Rule> rule_stack;
	set<string> symbol_temp_set;
	set<P_Rule> in_stack_rules;

	unordered_map<P_Rule, set<string>> rule_symbol_map;

	for (auto &e : ruleList) {
		if (e->rule_name == symbol) {
			rule_stack.push_back(e);
			in_stack_rules.insert(e);
		}
	}

	while (rule_stack.size() > 0) {
		P_Rule rule = rule_stack.back();
		bool has_calculate = true;
		P_Rule un_calculate_rule = nullptr;
		symbol_temp_set.clear();

		for (int i1 = 0; i1 < rule->symbols.size(); i1++) {

			if (terminator.count(rule->symbols[i1]) > 0) {
				symbol_temp_set.insert(rule->symbols[i1]);
			}
			else {
				for (auto &e2 : ruleList) {
					if (in_stack_rules.count(e2) == 0 && e2->rule_name == rule->symbols[i1]) {
						if (has_calculate_symbol_set.count(e2) == 0) {
							has_calculate = false;
							un_calculate_rule = e2;
							break;
						}
						else {
							for (const auto &e3 : rule_symbol_map[e2]) {
								symbol_temp_set.insert(e3);
							}
						}
					}
				}
			}

			if (!has_calculate) {
				break;
			}

			if (symbol_temp_set.count("0") > 0) {
				if (i1 != (rule->symbols.size() - 1)) {
					symbol_temp_set.erase("0");
				}
			}
		}

		if (has_calculate) {
			for (const auto &e3 : symbol_temp_set) {
				rule_symbol_map[rule].insert(e3);
			}
			has_calculate_symbol_set.insert(rule);
			rule_stack.pop_back();
			in_stack_rules.erase(rule);
		}
		else {
			if (in_stack_rules.count(un_calculate_rule) == 0) {

				for (auto &e2 : ruleList) {
					if (e2->rule_name == un_calculate_rule->rule_name) {
						rule_stack.push_back(e2);
						in_stack_rules.insert(e2);
					}
				}
			}
		}
	}

	symbol_temp_set.clear();

	for (auto rule : ruleList) {
		if (rule->rule_name == symbol) {
			for (auto s : rule_symbol_map[rule]) {
				symbol_temp_set.insert(s);
			}
		}
	}
	for (const auto &e : symbol_temp_set) {
		Util::log(e);
	}

}




void Lalr::calculate_f_follow(unordered_map<string, set<string>> &f_follow, unordered_map<string, set<string>> &f_first, set<string> &zero_terminator,
	const vector<P_Rule> &ruleList, const set<string> &non_terminator, const set<string> &terminator, string start_symbol) {

	for (const auto &e : non_terminator) {
		f_follow[e] = set<string>();
	}

	f_follow[start_symbol].insert("'$'");

	set<string> has_calculate_follow_set;
	has_calculate_follow_set.insert(start_symbol);

	vector<string> symbol_stack;

	unordered_map<string, set<string>> brother_map;


	for (auto &k : non_terminator) {

		if (has_calculate_follow_set.count(k) == 0) {
			symbol_stack.push_back(k);

			while (symbol_stack.size() > 0) {
				string e = symbol_stack.back();
				bool is_insert_other = false;
				for (int i3 = 0; i3 < ruleList.size(); i3++) {

					auto e2 = ruleList[i3];
					bool is_done = false;
					bool is_match = false;
					for (int i1 = 0; i1 < e2->symbols.size(); i1++) {

						if (e2->symbols[i1] == e) {
							is_match = true;
							if (i1 != (e2->symbols.size() - 1)) {
								bool is_contained_zero_symbol = false;
								for (int i2 = i1 + 1; i2 < e2->symbols.size(); i2++) {

									if (terminator.count(e2->symbols[i2]) > 0) {
										if (e2->symbols[i2] != "0") {
											f_follow[e2->symbols[i1]].insert(e2->symbols[i2]);
										}
										else {
											is_contained_zero_symbol = true;
										}
									}
									else {
										for (const auto &e3 : f_first[e2->symbols[i2]]) {
											if (e3 != "0") {
												f_follow[e2->symbols[i1]].insert(e3);
											}
											else {
												is_contained_zero_symbol = true;
											}

										}
									}


									if (!is_contained_zero_symbol) {
										is_done = true;
										break;
									}
									else {
										if (i2 != (e2->symbols.size() - 1)) {
											is_contained_zero_symbol = false;
										}
									}

								}

								if (is_contained_zero_symbol) {
									if (has_calculate_follow_set.count(e2->rule_name) > 0) {
										for (auto &e3 : f_follow[e2->rule_name]) {
											f_follow[e2->symbols[i1]].insert(e3);
										}
										is_done = true;
									}
									else {
										/*
										if (find(symbol_stack.begin(), symbol_stack.end(), e2->rule_name) != symbol_stack.end()) {
											brother_map[e2->symbols[i1]].insert(e2->rule_name);
											brother_map[e2->rule_name].insert(e2->symbols[i1]);
											is_done = true;
										}
										*/

										auto p = find(symbol_stack.begin(), symbol_stack.end(), e2->rule_name);
										while (p != symbol_stack.end()) {
											brother_map[e2->symbols[i1]].insert(*p);
											brother_map[*p].insert(e2->symbols[i1]);
											++p;
											is_done = true;
										}


									}
								}

							}
							else {
								if (has_calculate_follow_set.count(e2->rule_name) > 0) {
									for (auto &e3 : f_follow[e2->rule_name]) {
										f_follow[e2->symbols[i1]].insert(e3);
									}
									is_done = true;
								}
								else {
									/*
									if (find(symbol_stack.begin(), symbol_stack.end(), e2->rule_name) != symbol_stack.end()) {
										brother_map[e2->symbols[i1]].insert(e2->rule_name);
										brother_map[e2->rule_name].insert(e2->symbols[i1]);
										is_done = true;
									}
									*/

									auto p = find(symbol_stack.begin(), symbol_stack.end(), e2->rule_name);
									while (p != symbol_stack.end()) {
										brother_map[e2->symbols[i1]].insert(*p);
										brother_map[*p].insert(e2->symbols[i1]);
										++p;
										is_done = true;
									}
								}
							}
						}
					}


					if (!is_match) {
						is_done = true;
					}
					if (!is_done) {
						symbol_stack.push_back(e2->rule_name);
						is_insert_other = true;
						break;
					}

				}



				if (!is_insert_other) {
					has_calculate_follow_set.insert(e);
					for (auto &e1 : brother_map[e]) {
						for (auto &e2 : f_follow[e1]) {
							f_follow[e].insert(e2);
						}
					}

					for (auto &e1 : brother_map[e]) {
						f_follow[e1] = f_follow[e];
					}
					symbol_stack.pop_back();
				}


			}

		}
	}





#ifdef __PRINT_F_FOLLOW
	Util::log("f_follow");
	for (const auto result : f_follow) {
		Util::log(result.first + ":");
		ostringstream tempOS;
		for (auto it = result.second.begin(); it != result.second.end(); ++it) {
			tempOS << *it << ",";
		}
		Util::log(tempOS.str());
	}
#endif

}


void Lalr::printGraph(vector<vector<P_Item>> &items_list,
	unordered_map<int, unordered_map<string, int>> &convert_map) {
	set<int> a;
	printGraph(items_list, convert_map, a, true);
}

void Lalr::printGraph(set<int> &itemSet) {
	printGraph(this->items_list, this->convert_map, itemSet, false);
}


void Lalr::printGraph(vector<vector<P_Item>> &items_list,
	unordered_map<int, unordered_map<string, int>> &convert_map,set<int> &itemSet,bool printAll) {
	if (printAll) {
		Util::log("打印转移状态图的点");

		for (int i1 = 0; i1 < items_list.size(); i1++) {
			Util::log(i1 + ":");
			ostringstream tempOS;
			for (auto e : items_list[i1]) {
				tempOS << e->rule->rule_name;
				tempOS << " :";
				for (auto e2 : e->rule->symbols) {
					tempOS << " " << e2;
				}
				tempOS << " " << e->status << " ###";

				for (auto e2 : e->end_for_symbol) {
					tempOS << " " << e2;
				}
				Util::log(tempOS.str());
			}
		}

		Util::log("打印转移状态图的弧");

		for (const auto result : convert_map) {
			Util::log(result.first + ":");
			ostringstream tempOS;
			for (auto it = result.second.begin(); it != result.second.end(); ++it) {
				tempOS << it->first << ":" << it->second << endl;
			}
			Util::log(tempOS.str());
		}
	}
	else {
		Util::log("打印转移状态图的点");
		for (int i1 = 0; i1 < items_list.size(); i1++) {
			if (itemSet.count(i1) > 0) {
				Util::log(i1 + ":");
				ostringstream tempOS;
				for (auto e : items_list[i1]) {
					tempOS << e->rule->rule_name;
					tempOS << " :";
					for (auto e2 : e->rule->symbols) {
						tempOS << " " << e2;
					}
					tempOS << " " << e->status << " ###";

					for (auto e2 : e->end_for_symbol) {
						tempOS << " " << e2;
					}
					Util::log(tempOS.str());
				}
			}
		}
	}

}


void Lalr::printStack(Node* &node_tree) {
	Util::log("深度优先遍历:");
	vector<Node*> item_node_stack2;
	item_node_stack2.push_back(node_tree);
	set<Node*> node_set;
	while (item_node_stack2.size() > 0) {
		Node *present_node = item_node_stack2.back();

		if (present_node->child_node_list.size() > 0 && node_set.count(present_node->child_node_list[0]) == 0) {
			item_node_stack2.push_back(present_node->child_node_list[0]);
		}
		else {
			node_set.insert(present_node);
			Util::log(pointerToString(present_node) +":");
			Util::log("symbol=" + present_node->symbol);
			Util::log("content=" + present_node->content);
			Util::log("offset=" + present_node->offset);
			Util::log("parent=" + pointerToString(present_node->parent));
			Util::log("child_node_list=" + pointerToString(&(present_node->child_node_list)));
			Util::log("");
			item_node_stack2.pop_back();
			if (present_node->parent != nullptr) {
				if ((present_node->offset + 1) < present_node->parent->child_node_list.size()) {
					item_node_stack2.push_back(present_node->parent->child_node_list[present_node->offset + 1]);
				}
			}

		}
	}
}

bool Lalr::shouldBeIgnore(const set<string> &ignore_symbol_set, Node *node, int level) {
	for (int i1 = 1; i1 <= level; i1++) {
		int i2 = i1;

		string s = "";
		Node *present_node = node;
		while (i2 > 0) {
			if (s == "") {
				s = present_node->symbol;
			}
			else {
				s = (present_node->symbol) + "." + s;
			}

			if (present_node->parent != nullptr) {
				present_node = present_node->parent;
				i2--;
			}
			else {
				break;
			}
		}

		if (ignore_symbol_set.count(s) > 0) {
			return true;
		}
	}
	return false;
}

//Ig_TypeParameterList
void Lalr::printStackTree(Node* &node_tree, string ignore_file_path) {

	Util::log("打印语法树:");

	vector <string> string_list;
	set<string> ignore_symbol_set;
	int ignore_symbol_level = 1;
	ifstream input_file;
	input_file.open(ignore_file_path.data());	//rule_file string
	string line;
	while (getline(input_file, line))
	{
		if (startsWith(line, "-") == 1) {
			continue;
		}

		ignore_symbol_set.insert(line);
		string_list.clear();

		vector <string> behaves;
		split(string_list, line, is_any_of("."));
		if (string_list.size() > ignore_symbol_level) {
			ignore_symbol_level = string_list.size();
		}
	}
	input_file.close();


	deque<Node*> item_node_stack2;
	item_node_stack2.push_back(node_tree);
	set<Node*> node_set;
	unordered_map<string, unordered_map<string, int>> plan_map;
	unordered_map<string, Node*> plan2_map;

	ostringstream os;
	const int padding_left = 4;
	const int branch_length = 4;

	//先用深度优先遍历计算要打印的块的长和高
	while (item_node_stack2.size() > 0) {
		Node *present_node = item_node_stack2.back();
		bool ignore_flag = shouldBeIgnore(ignore_symbol_set, present_node, ignore_symbol_level);



		if (!ignore_flag && present_node->child_node_list.size() > 0 && node_set.count(present_node->child_node_list[0]) == 0) {
			item_node_stack2.push_back(present_node->child_node_list[0]);
		}
		else {
			node_set.insert(present_node);

			if (!ignore_flag) {
				os.str("");
				os << present_node;
				string present_str = os.str();
				plan_map[present_str] = unordered_map<string, int>();

				int size1 = present_node->symbol.size() + padding_left;
				int size2 = 0;
				if (present_node->child_node_list.size() > 0) {
					for (const auto &e : present_node->child_node_list) {
						os.str("");
						os << e;
						size2 += plan_map[os.str()]["size_row"];
					}
				}
				plan_map[present_str]["size_row"] = size1 > size2 ? size1 : size2;
				plan2_map[present_str] = present_node;
				item_node_stack2.pop_back();

				size1 = 1;
				size2 = 0;
				if (present_node->child_node_list.size() > 0) {
					for (const auto &e : present_node->child_node_list) {
						os.str("");
						os << e;
						size2 = plan_map[os.str()]["size_col"] > size2 ? plan_map[os.str()]["size_col"] : size2;
					}
					size2 += branch_length;
				}
				plan_map[present_str]["size_col"] = size2 > size1 ? size2 : size1;

				if (present_node->parent != nullptr) {
					if ((present_node->offset + 1) < present_node->parent->child_node_list.size()) {
						item_node_stack2.push_back(present_node->parent->child_node_list[present_node->offset + 1]);
					}
				}

			}
			else {
				item_node_stack2.pop_back();
				if (present_node->parent != nullptr) {
					if ((present_node->offset + 1) < present_node->parent->child_node_list.size()) {
						item_node_stack2.push_back(present_node->parent->child_node_list[present_node->offset + 1]);
					}
				}
			}


		}
	}


	item_node_stack2.push_front(node_tree);
	os.str("");
	os << node_tree;
	plan_map[os.str()]["pos_x"] = 0;
	plan_map[os.str()]["pos_y"] = 0;
	while (item_node_stack2.size() > 0) {
		Node *present_node = item_node_stack2.back();
		if (!shouldBeIgnore(ignore_symbol_set, present_node, ignore_symbol_level)) {
			os.str("");
			os << present_node;
			string present_str = os.str();
			if (present_node->child_node_list.size() > 0) {
				int brother_x_offset = 0;
				for (const auto &e : present_node->child_node_list) {
					os.str("");
					os << e;
					plan_map[os.str()]["pos_x"] = plan_map[present_str]["pos_x"] + brother_x_offset;
					brother_x_offset += plan_map[os.str()]["size_row"];
					plan_map[os.str()]["pos_y"] = plan_map[present_str]["pos_y"] + branch_length;
					item_node_stack2.push_front(e);
				}

			}
			item_node_stack2.pop_back();
		}
		else {
			item_node_stack2.pop_back();
		}

	}


	vector<vector<char>> output;
	os.str("");
	os << node_tree;
	for (int i1 = 0; i1 < plan_map[os.str()]["size_col"]; i1++) {
		output.push_back(vector<char>());
		for (int i2 = 0; i2 < plan_map[os.str()]["size_row"]; i2++) {
			output.back().push_back(' ');
		}
	}



	for (auto &e : plan_map) {

		if (plan2_map.find(e.first) != plan2_map.end()) {

			for (int i1 = 0; i1 < plan2_map[e.first]->symbol.size(); i1++) {
				output[e.second["pos_y"]][e.second["pos_x"] + i1] = plan2_map[e.first]->symbol[i1];
			}

			if (plan2_map[e.first]->child_node_list.size() > 0) {
				output[e.second["pos_y"] + 1][e.second["pos_x"]] = '|';

				int beg_pos = e.second["pos_x"];
				if (plan2_map[e.first]->child_node_list.size() > 0) {
					os.str("");
					for (int i1 = 0; i1 < plan2_map[e.first]->child_node_list.size(); i1++) {
						if (!shouldBeIgnore(ignore_symbol_set, plan2_map[e.first]->child_node_list[i1], ignore_symbol_level)) {
							os << plan2_map[e.first]->child_node_list[i1];
							break;
						}
						if (os.str() != "") {
							beg_pos = plan_map[os.str()]["pos_x"];
						}
					}
				}

				int end_pos = beg_pos;

				if (plan2_map[e.first]->child_node_list.size() > 0) {
					os.str("");
					for (int i1 = plan2_map[e.first]->child_node_list.size() - 1; i1 >= 0; i1--) {
						if (!shouldBeIgnore(ignore_symbol_set, plan2_map[e.first]->child_node_list[i1], ignore_symbol_level)) {
							os << plan2_map[e.first]->child_node_list[i1];
							break;
						}
					}
					if (os.str() != "") {
						end_pos = plan_map[os.str()]["pos_x"];
					}
				}


				for (int i1 = beg_pos; i1 <= end_pos; i1++) {
					output[e.second["pos_y"] + 2][i1] = '-';
				}

				for (int i1 = 0; i1 < plan2_map[e.first]->child_node_list.size(); i1++) {

					if (!shouldBeIgnore(ignore_symbol_set, plan2_map[e.first]->child_node_list[i1], ignore_symbol_level)) {
						os.str("");
						os << plan2_map[e.first]->child_node_list[i1];
						output[e.second["pos_y"] + 3][plan_map[os.str()]["pos_x"]] = '|';
					}

				}

			}

		}

	}


	for (const auto &e : output) {
		ostringstream tempOS;
		for (const auto &e1 : e) {
			tempOS << e1;
		}
		Util::log(tempOS.str());
	}

}


void Lalr::parse_all_symbol(set<string> &terminator, set<string> &non_terminator, set<string> &zero_terminator, const vector<P_Rule> &ruleList) {
	for (auto rule : ruleList) {
		for (auto s : rule->symbols) {
			if (s[0] == '\'') {
				terminator.insert(s);
			}
			else if (s != "0") {
				non_terminator.insert(s);
			}
			else {
				terminator.insert(s);
			}
		}
		if (rule->symbols.size() == 1 && rule->symbols[0] == "0") {
			non_terminator.insert(rule->rule_name);
		}
	}
	terminator.insert("'$'");


	vector<string> stack;
	set<string> in_stack;
	unordered_map<string, bool> zero_map;
	for (const string &e : non_terminator) {

		if (zero_map.count(e) == 0) {

			stack.push_back(e);
			in_stack.insert(e);

			while (stack.size() > 0) {

				string e1 = stack.back();

				set<string> unsolve_set;

				for (auto &rule : ruleList) {

					if (rule->rule_name == e1) {
						bool is_zero = true;
						string unsolve_symbol = "";


						for (auto &e2 : rule->symbols) {
							if (e2 == "0") {

							}
							else if (terminator.count(e2) > 0) {
								is_zero = false;
								break;
							}
							else if (non_terminator.count(e2) > 0) {
								if (zero_map.count(e2) > 0) {
									if (!zero_map[e2]) {
										is_zero = false;
										break;
									}
								}
								else {
									unsolve_symbol = e2;
									break;
								}
							}
						}

						if (unsolve_symbol != ""&&in_stack.count(unsolve_symbol) == 0) {
							unsolve_set.insert(unsolve_symbol);
						}
						else if (is_zero) {
							zero_map[e1] = true;
							break;
						}

					}
				}

				if (unsolve_set.size() > 0) {
					for (const auto &e2 : unsolve_set) {
						stack.push_back(e2);
						in_stack.insert(e2);
					}
				}
				else {
					if (zero_map.count(e1) == 0) {
						zero_map[e1] = false;
					}
					stack.pop_back();
					in_stack.erase(e1);
				}
			}
		}
	}

	for (auto &e : zero_map) {
		if (e.second) {
			zero_terminator.insert(e.first);
		}
	}

#ifdef __PRINT_SYMBOL
	Util::log("终端符号：");
	for (const auto &e : terminator) {
		Util::log(e);
	}
	Util::log(e);

	Util::log("非终端符号：");
	for (const auto &e : non_terminator) {
		Util::log(e);
	}
	Util::log(e);
#endif
}


void Lalr::calculate_first_set(const vector<string> &strArr, set<string> &result_set, unordered_map<string, set<string>> &f_first) {
	result_set.clear();
	bool has_zero = true;
	for (const string &e : strArr) {
		if (startsWith(e, "'")) {
			result_set.insert(e);
			break;
		}
		else {
			result_set.insert(f_first[e].begin(), f_first[e].end());
		}
		if (f_first[e].count("0") == 0) {
			has_zero = false;
			break;
		}
	}

	if (!has_zero) {
		result_set.erase("0");
	}

}

bool Lalr::is_P_Item_equal(const P_Item &c1, const P_Item &c2) {
	if (c1->rule < c2->rule) {
		return false;
	}
	else if (c2->rule < c1->rule) {
		return false;
	}
	else if (c1->status != c2->status) {
		return false;
	}
	else {
		return true;
	}
}






void Lalr::calClosure(vector<P_Item> &_items, set<string> &rule_name_set, const vector<P_Rule> &ruleList,
	const set<string> &non_terminator, unordered_map<string, set<P_Item>> &from_map, set<P_Item, P_Item_Cmp> &_items_set,
	set<P_Item, P_Item_Cmp> &_visited_items_set, const set<string> &zero_terminator) {
	//用于计算闭包
	deque<string> rule_name_deq;


	//	rule_name_set rule_name_deq 用于计算闭包
	for (auto e : rule_name_set) {
		rule_name_deq.push_front(e);
	}

	while (true) {
		while (rule_name_deq.size() > 0) {
			string rule_name = rule_name_deq.back();
			for (auto &e : ruleList) {
				if (e->rule_name == rule_name) {
					if (non_terminator.count(e->symbols[0]) > 0) {

						string rule_first_name = e->symbols[0];

						for (auto e2 : ruleList) {
							if (e2->rule_name == rule_name && e2->symbols[0] == rule_first_name) {
								from_map[rule_first_name].insert(P_Item(new Item(e2, 0)));
							}
						}
						if (rule_name_set.count(rule_first_name) == 0) {
							rule_name_set.insert(rule_first_name);
							rule_name_deq.push_front(rule_first_name);
						}

					}

				}
			}
			rule_name_deq.pop_back();
		}

		bool another_loop = false;
		for (auto &e : ruleList) {
			if (rule_name_set.count(e->rule_name) > 0) {

				for (int i1 = 0; i1 <= e->symbols.size(); i1++) {

					P_Item _p_item(new Item(e, i1));


					ostringstream os;
					os << "Fake_" << "X" << "_" << _p_item->rule->index << "_" << _p_item->status;
					string fakeDymbol = os.str();
					_p_item->end_for_symbol.insert(fakeDymbol);

					if (_items_set.count(_p_item) == 0) {

						_items.push_back(_p_item);
						_items_set.insert(_p_item);
						_visited_items_set.insert(_p_item);
					}

					if (i1 != e->symbols.size()) {
						if (e->symbols[i1] == "0" || non_terminator.count(e->symbols[i1]) > 0 && zero_terminator.count(e->symbols[i1]) > 0) {
							if ((i1 + 1) < e->symbols.size() && non_terminator.count(e->symbols[i1 + 1]) > 0) {
								from_map[e->symbols[i1 + 1]].insert(P_Item(new Item(e, i1 + 1)));
								if (rule_name_set.count(e->symbols[i1 + 1]) == 0) {
									another_loop = true;
									rule_name_set.insert(e->symbols[i1 + 1]);
									rule_name_deq.push_front(e->symbols[i1 + 1]);
								}
							}
						}
						else {
							break;
						}
					}
				}
			}
		}

		if (!another_loop) {
			break;
		}
	}


}



void Lalr::calEndForSymbol(string itemIndex, vector<P_Item> &_items, set<P_Item> &has_calculated_end_for_symbol_set, unordered_map<string, set<P_Item>> &from_map,
	vector<string> &first_input, set<string> _first_set, unordered_map<string, set<string>> &f_first) {

	for (auto &e : _items) {

		if (has_calculated_end_for_symbol_set.count(e) == 0) {
			deque<P_Item> que;
			que.push_back(e);

			while (que.size() > 0) {
				P_Item e4 = que.back();

				bool is_calculat_success = true;
				set<string> result_set;

				if (from_map[e4->rule->rule_name].size() > 0) {

					for (auto &e2 : from_map[e4->rule->rule_name]) {

						for (auto &e3 : _items) {

							if (is_P_Item_equal(e2, e3)) {
								first_input.clear();
								for (int i2 = e3->status + 1; i2 < e3->rule->symbols.size(); i2++) {
									first_input.push_back(e3->rule->symbols[i2]);
								}
								calculate_first_set(first_input, _first_set, f_first);


								if (_first_set.size() == 0 || _first_set.count("0") != 0) {
									_first_set.erase("0");

									if (has_calculated_end_for_symbol_set.count(e3) != 0) {
										_first_set.insert(e3->end_for_symbol.begin(), e3->end_for_symbol.end());
										result_set.insert(_first_set.begin(), _first_set.end());
									}
									else {
										que.push_back(e3);
										is_calculat_success = false;
									}


								}
								else {
									result_set.insert(_first_set.begin(), _first_set.end());
								}
							}
							if (!is_calculat_success) {
								break;
							}

						}
						if (!is_calculat_success) {
							break;
						}
					}
					if (is_calculat_success) {
						e4->end_for_symbol.insert(result_set.begin(), result_set.end());

						que.pop_back();
						has_calculated_end_for_symbol_set.insert(e4);
					}

				}

			}

		}
	}
}




void Lalr::refreshEndForSymbolFlow(vector<vector<P_Item>>  &items_list_temp) {
	bool isChange = true;
	deque<int> fakeSymbol_deq;
	set<int> fakeSymbol_set;
	unordered_map<string,set<string>> fakeSymbolMap;
	

	while (isChange) {
		isChange = false;
		fakeSymbol_set.clear();

		fakeSymbol_deq.push_front(0);
		fakeSymbol_set.insert(0);

		while (fakeSymbol_deq.size() > 0) {
			int itemNumber = fakeSymbol_deq.back();
			for (const auto &e : items_list_temp[itemNumber]) {
				ostringstream os;
				os << "Fake_" << itemNumber << "_" << e->rule->index << "_" << e->status;
				string fakeSymbol = os.str();
				for (const auto &e2 : items_list_temp[itemNumber]) {
					if (e2->end_for_symbol.count(fakeSymbol) > 0) {
						int originNum = e2->end_for_symbol.size();
						e2->end_for_symbol.insert(e->end_for_symbol.begin(), e->end_for_symbol.end());
						if (originNum != e2->end_for_symbol.size()) {
							isChange = true;
						}
					}
				}

			}


			for (const auto &e : items_list_temp[itemNumber]) {
				if (e->status!=e->rule->symbols.size()&&convert_map[itemNumber].count(e->rule->symbols[e->status]) > 0) {


					int nextItemNumber = convert_map[itemNumber][e->rule->symbols[e->status]];
					bool isChange2 = false;


					for (const auto &e2 : items_list_temp[nextItemNumber]) {
						if (e2->rule->index== e->rule->index&&e2->status==(e->status+1)) {
							int originNum = e2->end_for_symbol.size();
							e2->end_for_symbol.insert(e->end_for_symbol.begin(), e->end_for_symbol.end());
							if (originNum != e2->end_for_symbol.size()) {
								isChange = true;
								isChange2 = true;
							}
						}
					}


					if (fakeSymbol_set.count(nextItemNumber)==0||isChange2) {
						fakeSymbol_deq.push_front(nextItemNumber);
						fakeSymbol_set.insert(nextItemNumber);
					}
						

					

				}
			}
			
			fakeSymbol_deq.pop_back();

		}



	}


}



/*
items_list 项集


*/
void Lalr::get_items_list_and_convert_map(vector<vector<P_Item>> &items_list,
	const set<string> &non_terminator, const set<string> &zero_terminator, unordered_map<string, set<string>> &f_first, const vector<P_Rule> &ruleList, const string start_symbol) {


	unordered_map<int, unordered_map<string, int>> reverse_convert_map;


	vector<P_Item> items0;
	items_list.push_back(items0);

	//用于计算闭包
	deque<string> rule_name_deq;
	set<string> rule_name_set;
	//用于计算向前看符号
	unordered_map<string, set<P_Item>> from_map;

	//_items_set _visited_items_set 用于验证是否存在二义性
	set<P_Item, P_Item_Cmp> _items_set;
	set<P_Item, P_Item_Cmp> _visited_items_set;

	//first_input _first_set has_calculated_end_for_symbol_set 用于计算 end_for_symbol_set
	vector<string> first_input;
	set<string> _first_set;
	set<P_Item> has_calculated_end_for_symbol_set;


	for (const auto &e : ruleList) {
		if (e->rule_name == start_symbol) {
			_first_set.clear();
			_first_set.insert("'$'");
			ostringstream os;
			os<< "Fake_" << 0 << "_" << e->index << "_" << 0;
			string fakeDymbol = os.str();
			_first_set.insert(fakeDymbol);
			P_Item _p_item(new Item(e, 0, _first_set));
			has_calculated_end_for_symbol_set.insert(_p_item);
			items_list[0].push_back(_p_item);
			_items_set.insert(_p_item);
			_visited_items_set.insert(_p_item);
			rule_name_set.insert(_p_item->rule->symbols[_p_item->status]);

			set<P_Item> from_set;
			from_set.insert(_p_item);
			from_map[_p_item->rule->symbols[_p_item->status]] = from_set;

		}
	}


	//	rule_name_set rule_name_deq 用于计算闭包

	calClosure(items_list[0], rule_name_set, ruleList, non_terminator, from_map, _items_set, _visited_items_set, zero_terminator);
	//计算 end_for_symbol
	calEndForSymbol("0", items_list[0], has_calculated_end_for_symbol_set, from_map, first_input, _first_set, f_first);


	for (const auto &e : items_list[0]) {
		set<string> eraseSet;
		set<string> insertSet;
		for (const auto &e2 : e->end_for_symbol) {
			if (startsWith(e2, "Fake_X_") == 1) {
				string s=replaceAll(e2, "X", std::to_string(0));
				insertSet.insert(s);
				eraseSet.insert(e2);
			}
		}
		for (const auto &e2 : eraseSet) {
			e->end_for_symbol.erase(e2);
		}
		e->end_for_symbol.insert(insertSet.begin(), insertSet.end());
	}


	rule_name_set.clear();


	set<int> status_set;
	deque<int> status_que;
	status_que.push_front(0);


	set<string> move_symbol_set;




	//构造状态转移图
	while (status_que.size() > 0) {
		int status_number = status_que.back();
		//收集所有移动符号
		for (P_Item &e : items_list[status_number]) {
			if (e->rule->symbols.size() > e->status) {
				move_symbol_set.insert(e->rule->symbols[e->status]);
			}
		}
		move_symbol_set.erase("0");
		from_map.clear();
		has_calculated_end_for_symbol_set.clear();

		if (convert_map.find(status_number) == convert_map.end()) {
			convert_map[status_number] = unordered_map<string, int>();
		}
		for (string symble : move_symbol_set) {
			vector<P_Item> _items;
			_items_set.clear();
			bool is_final_item = false;
			for (P_Item &e : items_list[status_number]) {
				if (e->rule->symbols.size() > e->status) {
					if (e->rule->symbols[e->status] == symble) {
						P_Item _p_item(new Item(e->rule, e->status + 1, e->end_for_symbol));

						ostringstream os;
						os << "Fake_" << "X" << "_" << _p_item->rule->index << "_" << _p_item->status;
						string fakeDymbol = os.str();
						_p_item->end_for_symbol.insert(fakeDymbol);

						has_calculated_end_for_symbol_set.insert(_p_item);
						if (_p_item->rule->rule_name == start_symbol && _p_item->status == 1) {
							is_final_item = true;
						}
						_items.push_back(_p_item);

						if (_items_set.count(_p_item) == 0) {
							_items_set.insert(_p_item);
							_visited_items_set.insert(_p_item);
						}

					}
				}
			}




			for (auto e : _items) {
				if (e->rule->symbols.size() > e->status) {
					rule_name_set.insert(e->rule->symbols[e->status]);

					from_map[e->rule->symbols[e->status]].insert(e);

				}
			}


			calClosure(_items, rule_name_set, ruleList, non_terminator, from_map, _items_set, _visited_items_set, zero_terminator);
			//计算 end_for_symbol
			calEndForSymbol("X", _items, has_calculated_end_for_symbol_set, from_map, first_input, _first_set, f_first);


			//判断是否本次item是否已经存在
			bool isExist = false;
			int items_list_index = -1;
			for (int i1 = 0; i1 < items_list.size(); i1++) {
				if (items_list[i1].size() == _items.size()) {
					bool flag = true;
					for (auto &e : items_list[i1]) {

						bool isMatch = false;
						for (const auto &e2 : _items_set) {
							if (*e2 == *e) {
								isMatch = true;
								break;
							}
						}
						if (!isMatch) {
							flag = false;
							break;
						}


					}
					if (flag) {
						items_list_index = i1;
						isExist = true;
						break;
					}
				}
			}


			//

			if (!isExist) {
				
				for (const auto &e : _items) {
					set<string> eraseSet;
					set<string> insertSet;
					for (const auto &e2 : e->end_for_symbol) {
						if (startsWith(e2, "Fake_X_") == 1) {
							string s = replaceAll(e2, "X", std::to_string(items_list.size()));
							insertSet.insert(s);
							eraseSet.insert(e2);
						}
					}
					for (const auto &e2 : eraseSet) {
						e->end_for_symbol.erase(e2);
					}
					e->end_for_symbol.insert(insertSet.begin(), insertSet.end());
				}



				

				items_list.push_back(_items);
				status_que.push_front(items_list.size() - 1);
				items_list_index = items_list.size() - 1;


				if (is_final_item) {
					if (convert_map.find(items_list_index) == convert_map.end()) {
						convert_map[items_list_index] = unordered_map<string, int>();
					}
					convert_map[items_list_index]["'$'"] = -1;
				}
			}
			else {

				for (const auto &e1 : _items) {
					for (const auto &e : items_list[items_list_index]) {
						if (e1 == e) {
							e->end_for_symbol.insert(e1->end_for_symbol.begin(), e1->end_for_symbol.end());
							break;
						}
					}
				}


			}

			convert_map[status_number][symble] = items_list_index;
			reverse_convert_map[items_list_index][symble] = status_number;
			rule_name_deq.clear();
			rule_name_set.clear();
		}





		move_symbol_set.clear();
		status_que.pop_back();
	}

	/*
	_items_set.clear();
	P_Item p_search_item(new Item());111111111111111111111111111111111111111111111111111111111
	for (const auto &e : ruleList) {
		p_search_item->rule = e;
		for (int i1 = 0; i1 <= e->symbols.size(); i1++) {
			p_search_item->status = i1;
			if (_visited_items_set.count(p_search_item) == 0) {
				_items_set.insert(P_Item(new Item(*(p_search_item.get()))));
			}
		}
	}


		if (_items_set.size() > 0) {
			Util::log("存在自由rule:");
			int i1 = 0;
			
			for (const auto &e : _items_set) {
				Util::log(i1 + ":");
				ostringstream tempOS;
				tempOS << e->rule->rule_name;
				tempOS << " :";
				for (auto e2 : e->rule->symbols) {
					tempOS << " " << e2;
				}
				tempOS << " " << e->status;
				Util::log(tempOS.str());
				i1++;
			}
			throw;
		}
	*/

	refreshEndForSymbolFlow(items_list);


	for (const auto &e : items_list) {
		for (auto &e1 : e) {
			set<string> rmSet;
			for (auto &e2 : e1->end_for_symbol) {
				if (startsWith(e2,"Fake_")==1) {
					rmSet.insert(e2);
				}
			}

			for (auto &e2 : rmSet) {
				e1->end_for_symbol.erase(e2);
			}
		}
	}

#ifdef __PRINT_GRAPH
	printGraph(items_list, convert_map);
#endif

#ifdef __CHECK_CONFILCT
	for (int i1 = 0; i1 < items_list.size(); i1++) {
		const auto &e1 = items_list[i1];
		set<string> checkSet;
		for (const auto &e2 : e1) {
			if (e2->status == e2->rule->symbols.size()) {
				int num1 = checkSet.size();
				int num2 = e2->end_for_symbol.size();
				if (e2->end_for_symbol.count("'$'")==1) {
					num2--;
				}
				checkSet.insert(e2->end_for_symbol.begin(), e2->end_for_symbol.end());
				checkSet.erase("'$'");
				if (checkSet.size() < (num1 + num2)) {
					Util::log(string("item" + i1) + ":" + (e2->rule->index + "存在规约-规约冲突"));
					for(const auto &e3:e2->end_for_symbol) {
						if (e3=="'$'") {
							continue;
						}
						for (const auto &e4 : e1) {
							if (e4->status != e4->rule->symbols.size()) {
								continue;
							}
							if (*e4 == *e2) {
								break;
							}
							if (e4->end_for_symbol.count(e3)>0) {
								Util::log((e3 + ",") + std::to_string(e4->rule->index));
							}
						}
					}

				}
			}
		}
	}
#endif




}


bool Lalr::detect_ambigulous(const vector<P_Rule> &ruleList, const vector<vector<P_Item>> items_list) {
	bool flag = false;
	set<int> item_set;
	set<int> rule_set;
	for (int i1 = 0; i1 < move_table.size(); i1++) {
		const auto e1 = forecast_list[move_table[i1]];
		for (auto &e2 : e1) {
			if (e2.first!=-1 &&ordered_symbols[e2.first] == "0") {
				continue;
			}
			if (e2.second.find(",") != string::npos) {

				flag = true;
				Util::log(string("存在二义性:" + i1) + "," + (ordered_symbols[e2.first] + ":" + e2.second));
				item_set.insert(i1);
				vector <string> string_list;
				split(string_list, e2.second, is_any_of(","));
				for (const auto &e : string_list) {
					if (e[0] == 's') {
						item_set.insert(atoi(e.substr(1).c_str()));
					}
					else {
						rule_set.insert(atoi(e.substr(1).c_str()));
					}
				}

			}
		}
	}
	if (flag) {
		Util::log("打印转移状态图的点");
		for (const int &i1 : item_set) {
			Util::log(i1 + ":");
			for (auto e : items_list[i1]) {
				ostringstream tempOS;
				tempOS << e->rule->rule_name;
				tempOS << " :";
				for (auto e2 : e->rule->symbols) {
					tempOS << " " << e2;
				}
				tempOS << " " << e->status;
				Util::log(tempOS.str());
			}
		}

		Util::log("打印文法:");
		for (const int &i1 : rule_set) {
			auto &rule = ruleList[i1];
			Util::log(i1 + ":");
			ostringstream tempOS;
			tempOS << rule->rule_name;
			tempOS << " :";
			for (auto e2 : rule->symbols) {
				tempOS << " " << e2;
			}
			Util::log(tempOS.str());
		}

	}

	return flag;
}



void Lalr::calculate_forecast_list(const vector<vector<P_Item>> &items_list, const set<string> &terminator, vector<P_Rule> &ruleList, unordered_map<P_Rule, int> &rule_map,
	unordered_map<int, unordered_map<string, int>> &convert_map, unordered_map<string, set<string>> &f_follow) {
	for (int i1 = 0; i1 < items_list.size(); i1++) {
		unordered_map<int, string> _map;
		vector <string> string_list;
		for (auto &e1 : terminator) {
			string s = "";
			string r = "";
			if (convert_map[i1].find(e1) != convert_map[i1].end()) {
				s = "s" + to_string(convert_map[i1][e1]);
			}

			for (const auto &e2 : items_list[i1]) {

				if (e2->end_for_symbol.count(e1) > 0 && e2->status == e2->rule->symbols.size()
					&& f_follow[e2->rule->rule_name].count(e1) > 0) {

#ifdef __ALLOW_AMBIGULOUS
					if (r == "") {
						r = "r" + to_string(rule_map[e2->rule]);
					}
#else
					if (r == "") {
						r = "r" + to_string(rule_map[e2->rule]);
					}
					else {
						r += ",r" + to_string(rule_map[e2->rule]);
					}
#endif
				}
			}


#ifdef __ALLOW_AMBIGULOUS
		if (s == "") {
				s = r;
		}
#else
		if (s == "") {
			s = r;
		}
		else if (r != "") {
			s += "," + r;
		}
#endif


			if (s != "") {
				if (s == "s-1"&&r == "r0") {
					s = "acc";
				}
				_map[symbol_to_id[e1]] = s;
			}
		}




		//专门针对 0 和 $ begin
		string r = "";
		for (const auto &e2 : items_list[i1]) {
			if ((e2->end_for_symbol.count("0") > 0 || e2->end_for_symbol.count("'$'") > 0) && e2->status == e2->rule->symbols.size()) {
#ifdef __ALLOW_AMBIGULOUS

				if (r == "") {
					r = "r" + to_string(rule_map[e2->rule]);
				}

#else
				if (r == "") {
					r = "r" + to_string(rule_map[e2->rule]);
				}
				else {
					r += ",r" + to_string(rule_map[e2->rule]);
				}
#endif
			}
		}


		if (r != "") {
			if (r == "r0") {
				r = "acc";
			}
			_map[symbol_to_id["0"]] = r;
			_map[symbol_to_id["'$'"]] = r;
		}
		//专门针对 0 和 $ end
		simplifyMap(_map);

		int index = -1;
		for (int i2 = 0; i2 < forecast_list.size(); i2++) {
			if (is_map_same(forecast_list[i2], _map)) {
				index = i2;
				break;
			}
		}

		if (index == -1) {
			forecast_list.push_back(_map);
			index = forecast_list.size() - 1;
		}
		//move_table[i1] = index;
		move_table.push_back(index);

	}

#ifdef __PRINT_FORECAST

	for (int i1 = 0; i1 < move_table.size(); i1++) {
		Util::log(i1 + ":");
		for (const auto &e : forecast_list[move_table[i1]]) {
			if (e.first == -1) {
				Util::log("any" + ":"+ e.second);
			}
			else {
				Util::log(ordered_symbols[e.first] + ":" + e.second);
			}
			
		}
	}

#endif
}


void Lalr::simplifyMap(unordered_map<int,string> &map) {
	unordered_map<string, int> action_count_map;

	int normal_action_count = 0;
	for (const auto &e: map) {
		if (action_count_map.count(e.second) == 0) {
			action_count_map[e.second] = 0;
		}
		action_count_map[e.second] = action_count_map[e.second] + 1;
		normal_action_count++;
	}
	int error_action_count = terminator.size() - normal_action_count;
	

	int max = 0;
	string action;
	for (const auto &e: action_count_map) {
		if (e.second>max) {
			action = e.first;
			max= e.second;
		}
	}
	if (error_action_count > max) {
		max = error_action_count;
		action = "";
	}
	else {
		set<int> _set;
		for (const auto &e : map) {
			if (e.second == action) {
				_set.insert(e.first);
			}
		}

		for (const auto &e : _set) {
			map.erase(e);
		}
	}
	map[-1] = action;

}

bool Lalr::is_map_same(unordered_map<int,string> &map1, unordered_map<int, string> &map2) {
	if (map1.size() != map2.size()) {
		return false;
	}
	else {
		for (const auto &e : map1) {
			if (map2.count(e.first)==0 || map2[e.first] != e.second) {
				return false;
			}
		}
		return true;
	}
}

Node* Lalr::syntax_analyze(const vector<P_Rule> &ruleList, set<string> &terminator, set<string> &non_terminator,
	unordered_map<int, unordered_map<string, int>> &convert_map) {
	struct ItemNode {
		Node *node;
		int item_status;
	};

	typedef std::shared_ptr<ItemNode> P_ItemNode;

	vector<P_ItemNode> item_node_stack1;
	item_node_stack1.push_back(P_ItemNode(new ItemNode()));
	item_node_stack1[0]->node = nullptr;
	item_node_stack1[0]->item_status = 0;

	Node* resultTree = nullptr;
	bool finished_flag = false;
	bool unexception_input = false;
	int wordListId = 0;
	int _lineNum = 0;
	vector <string> strs;
	//auto p_input = input.begin();
	int wordId = word_list_beg;
	//auto p_input = _total_lex_word_list[word_list_beg];
	//word_list_beg _total_lex_word_list
#ifdef __PRINT_PARSE_PROCESS
	if (switchParseProcess) {
		Util::log("打印过程");
	}
#endif
	while (!finished_flag) {

		P_ItemNode top_item = item_node_stack1.back();

		string input_type;
		string action;
		if (!unexception_input) {

			if (wordId>= word_list_beg && wordId <=word_list_end) {
				input_type = _total_lex_word_list[wordId]->type;
			}

			else {
				input_type = "'$'";
			}

		}
		else {
			input_type = "'$'";
		}

		if (forecast_list[move_table[top_item->item_status]].count(symbol_to_id[input_type]) == 0) {
			action = forecast_list[move_table[top_item->item_status]][-1];
		}
		else {
			action = forecast_list[move_table[top_item->item_status]][symbol_to_id[input_type]];
		}
		
		if (action.find(",")>0) {
			strs.clear();
			split(strs, action, is_any_of(","));
			action = strs[0];
		}

#ifdef __PRINT_PARSE_PROCESS
		//if (switchParseProcess) {
		if (true) {
			string top_symbol = "";
			int top_status = 0;
			if (top_item->node != nullptr) {
				top_symbol = top_item->node->symbol;
				top_status = top_item->item_status;
			}
			log(std::to_string(top_status) + "," + top_symbol + "," + action);
		}
#endif

		if (action == "acc") {
			resultTree = top_item->node;
			
			finished_flag = true;
		}
		else if (action[0] == 's') {
			item_node_stack1.push_back(P_ItemNode(new ItemNode()));
			Node *node = new Node();
			node->symbol = _total_lex_word_list[wordId]->type;
			node->content = _total_lex_word_list[wordId]->content;
			node->index = wordListId;
			node->lineNum = _total_lex_word_list[wordId]->lineNum;
			node->parent = nullptr;
			node->offset = 0;
			item_node_stack1.back()->node = node;
			item_node_stack1.back()->item_status = atoi(action.substr(1).c_str());
			++wordId;
			++wordListId;
			_lineNum = node->lineNum;
			log("压入：" + node->symbol);
		}
		else if (action[0] == 'r') {
			P_Rule best_rule = ruleList[atoi(action.substr(1).c_str())];
			Node *parent_node = new Node();
			parent_node->symbol = best_rule->rule_name;
			parent_node->ruleId = atoi(action.substr(1).c_str());
			parent_node->offset = 0;
			parent_node->parent = nullptr;


			unordered_map<int, int> map;
			int i2 = item_node_stack1.size() - 1;
			if (best_rule->symbols.size() > 0) {
				for (int i1 = (best_rule->symbols.size() - 1); i1 >= 0; i1--) {
					if (best_rule->symbols[i1] == "0") {
						continue;
					}
					else if (item_node_stack1[i2]->node != nullptr&&best_rule->symbols[i1] == item_node_stack1[i2]->node->symbol) {
						map[i1] = i2;
						i2--;
					}
					else {
						continue;
					}
				}
				i2++;
			}


			Node *pre_child_node = nullptr;
			int emptyBeg = -1;
			int emptyEnd = -1;
			for (int i1 = 0; i1 < best_rule->symbols.size(); i1++) {
				if (map.count(i1) == 0) {
					//pre_child_node = new Node();
					//pre_child_node->symbol = best_rule->symbols[i1];
					//pre_child_node->content = "";
					//pre_child_node->index = -1;

					if (emptyBeg == -1) {
						emptyBeg = i1;
						emptyEnd = i1;
					}
					else {
						emptyEnd = i1;
					}

				}
				else {
					pre_child_node = item_node_stack1[map[i1]]->node;


					if (emptyBeg != -1) {
						for (int i2 = emptyBeg; i2 <= emptyEnd; i2++) {
							Node *pre_child_node2 = create_empty_tree(best_rule->symbols[i2], pre_child_node->index, pre_child_node->lineNum);
							pre_child_node2->offset = i2;
							pre_child_node2->parent = parent_node;
							parent_node->child_node_list.push_back(pre_child_node2);
						}
					}
					pre_child_node->offset = i1;
					pre_child_node->parent = parent_node;
					parent_node->child_node_list.push_back(pre_child_node);
					emptyBeg = -1;
					emptyEnd = -1;

				}
			}

			if (emptyBeg != -1) {
				for (int i2 = emptyBeg; i2 <= emptyEnd; i2++) {
					Node *pre_child_node2 = create_empty_tree(best_rule->symbols[i2], wordListId, _lineNum);
					pre_child_node2->offset = i2;
					pre_child_node2->parent = parent_node;
					parent_node->child_node_list.push_back(pre_child_node2);
				}
			}

			if (parent_node->child_node_list.size() > 0) {
				parent_node->index = parent_node->child_node_list[0]->index;
				parent_node->lineNum = parent_node->child_node_list[0]->lineNum;
			}
			



			int present_stack_size = item_node_stack1.size();
			for (; i2 < present_stack_size; i2++) {
				item_node_stack1.pop_back();
			}


			if (item_node_stack1.size() > 0) {
				top_item = item_node_stack1.back();
				item_node_stack1.push_back(P_ItemNode(new ItemNode()));
				item_node_stack1.back()->node = parent_node;
				item_node_stack1.back()->item_status = convert_map[top_item->item_status][parent_node->symbol];
			}
			else {
				item_node_stack1.push_back(P_ItemNode(new ItemNode()));
				item_node_stack1.back()->node = parent_node;
				item_node_stack1.back()->item_status = convert_map[0][parent_node->symbol];
			}
			log("弹出2：" + item_node_stack1.back()->node->symbol);
		}
		else {
			if (!switchAllowIllegalInput) {
				#ifdef __PRINT_NOT_SILENT
								if (switchNotSilent) {

									log(string("遇到意外输入:item_status:" + top_item->item_status) + ",input_content:" + _total_lex_word_list[wordId]->content);
									log(string("遇到意外输入:item_status:" + top_item->item_status) + ",input_type:" + input_type);
									log(string("line:" + _total_lex_word_list[wordId]->lineNum) + string(",col:" + _total_lex_word_list[wordId]->colNum));
								}

				#endif

				//别忘了去实现内存，暂时先不写
				break;
			}
			else {
				if (!unexception_input) {
					unexception_input = true;
				}
				else {
					item_node_stack1.pop_back();
				}
				
			}

		}
#ifdef __PRINT_PARSE_PROCESS
		if (switchParseProcess) {
			ostringstream teamOS;
			for (auto &e : item_node_stack1) {
				if (e->node != nullptr) {
					teamOS << e->node->symbol << ",";
				}
			}
			Util::log(teamOS.str());
		}
#endif

	}

	if (resultTree!=nullptr) {

		Node *parent_node = new Node();
		parent_node->symbol = "ele_begin";

		for (int i1 = 0; i1 < ruleList.size();i1++) {
			if (ruleList[i1]->rule_name == "ele_begin") {
				parent_node->ruleId = i1;
			}
		}

		parent_node->offset = 0;
		parent_node->parent = nullptr;

		resultTree->parent = parent_node;
		parent_node->child_node_list.push_back(resultTree);

		resultTree = parent_node;
	}

	return resultTree;
}


Node * Lalr::create_empty_tree(string & symbol,int index0,int lineNum) {

	if (symbol=="0") {
		Node * emptyNode = new Node();
		emptyNode->content = "";
		emptyNode->index = index0;
		emptyNode->lineNum = lineNum;
		emptyNode->symbol = "";
		emptyNode->symbol = "0";
		return emptyNode;
	}
	else {
		int bestRuleId = -1;
		int length = 9999;
		for (int i1 = 0; i1 < ruleList.size(); i1++) {
			if (ruleList[i1]->rule_name == symbol) {
				if (ruleList[i1]->symbols.size() == 1 && ruleList[i1]->symbols[0] == "0") {
					bestRuleId = i1;
					length = 1;
					break;
				}
				else if (ruleList[i1]->symbols.size() > length) {
					continue;
				}
				else {
					bool isEmptyRule = true;
					for (const auto &e : ruleList[i1]->symbols) {
						if (startsWith(e, "'") == 1 || e != "0"&& f_first[e].find("0") == f_first[e].end()) {
							isEmptyRule = false;
							break;
						}
					}
					if (isEmptyRule) {
						bestRuleId = i1;
						length = ruleList[i1]->symbols.size();
					}
				}
			}
		}

		if (bestRuleId != -1) {
			Node * emptyNode = new Node();
			emptyNode->content = "";
			emptyNode->index = index0;
			emptyNode->lineNum = lineNum;
			emptyNode->symbol = symbol;
			emptyNode->ruleId = bestRuleId;

			int index = 0;
			for (auto &e : ruleList[bestRuleId]->symbols) {
				Node * child = create_empty_tree(e, index0, lineNum);
				if (child!=nullptr) {
					child->offset = index;
					child->parent = emptyNode;
				}
				index++;
				emptyNode->child_node_list.push_back(child);
			}
			return emptyNode;
		}
		else {
			return nullptr;
		}

	}












}



Lalr::Lalr() {

}


Lalr::~Lalr() {
}

/**

深度优先遍历:
T
|
----------------------------
|                          |
B                          C
|                          |
-                          ---------------------------
|                          |      |           |      |
'simple-type-specifier'    '['    'number'    ']'    C
													 |
													 ---------------------------
													 |      |           |      |
													 '['    'number'    ']'    C
																			   |
																			   -
																			   |
																			   0

ele_begin : T		{$$=$1;}
T : B C			{$2.next=$1;$$=$2;}
B : 'simple-type-specifier'	{Type* type=new Type($1,Tag::BASIC,4);$$=type;}
C : 0	{$$=$$.next;}
C : '[' 'number' ']' C	{$4.next=$$.next;$$=new Array(atoi(($2).c_str()),(Type*)$4);}

3
4
*/