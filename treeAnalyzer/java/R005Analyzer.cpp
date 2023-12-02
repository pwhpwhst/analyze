#include "R005Analyzer.h"
#include "../../symbols/java/ClassListToken.h"
#include "../../symbols/java/ClassToken.h"
#include "../../symbols/java/ImportToken.h"
#include "../../symbols/java/ImportListToken.h"
#include "../../symbols/java/ImportEntity.h"
#include "../../symbols/java/ModifierToken.h"
#include "../../symbols/java/ModifierListToken.h"
#include "../../symbols/java/ModifierEntity.h"
#include "../../symbols/java/StatementToken.h"
#include "../../symbols/java/StatementListToken.h"
#include "../../symbols/java/StatementEntity.h"
#include <iostream>
#include <sstream>
using namespace std;

#include "R005Analyzer_1.h"

void logR005(const string& s) {
//		cout<<s<<endl;
}



P_NodeValue R005_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR005("R005_DefaultAnalyzer");
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


};



//beg_ele_begin : TypeDeclarationList
void R005_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p0 == nullptr) {
		p0 = P_Token(new ClassListToken());
	}


	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_Identifier : 'IDENTIFIER'
void R005_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Identifier_0Analyzer");
	//TO DO  R005_Identifier_0Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R005_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DetailIdentifier_0Analyzer");
	//TO DO  R005_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R005_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DetailIdentifier_1Analyzer");
	//TO DO  R005_DetailIdentifier_1Analyzer
};



//beg_TypeDeclarationList : TypeDeclaration
void R005_TypeDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];

	ClassListToken* p = new ClassListToken();
	if (p0 != nullptr) {
		p->list.push_front(((ClassToken *)(p0.get()))->classEntity);
	}

	nodeValue->context["TypeDeclarationList"] = P_Token(p);
};



//beg_TypeDeclaration : ClassDeclaration
void R005_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
	nodeValue->context["TypeDeclaration"] = p0;
};



//beg_TypeDeclaration : InterfaceDeclaration
void R005_TypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];
	nodeValue->context["TypeDeclaration"] = p0;
};



//beg_TypeDeclaration : 'semicolon'
void R005_TypeDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeDeclaration_2Analyzer");
	//TO DO  R005_TypeDeclaration_2Analyzer
};



//beg_ClassDeclaration : NormalClassDeclaration
void R005_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_ClassDeclaration : EnumDeclaration
void R005_ClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
void R005_InterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalInterfaceDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
void R005_InterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
void R005_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_0Analyzer");
	
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p2;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
void R005_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = P_Token(p3);
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
void R005_NormalClassDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_2Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
void R005_NormalClassDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_3Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass ClassBody
void R005_NormalClassDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_4Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass ClassBody
void R005_NormalClassDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_5Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass ClassBody
void R005_NormalClassDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_6Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments ClassBody
void R005_NormalClassDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_7Analyzer");
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p5;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces ClassBody
void R005_NormalClassDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_8Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces ClassBody
void R005_NormalClassDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_9Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces ClassBody
void R005_NormalClassDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_10Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces ClassBody
void R005_NormalClassDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_11Analyzer");
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p5;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces ClassBody
void R005_NormalClassDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_12Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces ClassBody
void R005_NormalClassDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_13Analyzer");
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p5;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces ClassBody
void R005_NormalClassDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_14Analyzer");
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p5;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments Superinterfaces ClassBody
void R005_NormalClassDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_15Analyzer");
	P_Token  p6 = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p6;
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : 'enum' Identifier ClassBody
void R005_EnumDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p2;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier ClassBody
void R005_EnumDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces ClassBody
void R005_EnumDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_2Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces ClassBody
void R005_EnumDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_3Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ClassBody
void R005_NormalInterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p2;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ClassBody
void R005_NormalInterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ClassBody
void R005_NormalInterfaceDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_2Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ClassBody
void R005_NormalInterfaceDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_3Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces ClassBody
void R005_NormalInterfaceDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_4Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces ClassBody
void R005_NormalInterfaceDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_5Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces ClassBody
void R005_NormalInterfaceDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_6Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces ClassBody
void R005_NormalInterfaceDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_7Analyzer");
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p5;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
void R005_ExtendsInterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExtendsInterfaces_0Analyzer");
	//TO DO  R005_ExtendsInterfaces_0Analyzer
};



//beg_AnnotationTypeDeclaration : 'AT' 'interface' Identifier ClassBody
void R005_AnnotationTypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_0Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT' 'interface' Identifier ClassBody
void R005_AnnotationTypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_1Analyzer");
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p4;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier ClassBody
void R005_AnnotationTypeDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_2Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p2;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier ClassBody
void R005_AnnotationTypeDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_3Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	//classEntity->name = p1->content;
	p->classEntity = classEntity;
	p->classEntity->statementList = p3;
	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_ClassBody : 'LEFT_BRACE' 'RIGHT_BRACE'
void R005_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBody_0Analyzer");
	StatementListToken *p = new StatementListToken();
	nodeValue->context["ClassBody"] = P_Token(p);

};



//beg_ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
void R005_ClassBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBody_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];

	nodeValue->context["ClassBody"] = p1;

};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R005_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassBodyDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];

	((StatementListToken *)(p1.get()))->list.push_front(((StatementToken *)(p0.get()))->statementEntity);
	
	nodeValue->context["ClassBodyDeclarationList"] = p1;

};



//beg_ClassBodyDeclarationList : 0
void R005_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclarationList_1Analyzer");
	StatementListToken *p = new StatementListToken();

	nodeValue->context["ClassBodyDeclarationList"] = P_Token(p);

};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
void R005_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassMemberDeclaration"];
	nodeValue->context["ClassBodyDeclaration"] = P_Token(p0);
};



//beg_ClassMemberDeclaration : InstanceInitializer
void R005_ClassMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InstanceInitializer"];

	nodeValue->context["ClassMemberDeclaration"] = P_Token(p0);

};



//beg_ClassMemberDeclaration : StaticInitializer
void R005_ClassMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["StaticInitializer"];

	nodeValue->context["ClassMemberDeclaration"] = P_Token(p0);
};



//beg_InstanceInitializer : Block
void R005_InstanceInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InstanceInitializer_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Block"];
	nodeValue->context["InstanceInitializer"] = p0;
};



//beg_StaticInitializer : 'static' Block
void R005_StaticInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StaticInitializer_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Block"];
	((StatementToken *)(p1.get()))->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	((StatementToken *)(p1.get()))->statementEntity->begLineNum= nodeValue->node->child_node_list[0]->lineNum;
	nodeValue->context["StaticInitializer"] = p1;
};



//beg_ModifierList : Modifier ModifierList
void R005_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ModifierList_0Analyzer");
	//TO DO  R005_ModifierList_0Analyzer
};



//beg_ModifierList : Modifier
void R005_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ModifierList_1Analyzer");
	//TO DO  R005_ModifierList_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R005_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContent_0Analyzer");
	//TO DO  R005_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R005_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContentStatements_0Analyzer");
	//TO DO  R005_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES
void R005_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContentStatements_1Analyzer");
	//TO DO  R005_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R005_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_0Analyzer");
	//TO DO  R005_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R005_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_1Analyzer");
	//TO DO  R005_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R005_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_2Analyzer");
	//TO DO  R005_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R005_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_3Analyzer");
	//TO DO  R005_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R005_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_4Analyzer");
	//TO DO  R005_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R005_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_5Analyzer");
	//TO DO  R005_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R005_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_6Analyzer");
	//TO DO  R005_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R005_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_7Analyzer");
	//TO DO  R005_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R005_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_8Analyzer");
	//TO DO  R005_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R005_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_9Analyzer");
	//TO DO  R005_NonPARENTHESES_9Analyzer
};



//beg_StatementEle : 'IDENTIFIER'
void R005_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_0Analyzer");
	//TO DO  R005_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R005_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_1Analyzer");
	//TO DO  R005_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R005_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_2Analyzer");
	//TO DO  R005_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R005_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_3Analyzer");
	//TO DO  R005_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R005_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_4Analyzer");
	//TO DO  R005_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R005_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_5Analyzer");
	//TO DO  R005_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R005_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_6Analyzer");
	//TO DO  R005_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R005_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_7Analyzer");
	//TO DO  R005_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R005_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_8Analyzer");
	//TO DO  R005_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R005_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_9Analyzer");
	//TO DO  R005_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R005_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_10Analyzer");
	//TO DO  R005_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R005_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_11Analyzer");
	//TO DO  R005_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R005_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_12Analyzer");
	//TO DO  R005_StatementEle_12Analyzer
};



//beg_StatementEle : 'EQUAL'
void R005_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_13Analyzer");
	//TO DO  R005_StatementEle_13Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R005_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_14Analyzer");
	//TO DO  R005_StatementEle_14Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R005_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_15Analyzer");
	//TO DO  R005_StatementEle_15Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R005_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_16Analyzer");
	//TO DO  R005_StatementEle_16Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R005_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_17Analyzer");
	//TO DO  R005_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R005_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_18Analyzer");
	//TO DO  R005_StatementEle_18Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R005_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_19Analyzer");
	//TO DO  R005_StatementEle_19Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R005_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_20Analyzer");
	//TO DO  R005_StatementEle_20Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R005_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_21Analyzer");
	//TO DO  R005_StatementEle_21Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R005_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_22Analyzer");
	//TO DO  R005_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR'
void R005_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_23Analyzer");
	//TO DO  R005_StatementEle_23Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R005_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_24Analyzer");
	//TO DO  R005_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS'
void R005_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_25Analyzer");
	//TO DO  R005_StatementEle_25Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R005_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_26Analyzer");
	//TO DO  R005_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R005_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_27Analyzer");
	//TO DO  R005_StatementEle_27Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R005_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_28Analyzer");
	//TO DO  R005_StatementEle_28Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R005_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_29Analyzer");
	//TO DO  R005_StatementEle_29Analyzer
};



//beg_StatementEle : 'QUESTION'
void R005_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_30Analyzer");
	//TO DO  R005_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R005_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_31Analyzer");
	//TO DO  R005_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R005_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_32Analyzer");
	//TO DO  R005_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R005_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_33Analyzer");
	//TO DO  R005_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R005_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_34Analyzer");
	//TO DO  R005_StatementEle_34Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R005_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_35Analyzer");
	//TO DO  R005_StatementEle_35Analyzer
};



//beg_StatementEle : 'SLASH'
void R005_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_36Analyzer");
	//TO DO  R005_StatementEle_36Analyzer
};



//beg_StatementEle : 'SPOT'
void R005_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_37Analyzer");
	//TO DO  R005_StatementEle_37Analyzer
};



//beg_StatementEle : 'STAR'
void R005_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_38Analyzer");
	//TO DO  R005_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R005_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_39Analyzer");
	//TO DO  R005_StatementEle_39Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R005_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_40Analyzer");
	//TO DO  R005_StatementEle_40Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R005_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_41Analyzer");
	//TO DO  R005_StatementEle_41Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R005_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_42Analyzer");
	//TO DO  R005_StatementEle_42Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R005_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_43Analyzer");
	//TO DO  R005_StatementEle_43Analyzer
};



//beg_StatementEle : 'TILDE'
void R005_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_44Analyzer");
	//TO DO  R005_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R005_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_45Analyzer");
	//TO DO  R005_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R005_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_46Analyzer");
	//TO DO  R005_StatementEle_46Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R005_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_47Analyzer");
	//TO DO  R005_StatementEle_47Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R005_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_48Analyzer");
	//TO DO  R005_StatementEle_48Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R005_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_49Analyzer");
	//TO DO  R005_StatementEle_49Analyzer
};



//beg_StatementEle : 'abstract'
void R005_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_50Analyzer");
	//TO DO  R005_StatementEle_50Analyzer
};



//beg_StatementEle : 'boolean'
void R005_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_51Analyzer");
	//TO DO  R005_StatementEle_51Analyzer
};



//beg_StatementEle : 'byte'
void R005_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_52Analyzer");
	//TO DO  R005_StatementEle_52Analyzer
};



//beg_StatementEle : 'char'
void R005_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_53Analyzer");
	//TO DO  R005_StatementEle_53Analyzer
};



//beg_StatementEle : 'class'
void R005_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_54Analyzer");
	//TO DO  R005_StatementEle_54Analyzer
};



//beg_StatementEle : 'default'
void R005_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_55Analyzer");
	//TO DO  R005_StatementEle_55Analyzer
};



//beg_StatementEle : 'double'
void R005_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_56Analyzer");
	//TO DO  R005_StatementEle_56Analyzer
};



//beg_StatementEle : 'enum'
void R005_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_57Analyzer");
	//TO DO  R005_StatementEle_57Analyzer
};



//beg_StatementEle : 'extends'
void R005_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_58Analyzer");
	//TO DO  R005_StatementEle_58Analyzer
};



//beg_StatementEle : 'final'
void R005_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_59Analyzer");
	//TO DO  R005_StatementEle_59Analyzer
};



//beg_StatementEle : 'float'
void R005_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_60Analyzer");
	//TO DO  R005_StatementEle_60Analyzer
};



//beg_StatementEle : 'implements'
void R005_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_61Analyzer");
	//TO DO  R005_StatementEle_61Analyzer
};



//beg_StatementEle : 'instanceof'
void R005_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_62Analyzer");
	//TO DO  R005_StatementEle_62Analyzer
};



//beg_StatementEle : 'int'
void R005_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_63Analyzer");
	//TO DO  R005_StatementEle_63Analyzer
};



//beg_StatementEle : 'interface'
void R005_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_64Analyzer");
	//TO DO  R005_StatementEle_64Analyzer
};



//beg_StatementEle : 'long'
void R005_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_65Analyzer");
	//TO DO  R005_StatementEle_65Analyzer
};



//beg_StatementEle : 'native'
void R005_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_66Analyzer");
	//TO DO  R005_StatementEle_66Analyzer
};



//beg_StatementEle : 'new'
void R005_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_67Analyzer");
	//TO DO  R005_StatementEle_67Analyzer
};



//beg_StatementEle : 'null'
void R005_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_68Analyzer");
	//TO DO  R005_StatementEle_68Analyzer
};



//beg_StatementEle : 'private'
void R005_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_69Analyzer");
	//TO DO  R005_StatementEle_69Analyzer
};



//beg_StatementEle : 'protected'
void R005_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_70Analyzer");
	//TO DO  R005_StatementEle_70Analyzer
};



//beg_StatementEle : 'public'
void R005_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_71Analyzer");
	//TO DO  R005_StatementEle_71Analyzer
};



//beg_StatementEle : 'short'
void R005_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_72Analyzer");
	//TO DO  R005_StatementEle_72Analyzer
};



//beg_StatementEle : 'static'
void R005_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_73Analyzer");
	//TO DO  R005_StatementEle_73Analyzer
};



//beg_StatementEle : 'super'
void R005_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_74Analyzer");
	//TO DO  R005_StatementEle_74Analyzer
};



//beg_StatementEle : 'synchronized'
void R005_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_75Analyzer");
	//TO DO  R005_StatementEle_75Analyzer
};



//beg_StatementEle : 'this'
void R005_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_76Analyzer");
	//TO DO  R005_StatementEle_76Analyzer
};



//beg_StatementEle : 'throws'
void R005_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_77Analyzer");
	//TO DO  R005_StatementEle_77Analyzer
};



//beg_StatementEle : 'transient'
void R005_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_78Analyzer");
	//TO DO  R005_StatementEle_78Analyzer
};



//beg_StatementEle : 'void'
void R005_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_79Analyzer");
	//TO DO  R005_StatementEle_79Analyzer
};



//beg_StatementEle : 'volatile'
void R005_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_80Analyzer");
	//TO DO  R005_StatementEle_80Analyzer
};



//beg_Modifier : 'public'
void R005_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_0Analyzer");
	//TO DO  R005_Modifier_0Analyzer
};



//beg_Modifier : 'protected'
void R005_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_1Analyzer");
	//TO DO  R005_Modifier_1Analyzer
};



//beg_Modifier : 'private'
void R005_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_2Analyzer");
	//TO DO  R005_Modifier_2Analyzer
};



//beg_Modifier : 'abstract'
void R005_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_3Analyzer");
	//TO DO  R005_Modifier_3Analyzer
};



//beg_Modifier : 'static'
void R005_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_4Analyzer");
	//TO DO  R005_Modifier_4Analyzer
};



//beg_Modifier : 'final'
void R005_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_5Analyzer");
	//TO DO  R005_Modifier_5Analyzer
};



//beg_Modifier : 'strictfp'
void R005_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_6Analyzer");
	//TO DO  R005_Modifier_6Analyzer
};



//beg_Modifier : 'default'
void R005_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_7Analyzer");
	//TO DO  R005_Modifier_7Analyzer
};



//beg_Modifier : 'volatile'
void R005_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_8Analyzer");
	//TO DO  R005_Modifier_8Analyzer
};



//beg_Modifier : 'synchronized'
void R005_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_9Analyzer");
	//TO DO  R005_Modifier_9Analyzer
};



//beg_Modifier : 'transient'
void R005_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_10Analyzer");
	//TO DO  R005_Modifier_10Analyzer
};



//beg_Modifier : 'native'
void R005_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_11Analyzer");
	//TO DO  R005_Modifier_11Analyzer
};



//beg_Modifier : Annotation
void R005_Modifier_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_12Analyzer");
	//TO DO  R005_Modifier_12Analyzer
};



//beg_MethodBody : Block
void R005_MethodBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodBody_0Analyzer");
	//TO DO  R005_MethodBody_0Analyzer
};



//beg_MethodBody : 'semicolon'
void R005_MethodBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodBody_1Analyzer");
	//TO DO  R005_MethodBody_1Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R005_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Block_0Analyzer");

	StatementToken *p = new StatementToken();
	P_StatementEntity statementEntity = P_StatementEntity(new StatementEntity);

	statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity = statementEntity;

	nodeValue->context["Block"] = P_Token(p);
};



//beg_BlockStatements : Block BlockStatements
void R005_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_0Analyzer");
	//TO DO  R005_BlockStatements_0Analyzer
};



//beg_BlockStatements : NonBrace BlockStatements
void R005_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_1Analyzer");
	//TO DO  R005_BlockStatements_1Analyzer
};



//beg_BlockStatements : 0
void R005_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_2Analyzer");

};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R005_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Annotation_0Analyzer");
	//TO DO  R005_Annotation_0Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier
void R005_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Annotation_1Analyzer");
	//TO DO  R005_Annotation_1Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R005_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArguments_0Analyzer");
	//TO DO  R005_TypeArguments_0Analyzer
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R005_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentList_0Analyzer");
	//TO DO  R005_TypeArgumentList_0Analyzer
};



//beg_TypeArgumentList : 0
void R005_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentList_1Analyzer");
	//TO DO  R005_TypeArgumentList_1Analyzer
};



//beg_NonANGLE_BRACKET : 'QUESTION'
void R005_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_0Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_0Analyzer
};



//beg_NonANGLE_BRACKET : 'extends'
void R005_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_1Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_1Analyzer
};



//beg_NonANGLE_BRACKET : 'super'
void R005_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_2Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_2Analyzer
};



//beg_NonANGLE_BRACKET : 'COMMA'
void R005_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_3Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_3Analyzer
};



//beg_NonANGLE_BRACKET : Identifier
void R005_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_4Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_4Analyzer
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
void R005_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_5Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_5Analyzer
};



//beg_NonANGLE_BRACKET : 'SPOT'
void R005_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_6Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_6Analyzer
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
void R005_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_7Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_7Analyzer
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R005_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_8Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_8Analyzer
};



//beg_NonBrace : StatementEle
void R005_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_0Analyzer");
	//TO DO  R005_NonBrace_0Analyzer
};



//beg_NonBrace : 'COMMA'
void R005_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_1Analyzer");
	//TO DO  R005_NonBrace_1Analyzer
};



//beg_NonBrace : 'semicolon'
void R005_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_2Analyzer");
	//TO DO  R005_NonBrace_2Analyzer
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
void R005_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_3Analyzer");
	//TO DO  R005_NonBrace_3Analyzer
};



//beg_NonBrace : 'LEFT_BRACKET'
void R005_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_4Analyzer");
	//TO DO  R005_NonBrace_4Analyzer
};



//beg_NonBrace : 'LEFT_PARENTHESES'
void R005_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_5Analyzer");
	//TO DO  R005_NonBrace_5Analyzer
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
void R005_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_6Analyzer");
	//TO DO  R005_NonBrace_6Analyzer
};



//beg_NonBrace : 'RIGHT_BRACKET'
void R005_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_7Analyzer");
	//TO DO  R005_NonBrace_7Analyzer
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
void R005_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_8Analyzer");
	//TO DO  R005_NonBrace_8Analyzer
};



//beg_UnannPrimitiveType : NumericType
void R005_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_0Analyzer");
	//TO DO  R005_UnannPrimitiveType_0Analyzer
};



//beg_UnannPrimitiveType : 'boolean'
void R005_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_1Analyzer");
	//TO DO  R005_UnannPrimitiveType_1Analyzer
};



//beg_NumericType : IntegralType
void R005_NumericType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NumericType_0Analyzer");
	//TO DO  R005_NumericType_0Analyzer
};



//beg_NumericType : FloatingPointType
void R005_NumericType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NumericType_1Analyzer");
	//TO DO  R005_NumericType_1Analyzer
};



//beg_IntegralType : 'byte'
void R005_IntegralType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_IntegralType_0Analyzer");
	//TO DO  R005_IntegralType_0Analyzer
};



//beg_IntegralType : 'short'
void R005_IntegralType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_IntegralType_1Analyzer");
	//TO DO  R005_IntegralType_1Analyzer
};



//beg_IntegralType : 'int'
void R005_IntegralType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_IntegralType_2Analyzer");
	//TO DO  R005_IntegralType_2Analyzer
};



//beg_IntegralType : 'long'
void R005_IntegralType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_IntegralType_3Analyzer");
	//TO DO  R005_IntegralType_3Analyzer
};



//beg_IntegralType : 'char'
void R005_IntegralType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_IntegralType_4Analyzer");
	//TO DO  R005_IntegralType_4Analyzer
};



//beg_FloatingPointType : 'float'
void R005_FloatingPointType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FloatingPointType_0Analyzer");
	//TO DO  R005_FloatingPointType_0Analyzer
};



//beg_FloatingPointType : 'double'
void R005_FloatingPointType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FloatingPointType_1Analyzer");
	//TO DO  R005_FloatingPointType_1Analyzer
};



//beg_Superclass : 'extends' ClassType
void R005_Superclass_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Superclass_0Analyzer");
	//TO DO  R005_Superclass_0Analyzer
};



//beg_ClassTypeEle : Identifier
void R005_ClassTypeEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_0Analyzer");
	//TO DO  R005_ClassTypeEle_0Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier
void R005_ClassTypeEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_1Analyzer");
	//TO DO  R005_ClassTypeEle_1Analyzer
};



//beg_ClassTypeEle : Identifier TypeArguments
void R005_ClassTypeEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_2Analyzer");
	//TO DO  R005_ClassTypeEle_2Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
void R005_ClassTypeEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_3Analyzer");
	//TO DO  R005_ClassTypeEle_3Analyzer
};



//beg_ClassType : ClassTypeEle
void R005_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassType_0Analyzer");
	//TO DO  R005_ClassType_0Analyzer
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
void R005_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassType_1Analyzer");
	//TO DO  R005_ClassType_1Analyzer
};



//beg_AnnotationList : Annotation AnnotationList
void R005_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationList_0Analyzer");
	//TO DO  R005_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R005_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationList_1Analyzer");
	//TO DO  R005_AnnotationList_1Analyzer
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
void R005_Superinterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Superinterfaces_0Analyzer");
	//TO DO  R005_Superinterfaces_0Analyzer
};



//beg_InterfaceTypeList : ClassType
void R005_InterfaceTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceTypeList_0Analyzer");
	//TO DO  R005_InterfaceTypeList_0Analyzer
};



//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
void R005_InterfaceTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceTypeList_1Analyzer");
	//TO DO  R005_InterfaceTypeList_1Analyzer
};



