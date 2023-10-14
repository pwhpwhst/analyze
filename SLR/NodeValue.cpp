
#include "NodeValue.h"
using namespace std;




NodeValue::NodeValue(Node *node, int value_type) {
	this->node = node;
	this->value_type = value_type;
}


//NodeValue::NodeValue(Node *node) {
//	this->node = node;
//	this->context["status"] =P_Token(new Token("status","parsing"));
//	this->context["pos"] = P_Token(new Token("pos", "-1"));
//}

P_Token NodeValue::get_context(string &key) {
	if (this->context.count(key) == 0) {
		context[key]= P_Token(new Token());
	}
	return context.at(key);
}

NodeValue::NodeValue() {}

NodeValue::~NodeValue() {}

