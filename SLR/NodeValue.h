#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include "Node.h"
#include "../symbols/Token.h"
using namespace std;
class NodeValue {

public: static const int SYN = 0;
public: static const int INH = 1;
public: Node* node;
public: int value_type;
public: NodeValue();
public: NodeValue(Node *node, int value_type);
//public: NodeValue(Node *node);
public: virtual ~NodeValue();

public: unordered_map<string, P_Token> context;
public: P_Token get_context(string key);
};

typedef std::shared_ptr<NodeValue> P_NodeValue;

	

