#include "R004Analyzer.h"
#include "../../Util/Util.h"
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

#include "R004Analyzer_1.h"

void logR004(const string& s) {
//			Util::log(s);
}



P_NodeValue R004_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR004("R004_DefaultAnalyzer");
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


//beg_ele_begin : CompilationUnit
void R004_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["CompilationUnit"];
	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
void R004_CompilationUnit_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p2 == nullptr) {
		p2 = P_Token(new ClassListToken());
	}

	((ClassListToken *)(p2.get()))->packageName = p0->content;
	((ClassListToken *)(p2.get()))->importList = p1;
	nodeValue->context["CompilationUnit"] = p2;
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList
void R004_CompilationUnit_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];

	ClassListToken *p = new ClassListToken();
	p->packageName = p0->content;
	p->importList = p1;
	nodeValue->context["CompilationUnit"] = P_Token(p);
};



//beg_CompilationUnit : PackageDeclaration TypeDeclarationList
void R004_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p1 == nullptr) {
		p1 = P_Token(new ClassListToken());
	}

	((ClassListToken *)(p1.get()))->packageName = p0->content;

	nodeValue->context["CompilationUnit"] = p1;
};



//beg_CompilationUnit : ImportDeclarationList TypeDeclarationList
void R004_CompilationUnit_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p1 == nullptr) {
		p1 = P_Token(new ClassListToken());
	}

	((ClassListToken *)(p1.get()))->importList = p0;

	nodeValue->context["CompilationUnit"] = p1;
};



//beg_CompilationUnit : PackageDeclaration
void R004_CompilationUnit_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"];

	ClassListToken *p = new ClassListToken();
	p->packageName = p0->content;
	nodeValue->context["CompilationUnit"] = P_Token(p);
};



//beg_CompilationUnit : ImportDeclarationList
void R004_CompilationUnit_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_5Analyzer");
	//TO DO  R004_CompilationUnit_5Analyzer

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclarationList"];

	ClassListToken *p = new ClassListToken();
	p->importList = p0;

	nodeValue->context["CompilationUnit"] = P_Token(p);

};



//beg_CompilationUnit : TypeDeclarationList
void R004_CompilationUnit_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_CompilationUnit_6Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p0 == nullptr) {
		p0 = P_Token(new ClassListToken());
	}


	nodeValue->context["CompilationUnit"] = p0;
};



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
void R004_PackageDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_PackageDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"];
	nodeValue->context["PackageDeclaration"] = p1;
};


//beg_PackageDeclaration : ModifierList 'package' DetailIdentifier 'semicolon'
void R004_PackageDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_PackageDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"];
	nodeValue->context["PackageDeclaration"] = p2;
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R004_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DetailIdentifier_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"];
	p2->content = p0->content + "." + p2->content;
	nodeValue->context["DetailIdentifier"] = p2;
};



//beg_DetailIdentifier : Identifier
void R004_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DetailIdentifier_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	nodeValue->context["DetailIdentifier"] = p0;
};



//beg_Identifier : 'IDENTIFIER'
void R004_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_ImportDeclarationList : ImportDeclaration ImportDeclarationList
void R004_ImportDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];

	((ImportListToken *)(p1.get()))->list.push_front(((ImportToken *)(p0.get()))->importEntity);


	nodeValue->context["ImportDeclarationList"] = p1;
};



//beg_ImportDeclarationList : ImportDeclaration
void R004_ImportDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclarationList_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclaration"];
	ImportListToken *p = new ImportListToken();
	p->list.push_front(((ImportToken *)(p0.get()))->importEntity);


	nodeValue->context["ImportDeclarationList"] = P_Token(p);

};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT_STAR' 'semicolon'
void R004_ImportDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclaration_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"];
	ImportToken *p = new ImportToken();
	P_ImportEntity importEntity = P_ImportEntity(new ImportEntity());
	importEntity->name = p2->content + ".*";
	importEntity->isStatic = true;
	p->importEntity = importEntity;


	nodeValue->context["ImportDeclaration"] = P_Token(p);
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
void R004_ImportDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"];
	ImportToken *p = new ImportToken();
	P_ImportEntity importEntity = P_ImportEntity(new ImportEntity);
	importEntity->name = p2->content;
	importEntity->isStatic = true;
	p->importEntity = importEntity;


	nodeValue->context["ImportDeclaration"] = P_Token(p);
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT_STAR' 'semicolon'
void R004_ImportDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"];
	ImportToken *p = new ImportToken();
	P_ImportEntity importEntity = P_ImportEntity(new ImportEntity);
	importEntity->name = p1->content + ".*";
	p->importEntity = importEntity;


	nodeValue->context["ImportDeclaration"] = P_Token(p);
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'semicolon'
void R004_ImportDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"];
	ImportToken *p = new ImportToken();
	P_ImportEntity importEntity = P_ImportEntity(new ImportEntity);
	importEntity->name = p1->content;
	p->importEntity = importEntity;


	nodeValue->context["ImportDeclaration"] = P_Token(p);
};


//beg_TypeDeclarationList : TypeDeclaration
void R004_TypeDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];

	ClassListToken* p = new ClassListToken();
	if (p0 != nullptr) {
		p->list.push_front(((ClassToken *)(p0.get()))->classEntity);
	}

	nodeValue->context["TypeDeclarationList"] = P_Token(p);
};



//beg_TypeDeclaration : ClassDeclaration
void R004_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
	nodeValue->context["TypeDeclaration"] = p0;
};



//beg_TypeDeclaration : InterfaceDeclaration
void R004_TypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];
	nodeValue->context["TypeDeclaration"] = p0;
};



//beg_TypeDeclaration : 'semicolon'
void R004_TypeDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclaration_2Analyzer");
};



//beg_ClassDeclaration : NormalClassDeclaration
void R004_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassDeclaration_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_ClassDeclaration : EnumDeclaration
void R004_ClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
void R004_InterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_InterfaceDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalInterfaceDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
void R004_InterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_InterfaceDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass  Superinterfaces ClassBody
void R004_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p6 = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p6;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces ClassBody
void R004_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p5;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces ClassBody
void R004_NormalClassDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p5;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces ClassBody
void R004_NormalClassDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces ClassBody
void R004_NormalClassDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p5;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces ClassBody
void R004_NormalClassDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_5Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces ClassBody
void R004_NormalClassDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_6Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces ClassBody
void R004_NormalClassDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_7Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p3;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass  ClassBody
void R004_NormalClassDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_8Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p5;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass ClassBody
void R004_NormalClassDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_9Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass ClassBody
void R004_NormalClassDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_10Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass ClassBody
void R004_NormalClassDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_11Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p3;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
void R004_NormalClassDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_12Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p4;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
void R004_NormalClassDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_13Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	classEntity->statementList = p3;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
void R004_NormalClassDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_14Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	classEntity->statementList = p3;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier ClassBody
void R004_NormalClassDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_15Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalClassDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;

	classEntity->statementList = p2;


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};




//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces EnumBody
void R004_EnumDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumDeclaration_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["EnumBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "EnumDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;

	classEntity->statementList = p4;


	nodeValue->context["EnumDeclaration"] = P_Token(p);

};



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces EnumBody
void R004_EnumDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumDeclaration_1Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["EnumBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "EnumDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;

	classEntity->statementList = p3;


	nodeValue->context["EnumDeclaration"] = P_Token(p);


};



//beg_EnumDeclaration : ModifierList 'enum' Identifier EnumBody
void R004_EnumDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumDeclaration_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["EnumBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "EnumDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};




//beg_EnumDeclaration : 'enum' Identifier EnumBody
void R004_EnumDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumBody"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "EnumDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;

	classEntity->statementList = p2;


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};





//beg_NormalInterfaceDeclaration : 'interface' Identifier ClassBody
void R004_NormalInterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p2;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ClassBody
void R004_NormalInterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ClassBody
void R004_NormalInterfaceDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ClassBody
void R004_NormalInterfaceDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p4;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces ClassBody
void R004_NormalInterfaceDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_4Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces ClassBody
void R004_NormalInterfaceDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_5Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p4;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces ClassBody
void R004_NormalInterfaceDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_6Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p4;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces ClassBody
void R004_NormalInterfaceDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalInterfaceDeclaration_7Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p5 = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "NormalInterfaceDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p5;

	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
void R004_ExtendsInterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ExtendsInterfaces_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_AnnotationTypeDeclaration : 'AT' 'interface' Identifier ClassBody
void R004_AnnotationTypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationTypeDeclaration_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "AnnotationTypeDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;

	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT' 'interface' Identifier ClassBody
void R004_AnnotationTypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationTypeDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p3->content;
	classEntity->type = "AnnotationTypeDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p4;

	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier ClassBody
void R004_AnnotationTypeDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationTypeDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	classEntity->type = "AnnotationTypeDeclaration";
	classEntity->index = nodeValue->node->child_node_list[0]->index;
	classEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p2;

	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier ClassBody
void R004_AnnotationTypeDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationTypeDeclaration_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ModifierList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];


	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p2->content;
	classEntity->type = "AnnotationTypeDeclaration";
	classEntity->index = ((ModifierListToken *)p0.get())->list[0]->index;
	classEntity->lineNum = ((ModifierListToken *)p0.get())->list[0]->lineNum;
	p->classEntity = classEntity;
	classEntity->statementList = p3;

	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
void R004_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBody_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
	nodeValue->context["ClassBody"] = p1;

};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R004_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclarationList_0Analyzer");


	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassBodyDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];

	if (p1 == nullptr) {
		StatementListToken *p = new StatementListToken();
		p1 = P_Token(p);
	}

	((StatementListToken *)(p1.get()))->list.push_front(((StatementToken *)(p0.get()))->statementEntity);


	nodeValue->context["ClassBodyDeclarationList"] = p1;


};



//beg_ClassBodyDeclarationList : 0
void R004_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclarationList_1Analyzer");
	StatementListToken *p = new StatementListToken();
	nodeValue->context["ClassBodyDeclarationList"] = P_Token(p);

};



//beg_ClassBodyDeclaration : ClassStatementPrefix 'semicolon'
void R004_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassStatementPrefix"];

	if (p0 == nullptr) {
		StatementToken *p = new StatementToken();
		StatementEntity *statementEntity = new StatementEntity();
		statementEntity->begLineNum = nodeValue->node->child_node_list[1]->lineNum;
		statementEntity->begIndex = nodeValue->node->child_node_list[1]->index;
		p->statementEntity = P_StatementEntity(statementEntity);
		p0 = P_Token(p);
	}

	((StatementToken*)(p0.get()))->statementEntity->endLineNum = nodeValue->node->child_node_list[1]->lineNum;
	((StatementToken*)(p0.get()))->statementEntity->endIndex = nodeValue->node->child_node_list[1]->index;
	((StatementToken*)(p0.get()))->statementEntity->endWith = "semicolon";

	nodeValue->context["ClassBodyDeclaration"] = p0;
};



//beg_ClassBodyDeclaration : ClassStatementPrefix Block
void R004_ClassBodyDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassStatementPrefix"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Block"];

	if (p0 == nullptr) {
		StatementToken *p = new StatementToken();
		StatementEntity *statementEntity = new StatementEntity();
		statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
		statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
		p->statementEntity = P_StatementEntity(statementEntity);
		p0 = P_Token(p);
	}

	((StatementToken*)(p0.get()))->statementEntity->endLineNum = ((StatementToken *)p1.get())->statementEntity->endLineNum;
	((StatementToken*)(p0.get()))->statementEntity->endIndex = ((StatementToken *)p1.get())->statementEntity->endIndex;
	((StatementToken*)(p0.get()))->statementEntity->endWith = "Block";

	nodeValue->context["ClassBodyDeclaration"] = p0;

};



//beg_ClassStatementPrefix : NonBraceAndSemicolon ClassStatementPrefix
void R004_ClassStatementPrefix_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassStatementPrefix_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NonBraceAndSemicolon"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassStatementPrefix"];

	if (p1 == nullptr) {
		StatementToken *p = new StatementToken();
		StatementEntity *statementEntity = new StatementEntity();
		p->statementEntity = P_StatementEntity(statementEntity);
		p1 = P_Token(p);
	}

	((StatementToken*)(p1.get()))->statementEntity->begLineNum = ((StatementToken*)(p0.get()))->statementEntity->begLineNum;
	((StatementToken*)(p1.get()))->statementEntity->begIndex = ((StatementToken*)(p0.get()))->statementEntity->begIndex;

	nodeValue->context["ClassStatementPrefix"] = p1;
};



//beg_ClassStatementPrefix : 0
void R004_ClassStatementPrefix_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassStatementPrefix_1Analyzer");
	//TO DO  R004_ClassStatementPrefix_1Analyzer
};



//beg_NonBraceAndSemicolon : StatementEle
void R004_NonBraceAndSemicolon_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBraceAndSemicolon_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["StatementEle"];
	nodeValue->context["NonBraceAndSemicolon"] = p0;
};



//beg_NonBraceAndSemicolon : 'COMMA'
void R004_NonBraceAndSemicolon_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBraceAndSemicolon_1Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["NonBraceAndSemicolon"] = P_Token(p);
};



//beg_NonBraceAndSemicolon : AnnotationContent
void R004_NonBraceAndSemicolon_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBraceAndSemicolon_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationContent"];
	nodeValue->context["NonBraceAndSemicolon"] = p0;

};



//beg_NonBraceAndSemicolon : DimExpr
void R004_NonBraceAndSemicolon_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBraceAndSemicolon_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["DimExpr"];
	nodeValue->context["NonBraceAndSemicolon"] = p0;
};



//beg_NonBraceAndSemicolon : TypeArguments
void R004_NonBraceAndSemicolon_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBraceAndSemicolon_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	nodeValue->context["NonBraceAndSemicolon"] = p0;
};



//beg_ModifierList : Modifier ModifierList
void R004_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ModifierList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Modifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ModifierList"];

	((ModifierListToken *)(p1.get()))->list.push_front(((ModifierToken *)(p0.get()))->modifierEntity);
	nodeValue->context["ModifierList"] = p1;
};



//beg_ModifierList : Modifier
void R004_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ModifierList_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Modifier"];
	ModifierListToken *p = new ModifierListToken();
	p->list.push_front(((ModifierToken *)(p0.get()))->modifierEntity);

	nodeValue->context["ModifierList"] = P_Token(p);
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R004_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationContent_0Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["AnnotationContent"] = P_Token(p);
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R004_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationContentStatements_0Analyzer");
	//TO DO  R004_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R004_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationContentStatements_1Analyzer");
	//TO DO  R004_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R004_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_0Analyzer");
	//TO DO  R004_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R004_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_1Analyzer");
	//TO DO  R004_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R004_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_2Analyzer");
	//TO DO  R004_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R004_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_3Analyzer");
	//TO DO  R004_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R004_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_4Analyzer");
	//TO DO  R004_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R004_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_5Analyzer");
	//TO DO  R004_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R004_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_6Analyzer");
	//TO DO  R004_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R004_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_7Analyzer");
	//TO DO  R004_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R004_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_8Analyzer");
	//TO DO  R004_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R004_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_9Analyzer");
	//TO DO  R004_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : AnnotationContent
void R004_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonPARENTHESES_10Analyzer");
	//TO DO  R004_NonPARENTHESES_10Analyzer
};



//beg_StatementEle : 'IDENTIFIER'
void R004_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_0Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'AND'
void R004_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_1Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'AND_EQUAL'
void R004_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_2Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'AT'
void R004_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_3Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'AT_INTERFACE'
void R004_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_4Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'BIT_AND'
void R004_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_5Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'BIT_OR'
void R004_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_6Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'BooleanLiteral'
void R004_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_7Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'CARET'
void R004_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_8Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'COLON'
void R004_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_9Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'CharacterLiteral'
void R004_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_10Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'DB_EQUAL'
void R004_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_11Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R004_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_12Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'EQUAL'
void R004_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_13Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'FloatingPointLiteral'
void R004_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_14Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'GT_EQUAL'
void R004_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_15Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'IntegerLiteral'
void R004_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_16Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'LAMBDA_TO'
void R004_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_17Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'LEFT_SHIFT'
void R004_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_18Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R004_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_19Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'LT_EQUAL'
void R004_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_20Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'MULTI_EQUAL'
void R004_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_21Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'NOT_EQUAL'
void R004_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_22Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'OR'
void R004_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_23Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'OR_EQUAL'
void R004_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_24Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'PLUS'
void R004_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_25Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'PLUS_EQUAL'
void R004_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_26Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'PRECENTAGE'
void R004_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_27Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R004_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_28Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R004_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_29Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'QUESTION'
void R004_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_30Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R004_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_31Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R004_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_32Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R004_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_33Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R004_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_34Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R004_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_35Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'SLASH'
void R004_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_36Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'SPOT'
void R004_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_37Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'STAR'
void R004_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_38Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'SUBTRACT'
void R004_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_39Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R004_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_40Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'SURPRISE'
void R004_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_41Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'StringLiteral'
void R004_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_42Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'THREE_SPOT'
void R004_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_43Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'TILDE'
void R004_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_44Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'TWO_COLON'
void R004_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_45Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'TWO_PLUS'
void R004_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_46Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R004_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_47Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'TypeNameId'
void R004_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_48Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'XOR_EQUAL'
void R004_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_49Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'abstract'
void R004_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_50Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'boolean'
void R004_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_51Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'byte'
void R004_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_52Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'char'
void R004_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_53Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'class'
void R004_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_54Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'default'
void R004_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_55Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'double'
void R004_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_56Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'enum'
void R004_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_57Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'extends'
void R004_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_58Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'final'
void R004_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_59Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'float'
void R004_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_60Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'implements'
void R004_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_61Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'instanceof'
void R004_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_62Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'int'
void R004_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_63Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'interface'
void R004_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_64Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'long'
void R004_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_65Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'native'
void R004_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_66Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'new'
void R004_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_67Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'null'
void R004_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_68Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'private'
void R004_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_69Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'protected'
void R004_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_70Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'public'
void R004_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_71Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'short'
void R004_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_72Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'static'
void R004_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_73Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'super'
void R004_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_74Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'synchronized'
void R004_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_75Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'this'
void R004_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_76Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'throws'
void R004_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_77Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'transient'
void R004_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_78Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'void'
void R004_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_79Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};



//beg_StatementEle : 'volatile'
void R004_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_80Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[0]->index;
	nodeValue->context["StatementEle"] = P_Token(p);
};









//beg_Modifier : 'public'
void R004_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_0Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'protected'
void R004_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_1Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'private'
void R004_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_2Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'abstract'
void R004_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_3Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'static'
void R004_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_4Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'final'
void R004_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_5Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'strictfp'
void R004_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_6Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'default'
void R004_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_7Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'volatile'
void R004_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_8Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'synchronized'
void R004_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_9Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'transient'
void R004_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_10Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};



//beg_Modifier : 'native'
void R004_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_11Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = nodeValue->node->child_node_list[0]->content;
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};

//beg_Modifier : Annotation
void R004_Modifier_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_12Analyzer");


	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = "Annotation";
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Modifier"] = P_Token(p);
};


//beg_MethodBody : Block
void R004_MethodBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodBody_0Analyzer");
	//TO DO  R004_MethodBody_0Analyzer
};



//beg_MethodBody : 'semicolon'
void R004_MethodBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodBody_1Analyzer");
	//TO DO  R004_MethodBody_1Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R004_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Block_0Analyzer");


	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();

	statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["Block"] = P_Token(p);


};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
void R004_Block_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Block_1Analyzer");
	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();

	statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["Block"] = P_Token(p);
};



//beg_BlockStatements : Block BlockStatements
void R004_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_BlockStatements_0Analyzer");
	//TO DO  R004_BlockStatements_0Analyzer
};



//beg_BlockStatements : NonBrace BlockStatements
void R004_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_BlockStatements_1Analyzer");
	//TO DO  R004_BlockStatements_1Analyzer
};



//beg_BlockStatements : 0
void R004_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_BlockStatements_2Analyzer");
	//TO DO  R004_BlockStatements_2Analyzer
};



//beg_NonBrace : StatementEle
void R004_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_0Analyzer");
	//TO DO  R004_NonBrace_0Analyzer
};



//beg_NonBrace : 'COMMA'
void R004_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_1Analyzer");
	//TO DO  R004_NonBrace_1Analyzer
};



//beg_NonBrace : 'semicolon'
void R004_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_2Analyzer");
	//TO DO  R004_NonBrace_2Analyzer
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
void R004_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_3Analyzer");
	//TO DO  R004_NonBrace_3Analyzer
};



//beg_NonBrace : 'LEFT_BRACKET'
void R004_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_4Analyzer");
	//TO DO  R004_NonBrace_4Analyzer
};



//beg_NonBrace : 'LEFT_PARENTHESES'
void R004_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_5Analyzer");
	//TO DO  R004_NonBrace_5Analyzer
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
void R004_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_6Analyzer");
	//TO DO  R004_NonBrace_6Analyzer
};



//beg_NonBrace : 'RIGHT_BRACKET'
void R004_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_7Analyzer");
	//TO DO  R004_NonBrace_7Analyzer
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
void R004_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonBrace_8Analyzer");
	//TO DO  R004_NonBrace_8Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R004_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Annotation_0Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = "Annotation";
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Annotation"] = P_Token(p);

};


//beg_Annotation : 'AT' DetailIdentifier
void R004_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Annotation_1Analyzer");

	ModifierToken *p = new ModifierToken();
	P_ModifierEntity modifierEntity = P_ModifierEntity(new ModifierEntity);
	modifierEntity->name = "Annotation";
	modifierEntity->index = nodeValue->node->child_node_list[0]->index;
	modifierEntity->lineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->modifierEntity = modifierEntity;

	nodeValue->context["Annotation"] = P_Token(p);
};







//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
void R004_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArguments_0Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
void R004_TypeArguments_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArguments_1Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
void R004_TypeArguments_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArguments_2Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R004_TypeArguments_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArguments_3Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArgumentListL2 : TypeArguments TypeArgumentListL2
void R004_TypeArgumentListL2_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL2_0Analyzer");
	//TO DO  R004_TypeArgumentListL2_0Analyzer
};



//beg_TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
void R004_TypeArgumentListL2_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL2_1Analyzer");
	//TO DO  R004_TypeArgumentListL2_1Analyzer
};



//beg_TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
void R004_TypeArgumentListL2_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL2_2Analyzer");
	//TO DO  R004_TypeArgumentListL2_2Analyzer
};



//beg_TypeArgumentListL1 : TypeArguments TypeArgumentListL1
void R004_TypeArgumentListL1_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL1_0Analyzer");
	//TO DO  R004_TypeArgumentListL1_0Analyzer
};



//beg_TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
void R004_TypeArgumentListL1_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL1_1Analyzer");
	//TO DO  R004_TypeArgumentListL1_1Analyzer
};



//beg_TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
void R004_TypeArgumentListL1_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentListL1_2Analyzer");
	//TO DO  R004_TypeArgumentListL1_2Analyzer
};





//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R004_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentList_0Analyzer");
	//TO DO  R004_TypeArgumentList_1Analyzer
};



//beg_TypeArgumentList : 0
void R004_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeArgumentList_1Analyzer");
	//TO DO  R004_TypeArgumentList_2Analyzer
};



//beg_NonANGLE_BRACKET : 'QUESTION'
void R004_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'extends'
void R004_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'super'
void R004_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_2Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'COMMA'
void R004_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_3Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : Identifier
void R004_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_4Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
void R004_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_5Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'SPOT'
void R004_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_6Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
void R004_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_7Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R004_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_8Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NonANGLE_BRACKET : TypeArguments
void R004_NonANGLE_BRACKET_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonANGLE_BRACKET_9Analyzer");
	//TO DO  R004_NonANGLE_BRACKET_9Analyzer
};



//beg_UnannPrimitiveType : NumericType
void R004_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_UnannPrimitiveType_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_UnannPrimitiveType : 'boolean'
void R004_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_UnannPrimitiveType_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NumericType : IntegralType
void R004_NumericType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NumericType_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_NumericType : FloatingPointType
void R004_NumericType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NumericType_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_IntegralType : 'byte'
void R004_IntegralType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_IntegralType_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_IntegralType : 'short'
void R004_IntegralType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_IntegralType_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_IntegralType : 'int'
void R004_IntegralType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_IntegralType_2Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_IntegralType : 'long'
void R004_IntegralType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_IntegralType_3Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_IntegralType : 'char'
void R004_IntegralType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_IntegralType_4Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_FloatingPointType : 'float'
void R004_FloatingPointType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_FloatingPointType_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_FloatingPointType : 'double'
void R004_FloatingPointType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_FloatingPointType_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_Superclass : 'extends' ClassType
void R004_Superclass_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Superclass_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};




//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
void R004_ClassTypeEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassTypeEle_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};


//beg_ClassTypeEle : Identifier TypeArguments
void R004_ClassTypeEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassTypeEle_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};


//beg_ClassTypeEle : AnnotationList Identifier
void R004_ClassTypeEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassTypeEle_2Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};


//beg_ClassTypeEle : Identifier
void R004_ClassTypeEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassTypeEle_3Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
void R004_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassType_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_ClassType : ClassTypeEle
void R004_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassType_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};







//beg_AnnotationList : Annotation AnnotationList
void R004_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationList_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_AnnotationList : Annotation
void R004_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationList_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
void R004_Superinterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Superinterfaces_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
void R004_InterfaceTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_InterfaceTypeList_0Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};




//beg_InterfaceTypeList : ClassType
void R004_InterfaceTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_InterfaceTypeList_1Analyzer");
	//TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer
};



//beg_DimExpr : 'LEFT_BRACKET' DimStatements 'RIGHT_BRACKET'
void R004_DimExpr_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DimExpr_0Analyzer");
	StatementToken *p = new StatementToken();
	p->statementEntity = P_StatementEntity(new StatementEntity);
	p->statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	p->statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["DimExpr"] = P_Token(p);
};



//beg_DimStatements : DimExpr DimStatements
void R004_DimStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DimStatements_0Analyzer");
	//TO DO  R004_DimStatements_0Analyzer
};



//beg_DimStatements : NonDim DimStatements
void R004_DimStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DimStatements_1Analyzer");
	//TO DO  R004_DimStatements_1Analyzer
};



//beg_DimStatements : 0
void R004_DimStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_DimStatements_2Analyzer");
	//TO DO  R004_DimStatements_2Analyzer
};



//beg_NonDim : StatementEle
void R004_NonDim_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_0Analyzer");
	//TO DO  R004_NonDim_0Analyzer
};



//beg_NonDim : 'COMMA'
void R004_NonDim_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_1Analyzer");
	//TO DO  R004_NonDim_1Analyzer
};



//beg_NonDim : 'semicolon'
void R004_NonDim_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_2Analyzer");
	//TO DO  R004_NonDim_2Analyzer
};



//beg_NonDim : 'LEFT_BRACE'
void R004_NonDim_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_3Analyzer");
	//TO DO  R004_NonDim_3Analyzer
};



//beg_NonDim : 'LEFT_PARENTHESES'
void R004_NonDim_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_4Analyzer");
	//TO DO  R004_NonDim_4Analyzer
};



//beg_NonDim : 'LEFT_ANGLE_BRACKET'
void R004_NonDim_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_5Analyzer");
	//TO DO  R004_NonDim_5Analyzer
};



//beg_NonDim : 'RIGHT_BRACE'
void R004_NonDim_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_6Analyzer");
	//TO DO  R004_NonDim_6Analyzer
};



//beg_NonDim : 'COMMA_RIGHT_BRACE'
void R004_NonDim_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_7Analyzer");
	//TO DO  R004_NonDim_7Analyzer
};



//beg_NonDim : 'RIGHT_PARENTHESES'
void R004_NonDim_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_8Analyzer");
	//TO DO  R004_NonDim_8Analyzer
};



//beg_NonDim : 'RIGHT_ANGLE_BRACKET'
void R004_NonDim_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NonDim_9Analyzer");
	//TO DO  R004_NonDim_9Analyzer
};



//beg_EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA' EnumBodyDeclarations 'RIGHT_BRACE'
void R004_EnumBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["EnumConstantList"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["EnumBodyDeclarations"];
	((StatementToken *)p1.get())->statementEntity->type = "EnumConstantList";
	((StatementListToken *)p3.get())->list.push_front(((StatementToken *)p1.get())->statementEntity);
	nodeValue->context["EnumBody"] = p3;
};



//beg_EnumBody : 'LEFT_BRACE' 'COMMA' EnumBodyDeclarations 'RIGHT_BRACE'
void R004_EnumBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumBodyDeclarations"];

	nodeValue->context["EnumBody"] = p2;
};



//beg_EnumBody : 'LEFT_BRACE' EnumConstantList EnumBodyDeclarations 'RIGHT_BRACE'
void R004_EnumBody_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["EnumConstantList"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumBodyDeclarations"];
	((StatementToken *)p1.get())->statementEntity->type = "EnumConstantList";
	((StatementListToken *)p2.get())->list.push_front(((StatementToken *)p1.get())->statementEntity);
	nodeValue->context["EnumBody"] = p2;
};



//beg_EnumBody : 'LEFT_BRACE' EnumBodyDeclarations 'RIGHT_BRACE'
void R004_EnumBody_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["EnumBodyDeclarations"];

	nodeValue->context["EnumBody"] = p1;
};



//beg_EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA' 'RIGHT_BRACE'
void R004_EnumBody_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_4Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["EnumConstantList"];
	StatementListToken *p = new StatementListToken();
	((StatementToken *)p1.get())->statementEntity->type = "EnumConstantList";
	p->list.push_front(((StatementToken *)p1.get())->statementEntity);

	nodeValue->context["EnumBody"] = P_Token(p);
};


//beg_EnumBody : 'LEFT_BRACE' 'COMMA' 'RIGHT_BRACE'
void R004_EnumBody_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_5Analyzer");
	//TO DO  R004_EnumBody_2Analyzer
};


//beg_EnumBody : 'LEFT_BRACE' EnumConstantList 'RIGHT_BRACE'
void R004_EnumBody_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_6Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["EnumConstantList"];
	StatementListToken *p = new StatementListToken();
	((StatementToken *)p1.get())->statementEntity->type = "EnumConstantList";
	p->list.push_front(((StatementToken *)p1.get())->statementEntity);

	nodeValue->context["EnumBody"] = P_Token(p);

};


//beg_EnumBody : 'LEFT_BRACE' 'RIGHT_BRACE'
void R004_EnumBody_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBody_7Analyzer");
	//TO DO  R004_EnumBody_0Analyzer
};




//beg_EnumConstantList : EnumConstantEleList 'COMMA' EnumConstantList
void R004_EnumConstantList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR004("R004_EnumConstantList_0Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantEleList"];
   P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumConstantList"];
   
   ((StatementToken*)p2.get())->statementEntity->begIndex = ((StatementToken*)p0.get())->statementEntity->begIndex;
   ((StatementToken*)p2.get())->statementEntity->begLineNum = ((StatementToken*)p0.get())->statementEntity->begLineNum;
   nodeValue->context["EnumConstantList"] = p2;
};



//beg_EnumConstantList : EnumConstantEleList
void R004_EnumConstantList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR004("R004_EnumConstantList_1Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantEleList"];
   nodeValue->context["EnumConstantList"] = p0;
};



//beg_EnumConstantEleList : EnumConstantEle EnumConstantEleList
void R004_EnumConstantEleList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR004("R004_EnumConstantEleList_0Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantEle"];
   nodeValue->context["EnumConstantEleList"] = p0;
};



//beg_EnumConstantEleList : EnumConstantEle
void R004_EnumConstantEleList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR004("R004_EnumConstantEleList_1Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantEle"];
   nodeValue->context["EnumConstantEleList"] = p0;
};



//beg_EnumConstantEle : StatementEle
void R004_EnumConstantEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumConstantEle_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["StatementEle"];
	nodeValue->context["EnumConstantEle"] = p0;
};



//beg_EnumConstantEle : AnnotationContent
void R004_EnumConstantEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumConstantEle_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationContent"];
	nodeValue->context["EnumConstantEle"] = p0;
};



//beg_EnumConstantEle : Block
void R004_EnumConstantEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumConstantEle_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Block"];
	nodeValue->context["EnumConstantEle"] = p0;
};



//beg_EnumBodyDeclarations : 'semicolon' ClassBodyDeclarationList
void R004_EnumBodyDeclarations_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_EnumBodyDeclarations_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
	nodeValue->context["EnumBodyDeclarations"] = p1;
};



