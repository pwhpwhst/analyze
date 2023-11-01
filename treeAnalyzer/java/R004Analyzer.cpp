
#include "R004Analyzer.h"
#include "../../symbols/java/ClassListToken.h"
#include "../../symbols/java/ClassToken.h"
#include "../../symbols/java/ImportToken.h"
#include "../../symbols/java/ImportListToken.h"
#include "../../symbols/java/ImportEntity.h"
#include<iostream>
#include <sstream>
using namespace std;

#include "R004Analyzer_1.h"

void logR004(const string& s) {
		//cout<<s<<endl;
}



P_NodeValue R004_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack,  Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

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

	if (p2==nullptr) {
		p2= P_Token(new ClassListToken());
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
	//TO DO  R004_CompilationUnit_6Analyzer
};



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
void R004_PackageDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_PackageDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"];
	nodeValue->context["PackageDeclaration"] = p1;
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



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
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



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
void R004_ImportDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ImportDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"];
	ImportToken *p = new ImportToken();
	P_ImportEntity importEntity = P_ImportEntity(new ImportEntity);
	importEntity->name = p1->content+".*";
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



//beg_TypeDeclarationList : TypeDeclaration TypeDeclarationList
void R004_TypeDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];

	if (p0!=nullptr) {
		((ClassListToken *)(p1.get()))->list.push_front(((ClassToken *)(p0.get()))->classEntity);
	}
	

	nodeValue->context["TypeDeclarationList"] = p1;
};



//beg_TypeDeclarationList : TypeDeclaration
void R004_TypeDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclarationList_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];

	ClassListToken* p = new ClassListToken();
	if (p0!=nullptr) {
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



//beg_TypeDeclaration : 'semicolon'
void R004_TypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_TypeDeclaration_1Analyzer");
};



//beg_ClassDeclaration : NormalClassDeclaration
void R004_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassDeclaration_0Analyzer");
	
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
void R004_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_NormalClassDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	ClassToken *p = new ClassToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	p->classEntity = classEntity;

	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_ClassBody : 'LEFT_BRACE'
void R004_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBody_0Analyzer");
	//TO DO  R004_ClassBody_0Analyzer
};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R004_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclarationList_0Analyzer");
	//TO DO  R004_ClassBodyDeclarationList_0Analyzer
};



//beg_ClassBodyDeclarationList : 0
void R004_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclarationList_1Analyzer");
	//TO DO  R004_ClassBodyDeclarationList_1Analyzer
};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
void R004_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassBodyDeclaration_0Analyzer");
	//TO DO  R004_ClassBodyDeclaration_0Analyzer
};



//beg_ClassMemberDeclaration : MethodDeclaration
void R004_ClassMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ClassMemberDeclaration_0Analyzer");
	//TO DO  R004_ClassMemberDeclaration_0Analyzer
};



//beg_MethodDeclaration : ModifierList MethodHeader MethodBody
void R004_MethodDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodDeclaration_0Analyzer");
	//TO DO  R004_MethodDeclaration_0Analyzer
};



//beg_MethodDeclaration : MethodHeader MethodBody
void R004_MethodDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodDeclaration_1Analyzer");
	//TO DO  R004_MethodDeclaration_1Analyzer
};



//beg_MethodHeader : 'void' MethodDeclarator
void R004_MethodHeader_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodHeader_0Analyzer");
	//TO DO  R004_MethodHeader_0Analyzer
};



//beg_MethodDeclarator : Identifier AnnotationContent
void R004_MethodDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_MethodDeclarator_0Analyzer");
	//TO DO  R004_MethodDeclarator_0Analyzer
};



//beg_ModifierList : Modifier ModifierList
void R004_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ModifierList_0Analyzer");
	//TO DO  R004_ModifierList_0Analyzer
};



//beg_ModifierList : Modifier
void R004_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_ModifierList_1Analyzer");
	//TO DO  R004_ModifierList_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R004_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationContent_0Analyzer");
	//TO DO  R004_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R004_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_AnnotationContentStatements_0Analyzer");
	//TO DO  R004_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES
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



//beg_StatementEle : 'IDENTIFIER'
void R004_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_0Analyzer");
	//TO DO  R004_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R004_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_1Analyzer");
	//TO DO  R004_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R004_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_2Analyzer");
	//TO DO  R004_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R004_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_3Analyzer");
	//TO DO  R004_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R004_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_4Analyzer");
	//TO DO  R004_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R004_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_5Analyzer");
	//TO DO  R004_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R004_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_6Analyzer");
	//TO DO  R004_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R004_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_7Analyzer");
	//TO DO  R004_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R004_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_8Analyzer");
	//TO DO  R004_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R004_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_9Analyzer");
	//TO DO  R004_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R004_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_10Analyzer");
	//TO DO  R004_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R004_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_11Analyzer");
	//TO DO  R004_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R004_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_12Analyzer");
	//TO DO  R004_StatementEle_12Analyzer
};



//beg_StatementEle : 'EQUAL'
void R004_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_13Analyzer");
	//TO DO  R004_StatementEle_13Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R004_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_14Analyzer");
	//TO DO  R004_StatementEle_14Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R004_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_15Analyzer");
	//TO DO  R004_StatementEle_15Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R004_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_16Analyzer");
	//TO DO  R004_StatementEle_16Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R004_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_17Analyzer");
	//TO DO  R004_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R004_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_18Analyzer");
	//TO DO  R004_StatementEle_18Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R004_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_19Analyzer");
	//TO DO  R004_StatementEle_19Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R004_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_20Analyzer");
	//TO DO  R004_StatementEle_20Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R004_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_21Analyzer");
	//TO DO  R004_StatementEle_21Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R004_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_22Analyzer");
	//TO DO  R004_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR'
void R004_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_23Analyzer");
	//TO DO  R004_StatementEle_23Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R004_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_24Analyzer");
	//TO DO  R004_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS'
void R004_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_25Analyzer");
	//TO DO  R004_StatementEle_25Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R004_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_26Analyzer");
	//TO DO  R004_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R004_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_27Analyzer");
	//TO DO  R004_StatementEle_27Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R004_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_28Analyzer");
	//TO DO  R004_StatementEle_28Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R004_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_29Analyzer");
	//TO DO  R004_StatementEle_29Analyzer
};



//beg_StatementEle : 'QUESTION'
void R004_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_30Analyzer");
	//TO DO  R004_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R004_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_31Analyzer");
	//TO DO  R004_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R004_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_32Analyzer");
	//TO DO  R004_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R004_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_33Analyzer");
	//TO DO  R004_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R004_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_34Analyzer");
	//TO DO  R004_StatementEle_34Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R004_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_35Analyzer");
	//TO DO  R004_StatementEle_35Analyzer
};



//beg_StatementEle : 'SLASH'
void R004_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_36Analyzer");
	//TO DO  R004_StatementEle_36Analyzer
};



//beg_StatementEle : 'SPOT'
void R004_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_37Analyzer");
	//TO DO  R004_StatementEle_37Analyzer
};



//beg_StatementEle : 'STAR'
void R004_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_38Analyzer");
	//TO DO  R004_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R004_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_39Analyzer");
	//TO DO  R004_StatementEle_39Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R004_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_40Analyzer");
	//TO DO  R004_StatementEle_40Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R004_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_41Analyzer");
	//TO DO  R004_StatementEle_41Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R004_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_42Analyzer");
	//TO DO  R004_StatementEle_42Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R004_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_43Analyzer");
	//TO DO  R004_StatementEle_43Analyzer
};



//beg_StatementEle : 'TILDE'
void R004_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_44Analyzer");
	//TO DO  R004_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R004_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_45Analyzer");
	//TO DO  R004_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R004_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_46Analyzer");
	//TO DO  R004_StatementEle_46Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R004_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_47Analyzer");
	//TO DO  R004_StatementEle_47Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R004_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_48Analyzer");
	//TO DO  R004_StatementEle_48Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R004_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_49Analyzer");
	//TO DO  R004_StatementEle_49Analyzer
};



//beg_StatementEle : 'abstract'
void R004_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_50Analyzer");
	//TO DO  R004_StatementEle_50Analyzer
};



//beg_StatementEle : 'boolean'
void R004_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_51Analyzer");
	//TO DO  R004_StatementEle_51Analyzer
};



//beg_StatementEle : 'byte'
void R004_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_52Analyzer");
	//TO DO  R004_StatementEle_52Analyzer
};



//beg_StatementEle : 'char'
void R004_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_53Analyzer");
	//TO DO  R004_StatementEle_53Analyzer
};



//beg_StatementEle : 'class'
void R004_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_54Analyzer");
	//TO DO  R004_StatementEle_54Analyzer
};



//beg_StatementEle : 'default'
void R004_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_55Analyzer");
	//TO DO  R004_StatementEle_55Analyzer
};



//beg_StatementEle : 'double'
void R004_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_56Analyzer");
	//TO DO  R004_StatementEle_56Analyzer
};



//beg_StatementEle : 'enum'
void R004_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_57Analyzer");
	//TO DO  R004_StatementEle_57Analyzer
};



//beg_StatementEle : 'extends'
void R004_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_58Analyzer");
	//TO DO  R004_StatementEle_58Analyzer
};



//beg_StatementEle : 'final'
void R004_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_59Analyzer");
	//TO DO  R004_StatementEle_59Analyzer
};



//beg_StatementEle : 'float'
void R004_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_60Analyzer");
	//TO DO  R004_StatementEle_60Analyzer
};



//beg_StatementEle : 'implements'
void R004_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_61Analyzer");
	//TO DO  R004_StatementEle_61Analyzer
};



//beg_StatementEle : 'instanceof'
void R004_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_62Analyzer");
	//TO DO  R004_StatementEle_62Analyzer
};



//beg_StatementEle : 'int'
void R004_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_63Analyzer");
	//TO DO  R004_StatementEle_63Analyzer
};



//beg_StatementEle : 'interface'
void R004_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_64Analyzer");
	//TO DO  R004_StatementEle_64Analyzer
};



//beg_StatementEle : 'long'
void R004_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_65Analyzer");
	//TO DO  R004_StatementEle_65Analyzer
};



//beg_StatementEle : 'native'
void R004_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_66Analyzer");
	//TO DO  R004_StatementEle_66Analyzer
};



//beg_StatementEle : 'new'
void R004_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_67Analyzer");
	//TO DO  R004_StatementEle_67Analyzer
};



//beg_StatementEle : 'null'
void R004_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_68Analyzer");
	//TO DO  R004_StatementEle_68Analyzer
};



//beg_StatementEle : 'private'
void R004_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_69Analyzer");
	//TO DO  R004_StatementEle_69Analyzer
};



//beg_StatementEle : 'protected'
void R004_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_70Analyzer");
	//TO DO  R004_StatementEle_70Analyzer
};



//beg_StatementEle : 'public'
void R004_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_71Analyzer");
	//TO DO  R004_StatementEle_71Analyzer
};



//beg_StatementEle : 'short'
void R004_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_72Analyzer");
	//TO DO  R004_StatementEle_72Analyzer
};



//beg_StatementEle : 'static'
void R004_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_73Analyzer");
	//TO DO  R004_StatementEle_73Analyzer
};



//beg_StatementEle : 'super'
void R004_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_74Analyzer");
	//TO DO  R004_StatementEle_74Analyzer
};



//beg_StatementEle : 'synchronized'
void R004_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_75Analyzer");
	//TO DO  R004_StatementEle_75Analyzer
};



//beg_StatementEle : 'this'
void R004_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_76Analyzer");
	//TO DO  R004_StatementEle_76Analyzer
};



//beg_StatementEle : 'throws'
void R004_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_77Analyzer");
	//TO DO  R004_StatementEle_77Analyzer
};



//beg_StatementEle : 'transient'
void R004_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_78Analyzer");
	//TO DO  R004_StatementEle_78Analyzer
};



//beg_StatementEle : 'void'
void R004_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_79Analyzer");
	//TO DO  R004_StatementEle_79Analyzer
};



//beg_StatementEle : 'volatile'
void R004_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_StatementEle_80Analyzer");
	//TO DO  R004_StatementEle_80Analyzer
};



//beg_Modifier : 'public'
void R004_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_0Analyzer");
	//TO DO  R004_Modifier_0Analyzer
};



//beg_Modifier : 'protected'
void R004_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_1Analyzer");
	//TO DO  R004_Modifier_1Analyzer
};



//beg_Modifier : 'private'
void R004_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_2Analyzer");
	//TO DO  R004_Modifier_2Analyzer
};



//beg_Modifier : 'abstract'
void R004_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_3Analyzer");
	//TO DO  R004_Modifier_3Analyzer
};



//beg_Modifier : 'static'
void R004_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_4Analyzer");
	//TO DO  R004_Modifier_4Analyzer
};



//beg_Modifier : 'final'
void R004_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_5Analyzer");
	//TO DO  R004_Modifier_5Analyzer
};



//beg_Modifier : 'strictfp'
void R004_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_6Analyzer");
	//TO DO  R004_Modifier_6Analyzer
};



//beg_Modifier : 'default'
void R004_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_7Analyzer");
	//TO DO  R004_Modifier_7Analyzer
};



//beg_Modifier : 'volatile'
void R004_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_8Analyzer");
	//TO DO  R004_Modifier_8Analyzer
};



//beg_Modifier : 'synchronized'
void R004_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_9Analyzer");
	//TO DO  R004_Modifier_9Analyzer
};



//beg_Modifier : 'transient'
void R004_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_10Analyzer");
	//TO DO  R004_Modifier_10Analyzer
};



//beg_Modifier : 'native'
void R004_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_Modifier_11Analyzer");
	//TO DO  R004_Modifier_11Analyzer
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
	//TO DO  R004_Block_0Analyzer
};



//beg_BlockStatements : 0
void R004_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR004("R004_BlockStatements_0Analyzer");
	//TO DO  R004_BlockStatements_0Analyzer
};

