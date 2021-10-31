#pragma once
#include<string>
#include<vector>
using namespace std;
class Node{
public: string symbol="";
public: string content = "";
public: int offset=0;
public: long index = -1;
public: Node *parent=nullptr;
public: vector<Node*> child_node_list;

public: string get_rule_str();

public: virtual ~Node();
};



