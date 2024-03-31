
#include "R003Analyzer.h"
#include "../../symbols/java/ClassListToken.h"
#include "../../Util/Util.h"
#include<iostream>
#include <sstream>
using namespace std;

#include "R003Analyzer_1.h"

void logR003(const string& s) {
	Util::log(s);
}



P_NodeValue R003_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack,  Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR003("R003_DefaultAnalyzer");
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
void R003_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["CompilationUnit"];
	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
void R003_CompilationUnit_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeDeclarationList"];
	nodeValue->context["CompilationUnit"] = p2;
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList
void R003_CompilationUnit_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_1Analyzer");
	//TO DO  R003_CompilationUnit_1Analyzer
};



//beg_CompilationUnit : PackageDeclaration TypeDeclarationList
void R003_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	nodeValue->context["CompilationUnit"] = p1;
};



//beg_CompilationUnit : ImportDeclarationList TypeDeclarationList
void R003_CompilationUnit_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	nodeValue->context["CompilationUnit"] = p1;
};



//beg_CompilationUnit : PackageDeclaration
void R003_CompilationUnit_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_4Analyzer");
	//TO DO  R003_CompilationUnit_4Analyzer
};



//beg_CompilationUnit : ImportDeclarationList
void R003_CompilationUnit_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_5Analyzer");
	//TO DO  R003_CompilationUnit_5Analyzer
};



//beg_CompilationUnit : TypeDeclarationList
void R003_CompilationUnit_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_CompilationUnit_6Analyzer");
	//TO DO  R003_CompilationUnit_6Analyzer
};



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
void R003_PackageDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_PackageDeclaration_0Analyzer");
	//TO DO  R003_PackageDeclaration_0Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R003_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_DetailIdentifier_0Analyzer");
	//TO DO  R003_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R003_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_DetailIdentifier_1Analyzer");
	//TO DO  R003_DetailIdentifier_1Analyzer
};



//beg_Identifier : 'IDENTIFIER'
void R003_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_ImportDeclarationList : ImportDeclaration ImportDeclarationList
void R003_ImportDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclarationList_0Analyzer");
	//TO DO  R003_ImportDeclarationList_0Analyzer
};



//beg_ImportDeclarationList : ImportDeclaration
void R003_ImportDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclarationList_1Analyzer");
	//TO DO  R003_ImportDeclarationList_1Analyzer
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
void R003_ImportDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclaration_0Analyzer");
	//TO DO  R003_ImportDeclaration_0Analyzer
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
void R003_ImportDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclaration_1Analyzer");
	//TO DO  R003_ImportDeclaration_1Analyzer
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
void R003_ImportDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclaration_2Analyzer");
	//TO DO  R003_ImportDeclaration_2Analyzer
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'semicolon'
void R003_ImportDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ImportDeclaration_3Analyzer");
	//TO DO  R003_ImportDeclaration_3Analyzer
};



//beg_TypeDeclarationList : TypeDeclaration TypeDeclarationList
void R003_TypeDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_TypeDeclarationList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];
	for (int i1 = 0; i1 < ((ClassListToken *)(p0.get()))->list.size(); i1++) {
		((ClassListToken *)(p1.get()))->list.push_back(((ClassListToken *)(p0.get()))->list[i1]);
	}
	nodeValue->context["TypeDeclarationList"] = p1;
};



//beg_TypeDeclarationList : TypeDeclaration
void R003_TypeDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_TypeDeclarationList_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"];
	nodeValue->context["TypeDeclarationList"] = p0;
};



//beg_TypeDeclaration : ClassDeclaration
void R003_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_TypeDeclaration_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
	nodeValue->context["TypeDeclaration"] = p0;

};



//beg_TypeDeclaration : 'semicolon'
void R003_TypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_TypeDeclaration_1Analyzer");
	//TO DO  R003_TypeDeclaration_1Analyzer
};



//beg_ClassDeclaration : NormalClassDeclaration
void R003_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassDeclaration_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
void R003_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NormalClassDeclaration_0Analyzer");


	Token * p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"].get();
	ClassListToken *p = new ClassListToken();
	P_ClassEntity classEntity = P_ClassEntity(new ClassEntity);
	classEntity->name = p1->content;
	p->list.push_back(classEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
void R003_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassBody_0Analyzer");
	//TO DO  R003_ClassBody_0Analyzer
};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R003_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassBodyDeclarationList_0Analyzer");
	//TO DO  R003_ClassBodyDeclarationList_0Analyzer
};



//beg_ClassBodyDeclarationList : 0
void R003_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassBodyDeclarationList_1Analyzer");
	//TO DO  R003_ClassBodyDeclarationList_1Analyzer
};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
void R003_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassBodyDeclaration_0Analyzer");
	//TO DO  R003_ClassBodyDeclaration_0Analyzer
};



//beg_ClassMemberDeclaration : MethodDeclaration
void R003_ClassMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ClassMemberDeclaration_0Analyzer");
	//TO DO  R003_ClassMemberDeclaration_0Analyzer
};



//beg_MethodDeclaration : ModifierList MethodHeader MethodBody
void R003_MethodDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodDeclaration_0Analyzer");
	//TO DO  R003_MethodDeclaration_0Analyzer
};



//beg_MethodDeclaration : MethodHeader MethodBody
void R003_MethodDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodDeclaration_1Analyzer");
	//TO DO  R003_MethodDeclaration_1Analyzer
};



//beg_MethodHeader : 'void' MethodDeclarator
void R003_MethodHeader_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodHeader_0Analyzer");
	//TO DO  R003_MethodHeader_0Analyzer
};



//beg_MethodDeclarator : Identifier AnnotationContent
void R003_MethodDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodDeclarator_0Analyzer");
	//TO DO  R003_MethodDeclarator_0Analyzer
};



//beg_ModifierList : Modifier ModifierList
void R003_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ModifierList_0Analyzer");
	//TO DO  R003_ModifierList_0Analyzer
};



//beg_ModifierList : Modifier
void R003_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_ModifierList_1Analyzer");
	//TO DO  R003_ModifierList_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R003_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_AnnotationContent_0Analyzer");
	//TO DO  R003_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R003_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_AnnotationContentStatements_0Analyzer");
	//TO DO  R003_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES
void R003_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_AnnotationContentStatements_1Analyzer");
	//TO DO  R003_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R003_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_0Analyzer");
	//TO DO  R003_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R003_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_1Analyzer");
	//TO DO  R003_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R003_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_2Analyzer");
	//TO DO  R003_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R003_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_3Analyzer");
	//TO DO  R003_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R003_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_4Analyzer");
	//TO DO  R003_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R003_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_5Analyzer");
	//TO DO  R003_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R003_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_6Analyzer");
	//TO DO  R003_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R003_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_7Analyzer");
	//TO DO  R003_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R003_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_8Analyzer");
	//TO DO  R003_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R003_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_NonPARENTHESES_9Analyzer");
	//TO DO  R003_NonPARENTHESES_9Analyzer
};



//beg_StatementEle : 'IDENTIFIER'
void R003_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_0Analyzer");
	//TO DO  R003_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R003_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_1Analyzer");
	//TO DO  R003_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R003_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_2Analyzer");
	//TO DO  R003_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R003_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_3Analyzer");
	//TO DO  R003_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R003_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_4Analyzer");
	//TO DO  R003_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R003_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_5Analyzer");
	//TO DO  R003_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R003_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_6Analyzer");
	//TO DO  R003_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R003_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_7Analyzer");
	//TO DO  R003_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R003_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_8Analyzer");
	//TO DO  R003_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R003_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_9Analyzer");
	//TO DO  R003_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R003_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_10Analyzer");
	//TO DO  R003_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R003_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_11Analyzer");
	//TO DO  R003_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R003_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_12Analyzer");
	//TO DO  R003_StatementEle_12Analyzer
};



//beg_StatementEle : 'EQUAL'
void R003_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_13Analyzer");
	//TO DO  R003_StatementEle_13Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R003_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_14Analyzer");
	//TO DO  R003_StatementEle_14Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R003_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_15Analyzer");
	//TO DO  R003_StatementEle_15Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R003_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_16Analyzer");
	//TO DO  R003_StatementEle_16Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R003_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_17Analyzer");
	//TO DO  R003_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R003_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_18Analyzer");
	//TO DO  R003_StatementEle_18Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R003_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_19Analyzer");
	//TO DO  R003_StatementEle_19Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R003_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_20Analyzer");
	//TO DO  R003_StatementEle_20Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R003_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_21Analyzer");
	//TO DO  R003_StatementEle_21Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R003_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_22Analyzer");
	//TO DO  R003_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR'
void R003_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_23Analyzer");
	//TO DO  R003_StatementEle_23Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R003_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_24Analyzer");
	//TO DO  R003_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS'
void R003_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_25Analyzer");
	//TO DO  R003_StatementEle_25Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R003_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_26Analyzer");
	//TO DO  R003_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R003_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_27Analyzer");
	//TO DO  R003_StatementEle_27Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R003_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_28Analyzer");
	//TO DO  R003_StatementEle_28Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R003_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_29Analyzer");
	//TO DO  R003_StatementEle_29Analyzer
};



//beg_StatementEle : 'QUESTION'
void R003_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_30Analyzer");
	//TO DO  R003_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R003_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_31Analyzer");
	//TO DO  R003_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R003_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_32Analyzer");
	//TO DO  R003_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R003_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_33Analyzer");
	//TO DO  R003_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R003_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_34Analyzer");
	//TO DO  R003_StatementEle_34Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R003_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_35Analyzer");
	//TO DO  R003_StatementEle_35Analyzer
};



//beg_StatementEle : 'SLASH'
void R003_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_36Analyzer");
	//TO DO  R003_StatementEle_36Analyzer
};



//beg_StatementEle : 'SPOT'
void R003_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_37Analyzer");
	//TO DO  R003_StatementEle_37Analyzer
};



//beg_StatementEle : 'STAR'
void R003_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_38Analyzer");
	//TO DO  R003_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R003_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_39Analyzer");
	//TO DO  R003_StatementEle_39Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R003_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_40Analyzer");
	//TO DO  R003_StatementEle_40Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R003_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_41Analyzer");
	//TO DO  R003_StatementEle_41Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R003_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_42Analyzer");
	//TO DO  R003_StatementEle_42Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R003_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_43Analyzer");
	//TO DO  R003_StatementEle_43Analyzer
};



//beg_StatementEle : 'TILDE'
void R003_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_44Analyzer");
	//TO DO  R003_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R003_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_45Analyzer");
	//TO DO  R003_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R003_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_46Analyzer");
	//TO DO  R003_StatementEle_46Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R003_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_47Analyzer");
	//TO DO  R003_StatementEle_47Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R003_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_48Analyzer");
	//TO DO  R003_StatementEle_48Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R003_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_49Analyzer");
	//TO DO  R003_StatementEle_49Analyzer
};



//beg_StatementEle : 'abstract'
void R003_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_50Analyzer");
	//TO DO  R003_StatementEle_50Analyzer
};



//beg_StatementEle : 'boolean'
void R003_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_51Analyzer");
	//TO DO  R003_StatementEle_51Analyzer
};



//beg_StatementEle : 'byte'
void R003_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_52Analyzer");
	//TO DO  R003_StatementEle_52Analyzer
};



//beg_StatementEle : 'char'
void R003_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_53Analyzer");
	//TO DO  R003_StatementEle_53Analyzer
};



//beg_StatementEle : 'class'
void R003_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_54Analyzer");
	//TO DO  R003_StatementEle_54Analyzer
};



//beg_StatementEle : 'default'
void R003_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_55Analyzer");
	//TO DO  R003_StatementEle_55Analyzer
};



//beg_StatementEle : 'double'
void R003_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_56Analyzer");
	//TO DO  R003_StatementEle_56Analyzer
};



//beg_StatementEle : 'enum'
void R003_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_57Analyzer");
	//TO DO  R003_StatementEle_57Analyzer
};



//beg_StatementEle : 'extends'
void R003_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_58Analyzer");
	//TO DO  R003_StatementEle_58Analyzer
};



//beg_StatementEle : 'final'
void R003_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_59Analyzer");
	//TO DO  R003_StatementEle_59Analyzer
};



//beg_StatementEle : 'float'
void R003_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_60Analyzer");
	//TO DO  R003_StatementEle_60Analyzer
};



//beg_StatementEle : 'implements'
void R003_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_61Analyzer");
	//TO DO  R003_StatementEle_61Analyzer
};



//beg_StatementEle : 'instanceof'
void R003_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_62Analyzer");
	//TO DO  R003_StatementEle_62Analyzer
};



//beg_StatementEle : 'int'
void R003_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_63Analyzer");
	//TO DO  R003_StatementEle_63Analyzer
};



//beg_StatementEle : 'interface'
void R003_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_64Analyzer");
	//TO DO  R003_StatementEle_64Analyzer
};



//beg_StatementEle : 'long'
void R003_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_65Analyzer");
	//TO DO  R003_StatementEle_65Analyzer
};



//beg_StatementEle : 'native'
void R003_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_66Analyzer");
	//TO DO  R003_StatementEle_66Analyzer
};



//beg_StatementEle : 'new'
void R003_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_67Analyzer");
	//TO DO  R003_StatementEle_67Analyzer
};



//beg_StatementEle : 'null'
void R003_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_68Analyzer");
	//TO DO  R003_StatementEle_68Analyzer
};



//beg_StatementEle : 'private'
void R003_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_69Analyzer");
	//TO DO  R003_StatementEle_69Analyzer
};



//beg_StatementEle : 'protected'
void R003_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_70Analyzer");
	//TO DO  R003_StatementEle_70Analyzer
};



//beg_StatementEle : 'public'
void R003_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_71Analyzer");
	//TO DO  R003_StatementEle_71Analyzer
};



//beg_StatementEle : 'short'
void R003_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_72Analyzer");
	//TO DO  R003_StatementEle_72Analyzer
};



//beg_StatementEle : 'static'
void R003_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_73Analyzer");
	//TO DO  R003_StatementEle_73Analyzer
};



//beg_StatementEle : 'super'
void R003_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_74Analyzer");
	//TO DO  R003_StatementEle_74Analyzer
};



//beg_StatementEle : 'synchronized'
void R003_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_75Analyzer");
	//TO DO  R003_StatementEle_75Analyzer
};



//beg_StatementEle : 'this'
void R003_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_76Analyzer");
	//TO DO  R003_StatementEle_76Analyzer
};



//beg_StatementEle : 'throws'
void R003_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_77Analyzer");
	//TO DO  R003_StatementEle_77Analyzer
};



//beg_StatementEle : 'transient'
void R003_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_78Analyzer");
	//TO DO  R003_StatementEle_78Analyzer
};



//beg_StatementEle : 'void'
void R003_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_79Analyzer");
	//TO DO  R003_StatementEle_79Analyzer
};



//beg_StatementEle : 'volatile'
void R003_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_StatementEle_80Analyzer");
	//TO DO  R003_StatementEle_80Analyzer
};



//beg_Modifier : 'public'
void R003_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_0Analyzer");
	//TO DO  R003_Modifier_0Analyzer
};



//beg_Modifier : 'protected'
void R003_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_1Analyzer");
	//TO DO  R003_Modifier_1Analyzer
};



//beg_Modifier : 'private'
void R003_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_2Analyzer");
	//TO DO  R003_Modifier_2Analyzer
};



//beg_Modifier : 'abstract'
void R003_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_3Analyzer");
	//TO DO  R003_Modifier_3Analyzer
};



//beg_Modifier : 'static'
void R003_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_4Analyzer");
	//TO DO  R003_Modifier_4Analyzer
};



//beg_Modifier : 'final'
void R003_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_5Analyzer");
	//TO DO  R003_Modifier_5Analyzer
};



//beg_Modifier : 'strictfp'
void R003_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_6Analyzer");
	//TO DO  R003_Modifier_6Analyzer
};



//beg_Modifier : 'default'
void R003_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_7Analyzer");
	//TO DO  R003_Modifier_7Analyzer
};



//beg_Modifier : 'volatile'
void R003_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_8Analyzer");
	//TO DO  R003_Modifier_8Analyzer
};



//beg_Modifier : 'synchronized'
void R003_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_9Analyzer");
	//TO DO  R003_Modifier_9Analyzer
};



//beg_Modifier : 'transient'
void R003_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_10Analyzer");
	//TO DO  R003_Modifier_10Analyzer
};



//beg_Modifier : 'native'
void R003_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Modifier_11Analyzer");
	//TO DO  R003_Modifier_11Analyzer
};



//beg_MethodBody : Block
void R003_MethodBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodBody_0Analyzer");
	//TO DO  R003_MethodBody_0Analyzer
};



//beg_MethodBody : 'semicolon'
void R003_MethodBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_MethodBody_1Analyzer");
	//TO DO  R003_MethodBody_1Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R003_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_Block_0Analyzer");
	//TO DO  R003_Block_0Analyzer
};



//beg_BlockStatements : 0
void R003_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR003("R003_BlockStatements_0Analyzer");
	//TO DO  R003_BlockStatements_0Analyzer
};
