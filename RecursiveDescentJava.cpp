#include "RecursiveDescentJava.h"
#include"symbols\PrimarySymbolConverter.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include"SLR\NodeValue.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include"SLR\SDT_Factory.h"
using namespace std;
using namespace boost;

RecursiveDescentJava::RecursiveDescentJava() {}

RecursiveDescentJava::~RecursiveDescentJava() {}



string RecursiveDescentJava::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}

void RecursiveDescentJava::log(const string& s) {
			  cout<<s<<endl;
}

int RecursiveDescentJava::startsWith(const string& s, const string& sub) {
	if (sub.length() > s.length()) {
		return 0;
	}
	return s.find(sub) == 0 ? 1 : 0;
}


int RecursiveDescentJava::endsWith(const string& s, const string& sub) {
	if (sub.length() > s.length()) {
		return 0;
	}
	return s.rfind(sub) == (s.length() - sub.length()) ? 1 : 0;
}


void RecursiveDescentJava::init_total_lex_word_list(string compile_file, PrimarySymbolConverter &primarySymbolConverter, set<string> &endSymbolSet) {
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

Node* RecursiveDescentJava::createTerminateNode(P_Lex_Word &p) {
	Node *node = new Node();
	node->symbol = p->type;
	if (node->symbol!="0") {
		node->content = p->content;
		node->index = p->index;
		node->lineNum = p->lineNum;
	}
	else {
		node->content = "";
		node->index = -1;
	}
	
	node->parent = nullptr;
	node->offset = 0;

	return node;
}



void RecursiveDescentJava::paresOrders(const string& rule_file, vector<string>& orders) {
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
			//cout<<"left="<<rule_str1<<endl;
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
					//cout<<"right="<<os.str()<<endl;
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
					//cout<<"right="<<os.str()<<endl;
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

}


void RecursiveDescentJava::init(string rule_file) {

	vector <string> strs;
	split(strs, rule_file, is_any_of("\\"));


	ruleFileName = strs[strs.size() - 1];
	ruleFileName = replaceAll(ruleFileName, ".txt", "");


	//log("生成ruleListing");
	ifstream input_file;
	input_file.open(rule_file.data());

	ruleList.clear();
	vector<string> orders;
	unordered_map<string, string> temp_forecast_map;
	paresOrders(rule_file, orders);

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


	for (const auto &e : orders) {
		ruleList.push_back(P_Rule(new Rule(e)));
		ruleList.back()->index = ruleList.size() - 1;
	}
}

void RecursiveDescentJava::findFirstAndLastRules(string symbol,unordered_map<string,int> &map) {
	bool isMatched = false;
	for (int i1 = 0; i1 < ruleList.size(); i1++) {
		if (ruleList[i1]->rule_name == symbol) {
			if (!isMatched) {
				map["first"] = i1;
			}
			map["last"] = i1;
			isMatched = true;
		}
		else {
			if (isMatched) {
				isMatched = false;
				break;
			}
		}
	}
}

Node* RecursiveDescentJava::createNode(P_Rule &rule) {
	Node *p=new Node();

	p->symbol = rule->rule_name;
	p->ruleId = rule->index;
	return p;
}

Node* RecursiveDescentJava::slr(Env& env,string rootSymbol) {

	struct ItemNode {
		Node *node;
		int beginRuleIndex;
		int latestRuleIndex;
		int status;
	};

	int DOING = 0;
	int FAIL = 1;
	int DONE = 2;

	unordered_map<string, int> transferMap;
	typedef std::shared_ptr<ItemNode> P_ItemNode;
	vector<P_ItemNode> item_node_stack1;
	item_node_stack1.push_back(P_ItemNode(new ItemNode()));
//	log("压入：" + rootSymbol);
	transferMap.clear();
	findFirstAndLastRules(rootSymbol, transferMap);

	item_node_stack1[0]->node = new Node();
	item_node_stack1[0]->node->symbol = rootSymbol;
	item_node_stack1[0]->beginRuleIndex =transferMap["first"];
	item_node_stack1[0]->latestRuleIndex = transferMap["last"];
	item_node_stack1[0]->node->ruleId = item_node_stack1[0]->beginRuleIndex;
	item_node_stack1[0]->status = DOING;

	

	int wordListId = 0;
	Node* resultNodePtr = nullptr;

	while (item_node_stack1.size()>0) {

		P_ItemNode top_item = item_node_stack1.back();

		if (top_item->status== FAIL) {
			if (top_item->node->ruleId != top_item->latestRuleIndex) {
				int newRuleId = top_item->node->ruleId+1;
				
				Node* newNode=createNode(ruleList[newRuleId]);
				newNode->offset = top_item->node->offset;
				newNode->parent = top_item->node->parent;

				Node::releaseNode(top_item->node);
				top_item->node = newNode;
				top_item->status = DOING;
				
			}
			else {
				Node* parentNode = item_node_stack1.back()->node->parent;
				while (item_node_stack1.back()->node != parentNode) {
//					log("弹出1：" + item_node_stack1.back()->node->symbol);
//					cout << "wordListId=" << wordListId << endl;
					Node::releaseNode(item_node_stack1.back()->node);
					item_node_stack1.pop_back();
				}
				item_node_stack1.back()->status = FAIL;
				if (item_node_stack1.back()->node->child_node_list.size()>0) {
					wordListId=item_node_stack1.back()->node->child_node_list[0]->index;
				}
				
			}

		}
		else if (top_item->status == DONE) {
			
			if (top_item->node->parent!=nullptr) {
				top_item->node->parent->child_node_list.push_back(top_item->node);
				if (top_item->node->offset==0) {
					top_item->node->parent->index = top_item->node->index;
					top_item->node->parent->lineNum = top_item->node->lineNum;
				}
			}else{
				resultNodePtr= top_item->node;
			}

//				log("弹出2：" + item_node_stack1.back()->node->symbol);
//				cout << "wordListId=" << wordListId << endl;
				item_node_stack1.pop_back();

		}

		else if (top_item->status == DOING) {
			if (startsWith(top_item->node->symbol, "'") == 1) {
				if (wordListId< total_lex_word_list.size() 
						&&total_lex_word_list[wordListId]->type == top_item->node->symbol) {
					top_item->status = DONE;
					top_item->node->content = total_lex_word_list[wordListId]->content;
					top_item->node->index = wordListId;
					top_item->node->lineNum = total_lex_word_list[wordListId]->lineNum;
					wordListId++;
					
				}
				else {
					top_item->status = FAIL;
				}
			}
			else if (top_item->node->symbol == "0") {
				top_item->status = DONE;
				top_item->node->index = wordListId;
				top_item->node->lineNum = total_lex_word_list[wordListId]->lineNum;
			}
			else {
				if (top_item->node->child_node_list.size()== ruleList[top_item->node->ruleId]->symbols.size()) {
					item_node_stack1.back()->status = DONE;
				}
				else {
					for (int i1 = ruleList[top_item->node->ruleId]->symbols.size() - 1; i1 >= 0; i1--) {
//						log("压入：" + ruleList[top_item->node->ruleId]->symbols[i1]);
//						cout << "wordListId=" << wordListId << endl;
						item_node_stack1.push_back(P_ItemNode(new ItemNode()));
						item_node_stack1.back()->node = new Node();
						item_node_stack1.back()->node->symbol = ruleList[top_item->node->ruleId]->symbols[i1];
						item_node_stack1.back()->node->parent = top_item->node;
						transferMap.clear();
						findFirstAndLastRules(item_node_stack1.back()->node->symbol, transferMap);
						item_node_stack1.back()->beginRuleIndex = transferMap["first"];
						item_node_stack1.back()->latestRuleIndex = transferMap["last"];
						item_node_stack1.back()->node->ruleId = transferMap["first"];
						item_node_stack1.back()->node->offset = i1;
						item_node_stack1.back()->status = DOING;
					}
				}

			}
		}
	}

//	cout << "wordListId()=" << wordListId << endl;
//	cout << "total_lex_word_list.size()=" << total_lex_word_list.size() << endl;

	
		


	return resultNodePtr;
}



void RecursiveDescentJava::gen_middle_code(Env &env, Node* &node_tree, unordered_map<string, string> &imfo_map) {

	cout << "生成中间代码:" << endl;

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
			cout << sdtKey << "未定义";
			throw;
		}

		try {
			sdt_genertor->handle(top, stack, env, nodeValueMap);
		}
		catch (...) {
			cout << "catch (...)" << endl;
		}



	}

}
