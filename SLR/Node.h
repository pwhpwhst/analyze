#pragma once
#include<string>
#include<vector>
using namespace std;
class Node{
public: string symbol="";
public: string content = "";
public: int offset=0;
public: int ruleId = -1;
public: long index = -1;	//´Ê·¨Á÷Î»ÖÃ
public: long lineNum = -1;	
public: Node *parent=nullptr;
public: vector<Node*> child_node_list;

public: string get_rule_str();
public: static void releaseNode(Node *node);
public: virtual ~Node();

};



