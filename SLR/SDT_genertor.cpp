#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_genertor.h"
using namespace std;

SDT_genertor::SDT_genertor() {}

SDT_genertor::~SDT_genertor() {}

inline string SDT_genertor::child(const P_NodeValue &nodeValue, int index, int value_type) {
	os.str("");
	os << nodeValue->node->child_node_list[index] << "_" << value_type;
	return os.str();
}

inline string SDT_genertor::own(const P_NodeValue &nodeValue, int value_type) {
	os.str("");
	os << nodeValue->node << "_" << value_type;
	return os.str();
}