#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R010_DefaultAnalyzer :virtual public SDT_genertor {
public: R010_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_DefaultAnalyzer();
};



//beg_ele_begin : TypeParameters
class R010_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ele_begin_0Analyzer();
};



//beg_TypeParameters : 'LEFT_ANGLE_BRACKET' TypeParameterList 'RIGHT_ANGLE_BRACKET'
class R010_TypeParameters_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameters_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameters_0Analyzer();
};



//beg_TypeParameterList : TypeParameter 'COMMA' TypeParameterList
class R010_TypeParameterList_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameterList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameterList_0Analyzer();
};



//beg_TypeParameterList : TypeParameter
class R010_TypeParameterList_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameterList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameterList_1Analyzer();
};



//beg_TypeParameter : AnnotationList Identifier TypeBound
class R010_TypeParameter_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameter_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameter_0Analyzer();
};



//beg_TypeParameter : Identifier TypeBound
class R010_TypeParameter_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameter_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameter_1Analyzer();
};



//beg_TypeParameter : AnnotationList Identifier
class R010_TypeParameter_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameter_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameter_2Analyzer();
};



//beg_TypeParameter : Identifier
class R010_TypeParameter_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeParameter_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeParameter_3Analyzer();
};



//beg_TypeBound : 'extends' AdditionalBoundList
class R010_TypeBound_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeBound_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeBound_0Analyzer();
};



//beg_AdditionalBoundList : ClassType 'AND' AdditionalBoundList
class R010_AdditionalBoundList_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_AdditionalBoundList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AdditionalBoundList_0Analyzer();
};



//beg_AdditionalBoundList : ClassType
class R010_AdditionalBoundList_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_AdditionalBoundList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AdditionalBoundList_1Analyzer();
};



//beg_ReferenceType : ClassType Dims
class R010_ReferenceType_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_ReferenceType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ReferenceType_0Analyzer();
};



//beg_ReferenceType : ClassType
class R010_ReferenceType_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_ReferenceType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ReferenceType_1Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
class R010_ClassTypeEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassTypeEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassTypeEle_0Analyzer();
};



//beg_ClassTypeEle : Identifier TypeArguments
class R010_ClassTypeEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassTypeEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassTypeEle_1Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier
class R010_ClassTypeEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassTypeEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassTypeEle_2Analyzer();
};



//beg_ClassTypeEle : Identifier
class R010_ClassTypeEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassTypeEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassTypeEle_3Analyzer();
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
class R010_ClassType_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassType_0Analyzer();
};



//beg_ClassType : ClassTypeEle
class R010_ClassType_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_ClassType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_ClassType_1Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R010_Dims_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_Dims_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Dims_0Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R010_Dims_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_Dims_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Dims_1Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R010_Dims_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_Dims_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Dims_2Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R010_Dims_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_Dims_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Dims_3Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_SHIFT2'
class R010_TypeArguments_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeArguments_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeArguments_0Analyzer();
};



//beg_TypeArgumentList : TypeArgument TypeArgumentList
class R010_TypeArgumentList_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeArgumentList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeArgumentList_0Analyzer();
};



//beg_TypeArgumentList : TypeArgument
class R010_TypeArgumentList_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeArgumentList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeArgumentList_1Analyzer();
};



//beg_TypeArgument : ReferenceType
class R010_TypeArgument_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeArgument_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeArgument_0Analyzer();
};



//beg_TypeArgument : Wildcard
class R010_TypeArgument_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_TypeArgument_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_TypeArgument_1Analyzer();
};



//beg_Wildcard : AnnotationList 'QUESTION' WildcardBounds
class R010_Wildcard_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_Wildcard_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Wildcard_0Analyzer();
};



//beg_Wildcard : 'QUESTION' WildcardBounds
class R010_Wildcard_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_Wildcard_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Wildcard_1Analyzer();
};



//beg_Wildcard : AnnotationList 'QUESTION'
class R010_Wildcard_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_Wildcard_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Wildcard_2Analyzer();
};



//beg_Wildcard : 'QUESTION'
class R010_Wildcard_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_Wildcard_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Wildcard_3Analyzer();
};



//beg_WildcardBounds : 'extends' ReferenceType
class R010_WildcardBounds_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_WildcardBounds_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_WildcardBounds_0Analyzer();
};



//beg_WildcardBounds : 'super' ReferenceType
class R010_WildcardBounds_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_WildcardBounds_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_WildcardBounds_1Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R010_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_Identifier_0Analyzer();
};



//beg_AnnotationList : Annotation AnnotationList
class R010_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AnnotationList_0Analyzer();
};



//beg_AnnotationList : Annotation
class R010_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AnnotationList_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R010_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R010_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : 0
class R010_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R010_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R010_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R010_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R010_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R010_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R010_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R010_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R010_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R010_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R010_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_9Analyzer();
};



//beg_NonPARENTHESES : AnnotationContent
class R010_NonPARENTHESES_10Analyzer :virtual public Non_Terminate_genertor {
public: R010_NonPARENTHESES_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_NonPARENTHESES_10Analyzer();
};



//beg_StatementEle : 'IDENTIFIER'
class R010_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R010_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R010_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R010_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R010_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R010_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R010_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R010_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R010_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R010_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R010_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R010_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R010_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_12Analyzer();
};



//beg_StatementEle : 'EQUAL'
class R010_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_13Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R010_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_14Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R010_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_15Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R010_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R010_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R010_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R010_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_19Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R010_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_20Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R010_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_21Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R010_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR'
class R010_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_23Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R010_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS'
class R010_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R010_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R010_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R010_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_28Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R010_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_29Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R010_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R010_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R010_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R010_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R010_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_34Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R010_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SLASH'
class R010_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_36Analyzer();
};



//beg_StatementEle : 'SPOT'
class R010_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_37Analyzer();
};



//beg_StatementEle : 'STAR'
class R010_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R010_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R010_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_40Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R010_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_41Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R010_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_42Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R010_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TILDE'
class R010_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R010_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R010_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R010_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_47Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R010_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_48Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R010_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_49Analyzer();
};



//beg_StatementEle : 'abstract'
class R010_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_50Analyzer();
};



//beg_StatementEle : 'boolean'
class R010_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_51Analyzer();
};



//beg_StatementEle : 'byte'
class R010_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_52Analyzer();
};



//beg_StatementEle : 'char'
class R010_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_53Analyzer();
};



//beg_StatementEle : 'class'
class R010_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_54Analyzer();
};



//beg_StatementEle : 'default'
class R010_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_55Analyzer();
};



//beg_StatementEle : 'double'
class R010_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_56Analyzer();
};



//beg_StatementEle : 'enum'
class R010_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_57Analyzer();
};



//beg_StatementEle : 'extends'
class R010_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_58Analyzer();
};



//beg_StatementEle : 'final'
class R010_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_59Analyzer();
};



//beg_StatementEle : 'float'
class R010_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_60Analyzer();
};



//beg_StatementEle : 'implements'
class R010_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_61Analyzer();
};



//beg_StatementEle : 'instanceof'
class R010_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_62Analyzer();
};



//beg_StatementEle : 'int'
class R010_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_63Analyzer();
};



//beg_StatementEle : 'interface'
class R010_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_64Analyzer();
};



//beg_StatementEle : 'long'
class R010_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_65Analyzer();
};



//beg_StatementEle : 'native'
class R010_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_66Analyzer();
};



//beg_StatementEle : 'new'
class R010_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_67Analyzer();
};



//beg_StatementEle : 'null'
class R010_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_68Analyzer();
};



//beg_StatementEle : 'private'
class R010_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_69Analyzer();
};



//beg_StatementEle : 'protected'
class R010_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_70Analyzer();
};



//beg_StatementEle : 'public'
class R010_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_71Analyzer();
};



//beg_StatementEle : 'short'
class R010_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_72Analyzer();
};



//beg_StatementEle : 'static'
class R010_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_73Analyzer();
};



//beg_StatementEle : 'super'
class R010_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_74Analyzer();
};



//beg_StatementEle : 'synchronized'
class R010_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_75Analyzer();
};



//beg_StatementEle : 'this'
class R010_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_76Analyzer();
};



//beg_StatementEle : 'throws'
class R010_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_77Analyzer();
};



//beg_StatementEle : 'transient'
class R010_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_78Analyzer();
};



//beg_StatementEle : 'void'
class R010_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_79Analyzer();
};



//beg_StatementEle : 'volatile'
class R010_StatementEle_80Analyzer :virtual public Non_Terminate_genertor {
public: R010_StatementEle_80Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R010_StatementEle_80Analyzer();
};
