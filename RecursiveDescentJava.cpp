#include "RecursiveDescentJava.h"
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

RecursiveDescentJava::RecursiveDescentJava() {}

RecursiveDescentJava::~RecursiveDescentJava() {}

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

int RecursiveDescentJava::init(string rule_file) {

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

	return 0;
}


Node* RecursiveDescentJava::slr(Env& env,string rootSymbol,int wordListBegId) {

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
	log("压入：" + rootSymbol);
	transferMap.clear();
	findFirstAndLastRules(rootSymbol, transferMap);

	item_node_stack1[0]->node = new Node();
	item_node_stack1[0]->node->symbol = rootSymbol;
	item_node_stack1[0]->beginRuleIndex =transferMap["first"];
	item_node_stack1[0]->latestRuleIndex = transferMap["last"];
	item_node_stack1[0]->node->ruleId = item_node_stack1[0]->beginRuleIndex;
	item_node_stack1[0]->status = DOING;

	

	int wordListId = wordListBegId;
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
				while (item_node_stack1.size()>0&& item_node_stack1.back()->node != parentNode) {
					log("弹出1：" + item_node_stack1.back()->node->symbol);
					log("wordListId=" + std::to_string(wordListId));
					Node::releaseNode(item_node_stack1.back()->node);
					item_node_stack1.pop_back();

				}
				if (item_node_stack1.size()>0) {
					item_node_stack1.back()->status = FAIL;
					if (item_node_stack1.back()->node->child_node_list.size() > 0) {
						wordListId = item_node_stack1.back()->node->child_node_list[0]->index;
					}
				}
				else {
					resultNodePtr = nullptr;
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

				log("弹出2：" + item_node_stack1.back()->node->symbol);
				log("wordListId=" + std::to_string(wordListId));
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
						log("压入：" + ruleList[top_item->node->ruleId]->symbols[i1]);
						log("wordListId=" + std::to_string(wordListId));
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

	//Util::log("wordListId()=" + wordListId);
	//Util::log("total_lex_word_list.size()=" + total_lex_word_list.size());

	return resultNodePtr;
}
