#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_genertor.h"
using namespace std;

SDT_genertor::SDT_genertor() {}

SDT_genertor::~SDT_genertor() {}

string SDT_genertor::child(const P_NodeValue &nodeValue, int index, int value_type) {
	os.str("");
	os << nodeValue->node->child_node_list[index] << "_" << value_type;
	return os.str();
}

string SDT_genertor::own(const P_NodeValue &nodeValue, int value_type) {
	os.str("");
	os << nodeValue->node << "_" << value_type;
	return os.str();
}


Non_Terminate_genertor::Non_Terminate_genertor() {
}

P_NodeValue Non_Terminate_genertor::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	//logR001("Non_Terminate_genertor");
	ostringstream os;
	os << nodeValue->node->child_node_list.back();
	os << "_";
	os << NodeValue::SYN;


	if (nodeValueMap.count(os.str()) == 0) {
		for (int i1 = nodeValue->node->child_node_list.size() - 1; i1 >= 0; i1--) {
			stack.push_back(P_NodeValue(new NodeValue(nodeValue->node->child_node_list[i1], NodeValue::SYN)));
		}
	}
	else {

		//os.str("");
		//os << nodeValue->node->child_node_list[0];
		//os << "_";
		//os << NodeValue::SYN;
		//nodeValue->context["CompilationUnit"] = nodeValueMap[os.str()]->context["TypeDeclarationList"];

		handle(nodeValue, env, nodeValueMap);

		for (auto &e : nodeValue->node->child_node_list) {
			os.str("");
			os << e;
			os << "_";
			os << NodeValue::SYN;
			nodeValueMap.erase(os.str());
		}
		os.str("");
		os << nodeValue->node;
		os << "_";
		os << NodeValue::SYN;
		nodeValueMap[os.str()] = nodeValue;
		stack.pop_back();
	}

	return nullptr;
}


Non_Terminate_genertor::~Non_Terminate_genertor() {
}



Non_Terminate_Skip_genertor::Non_Terminate_Skip_genertor() {
}

P_NodeValue Non_Terminate_Skip_genertor::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	ostringstream os;
	os << nodeValue->node;
	os << "_";
	os << NodeValue::SYN;

	nodeValueMap[os.str()] = nodeValue;
	for (auto &e : nodeValue->node->child_node_list) {
		os.str("");
		os << e;
		os << "_";
		os << NodeValue::SYN;
		nodeValueMap.erase(os.str());
	}
	os.str("");
	os << nodeValue->node;
	os << "_";
	os << NodeValue::SYN;
	nodeValueMap[os.str()] = nodeValue;
	stack.pop_back();
	return nullptr;
}


Non_Terminate_Skip_genertor::~Non_Terminate_Skip_genertor() {
}