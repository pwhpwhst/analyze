#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R007_DefaultAnalyzer :virtual public SDT_genertor {
public: R007_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_DefaultAnalyzer();
};



//beg_ele_begin : EnumFirstStatement
class R007_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_ele_begin_0Analyzer();
};



//beg_EnumFirstStatement : EnumConstant 'COMMA' EnumFirstStatement
class R007_EnumFirstStatement_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumFirstStatement_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumFirstStatement_0Analyzer();
};



//beg_EnumFirstStatement : EnumConstant
class R007_EnumFirstStatement_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumFirstStatement_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumFirstStatement_1Analyzer();
};



//beg_EnumFirstStatement : 0
class R007_EnumFirstStatement_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumFirstStatement_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumFirstStatement_2Analyzer();
};



//beg_EnumConstant : Identifier
class R007_EnumConstant_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_0Analyzer();
};



//beg_EnumConstant : AnnotationList Identifier
class R007_EnumConstant_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_1Analyzer();
};



//beg_EnumConstant : Identifier AnnotationContent
class R007_EnumConstant_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_2Analyzer();
};



//beg_EnumConstant : AnnotationList Identifier AnnotationContent
class R007_EnumConstant_3Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_3Analyzer();
};



//beg_EnumConstant : Identifier Block
class R007_EnumConstant_4Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_4Analyzer();
};



//beg_EnumConstant : AnnotationList Identifier Block
class R007_EnumConstant_5Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_5Analyzer();
};



//beg_EnumConstant : Identifier AnnotationContent Block
class R007_EnumConstant_6Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_6Analyzer();
};



//beg_EnumConstant : AnnotationList Identifier AnnotationContent Block
class R007_EnumConstant_7Analyzer :virtual public Non_Terminate_genertor {
public: R007_EnumConstant_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_EnumConstant_7Analyzer();
};



//beg_AnnotationList : Annotation AnnotationList
class R007_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_AnnotationList_0Analyzer();
};



//beg_AnnotationList : Annotation
class R007_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_AnnotationList_1Analyzer();
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R007_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_DetailIdentifier_0Analyzer();
};



//beg_DetailIdentifier : Identifier
class R007_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_DetailIdentifier_1Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
class R007_Annotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_Annotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_Annotation_0Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier
class R007_Annotation_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_Annotation_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_Annotation_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R007_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R007_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : 0
class R007_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R007_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R007_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R007_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R007_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R007_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R007_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R007_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R007_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R007_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R007_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_9Analyzer();
};



//beg_NonPARENTHESES : 'EQUAL'
class R007_NonPARENTHESES_10Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_10Analyzer();
};



//beg_NonPARENTHESES : AnnotationContent
class R007_NonPARENTHESES_11Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonPARENTHESES_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonPARENTHESES_11Analyzer();
};



//beg_StatementEle : Identifier
class R007_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R007_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R007_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R007_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R007_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R007_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R007_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R007_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R007_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R007_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R007_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R007_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R007_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_12Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R007_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_13Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R007_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_14Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R007_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_15Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R007_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R007_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R007_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R007_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_19Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R007_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_20Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R007_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_21Analyzer();
};



//beg_StatementEle : 'OR'
class R007_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R007_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_23Analyzer();
};



//beg_StatementEle : 'PLUS'
class R007_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R007_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R007_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R007_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R007_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_28Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R007_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_29Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R007_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R007_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R007_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R007_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R007_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_34Analyzer();
};



//beg_StatementEle : 'SLASH'
class R007_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SPOT'
class R007_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_36Analyzer();
};



//beg_StatementEle : 'STAR'
class R007_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_37Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R007_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R007_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R007_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_40Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R007_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_41Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R007_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_42Analyzer();
};



//beg_StatementEle : 'TILDE'
class R007_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R007_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R007_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R007_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R007_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_47Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R007_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_48Analyzer();
};



//beg_StatementEle : 'abstract'
class R007_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_49Analyzer();
};



//beg_StatementEle : 'boolean'
class R007_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_50Analyzer();
};



//beg_StatementEle : 'byte'
class R007_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_51Analyzer();
};



//beg_StatementEle : 'char'
class R007_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_52Analyzer();
};



//beg_StatementEle : 'class'
class R007_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_53Analyzer();
};



//beg_StatementEle : 'default'
class R007_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_54Analyzer();
};



//beg_StatementEle : 'double'
class R007_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_55Analyzer();
};



//beg_StatementEle : 'enum'
class R007_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_56Analyzer();
};



//beg_StatementEle : 'extends'
class R007_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_57Analyzer();
};



//beg_StatementEle : 'final'
class R007_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_58Analyzer();
};



//beg_StatementEle : 'float'
class R007_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_59Analyzer();
};



//beg_StatementEle : 'implements'
class R007_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_60Analyzer();
};



//beg_StatementEle : 'instanceof'
class R007_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_61Analyzer();
};



//beg_StatementEle : 'int'
class R007_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_62Analyzer();
};



//beg_StatementEle : 'interface'
class R007_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_63Analyzer();
};



//beg_StatementEle : 'long'
class R007_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_64Analyzer();
};



//beg_StatementEle : 'native'
class R007_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_65Analyzer();
};



//beg_StatementEle : 'new'
class R007_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_66Analyzer();
};



//beg_StatementEle : 'null'
class R007_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_67Analyzer();
};



//beg_StatementEle : 'private'
class R007_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_68Analyzer();
};



//beg_StatementEle : 'protected'
class R007_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_69Analyzer();
};



//beg_StatementEle : 'public'
class R007_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_70Analyzer();
};



//beg_StatementEle : 'short'
class R007_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_71Analyzer();
};



//beg_StatementEle : 'static'
class R007_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_72Analyzer();
};



//beg_StatementEle : 'super'
class R007_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_73Analyzer();
};



//beg_StatementEle : 'synchronized'
class R007_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_74Analyzer();
};



//beg_StatementEle : 'this'
class R007_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_75Analyzer();
};



//beg_StatementEle : 'throws'
class R007_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_76Analyzer();
};



//beg_StatementEle : 'transient'
class R007_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_77Analyzer();
};



//beg_StatementEle : 'void'
class R007_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_78Analyzer();
};



//beg_StatementEle : 'volatile'
class R007_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R007_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_StatementEle_79Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R007_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_Identifier_0Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
class R007_Block_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_Block_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_Block_0Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
class R007_Block_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_Block_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_Block_1Analyzer();
};



//beg_BlockStatements : Block BlockStatements
class R007_BlockStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_BlockStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_BlockStatements_0Analyzer();
};



//beg_BlockStatements : NonBrace BlockStatements
class R007_BlockStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_BlockStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_BlockStatements_1Analyzer();
};



//beg_BlockStatements : 0
class R007_BlockStatements_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_BlockStatements_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_BlockStatements_2Analyzer();
};



//beg_NonBrace : StatementEle
class R007_NonBrace_0Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_0Analyzer();
};



//beg_NonBrace : 'COMMA'
class R007_NonBrace_1Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_1Analyzer();
};



//beg_NonBrace : 'semicolon'
class R007_NonBrace_2Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_2Analyzer();
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
class R007_NonBrace_3Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_3Analyzer();
};



//beg_NonBrace : 'LEFT_BRACKET'
class R007_NonBrace_4Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_4Analyzer();
};



//beg_NonBrace : 'LEFT_PARENTHESES'
class R007_NonBrace_5Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_5Analyzer();
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
class R007_NonBrace_6Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_6Analyzer();
};



//beg_NonBrace : 'RIGHT_BRACKET'
class R007_NonBrace_7Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_7Analyzer();
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
class R007_NonBrace_8Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_8Analyzer();
};



//beg_NonBrace : 'EQUAL'
class R007_NonBrace_9Analyzer :virtual public Non_Terminate_genertor {
public: R007_NonBrace_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R007_NonBrace_9Analyzer();
};
