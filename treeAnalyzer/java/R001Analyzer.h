#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R001_DefaultAnalyzer :virtual public SDT_genertor {
public: R001_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DefaultAnalyzer();
};


//ele_begin : CompilationUnit
class R001_ele_begin_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_begin_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_begin_0Analyzer();
};



//Identifier : 'IDENTIFIER'
class R001_Identifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Identifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Identifier_0Analyzer();
};



//IdentifierList : 'SPOT' Identifier IdentifierList
class R001_IdentifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_IdentifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IdentifierList_0Analyzer();
};



//IdentifierList : 0
class R001_IdentifierList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_IdentifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IdentifierList_1Analyzer();
};



//Literal : 'IntegerLiteral'
class R001_Literal_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Literal_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Literal_0Analyzer();
};



//Literal : 'FloatingPointLiteral'
class R001_Literal_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Literal_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Literal_1Analyzer();
};



//Literal : 'BooleanLiteral'
class R001_Literal_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_Literal_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Literal_2Analyzer();
};



//Literal : 'CharacterLiteral'
class R001_Literal_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_Literal_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Literal_3Analyzer();
};



//Literal : 'null'
class R001_Literal_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_Literal_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Literal_4Analyzer();
};



//UnannType : UnannPrimitiveType
class R001_UnannType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannType_0Analyzer();
};



//UnannType : UnannClassOrInterfaceType
class R001_UnannType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannType_1Analyzer();
};



//UnannType : UnannArrayType
class R001_UnannType_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannType_2Analyzer();
};



//UnannPrimitiveType : NumericType
class R001_UnannPrimitiveType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannPrimitiveType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannPrimitiveType_0Analyzer();
};



//UnannPrimitiveType : 'boolean'
class R001_UnannPrimitiveType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannPrimitiveType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannPrimitiveType_1Analyzer();
};



//NumericType : IntegralType
class R001_NumericType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NumericType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NumericType_0Analyzer();
};



//NumericType : FloatingPointType
class R001_NumericType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NumericType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NumericType_1Analyzer();
};



//IntegralType : 'byte'
class R001_IntegralType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_IntegralType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IntegralType_0Analyzer();
};



//IntegralType : 'short'
class R001_IntegralType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_IntegralType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IntegralType_1Analyzer();
};



//IntegralType : 'int'
class R001_IntegralType_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_IntegralType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IntegralType_2Analyzer();
};



//IntegralType : 'long'
class R001_IntegralType_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_IntegralType_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IntegralType_3Analyzer();
};



//IntegralType : 'char'
class R001_IntegralType_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_IntegralType_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_IntegralType_4Analyzer();
};



//FloatingPointType : 'float'
class R001_FloatingPointType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_FloatingPointType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_FloatingPointType_0Analyzer();
};



//FloatingPointType : 'double'
class R001_FloatingPointType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_FloatingPointType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_FloatingPointType_1Analyzer();
};



//UnannClassOrInterfaceType : UnannClassType 'SPOT' UnannClassOrInterfaceType
class R001_UnannClassOrInterfaceType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannClassOrInterfaceType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannClassOrInterfaceType_0Analyzer();
};



//UnannClassOrInterfaceType : UnannClassType 'SPOT' AnnotationList UnannClassOrInterfaceType
class R001_UnannClassOrInterfaceType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannClassOrInterfaceType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannClassOrInterfaceType_1Analyzer();
};



//UnannClassOrInterfaceType : UnannClassType
class R001_UnannClassOrInterfaceType_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannClassOrInterfaceType_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannClassOrInterfaceType_2Analyzer();
};



//UnannClassType : Identifier
class R001_UnannClassType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannClassType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannClassType_0Analyzer();
};



//UnannClassType : Identifier TypeArguments
class R001_UnannClassType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannClassType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannClassType_1Analyzer();
};



//UnannArrayType : UnannPrimitiveType Dims
class R001_UnannArrayType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannArrayType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannArrayType_0Analyzer();
};



//UnannArrayType : UnannClassOrInterfaceType Dims
class R001_UnannArrayType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_UnannArrayType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_UnannArrayType_1Analyzer();
};



//CompilationUnit : PackageDeclaration
class R001_CompilationUnit_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_0Analyzer();
};



//CompilationUnit : ImportDeclarationList
class R001_CompilationUnit_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_1Analyzer();
};



//CompilationUnit : TypeDeclarationList
class R001_CompilationUnit_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_2Analyzer();
};



//CompilationUnit : PackageDeclaration ImportDeclarationList
class R001_CompilationUnit_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_3Analyzer();
};



//CompilationUnit : PackageDeclaration TypeDeclarationList
class R001_CompilationUnit_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_4Analyzer();
};



//CompilationUnit : ImportDeclarationList TypeDeclarationList
class R001_CompilationUnit_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_5Analyzer();
};



//CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
class R001_CompilationUnit_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_CompilationUnit_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_CompilationUnit_6Analyzer();
};



//PackageDeclaration : AnnotationList 'package' DetailIdentifier 'semicolon'
class R001_PackageDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_PackageDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_PackageDeclaration_0Analyzer();
};



//PackageDeclaration : 'package' DetailIdentifier 'semicolon'
class R001_PackageDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_PackageDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_PackageDeclaration_1Analyzer();
};



//DetailIdentifier : Identifier 'SPOT' DetailIdentifier
class R001_DetailIdentifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_DetailIdentifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DetailIdentifier_0Analyzer();
};



//DetailIdentifier : Identifier
class R001_DetailIdentifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_DetailIdentifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DetailIdentifier_1Analyzer();
};



//ImportDeclarationList : ImportDeclaration ImportDeclarationList
class R001_ImportDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclarationList_0Analyzer();
};



//ImportDeclarationList : ImportDeclaration
class R001_ImportDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclarationList_1Analyzer();
};



//ImportDeclaration : 'import' DetailIdentifier 'semicolon'
class R001_ImportDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclaration_0Analyzer();
};



//ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
class R001_ImportDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclaration_1Analyzer();
};



//ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R001_ImportDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclaration_2Analyzer();
};



//ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
class R001_ImportDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_ImportDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ImportDeclaration_3Analyzer();
};



//TypeDeclarationList : TypeDeclaration TypeDeclarationList
class R001_TypeDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeDeclarationList_0Analyzer();
};



//TypeDeclarationList : TypeDeclaration
class R001_TypeDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeDeclarationList_1Analyzer();
};



//TypeDeclaration : ClassDeclaration
class R001_TypeDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeDeclaration_0Analyzer();
};



//TypeDeclaration : InterfaceDeclaration
class R001_TypeDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeDeclaration_1Analyzer();
};



//TypeDeclaration : 'semicolon'
class R001_TypeDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeDeclaration_2Analyzer();
};



//ClassDeclaration : NormalClassDeclaration
class R001_ClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassDeclaration_0Analyzer();
};



//ClassDeclaration : EnumDeclaration
class R001_ClassDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassDeclaration_1Analyzer();
};



//NormalClassDeclaration : 'class' Identifier ClassBody
class R001_NormalClassDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_0Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
class R001_NormalClassDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_1Analyzer();
};



//NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
class R001_NormalClassDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_2Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
class R001_NormalClassDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_3Analyzer();
};



//NormalClassDeclaration : 'class' Identifier 'extends' ClassType ClassBody
class R001_NormalClassDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_4Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier 'extends' ClassType ClassBody
class R001_NormalClassDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_5Analyzer();
};



//NormalClassDeclaration : 'class' Identifier TypeArguments 'extends' ClassType ClassBody
class R001_NormalClassDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_6Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'extends' ClassType ClassBody
class R001_NormalClassDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_7Analyzer();
};



//NormalClassDeclaration : 'class' Identifier 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_8Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_9Analyzer();
};



//NormalClassDeclaration : 'class' Identifier TypeArguments 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_10Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_10Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_11Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_11Analyzer();
};



//NormalClassDeclaration : 'class' Identifier 'extends' ClassType 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_12Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_12Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier 'extends' ClassType 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_13Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_13Analyzer();
};



//NormalClassDeclaration : 'class' Identifier TypeArguments 'extends' ClassType 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_14Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_14Analyzer();
};



//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'extends' ClassType 'implements' InterfaceTypeList ClassBody
class R001_NormalClassDeclaration_15Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalClassDeclaration_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalClassDeclaration_15Analyzer();
};



//ModifierList : Modifier ModifierList
class R001_ModifierList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ModifierList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ModifierList_0Analyzer();
};



//ModifierList : Modifier
class R001_ModifierList_1Analyzer :virtual public Non_Terminate_Skip_genertor {
public: R001_ModifierList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ModifierList_1Analyzer();
};



//Modifier : Annotation
class R001_Modifier_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_0Analyzer();
};



//Modifier : 'public'
class R001_Modifier_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_1Analyzer();
};



//Modifier : 'protected'
class R001_Modifier_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_2Analyzer();
};



//Modifier : 'private'
class R001_Modifier_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_3Analyzer();
};



//Modifier : 'abstract'
class R001_Modifier_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_4Analyzer();
};



//Modifier : 'static'
class R001_Modifier_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_5Analyzer();
};



//Modifier : 'final'
class R001_Modifier_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_6Analyzer();
};



//Modifier : 'strictfp'
class R001_Modifier_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_7Analyzer();
};



//Modifier : 'default'
class R001_Modifier_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_8Analyzer();
};



//Modifier : 'volatile'
class R001_Modifier_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_9Analyzer();
};



//Modifier : 'synchronized'
class R001_Modifier_10Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_10Analyzer();
};



//Modifier : 'transient'
class R001_Modifier_11Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_11Analyzer();
};



//Modifier : 'native'
class R001_Modifier_12Analyzer :virtual public Non_Terminate_genertor {
public: R001_Modifier_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Modifier_12Analyzer();
};



//InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
class R001_InterfaceTypeList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_InterfaceTypeList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_InterfaceTypeList_0Analyzer();
};



//InterfaceTypeList : ClassType
class R001_InterfaceTypeList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_InterfaceTypeList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_InterfaceTypeList_1Analyzer();
};



//ClassType : ClassType 'SPOT' ClassTypeUnit
class R001_ClassType_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassType_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassType_0Analyzer();
};



//ClassType : ClassTypeUnit
class R001_ClassType_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassType_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassType_1Analyzer();
};



//ClassTypeUnit : Identifier
class R001_ClassTypeUnit_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassTypeUnit_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassTypeUnit_0Analyzer();
};



//ClassTypeUnit : Identifier TypeArguments
class R001_ClassTypeUnit_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassTypeUnit_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassTypeUnit_1Analyzer();
};



//ClassTypeUnit : AnnotationList Identifier
class R001_ClassTypeUnit_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassTypeUnit_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassTypeUnit_2Analyzer();
};



//ClassTypeUnit : AnnotationList Identifier TypeArguments
class R001_ClassTypeUnit_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassTypeUnit_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassTypeUnit_3Analyzer();
};



//EnumDeclaration : 'enum' Identifier EnumBody
class R001_EnumDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumDeclaration_0Analyzer();
};



//EnumDeclaration : ModifierList 'enum' Identifier EnumBody
class R001_EnumDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumDeclaration_1Analyzer();
};



//EnumDeclaration : 'enum' Identifier  'implements' InterfaceTypeList EnumBody
class R001_EnumDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumDeclaration_2Analyzer();
};



//EnumDeclaration : ModifierList 'enum' Identifier 'implements' InterfaceTypeList EnumBody
class R001_EnumDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumDeclaration_3Analyzer();
};



//InterfaceDeclaration : NormalInterfaceDeclaration
class R001_InterfaceDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_InterfaceDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_InterfaceDeclaration_0Analyzer();
};



//InterfaceDeclaration : AnnotationTypeDeclaration
class R001_InterfaceDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_InterfaceDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_InterfaceDeclaration_1Analyzer();
};



//NormalInterfaceDeclaration : 'interface' Identifier ClassBody
class R001_NormalInterfaceDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_0Analyzer();
};



//NormalInterfaceDeclaration : ModifierList 'interface' Identifier ClassBody
class R001_NormalInterfaceDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_1Analyzer();
};



//NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ClassBody
class R001_NormalInterfaceDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_2Analyzer();
};



//NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ClassBody
class R001_NormalInterfaceDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_3Analyzer();
};



//NormalInterfaceDeclaration : 'interface' Identifier 'extends' InterfaceTypeList ClassBody
class R001_NormalInterfaceDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_4Analyzer();
};



//NormalInterfaceDeclaration : ModifierList 'interface' Identifier 'extends' InterfaceTypeList ClassBody
class R001_NormalInterfaceDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_5Analyzer();
};



//NormalInterfaceDeclaration : 'interface' Identifier TypeArguments 'extends' InterfaceTypeList ClassBody
class R001_NormalInterfaceDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_6Analyzer();
};



//NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments 'extends' InterfaceTypeList ClassBody
class R001_NormalInterfaceDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalInterfaceDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalInterfaceDeclaration_7Analyzer();
};



//AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier AnnotationTypeBody
class R001_AnnotationTypeDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeDeclaration_0Analyzer();
};



//AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier AnnotationTypeBody
class R001_AnnotationTypeDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeDeclaration_1Analyzer();
};



//Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
class R001_Block_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Block_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Block_0Analyzer();
};



//Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
class R001_Block_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Block_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Block_1Analyzer();
};



//BlockStatements : Block BlockStatements
class R001_BlockStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_BlockStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_BlockStatements_0Analyzer();
};



//BlockStatements : NonBrace BlockStatements
class R001_BlockStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_BlockStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_BlockStatements_1Analyzer();
};



//BlockStatements : 0
class R001_BlockStatements_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_BlockStatements_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_BlockStatements_2Analyzer();
};



//NonBrace : StatementEle
class R001_NonBrace_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_0Analyzer();
};



//NonBrace : 'COMMA'
class R001_NonBrace_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_1Analyzer();
};



//NonBrace : 'semicolon'
class R001_NonBrace_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_2Analyzer();
};



//NonBrace : 'LEFT_ANGLE_BRACKET'
class R001_NonBrace_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_3Analyzer();
};



//NonBrace : 'LEFT_BRACKET'
class R001_NonBrace_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_4Analyzer();
};



//NonBrace : 'LEFT_PARENTHESES'
class R001_NonBrace_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_5Analyzer();
};



//NonBrace : 'RIGHT_ANGLE_BRACKET'
class R001_NonBrace_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_6Analyzer();
};



//NonBrace : 'RIGHT_BRACKET'
class R001_NonBrace_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_7Analyzer();
};



//NonBrace : 'RIGHT_PARENTHESES'
class R001_NonBrace_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonBrace_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonBrace_8Analyzer();
};



//StatementEle : 'IDENTIFIER'
class R001_StatementEle_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_0Analyzer();
};



//StatementEle : 'AND'
class R001_StatementEle_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_1Analyzer();
};



//StatementEle : 'AND_EQUAL'
class R001_StatementEle_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_2Analyzer();
};



//StatementEle : 'AT'
class R001_StatementEle_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_3Analyzer();
};



//StatementEle : 'AT_INTERFACE'
class R001_StatementEle_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_4Analyzer();
};



//StatementEle : 'BIT_AND'
class R001_StatementEle_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_5Analyzer();
};



//StatementEle : 'BIT_OR'
class R001_StatementEle_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_6Analyzer();
};



//StatementEle : 'BooleanLiteral'
class R001_StatementEle_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_7Analyzer();
};



//StatementEle : 'CARET'
class R001_StatementEle_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_8Analyzer();
};



//StatementEle : 'COLON'
class R001_StatementEle_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_9Analyzer();
};



//StatementEle : 'CharacterLiteral'
class R001_StatementEle_10Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_10Analyzer();
};



//StatementEle : 'DB_EQUAL'
class R001_StatementEle_11Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_11Analyzer();
};



//StatementEle : 'DIVIDE_EQUAL'
class R001_StatementEle_12Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_12Analyzer();
};



//StatementEle : 'EQUAL'
class R001_StatementEle_13Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_13Analyzer();
};



//StatementEle : 'FloatingPointLiteral'
class R001_StatementEle_14Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_14Analyzer();
};



//StatementEle : 'GT_EQUAL'
class R001_StatementEle_15Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_15Analyzer();
};



//StatementEle : 'IntegerLiteral'
class R001_StatementEle_16Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_16Analyzer();
};



//StatementEle : 'LAMBDA_TO'
class R001_StatementEle_17Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_17Analyzer();
};



//StatementEle : 'LEFT_SHIFT'
class R001_StatementEle_18Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_18Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_18Analyzer();
};



//StatementEle : 'LEFT_SHIFT_EQUAL'
class R001_StatementEle_19Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_19Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_19Analyzer();
};



//StatementEle : 'LT_EQUAL'
class R001_StatementEle_20Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_20Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_20Analyzer();
};



//StatementEle : 'MULTI_EQUAL'
class R001_StatementEle_21Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_21Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_21Analyzer();
};



//StatementEle : 'NOT_EQUAL'
class R001_StatementEle_22Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_22Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_22Analyzer();
};



//StatementEle : 'OR'
class R001_StatementEle_23Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_23Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_23Analyzer();
};



//StatementEle : 'OR_EQUAL'
class R001_StatementEle_24Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_24Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_24Analyzer();
};



//StatementEle : 'PLUS'
class R001_StatementEle_25Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_25Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_25Analyzer();
};



//StatementEle : 'PLUS_EQUAL'
class R001_StatementEle_26Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_26Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_26Analyzer();
};



//StatementEle : 'PRECENTAGE'
class R001_StatementEle_27Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_27Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_27Analyzer();
};



//StatementEle : 'PRECENTAGE_EQUAL'
class R001_StatementEle_28Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_28Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_28Analyzer();
};



//StatementEle : 'PackageOrTypeNameId'
class R001_StatementEle_29Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_29Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_29Analyzer();
};



//StatementEle : 'QUESTION'
class R001_StatementEle_30Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_30Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_30Analyzer();
};



//StatementEle : 'RIGHT_SHIFT'
class R001_StatementEle_31Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_31Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_31Analyzer();
};



//StatementEle : 'RIGHT_SHIFT2'
class R001_StatementEle_32Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_32Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_32Analyzer();
};



//StatementEle : 'RIGHT_SHIFT2_EQUAL'
class R001_StatementEle_33Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_33Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_33Analyzer();
};



//StatementEle : 'RIGHT_SHIFT_EQUAL'
class R001_StatementEle_34Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_34Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_34Analyzer();
};



//StatementEle : 'RIGTH_BRACKET'
class R001_StatementEle_35Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_35Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_35Analyzer();
};



//StatementEle : 'SLASH'
class R001_StatementEle_36Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_36Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_36Analyzer();
};



//StatementEle : 'SPOT'
class R001_StatementEle_37Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_37Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_37Analyzer();
};



//StatementEle : 'STAR'
class R001_StatementEle_38Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_38Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_38Analyzer();
};



//StatementEle : 'SUBTRACT'
class R001_StatementEle_39Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_39Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_39Analyzer();
};



//StatementEle : 'SUBTRACT_EQUAL'
class R001_StatementEle_40Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_40Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_40Analyzer();
};



//StatementEle : 'SURPRISE'
class R001_StatementEle_41Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_41Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_41Analyzer();
};



//StatementEle : 'StringLiteral'
class R001_StatementEle_42Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_42Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_42Analyzer();
};



//StatementEle : 'THREE_SPOT'
class R001_StatementEle_43Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_43Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_43Analyzer();
};



//StatementEle : 'TILDE'
class R001_StatementEle_44Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_44Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_44Analyzer();
};



//StatementEle : 'TWO_COLON'
class R001_StatementEle_45Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_45Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_45Analyzer();
};



//StatementEle : 'TWO_PLUS'
class R001_StatementEle_46Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_46Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_46Analyzer();
};



//StatementEle : 'TWO_SUBTRACT'
class R001_StatementEle_47Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_47Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_47Analyzer();
};



//StatementEle : 'TypeNameId'
class R001_StatementEle_48Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_48Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_48Analyzer();
};



//StatementEle : 'XOR_EQUAL'
class R001_StatementEle_49Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_49Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_49Analyzer();
};



//StatementEle : 'abstract'
class R001_StatementEle_50Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_50Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_50Analyzer();
};



//StatementEle : 'boolean'
class R001_StatementEle_51Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_51Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_51Analyzer();
};



//StatementEle : 'byte'
class R001_StatementEle_52Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_52Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_52Analyzer();
};



//StatementEle : 'char'
class R001_StatementEle_53Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_53Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_53Analyzer();
};



//StatementEle : 'class'
class R001_StatementEle_54Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_54Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_54Analyzer();
};



//StatementEle : 'default'
class R001_StatementEle_55Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_55Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_55Analyzer();
};



//StatementEle : 'double'
class R001_StatementEle_56Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_56Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_56Analyzer();
};



//StatementEle : 'enum'
class R001_StatementEle_57Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_57Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_57Analyzer();
};



//StatementEle : 'extends'
class R001_StatementEle_58Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_58Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_58Analyzer();
};



//StatementEle : 'final'
class R001_StatementEle_59Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_59Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_59Analyzer();
};



//StatementEle : 'float'
class R001_StatementEle_60Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_60Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_60Analyzer();
};



//StatementEle : 'implements'
class R001_StatementEle_61Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_61Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_61Analyzer();
};



//StatementEle : 'instanceof'
class R001_StatementEle_62Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_62Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_62Analyzer();
};



//StatementEle : 'int'
class R001_StatementEle_63Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_63Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_63Analyzer();
};



//StatementEle : 'interface'
class R001_StatementEle_64Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_64Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_64Analyzer();
};



//StatementEle : 'long'
class R001_StatementEle_65Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_65Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_65Analyzer();
};



//StatementEle : 'native'
class R001_StatementEle_66Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_66Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_66Analyzer();
};



//StatementEle : 'new'
class R001_StatementEle_67Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_67Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_67Analyzer();
};



//StatementEle : 'null'
class R001_StatementEle_68Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_68Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_68Analyzer();
};



//StatementEle : 'private'
class R001_StatementEle_69Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_69Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_69Analyzer();
};



//StatementEle : 'protected'
class R001_StatementEle_70Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_70Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_70Analyzer();
};



//StatementEle : 'public'
class R001_StatementEle_71Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_71Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_71Analyzer();
};



//StatementEle : 'short'
class R001_StatementEle_72Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_72Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_72Analyzer();
};



//StatementEle : 'static'
class R001_StatementEle_73Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_73Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_73Analyzer();
};



//StatementEle : 'super'
class R001_StatementEle_74Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_74Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_74Analyzer();
};



//StatementEle : 'synchronized'
class R001_StatementEle_75Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_75Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_75Analyzer();
};



//StatementEle : 'this'
class R001_StatementEle_76Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_76Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_76Analyzer();
};



//StatementEle : 'throws'
class R001_StatementEle_77Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_77Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_77Analyzer();
};



//StatementEle : 'transient'
class R001_StatementEle_78Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_78Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_78Analyzer();
};



//StatementEle : 'void'
class R001_StatementEle_79Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_79Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_79Analyzer();
};



//StatementEle : 'volatile'
class R001_StatementEle_80Analyzer :virtual public Non_Terminate_genertor {
public: R001_StatementEle_80Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StatementEle_80Analyzer();
};



//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
class R001_TypeArguments_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArguments_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArguments_0Analyzer();
};



//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
class R001_TypeArguments_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArguments_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArguments_1Analyzer();
};



//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
class R001_TypeArguments_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArguments_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArguments_2Analyzer();
};



//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
class R001_TypeArguments_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArguments_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArguments_3Analyzer();
};



//TypeArgumentListL2 : TypeArguments TypeArgumentListL2
class R001_TypeArgumentListL2_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL2_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL2_0Analyzer();
};



//TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
class R001_TypeArgumentListL2_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL2_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL2_1Analyzer();
};



//TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
class R001_TypeArgumentListL2_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL2_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL2_2Analyzer();
};



//TypeArgumentListL1 : TypeArguments TypeArgumentListL1
class R001_TypeArgumentListL1_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL1_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL1_0Analyzer();
};



//TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
class R001_TypeArgumentListL1_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL1_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL1_1Analyzer();
};



//TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
class R001_TypeArgumentListL1_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentListL1_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentListL1_2Analyzer();
};



//TypeArgumentList : TypeArguments TypeArgumentList
class R001_TypeArgumentList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentList_0Analyzer();
};



//TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
class R001_TypeArgumentList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentList_1Analyzer();
};



//TypeArgumentList : 0
class R001_TypeArgumentList_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_TypeArgumentList_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_TypeArgumentList_2Analyzer();
};



//NonANGLE_BRACKET : 'QUESTION'
class R001_NonANGLE_BRACKET_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_0Analyzer();
};



//NonANGLE_BRACKET : 'extends'
class R001_NonANGLE_BRACKET_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_1Analyzer();
};



//NonANGLE_BRACKET : 'super'
class R001_NonANGLE_BRACKET_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_2Analyzer();
};



//NonANGLE_BRACKET : 'COMMA'
class R001_NonANGLE_BRACKET_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_3Analyzer();
};



//NonANGLE_BRACKET : Identifier
class R001_NonANGLE_BRACKET_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_4Analyzer();
};



//NonANGLE_BRACKET : UnannPrimitiveType
class R001_NonANGLE_BRACKET_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_5Analyzer();
};



//NonANGLE_BRACKET : 'SPOT'
class R001_NonANGLE_BRACKET_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_6Analyzer();
};



//NonANGLE_BRACKET : 'LEFT_BRACKET'
class R001_NonANGLE_BRACKET_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_7Analyzer();
};



//NonANGLE_BRACKET : 'RIGHT_BRACKET'
class R001_NonANGLE_BRACKET_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonANGLE_BRACKET_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonANGLE_BRACKET_8Analyzer();
};



//AnnotationList : Annotation AnnotationList
class R001_AnnotationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationList_0Analyzer();
};



//AnnotationList : Annotation
class R001_AnnotationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationList_1Analyzer();
};



//Annotation : NormalAnnotation
class R001_Annotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Annotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Annotation_0Analyzer();
};



//Annotation : MarkerAnnotation
class R001_Annotation_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Annotation_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Annotation_1Analyzer();
};



//Annotation : SingleElementAnnotation
class R001_Annotation_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_Annotation_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Annotation_2Analyzer();
};



//MarkerAnnotation : 'AT' DetailIdentifier
class R001_MarkerAnnotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_MarkerAnnotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MarkerAnnotation_0Analyzer();
};



//NormalAnnotation : 'AT' DetailIdentifier AnnotationContent
class R001_NormalAnnotation_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NormalAnnotation_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NormalAnnotation_0Analyzer();
};



//AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
class R001_AnnotationContent_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContent_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContent_0Analyzer();
};



//AnnotationContentStatements : AnnotationContent AnnotationContentStatements
class R001_AnnotationContentStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_0Analyzer();
};



//AnnotationContentStatements : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' AnnotationContentStatements
class R001_AnnotationContentStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_1Analyzer();
};



//AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
class R001_AnnotationContentStatements_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_2Analyzer();
};



//AnnotationContentStatements : NonPARENTHESES
class R001_AnnotationContentStatements_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_3Analyzer();
};



//AnnotationContentStatements : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
class R001_AnnotationContentStatements_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_4Analyzer();
};



//AnnotationContentStatements : AnnotationContent
class R001_AnnotationContentStatements_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationContentStatements_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationContentStatements_5Analyzer();
};



//NonPARENTHESES : StatementEle
class R001_NonPARENTHESES_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_0Analyzer();
};



//NonPARENTHESES : 'COMMA'
class R001_NonPARENTHESES_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_1Analyzer();
};



//NonPARENTHESES : 'semicolon'
class R001_NonPARENTHESES_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_2Analyzer();
};



//NonPARENTHESES : 'LEFT_BRACE'
class R001_NonPARENTHESES_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_3Analyzer();
};



//NonPARENTHESES : 'LEFT_BRACKET'
class R001_NonPARENTHESES_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_4Analyzer();
};



//NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
class R001_NonPARENTHESES_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_5Analyzer();
};



//NonPARENTHESES : 'RIGHT_BRACE'
class R001_NonPARENTHESES_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_6Analyzer();
};



//NonPARENTHESES : 'COMMA_RIGHT_BRACE'
class R001_NonPARENTHESES_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_7Analyzer();
};



//NonPARENTHESES : 'RIGHT_BRACKET'
class R001_NonPARENTHESES_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_8Analyzer();
};



//NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
class R001_NonPARENTHESES_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonPARENTHESES_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonPARENTHESES_9Analyzer();
};



//DimExpr : 'LEFT_BRACKET' DimStatements 'RIGHT_BRACKET'
class R001_DimExpr_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_DimExpr_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DimExpr_0Analyzer();
};



//DimStatements : DimExpr DimStatements
class R001_DimStatements_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_DimStatements_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DimStatements_0Analyzer();
};



//DimStatements : NonDim DimStatements
class R001_DimStatements_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_DimStatements_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DimStatements_1Analyzer();
};



//DimStatements : 0
class R001_DimStatements_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_DimStatements_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DimStatements_2Analyzer();
};



//NonDim : StatementEle
class R001_NonDim_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_0Analyzer();
};



//NonDim : 'COMMA'
class R001_NonDim_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_1Analyzer();
};



//NonDim : 'semicolon'
class R001_NonDim_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_2Analyzer();
};



//NonDim : 'LEFT_BRACE'
class R001_NonDim_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_3Analyzer();
};



//NonDim : 'LEFT_PARENTHESES'
class R001_NonDim_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_4Analyzer();
};



//NonDim : 'LEFT_ANGLE_BRACKET'
class R001_NonDim_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_5Analyzer();
};



//NonDim : 'RIGHT_BRACE'
class R001_NonDim_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_6Analyzer();
};



//NonDim : 'COMMA_RIGHT_BRACE'
class R001_NonDim_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_7Analyzer();
};



//NonDim : 'RIGHT_PARENTHESES'
class R001_NonDim_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_8Analyzer();
};



//NonDim : 'RIGHT_ANGLE_BRACKET'
class R001_NonDim_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_NonDim_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_NonDim_9Analyzer();
};



//Dims : Dim Dims
class R001_Dims_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Dims_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Dims_0Analyzer();
};



//Dims : Dim
class R001_Dims_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Dims_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Dims_1Analyzer();
};



//Dim : 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R001_Dim_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Dim_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Dim_0Analyzer();
};



//Dim : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
class R001_Dim_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Dim_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Dim_1Analyzer();
};



//Expression : ele Expression
class R001_Expression_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Expression_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Expression_0Analyzer();
};



//Expression : ele
class R001_Expression_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_Expression_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Expression_1Analyzer();
};



//ele : StatementEle
class R001_ele_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_0Analyzer();
};



//ele : AnnotationContent
class R001_ele_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_1Analyzer();
};



//ele : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
class R001_ele_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_2Analyzer();
};



//ele : DimExpr
class R001_ele_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_3Analyzer();
};



//ele : Block
class R001_ele_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_4Analyzer();
};



//ele : TypeArguments
class R001_ele_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_ele_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ele_5Analyzer();
};



//ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
class R001_ClassBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBody_0Analyzer();
};



//ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
class R001_ClassBodyDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBodyDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBodyDeclarationList_0Analyzer();
};



//ClassBodyDeclarationList : 0
class R001_ClassBodyDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBodyDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBodyDeclarationList_1Analyzer();
};



//ClassBodyDeclaration : ClassMemberDeclaration
class R001_ClassBodyDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBodyDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBodyDeclaration_0Analyzer();
};



//ClassBodyDeclaration : InstanceInitializer
class R001_ClassBodyDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBodyDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBodyDeclaration_1Analyzer();
};



//ClassBodyDeclaration : StaticInitializer
class R001_ClassBodyDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassBodyDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassBodyDeclaration_2Analyzer();
};



//ClassMemberDeclaration : FieldDeclaration
class R001_ClassMemberDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassMemberDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassMemberDeclaration_0Analyzer();
};



//ClassMemberDeclaration : MethodDeclaration
class R001_ClassMemberDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassMemberDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassMemberDeclaration_1Analyzer();
};



//ClassMemberDeclaration : ClassDeclaration
class R001_ClassMemberDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassMemberDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassMemberDeclaration_2Analyzer();
};



//ClassMemberDeclaration : InterfaceDeclaration
class R001_ClassMemberDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassMemberDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassMemberDeclaration_3Analyzer();
};



//ClassMemberDeclaration : 'semicolon'
class R001_ClassMemberDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_ClassMemberDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ClassMemberDeclaration_4Analyzer();
};



//InstanceInitializer : Block
class R001_InstanceInitializer_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_InstanceInitializer_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_InstanceInitializer_0Analyzer();
};



//StaticInitializer : 'static' Block
class R001_StaticInitializer_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_StaticInitializer_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_StaticInitializer_0Analyzer();
};



//FieldDeclaration : UnannType VariableDeclaratorList 'semicolon'
class R001_FieldDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_FieldDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_FieldDeclaration_0Analyzer();
};



//FieldDeclaration : ModifierList UnannType VariableDeclaratorList 'semicolon'
class R001_FieldDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_FieldDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_FieldDeclaration_1Analyzer();
};



//VariableDeclaratorList : VariableDeclarator 'COMMA' VariableDeclaratorList
class R001_VariableDeclaratorList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclaratorList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclaratorList_0Analyzer();
};



//VariableDeclaratorList : VariableDeclarator
class R001_VariableDeclaratorList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclaratorList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclaratorList_1Analyzer();
};



//VariableDeclarator : VariableDeclaratorId
class R001_VariableDeclarator_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclarator_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclarator_0Analyzer();
};



//VariableDeclarator : VariableDeclaratorId 'EQUAL' Expression
class R001_VariableDeclarator_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclarator_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclarator_1Analyzer();
};



//VariableDeclaratorId : Identifier Dims
class R001_VariableDeclaratorId_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclaratorId_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclaratorId_0Analyzer();
};



//VariableDeclaratorId : Identifier
class R001_VariableDeclaratorId_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_VariableDeclaratorId_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_VariableDeclaratorId_1Analyzer();
};



//MethodDeclaration : MethodHeader MethodBody
class R001_MethodDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclaration_0Analyzer();
};



//MethodDeclaration : ModifierList MethodHeader MethodBody
class R001_MethodDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclaration_1Analyzer();
};



//MethodHeader : UnannType MethodDeclarator
class R001_MethodHeader_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_0Analyzer();
};



//MethodHeader : UnannType MethodDeclarator Throws
class R001_MethodHeader_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_1Analyzer();
};



//MethodHeader : TypeArguments UnannType MethodDeclarator
class R001_MethodHeader_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_2Analyzer();
};



//MethodHeader : TypeArguments UnannType MethodDeclarator Throws
class R001_MethodHeader_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_3Analyzer();
};



//MethodHeader : TypeArguments AnnotationList UnannType MethodDeclarator
class R001_MethodHeader_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_4Analyzer();
};



//MethodHeader : TypeArguments AnnotationList UnannType MethodDeclarator Throws
class R001_MethodHeader_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_5Analyzer();
};



//MethodHeader : 'void' MethodDeclarator
class R001_MethodHeader_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_6Analyzer();
};



//MethodHeader : 'void' MethodDeclarator Throws
class R001_MethodHeader_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_7Analyzer();
};



//MethodHeader : TypeArguments 'void' MethodDeclarator
class R001_MethodHeader_8Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_8Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_8Analyzer();
};



//MethodHeader : TypeArguments 'void' MethodDeclarator Throws
class R001_MethodHeader_9Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_9Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_9Analyzer();
};



//MethodHeader : TypeArguments AnnotationList 'void' MethodDeclarator
class R001_MethodHeader_10Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_10Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_10Analyzer();
};



//MethodHeader : TypeArguments AnnotationList 'void' MethodDeclarator Throws
class R001_MethodHeader_11Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_11Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_11Analyzer();
};



//MethodHeader : MethodDeclarator
class R001_MethodHeader_12Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_12Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_12Analyzer();
};



//MethodHeader : MethodDeclarator Throws
class R001_MethodHeader_13Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_13Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_13Analyzer();
};



//MethodHeader : TypeArguments MethodDeclarator
class R001_MethodHeader_14Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_14Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_14Analyzer();
};



//MethodHeader : TypeArguments MethodDeclarator Throws
class R001_MethodHeader_15Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_15Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_15Analyzer();
};



//MethodHeader : TypeArguments AnnotationList MethodDeclarator
class R001_MethodHeader_16Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_16Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_16Analyzer();
};



//MethodHeader : TypeArguments AnnotationList MethodDeclarator Throws
class R001_MethodHeader_17Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodHeader_17Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodHeader_17Analyzer();
};



//MethodDeclarator : Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
class R001_MethodDeclarator_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclarator_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclarator_0Analyzer();
};



//MethodDeclarator : Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims
class R001_MethodDeclarator_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclarator_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclarator_1Analyzer();
};



//MethodDeclarator : Identifier AnnotationContent
class R001_MethodDeclarator_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclarator_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclarator_2Analyzer();
};



//MethodDeclarator : Identifier AnnotationContent Dims
class R001_MethodDeclarator_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodDeclarator_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodDeclarator_3Analyzer();
};



//MethodBody : Block
class R001_MethodBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodBody_0Analyzer();
};



//MethodBody : 'semicolon'
class R001_MethodBody_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_MethodBody_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_MethodBody_1Analyzer();
};



//Throws : 'throws' ExceptionTypeList
class R001_Throws_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_Throws_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_Throws_0Analyzer();
};



//ExceptionTypeList : ClassType 'COMMA' ExceptionTypeList
class R001_ExceptionTypeList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ExceptionTypeList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ExceptionTypeList_0Analyzer();
};



//ExceptionTypeList : ClassType
class R001_ExceptionTypeList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ExceptionTypeList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ExceptionTypeList_1Analyzer();
};



//EnumBody : 'LEFT_BRACE' 'RIGHT_BRACE'
class R001_EnumBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_0Analyzer();
};



//EnumBody : 'LEFT_BRACE' EnumConstantList 'RIGHT_BRACE'
class R001_EnumBody_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_1Analyzer();
};



//EnumBody : 'LEFT_BRACE' 'COMMA_RIGHT_BRACE'
class R001_EnumBody_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_2Analyzer();
};



//EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA_RIGHT_BRACE'
class R001_EnumBody_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_3Analyzer();
};



//EnumBody : 'LEFT_BRACE' 'semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
class R001_EnumBody_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_4Analyzer();
};



//EnumBody : 'LEFT_BRACE' EnumConstantList 'semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
class R001_EnumBody_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_5Analyzer();
};



//EnumBody : 'LEFT_BRACE' 'COMMA_semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
class R001_EnumBody_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_6Analyzer();
};



//EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA_semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
class R001_EnumBody_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumBody_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumBody_7Analyzer();
};



//EnumConstantList : MethodDeclarator 'COMMA' EnumConstantList
class R001_EnumConstantList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumConstantList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumConstantList_0Analyzer();
};



//EnumConstantList : Identifier 'COMMA' EnumConstantList
class R001_EnumConstantList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumConstantList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumConstantList_1Analyzer();
};



//EnumConstantList : MethodDeclarator
class R001_EnumConstantList_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumConstantList_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumConstantList_2Analyzer();
};



//EnumConstantList : Identifier
class R001_EnumConstantList_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_EnumConstantList_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_EnumConstantList_3Analyzer();
};



//AnnotationTypeBody : 'LEFT_BRACE' AnnotationTypeMemberDeclarationList 'RIGHT_BRACE'
class R001_AnnotationTypeBody_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeBody_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeBody_0Analyzer();
};



//AnnotationTypeMemberDeclarationList : AnnotationTypeMemberDeclaration AnnotationTypeMemberDeclarationList
class R001_AnnotationTypeMemberDeclarationList_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclarationList_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclarationList_0Analyzer();
};



//AnnotationTypeMemberDeclarationList : 0
class R001_AnnotationTypeMemberDeclarationList_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclarationList_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclarationList_1Analyzer();
};



//AnnotationTypeMemberDeclaration : AnnotationTypeElementDeclaration
class R001_AnnotationTypeMemberDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclaration_0Analyzer();
};



//AnnotationTypeMemberDeclaration : FieldDeclaration
class R001_AnnotationTypeMemberDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclaration_1Analyzer();
};



//AnnotationTypeMemberDeclaration : ClassDeclaration
class R001_AnnotationTypeMemberDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclaration_2Analyzer();
};



//AnnotationTypeMemberDeclaration : InterfaceDeclaration
class R001_AnnotationTypeMemberDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclaration_3Analyzer();
};



//AnnotationTypeMemberDeclaration : 'semicolon'
class R001_AnnotationTypeMemberDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeMemberDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeMemberDeclaration_4Analyzer();
};



//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' 'semicolon'
class R001_AnnotationTypeElementDeclaration_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_0Analyzer();
};



//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' 'semicolon'
class R001_AnnotationTypeElementDeclaration_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_1Analyzer();
};



//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims 'semicolon'
class R001_AnnotationTypeElementDeclaration_2Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_2Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_2Analyzer();
};



//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims 'semicolon'
class R001_AnnotationTypeElementDeclaration_3Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_3Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_3Analyzer();
};



//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' DefaultValue 'semicolon'
class R001_AnnotationTypeElementDeclaration_4Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_4Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_4Analyzer();
};



//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' DefaultValue 'semicolon'
class R001_AnnotationTypeElementDeclaration_5Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_5Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_5Analyzer();
};



//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims DefaultValue 'semicolon'
class R001_AnnotationTypeElementDeclaration_6Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_6Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_6Analyzer();
};



//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims DefaultValue 'semicolon'
class R001_AnnotationTypeElementDeclaration_7Analyzer :virtual public Non_Terminate_genertor {
public: R001_AnnotationTypeElementDeclaration_7Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_AnnotationTypeElementDeclaration_7Analyzer();
};



//DefaultValue : 'default' ElementValue
class R001_DefaultValue_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_DefaultValue_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_DefaultValue_0Analyzer();
};



//ElementValue : Expression
class R001_ElementValue_0Analyzer :virtual public Non_Terminate_genertor {
public: R001_ElementValue_0Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ElementValue_0Analyzer();
};



//ElementValue : Annotation
class R001_ElementValue_1Analyzer :virtual public Non_Terminate_genertor {
public: R001_ElementValue_1Analyzer();
public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: virtual ~R001_ElementValue_1Analyzer();
};



