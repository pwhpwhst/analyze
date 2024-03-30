#include "R006Analyzer.h"
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

#include "R006Analyzer_1.h"

void logR006(const string& s) {
	//	cout << s << endl;
}



P_NodeValue R006_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR006("R006_DefaultAnalyzer");
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

//beg_ele_begin : ParameterListWithParentheses
void R006_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ParameterListWithParentheses"];
	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_ParameterListWithParentheses : 'LEFT_PARENTHESES' FormalParameterList 'RIGHT_PARENTHESES'
void R006_ParameterListWithParentheses_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ParameterListWithParentheses_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["FormalParameterList"];
	nodeValue->context["ParameterListWithParentheses"] = p1;
};



//beg_ParameterListWithParentheses : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
void R006_ParameterListWithParentheses_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ParameterListWithParentheses_1Analyzer");
	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "Empty";
	p->statementEntity = P_StatementEntity(statementEntity);
	nodeValue->context["ParameterListWithParentheses"] = P_Token(p);
};


//beg_FormalParameterList : Parameter 'COMMA' FormalParameterList
void R006_FormalParameterList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_FormalParameterList_0Analyzer");


	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Parameter"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["FormalParameterList"];


	FieldToken *fieldP = new FieldToken();
	fieldP->unannType = ((DimListToken *)(p0.get()))->resultType;
	fieldP->name = ((DimListToken *)(p0.get()))->name;
	fieldP->dimNum = ((DimListToken *)(p0.get()))->num;
	fieldP->isMultiParameters = ((DimListToken *)(p0.get()))->isMultiParameters;
	fieldP->isReceiverParameter = ((DimListToken *)(p0.get()))->isReceiverParameter;
	((StatementToken *)(p2.get()))->statementEntity->fieldList.push_front(P_FieldToken(fieldP));

	nodeValue->context["FormalParameterList"] = p2;

};



//beg_FormalParameterList : Parameter
void R006_FormalParameterList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_FormalParameterList_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Parameter"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "FormalParameterList";

	FieldToken *fieldP = new FieldToken();
	fieldP->unannType = ((DimListToken *)(p0.get()))->resultType;
	fieldP->name = ((DimListToken *)(p0.get()))->name;
	fieldP->dimNum = ((DimListToken *)(p0.get()))->num;
	fieldP->isMultiParameters = ((DimListToken *)(p0.get()))->isMultiParameters;
	fieldP->isReceiverParameter = ((DimListToken *)(p0.get()))->isReceiverParameter;
	statementEntity->fieldList.push_front(P_FieldToken(fieldP));

	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["FormalParameterList"] = P_Token(p);
};



//beg_Parameter : ReceiverParameter
void R006_Parameter_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Parameter_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ReceiverParameter"];
	nodeValue->context["Parameter"] = p0;
};



//beg_Parameter : FormalParameter
void R006_Parameter_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Parameter_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["FormalParameter"];
	nodeValue->context["Parameter"] = p0;
};



//beg_Parameter : LastFormalParameter
void R006_Parameter_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Parameter_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["LastFormalParameter"];
	nodeValue->context["Parameter"] = p0;
};



//beg_VariableModifierList : 'final' VariableModifierList
void R006_VariableModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableModifierList_0Analyzer");
	//TO DO  R006_VariableModifierList_0Analyzer
};



//beg_VariableModifierList : AnnotationList VariableModifierList
void R006_VariableModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableModifierList_1Analyzer");
	//TO DO  R006_VariableModifierList_1Analyzer
};



//beg_VariableModifierList : 'final'
void R006_VariableModifierList_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableModifierList_2Analyzer");
	//TO DO  R006_VariableModifierList_2Analyzer
};



//beg_VariableModifierList : AnnotationList
void R006_VariableModifierList_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableModifierList_3Analyzer");
	//TO DO  R006_VariableModifierList_3Analyzer
};



//beg_LastFormalParameter : VariableModifierList UnannType 'THREE_SPOT' VariableDeclaratorId
void R006_LastFormalParameter_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_LastFormalParameter_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p3.get()))->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((DimListToken *)(p3.get()))->isMultiParameters = true;
	((DimListToken *)(p3.get()))->isReceiverParameter = false;
	nodeValue->context["LastFormalParameter"] = p3;
};



//beg_LastFormalParameter : VariableModifierList UnannType AnnotationList 'THREE_SPOT' VariableDeclaratorId
void R006_LastFormalParameter_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_LastFormalParameter_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p4.get()))->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((DimListToken *)(p4.get()))->isMultiParameters = true;
	((DimListToken *)(p4.get()))->isReceiverParameter = false;
	nodeValue->context["LastFormalParameter"] = p4;
};



//beg_LastFormalParameter : UnannType 'THREE_SPOT' VariableDeclaratorId
void R006_LastFormalParameter_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_LastFormalParameter_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p2.get()))->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	((DimListToken *)(p2.get()))->isMultiParameters = true;
	((DimListToken *)(p2.get()))->isReceiverParameter = false;
	nodeValue->context["LastFormalParameter"] = p2;
};



//beg_LastFormalParameter : UnannType AnnotationList 'THREE_SPOT' VariableDeclaratorId
void R006_LastFormalParameter_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_LastFormalParameter_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p3.get()))->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	((DimListToken *)(p3.get()))->isMultiParameters = true;
	((DimListToken *)(p3.get()))->isReceiverParameter = false;
	nodeValue->context["LastFormalParameter"] = p3;
};



//beg_LastFormalParameter : FormalParameter
void R006_LastFormalParameter_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_LastFormalParameter_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["FormalParameter"];
	nodeValue->context["LastFormalParameter"] = p0;
};



//beg_FormalParameter : UnannType VariableDeclaratorId
void R006_FormalParameter_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_FormalParameter_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p1.get()))->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	((DimListToken *)(p1.get()))->isMultiParameters = false;
	((DimListToken *)(p1.get()))->isReceiverParameter = false;
	nodeValue->context["FormalParameter"] = p1;
};



//beg_FormalParameter : VariableModifierList UnannType VariableDeclaratorId
void R006_FormalParameter_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_FormalParameter_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorId"];

	((DimListToken *)(p2.get()))->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((DimListToken *)(p2.get()))->isMultiParameters = false;
	((DimListToken *)(p1.get()))->isReceiverParameter = false;
	nodeValue->context["FormalParameter"] = p2;
};



//beg_ReceiverParameter : UnannType 'this'
void R006_ReceiverParameter_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ReceiverParameter_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = "";
	p->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	p->isMultiParameters = false;
	p->isReceiverParameter = true;

	nodeValue->context["ReceiverParameter"] = P_Token(p);
};



//beg_ReceiverParameter : AnnotationList UnannType 'this'
void R006_ReceiverParameter_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ReceiverParameter_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = "";
	p->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	p->isMultiParameters = false;
	p->isReceiverParameter = true;

	nodeValue->context["ReceiverParameter"] = P_Token(p);
};



//beg_ReceiverParameter : UnannType Identifier 'SPOT' 'this'
void R006_ReceiverParameter_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ReceiverParameter_2Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = p1->content;
	p->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	p->isMultiParameters = false;
	p->isReceiverParameter = true;

	nodeValue->context["ReceiverParameter"] = P_Token(p);

};



//beg_ReceiverParameter : AnnotationList UnannType Identifier 'SPOT' 'this'
void R006_ReceiverParameter_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_ReceiverParameter_3Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = p2->content;
	p->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	p->isMultiParameters = false;
	p->isReceiverParameter = true;

	nodeValue->context["ReceiverParameter"] = P_Token(p);
};



//beg_VariableDeclaratorId : Identifier Dims
void R006_VariableDeclaratorId_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableDeclaratorId_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p1.get()))->name = p0->content;

	nodeValue->context["VariableDeclaratorId"] = p1;
};


//beg_VariableDeclaratorId : Identifier
void R006_VariableDeclaratorId_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_VariableDeclaratorId_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = p0->content;


	nodeValue->context["VariableDeclaratorId"] = P_Token(p);

};



//beg_Identifier : 'IDENTIFIER'
void R006_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R006_Dims_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Dims_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p2.get()))->num = ((DimListToken *)(p2.get()))->num + 1;

	nodeValue->context["Dims"] = p2;

};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R006_Dims_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Dims_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p3.get()))->num = ((DimListToken *)(p3.get()))->num + 1;

	nodeValue->context["Dims"] = p3;
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R006_Dims_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Dims_2Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);

};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R006_Dims_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Dims_3Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);
};


//beg_AnnotationList : Annotation AnnotationList
void R006_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_AnnotationList_0Analyzer");
	//TO DO  R006_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R006_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_AnnotationList_1Analyzer");
	//TO DO  R006_AnnotationList_1Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R006_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Annotation_0Analyzer");
	//TO DO  R006_Annotation_0Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier
void R006_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_Annotation_1Analyzer");
	//TO DO  R006_Annotation_1Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R006_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_DetailIdentifier_0Analyzer");
	//TO DO  R006_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R006_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_DetailIdentifier_1Analyzer");
	//TO DO  R006_DetailIdentifier_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R006_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_AnnotationContent_0Analyzer");
	//TO DO  R006_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R006_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_AnnotationContentStatements_0Analyzer");
	//TO DO  R006_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R006_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_AnnotationContentStatements_1Analyzer");
	//TO DO  R006_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R006_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_0Analyzer");
	//TO DO  R006_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R006_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_1Analyzer");
	//TO DO  R006_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R006_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_2Analyzer");
	//TO DO  R006_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R006_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_3Analyzer");
	//TO DO  R006_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R006_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_4Analyzer");
	//TO DO  R006_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R006_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_5Analyzer");
	//TO DO  R006_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R006_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_6Analyzer");
	//TO DO  R006_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R006_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_7Analyzer");
	//TO DO  R006_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R006_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_8Analyzer");
	//TO DO  R006_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R006_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_9Analyzer");
	//TO DO  R006_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : 'EQUAL'
void R006_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonPARENTHESES_10Analyzer");
	//TO DO  R006_NonPARENTHESES_10Analyzer
};



//beg_StatementEle : Identifier
void R006_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_0Analyzer");
	//TO DO  R006_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R006_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_1Analyzer");
	//TO DO  R006_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R006_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_2Analyzer");
	//TO DO  R006_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R006_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_3Analyzer");
	//TO DO  R006_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R006_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_4Analyzer");
	//TO DO  R006_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R006_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_5Analyzer");
	//TO DO  R006_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R006_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_6Analyzer");
	//TO DO  R006_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R006_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_7Analyzer");
	//TO DO  R006_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R006_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_8Analyzer");
	//TO DO  R006_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R006_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_9Analyzer");
	//TO DO  R006_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R006_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_10Analyzer");
	//TO DO  R006_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R006_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_11Analyzer");
	//TO DO  R006_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R006_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_12Analyzer");
	//TO DO  R006_StatementEle_12Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R006_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_13Analyzer");
	//TO DO  R006_StatementEle_13Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R006_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_14Analyzer");
	//TO DO  R006_StatementEle_14Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R006_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_15Analyzer");
	//TO DO  R006_StatementEle_15Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R006_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_16Analyzer");
	//TO DO  R006_StatementEle_16Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R006_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_17Analyzer");
	//TO DO  R006_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R006_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_18Analyzer");
	//TO DO  R006_StatementEle_18Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R006_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_19Analyzer");
	//TO DO  R006_StatementEle_19Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R006_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_20Analyzer");
	//TO DO  R006_StatementEle_20Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R006_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_21Analyzer");
	//TO DO  R006_StatementEle_21Analyzer
};



//beg_StatementEle : 'OR'
void R006_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_22Analyzer");
	//TO DO  R006_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R006_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_23Analyzer");
	//TO DO  R006_StatementEle_23Analyzer
};



//beg_StatementEle : 'PLUS'
void R006_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_24Analyzer");
	//TO DO  R006_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R006_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_25Analyzer");
	//TO DO  R006_StatementEle_25Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R006_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_26Analyzer");
	//TO DO  R006_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R006_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_27Analyzer");
	//TO DO  R006_StatementEle_27Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R006_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_28Analyzer");
	//TO DO  R006_StatementEle_28Analyzer
};



//beg_StatementEle : 'QUESTION'
void R006_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_29Analyzer");
	//TO DO  R006_StatementEle_29Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R006_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_30Analyzer");
	//TO DO  R006_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R006_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_31Analyzer");
	//TO DO  R006_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R006_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_32Analyzer");
	//TO DO  R006_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R006_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_33Analyzer");
	//TO DO  R006_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R006_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_34Analyzer");
	//TO DO  R006_StatementEle_34Analyzer
};



//beg_StatementEle : 'SLASH'
void R006_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_35Analyzer");
	//TO DO  R006_StatementEle_35Analyzer
};



//beg_StatementEle : 'SPOT'
void R006_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_36Analyzer");
	//TO DO  R006_StatementEle_36Analyzer
};



//beg_StatementEle : 'STAR'
void R006_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_37Analyzer");
	//TO DO  R006_StatementEle_37Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R006_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_38Analyzer");
	//TO DO  R006_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R006_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_39Analyzer");
	//TO DO  R006_StatementEle_39Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R006_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_40Analyzer");
	//TO DO  R006_StatementEle_40Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R006_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_41Analyzer");
	//TO DO  R006_StatementEle_41Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R006_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_42Analyzer");
	//TO DO  R006_StatementEle_42Analyzer
};



//beg_StatementEle : 'TILDE'
void R006_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_43Analyzer");
	//TO DO  R006_StatementEle_43Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R006_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_44Analyzer");
	//TO DO  R006_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R006_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_45Analyzer");
	//TO DO  R006_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R006_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_46Analyzer");
	//TO DO  R006_StatementEle_46Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R006_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_47Analyzer");
	//TO DO  R006_StatementEle_47Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R006_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_48Analyzer");
	//TO DO  R006_StatementEle_48Analyzer
};



//beg_StatementEle : 'abstract'
void R006_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_49Analyzer");
	//TO DO  R006_StatementEle_49Analyzer
};



//beg_StatementEle : UnannPrimitiveType
void R006_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_50Analyzer");
	//TO DO  R006_StatementEle_50Analyzer
};



//beg_StatementEle : 'class'
void R006_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_51Analyzer");
	//TO DO  R006_StatementEle_51Analyzer
};



//beg_StatementEle : 'default'
void R006_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_52Analyzer");
	//TO DO  R006_StatementEle_52Analyzer
};



//beg_StatementEle : 'enum'
void R006_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_53Analyzer");
	//TO DO  R006_StatementEle_53Analyzer
};



//beg_StatementEle : 'extends'
void R006_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_54Analyzer");
	//TO DO  R006_StatementEle_54Analyzer
};



//beg_StatementEle : 'final'
void R006_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_55Analyzer");
	//TO DO  R006_StatementEle_55Analyzer
};



//beg_StatementEle : 'implements'
void R006_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_56Analyzer");
	//TO DO  R006_StatementEle_56Analyzer
};



//beg_StatementEle : 'instanceof'
void R006_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_57Analyzer");
	//TO DO  R006_StatementEle_57Analyzer
};



//beg_StatementEle : 'interface'
void R006_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_58Analyzer");
	//TO DO  R006_StatementEle_58Analyzer
};



//beg_StatementEle : 'native'
void R006_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_59Analyzer");
	//TO DO  R006_StatementEle_59Analyzer
};



//beg_StatementEle : 'new'
void R006_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_60Analyzer");
	//TO DO  R006_StatementEle_60Analyzer
};



//beg_StatementEle : 'null'
void R006_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_61Analyzer");
	//TO DO  R006_StatementEle_61Analyzer
};



//beg_StatementEle : 'private'
void R006_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_62Analyzer");
	//TO DO  R006_StatementEle_62Analyzer
};



//beg_StatementEle : 'protected'
void R006_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_63Analyzer");
	//TO DO  R006_StatementEle_63Analyzer
};



//beg_StatementEle : 'public'
void R006_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_64Analyzer");
	//TO DO  R006_StatementEle_64Analyzer
};



//beg_StatementEle : 'static'
void R006_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_65Analyzer");
	//TO DO  R006_StatementEle_65Analyzer
};



//beg_StatementEle : 'super'
void R006_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_66Analyzer");
	//TO DO  R006_StatementEle_66Analyzer
};



//beg_StatementEle : 'synchronized'
void R006_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_67Analyzer");
	//TO DO  R006_StatementEle_67Analyzer
};



//beg_StatementEle : 'this'
void R006_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_68Analyzer");
	//TO DO  R006_StatementEle_68Analyzer
};



//beg_StatementEle : 'throws'
void R006_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_69Analyzer");
	//TO DO  R006_StatementEle_69Analyzer
};



//beg_StatementEle : 'transient'
void R006_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_70Analyzer");
	//TO DO  R006_StatementEle_70Analyzer
};



//beg_StatementEle : 'void'
void R006_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_71Analyzer");
	//TO DO  R006_StatementEle_71Analyzer
};



//beg_StatementEle : 'volatile'
void R006_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_StatementEle_72Analyzer");
	//TO DO  R006_StatementEle_72Analyzer
};







//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
void R006_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArguments_0Analyzer");
	//TO DO  R006_TypeArguments_0Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
void R006_TypeArguments_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArguments_1Analyzer");
	//TO DO  R006_TypeArguments_1Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
void R006_TypeArguments_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArguments_2Analyzer");
	//TO DO  R006_TypeArguments_2Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R006_TypeArguments_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArguments_3Analyzer");
	//TO DO  R006_TypeArguments_3Analyzer
};



//beg_TypeArgumentListL2 : TypeArguments TypeArgumentListL2
void R006_TypeArgumentListL2_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL2_0Analyzer");
	//TO DO  R006_TypeArgumentListL2_0Analyzer
};



//beg_TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
void R006_TypeArgumentListL2_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL2_1Analyzer");
	//TO DO  R006_TypeArgumentListL2_1Analyzer
};



//beg_TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
void R006_TypeArgumentListL2_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL2_2Analyzer");
	//TO DO  R006_TypeArgumentListL2_2Analyzer
};



//beg_TypeArgumentListL1 : TypeArguments TypeArgumentListL1
void R006_TypeArgumentListL1_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL1_0Analyzer");
	//TO DO  R006_TypeArgumentListL1_0Analyzer
};



//beg_TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
void R006_TypeArgumentListL1_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL1_1Analyzer");
	//TO DO  R006_TypeArgumentListL1_1Analyzer
};



//beg_TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
void R006_TypeArgumentListL1_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentListL1_2Analyzer");
	//TO DO  R006_TypeArgumentListL1_2Analyzer
};



//beg_TypeArgumentList : TypeArguments TypeArgumentList
void R006_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentList_0Analyzer");
	//TO DO  R006_TypeArgumentList_0Analyzer
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R006_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentList_1Analyzer");
	//TO DO  R006_TypeArgumentList_1Analyzer
};



//beg_TypeArgumentList : 0
void R006_TypeArgumentList_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_TypeArgumentList_2Analyzer");
	//TO DO  R006_TypeArgumentList_2Analyzer
};



//beg_NonANGLE_BRACKET : 'QUESTION'
void R006_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_0Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_0Analyzer
};



//beg_NonANGLE_BRACKET : 'extends'
void R006_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_1Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_1Analyzer
};



//beg_NonANGLE_BRACKET : 'super'
void R006_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_2Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_2Analyzer
};



//beg_NonANGLE_BRACKET : 'COMMA'
void R006_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_3Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_3Analyzer
};



//beg_NonANGLE_BRACKET : Identifier
void R006_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_4Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_4Analyzer
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
void R006_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_5Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_5Analyzer
};



//beg_NonANGLE_BRACKET : 'SPOT'
void R006_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_6Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_6Analyzer
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
void R006_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_7Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_7Analyzer
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R006_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_8Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_8Analyzer
};

//beg_NonANGLE_BRACKET : TypeArguments
void R006_NonANGLE_BRACKET_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_NonANGLE_BRACKET_9Analyzer");
	//TO DO  R006_NonANGLE_BRACKET_9Analyzer
};



//beg_UnannType : UnannArrayType
void R006_UnannType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannArrayType"];
	nodeValue->context["UnannType"] = p0;
};


//beg_UnannType : UnannPrimitiveType
void R006_UnannType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	nodeValue->context["UnannType"] = p0;

};



//beg_UnannType : UnannClassOrInterfaceType
void R006_UnannType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	nodeValue->context["UnannType"] = p0;
};







//beg_UnannPrimitiveType : 'boolean'
void R006_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_0Analyzer");

	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("boolean");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);


};



//beg_UnannPrimitiveType : 'byte'
void R006_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_1Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("byte");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'short'
void R006_UnannPrimitiveType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_2Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("short");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'int'
void R006_UnannPrimitiveType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_3Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("int");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'long'
void R006_UnannPrimitiveType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_4Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("long");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'char'
void R006_UnannPrimitiveType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_5Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("char");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'float'
void R006_UnannPrimitiveType_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_6Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("float");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'double'
void R006_UnannPrimitiveType_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannPrimitiveType_7Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("double");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};




//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' AnnotationList UnannClassOrInterfaceType
void R006_UnannClassOrInterfaceType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p4.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p4;
};



//beg_UnannClassOrInterfaceType : Identifier 'SPOT' AnnotationList UnannClassOrInterfaceType
void R006_UnannClassOrInterfaceType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' UnannClassOrInterfaceType
void R006_UnannClassOrInterfaceType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier 'SPOT' UnannClassOrInterfaceType
void R006_UnannClassOrInterfaceType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p2.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p2;

};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments
void R006_UnannClassOrInterfaceType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};



//beg_UnannClassOrInterfaceType : Identifier
void R006_UnannClassOrInterfaceType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannClassOrInterfaceType_5Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};




//beg_UnannArrayType : UnannPrimitiveType Dims
void R006_UnannArrayType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannArrayType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



//beg_UnannArrayType : UnannClassOrInterfaceType Dims
void R006_UnannArrayType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR006("R006_UnannArrayType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



