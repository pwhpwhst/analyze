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

#include "R001Analyzer2.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include "R001Analyzer3.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////
//CompilationUnit : TypeDeclarationList
void R001_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_2Analyzer");
	nodeValue->context["CompilationUnit"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list= nodeValue->context["CompilationUnit"];
}


//TypeDeclarationList : TypeDeclaration
void R001_TypeDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclarationList_1Analyzer");
	Array *p = new Array();
	nodeValue->context["TypeDeclarationList"] = P_Token(p);
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"]);
}


//TypeDeclaration : ClassDeclaration
void R001_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclaration_0Analyzer");
	nodeValue->context["TypeDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
}



//ClassDeclaration : NormalClassDeclaration
void R001_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassDeclaration_0Analyzer");
	nodeValue->context["ClassDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
}


//NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
void R001_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_1Analyzer");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

}


//Identifier : 'IDENTIFIER'
void R001_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Identifier_0Analyzer");
	nodeValue->context["identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
}

//ClassBody: 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBody_0Analyzer");
	nodeValue->context["ClassBody"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}


//ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R001_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_0Analyzer");
	nodeValue->context["ClassBodyDeclarationList"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
	Array * p = (Array *)(nodeValue->context["ClassBodyDeclarationList"].get());
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassBodyDeclaration"]);
}


//ClassBodyDeclaration : ClassMemberDeclaration
void R001_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclaration_0Analyzer");
	nodeValue->context["ClassBodyDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassMemberDeclaration"];
}


//ClassMemberDeclaration : ClassDeclaration
void R001_ClassMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_2Analyzer");
	nodeValue->context["ClassMemberDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
}


//NormalClassDeclaration : 'class' Identifier ClassBody
void R001_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_0Analyzer");
	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];
}


//ClassBodyDeclarationList : 0
void R001_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_1Analyzer");
	Array *p = new Array();
	nodeValue->context["ClassBodyDeclarationList"] = P_Token(p);
}
