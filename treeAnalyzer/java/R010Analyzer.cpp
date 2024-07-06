#include "R010Analyzer.h"
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
#include "../../symbols/java/DimListToken.h"
#include "../../symbols/java/FieldToken.h"
#include "../../symbols/java/UnannTypeToken.h"
#include "../../symbols/java/TypeListToken.h"
#include "../../symbols/java/TypeToken.h"
#include "../../symbols/java/TypeEntity.h"


#include <iostream>
#include <sstream>
using namespace std;

#include "R010Analyzer_1.h"

void logR010(const string& s) {
//		Util::log(s);
}


P_NodeValue R010_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR010("R010_DefaultAnalyzer");
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


//beg_ele_begin : TypeParameters
void R010_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ele_begin_0Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeParameters"];
   nodeValue->context["ele_begin"] = p0;

   env.list.push_back(nodeValue->context["ele_begin"]);

};



//beg_TypeParameters : 'LEFT_ANGLE_BRACKET' TypeParameterList 'RIGHT_ANGLE_BRACKET'
void R010_TypeParameters_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameters_0Analyzer");
   P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeParameterList"];
   nodeValue->context["TypeParameters"] = p1;
};



//beg_TypeParameterList : TypeParameter 'COMMA' TypeParameterList
void R010_TypeParameterList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameterList_0Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeParameter"];
   P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeParameterList"];

   ((TypeListToken *)(p2.get()))->list.push_front(((TypeToken *)(p0.get()))->typeEntity);


   nodeValue->context["TypeParameterList"] = p2;

};



//beg_TypeParameterList : TypeParameter
void R010_TypeParameterList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameterList_1Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeParameter"];

   TypeListToken *p = new TypeListToken();
   p->list.push_front(((TypeToken *)(p0.get()))->typeEntity);


   nodeValue->context["TypeParameterList"] = P_Token(p);


};



//beg_TypeParameter : AnnotationList Identifier TypeBound
void R010_TypeParameter_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameter_0Analyzer");
   Token * p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"].get();
   TypeToken *p = new TypeToken();
   P_TypeEntity typeEntity = P_TypeEntity(new TypeEntity);
   typeEntity->name = p1->content;
   p->typeEntity = typeEntity;

   nodeValue->context["TypeParameter"] = P_Token(p);
};



//beg_TypeParameter : Identifier TypeBound
void R010_TypeParameter_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameter_1Analyzer");
   Token * p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"].get();
   TypeToken *p = new TypeToken();
   P_TypeEntity typeEntity = P_TypeEntity(new TypeEntity);
   typeEntity->name = p0->content;
   p->typeEntity = typeEntity;

   nodeValue->context["TypeParameter"] = P_Token(p);
};



//beg_TypeParameter : AnnotationList Identifier
void R010_TypeParameter_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameter_2Analyzer");
   Token * p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"].get();
   TypeToken *p = new TypeToken();
   P_TypeEntity typeEntity = P_TypeEntity(new TypeEntity);
   typeEntity->name = p1->content;
   p->typeEntity = typeEntity;

   nodeValue->context["TypeParameter"] = P_Token(p);
};



//beg_TypeParameter : Identifier
void R010_TypeParameter_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeParameter_3Analyzer");

   Token * p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"].get();
   TypeToken *p = new TypeToken();
   P_TypeEntity typeEntity = P_TypeEntity(new TypeEntity);
   typeEntity->name= p0->content;
   p->typeEntity = typeEntity;

   nodeValue->context["TypeParameter"] = P_Token(p);

};



//beg_TypeBound : 'extends' AdditionalBoundList
void R010_TypeBound_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeBound_0Analyzer");
   //TO DO  R010_TypeBound_0Analyzer
};



//beg_AdditionalBoundList : ClassType 'AND' AdditionalBoundList
void R010_AdditionalBoundList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AdditionalBoundList_0Analyzer");
   //TO DO  R010_AdditionalBoundList_0Analyzer
};



//beg_AdditionalBoundList : ClassType
void R010_AdditionalBoundList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AdditionalBoundList_1Analyzer");
   //TO DO  R010_AdditionalBoundList_1Analyzer
};



//beg_ReferenceType : ClassType Dims
void R010_ReferenceType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ReferenceType_0Analyzer");
   //TO DO  R010_ReferenceType_0Analyzer
};



//beg_ReferenceType : ClassType
void R010_ReferenceType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ReferenceType_1Analyzer");
   //TO DO  R010_ReferenceType_1Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
void R010_ClassTypeEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassTypeEle_0Analyzer");
   //TO DO  R010_ClassTypeEle_0Analyzer
};



//beg_ClassTypeEle : Identifier TypeArguments
void R010_ClassTypeEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassTypeEle_1Analyzer");
   //TO DO  R010_ClassTypeEle_1Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier
void R010_ClassTypeEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassTypeEle_2Analyzer");
   //TO DO  R010_ClassTypeEle_2Analyzer
};



//beg_ClassTypeEle : Identifier
void R010_ClassTypeEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassTypeEle_3Analyzer");
   //TO DO  R010_ClassTypeEle_3Analyzer
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
void R010_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassType_0Analyzer");
   //TO DO  R010_ClassType_0Analyzer
};



//beg_ClassType : ClassTypeEle
void R010_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_ClassType_1Analyzer");
   //TO DO  R010_ClassType_1Analyzer
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R010_Dims_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Dims_0Analyzer");
   //TO DO  R010_Dims_0Analyzer
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R010_Dims_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Dims_1Analyzer");
   //TO DO  R010_Dims_1Analyzer
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R010_Dims_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Dims_2Analyzer");
   //TO DO  R010_Dims_2Analyzer
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R010_Dims_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Dims_3Analyzer");
   //TO DO  R010_Dims_3Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_SHIFT2'
void R010_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeArguments_0Analyzer");
   //TO DO  R010_TypeArguments_0Analyzer
};



//beg_TypeArgumentList : TypeArgument TypeArgumentList
void R010_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeArgumentList_0Analyzer");
   //TO DO  R010_TypeArgumentList_0Analyzer
};



//beg_TypeArgumentList : TypeArgument
void R010_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeArgumentList_1Analyzer");
   //TO DO  R010_TypeArgumentList_1Analyzer
};



//beg_TypeArgument : ReferenceType
void R010_TypeArgument_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeArgument_0Analyzer");
   //TO DO  R010_TypeArgument_0Analyzer
};



//beg_TypeArgument : Wildcard
void R010_TypeArgument_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_TypeArgument_1Analyzer");
   //TO DO  R010_TypeArgument_1Analyzer
};



//beg_Wildcard : AnnotationList 'QUESTION' WildcardBounds
void R010_Wildcard_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Wildcard_0Analyzer");
   //TO DO  R010_Wildcard_0Analyzer
};



//beg_Wildcard : 'QUESTION' WildcardBounds
void R010_Wildcard_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Wildcard_1Analyzer");
   //TO DO  R010_Wildcard_1Analyzer
};



//beg_Wildcard : AnnotationList 'QUESTION'
void R010_Wildcard_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Wildcard_2Analyzer");
   //TO DO  R010_Wildcard_2Analyzer
};



//beg_Wildcard : 'QUESTION'
void R010_Wildcard_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Wildcard_3Analyzer");
   //TO DO  R010_Wildcard_3Analyzer
};



//beg_WildcardBounds : 'extends' ReferenceType
void R010_WildcardBounds_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_WildcardBounds_0Analyzer");
   //TO DO  R010_WildcardBounds_0Analyzer
};



//beg_WildcardBounds : 'super' ReferenceType
void R010_WildcardBounds_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_WildcardBounds_1Analyzer");
   //TO DO  R010_WildcardBounds_1Analyzer
};



//beg_Identifier : 'IDENTIFIER'
void R010_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_Identifier_0Analyzer");
   nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_AnnotationList : Annotation AnnotationList
void R010_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AnnotationList_0Analyzer");
   //TO DO  R010_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R010_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AnnotationList_1Analyzer");
   //TO DO  R010_AnnotationList_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R010_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AnnotationContent_0Analyzer");
   //TO DO  R010_AnnotationContent_0Analyzer
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R010_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AnnotationContentStatements_0Analyzer");
   //TO DO  R010_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R010_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_AnnotationContentStatements_1Analyzer");
   //TO DO  R010_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R010_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_0Analyzer");
   //TO DO  R010_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R010_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_1Analyzer");
   //TO DO  R010_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R010_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_2Analyzer");
   //TO DO  R010_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R010_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_3Analyzer");
   //TO DO  R010_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R010_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_4Analyzer");
   //TO DO  R010_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R010_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_5Analyzer");
   //TO DO  R010_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R010_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_6Analyzer");
   //TO DO  R010_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R010_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_7Analyzer");
   //TO DO  R010_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R010_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_8Analyzer");
   //TO DO  R010_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R010_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_9Analyzer");
   //TO DO  R010_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : AnnotationContent
void R010_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_NonPARENTHESES_10Analyzer");
   //TO DO  R010_NonPARENTHESES_10Analyzer
};



//beg_StatementEle : 'IDENTIFIER'
void R010_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_0Analyzer");
   //TO DO  R010_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R010_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_1Analyzer");
   //TO DO  R010_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R010_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_2Analyzer");
   //TO DO  R010_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R010_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_3Analyzer");
   //TO DO  R010_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R010_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_4Analyzer");
   //TO DO  R010_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R010_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_5Analyzer");
   //TO DO  R010_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R010_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_6Analyzer");
   //TO DO  R010_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R010_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_7Analyzer");
   //TO DO  R010_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R010_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_8Analyzer");
   //TO DO  R010_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R010_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_9Analyzer");
   //TO DO  R010_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R010_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_10Analyzer");
   //TO DO  R010_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R010_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_11Analyzer");
   //TO DO  R010_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R010_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_12Analyzer");
   //TO DO  R010_StatementEle_12Analyzer
};



//beg_StatementEle : 'EQUAL'
void R010_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_13Analyzer");
   //TO DO  R010_StatementEle_13Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R010_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_14Analyzer");
   //TO DO  R010_StatementEle_14Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R010_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_15Analyzer");
   //TO DO  R010_StatementEle_15Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R010_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_16Analyzer");
   //TO DO  R010_StatementEle_16Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R010_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_17Analyzer");
   //TO DO  R010_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R010_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_18Analyzer");
   //TO DO  R010_StatementEle_18Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R010_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_19Analyzer");
   //TO DO  R010_StatementEle_19Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R010_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_20Analyzer");
   //TO DO  R010_StatementEle_20Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R010_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_21Analyzer");
   //TO DO  R010_StatementEle_21Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R010_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_22Analyzer");
   //TO DO  R010_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR'
void R010_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_23Analyzer");
   //TO DO  R010_StatementEle_23Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R010_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_24Analyzer");
   //TO DO  R010_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS'
void R010_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_25Analyzer");
   //TO DO  R010_StatementEle_25Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R010_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_26Analyzer");
   //TO DO  R010_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R010_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_27Analyzer");
   //TO DO  R010_StatementEle_27Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R010_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_28Analyzer");
   //TO DO  R010_StatementEle_28Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R010_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_29Analyzer");
   //TO DO  R010_StatementEle_29Analyzer
};



//beg_StatementEle : 'QUESTION'
void R010_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_30Analyzer");
   //TO DO  R010_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R010_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_31Analyzer");
   //TO DO  R010_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R010_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_32Analyzer");
   //TO DO  R010_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R010_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_33Analyzer");
   //TO DO  R010_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R010_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_34Analyzer");
   //TO DO  R010_StatementEle_34Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R010_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_35Analyzer");
   //TO DO  R010_StatementEle_35Analyzer
};



//beg_StatementEle : 'SLASH'
void R010_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_36Analyzer");
   //TO DO  R010_StatementEle_36Analyzer
};



//beg_StatementEle : 'SPOT'
void R010_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_37Analyzer");
   //TO DO  R010_StatementEle_37Analyzer
};



//beg_StatementEle : 'STAR'
void R010_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_38Analyzer");
   //TO DO  R010_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R010_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_39Analyzer");
   //TO DO  R010_StatementEle_39Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R010_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_40Analyzer");
   //TO DO  R010_StatementEle_40Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R010_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_41Analyzer");
   //TO DO  R010_StatementEle_41Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R010_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_42Analyzer");
   //TO DO  R010_StatementEle_42Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R010_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_43Analyzer");
   //TO DO  R010_StatementEle_43Analyzer
};



//beg_StatementEle : 'TILDE'
void R010_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_44Analyzer");
   //TO DO  R010_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R010_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_45Analyzer");
   //TO DO  R010_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R010_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_46Analyzer");
   //TO DO  R010_StatementEle_46Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R010_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_47Analyzer");
   //TO DO  R010_StatementEle_47Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R010_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_48Analyzer");
   //TO DO  R010_StatementEle_48Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R010_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_49Analyzer");
   //TO DO  R010_StatementEle_49Analyzer
};



//beg_StatementEle : 'abstract'
void R010_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_50Analyzer");
   //TO DO  R010_StatementEle_50Analyzer
};



//beg_StatementEle : 'boolean'
void R010_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_51Analyzer");
   //TO DO  R010_StatementEle_51Analyzer
};



//beg_StatementEle : 'byte'
void R010_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_52Analyzer");
   //TO DO  R010_StatementEle_52Analyzer
};



//beg_StatementEle : 'char'
void R010_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_53Analyzer");
   //TO DO  R010_StatementEle_53Analyzer
};



//beg_StatementEle : 'class'
void R010_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_54Analyzer");
   //TO DO  R010_StatementEle_54Analyzer
};



//beg_StatementEle : 'default'
void R010_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_55Analyzer");
   //TO DO  R010_StatementEle_55Analyzer
};



//beg_StatementEle : 'double'
void R010_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_56Analyzer");
   //TO DO  R010_StatementEle_56Analyzer
};



//beg_StatementEle : 'enum'
void R010_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_57Analyzer");
   //TO DO  R010_StatementEle_57Analyzer
};



//beg_StatementEle : 'extends'
void R010_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_58Analyzer");
   //TO DO  R010_StatementEle_58Analyzer
};



//beg_StatementEle : 'final'
void R010_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_59Analyzer");
   //TO DO  R010_StatementEle_59Analyzer
};



//beg_StatementEle : 'float'
void R010_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_60Analyzer");
   //TO DO  R010_StatementEle_60Analyzer
};



//beg_StatementEle : 'implements'
void R010_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_61Analyzer");
   //TO DO  R010_StatementEle_61Analyzer
};



//beg_StatementEle : 'instanceof'
void R010_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_62Analyzer");
   //TO DO  R010_StatementEle_62Analyzer
};



//beg_StatementEle : 'int'
void R010_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_63Analyzer");
   //TO DO  R010_StatementEle_63Analyzer
};



//beg_StatementEle : 'interface'
void R010_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_64Analyzer");
   //TO DO  R010_StatementEle_64Analyzer
};



//beg_StatementEle : 'long'
void R010_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_65Analyzer");
   //TO DO  R010_StatementEle_65Analyzer
};



//beg_StatementEle : 'native'
void R010_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_66Analyzer");
   //TO DO  R010_StatementEle_66Analyzer
};



//beg_StatementEle : 'new'
void R010_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_67Analyzer");
   //TO DO  R010_StatementEle_67Analyzer
};



//beg_StatementEle : 'null'
void R010_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_68Analyzer");
   //TO DO  R010_StatementEle_68Analyzer
};



//beg_StatementEle : 'private'
void R010_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_69Analyzer");
   //TO DO  R010_StatementEle_69Analyzer
};



//beg_StatementEle : 'protected'
void R010_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_70Analyzer");
   //TO DO  R010_StatementEle_70Analyzer
};



//beg_StatementEle : 'public'
void R010_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_71Analyzer");
   //TO DO  R010_StatementEle_71Analyzer
};



//beg_StatementEle : 'short'
void R010_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_72Analyzer");
   //TO DO  R010_StatementEle_72Analyzer
};



//beg_StatementEle : 'static'
void R010_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_73Analyzer");
   //TO DO  R010_StatementEle_73Analyzer
};



//beg_StatementEle : 'super'
void R010_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_74Analyzer");
   //TO DO  R010_StatementEle_74Analyzer
};



//beg_StatementEle : 'synchronized'
void R010_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_75Analyzer");
   //TO DO  R010_StatementEle_75Analyzer
};



//beg_StatementEle : 'this'
void R010_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_76Analyzer");
   //TO DO  R010_StatementEle_76Analyzer
};



//beg_StatementEle : 'throws'
void R010_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_77Analyzer");
   //TO DO  R010_StatementEle_77Analyzer
};



//beg_StatementEle : 'transient'
void R010_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_78Analyzer");
   //TO DO  R010_StatementEle_78Analyzer
};



//beg_StatementEle : 'void'
void R010_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_79Analyzer");
   //TO DO  R010_StatementEle_79Analyzer
};



//beg_StatementEle : 'volatile'
void R010_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR010("R010_StatementEle_80Analyzer");
   //TO DO  R010_StatementEle_80Analyzer
};



