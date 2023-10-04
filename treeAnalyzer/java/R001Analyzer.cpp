//	https://docs.oracle.com/javase/specs/jls/se8/html/jls-19.html

//(Lexical Structure)
//
//(Types, Values, and Variables)
//
//(Names)
//
//(Packages)
//
//(Classes) (Interfaces) 修饰符 Method Normal Enum body  方法体
//
//
//
//(Arrays)
//
//(Blocks and Statements)
//
//(Expressions)



#include "R001Analyzer.h"
#include "../../symbols/java/Method.h"
#include "../../symbols/java/Class.h"
#include "../../symbols/java/Import.h"
#include "../../symbols/java/Block.h"
#include "../../symbols/java/Array.h"
#include "../../symbols/java/CompileUnit.h"
#include<iostream>
#include <sstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////

string getPackageName(Array *ptr) {

	ostringstream os;
	for (int i1 = 0; i1 < ptr->list.size(); i1++) {
		os << ptr->list[i1]->content;
		if (i1 != ptr->list.size() - 1) {
			os << ".";
		}
	}
	return os.str();
}

void logR001(const string& s) {
//	cout<<s<<endl;
}

R001_DefaultAnalyzer::R001_DefaultAnalyzer() {
}

P_NodeValue R001_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DefaultAnalyzer");
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


R001_DefaultAnalyzer::~R001_DefaultAnalyzer() {
}

#include "R001Analyzer2.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////

//java 文本

//IdentifierList : 'SPOT' Identifier IdentifierList
void R001_IdentifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IdentifierList_0");
}


//IdentifierList : 0
void R001_IdentifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IdentifierList_1");
}


//Literal : 'IntegerLiteral'
void R001_Literal_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Literal_0");
}


//Literal : 'FloatingPointLiteral'
void R001_Literal_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Literal_1");
}


//Literal : 'BooleanLiteral'
void R001_Literal_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Literal_2");
}


//Literal : 'CharacterLiteral'
void R001_Literal_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Literal_3");
}


//Literal : 'null'
void R001_Literal_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Literal_4");
}


//Identifier : 'IDENTIFIER'
void R001_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
}







//DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R001_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DetailIdentifier_0");
	nodeValue->context["DetailIdentifier"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"];
	Array *p = (Array *)nodeValue->context["DetailIdentifier"].get();
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]);
}


//DetailIdentifier : Identifier
void R001_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DetailIdentifier_1");
	Array *p = new Array();
	nodeValue->context["DetailIdentifier"] = P_Token(p);
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]);
}





/////////////////////////////////////////////////////////////////////////////////////////////////////
//类型

//UnannType : UnannPrimitiveType
void R001_UnannType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannType_0");
}


//UnannType : UnannClassOrInterfaceType
void R001_UnannType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannType_1");
}


//UnannType : UnannArrayType
void R001_UnannType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannType_2");
}


//UnannPrimitiveType : NumericType
void R001_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannPrimitiveType_0");
}


//UnannPrimitiveType : 'boolean'
void R001_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannPrimitiveType_1");
}


//NumericType : IntegralType
void R001_NumericType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NumericType_0");
}


//NumericType : FloatingPointType
void R001_NumericType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NumericType_1");
}


//IntegralType : 'byte'
void R001_IntegralType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IntegralType_0");
}


//IntegralType : 'short'
void R001_IntegralType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IntegralType_1");
}


//IntegralType : 'int'
void R001_IntegralType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IntegralType_2");
}


//IntegralType : 'long'
void R001_IntegralType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IntegralType_3");
}


//IntegralType : 'char'
void R001_IntegralType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_IntegralType_4");
}


//FloatingPointType : 'float'
void R001_FloatingPointType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_FloatingPointType_0");
}


//FloatingPointType : 'double'
void R001_FloatingPointType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_FloatingPointType_1");
}


//UnannClassOrInterfaceType : UnannClassType 'SPOT' UnannClassOrInterfaceType
void R001_UnannClassOrInterfaceType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannClassOrInterfaceType_0");
}


//UnannClassOrInterfaceType : UnannClassType 'SPOT' AnnotationList UnannClassOrInterfaceType
void R001_UnannClassOrInterfaceType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannClassOrInterfaceType_1");
}


//UnannClassOrInterfaceType : UnannClassType
void R001_UnannClassOrInterfaceType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannClassOrInterfaceType_2");
}


//UnannClassType : Identifier
void R001_UnannClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannClassType_0");
}


//UnannClassType : Identifier TypeArguments
void R001_UnannClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannClassType_1");
}


//UnannArrayType : UnannPrimitiveType Dims
void R001_UnannArrayType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannArrayType_0");
}


//UnannArrayType : UnannClassOrInterfaceType Dims
void R001_UnannArrayType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_UnannArrayType_1");
}



//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
void R001_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArguments_0");
}


//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
void R001_TypeArguments_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArguments_1");
}


//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
void R001_TypeArguments_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArguments_2");
}


//TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R001_TypeArguments_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArguments_3");
}


//TypeArgumentListL2 : TypeArguments TypeArgumentListL2
void R001_TypeArgumentListL2_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL2_0");
}


//TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
void R001_TypeArgumentListL2_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL2_1");
}


//TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
void R001_TypeArgumentListL2_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL2_2");
}


//TypeArgumentListL1 : TypeArguments TypeArgumentListL1
void R001_TypeArgumentListL1_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL1_0");
}


//TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
void R001_TypeArgumentListL1_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL1_1");
}


//TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
void R001_TypeArgumentListL1_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentListL1_2");
}


//TypeArgumentList : TypeArguments TypeArgumentList
void R001_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentList_0");
}


//TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R001_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentList_1");
}


//TypeArgumentList : 0
void R001_TypeArgumentList_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeArgumentList_2");
}


//NonANGLE_BRACKET : 'QUESTION'
void R001_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_0");
}


//NonANGLE_BRACKET : 'extends'
void R001_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_1");
}


//NonANGLE_BRACKET : 'super'
void R001_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_2");
}


//NonANGLE_BRACKET : 'COMMA'
void R001_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_3");
}


//NonANGLE_BRACKET : Identifier
void R001_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_4");
}


//NonANGLE_BRACKET : UnannPrimitiveType
void R001_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_5");
}


//NonANGLE_BRACKET : 'SPOT'
void R001_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_6");
}


//NonANGLE_BRACKET : 'LEFT_BRACKET'
void R001_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_7");
}


//NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R001_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonANGLE_BRACKET_8");
}





//ele_begin : CompilationUnit
void R001_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_begin_0");
}

//TypeDeclaration : 'semicolon'
void R001_TypeDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclaration_2");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Package


//CompilationUnit : PackageDeclaration
void R001_CompilationUnit_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_0");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->import_class_list = P_Token(new Array());
	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;

}


//CompilationUnit : ImportDeclarationList
void R001_CompilationUnit_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_1");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);
	p->import_class_list = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : PackageDeclaration ImportDeclarationList
void R001_CompilationUnit_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_3");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);
	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
	p->import_class_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : TypeDeclarationList
void R001_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_2Analyzer");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->import_class_list = P_Token(new Array());
	p->type_declaration_list = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);

}


//CompilationUnit : PackageDeclaration TypeDeclarationList
void R001_CompilationUnit_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_4");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
	p->import_class_list = P_Token(new Array());
	p->type_declaration_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : ImportDeclarationList TypeDeclarationList
void R001_CompilationUnit_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_5");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->import_class_list = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclarationList"];
	p->type_declaration_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
void R001_CompilationUnit_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_6");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
	p->import_class_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];
	p->type_declaration_list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}



//TypeDeclarationList : TypeDeclaration TypeDeclarationList
void R001_TypeDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclarationList_0");
	nodeValue->context["TypeDeclarationList"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	Array * p = (Array *)(nodeValue->context["TypeDeclarationList"].get());
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"]);
}


//TypeDeclarationList : TypeDeclaration
void R001_TypeDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclarationList_1Analyzer");
	Array *p = new Array();
	nodeValue->context["TypeDeclarationList"] = P_Token(p);
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclaration"]);
}


//TypeDeclaration : ClassDeclaration
void R001_TypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclaration_0Analyzer");
	nodeValue->context["TypeDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
}

//TypeDeclaration : InterfaceDeclaration
void R001_TypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_TypeDeclaration_1");
	nodeValue->context["TypeDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];
}


//ClassDeclaration : NormalClassDeclaration
void R001_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassDeclaration_0Analyzer");
	nodeValue->context["ClassDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
}



//PackageDeclaration : AnnotationList 'package' DetailIdentifier 'semicolon'
void R001_PackageDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_PackageDeclaration_0");
	Array *arr = (Array*)nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"].get();
	nodeValue->context["PackageDeclaration"] = P_Token(new Token("string", getPackageName(arr), 0));
}


//PackageDeclaration : 'package' DetailIdentifier 'semicolon'
void R001_PackageDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_PackageDeclaration_1");
	Array *arr = (Array*)nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"].get();
	nodeValue->context["PackageDeclaration"] = P_Token(new Token("string", getPackageName(arr), 0));
}



//ImportDeclaration : 'import' DetailIdentifier 'semicolon'
void R001_ImportDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclaration_0");

	Array * p = (Array *)(nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"].get());
	ostringstream sb;
	for (int i1 = 0; i1 < p->list.size(); i1++) {
		sb << p->list[i1]->content;
		if (i1 != (p->list.size() - 1)) {
			sb << ".";
		}
	}
	Import *p1 = new Import();
	nodeValue->context["ImportDeclaration"] = P_Token(p1);
	p1->name = sb.str();
	p1->isSingle = 1;
	p1->isStatic = 0;
}


//ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
void R001_ImportDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclaration_1");

	Array * p = (Array *)(nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"].get());
	ostringstream sb;
	for (int i1 = 0; i1 < p->list.size(); i1++) {
		sb << p->list[i1]->content;
		if (i1 != (p->list.size() - 1)) {
			sb << ".";
		}
	}
	Import *p1 = new Import();
	nodeValue->context["ImportDeclaration"] = P_Token(p1);
	p1->name = sb.str();
	p1->isSingle = 1;
	p1->isStatic = 1;
}


//ImportDeclaration : 'import' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
void R001_ImportDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclaration_2");

	Array * p = (Array *)(nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"].get());
	ostringstream sb;
	for (int i1 = 0; i1 < p->list.size(); i1++) {
		sb << p->list[i1]->content;
		if (i1 != (p->list.size() - 1)) {
			sb << ".";
		}
	}
	Import *p1 = new Import();
	nodeValue->context["ImportDeclaration"] = P_Token(p1);
	p1->name = sb.str();
	p1->isSingle = 0;
	p1->isStatic = 0;
}


//ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT' 'STAR' 'semicolon'
void R001_ImportDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclaration_3");
	Array * p = (Array *)(nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"].get());
	ostringstream sb;
	for (int i1 = 0; i1 < p->list.size(); i1++) {
		sb << p->list[i1]->content;
		if (i1 != (p->list.size() - 1)) {
			sb << ".";
		}
	}
	Import *p1 = new Import();
	nodeValue->context["ImportDeclaration"] = P_Token(p1);
	p1->name = sb.str();
	p1->isSingle = 0;
	p1->isStatic = 1;
}



//ImportDeclarationList : ImportDeclaration ImportDeclarationList
void R001_ImportDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclarationList_0");
	Array *p = (Array *)(nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"].get());
	logR001("a");
	nodeValue->context["ImportDeclarationList"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ImportDeclarationList"];
	logR001("b");
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclaration"]);
	logR001("c");
}


//ImportDeclarationList : ImportDeclaration
void R001_ImportDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ImportDeclarationList_1");
	Array *p = new Array();
	nodeValue->context["ImportDeclarationList"] = P_Token(p);
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ImportDeclaration"]);
}






//修饰符

//ModifierList : Modifier ModifierList
void R001_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ModifierList_0");
}


//ModifierList : Modifier
void R001_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ModifierList_1");
}


//Modifier : Annotation
void R001_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_0");
}


//Modifier : 'public'
void R001_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_1");
}


//Modifier : 'protected'
void R001_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_2");
}


//Modifier : 'private'
void R001_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_3");
}


//Modifier : 'abstract'
void R001_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_4");
}


//Modifier : 'static'
void R001_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_5");
}


//Modifier : 'final'
void R001_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_6");
}


//Modifier : 'strictfp'
void R001_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_7");
}


//Modifier : 'default'
void R001_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_8");
}


//Modifier : 'volatile'
void R001_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_9");
}


//Modifier : 'synchronized'
void R001_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_10");
}


//Modifier : 'transient'
void R001_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_11");
}


//Modifier : 'native'
void R001_Modifier_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Modifier_12");
}



//AnnotationList : Annotation AnnotationList
void R001_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationList_0");
}


//AnnotationList : Annotation
void R001_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationList_1");
}


//Annotation : NormalAnnotation
void R001_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Annotation_0");
}


//Annotation : MarkerAnnotation
void R001_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Annotation_1");
}


//Annotation : SingleElementAnnotation
void R001_Annotation_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Annotation_2");
}


//MarkerAnnotation : 'AT' DetailIdentifier
void R001_MarkerAnnotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MarkerAnnotation_0");
}


//NormalAnnotation : 'AT' DetailIdentifier AnnotationContent
void R001_NormalAnnotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalAnnotation_0");
}


//AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R001_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContent_0");
}


//AnnotationContentStatements : AnnotationContent AnnotationContentStatements
void R001_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_0");
}


//AnnotationContentStatements : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' AnnotationContentStatements
void R001_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_1");
}


//AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R001_AnnotationContentStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_2");
}


//AnnotationContentStatements : NonPARENTHESES
void R001_AnnotationContentStatements_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_3");
}


//AnnotationContentStatements : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
void R001_AnnotationContentStatements_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_4");
}


//AnnotationContentStatements : AnnotationContent
void R001_AnnotationContentStatements_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationContentStatements_5");
}


//NonPARENTHESES : StatementEle
void R001_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_0");
}


//NonPARENTHESES : 'COMMA'
void R001_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_1");
}


//NonPARENTHESES : 'semicolon'
void R001_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_2");
}


//NonPARENTHESES : 'LEFT_BRACE'
void R001_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_3");
}


//NonPARENTHESES : 'LEFT_BRACKET'
void R001_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_4");
}


//NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R001_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_5");
}


//NonPARENTHESES : 'RIGHT_BRACE'
void R001_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_6");
}


//NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R001_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_7");
}


//NonPARENTHESES : 'RIGHT_BRACKET'
void R001_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_8");
}


//NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R001_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonPARENTHESES_9");
}


//ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_ClassBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBody_0Analyzer");
	nodeValue->context["ClassBody"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}


//ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
void R001_ClassBodyDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_0Analyzer");
	nodeValue->context["ClassBodyDeclarationList"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
	Array * p = (Array *)(nodeValue->context["ClassBodyDeclarationList"].get());
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassBodyDeclaration"]);
}

//ClassBodyDeclarationList : 0
void R001_ClassBodyDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclarationList_1Analyzer");
	nodeValue->context["ClassBodyDeclarationList"] = P_Token(new Array());
}



//ClassMemberDeclaration : MethodDeclaration
void R001_ClassMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_1");
	nodeValue->context["ClassMemberDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodDeclaration"];
}


//ClassBodyDeclaration : ClassMemberDeclaration
void R001_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclaration_0Analyzer");
	nodeValue->context["ClassBodyDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassMemberDeclaration"];
}


//ClassMemberDeclaration : ClassDeclaration
void R001_ClassMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_2Analyzer");
	nodeValue->context["ClassMemberDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
}

//ClassMemberDeclaration : InterfaceDeclaration
void R001_ClassMemberDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_3");
	nodeValue->context["ClassMemberDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];
}



//InterfaceDeclaration : NormalInterfaceDeclaration
void R001_InterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_InterfaceDeclaration_0");
	nodeValue->context["InterfaceDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalInterfaceDeclaration"];
}


//NormalInterfaceDeclaration : 'interface' Identifier ClassBody
void R001_NormalInterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_0");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : ModifierList 'interface' Identifier ClassBody
void R001_NormalInterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_1");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}




//NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ClassBody
void R001_NormalInterfaceDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_2");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ClassBody
void R001_NormalInterfaceDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_3");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : 'interface' Identifier 'extends' InterfaceTypeList ClassBody
void R001_NormalInterfaceDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_4");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : ModifierList 'interface' Identifier 'extends' InterfaceTypeList ClassBody
void R001_NormalInterfaceDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_5");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : 'interface' Identifier TypeArguments 'extends' InterfaceTypeList ClassBody
void R001_NormalInterfaceDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_6");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments 'extends' InterfaceTypeList ClassBody
void R001_NormalInterfaceDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalInterfaceDeclaration_7");

	Class *p = new Class();
	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalInterfaceDeclaration";
}


//InterfaceDeclaration : AnnotationTypeDeclaration
void R001_InterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_InterfaceDeclaration_1");
	nodeValue->context["InterfaceDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeDeclaration"];
}


//AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier AnnotationTypeBody
void R001_AnnotationTypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeDeclaration_0");
	Class *p = new Class();
	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationTypeBody"];
	p->classType = "AnnotationTypeDeclaration";
}


//AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier AnnotationTypeBody
void R001_AnnotationTypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeDeclaration_1");
	Class *p = new Class();
	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["AnnotationTypeBody"];
	p->classType = "AnnotationTypeDeclaration";
}


//AnnotationTypeMemberDeclaration : ClassDeclaration
void R001_AnnotationTypeMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclaration_2");
	nodeValue->context["AnnotationTypeMemberDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];
}


//AnnotationTypeMemberDeclarationList : AnnotationTypeMemberDeclaration AnnotationTypeMemberDeclarationList
void R001_AnnotationTypeMemberDeclarationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclarationList_0");

	nodeValue->context["AnnotationTypeMemberDeclarationList"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["AnnotationTypeMemberDeclarationList"];
	Array * p = (Array *)(nodeValue->context["AnnotationTypeMemberDeclarationList"].get());
	p->list.push_front(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeMemberDeclaration"]);

}


//AnnotationTypeMemberDeclarationList : 0
void R001_AnnotationTypeMemberDeclarationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclarationList_1");
	nodeValue->context["AnnotationTypeMemberDeclarationList"] = P_Token(new Array());
}



//AnnotationTypeBody : 'LEFT_BRACE' AnnotationTypeMemberDeclarationList 'RIGHT_BRACE'
void R001_AnnotationTypeBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeBody_0");
	nodeValue->context["AnnotationTypeBody"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["AnnotationTypeMemberDeclarationList"];
}



//EnumBody : 'LEFT_BRACE' 'RIGHT_BRACE'
void R001_EnumBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_0");
	nodeValue->context["EnumBody"] = P_Token(new Array());
}



//EnumBody : 'LEFT_BRACE' EnumConstantList 'RIGHT_BRACE'
void R001_EnumBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_1");
	nodeValue->context["EnumBody"] = P_Token(new Array());
}


//EnumBody : 'LEFT_BRACE' 'COMMA_RIGHT_BRACE'
void R001_EnumBody_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_2");
	nodeValue->context["EnumBody"] = P_Token(new Array());
}


//EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA_RIGHT_BRACE'
void R001_EnumBody_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_3");
	nodeValue->context["EnumBody"] = P_Token(new Array());
}


//EnumBody : 'LEFT_BRACE' 'semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_EnumBody_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_4");
	nodeValue->context["EnumBody"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}


//EnumBody : 'LEFT_BRACE' EnumConstantList 'semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_EnumBody_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_5");
	nodeValue->context["EnumBody"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}


//EnumBody : 'LEFT_BRACE' 'COMMA_semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_EnumBody_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_6");
	nodeValue->context["EnumBody"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}


//EnumBody : 'LEFT_BRACE' EnumConstantList 'COMMA_semicolon' ClassBodyDeclarationList 'RIGHT_BRACE'
void R001_EnumBody_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumBody_7");
	nodeValue->context["EnumBody"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBodyDeclarationList"];
}





//InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
void R001_InterfaceTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_InterfaceTypeList_0");
}


//InterfaceTypeList : ClassType
void R001_InterfaceTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_InterfaceTypeList_1");
}


//ClassType : ClassType 'SPOT' ClassTypeUnit
void R001_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassType_0");
}


//ClassType : ClassTypeUnit
void R001_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassType_1");
}


//ClassTypeUnit : Identifier
void R001_ClassTypeUnit_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassTypeUnit_0");
}


//ClassTypeUnit : Identifier TypeArguments
void R001_ClassTypeUnit_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassTypeUnit_1");
}


//ClassTypeUnit : AnnotationList Identifier
void R001_ClassTypeUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassTypeUnit_2");
}


//ClassTypeUnit : AnnotationList Identifier TypeArguments
void R001_ClassTypeUnit_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassTypeUnit_3");
}




//ClassBodyDeclaration : InstanceInitializer
void R001_ClassBodyDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclaration_1");
}


//ClassBodyDeclaration : StaticInitializer
void R001_ClassBodyDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassBodyDeclaration_2");
}


//ClassMemberDeclaration : FieldDeclaration
void R001_ClassMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_0");
}




//ClassMemberDeclaration : 'semicolon'
void R001_ClassMemberDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassMemberDeclaration_4");
}


//InstanceInitializer : Block
void R001_InstanceInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_InstanceInitializer_0");
}


//StaticInitializer : 'static' Block
void R001_StaticInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StaticInitializer_0");
}


//FieldDeclaration : UnannType VariableDeclaratorList 'semicolon'
void R001_FieldDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_FieldDeclaration_0");
}


//FieldDeclaration : ModifierList UnannType VariableDeclaratorList 'semicolon'
void R001_FieldDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_FieldDeclaration_1");
}





//EnumConstantList : MethodDeclarator 'COMMA' EnumConstantList
void R001_EnumConstantList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumConstantList_0");
}


//EnumConstantList : Identifier 'COMMA' EnumConstantList
void R001_EnumConstantList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumConstantList_1");
}


//EnumConstantList : MethodDeclarator
void R001_EnumConstantList_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumConstantList_2");
}


//EnumConstantList : Identifier
void R001_EnumConstantList_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumConstantList_3");
}


//AnnotationTypeMemberDeclaration : AnnotationTypeElementDeclaration
void R001_AnnotationTypeMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclaration_0");
}


//AnnotationTypeMemberDeclaration : FieldDeclaration
void R001_AnnotationTypeMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclaration_1");
}





//AnnotationTypeMemberDeclaration : InterfaceDeclaration
void R001_AnnotationTypeMemberDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclaration_3");
}


//AnnotationTypeMemberDeclaration : 'semicolon'
void R001_AnnotationTypeMemberDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeMemberDeclaration_4");
}


//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' 'semicolon'
void R001_AnnotationTypeElementDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_0");
}


//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' 'semicolon'
void R001_AnnotationTypeElementDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_1");
}


//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims 'semicolon'
void R001_AnnotationTypeElementDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_2");
}


//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims 'semicolon'
void R001_AnnotationTypeElementDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_3");
}


//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' DefaultValue 'semicolon'
void R001_AnnotationTypeElementDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_4");
}


//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' DefaultValue 'semicolon'
void R001_AnnotationTypeElementDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_5");
}


//AnnotationTypeElementDeclaration : UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims DefaultValue 'semicolon'
void R001_AnnotationTypeElementDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_6");
}


//AnnotationTypeElementDeclaration : ModifierList UnannType Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims DefaultValue 'semicolon'
void R001_AnnotationTypeElementDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_AnnotationTypeElementDeclaration_7");
}


//NormalClassDeclaration : 'class' Identifier ClassBody
void R001_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_0Analyzer");
	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}



//NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
void R001_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_1Analyzer");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}



//NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
void R001_NormalClassDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_2");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";


}


//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
void R001_NormalClassDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_3");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";


}


//NormalClassDeclaration : 'class' Identifier 'extends' ClassType ClassBody
void R001_NormalClassDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_4");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : ModifierList 'class' Identifier 'extends' ClassType ClassBody
void R001_NormalClassDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_5");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";

}


//NormalClassDeclaration : 'class' Identifier TypeArguments 'extends' ClassType ClassBody
void R001_NormalClassDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_6");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'extends' ClassType ClassBody
void R001_NormalClassDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_7");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : 'class' Identifier 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_8");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : ModifierList 'class' Identifier 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_9");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";

}


//NormalClassDeclaration : 'class' Identifier TypeArguments 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_10");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_11");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : 'class' Identifier 'extends' ClassType 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_12");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 6, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";
}


//NormalClassDeclaration : ModifierList 'class' Identifier 'extends' ClassType 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_13");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 7, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";

}


//NormalClassDeclaration : 'class' Identifier TypeArguments 'extends' ClassType 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_14");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 7, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";

}


//NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments 'extends' ClassType 'implements' InterfaceTypeList ClassBody
void R001_NormalClassDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NormalClassDeclaration_15");

	Class *p = new Class();
	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->list = nodeValueMap[child(nodeValue, 8, NodeValue::SYN)]->context["ClassBody"];
	p->classType = "NormalClassDeclaration";

}


//EnumDeclaration : 'enum' Identifier EnumBody
void R001_EnumDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumDeclaration_0");

	Class *p = new Class();
	nodeValue->context["EnumDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->classType = "EnumDeclaration";
	p->list = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["EnumBody"];
}


//EnumDeclaration : ModifierList 'enum' Identifier EnumBody
void R001_EnumDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumDeclaration_1");

	Class *p = new Class();
	nodeValue->context["EnumDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->classType = "EnumDeclaration";
	p->list = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["EnumBody"];
}


//EnumDeclaration : 'enum' Identifier  'implements' InterfaceTypeList EnumBody
void R001_EnumDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumDeclaration_2");

	Class *p = new Class();
	nodeValue->context["EnumDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"]->content;
	p->classType = "EnumDeclaration";
	p->list = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["EnumBody"];
}


//EnumDeclaration : ModifierList 'enum' Identifier 'implements' InterfaceTypeList EnumBody
void R001_EnumDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_EnumDeclaration_3");

	Class *p = new Class();
	nodeValue->context["EnumDeclaration"] = P_Token(p);
	p->className = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"]->content;
	p->classType = "EnumDeclaration";
	p->list = nodeValueMap[child(nodeValue, 5, NodeValue::SYN)]->context["EnumBody"];
}


//ClassDeclaration : EnumDeclaration
void R001_ClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ClassDeclaration_1");
	nodeValue->context["ClassDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumDeclaration"];
}





//DefaultValue : 'default' ElementValue
void R001_DefaultValue_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DefaultValue_0");
}


//ElementValue : Expression
void R001_ElementValue_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ElementValue_0");
}


//ElementValue : Annotation
void R001_ElementValue_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ElementValue_1");
}




//VariableDeclaratorList : VariableDeclarator 'COMMA' VariableDeclaratorList
void R001_VariableDeclaratorList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclaratorList_0");
}


//VariableDeclaratorList : VariableDeclarator
void R001_VariableDeclaratorList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclaratorList_1");
}


//VariableDeclarator : VariableDeclaratorId
void R001_VariableDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclarator_0");
}


//VariableDeclarator : VariableDeclaratorId 'EQUAL' Expression
void R001_VariableDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclarator_1");
}


//VariableDeclaratorId : Identifier Dims
void R001_VariableDeclaratorId_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclaratorId_0");
}


//VariableDeclaratorId : Identifier
void R001_VariableDeclaratorId_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_VariableDeclaratorId_1");
}


//MethodDeclarator : Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
void R001_MethodDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclarator_0");
	Method *p = new Method();
	p->methodName = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]->content;
	nodeValue->context["MethodDeclarator"] = P_Token(p);
}


//MethodDeclarator : Identifier 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES' Dims
void R001_MethodDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclarator_1");
	Method *p = new Method();
	p->methodName = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]->content;
	nodeValue->context["MethodDeclarator"] = P_Token(p);
}


//MethodDeclarator : Identifier AnnotationContent
void R001_MethodDeclarator_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclarator_2");
	Method *p = new Method();
	p->methodName = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]->content;
	nodeValue->context["MethodDeclarator"] = P_Token(p);
}


//MethodDeclarator : Identifier AnnotationContent Dims
void R001_MethodDeclarator_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclarator_3");
	Method *p = new Method();
	p->methodName = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"]->content;
	nodeValue->context["MethodDeclarator"] = P_Token(p);
}




//MethodHeader : UnannType MethodDeclarator
void R001_MethodHeader_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_0");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : UnannType MethodDeclarator Throws
void R001_MethodHeader_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_1");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments UnannType MethodDeclarator
void R001_MethodHeader_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_2");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments UnannType MethodDeclarator Throws
void R001_MethodHeader_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_3");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList UnannType MethodDeclarator
void R001_MethodHeader_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_4");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList UnannType MethodDeclarator Throws
void R001_MethodHeader_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_5");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : 'void' MethodDeclarator
void R001_MethodHeader_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_6");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : 'void' MethodDeclarator Throws
void R001_MethodHeader_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_7");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments 'void' MethodDeclarator
void R001_MethodHeader_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_8");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments 'void' MethodDeclarator Throws
void R001_MethodHeader_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_9");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList 'void' MethodDeclarator
void R001_MethodHeader_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_10");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList 'void' MethodDeclarator Throws
void R001_MethodHeader_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_11");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : MethodDeclarator
void R001_MethodHeader_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_12");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : MethodDeclarator Throws
void R001_MethodHeader_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_13");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments MethodDeclarator
void R001_MethodHeader_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_14");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments MethodDeclarator Throws
void R001_MethodHeader_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_15");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList MethodDeclarator
void R001_MethodHeader_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_16");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodHeader : TypeArguments AnnotationList MethodDeclarator Throws
void R001_MethodHeader_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodHeader_17");
	nodeValue->context["MethodHeader"] = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];
}


//MethodDeclaration : MethodHeader MethodBody
void R001_MethodDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclaration_0");
	nodeValue->context["MethodDeclaration"] = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodHeader"];
	Method * p = (Method *)(nodeValue->context["MethodDeclaration"].get());
	Block * p2 = (Block *)(nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodBody"].get());
	p->bodyBeg = p2->beg;
	p->bodyEnd = p2->end;
	p->bodyBegLine = p2->lineBeg;
	p->bodyEndLine = p2->lineEnd;
}


//MethodDeclaration : ModifierList MethodHeader MethodBody
void R001_MethodDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodDeclaration_1");
	nodeValue->context["MethodDeclaration"] = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodHeader"];
	Method * p = (Method *)(nodeValue->context["MethodDeclaration"].get());
	Block * p2 = (Block *)(nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodBody"].get());
	//P_Token  p2 = (P_Token)(nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodBody"].get());
	p->bodyBeg = p2->beg;
	p->bodyEnd = p2->end;
	p->bodyBegLine = p2->lineBeg;
	p->bodyEndLine = p2->lineEnd;
}

//MethodDeclaration : MethodHeader MethodBody
//MethodDeclaration : ModifierList MethodHeader MethodBody


//方法体

//MethodBody : 'semicolon'
void R001_MethodBody_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodBody_1");
}



//Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R001_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Block_0");
	Block *p1 = new Block();
	nodeValue->context["Block"] = P_Token(p1);
	p1->beg = nodeValue->node->child_node_list[0]->index;
	p1->end = nodeValue->node->child_node_list[2]->index;
	p1->lineBeg=nodeValue->node->child_node_list[0]->lineNum;
	p1->lineEnd= nodeValue->node->child_node_list[2]->lineNum;
}


//Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
void R001_Block_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Block_1");
	Block *p1 = new Block();
	nodeValue->context["Block"] = P_Token(p1);
	p1->beg = nodeValue->node->child_node_list[0]->index;
	p1->end = nodeValue->node->child_node_list[2]->index;
	p1->lineBeg = nodeValue->node->child_node_list[0]->lineNum;
	p1->lineEnd = nodeValue->node->child_node_list[2]->lineNum;
}



//MethodBody : Block
void R001_MethodBody_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_MethodBody_0");
	Block * p = (Block *)(nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Block"].get());
	Block *p1 = new Block();
	p1->beg = p->beg;
	p1->end = p->end;
	p1->lineBeg = p->lineBeg;
	p1->lineEnd = p->lineEnd;
	nodeValue->context["MethodBody"] = P_Token(p1);
}





//BlockStatements : Block BlockStatements
void R001_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_BlockStatements_0");
}


//BlockStatements : NonBrace BlockStatements
void R001_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_BlockStatements_1");
}


//BlockStatements : 0
void R001_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_BlockStatements_2");
}


//NonBrace : StatementEle
void R001_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_0");
}


//NonBrace : 'COMMA'
void R001_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_1");
}


//NonBrace : 'semicolon'
void R001_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_2");
}


//NonBrace : 'LEFT_ANGLE_BRACKET'
void R001_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_3");
}


//NonBrace : 'LEFT_BRACKET'
void R001_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_4");
}


//NonBrace : 'LEFT_PARENTHESES'
void R001_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_5");
}


//NonBrace : 'RIGHT_ANGLE_BRACKET'
void R001_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_6");
}


//NonBrace : 'RIGHT_BRACKET'
void R001_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_7");
}


//NonBrace : 'RIGHT_PARENTHESES'
void R001_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonBrace_8");
}


//StatementEle : 'IDENTIFIER'
void R001_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_0");
}


//StatementEle : 'AND'
void R001_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_1");
}


//StatementEle : 'AND_EQUAL'
void R001_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_2");
}


//StatementEle : 'AT'
void R001_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_3");
}


//StatementEle : 'AT_INTERFACE'
void R001_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_4");
}


//StatementEle : 'BIT_AND'
void R001_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_5");
}


//StatementEle : 'BIT_OR'
void R001_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_6");
}


//StatementEle : 'BooleanLiteral'
void R001_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_7");
}


//StatementEle : 'CARET'
void R001_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_8");
}


//StatementEle : 'COLON'
void R001_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_9");
}


//StatementEle : 'CharacterLiteral'
void R001_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_10");
}


//StatementEle : 'DB_EQUAL'
void R001_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_11");
}


//StatementEle : 'DIVIDE_EQUAL'
void R001_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_12");
}


//StatementEle : 'EQUAL'
void R001_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_13");
}


//StatementEle : 'FloatingPointLiteral'
void R001_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_14");
}


//StatementEle : 'GT_EQUAL'
void R001_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_15");
}


//StatementEle : 'IntegerLiteral'
void R001_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_16");
}


//StatementEle : 'LAMBDA_TO'
void R001_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_17");
}


//StatementEle : 'LEFT_SHIFT'
void R001_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_18");
}


//StatementEle : 'LEFT_SHIFT_EQUAL'
void R001_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_19");
}


//StatementEle : 'LT_EQUAL'
void R001_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_20");
}


//StatementEle : 'MULTI_EQUAL'
void R001_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_21");
}


//StatementEle : 'NOT_EQUAL'
void R001_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_22");
}


//StatementEle : 'OR'
void R001_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_23");
}


//StatementEle : 'OR_EQUAL'
void R001_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_24");
}


//StatementEle : 'PLUS'
void R001_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_25");
}


//StatementEle : 'PLUS_EQUAL'
void R001_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_26");
}


//StatementEle : 'PRECENTAGE'
void R001_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_27");
}


//StatementEle : 'PRECENTAGE_EQUAL'
void R001_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_28");
}


//StatementEle : 'PackageOrTypeNameId'
void R001_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_29");
}


//StatementEle : 'QUESTION'
void R001_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_30");
}


//StatementEle : 'RIGHT_SHIFT'
void R001_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_31");
}


//StatementEle : 'RIGHT_SHIFT2'
void R001_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_32");
}


//StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R001_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_33");
}


//StatementEle : 'RIGHT_SHIFT_EQUAL'
void R001_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_34");
}


//StatementEle : 'RIGTH_BRACKET'
void R001_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_35");
}


//StatementEle : 'SLASH'
void R001_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_36");
}


//StatementEle : 'SPOT'
void R001_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_37");
}


//StatementEle : 'STAR'
void R001_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_38");
}


//StatementEle : 'SUBTRACT'
void R001_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_39");
}


//StatementEle : 'SUBTRACT_EQUAL'
void R001_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_40");
}


//StatementEle : 'SURPRISE'
void R001_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_41");
}


//StatementEle : 'StringLiteral'
void R001_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_42");
}


//StatementEle : 'THREE_SPOT'
void R001_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_43");
}


//StatementEle : 'TILDE'
void R001_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_44");
}


//StatementEle : 'TWO_COLON'
void R001_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_45");
}


//StatementEle : 'TWO_PLUS'
void R001_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_46");
}


//StatementEle : 'TWO_SUBTRACT'
void R001_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_47");
}


//StatementEle : 'TypeNameId'
void R001_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_48");
}


//StatementEle : 'XOR_EQUAL'
void R001_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_49");
}


//StatementEle : 'abstract'
void R001_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_50");
}


//StatementEle : 'boolean'
void R001_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_51");
}


//StatementEle : 'byte'
void R001_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_52");
}


//StatementEle : 'char'
void R001_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_53");
}


//StatementEle : 'class'
void R001_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_54");
}


//StatementEle : 'default'
void R001_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_55");
}


//StatementEle : 'double'
void R001_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_56");
}


//StatementEle : 'enum'
void R001_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_57");
}


//StatementEle : 'extends'
void R001_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_58");
}


//StatementEle : 'final'
void R001_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_59");
}


//StatementEle : 'float'
void R001_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_60");
}


//StatementEle : 'implements'
void R001_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_61");
}


//StatementEle : 'instanceof'
void R001_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_62");
}


//StatementEle : 'int'
void R001_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_63");
}


//StatementEle : 'interface'
void R001_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_64");
}


//StatementEle : 'long'
void R001_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_65");
}


//StatementEle : 'native'
void R001_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_66");
}


//StatementEle : 'new'
void R001_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_67");
}


//StatementEle : 'null'
void R001_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_68");
}


//StatementEle : 'private'
void R001_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_69");
}


//StatementEle : 'protected'
void R001_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_70");
}


//StatementEle : 'public'
void R001_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_71");
}


//StatementEle : 'short'
void R001_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_72");
}


//StatementEle : 'static'
void R001_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_73");
}


//StatementEle : 'super'
void R001_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_74");
}


//StatementEle : 'synchronized'
void R001_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_75");
}


//StatementEle : 'this'
void R001_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_76");
}


//StatementEle : 'throws'
void R001_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_77");
}


//StatementEle : 'transient'
void R001_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_78");
}


//StatementEle : 'void'
void R001_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_79");
}


//StatementEle : 'volatile'
void R001_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_StatementEle_80");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//数组

//DimExpr : 'LEFT_BRACKET' DimStatements 'RIGHT_BRACKET'
void R001_DimExpr_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DimExpr_0");
}


//DimStatements : DimExpr DimStatements
void R001_DimStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DimStatements_0");
}


//DimStatements : NonDim DimStatements
void R001_DimStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DimStatements_1");
}


//DimStatements : 0
void R001_DimStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_DimStatements_2");
}


//NonDim : StatementEle
void R001_NonDim_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_0");
}


//NonDim : 'COMMA'
void R001_NonDim_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_1");
}


//NonDim : 'semicolon'
void R001_NonDim_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_2");
}


//NonDim : 'LEFT_BRACE'
void R001_NonDim_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_3");
}


//NonDim : 'LEFT_PARENTHESES'
void R001_NonDim_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_4");
}


//NonDim : 'LEFT_ANGLE_BRACKET'
void R001_NonDim_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_5");
}


//NonDim : 'RIGHT_BRACE'
void R001_NonDim_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_6");
}


//NonDim : 'COMMA_RIGHT_BRACE'
void R001_NonDim_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_7");
}


//NonDim : 'RIGHT_PARENTHESES'
void R001_NonDim_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_8");
}


//NonDim : 'RIGHT_ANGLE_BRACKET'
void R001_NonDim_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_NonDim_9");
}


//Dims : Dim Dims
void R001_Dims_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Dims_0");
}


//Dims : Dim
void R001_Dims_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Dims_1");
}


//Dim : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R001_Dim_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Dim_0");
}


//Dim : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R001_Dim_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Dim_1");
}

///////////////////////////////////////////////////////////////////////////////////////////
//表达式和statement


//Expression : ele Expression
void R001_Expression_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Expression_0");
}


//Expression : ele
void R001_Expression_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Expression_1");
}


//ele : StatementEle
void R001_ele_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_0");
}


//ele : AnnotationContent
void R001_ele_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_1");
}


//ele : 'LEFT_PARENTHESES' 'RIGHT_PARENTHESES'
void R001_ele_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_2");
}


//ele : DimExpr
void R001_ele_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_3");
}


//ele : Block
void R001_ele_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_4");
}


//ele : TypeArguments
void R001_ele_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ele_5");
}









//Throws : 'throws' ExceptionTypeList
void R001_Throws_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Throws_0");
}


//ExceptionTypeList : ClassType 'COMMA' ExceptionTypeList
void R001_ExceptionTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ExceptionTypeList_0");
}


//ExceptionTypeList : ClassType
void R001_ExceptionTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_ExceptionTypeList_1");
}

























/////////////////////////////////////////////////////////////////////////////////////////////////////










































