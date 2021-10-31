#include<vector>
#include <sstream>
#include <iostream>
#include "Node.h"
using namespace std;

string Node::get_rule_str(){
	ostringstream os;
	os<<this->symbol<<" :";
	for(const auto &e:child_node_list){
		os<<" "<<e->symbol;
	}
	return os.str();
}





Node::~Node() {
//	cout << "haha" << endl;
	for (auto &e:child_node_list) {
		delete e;
	}
}



