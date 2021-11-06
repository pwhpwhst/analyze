#include "JAVASpaceTreeAnalyzer.h"
#include <deque>
#include <set>
#include <sstream>
using namespace std;





JAVASpaceTreeAnalyzer::JAVASpaceTreeAnalyzer() {
}

JAVASpaceTreeAnalyzer::~JAVASpaceTreeAnalyzer() {
}


void JAVASpaceTreeAnalyzer::parse(Node *treeNode, vector<P_MethodOrFieldEntity> &result_vector) {

	deque<Node*> queue;
	queue.push_front(treeNode);


	while (queue.size() > 0) {
		Node* present_node = queue.back();
		if (present_node->child_node_list.size() > 0) {
			for (auto &e : present_node->child_node_list) {
				queue.push_front(e);
			}
		}

		if (present_node->symbol == "ClassBody") {
			auto p = P_MethodOrFieldEntity(new MethodOrFieldEntity());
			parse_ClassBody(*p, present_node);
			result_vector.push_back(p);
		}

		queue.pop_back();
	}



}



void JAVASpaceTreeAnalyzer::parse_ClassBody(MethodOrFieldEntity &entity, Node *node) {
	for (auto &e : node->child_node_list) {
		if (e->symbol == "'LEFT_BRACE'") {
			entity.beg_index = e->index;
		}
		else if (e->symbol == "'RIGHT_BRACE'") {
			entity.end_index = e->index;
		}
	}

}

