#include "Parser.h"
#include"symbols\PrimarySymbolConverter.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include"SLR\NodeValue.h"
#include "Util/Util.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include"SLR\SDT_Factory.h"
using namespace std;
using namespace boost;

Parser::Parser() {}

Parser::~Parser() {}


void Parser::log(const string& s) {
	if (logSwitch) {
		Util::log(s);
	}
}

int Parser::startsWith(const string& s, const string& sub) {
	if (sub.length() > s.length()) {
		return 0;
	}
	return s.find(sub) == 0 ? 1 : 0;
}


int Parser::endsWith(const string& s, const string& sub) {
	if (sub.length() > s.length()) {
		return 0;
	}
	return s.rfind(sub) == (s.length() - sub.length()) ? 1 : 0;
}


string Parser::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}



void Parser::init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, set<string> &endSymbolSet) {
	total_lex_word_list.clear();

	//定义上下文
	//log("定义上下文");

	//生成输入
	//log("生成输入");

	vector<P_Lex_Word>  _total_lex_word_list;
	vector <string> behaves;
	_total_lex_word_list.clear();
	word_parser(compile_file, _total_lex_word_list);

	for (P_Lex_Word &e : _total_lex_word_list) {
		auto p = P_Lex_Word(new Lex_Word());
		primarySymbolConverter.convert(*e, *p);
		if (p->type != "0") {
			total_lex_word_list.push_back(p);
			/*
			if (endSymbolSet.count(p->type) > 0) {
				break;
			}
			*/

			bool isMatch = false;
			for (const auto &e2 : endSymbolSet) {
				bool isMatch2 = true;

				behaves.clear();
				split(behaves, e2, is_any_of(","));
				if (total_lex_word_list.size() < behaves.size()) {
					isMatch2 = false;
				}
				else {
					for (int i1 = behaves.size() - 1, i2 = total_lex_word_list.size() - 1; i1 >= 0; i1--, i2--) {
						if (behaves[i1] != total_lex_word_list[i2]->type) {
							isMatch2 = false;
							break;
						}
					}
				}

				if (isMatch2) {
					isMatch = true;
					break;
				}

			}

			if (isMatch) {
				break;
			}
		}
	}
}



void Parser::init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, int begIndex, int endIndex) {
	total_lex_word_list.clear();

	//定义上下文
	log("定义上下文");

	//生成输入
	log("生成输入");

	vector<P_Lex_Word>  _total_lex_word_list;
	vector <string> behaves;
	_total_lex_word_list.clear();
	word_parser(compile_file, _total_lex_word_list);
	int index = 0;
	for (P_Lex_Word &e : _total_lex_word_list) {
		auto p = P_Lex_Word(new Lex_Word());
		primarySymbolConverter.convert(*e, *p);
		if (p->type != "0") {
			if (endIndex == -1) {
				if (p->index >= begIndex) {
					total_lex_word_list.push_back(p);
				}
			}
			else {
				if (index >= begIndex && index <= endIndex) {
					total_lex_word_list.push_back(p);
				}
				index++;
			}

		}
	}



#ifdef __PRINT_LEX_WORD_LIST
	for (const auto &e : total_lex_word_list) {
		Util::log("type=" + e->type);
		Util::log("content=" + e->content);
		Util::log("");
	}
#endif
	//人手添加总结符号
	total_lex_word_list.push_back(P_Lex_Word(new Lex_Word()));
	total_lex_word_list.back()->type = "'end'";
}



void Parser::gen_middle_code(Env &env, Node* &node_tree, unordered_map<string, string> &imfo_map) {

	//Util::log("生成中间代码:");

	//set<string> has_calculate_set;
	unordered_map<string, P_NodeValue> nodeValueMap;

	vector<P_NodeValue> stack;
	stack.push_back(P_NodeValue(new NodeValue(node_tree, NodeValue::SYN)));

	//P_NodeValue childNodeValue = nullptr;
	while (stack.size() > 0) {
		auto top = stack.back();
		string  sdtKey = ruleFileName + "_" + top->node->symbol + "_" + std::to_string(ruleIdToSubId[top->node->ruleId]);
		P_SDT_genertor sdt_genertor = SDT_Factory::instance.getSDT_genertor(sdtKey);
		if (sdt_genertor == nullptr) {
			Util::log(sdtKey + "未定义");
			throw;
		}

		try {
			sdt_genertor->handle(top, stack, env, nodeValueMap);
		}
		catch (...) {
			Util::log("catch (...)");
		}
	}
}

void Parser::paresOrders(const string& rule_file, vector<string>& orders) {
	vector<vector<string>*> solveConflictList;
	paresOrders(rule_file,  orders, solveConflictList);
}

void Parser::paresOrders(const string& rule_file, vector<string>& orders,vector<vector<string>*> &solveConflictList) {
	ifstream input_file;
	input_file.open(rule_file.data());
	string rule_str;
	ostringstream os;
	int status = 6;
	int bracketsCount = 0;
	vector <string> string_list;
	string left;
	string right;
	unordered_map<string, string> order_map;

	while (getline(input_file, rule_str)) {
		if (rule_str[0] == '=') {
			break;
		}
		if (rule_str[0] == '-') {
			continue;
		}
		rule_str = trim_left_copy(trim_right_copy(rule_str));


		if (status == 6) {
			if (startsWith(rule_str, "//") == 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") == 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") != 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") != 1 && endsWith(rule_str, "*/") == 1) {
				status = 5; break;
			}

			string_list.clear();
			split(string_list, rule_str, is_any_of("{"));

			int _status = 0;
			string rule_str1 = "";
			string rule_str2 = "";
			for (int i1 = 0; i1 < string_list.size(); i1++) {
				string e = string_list[i1];
				if (_status == 0) {
					if (endsWith(e, " ") != 1 && endsWith(e, "\t") != 1) {
						rule_str1 += e;
						if (i1 != (string_list.size() - 1)) {
							rule_str1 += "{";
						}
					}
					else {
						rule_str1 += e;
						rule_str1 = trim_right_copy(rule_str1);
						_status = 1;
					}
				}
				else if (_status == 1) {
					rule_str2 += "{";
					rule_str2 += trim_left_copy(trim_right_copy(e));
				}
			}
			left = rule_str1;
			orders.push_back(left);
			rule_str2 = trim_right_copy(rule_str2);
			rule_str2 = trim_left_copy(rule_str2);



			if (rule_str2 != "") {
				os.str("");
				for (int i1 = 0; i1 < rule_str2.length(); i1++) {
					os << rule_str2[i1];
					if (rule_str2[i1] == '{') {
						bracketsCount++;
					}
					else if (rule_str2[i1] == '}') {
						bracketsCount--;
					}
				}
				if (bracketsCount == 0) {
					status = 6;
					right = os.str();
					order_map[left] = right;
					left = "";
					right = "";
					os.str("");
				}
				else {
					status = 3;
				}
			}
			else {
				status = 6;
				left = "";
				right = "";
			}



		}
		else if (status == 3) {
			if (startsWith(rule_str, "//") == 1) {
				continue;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") == 1) {
				continue;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") != 1) {
				status = 4; continue;
			}
			else if (startsWith(rule_str, "/*") != 1 && endsWith(rule_str, "*/") == 1) {
				status = 5; break;
			}


			if (rule_str != "") {
				for (int i1 = 0; i1 < rule_str.length(); i1++) {
					os << rule_str[i1];
					if (rule_str[i1] == '{') {
						bracketsCount++;
					}
					else if (rule_str[i1] == '}') {
						bracketsCount--;
					}
				}
				if (bracketsCount == 0) {
					status = 6;
					right = os.str();
					order_map[left] = right;
					left = "";
					right = "";
					os.str("");
				}
				else {
					status = 3;
				}
			}

		}
		else if (status == 4) {
			if (startsWith(rule_str, "//") == 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") == 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") == 1 && endsWith(rule_str, "*/") != 1) {
				status = 5; break;
			}
			else if (startsWith(rule_str, "/*") != 1 && endsWith(rule_str, "*/") == 1) {
				status = 3; continue;
			}
		}
	}

	vector<string> *tempList=nullptr;
	while (getline(input_file, rule_str)) {
		if (rule_str == "sc") {
			tempList = new vector<string>;
			solveConflictList.push_back(tempList);
		}
		else {
			tempList->push_back(rule_str);
		}
	}

}
