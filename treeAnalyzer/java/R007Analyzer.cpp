#include "R007Analyzer.h"
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
#include "../../symbols/java/DimListToken.h"
#include "../../symbols/java/FieldToken.h"
#include "../../symbols/java/UnannTypeToken.h"


#include <iostream>
#include <sstream>
using namespace std;

#include "R007Analyzer_1.h"

void logR007(const string& s) {
	//					cout << s << endl;
}



P_NodeValue R007_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR007("R007_DefaultAnalyzer");
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

//beg_ele_begin : EnumFirstStatement
void R007_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumFirstStatement"];
	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_EnumFirstStatement : EnumConstantList 'COMMA'
void R007_EnumFirstStatement_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumFirstStatement_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantList"];


	nodeValue->context["EnumFirstStatement"] = p0;
};



//beg_EnumFirstStatement : EnumConstantList
void R007_EnumFirstStatement_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumFirstStatement_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstantList"];


	nodeValue->context["EnumFirstStatement"] = p0;

};



//beg_EnumConstantList : EnumConstant 'COMMA' EnumConstantList
void R007_EnumConstantList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstantList_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstant"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumConstantList"];


	FieldToken *fieldP = new FieldToken();
	fieldP->name = ((FieldToken*)(p0.get()))->name;

	((StatementToken*)(p2.get()))->statementEntity->fieldList.push_front(P_FieldToken(fieldP));

	nodeValue->context["EnumConstantList"] = p2;
};



//beg_EnumConstantList : EnumConstant
void R007_EnumConstantList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstantList_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumConstant"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumConstantList";

	FieldToken *fieldP = new FieldToken();
	fieldP->name = ((FieldToken*)(p0.get()))->name;

	statementEntity->fieldList.push_front(P_FieldToken(fieldP));
	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["EnumConstantList"] = P_Token(p);
};



//beg_EnumConstant : Identifier
void R007_EnumConstant_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];

	FieldToken *fieldP = new FieldToken();
	fieldP->name = p0->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : AnnotationList Identifier
void R007_EnumConstant_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	FieldToken *fieldP = new FieldToken();
	fieldP->name = p1->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : Identifier AnnotationContent
void R007_EnumConstant_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p0->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : AnnotationList Identifier AnnotationContent
void R007_EnumConstant_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p1->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : Identifier Block
void R007_EnumConstant_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p0->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : AnnotationList Identifier Block
void R007_EnumConstant_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_5Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p1->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : Identifier AnnotationContent Block
void R007_EnumConstant_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_6Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p0->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_EnumConstant : AnnotationList Identifier AnnotationContent Block
void R007_EnumConstant_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_EnumConstant_7Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	FieldToken *fieldP = new FieldToken();
	fieldP->name = p1->content;

	nodeValue->context["EnumConstant"] = P_Token(fieldP);
};



//beg_AnnotationList : Annotation AnnotationList
void R007_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_AnnotationList_0Analyzer");
	//TO DO  R007_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R007_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_AnnotationList_1Analyzer");
	//TO DO  R007_AnnotationList_1Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R007_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_DetailIdentifier_0Analyzer");
	//TO DO  R007_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R007_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_DetailIdentifier_1Analyzer");
	//TO DO  R007_DetailIdentifier_1Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R007_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_Annotation_0Analyzer");
	//TO DO  R007_Annotation_0Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier
void R007_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_Annotation_1Analyzer");
	//TO DO  R007_Annotation_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R007_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_AnnotationContent_0Analyzer");
	//TO DO  R007_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R007_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_AnnotationContentStatements_0Analyzer");
	//TO DO  R007_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R007_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_AnnotationContentStatements_1Analyzer");
	//TO DO  R007_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R007_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_0Analyzer");
	//TO DO  R007_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R007_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_1Analyzer");
	//TO DO  R007_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R007_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_2Analyzer");
	//TO DO  R007_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R007_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_3Analyzer");
	//TO DO  R007_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R007_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_4Analyzer");
	//TO DO  R007_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R007_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_5Analyzer");
	//TO DO  R007_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R007_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_6Analyzer");
	//TO DO  R007_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R007_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_7Analyzer");
	//TO DO  R007_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R007_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_8Analyzer");
	//TO DO  R007_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R007_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_9Analyzer");
	//TO DO  R007_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : 'EQUAL'
void R007_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonPARENTHESES_10Analyzer");
	//TO DO  R007_NonPARENTHESES_10Analyzer
};



//beg_StatementEle : Identifier
void R007_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_0Analyzer");
	//TO DO  R007_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R007_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_1Analyzer");
	//TO DO  R007_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R007_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_2Analyzer");
	//TO DO  R007_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R007_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_3Analyzer");
	//TO DO  R007_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R007_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_4Analyzer");
	//TO DO  R007_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R007_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_5Analyzer");
	//TO DO  R007_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R007_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_6Analyzer");
	//TO DO  R007_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R007_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_7Analyzer");
	//TO DO  R007_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R007_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_8Analyzer");
	//TO DO  R007_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R007_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_9Analyzer");
	//TO DO  R007_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R007_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_10Analyzer");
	//TO DO  R007_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R007_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_11Analyzer");
	//TO DO  R007_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R007_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_12Analyzer");
	//TO DO  R007_StatementEle_12Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R007_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_13Analyzer");
	//TO DO  R007_StatementEle_13Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R007_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_14Analyzer");
	//TO DO  R007_StatementEle_14Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R007_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_15Analyzer");
	//TO DO  R007_StatementEle_15Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R007_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_16Analyzer");
	//TO DO  R007_StatementEle_16Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R007_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_17Analyzer");
	//TO DO  R007_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R007_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_18Analyzer");
	//TO DO  R007_StatementEle_18Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R007_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_19Analyzer");
	//TO DO  R007_StatementEle_19Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R007_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_20Analyzer");
	//TO DO  R007_StatementEle_20Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R007_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_21Analyzer");
	//TO DO  R007_StatementEle_21Analyzer
};



//beg_StatementEle : 'OR'
void R007_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_22Analyzer");
	//TO DO  R007_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R007_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_23Analyzer");
	//TO DO  R007_StatementEle_23Analyzer
};



//beg_StatementEle : 'PLUS'
void R007_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_24Analyzer");
	//TO DO  R007_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R007_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_25Analyzer");
	//TO DO  R007_StatementEle_25Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R007_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_26Analyzer");
	//TO DO  R007_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R007_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_27Analyzer");
	//TO DO  R007_StatementEle_27Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R007_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_28Analyzer");
	//TO DO  R007_StatementEle_28Analyzer
};



//beg_StatementEle : 'QUESTION'
void R007_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_29Analyzer");
	//TO DO  R007_StatementEle_29Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R007_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_30Analyzer");
	//TO DO  R007_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R007_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_31Analyzer");
	//TO DO  R007_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R007_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_32Analyzer");
	//TO DO  R007_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R007_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_33Analyzer");
	//TO DO  R007_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R007_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_34Analyzer");
	//TO DO  R007_StatementEle_34Analyzer
};



//beg_StatementEle : 'SLASH'
void R007_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_35Analyzer");
	//TO DO  R007_StatementEle_35Analyzer
};



//beg_StatementEle : 'SPOT'
void R007_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_36Analyzer");
	//TO DO  R007_StatementEle_36Analyzer
};



//beg_StatementEle : 'STAR'
void R007_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_37Analyzer");
	//TO DO  R007_StatementEle_37Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R007_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_38Analyzer");
	//TO DO  R007_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R007_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_39Analyzer");
	//TO DO  R007_StatementEle_39Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R007_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_40Analyzer");
	//TO DO  R007_StatementEle_40Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R007_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_41Analyzer");
	//TO DO  R007_StatementEle_41Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R007_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_42Analyzer");
	//TO DO  R007_StatementEle_42Analyzer
};



//beg_StatementEle : 'TILDE'
void R007_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_43Analyzer");
	//TO DO  R007_StatementEle_43Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R007_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_44Analyzer");
	//TO DO  R007_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R007_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_45Analyzer");
	//TO DO  R007_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R007_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_46Analyzer");
	//TO DO  R007_StatementEle_46Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R007_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_47Analyzer");
	//TO DO  R007_StatementEle_47Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R007_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_48Analyzer");
	//TO DO  R007_StatementEle_48Analyzer
};



//beg_StatementEle : 'abstract'
void R007_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_49Analyzer");
	//TO DO  R007_StatementEle_49Analyzer
};



//beg_StatementEle : 'boolean'
void R007_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_50Analyzer");
	//TO DO  R007_StatementEle_50Analyzer
};



//beg_StatementEle : 'byte'
void R007_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_51Analyzer");
	//TO DO  R007_StatementEle_51Analyzer
};



//beg_StatementEle : 'char'
void R007_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_52Analyzer");
	//TO DO  R007_StatementEle_52Analyzer
};



//beg_StatementEle : 'class'
void R007_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_53Analyzer");
	//TO DO  R007_StatementEle_53Analyzer
};



//beg_StatementEle : 'default'
void R007_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_54Analyzer");
	//TO DO  R007_StatementEle_54Analyzer
};



//beg_StatementEle : 'double'
void R007_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_55Analyzer");
	//TO DO  R007_StatementEle_55Analyzer
};



//beg_StatementEle : 'enum'
void R007_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_56Analyzer");
	//TO DO  R007_StatementEle_56Analyzer
};



//beg_StatementEle : 'extends'
void R007_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_57Analyzer");
	//TO DO  R007_StatementEle_57Analyzer
};



//beg_StatementEle : 'final'
void R007_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_58Analyzer");
	//TO DO  R007_StatementEle_58Analyzer
};



//beg_StatementEle : 'float'
void R007_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_59Analyzer");
	//TO DO  R007_StatementEle_59Analyzer
};



//beg_StatementEle : 'implements'
void R007_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_60Analyzer");
	//TO DO  R007_StatementEle_60Analyzer
};



//beg_StatementEle : 'instanceof'
void R007_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_61Analyzer");
	//TO DO  R007_StatementEle_61Analyzer
};



//beg_StatementEle : 'int'
void R007_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_62Analyzer");
	//TO DO  R007_StatementEle_62Analyzer
};



//beg_StatementEle : 'interface'
void R007_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_63Analyzer");
	//TO DO  R007_StatementEle_63Analyzer
};



//beg_StatementEle : 'long'
void R007_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_64Analyzer");
	//TO DO  R007_StatementEle_64Analyzer
};



//beg_StatementEle : 'native'
void R007_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_65Analyzer");
	//TO DO  R007_StatementEle_65Analyzer
};



//beg_StatementEle : 'new'
void R007_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_66Analyzer");
	//TO DO  R007_StatementEle_66Analyzer
};



//beg_StatementEle : 'null'
void R007_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_67Analyzer");
	//TO DO  R007_StatementEle_67Analyzer
};



//beg_StatementEle : 'private'
void R007_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_68Analyzer");
	//TO DO  R007_StatementEle_68Analyzer
};



//beg_StatementEle : 'protected'
void R007_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_69Analyzer");
	//TO DO  R007_StatementEle_69Analyzer
};



//beg_StatementEle : 'public'
void R007_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_70Analyzer");
	//TO DO  R007_StatementEle_70Analyzer
};



//beg_StatementEle : 'short'
void R007_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_71Analyzer");
	//TO DO  R007_StatementEle_71Analyzer
};



//beg_StatementEle : 'static'
void R007_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_72Analyzer");
	//TO DO  R007_StatementEle_72Analyzer
};



//beg_StatementEle : 'super'
void R007_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_73Analyzer");
	//TO DO  R007_StatementEle_73Analyzer
};



//beg_StatementEle : 'synchronized'
void R007_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_74Analyzer");
	//TO DO  R007_StatementEle_74Analyzer
};



//beg_StatementEle : 'this'
void R007_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_75Analyzer");
	//TO DO  R007_StatementEle_75Analyzer
};



//beg_StatementEle : 'throws'
void R007_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_76Analyzer");
	//TO DO  R007_StatementEle_76Analyzer
};



//beg_StatementEle : 'transient'
void R007_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_77Analyzer");
	//TO DO  R007_StatementEle_77Analyzer
};



//beg_StatementEle : 'void'
void R007_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_78Analyzer");
	//TO DO  R007_StatementEle_78Analyzer
};



//beg_StatementEle : 'volatile'
void R007_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_StatementEle_79Analyzer");
	//TO DO  R007_StatementEle_79Analyzer
};



//beg_Identifier : 'IDENTIFIER'
void R007_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R007_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_Block_0Analyzer");
	//TO DO  R007_Block_0Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
void R007_Block_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_Block_1Analyzer");
	//TO DO  R007_Block_1Analyzer
};



//beg_BlockStatements : Block BlockStatements
void R007_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_BlockStatements_0Analyzer");
	//TO DO  R007_BlockStatements_0Analyzer
};



//beg_BlockStatements : NonBrace BlockStatements
void R007_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_BlockStatements_1Analyzer");
	//TO DO  R007_BlockStatements_1Analyzer
};



//beg_BlockStatements : 0
void R007_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_BlockStatements_2Analyzer");
	//TO DO  R007_BlockStatements_2Analyzer
};



//beg_NonBrace : StatementEle
void R007_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_0Analyzer");
	//TO DO  R007_NonBrace_0Analyzer
};



//beg_NonBrace : 'COMMA'
void R007_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_1Analyzer");
	//TO DO  R007_NonBrace_1Analyzer
};



//beg_NonBrace : 'semicolon'
void R007_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_2Analyzer");
	//TO DO  R007_NonBrace_2Analyzer
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
void R007_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_3Analyzer");
	//TO DO  R007_NonBrace_3Analyzer
};



//beg_NonBrace : 'LEFT_BRACKET'
void R007_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_4Analyzer");
	//TO DO  R007_NonBrace_4Analyzer
};



//beg_NonBrace : 'LEFT_PARENTHESES'
void R007_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_5Analyzer");
	//TO DO  R007_NonBrace_5Analyzer
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
void R007_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_6Analyzer");
	//TO DO  R007_NonBrace_6Analyzer
};



//beg_NonBrace : 'RIGHT_BRACKET'
void R007_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_7Analyzer");
	//TO DO  R007_NonBrace_7Analyzer
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
void R007_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_8Analyzer");
	//TO DO  R007_NonBrace_8Analyzer
};



//beg_NonBrace : 'EQUAL'
void R007_NonBrace_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR007("R007_NonBrace_9Analyzer");
	//TO DO  R007_NonBrace_9Analyzer
};



