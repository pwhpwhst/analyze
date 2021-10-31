#include "JAVATreeAnalyzer.h"
#include <deque>
#include <set>
#include <sstream>
using namespace std;





JAVATreeAnalyzer::JAVATreeAnalyzer() {
}

JAVATreeAnalyzer::~JAVATreeAnalyzer() {
}


void JAVATreeAnalyzer::parse(Node *treeNode, vector<P_MethodOrFieldEntity> &result_vector) {
	deque<Node*> queue;
	queue.push_front(treeNode);


	while (queue.size()>0) {
		Node* present_node=queue.back();
		if (present_node->child_node_list.size()>0) {
			for (auto &e : present_node->child_node_list) {
				queue.push_front(e);
			}
		}

		if (present_node->symbol=="MethodOrFieldDecl") {
			auto p = P_MethodOrFieldEntity(new MethodOrFieldEntity());
			parse_MethodOrFieldDecl(*p, present_node);
			result_vector.push_back(p);
		}

		queue.pop_back();
	}
}

void JAVATreeAnalyzer::parse_MethodOrFieldDecl(MethodOrFieldEntity &entity, Node *node) {
	parse_Type(entity, node->child_node_list[0]);
	string content=node->child_node_list[1]->child_node_list[0]->content;
	entity.name = content;
	parse_MethodOrFieldRest(entity, node->child_node_list[2]);
}

void JAVATreeAnalyzer::parse_Type(MethodOrFieldEntity &entity, Node *node) {
	deque<Node*> stack;
	set<Node*> has_visited;

	stack.push_back(node);
	has_visited.insert(node);
	ostringstream sb;

	while (stack.size() > 0) {
		bool visit_child = false;
		if (stack.back()->child_node_list.size()>0) {
			for (auto &e: stack.back()->child_node_list) {
				if (has_visited.count(e) == 0) {
					stack.push_back(e);
					has_visited.insert(e);
					visit_child = true;
					break;
				}
			}
		}
		if (!visit_child) {
			if (stack.back()->content!="") {
				sb << stack.back()->content;
			}
			stack.pop_back();
		}
	}
	entity.return_type = sb.str();
}


void JAVATreeAnalyzer::parse_MethodOrFieldRest(MethodOrFieldEntity &entity, Node *node) {
	if (node->child_node_list[0]->symbol == "FieldDeclaratorsRest") {
		entity.type = "field";
	}
	else {
		entity.type = "method";
		for (auto &e : node->child_node_list[0]->child_node_list[0]->child_node_list) {
			if (e->symbol=="FormalParameterDecls") {
				parse_FormalParameterDecls(entity, e);
			}
		}
	}
}


void JAVATreeAnalyzer::parse_FormalParameterDecls(MethodOrFieldEntity &entity, Node *node) {
	deque<Node*> stack;
	set<Node*> has_visited;

	stack.push_back(node);
	has_visited.insert(node);
	ostringstream sb;

	while (stack.size() > 0) {
		bool visit_child = false;
		if (stack.back()->child_node_list.size() > 0) {
			for (auto &e : stack.back()->child_node_list) {
				if (e->symbol!="VariableDeclaratorId" && has_visited.count(e) == 0) {
					stack.push_back(e);
					has_visited.insert(e);
					visit_child = true;
					break;
				}
			}
		}
		if (!visit_child) {
			if (stack.back()->content != "") {
				sb << stack.back()->content;
			}
			stack.pop_back();
		}
	}
	entity.parameters = sb.str();
}

