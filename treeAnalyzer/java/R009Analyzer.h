#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R009_DefaultAnalyzer :virtual public SDT_genertor {
public: R009_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DefaultAnalyzer();
};



//beg_ele_begin : AnnotationTypeMemberDeclaration
class R009_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ele_begin_0Analyzer();
};



//beg_AnnotationTypeMemberDeclaration : AnnotationTypeElementDeclaration
class R009_AnnotationTypeMemberDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeMemberDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeMemberDeclaration_0Analyzer();
};



//beg_AnnotationTypeMemberDeclaration : ConstantDeclaration
class R009_AnnotationTypeMemberDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeMemberDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeMemberDeclaration_1Analyzer();
};



//beg_AnnotationTypeMemberDeclaration : ConstantDeclarationFake
class R009_AnnotationTypeMemberDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeMemberDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeMemberDeclaration_2Analyzer();
};



//beg_AnnotationTypeMemberDeclaration : ClassDeclaration
class R009_AnnotationTypeMemberDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeMemberDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeMemberDeclaration_3Analyzer();
};



//beg_AnnotationTypeMemberDeclaration : InterfaceDeclaration
class R009_AnnotationTypeMemberDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeMemberDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeMemberDeclaration_4Analyzer();
};



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
class R009_InterfaceDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_InterfaceDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_InterfaceDeclaration_0Analyzer();
};



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
class R009_InterfaceDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_InterfaceDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_InterfaceDeclaration_1Analyzer();
};



//beg_ClassDeclaration : NormalClassDeclaration
class R009_ClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassDeclaration_0Analyzer();
};



//beg_ClassDeclaration : EnumDeclaration
class R009_ClassDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassDeclaration_1Analyzer();
};



//beg_EnumDeclaration : 'enum' Identifier Block
class R009_EnumDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_EnumDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_EnumDeclaration_0Analyzer();
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Block
class R009_EnumDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_EnumDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_EnumDeclaration_1Analyzer();
};



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces Block
class R009_EnumDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_EnumDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_EnumDeclaration_2Analyzer();
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces Block
class R009_EnumDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_EnumDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_EnumDeclaration_3Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Block
class R009_NormalClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_0Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Block
class R009_NormalClassDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_1Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Block
class R009_NormalClassDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_2Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Block
class R009_NormalClassDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_3Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Block
class R009_NormalClassDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_4Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Block
class R009_NormalClassDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_5Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Block
class R009_NormalClassDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_6Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments Block
class R009_NormalClassDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_7Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces Block
class R009_NormalClassDeclaration_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_8Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces Block
class R009_NormalClassDeclaration_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_9Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces Block
class R009_NormalClassDeclaration_10Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_10Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces Block
class R009_NormalClassDeclaration_11Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_11Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces Block
class R009_NormalClassDeclaration_12Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_12Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces Block
class R009_NormalClassDeclaration_13Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_13Analyzer();
};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces Block
class R009_NormalClassDeclaration_14Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_14Analyzer();
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments Superinterfaces Block
class R009_NormalClassDeclaration_15Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalClassDeclaration_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalClassDeclaration_15Analyzer();
};



//beg_Superclass : 'extends' ClassType
class R009_Superclass_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Superclass_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Superclass_0Analyzer();
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
class R009_Superinterfaces_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Superinterfaces_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Superinterfaces_0Analyzer();
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier Block
class R009_NormalInterfaceDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_0Analyzer();
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier Block
class R009_NormalInterfaceDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_1Analyzer();
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments Block
class R009_NormalInterfaceDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_2Analyzer();
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments Block
class R009_NormalInterfaceDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_3Analyzer();
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces Block
class R009_NormalInterfaceDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_4Analyzer();
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces Block
class R009_NormalInterfaceDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_5Analyzer();
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces Block
class R009_NormalInterfaceDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_6Analyzer();
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces Block
class R009_NormalInterfaceDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_NormalInterfaceDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NormalInterfaceDeclaration_7Analyzer();
};



//beg_AnnotationTypeDeclaration : 'AT' 'interface' Identifier Block
class R009_AnnotationTypeDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeDeclaration_0Analyzer();
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT' 'interface' Identifier Block
class R009_AnnotationTypeDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeDeclaration_1Analyzer();
};



//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier Block
class R009_AnnotationTypeDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeDeclaration_2Analyzer();
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier Block
class R009_AnnotationTypeDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeDeclaration_3Analyzer();
};



//beg_Identifier : 'IDENTIFIER'
class R009_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Identifier_0Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
class R009_Block_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Block_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Block_0Analyzer();
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
class R009_Block_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_Block_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Block_1Analyzer();
};



//beg_BlockStatements : Block BlockStatements
class R009_BlockStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_BlockStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_BlockStatements_0Analyzer();
};



//beg_BlockStatements : NonBrace BlockStatements
class R009_BlockStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_BlockStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_BlockStatements_1Analyzer();
};



//beg_BlockStatements : 0
class R009_BlockStatements_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_BlockStatements_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_BlockStatements_2Analyzer();
};



//beg_NonBrace : StatementEle
class R009_NonBrace_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_0Analyzer();
};



//beg_NonBrace : 'COMMA'
class R009_NonBrace_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_1Analyzer();
};



//beg_NonBrace : 'semicolon'
class R009_NonBrace_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_2Analyzer();
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
class R009_NonBrace_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_3Analyzer();
};



//beg_NonBrace : 'LEFT_BRACKET'
class R009_NonBrace_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_4Analyzer();
};



//beg_NonBrace : 'LEFT_PARENTHESES'
class R009_NonBrace_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_5Analyzer();
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
class R009_NonBrace_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_6Analyzer();
};



//beg_NonBrace : 'RIGHT_BRACKET'
class R009_NonBrace_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_7Analyzer();
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
class R009_NonBrace_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_8Analyzer();
};



//beg_NonBrace : 'EQUAL'
class R009_NonBrace_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonBrace_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonBrace_9Analyzer();
};



//beg_StatementEle : Identifier
class R009_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_0Analyzer();
};



//beg_StatementEle : 'AND'
class R009_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_1Analyzer();
};



//beg_StatementEle : 'AND_EQUAL'
class R009_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_2Analyzer();
};



//beg_StatementEle : 'AT'
class R009_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_3Analyzer();
};



//beg_StatementEle : 'AT_INTERFACE'
class R009_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_4Analyzer();
};



//beg_StatementEle : 'BIT_AND'
class R009_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_5Analyzer();
};



//beg_StatementEle : 'BIT_OR'
class R009_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_6Analyzer();
};



//beg_StatementEle : 'BooleanLiteral'
class R009_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_7Analyzer();
};



//beg_StatementEle : 'CARET'
class R009_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_8Analyzer();
};



//beg_StatementEle : 'COLON'
class R009_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_9Analyzer();
};



//beg_StatementEle : 'CharacterLiteral'
class R009_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_10Analyzer();
};



//beg_StatementEle : 'DB_EQUAL'
class R009_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_11Analyzer();
};



//beg_StatementEle : 'DIVIDE_EQUAL'
class R009_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_12Analyzer();
};



//beg_StatementEle : 'FloatingPointLiteral'
class R009_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_13Analyzer();
};



//beg_StatementEle : 'GT_EQUAL'
class R009_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_14Analyzer();
};



//beg_StatementEle : 'IntegerLiteral'
class R009_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_15Analyzer();
};



//beg_StatementEle : 'LAMBDA_TO'
class R009_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_16Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT'
class R009_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_17Analyzer();
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
class R009_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_18Analyzer();
};



//beg_StatementEle : 'LT_EQUAL'
class R009_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_19Analyzer();
};



//beg_StatementEle : 'MULTI_EQUAL'
class R009_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_20Analyzer();
};



//beg_StatementEle : 'NOT_EQUAL'
class R009_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_21Analyzer();
};



//beg_StatementEle : 'OR'
class R009_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_22Analyzer();
};



//beg_StatementEle : 'OR_EQUAL'
class R009_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_23Analyzer();
};



//beg_StatementEle : 'PLUS'
class R009_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_24Analyzer();
};



//beg_StatementEle : 'PLUS_EQUAL'
class R009_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_25Analyzer();
};



//beg_StatementEle : 'PRECENTAGE'
class R009_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_26Analyzer();
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
class R009_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_27Analyzer();
};



//beg_StatementEle : 'PackageOrTypeNameId'
class R009_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_28Analyzer();
};



//beg_StatementEle : 'QUESTION'
class R009_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_29Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT'
class R009_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_30Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2'
class R009_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_31Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R009_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_32Analyzer();
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
class R009_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_33Analyzer();
};



//beg_StatementEle : 'RIGTH_BRACKET'
class R009_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_34Analyzer();
};



//beg_StatementEle : 'SLASH'
class R009_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_35Analyzer();
};



//beg_StatementEle : 'SPOT'
class R009_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_36Analyzer();
};



//beg_StatementEle : 'STAR'
class R009_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_37Analyzer();
};



//beg_StatementEle : 'SUBTRACT'
class R009_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_38Analyzer();
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
class R009_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_39Analyzer();
};



//beg_StatementEle : 'SURPRISE'
class R009_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_40Analyzer();
};



//beg_StatementEle : 'StringLiteral'
class R009_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_41Analyzer();
};



//beg_StatementEle : 'THREE_SPOT'
class R009_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_42Analyzer();
};



//beg_StatementEle : 'TILDE'
class R009_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_43Analyzer();
};



//beg_StatementEle : 'TWO_COLON'
class R009_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_44Analyzer();
};



//beg_StatementEle : 'TWO_PLUS'
class R009_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_45Analyzer();
};



//beg_StatementEle : 'TWO_SUBTRACT'
class R009_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_46Analyzer();
};



//beg_StatementEle : 'TypeNameId'
class R009_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_47Analyzer();
};



//beg_StatementEle : 'XOR_EQUAL'
class R009_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_48Analyzer();
};



//beg_StatementEle : 'abstract'
class R009_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_49Analyzer();
};



//beg_StatementEle : 'boolean'
class R009_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_50Analyzer();
};



//beg_StatementEle : 'byte'
class R009_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_51Analyzer();
};



//beg_StatementEle : 'char'
class R009_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_52Analyzer();
};



//beg_StatementEle : 'class'
class R009_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_53Analyzer();
};



//beg_StatementEle : 'default'
class R009_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_54Analyzer();
};



//beg_StatementEle : 'double'
class R009_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_55Analyzer();
};



//beg_StatementEle : 'enum'
class R009_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_56Analyzer();
};



//beg_StatementEle : 'extends'
class R009_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_57Analyzer();
};



//beg_StatementEle : 'final'
class R009_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_58Analyzer();
};



//beg_StatementEle : 'float'
class R009_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_59Analyzer();
};



//beg_StatementEle : 'implements'
class R009_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_60Analyzer();
};



//beg_StatementEle : 'instanceof'
class R009_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_61Analyzer();
};



//beg_StatementEle : 'int'
class R009_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_62Analyzer();
};



//beg_StatementEle : 'interface'
class R009_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_63Analyzer();
};



//beg_StatementEle : 'long'
class R009_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_64Analyzer();
};



//beg_StatementEle : 'native'
class R009_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_65Analyzer();
};



//beg_StatementEle : 'new'
class R009_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_66Analyzer();
};



//beg_StatementEle : 'null'
class R009_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_67Analyzer();
};



//beg_StatementEle : 'private'
class R009_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_68Analyzer();
};



//beg_StatementEle : 'protected'
class R009_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_69Analyzer();
};



//beg_StatementEle : 'public'
class R009_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_70Analyzer();
};



//beg_StatementEle : 'short'
class R009_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_71Analyzer();
};



//beg_StatementEle : 'static'
class R009_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_72Analyzer();
};



//beg_StatementEle : 'super'
class R009_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_73Analyzer();
};



//beg_StatementEle : 'synchronized'
class R009_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_74Analyzer();
};



//beg_StatementEle : 'this'
class R009_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_75Analyzer();
};



//beg_StatementEle : 'throws'
class R009_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_76Analyzer();
};



//beg_StatementEle : 'transient'
class R009_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_77Analyzer();
};



//beg_StatementEle : 'void'
class R009_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_78Analyzer();
};



//beg_StatementEle : 'volatile'
class R009_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R009_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_StatementEle_79Analyzer();
};



//beg_ModifierList : Modifier ModifierList
class R009_ModifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ModifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ModifierList_0Analyzer();
};



//beg_ModifierList : Modifier
class R009_ModifierList_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ModifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ModifierList_1Analyzer();
};



//beg_Modifier : 'public'
class R009_Modifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_0Analyzer();
};



//beg_Modifier : 'protected'
class R009_Modifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_1Analyzer();
};



//beg_Modifier : 'private'
class R009_Modifier_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_2Analyzer();
};



//beg_Modifier : 'abstract'
class R009_Modifier_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_3Analyzer();
};



//beg_Modifier : 'static'
class R009_Modifier_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_4Analyzer();
};



//beg_Modifier : 'final'
class R009_Modifier_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_5Analyzer();
};



//beg_Modifier : 'strictfp'
class R009_Modifier_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_6Analyzer();
};



//beg_Modifier : 'default'
class R009_Modifier_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_7Analyzer();
};



//beg_Modifier : 'volatile'
class R009_Modifier_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_8Analyzer();
};



//beg_Modifier : 'synchronized'
class R009_Modifier_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_9Analyzer();
};



//beg_Modifier : 'transient'
class R009_Modifier_10Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_10Analyzer();
};



//beg_Modifier : 'native'
class R009_Modifier_11Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_11Analyzer();
};



//beg_Modifier : Annotation
class R009_Modifier_12Analyzer :virtual public Non_Terminate_genertor {
public: R009_Modifier_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Modifier_12Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
class R009_Annotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Annotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Annotation_0Analyzer();
};



//beg_Annotation : 'AT' DetailIdentifier
class R009_Annotation_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_Annotation_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Annotation_1Analyzer();
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R009_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DetailIdentifier_0Analyzer();
};



//beg_DetailIdentifier : Identifier
class R009_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DetailIdentifier_1Analyzer();
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R009_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationContent_0Analyzer();
};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R009_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationContentStatements_0Analyzer();
};



//beg_AnnotationContentStatements : 0
class R009_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationContentStatements_1Analyzer();
};



//beg_NonPARENTHESES : StatementEle
class R009_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_0Analyzer();
};



//beg_NonPARENTHESES : 'COMMA'
class R009_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_1Analyzer();
};



//beg_NonPARENTHESES : 'semicolon'
class R009_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_2Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
class R009_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_3Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
class R009_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_4Analyzer();
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R009_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_5Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
class R009_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_6Analyzer();
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R009_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_7Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
class R009_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_8Analyzer();
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R009_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_9Analyzer();
};



//beg_NonPARENTHESES : 'EQUAL'
class R009_NonPARENTHESES_10Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonPARENTHESES_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonPARENTHESES_10Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
class R009_TypeArguments_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArguments_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArguments_0Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
class R009_TypeArguments_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArguments_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArguments_1Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
class R009_TypeArguments_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArguments_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArguments_2Analyzer();
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
class R009_TypeArguments_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArguments_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArguments_3Analyzer();
};



//beg_TypeArgumentListL2 : TypeArguments TypeArgumentListL2
class R009_TypeArgumentListL2_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL2_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL2_0Analyzer();
};



//beg_TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
class R009_TypeArgumentListL2_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL2_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL2_1Analyzer();
};



//beg_TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
class R009_TypeArgumentListL2_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL2_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL2_2Analyzer();
};



//beg_TypeArgumentListL1 : TypeArguments TypeArgumentListL1
class R009_TypeArgumentListL1_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL1_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL1_0Analyzer();
};



//beg_TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
class R009_TypeArgumentListL1_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL1_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL1_1Analyzer();
};



//beg_TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
class R009_TypeArgumentListL1_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentListL1_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentListL1_2Analyzer();
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
class R009_TypeArgumentList_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentList_0Analyzer();
};



//beg_TypeArgumentList : 0
class R009_TypeArgumentList_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_TypeArgumentList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_TypeArgumentList_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'QUESTION'
class R009_NonANGLE_BRACKET_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_0Analyzer();
};



//beg_NonANGLE_BRACKET : 'extends'
class R009_NonANGLE_BRACKET_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_1Analyzer();
};



//beg_NonANGLE_BRACKET : 'super'
class R009_NonANGLE_BRACKET_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_2Analyzer();
};



//beg_NonANGLE_BRACKET : 'COMMA'
class R009_NonANGLE_BRACKET_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_3Analyzer();
};



//beg_NonANGLE_BRACKET : Identifier
class R009_NonANGLE_BRACKET_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_4Analyzer();
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
class R009_NonANGLE_BRACKET_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_5Analyzer();
};



//beg_NonANGLE_BRACKET : 'SPOT'
class R009_NonANGLE_BRACKET_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_6Analyzer();
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
class R009_NonANGLE_BRACKET_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_7Analyzer();
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
class R009_NonANGLE_BRACKET_8Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_8Analyzer();
};



//beg_NonANGLE_BRACKET : TypeArguments
class R009_NonANGLE_BRACKET_9Analyzer :virtual public Non_Terminate_genertor {
public: R009_NonANGLE_BRACKET_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_NonANGLE_BRACKET_9Analyzer();
};



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
class R009_ExtendsInterfaces_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ExtendsInterfaces_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ExtendsInterfaces_0Analyzer();
};



//beg_InterfaceTypeList : ClassType
class R009_InterfaceTypeList_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_InterfaceTypeList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_InterfaceTypeList_0Analyzer();
};



//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
class R009_InterfaceTypeList_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_InterfaceTypeList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_InterfaceTypeList_1Analyzer();
};



//beg_ClassTypeEle : Identifier
class R009_ClassTypeEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassTypeEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassTypeEle_0Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier
class R009_ClassTypeEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassTypeEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassTypeEle_1Analyzer();
};



//beg_ClassTypeEle : Identifier TypeArguments
class R009_ClassTypeEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassTypeEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassTypeEle_2Analyzer();
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
class R009_ClassTypeEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassTypeEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassTypeEle_3Analyzer();
};



//beg_ClassType : ClassTypeEle
class R009_ClassType_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassType_0Analyzer();
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
class R009_ClassType_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ClassType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ClassType_1Analyzer();
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent 'semicolon'
class R009_AnnotationTypeElementDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_0Analyzer();
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent 'semicolon'
class R009_AnnotationTypeElementDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_1Analyzer();
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent Dims 'semicolon'
class R009_AnnotationTypeElementDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_2Analyzer();
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent Dims 'semicolon'
class R009_AnnotationTypeElementDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_3Analyzer();
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent DefaultValue 'semicolon'
class R009_AnnotationTypeElementDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_4Analyzer();
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent DefaultValue 'semicolon'
class R009_AnnotationTypeElementDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_5Analyzer();
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent Dims DefaultValue 'semicolon'
class R009_AnnotationTypeElementDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_6Analyzer();
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent Dims DefaultValue 'semicolon'
class R009_AnnotationTypeElementDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationTypeElementDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationTypeElementDeclaration_7Analyzer();
};



//beg_DefaultValue : 'default' ElementValue
class R009_DefaultValue_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_DefaultValue_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DefaultValue_0Analyzer();
};



//beg_ElementValue : Annotation
class R009_ElementValue_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ElementValue_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ElementValue_0Analyzer();
};



//beg_ElementValue : VariableInitializer
class R009_ElementValue_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ElementValue_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ElementValue_1Analyzer();
};



//beg_Result : UnannType
class R009_Result_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Result_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Result_0Analyzer();
};



//beg_Result : 'void'
class R009_Result_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_Result_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Result_1Analyzer();
};



//beg_UnannType : UnannArrayType
class R009_UnannType_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannType_0Analyzer();
};



//beg_UnannType : UnannPrimitiveType
class R009_UnannType_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannType_1Analyzer();
};



//beg_UnannType : UnannClassOrInterfaceType
class R009_UnannType_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannType_2Analyzer();
};



//beg_UnannPrimitiveType : 'boolean'
class R009_UnannPrimitiveType_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_0Analyzer();
};



//beg_UnannPrimitiveType : 'byte'
class R009_UnannPrimitiveType_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_1Analyzer();
};



//beg_UnannPrimitiveType : 'short'
class R009_UnannPrimitiveType_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_2Analyzer();
};



//beg_UnannPrimitiveType : 'int'
class R009_UnannPrimitiveType_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_3Analyzer();
};



//beg_UnannPrimitiveType : 'long'
class R009_UnannPrimitiveType_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_4Analyzer();
};



//beg_UnannPrimitiveType : 'char'
class R009_UnannPrimitiveType_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_5Analyzer();
};



//beg_UnannPrimitiveType : 'float'
class R009_UnannPrimitiveType_6Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_6Analyzer();
};



//beg_UnannPrimitiveType : 'double'
class R009_UnannPrimitiveType_7Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannPrimitiveType_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannPrimitiveType_7Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' AnnotationList UnannClassOrInterfaceType
class R009_UnannClassOrInterfaceType_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_0Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier 'SPOT' AnnotationList UnannClassOrInterfaceType
class R009_UnannClassOrInterfaceType_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_1Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' UnannClassOrInterfaceType
class R009_UnannClassOrInterfaceType_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_2Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier 'SPOT' UnannClassOrInterfaceType
class R009_UnannClassOrInterfaceType_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_3Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments
class R009_UnannClassOrInterfaceType_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_4Analyzer();
};



//beg_UnannClassOrInterfaceType : Identifier
class R009_UnannClassOrInterfaceType_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannClassOrInterfaceType_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannClassOrInterfaceType_5Analyzer();
};



//beg_UnannArrayType : UnannPrimitiveType Dims
class R009_UnannArrayType_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannArrayType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannArrayType_0Analyzer();
};



//beg_UnannArrayType : UnannClassOrInterfaceType Dims
class R009_UnannArrayType_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_UnannArrayType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_UnannArrayType_1Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R009_Dims_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_Dims_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Dims_0Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
class R009_Dims_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_Dims_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Dims_1Analyzer();
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R009_Dims_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_Dims_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Dims_2Analyzer();
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R009_Dims_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_Dims_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_Dims_3Analyzer();
};



//beg_ConstantDeclaration : UnannType VariableDeclaratorList 'semicolon'
class R009_ConstantDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ConstantDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ConstantDeclaration_0Analyzer();
};



//beg_ConstantDeclaration : ModifierList UnannType VariableDeclaratorList 'semicolon'
class R009_ConstantDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ConstantDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ConstantDeclaration_1Analyzer();
};



//beg_ConstantDeclarationFake : UnannType VariableDeclaratorList
class R009_ConstantDeclarationFake_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_ConstantDeclarationFake_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ConstantDeclarationFake_0Analyzer();
};



//beg_ConstantDeclarationFake : ModifierList UnannType VariableDeclaratorList
class R009_ConstantDeclarationFake_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_ConstantDeclarationFake_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_ConstantDeclarationFake_1Analyzer();
};



//beg_VariableDeclaratorList : VariableDeclarator 'COMMA' VariableDeclaratorList
class R009_VariableDeclaratorList_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclaratorList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclaratorList_0Analyzer();
};



//beg_VariableDeclaratorList : VariableDeclarator
class R009_VariableDeclaratorList_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclaratorList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclaratorList_1Analyzer();
};



//beg_VariableDeclarator : VariableDeclaratorId 'EQUAL' VariableInitializer
class R009_VariableDeclarator_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclarator_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclarator_0Analyzer();
};



//beg_VariableDeclarator : VariableDeclaratorId
class R009_VariableDeclarator_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclarator_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclarator_1Analyzer();
};



//beg_VariableInitializer : VariableInitializerEle VariableInitializer
class R009_VariableInitializer_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializer_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializer_0Analyzer();
};



//beg_VariableInitializer : VariableInitializerEle
class R009_VariableInitializer_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializer_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializer_1Analyzer();
};



//beg_VariableInitializerEle : StatementEle
class R009_VariableInitializerEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_0Analyzer();
};



//beg_VariableInitializerEle : Block
class R009_VariableInitializerEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_1Analyzer();
};



//beg_VariableInitializerEle : AnnotationContent
class R009_VariableInitializerEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_2Analyzer();
};



//beg_VariableInitializerEle : TypeArguments
class R009_VariableInitializerEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_3Analyzer();
};



//beg_VariableInitializerEle : DimExpr
class R009_VariableInitializerEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_4Analyzer();
};



//beg_VariableInitializerEle : 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R009_VariableInitializerEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableInitializerEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableInitializerEle_5Analyzer();
};



//beg_VariableDeclaratorId : Identifier Dims
class R009_VariableDeclaratorId_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclaratorId_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclaratorId_0Analyzer();
};



//beg_VariableDeclaratorId : Identifier
class R009_VariableDeclaratorId_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_VariableDeclaratorId_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_VariableDeclaratorId_1Analyzer();
};



//beg_AnnotationList : Annotation AnnotationList
class R009_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationList_0Analyzer();
};



//beg_AnnotationList : Annotation
class R009_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_AnnotationList_1Analyzer();
};



//beg_DimExpr : AnnotationList 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
class R009_DimExpr_0Analyzer :virtual public Non_Terminate_genertor {
public: R009_DimExpr_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DimExpr_0Analyzer();
};



//beg_DimExpr : 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
class R009_DimExpr_1Analyzer :virtual public Non_Terminate_genertor {
public: R009_DimExpr_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R009_DimExpr_1Analyzer();
};
