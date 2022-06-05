#include "R001Analyzer.h"
#include "../../symbols/java/Class.h"
#include "../../symbols/java/Array.h"
#include<iostream>
using namespace std;

void logR001(const string& s) {
			  cout<<s<<endl;
}

R001_DefaultAnalyzer::R001_DefaultAnalyzer() {
}

P_NodeValue R001_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DefaultAnalyzer");
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
	stack.pop_back();
	return nullptr;
}


R001_DefaultAnalyzer::~R001_DefaultAnalyzer() {
}

//CompilationUnit : TypeDeclarationList
R001_CompilationUnit_2Analyzer::R001_CompilationUnit_2Analyzer() {
}

P_NodeValue R001_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_2Analyzer");
	ostringstream os;
	os << nodeValue->node->child_node_list.back();
	os << "_";
	os << NodeValue::SYN;


	if (nodeValueMap.count(os.str()) == 0) {
		for (int i1 = nodeValue->node->child_node_list.size() - 1; i1 >= 0;i1--) {
			stack.push_back(P_NodeValue(new NodeValue(nodeValue->node->child_node_list[i1], NodeValue::SYN)));
		}
	}
	else {

		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["CompilationUnit"] = nodeValueMap[os.str()]->context["TypeDeclarationList"];

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


R001_CompilationUnit_2Analyzer::~R001_CompilationUnit_2Analyzer() {
}








//TypeDeclarationList : TypeDeclaration
R001_TypeDeclarationList_1Analyzer::R001_TypeDeclarationList_1Analyzer() {
}

P_NodeValue R001_TypeDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclarationList_1Analyzer");
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

		Array *p = new Array();
		nodeValue->context["TypeDeclarationList"] = P_Token(p);

		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		p->list.push_front(nodeValueMap[os.str()]->context["TypeDeclaration"]);

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


R001_TypeDeclarationList_1Analyzer::~R001_TypeDeclarationList_1Analyzer() {
}



//TypeDeclaration : ClassDeclaration
R001_TypeDeclaration_0Analyzer::R001_TypeDeclaration_0Analyzer() {
}

P_NodeValue R001_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclaration_0Analyzer");
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

		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["TypeDeclaration"] = nodeValueMap[os.str()]->context["ClassDeclaration"];

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


R001_TypeDeclaration_0Analyzer::~R001_TypeDeclaration_0Analyzer() {
}



//ClassDeclaration : NormalClassDeclaration
R001_ClassDeclaration_0Analyzer::R001_ClassDeclaration_0Analyzer() {
}

P_NodeValue R001_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassDeclaration_0Analyzer");
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


		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["ClassDeclaration"] = nodeValueMap[os.str()]->context["NormalClassDeclaration"];



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


R001_ClassDeclaration_0Analyzer::~R001_ClassDeclaration_0Analyzer() {
}


//NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
R001_NormalClassDeclaration_1Analyzer::R001_NormalClassDeclaration_1Analyzer() {
}

P_NodeValue R001_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_1Analyzer");
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
		Class *p = new Class();
		nodeValue->context["NormalClassDeclaration"] = P_Token(p);
		os.str("");
		os << nodeValue->node->child_node_list[2];
		os << "_";
		os << NodeValue::SYN;
		p->className = nodeValueMap[os.str()]->context["identifier"]->content;

		os.str("");
		os << nodeValue->node->child_node_list[3];
		os << "_";
		os << NodeValue::SYN;
		p->list = nodeValueMap[os.str()]->context["ClassBody"];


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


R001_NormalClassDeclaration_1Analyzer::~R001_NormalClassDeclaration_1Analyzer() {
}



R001_ModifierList_1Analyzer::R001_ModifierList_1Analyzer() {
}

P_NodeValue R001_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ModifierList_1Analyzer");

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


R001_ModifierList_1Analyzer::~R001_ModifierList_1Analyzer() {
}



//Identifier : 'IDENTIFIER'
R001_Identifier_0Analyzer::R001_Identifier_0Analyzer() {
}

P_NodeValue R001_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Identifier_0Analyzer");

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
		nodeValue->context["identifier"]=  P_Token(new Token("string", nodeValue->node->child_node_list[0]->content,0));
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


R001_Identifier_0Analyzer::~R001_Identifier_0Analyzer() {
}



//ClassBody: 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
R001_ClassBody_0Analyzer::R001_ClassBody_0Analyzer() {
}

P_NodeValue R001_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBody_0Analyzer");

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
		os.str("");
		os << nodeValue->node->child_node_list[1];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["ClassBody"] = nodeValueMap[os.str()]->context["ClassBodyDeclarationList"];

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


//ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
R001_ClassBody_0Analyzer::~R001_ClassBody_0Analyzer() {
}



R001_ClassBodyDeclarationList_0Analyzer::R001_ClassBodyDeclarationList_0Analyzer() {
}

P_NodeValue R001_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_0Analyzer");

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

		os.str("");
		os << nodeValue->node->child_node_list[1];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["ClassBodyDeclarationList"] = nodeValueMap[os.str()]->context["ClassBodyDeclarationList"];
		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		Array * p = (Array *)(nodeValue->context["ClassBodyDeclarationList"].get());
		p->list.push_front(nodeValueMap[os.str()]->context["ClassBodyDeclaration"]);

		

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


R001_ClassBodyDeclarationList_0Analyzer::~R001_ClassBodyDeclarationList_0Analyzer() {
}


//ClassBodyDeclaration : ClassMemberDeclaration
R001_ClassBodyDeclaration_0Analyzer::R001_ClassBodyDeclaration_0Analyzer() {
}

P_NodeValue R001_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclaration_0Analyzer");

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
		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["ClassBodyDeclaration"] = nodeValueMap[os.str()]->context["ClassMemberDeclaration"];

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






R001_ClassBodyDeclaration_0Analyzer::~R001_ClassBodyDeclaration_0Analyzer() {
}



R001_ClassMemberDeclaration_1Analyzer::R001_ClassMemberDeclaration_1Analyzer() {
}

P_NodeValue R001_ClassMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_1Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_ClassMemberDeclaration_1Analyzer::~R001_ClassMemberDeclaration_1Analyzer() {
}


//ClassMemberDeclaration : ClassDeclaration
R001_ClassMemberDeclaration_2Analyzer::R001_ClassMemberDeclaration_2Analyzer() {
}

P_NodeValue R001_ClassMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_2Analyzer");

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
		os.str("");
		os << nodeValue->node->child_node_list[0];
		os << "_";
		os << NodeValue::SYN;
		nodeValue->context["ClassMemberDeclaration"] = nodeValueMap[os.str()]->context["ClassDeclaration"];


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


R001_ClassMemberDeclaration_2Analyzer::~R001_ClassMemberDeclaration_2Analyzer() {
}




//NormalClassDeclaration : 'class' Identifier ClassBody
R001_NormalClassDeclaration_0Analyzer::R001_NormalClassDeclaration_0Analyzer() {
}

P_NodeValue R001_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_0Analyzer");

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

		Class *p = new Class();
		nodeValue->context["NormalClassDeclaration"] = P_Token(p); 
		os.str("");
		os << nodeValue->node->child_node_list[1];
		os << "_";
		os << NodeValue::SYN;
		p->className = nodeValueMap[os.str()]->context["identifier"]->content;

		os.str("");
		os << nodeValue->node->child_node_list[2];
		os << "_";
		os << NodeValue::SYN;
		p->list = nodeValueMap[os.str()]->context["ClassBody"];

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


R001_NormalClassDeclaration_0Analyzer::~R001_NormalClassDeclaration_0Analyzer() {
}







//ClassBodyDeclarationList : 0
R001_ClassBodyDeclarationList_1Analyzer::R001_ClassBodyDeclarationList_1Analyzer() {
}

P_NodeValue R001_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_1Analyzer");

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
		Array *p = new Array();
		nodeValue->context["ClassBodyDeclarationList"] = P_Token(p);


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


R001_ClassBodyDeclarationList_1Analyzer::~R001_ClassBodyDeclarationList_1Analyzer() {
}





R001_MethodDeclaration_1Analyzer::R001_MethodDeclaration_1Analyzer() {
}

P_NodeValue R001_MethodDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclaration_1Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_MethodDeclaration_1Analyzer::~R001_MethodDeclaration_1Analyzer() {
}





R001_MethodHeader_12Analyzer::R001_MethodHeader_12Analyzer() {
}

P_NodeValue R001_MethodHeader_12Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_12Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_MethodHeader_12Analyzer::~R001_MethodHeader_12Analyzer() {
}



R001_MethodDeclarator_0Analyzer::R001_MethodDeclarator_0Analyzer() {
}

P_NodeValue R001_MethodDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclarator_0Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_MethodDeclarator_0Analyzer::~R001_MethodDeclarator_0Analyzer() {
}






R001_MethodBody_0Analyzer::R001_MethodBody_0Analyzer() {
}

P_NodeValue R001_MethodBody_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodBody_0Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_MethodBody_0Analyzer::~R001_MethodBody_0Analyzer() {
}





R001_Block_0Analyzer::R001_Block_0Analyzer() {
}

P_NodeValue R001_Block_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Block_0Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_Block_0Analyzer::~R001_Block_0Analyzer() {
}





R001_BlockStatements_1Analyzer::R001_BlockStatements_1Analyzer() {
}

P_NodeValue R001_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_BlockStatements_1Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_BlockStatements_1Analyzer::~R001_BlockStatements_1Analyzer() {
}




R001_NonBrace_0Analyzer::R001_NonBrace_0Analyzer() {
}

P_NodeValue R001_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_0Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_NonBrace_0Analyzer::~R001_NonBrace_0Analyzer() {
}





R001_StatementEle_63Analyzer::R001_StatementEle_63Analyzer() {
}

P_NodeValue R001_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_63Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_StatementEle_63Analyzer::~R001_StatementEle_63Analyzer() {
}


R001_StatementEle_0Analyzer::R001_StatementEle_0Analyzer() {
}

P_NodeValue R001_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_0Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_StatementEle_0Analyzer::~R001_StatementEle_0Analyzer() {
}



R001_NonBrace_2Analyzer::R001_NonBrace_2Analyzer() {
}

P_NodeValue R001_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_2Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_NonBrace_2Analyzer::~R001_NonBrace_2Analyzer() {
}



R001_BlockStatements_2Analyzer::R001_BlockStatements_2Analyzer() {
}

P_NodeValue R001_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_BlockStatements_2Analyzer");

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
		//nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


R001_BlockStatements_2Analyzer::~R001_BlockStatements_2Analyzer() {
}