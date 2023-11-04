#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R003_DefaultAnalyzer :virtual public SDT_genertor {
public: R003_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_DefaultAnalyzer();
};



//beg_ele_begin : CompilationUnit
class R003_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ele_begin_0Analyzer();
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
class R003_CompilationUnit_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_0Analyzer();
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList
class R003_CompilationUnit_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_1Analyzer();
};



//beg_CompilationUnit : PackageDeclaration TypeDeclarationList
class R003_CompilationUnit_2Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_2Analyzer();
};



//beg_CompilationUnit : ImportDeclarationList TypeDeclarationList
class R003_CompilationUnit_3Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_3Analyzer();
};



//beg_CompilationUnit : PackageDeclaration
class R003_CompilationUnit_4Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_4Analyzer();
};



//beg_CompilationUnit : ImportDeclarationList
class R003_CompilationUnit_5Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_5Analyzer();
};



//beg_CompilationUnit : TypeDeclarationList
class R003_CompilationUnit_6Analyzer :virtual public Non_Terminate_genertor {
public: R003_CompilationUnit_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_CompilationUnit_6Analyzer();
};



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
class R003_PackageDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_PackageDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_PackageDeclaration_0Analyzer();
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R003_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_DetailIdentifier_0Analyzer();
};



//beg_DetailIdentifier : Identifier
class R003_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_DetailIdentifier_1Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R003_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Identifier_0Analyzer();
};



//beg_ImportDeclarationList : ImportDeclaration ImportDeclarationList
class R003_ImportDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclarationList_0Analyzer();
};



//beg_ImportDeclarationList : ImportDeclaration
class R003_ImportDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclarationList_1Analyzer();
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R003_ImportDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclaration_0Analyzer();
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
class R003_ImportDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclaration_1Analyzer();
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R003_ImportDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclaration_2Analyzer();
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'semicolon'
class R003_ImportDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R003_ImportDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ImportDeclaration_3Analyzer();
};



//beg_TypeDeclarationList : TypeDeclaration TypeDeclarationList
class R003_TypeDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_TypeDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_TypeDeclarationList_0Analyzer();
};



//beg_TypeDeclarationList : TypeDeclaration
class R003_TypeDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_TypeDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_TypeDeclarationList_1Analyzer();
};



//beg_TypeDeclaration : ClassDeclaration
class R003_TypeDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_TypeDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_TypeDeclaration_0Analyzer();
};



//beg_TypeDeclaration : 'semicolon'
class R003_TypeDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_TypeDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_TypeDeclaration_1Analyzer();
};



//beg_ClassDeclaration : NormalClassDeclaration
class R003_ClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassDeclaration_0Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
class R003_NormalClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_NormalClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NormalClassDeclaration_0Analyzer();
};



//beg_ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
class R003_ClassBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassBody_0Analyzer();
};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
class R003_ClassBodyDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassBodyDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassBodyDeclarationList_0Analyzer();
};



//beg_ClassBodyDeclarationList : 0
class R003_ClassBodyDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassBodyDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassBodyDeclarationList_1Analyzer();
};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
class R003_ClassBodyDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassBodyDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassBodyDeclaration_0Analyzer();
};



//beg_ClassMemberDeclaration : MethodDeclaration
class R003_ClassMemberDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ClassMemberDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ClassMemberDeclaration_0Analyzer();
};



//beg_MethodDeclaration : ModifierList MethodHeader MethodBody
class R003_MethodDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodDeclaration_0Analyzer();
};



//beg_MethodDeclaration : MethodHeader MethodBody
class R003_MethodDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodDeclaration_1Analyzer();
};



//beg_MethodHeader : 'void' MethodDeclarator
class R003_MethodHeader_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodHeader_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodHeader_0Analyzer();
};



//beg_MethodDeclarator : Identifier AnnotationContent
class R003_MethodDeclarator_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodDeclarator_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodDeclarator_0Analyzer();
};



//beg_ModifierList : Modifier ModifierList
class R003_ModifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_ModifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ModifierList_0Analyzer();
};



//beg_ModifierList : Modifier
class R003_ModifierList_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_ModifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_ModifierList_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R003_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R003_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES
class R003_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R003_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R003_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R003_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R003_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R003_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R003_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R003_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R003_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R003_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R003_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R003_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_NonPARENTHESES_9Analyzer();
};



//beg_StatementEle : 'IDENTIFIER'
class R003_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R003_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R003_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R003_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R003_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R003_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R003_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R003_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R003_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R003_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R003_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R003_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R003_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_12Analyzer();
};



//beg_StatementEle : 'EQUAL'
class R003_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_13Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R003_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_14Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R003_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_15Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R003_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R003_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R003_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R003_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_19Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R003_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_20Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R003_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_21Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R003_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR'
class R003_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_23Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R003_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS'
class R003_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R003_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R003_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R003_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_28Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R003_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_29Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R003_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R003_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R003_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R003_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R003_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_34Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R003_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SLASH'
class R003_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_36Analyzer();
};



//beg_StatementEle : 'SPOT'
class R003_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_37Analyzer();
};



//beg_StatementEle : 'STAR'
class R003_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R003_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R003_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_40Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R003_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_41Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R003_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_42Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R003_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TILDE'
class R003_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R003_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R003_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R003_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_47Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R003_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_48Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R003_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_49Analyzer();
};



//beg_StatementEle : 'abstract'
class R003_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_50Analyzer();
};



//beg_StatementEle : 'boolean'
class R003_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_51Analyzer();
};



//beg_StatementEle : 'byte'
class R003_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_52Analyzer();
};



//beg_StatementEle : 'char'
class R003_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_53Analyzer();
};



//beg_StatementEle : 'class'
class R003_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_54Analyzer();
};



//beg_StatementEle : 'default'
class R003_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_55Analyzer();
};



//beg_StatementEle : 'double'
class R003_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_56Analyzer();
};



//beg_StatementEle : 'enum'
class R003_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_57Analyzer();
};



//beg_StatementEle : 'extends'
class R003_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_58Analyzer();
};



//beg_StatementEle : 'final'
class R003_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_59Analyzer();
};



//beg_StatementEle : 'float'
class R003_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_60Analyzer();
};



//beg_StatementEle : 'implements'
class R003_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_61Analyzer();
};



//beg_StatementEle : 'instanceof'
class R003_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_62Analyzer();
};



//beg_StatementEle : 'int'
class R003_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_63Analyzer();
};



//beg_StatementEle : 'interface'
class R003_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_64Analyzer();
};



//beg_StatementEle : 'long'
class R003_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_65Analyzer();
};



//beg_StatementEle : 'native'
class R003_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_66Analyzer();
};



//beg_StatementEle : 'new'
class R003_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_67Analyzer();
};



//beg_StatementEle : 'null'
class R003_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_68Analyzer();
};



//beg_StatementEle : 'private'
class R003_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_69Analyzer();
};



//beg_StatementEle : 'protected'
class R003_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_70Analyzer();
};



//beg_StatementEle : 'public'
class R003_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_71Analyzer();
};



//beg_StatementEle : 'short'
class R003_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_72Analyzer();
};



//beg_StatementEle : 'static'
class R003_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_73Analyzer();
};



//beg_StatementEle : 'super'
class R003_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_74Analyzer();
};



//beg_StatementEle : 'synchronized'
class R003_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_75Analyzer();
};



//beg_StatementEle : 'this'
class R003_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_76Analyzer();
};



//beg_StatementEle : 'throws'
class R003_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_77Analyzer();
};



//beg_StatementEle : 'transient'
class R003_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_78Analyzer();
};



//beg_StatementEle : 'void'
class R003_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_79Analyzer();
};



//beg_StatementEle : 'volatile'
class R003_StatementEle_80Analyzer :virtual public Non_Terminate_genertor {
public: R003_StatementEle_80Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_StatementEle_80Analyzer();
};



//beg_Modifier : 'public'
class R003_Modifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_0Analyzer();
};



//beg_Modifier : 'protected'
class R003_Modifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_1Analyzer();
};



//beg_Modifier : 'private'
class R003_Modifier_2Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_2Analyzer();
};



//beg_Modifier : 'abstract'
class R003_Modifier_3Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_3Analyzer();
};



//beg_Modifier : 'static'
class R003_Modifier_4Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_4Analyzer();
};



//beg_Modifier : 'final'
class R003_Modifier_5Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_5Analyzer();
};



//beg_Modifier : 'strictfp'
class R003_Modifier_6Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_6Analyzer();
};



//beg_Modifier : 'default'
class R003_Modifier_7Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_7Analyzer();
};



//beg_Modifier : 'volatile'
class R003_Modifier_8Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_8Analyzer();
};



//beg_Modifier : 'synchronized'
class R003_Modifier_9Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_9Analyzer();
};



//beg_Modifier : 'transient'
class R003_Modifier_10Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_10Analyzer();
};



//beg_Modifier : 'native'
class R003_Modifier_11Analyzer :virtual public Non_Terminate_genertor {
public: R003_Modifier_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Modifier_11Analyzer();
};



//beg_MethodBody : Block
class R003_MethodBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodBody_0Analyzer();
};



//beg_MethodBody : 'semicolon'
class R003_MethodBody_1Analyzer :virtual public Non_Terminate_genertor {
public: R003_MethodBody_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_MethodBody_1Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
class R003_Block_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_Block_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_Block_0Analyzer();
};



//beg_BlockStatements : 0
class R003_BlockStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R003_BlockStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R003_BlockStatements_0Analyzer();
};

