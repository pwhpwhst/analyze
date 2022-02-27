#include "JAVATreeAnalyzer.h"
#include <deque>
#include <set>
#include <unordered_map>
#include <sstream>
using namespace std;





JAVATreeAnalyzer::JAVATreeAnalyzer() {
}

JAVATreeAnalyzer::~JAVATreeAnalyzer() {
}


void JAVATreeAnalyzer::findTypeDeclarationListBegin(Node *treeNode,unordered_map<string, string> &resultMap) {
	deque<Node*> queue;
	queue.push_front(treeNode);

	Node* target_node = nullptr;
	while (queue.size()>0) {
		Node* present_node=queue.back();

		if (present_node->symbol == "TypeDeclarationList") {
/*
			auto p = present_node;
			while (p->index == -1) {
				p = p->child_node_list[0];
			}

			resultMap["begin"] = std::to_string(p->index);
			resultMap["content"] = p->content;
			return;
*/
			target_node = present_node;
			break;
		}

		if (present_node->child_node_list.size() > 0) {
			for (auto &e : present_node->child_node_list) {
				queue.push_front(e);
			}
		}

		queue.pop_back();
	}

	if (target_node!=nullptr) {
		queue.clear();
		queue.push_back(target_node);
		while (queue.size() > 0) {
			Node* present_node = queue.back();
			if (present_node->index == -1) {
				if (present_node->child_node_list.size() > 0) {
					for (int i1 = present_node->child_node_list.size() - 1; i1 >= 0;i1--) {
						queue.push_back(present_node->child_node_list[i1]);
					}
				}
				else {
					queue.pop_back();
				}
			}
			else {
				resultMap["begin"] = std::to_string(present_node->index);
				//resultMap["content"] = present_node->content;
				return;
			}
			
		}
	}


}


