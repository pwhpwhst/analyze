#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R006_DefaultAnalyzer :virtual public SDT_genertor {
public: R006_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_DefaultAnalyzer();
};



//beg_ele_begin : ParameterListWithParentheses
class R006_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ele_begin_0Analyzer();
};



//beg_ParameterListWithParentheses : 'LEFT_PARENTHESES' FormalParameterList 'RIGHT_PARENTHESES'
class R006_ParameterListWithParentheses_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_ParameterListWithParentheses_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ParameterListWithParentheses_0Analyzer();
};



//beg_ParameterListWithParentheses : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
class R006_ParameterListWithParentheses_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_ParameterListWithParentheses_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ParameterListWithParentheses_1Analyzer();
};



//beg_FormalParameterList : Parameter 'COMMA' FormalParameterList
class R006_FormalParameterList_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_FormalParameterList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_FormalParameterList_0Analyzer();
};



//beg_FormalParameterList : Parameter
class R006_FormalParameterList_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_FormalParameterList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_FormalParameterList_1Analyzer();
};



//beg_Parameter : ReceiverParameter
class R006_Parameter_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_Parameter_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Parameter_0Analyzer();
};



//beg_Parameter : FormalParameter
class R006_Parameter_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_Parameter_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Parameter_1Analyzer();
};



//beg_Parameter : LastFormalParameter
class R006_Parameter_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_Parameter_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Parameter_2Analyzer();
};



//beg_VariableModifierList : 'final' VariableModifierList
class R006_VariableModifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableModifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableModifierList_0Analyzer();
};



//beg_VariableModifierList : AnnotationList VariableModifierList
class R006_VariableModifierList_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableModifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableModifierList_1Analyzer();
};



//beg_VariableModifierList : 'final'
class R006_VariableModifierList_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableModifierList_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableModifierList_2Analyzer();
};



//beg_VariableModifierList : AnnotationList
class R006_VariableModifierList_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableModifierList_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableModifierList_3Analyzer();
};



//beg_LastFormalParameter : VariableModifierList UnannType 'THREE_SPOT' VariableDeclaratorId
class R006_LastFormalParameter_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_LastFormalParameter_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_LastFormalParameter_0Analyzer();
};



//beg_LastFormalParameter : VariableModifierList UnannType AnnotationList 'THREE_SPOT' VariableDeclaratorId
class R006_LastFormalParameter_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_LastFormalParameter_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_LastFormalParameter_1Analyzer();
};



//beg_LastFormalParameter : UnannType 'THREE_SPOT' VariableDeclaratorId
class R006_LastFormalParameter_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_LastFormalParameter_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_LastFormalParameter_2Analyzer();
};



//beg_LastFormalParameter : UnannType AnnotationList 'THREE_SPOT' VariableDeclaratorId
class R006_LastFormalParameter_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_LastFormalParameter_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_LastFormalParameter_3Analyzer();
};



//beg_LastFormalParameter : FormalParameter
class R006_LastFormalParameter_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_LastFormalParameter_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_LastFormalParameter_4Analyzer();
};



//beg_FormalParameter : UnannType VariableDeclaratorId
class R006_FormalParameter_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_FormalParameter_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_FormalParameter_0Analyzer();
};



//beg_FormalParameter : VariableModifierList UnannType VariableDeclaratorId
class R006_FormalParameter_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_FormalParameter_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_FormalParameter_1Analyzer();
};



//beg_ReceiverParameter : UnannType 'this'
class R006_ReceiverParameter_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_ReceiverParameter_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ReceiverParameter_0Analyzer();
};



//beg_ReceiverParameter : AnnotationList UnannType 'this'
class R006_ReceiverParameter_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_ReceiverParameter_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ReceiverParameter_1Analyzer();
};



//beg_ReceiverParameter : UnannType Identifier 'SPOT' 'this'
class R006_ReceiverParameter_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_ReceiverParameter_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ReceiverParameter_2Analyzer();
};



//beg_ReceiverParameter : AnnotationList UnannType Identifier 'SPOT' 'this'
class R006_ReceiverParameter_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_ReceiverParameter_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_ReceiverParameter_3Analyzer();
};



//beg_VariableDeclaratorId : Identifier Dims
class R006_VariableDeclaratorId_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableDeclaratorId_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableDeclaratorId_0Analyzer();
};



//beg_VariableDeclaratorId : Identifier
class R006_VariableDeclaratorId_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_VariableDeclaratorId_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_VariableDeclaratorId_1Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R006_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Identifier_0Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R006_Dims_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_Dims_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Dims_0Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R006_Dims_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_Dims_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Dims_1Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R006_Dims_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_Dims_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Dims_2Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R006_Dims_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_Dims_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Dims_3Analyzer();
};



//beg_AnnotationList : Annotation AnnotationList
class R006_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_AnnotationList_0Analyzer();
};



//beg_AnnotationList : Annotation
class R006_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_AnnotationList_1Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
class R006_Annotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_Annotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Annotation_0Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier
class R006_Annotation_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_Annotation_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_Annotation_1Analyzer();
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R006_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_DetailIdentifier_0Analyzer();
};



//beg_DetailIdentifier : Identifier
class R006_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_DetailIdentifier_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R006_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R006_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : 0
class R006_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R006_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R006_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R006_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R006_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R006_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R006_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R006_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R006_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R006_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R006_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_9Analyzer();
};



//beg_NonPARENTHESES : 'EQUAL'
class R006_NonPARENTHESES_10Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonPARENTHESES_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonPARENTHESES_10Analyzer();
};



//beg_StatementEle : Identifier
class R006_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R006_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R006_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R006_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R006_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R006_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R006_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R006_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R006_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R006_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R006_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R006_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R006_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_12Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R006_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_13Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R006_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_14Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R006_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_15Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R006_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R006_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R006_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R006_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_19Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R006_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_20Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R006_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_21Analyzer();
};



//beg_StatementEle : 'OR'
class R006_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R006_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_23Analyzer();
};



//beg_StatementEle : 'PLUS'
class R006_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R006_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R006_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R006_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R006_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_28Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R006_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_29Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R006_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R006_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R006_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R006_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R006_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_34Analyzer();
};



//beg_StatementEle : 'SLASH'
class R006_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SPOT'
class R006_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_36Analyzer();
};



//beg_StatementEle : 'STAR'
class R006_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_37Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R006_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R006_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R006_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_40Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R006_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_41Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R006_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_42Analyzer();
};



//beg_StatementEle : 'TILDE'
class R006_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R006_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R006_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R006_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R006_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_47Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R006_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_48Analyzer();
};



//beg_StatementEle : 'abstract'
class R006_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_49Analyzer();
};



//beg_StatementEle : UnannPrimitiveType
class R006_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_50Analyzer();
};



//beg_StatementEle : 'class'
class R006_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_51Analyzer();
};



//beg_StatementEle : 'default'
class R006_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_52Analyzer();
};



//beg_StatementEle : 'enum'
class R006_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_53Analyzer();
};



//beg_StatementEle : 'extends'
class R006_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_54Analyzer();
};



//beg_StatementEle : 'final'
class R006_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_55Analyzer();
};



//beg_StatementEle : 'implements'
class R006_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_56Analyzer();
};



//beg_StatementEle : 'instanceof'
class R006_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_57Analyzer();
};



//beg_StatementEle : 'interface'
class R006_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_58Analyzer();
};



//beg_StatementEle : 'native'
class R006_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_59Analyzer();
};



//beg_StatementEle : 'new'
class R006_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_60Analyzer();
};



//beg_StatementEle : 'null'
class R006_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_61Analyzer();
};



//beg_StatementEle : 'private'
class R006_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_62Analyzer();
};



//beg_StatementEle : 'protected'
class R006_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_63Analyzer();
};



//beg_StatementEle : 'public'
class R006_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_64Analyzer();
};



//beg_StatementEle : 'static'
class R006_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_65Analyzer();
};



//beg_StatementEle : 'super'
class R006_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_66Analyzer();
};



//beg_StatementEle : 'synchronized'
class R006_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_67Analyzer();
};



//beg_StatementEle : 'this'
class R006_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_68Analyzer();
};



//beg_StatementEle : 'throws'
class R006_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_69Analyzer();
};



//beg_StatementEle : 'transient'
class R006_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_70Analyzer();
};



//beg_StatementEle : 'void'
class R006_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_71Analyzer();
};



//beg_StatementEle : 'volatile'
class R006_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R006_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_StatementEle_72Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
class R006_TypeArguments_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_TypeArguments_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_TypeArguments_0Analyzer();
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
class R006_TypeArgumentList_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_TypeArgumentList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_TypeArgumentList_0Analyzer();
};



//beg_TypeArgumentList : 0
class R006_TypeArgumentList_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_TypeArgumentList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_TypeArgumentList_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'QUESTION'
class R006_NonANGLE_BRACKET_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_0Analyzer();
};



//beg_NonANGLE_BRACKET : 'extends'
class R006_NonANGLE_BRACKET_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'super'
class R006_NonANGLE_BRACKET_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_2Analyzer();
};



//beg_NonANGLE_BRACKET : 'COMMA'
class R006_NonANGLE_BRACKET_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_3Analyzer();
};



//beg_NonANGLE_BRACKET : Identifier
class R006_NonANGLE_BRACKET_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_4Analyzer();
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
class R006_NonANGLE_BRACKET_5Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_5Analyzer();
};



//beg_NonANGLE_BRACKET : 'SPOT'
class R006_NonANGLE_BRACKET_6Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_6Analyzer();
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
class R006_NonANGLE_BRACKET_7Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_7Analyzer();
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
class R006_NonANGLE_BRACKET_8Analyzer :virtual public Non_Terminate_genertor {
public: R006_NonANGLE_BRACKET_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_NonANGLE_BRACKET_8Analyzer();
};



//beg_UnannType : UnannArrayType
class R006_UnannType_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannType_0Analyzer();
};



//beg_UnannType : UnannPrimitiveType
class R006_UnannType_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannType_1Analyzer();
};



//beg_UnannType : UnannClassOrInterfaceType
class R006_UnannType_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannType_2Analyzer();
};



//beg_UnannPrimitiveType : 'boolean'
class R006_UnannPrimitiveType_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_0Analyzer();
};



//beg_UnannPrimitiveType : 'byte'
class R006_UnannPrimitiveType_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_1Analyzer();
};



//beg_UnannPrimitiveType : 'short'
class R006_UnannPrimitiveType_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_2Analyzer();
};



//beg_UnannPrimitiveType : 'int'
class R006_UnannPrimitiveType_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_3Analyzer();
};



//beg_UnannPrimitiveType : 'long'
class R006_UnannPrimitiveType_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_4Analyzer();
};



//beg_UnannPrimitiveType : 'char'
class R006_UnannPrimitiveType_5Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_5Analyzer();
};



//beg_UnannPrimitiveType : 'float'
class R006_UnannPrimitiveType_6Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_6Analyzer();
};



//beg_UnannPrimitiveType : 'double'
class R006_UnannPrimitiveType_7Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannPrimitiveType_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannPrimitiveType_7Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier
class R006_UnannClassOrInterfaceType_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_0Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments
class R006_UnannClassOrInterfaceType_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_1Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier 'SPOT' UnannClassOrInterfaceType
class R006_UnannClassOrInterfaceType_2Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_2Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' UnannClassOrInterfaceType
class R006_UnannClassOrInterfaceType_3Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_3Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier 'SPOT' AnnotationList UnannClassOrInterfaceType
class R006_UnannClassOrInterfaceType_4Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_4Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' AnnotationList UnannClassOrInterfaceType
class R006_UnannClassOrInterfaceType_5Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannClassOrInterfaceType_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannClassOrInterfaceType_5Analyzer();
};



//beg_UnannArrayType : UnannPrimitiveType Dims
class R006_UnannArrayType_0Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannArrayType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannArrayType_0Analyzer();
};



//beg_UnannArrayType : UnannClassOrInterfaceType Dims
class R006_UnannArrayType_1Analyzer :virtual public Non_Terminate_genertor {
public: R006_UnannArrayType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R006_UnannArrayType_1Analyzer();
};
