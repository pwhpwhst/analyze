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

void Node::releaseNode(Node *node) {
	vector<Node*> stack;
	stack.push_back(node);
	while (stack.size() > 0) {
		Node* p = stack.back();

		Node* child = nullptr;
		for (auto &e : p->child_node_list) {
			if (e != nullptr) {
				child = e;
				break;
			}
		}

		if (child!=nullptr) {
			stack.push_back(child);
		}
		else {
			stack.pop_back();
			if (p->parent != nullptr) {
				for (int i1 = 0; i1 < p->parent->child_node_list.size(); i1++) {
						if (p->parent->child_node_list[i1] == p ) {
							p->parent->child_node_list[i1] = nullptr;
							if (i1 != (p->parent->child_node_list.size() - 1)) {
								stack.push_back(p->parent->child_node_list[i1 + 1]);
							}
						}
				}
			}
			delete p;
		}
	}
}



Node::~Node() {
	/*
	for (auto &e:child_node_list) {
		delete e;
	}
	*/
	
}



