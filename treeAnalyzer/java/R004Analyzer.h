#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R004_DefaultAnalyzer :virtual public SDT_genertor {
public: R004_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_DefaultAnalyzer();
};



//beg_ele_begin : CompilationUnit
class R004_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ele_begin_0Analyzer();
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
class R004_CompilationUnit_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_0Analyzer();
};



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList
class R004_CompilationUnit_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_1Analyzer();
};



//beg_CompilationUnit : PackageDeclaration TypeDeclarationList
class R004_CompilationUnit_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_2Analyzer();
};



//beg_CompilationUnit : ImportDeclarationList TypeDeclarationList
class R004_CompilationUnit_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_3Analyzer();
};



//beg_CompilationUnit : PackageDeclaration
class R004_CompilationUnit_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_4Analyzer();
};



//beg_CompilationUnit : ImportDeclarationList
class R004_CompilationUnit_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_5Analyzer();
};



//beg_CompilationUnit : TypeDeclarationList
class R004_CompilationUnit_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_CompilationUnit_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_CompilationUnit_6Analyzer();
};



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
class R004_PackageDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_PackageDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_PackageDeclaration_0Analyzer();
};



//beg_PackageDeclaration : ModifierList 'package' DetailIdentifier 'semicolon'
class R004_PackageDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_PackageDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_PackageDeclaration_1Analyzer();
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R004_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_DetailIdentifier_0Analyzer();
};



//beg_DetailIdentifier : Identifier
class R004_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_DetailIdentifier_1Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R004_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Identifier_0Analyzer();
};



//beg_ImportDeclarationList : ImportDeclaration ImportDeclarationList
class R004_ImportDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclarationList_0Analyzer();
};



//beg_ImportDeclarationList : ImportDeclaration
class R004_ImportDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclarationList_1Analyzer();
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R004_ImportDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclaration_0Analyzer();
};



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
class R004_ImportDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclaration_1Analyzer();
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R004_ImportDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclaration_2Analyzer();
};



//beg_ImportDeclaration : 'import' DetailIdentifier 'semicolon'
class R004_ImportDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_ImportDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ImportDeclaration_3Analyzer();
};



//beg_TypeDeclarationList : TypeDeclaration TypeDeclarationList
class R004_TypeDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeDeclarationList_0Analyzer();
};



//beg_TypeDeclarationList : TypeDeclaration
class R004_TypeDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeDeclarationList_1Analyzer();
};



//beg_TypeDeclaration : ClassDeclaration
class R004_TypeDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeDeclaration_0Analyzer();
};



//beg_TypeDeclaration : 'semicolon'
class R004_TypeDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeDeclaration_1Analyzer();
};



//beg_ClassDeclaration : NormalClassDeclaration
class R004_ClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassDeclaration_0Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
class R004_NormalClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_0Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
class R004_NormalClassDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_1Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
class R004_NormalClassDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_2Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
class R004_NormalClassDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_3Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass ClassBody
class R004_NormalClassDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_4Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass ClassBody
class R004_NormalClassDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_5Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass ClassBody
class R004_NormalClassDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_6Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments ClassBody
class R004_NormalClassDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_7Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces ClassBody
class R004_NormalClassDeclaration_8Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_8Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces ClassBody
class R004_NormalClassDeclaration_9Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_9Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces ClassBody
class R004_NormalClassDeclaration_10Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_10Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces ClassBody
class R004_NormalClassDeclaration_11Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_11Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces ClassBody
class R004_NormalClassDeclaration_12Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_12Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces ClassBody
class R004_NormalClassDeclaration_13Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_13Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces ClassBody
class R004_NormalClassDeclaration_14Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_14Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments Superinterfaces ClassBody
class R004_NormalClassDeclaration_15Analyzer :virtual public Non_Terminate_genertor {
public: R004_NormalClassDeclaration_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NormalClassDeclaration_15Analyzer();
};



//beg_ClassBody : 'LEFT_BRACE'
class R004_ClassBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassBody_0Analyzer();
};



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
class R004_ClassBodyDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassBodyDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassBodyDeclarationList_0Analyzer();
};



//beg_ClassBodyDeclarationList : 0
class R004_ClassBodyDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassBodyDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassBodyDeclarationList_1Analyzer();
};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
class R004_ClassBodyDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassBodyDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassBodyDeclaration_0Analyzer();
};



//beg_ClassMemberDeclaration : MethodDeclaration
class R004_ClassMemberDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassMemberDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassMemberDeclaration_0Analyzer();
};



//beg_MethodDeclaration : ModifierList MethodHeader MethodBody
class R004_MethodDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodDeclaration_0Analyzer();
};



//beg_MethodDeclaration : MethodHeader MethodBody
class R004_MethodDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodDeclaration_1Analyzer();
};



//beg_MethodHeader : 'void' MethodDeclarator
class R004_MethodHeader_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodHeader_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodHeader_0Analyzer();
};



//beg_MethodDeclarator : Identifier AnnotationContent
class R004_MethodDeclarator_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodDeclarator_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodDeclarator_0Analyzer();
};



//beg_ModifierList : Modifier ModifierList
class R004_ModifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ModifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ModifierList_0Analyzer();
};



//beg_ModifierList : Modifier
class R004_ModifierList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ModifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ModifierList_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R004_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R004_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES
class R004_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R004_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R004_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R004_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R004_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R004_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R004_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R004_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R004_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R004_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R004_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonPARENTHESES_9Analyzer();
};



//beg_StatementEle : 'IDENTIFIER'
class R004_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R004_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R004_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R004_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R004_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R004_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R004_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R004_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R004_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R004_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R004_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R004_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R004_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_12Analyzer();
};



//beg_StatementEle : 'EQUAL'
class R004_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_13Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R004_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_14Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R004_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_15Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R004_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R004_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R004_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R004_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_19Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R004_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_20Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R004_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_21Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R004_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR'
class R004_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_23Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R004_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS'
class R004_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R004_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R004_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R004_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_28Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R004_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_29Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R004_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R004_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R004_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R004_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R004_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_34Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R004_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SLASH'
class R004_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_36Analyzer();
};



//beg_StatementEle : 'SPOT'
class R004_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_37Analyzer();
};



//beg_StatementEle : 'STAR'
class R004_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R004_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R004_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_40Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R004_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_41Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R004_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_42Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R004_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TILDE'
class R004_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R004_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R004_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R004_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_47Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R004_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_48Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R004_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_49Analyzer();
};



//beg_StatementEle : 'abstract'
class R004_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_50Analyzer();
};



//beg_StatementEle : 'boolean'
class R004_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_51Analyzer();
};



//beg_StatementEle : 'byte'
class R004_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_52Analyzer();
};



//beg_StatementEle : 'char'
class R004_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_53Analyzer();
};



//beg_StatementEle : 'class'
class R004_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_54Analyzer();
};



//beg_StatementEle : 'default'
class R004_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_55Analyzer();
};



//beg_StatementEle : 'double'
class R004_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_56Analyzer();
};



//beg_StatementEle : 'enum'
class R004_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_57Analyzer();
};



//beg_StatementEle : 'extends'
class R004_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_58Analyzer();
};



//beg_StatementEle : 'final'
class R004_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_59Analyzer();
};



//beg_StatementEle : 'float'
class R004_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_60Analyzer();
};



//beg_StatementEle : 'implements'
class R004_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_61Analyzer();
};



//beg_StatementEle : 'instanceof'
class R004_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_62Analyzer();
};



//beg_StatementEle : 'int'
class R004_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_63Analyzer();
};



//beg_StatementEle : 'interface'
class R004_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_64Analyzer();
};



//beg_StatementEle : 'long'
class R004_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_65Analyzer();
};



//beg_StatementEle : 'native'
class R004_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_66Analyzer();
};



//beg_StatementEle : 'new'
class R004_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_67Analyzer();
};



//beg_StatementEle : 'null'
class R004_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_68Analyzer();
};



//beg_StatementEle : 'private'
class R004_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_69Analyzer();
};



//beg_StatementEle : 'protected'
class R004_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_70Analyzer();
};



//beg_StatementEle : 'public'
class R004_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_71Analyzer();
};



//beg_StatementEle : 'short'
class R004_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_72Analyzer();
};



//beg_StatementEle : 'static'
class R004_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_73Analyzer();
};



//beg_StatementEle : 'super'
class R004_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_74Analyzer();
};



//beg_StatementEle : 'synchronized'
class R004_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_75Analyzer();
};



//beg_StatementEle : 'this'
class R004_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_76Analyzer();
};



//beg_StatementEle : 'throws'
class R004_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_77Analyzer();
};



//beg_StatementEle : 'transient'
class R004_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_78Analyzer();
};



//beg_StatementEle : 'void'
class R004_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_79Analyzer();
};



//beg_StatementEle : 'volatile'
class R004_StatementEle_80Analyzer :virtual public Non_Terminate_genertor {
public: R004_StatementEle_80Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_StatementEle_80Analyzer();
};



//beg_Modifier : 'public'
class R004_Modifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_0Analyzer();
};



//beg_Modifier : 'protected'
class R004_Modifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_1Analyzer();
};



//beg_Modifier : 'private'
class R004_Modifier_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_2Analyzer();
};



//beg_Modifier : 'abstract'
class R004_Modifier_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_3Analyzer();
};



//beg_Modifier : 'static'
class R004_Modifier_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_4Analyzer();
};



//beg_Modifier : 'final'
class R004_Modifier_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_5Analyzer();
};



//beg_Modifier : 'strictfp'
class R004_Modifier_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_6Analyzer();
};



//beg_Modifier : 'default'
class R004_Modifier_7Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_7Analyzer();
};



//beg_Modifier : 'volatile'
class R004_Modifier_8Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_8Analyzer();
};



//beg_Modifier : 'synchronized'
class R004_Modifier_9Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_9Analyzer();
};



//beg_Modifier : 'transient'
class R004_Modifier_10Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_10Analyzer();
};



//beg_Modifier : 'native'
class R004_Modifier_11Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_11Analyzer();
};



//beg_Modifier : Annotation
class R004_Modifier_12Analyzer :virtual public Non_Terminate_genertor {
public: R004_Modifier_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Modifier_12Analyzer();
};



//beg_MethodBody : Block
class R004_MethodBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodBody_0Analyzer();
};



//beg_MethodBody : 'semicolon'
class R004_MethodBody_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_MethodBody_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_MethodBody_1Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
class R004_Block_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Block_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Block_0Analyzer();
};



//beg_BlockStatements : 0
class R004_BlockStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_BlockStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_BlockStatements_0Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
class R004_Annotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Annotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Annotation_0Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
class R004_TypeArguments_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeArguments_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeArguments_0Analyzer();
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
class R004_TypeArgumentList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeArgumentList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeArgumentList_0Analyzer();
};



//beg_TypeArgumentList : 0
class R004_TypeArgumentList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_TypeArgumentList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_TypeArgumentList_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'QUESTION'
class R004_NonANGLE_BRACKET_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_0Analyzer();
};



//beg_NonANGLE_BRACKET : 'extends'
class R004_NonANGLE_BRACKET_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'super'
class R004_NonANGLE_BRACKET_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_2Analyzer();
};



//beg_NonANGLE_BRACKET : 'COMMA'
class R004_NonANGLE_BRACKET_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_3Analyzer();
};



//beg_NonANGLE_BRACKET : Identifier
class R004_NonANGLE_BRACKET_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_4Analyzer();
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
class R004_NonANGLE_BRACKET_5Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_5Analyzer();
};



//beg_NonANGLE_BRACKET : 'SPOT'
class R004_NonANGLE_BRACKET_6Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_6Analyzer();
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
class R004_NonANGLE_BRACKET_7Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_7Analyzer();
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
class R004_NonANGLE_BRACKET_8Analyzer :virtual public Non_Terminate_genertor {
public: R004_NonANGLE_BRACKET_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NonANGLE_BRACKET_8Analyzer();
};



//beg_UnannPrimitiveType : NumericType
class R004_UnannPrimitiveType_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_UnannPrimitiveType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_UnannPrimitiveType_0Analyzer();
};



//beg_UnannPrimitiveType : 'boolean'
class R004_UnannPrimitiveType_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_UnannPrimitiveType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_UnannPrimitiveType_1Analyzer();
};



//beg_NumericType : IntegralType
class R004_NumericType_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_NumericType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NumericType_0Analyzer();
};



//beg_NumericType : FloatingPointType
class R004_NumericType_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_NumericType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_NumericType_1Analyzer();
};



//beg_IntegralType : 'byte'
class R004_IntegralType_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_IntegralType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_IntegralType_0Analyzer();
};



//beg_IntegralType : 'short'
class R004_IntegralType_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_IntegralType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_IntegralType_1Analyzer();
};



//beg_IntegralType : 'int'
class R004_IntegralType_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_IntegralType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_IntegralType_2Analyzer();
};



//beg_IntegralType : 'long'
class R004_IntegralType_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_IntegralType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_IntegralType_3Analyzer();
};



//beg_IntegralType : 'char'
class R004_IntegralType_4Analyzer :virtual public Non_Terminate_genertor {
public: R004_IntegralType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_IntegralType_4Analyzer();
};



//beg_FloatingPointType : 'float'
class R004_FloatingPointType_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_FloatingPointType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_FloatingPointType_0Analyzer();
};



//beg_FloatingPointType : 'double'
class R004_FloatingPointType_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_FloatingPointType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_FloatingPointType_1Analyzer();
};



//beg_Superclass : 'extends' ClassType
class R004_Superclass_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Superclass_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Superclass_0Analyzer();
};



//beg_ClassTypeEle : Identifier
class R004_ClassTypeEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassTypeEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassTypeEle_0Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier
class R004_ClassTypeEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassTypeEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassTypeEle_1Analyzer();
};



//beg_ClassTypeEle : Identifier TypeArguments
class R004_ClassTypeEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassTypeEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassTypeEle_2Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
class R004_ClassTypeEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassTypeEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassTypeEle_3Analyzer();
};



//beg_ClassType : ClassTypeEle
class R004_ClassType_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassType_0Analyzer();
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
class R004_ClassType_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_ClassType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_ClassType_1Analyzer();
};



//beg_AnnotationList : Annotation AnnotationList
class R004_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_AnnotationList_0Analyzer();
};



//beg_AnnotationList : Annotation
class R004_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_AnnotationList_1Analyzer();
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
class R004_Superinterfaces_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_Superinterfaces_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_Superinterfaces_0Analyzer();
};



//beg_InterfaceTypeList : ClassType
class R004_InterfaceTypeList_0Analyzer :virtual public Non_Terminate_genertor {
public: R004_InterfaceTypeList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_InterfaceTypeList_0Analyzer();
};



//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
class R004_InterfaceTypeList_1Analyzer :virtual public Non_Terminate_genertor {
public: R004_InterfaceTypeList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R004_InterfaceTypeList_1Analyzer();
};