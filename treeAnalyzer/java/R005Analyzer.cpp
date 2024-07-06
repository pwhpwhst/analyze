#include "R005Analyzer.h"
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



#include <iostream>
#include <sstream>
using namespace std;

#include "R005Analyzer_1.h"

void logR005(const string& s) {
	//	Util::log(s);
}



P_NodeValue R005_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR005("R005_DefaultAnalyzer");
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

//beg_ele_begin : ClassBodyDeclaration 
void R005_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR005("R005_ele_begin_0Analyzer");
   P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassBodyDeclaration"];
   nodeValue->context["ele_begin"] = p0;

   env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_ClassBodyDeclaration : ClassMemberDeclaration
void R005_ClassBodyDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassMemberDeclaration"];
	nodeValue->context["ClassBodyDeclaration"] = P_Token(p0);
};



//beg_ClassBodyDeclaration : InstanceInitializer
void R005_ClassBodyDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclaration_1Analyzer");
	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "InstanceInitializer";
	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["ClassBodyDeclaration"] = P_Token(p);
};



//beg_ClassBodyDeclaration : StaticInitializer
void R005_ClassBodyDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclaration_2Analyzer");

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "StaticInitializer";
	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["ClassBodyDeclaration"] = P_Token(p);

};



//beg_ClassBodyDeclaration : ConstructorDeclaration
void R005_ClassBodyDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassBodyDeclaration_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ConstructorDeclaration"];

	((StatementToken*)(p0.get()))->statementEntity->type = "ConstructorDeclaration";

	nodeValue->context["ClassBodyDeclaration"] = p0;
};



//beg_ClassMemberDeclaration : MethodDeclaration
void R005_ClassMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodDeclaration"];
	nodeValue->context["ClassMemberDeclaration"] = p0;
};



//beg_ClassMemberDeclaration : ClassDeclaration
void R005_ClassMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];


	nodeValue->context["ClassMemberDeclaration"] = P_Token(p0);
};



//beg_ClassMemberDeclaration : InterfaceDeclaration
void R005_ClassMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_2Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];


	nodeValue->context["ClassMemberDeclaration"] = P_Token(p0);
};



//beg_ClassMemberDeclaration : FieldDeclaration
void R005_ClassMemberDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_3Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["FieldDeclaration"];
	nodeValue->context["ClassMemberDeclaration"] = p0;

};



//beg_ClassMemberDeclaration : FieldDeclarationFake
void R005_ClassMemberDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassMemberDeclaration_4Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["FieldDeclarationFake"];
	nodeValue->context["ClassMemberDeclaration"] = p0;
};


//beg_FieldDeclaration : ModifierList Result VariableDeclaratorList 'semicolon'
void R005_FieldDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FieldDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Result"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];



	((StatementToken *)(p2.get()))->statementEntity->type = "FieldDeclaration";

	for (auto &e : ((StatementToken *)(p2.get()))->statementEntity->fieldList) {
		e->isPrimitiveType = ((UnannTypeToken *)(p1.get()))->isPrimitive;
		e->dimNum += ((UnannTypeToken *)(p1.get()))->dimNum;
	}

	for (auto &e : ((StatementToken *)(p2.get()))->statementEntity->fieldList) {
		((UnannTypeToken *)(p1.get()))->dimNum = e->dimNum;
		e->unannType = ((UnannTypeToken *)(p1.get()))->getText();
	}


	nodeValue->context["FieldDeclaration"] = p2;
};




//beg_FieldDeclaration : Result VariableDeclaratorList 'semicolon'
void R005_FieldDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FieldDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Result"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p1.get()))->statementEntity->type = "FieldDeclaration";

	for (auto &e : ((StatementToken *)(p1.get()))->statementEntity->fieldList) {
		e->isPrimitiveType = ((UnannTypeToken *)(p0.get()))->isPrimitive;
		e->dimNum += ((UnannTypeToken *)(p0.get()))->dimNum;
	}

	for (auto &e : ((StatementToken *)(p1.get()))->statementEntity->fieldList) {
		((UnannTypeToken *)(p0.get()))->dimNum = e->dimNum;
		e->unannType = ((UnannTypeToken *)(p0.get()))->getText();
	}

	nodeValue->context["FieldDeclaration"] = p1;
};



//beg_FieldDeclarationFake : ModifierList Result VariableDeclaratorList
void R005_FieldDeclarationFake_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FieldDeclarationFake_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p2.get()))->statementEntity->type = "FieldDeclarationFake";

	nodeValue->context["FieldDeclarationFake"] = p2;
};


//beg_FieldDeclarationFake : Result VariableDeclaratorList
void R005_FieldDeclarationFake_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_FieldDeclarationFake_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p1.get()))->statementEntity->type = "FieldDeclarationFake";

	nodeValue->context["FieldDeclarationFake"] = p1;
};



//beg_InstanceInitializer : Block
void R005_InstanceInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InstanceInitializer_0Analyzer");
	//TO DO  R005_InstanceInitializer_0Analyzer
};



//beg_StaticInitializer : 'static' Block
void R005_StaticInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StaticInitializer_0Analyzer");
	//TO DO  R005_StaticInitializer_0Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R005_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Block_0Analyzer");
	//TO DO  R005_Block_0Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
void R005_Block_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Block_1Analyzer");
	//TO DO  R005_Block_1Analyzer
};



//beg_BlockStatements : Block BlockStatements
void R005_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_0Analyzer");
	//TO DO  R005_BlockStatements_0Analyzer
};



//beg_BlockStatements : NonBrace BlockStatements
void R005_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_1Analyzer");
	//TO DO  R005_BlockStatements_1Analyzer
};



//beg_BlockStatements : 0
void R005_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_BlockStatements_2Analyzer");
	//TO DO  R005_BlockStatements_2Analyzer
};



//beg_NonBrace : StatementEle
void R005_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_0Analyzer");
	//TO DO  R005_NonBrace_0Analyzer
};



//beg_NonBrace : 'COMMA'
void R005_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_1Analyzer");
	//TO DO  R005_NonBrace_1Analyzer
};



//beg_NonBrace : 'semicolon'
void R005_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_2Analyzer");
	//TO DO  R005_NonBrace_2Analyzer
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
void R005_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_3Analyzer");
	//TO DO  R005_NonBrace_3Analyzer
};



//beg_NonBrace : 'LEFT_BRACKET'
void R005_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_4Analyzer");
	//TO DO  R005_NonBrace_4Analyzer
};



//beg_NonBrace : 'LEFT_PARENTHESES'
void R005_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_5Analyzer");
	//TO DO  R005_NonBrace_5Analyzer
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
void R005_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_6Analyzer");
	//TO DO  R005_NonBrace_6Analyzer
};



//beg_NonBrace : 'RIGHT_BRACKET'
void R005_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_7Analyzer");
	//TO DO  R005_NonBrace_7Analyzer
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
void R005_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_8Analyzer");
	//TO DO  R005_NonBrace_8Analyzer
};



//beg_NonBrace : 'EQUAL'
void R005_NonBrace_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonBrace_9Analyzer");
	//TO DO  R005_NonBrace_9Analyzer
};



//beg_StatementEle : Identifier
void R005_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_0Analyzer");
	//TO DO  R005_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R005_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_1Analyzer");
	//TO DO  R005_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R005_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_2Analyzer");
	//TO DO  R005_StatementEle_2Analyzer
};



//beg_StatementEle : AnnotationList
void R005_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR005("R005_StatementEle_3Analyzer");
   //TO DO  R005_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R005_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_4Analyzer");
	//TO DO  R005_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R005_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_5Analyzer");
	//TO DO  R005_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R005_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_6Analyzer");
	//TO DO  R005_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R005_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_7Analyzer");
	//TO DO  R005_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R005_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_8Analyzer");
	//TO DO  R005_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R005_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_9Analyzer");
	//TO DO  R005_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R005_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_10Analyzer");
	//TO DO  R005_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R005_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_11Analyzer");
	//TO DO  R005_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R005_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_12Analyzer");
	//TO DO  R005_StatementEle_12Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R005_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_13Analyzer");
	//TO DO  R005_StatementEle_13Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R005_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_14Analyzer");
	//TO DO  R005_StatementEle_14Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R005_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_15Analyzer");
	//TO DO  R005_StatementEle_15Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R005_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_16Analyzer");
	//TO DO  R005_StatementEle_16Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R005_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_17Analyzer");
	//TO DO  R005_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R005_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_18Analyzer");
	//TO DO  R005_StatementEle_18Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R005_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_19Analyzer");
	//TO DO  R005_StatementEle_19Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R005_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_20Analyzer");
	//TO DO  R005_StatementEle_20Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R005_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_21Analyzer");
	//TO DO  R005_StatementEle_21Analyzer
};



//beg_StatementEle : 'OR'
void R005_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_22Analyzer");
	//TO DO  R005_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R005_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_23Analyzer");
	//TO DO  R005_StatementEle_23Analyzer
};



//beg_StatementEle : 'PLUS'
void R005_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_24Analyzer");
	//TO DO  R005_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R005_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_25Analyzer");
	//TO DO  R005_StatementEle_25Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R005_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_26Analyzer");
	//TO DO  R005_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R005_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_27Analyzer");
	//TO DO  R005_StatementEle_27Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R005_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_28Analyzer");
	//TO DO  R005_StatementEle_28Analyzer
};



//beg_StatementEle : 'QUESTION'
void R005_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_29Analyzer");
	//TO DO  R005_StatementEle_29Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R005_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_30Analyzer");
	//TO DO  R005_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R005_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_31Analyzer");
	//TO DO  R005_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R005_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_32Analyzer");
	//TO DO  R005_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R005_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_33Analyzer");
	//TO DO  R005_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R005_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_34Analyzer");
	//TO DO  R005_StatementEle_34Analyzer
};



//beg_StatementEle : 'SLASH'
void R005_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_35Analyzer");
	//TO DO  R005_StatementEle_35Analyzer
};



//beg_StatementEle : 'SPOT'
void R005_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_36Analyzer");
	//TO DO  R005_StatementEle_36Analyzer
};



//beg_StatementEle : 'STAR'
void R005_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_37Analyzer");
	//TO DO  R005_StatementEle_37Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R005_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_38Analyzer");
	//TO DO  R005_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R005_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_39Analyzer");
	//TO DO  R005_StatementEle_39Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R005_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_40Analyzer");
	//TO DO  R005_StatementEle_40Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R005_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_41Analyzer");
	//TO DO  R005_StatementEle_41Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R005_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_42Analyzer");
	//TO DO  R005_StatementEle_42Analyzer
};



//beg_StatementEle : 'TILDE'
void R005_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_43Analyzer");
	//TO DO  R005_StatementEle_43Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R005_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_44Analyzer");
	//TO DO  R005_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R005_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_45Analyzer");
	//TO DO  R005_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R005_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_46Analyzer");
	//TO DO  R005_StatementEle_46Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R005_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_47Analyzer");
	//TO DO  R005_StatementEle_47Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R005_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_48Analyzer");
	//TO DO  R005_StatementEle_48Analyzer
};



//beg_StatementEle : 'abstract'
void R005_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_49Analyzer");
	//TO DO  R005_StatementEle_49Analyzer
};



//beg_StatementEle : 'boolean'
void R005_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_50Analyzer");
	//TO DO  R005_StatementEle_50Analyzer
};



//beg_StatementEle : 'byte'
void R005_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_51Analyzer");
	//TO DO  R005_StatementEle_51Analyzer
};



//beg_StatementEle : 'char'
void R005_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_52Analyzer");
	//TO DO  R005_StatementEle_52Analyzer
};



//beg_StatementEle : 'class'
void R005_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_53Analyzer");
	//TO DO  R005_StatementEle_53Analyzer
};



//beg_StatementEle : 'default'
void R005_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_54Analyzer");
	//TO DO  R005_StatementEle_54Analyzer
};



//beg_StatementEle : 'double'
void R005_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_55Analyzer");
	//TO DO  R005_StatementEle_55Analyzer
};



//beg_StatementEle : 'enum'
void R005_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_56Analyzer");
	//TO DO  R005_StatementEle_56Analyzer
};



//beg_StatementEle : 'extends'
void R005_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_57Analyzer");
	//TO DO  R005_StatementEle_57Analyzer
};



//beg_StatementEle : 'final'
void R005_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_58Analyzer");
	//TO DO  R005_StatementEle_58Analyzer
};



//beg_StatementEle : 'float'
void R005_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_59Analyzer");
	//TO DO  R005_StatementEle_59Analyzer
};



//beg_StatementEle : 'implements'
void R005_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_60Analyzer");
	//TO DO  R005_StatementEle_60Analyzer
};



//beg_StatementEle : 'instanceof'
void R005_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_61Analyzer");
	//TO DO  R005_StatementEle_61Analyzer
};



//beg_StatementEle : 'int'
void R005_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_62Analyzer");
	//TO DO  R005_StatementEle_62Analyzer
};



//beg_StatementEle : 'interface'
void R005_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_63Analyzer");
	//TO DO  R005_StatementEle_63Analyzer
};



//beg_StatementEle : 'long'
void R005_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_64Analyzer");
	//TO DO  R005_StatementEle_64Analyzer
};



//beg_StatementEle : 'native'
void R005_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_65Analyzer");
	//TO DO  R005_StatementEle_65Analyzer
};



//beg_StatementEle : 'new'
void R005_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_66Analyzer");
	//TO DO  R005_StatementEle_66Analyzer
};



//beg_StatementEle : 'null'
void R005_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_67Analyzer");
	//TO DO  R005_StatementEle_67Analyzer
};



//beg_StatementEle : 'private'
void R005_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_68Analyzer");
	//TO DO  R005_StatementEle_68Analyzer
};



//beg_StatementEle : 'protected'
void R005_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_69Analyzer");
	//TO DO  R005_StatementEle_69Analyzer
};



//beg_StatementEle : 'public'
void R005_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_70Analyzer");
	//TO DO  R005_StatementEle_70Analyzer
};



//beg_StatementEle : 'short'
void R005_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_71Analyzer");
	//TO DO  R005_StatementEle_71Analyzer
};



//beg_StatementEle : 'static'
void R005_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_72Analyzer");
	//TO DO  R005_StatementEle_72Analyzer
};



//beg_StatementEle : 'super'
void R005_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_73Analyzer");
	//TO DO  R005_StatementEle_73Analyzer
};



//beg_StatementEle : 'synchronized'
void R005_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_74Analyzer");
	//TO DO  R005_StatementEle_74Analyzer
};



//beg_StatementEle : 'this'
void R005_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_75Analyzer");
	//TO DO  R005_StatementEle_75Analyzer
};



//beg_StatementEle : 'throws'
void R005_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_76Analyzer");
	//TO DO  R005_StatementEle_76Analyzer
};



//beg_StatementEle : 'transient'
void R005_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_77Analyzer");
	//TO DO  R005_StatementEle_77Analyzer
};



//beg_StatementEle : 'void'
void R005_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_78Analyzer");
	//TO DO  R005_StatementEle_78Analyzer
};



//beg_StatementEle : 'volatile'
void R005_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_StatementEle_79Analyzer");
	//TO DO  R005_StatementEle_79Analyzer
};





//beg_StatementEle : 'DimExpr'
void R005_StatementEle_80Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR005("R005_StatementEle_80Analyzer");
   //TO DO  R005_StatementEle_80Analyzer
};



//beg_Identifier : 'IDENTIFIER'
void R005_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_ModifierList : Modifier ModifierList
void R005_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ModifierList_0Analyzer");
	//TO DO  R005_ModifierList_0Analyzer
};



//beg_ModifierList : Modifier
void R005_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ModifierList_1Analyzer");
	//TO DO  R005_ModifierList_1Analyzer
};



//beg_Modifier : 'public'
void R005_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_0Analyzer");
	//TO DO  R005_Modifier_0Analyzer
};



//beg_Modifier : 'protected'
void R005_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_1Analyzer");
	//TO DO  R005_Modifier_1Analyzer
};



//beg_Modifier : 'private'
void R005_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_2Analyzer");
	//TO DO  R005_Modifier_2Analyzer
};



//beg_Modifier : 'abstract'
void R005_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_3Analyzer");
	//TO DO  R005_Modifier_3Analyzer
};



//beg_Modifier : 'static'
void R005_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_4Analyzer");
	//TO DO  R005_Modifier_4Analyzer
};



//beg_Modifier : 'final'
void R005_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_5Analyzer");
	//TO DO  R005_Modifier_5Analyzer
};



//beg_Modifier : 'strictfp'
void R005_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_6Analyzer");
	//TO DO  R005_Modifier_6Analyzer
};



//beg_Modifier : 'default'
void R005_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_7Analyzer");
	//TO DO  R005_Modifier_7Analyzer
};



//beg_Modifier : 'volatile'
void R005_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_8Analyzer");
	//TO DO  R005_Modifier_8Analyzer
};



//beg_Modifier : 'synchronized'
void R005_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_9Analyzer");
	//TO DO  R005_Modifier_9Analyzer
};



//beg_Modifier : 'transient'
void R005_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_10Analyzer");
	//TO DO  R005_Modifier_10Analyzer
};



//beg_Modifier : 'native'
void R005_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_11Analyzer");
	//TO DO  R005_Modifier_11Analyzer
};



//beg_Modifier : Annotation
void R005_Modifier_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Modifier_12Analyzer");
	//TO DO  R005_Modifier_12Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R005_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Annotation_0Analyzer");
	//TO DO  R005_Annotation_0Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier
void R005_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Annotation_1Analyzer");
	//TO DO  R005_Annotation_1Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R005_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DetailIdentifier_0Analyzer");
	//TO DO  R005_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R005_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DetailIdentifier_1Analyzer");
	//TO DO  R005_DetailIdentifier_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R005_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContent_0Analyzer");

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();

	statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;
	statementEntity->begLineNum = nodeValue->node->child_node_list[0]->lineNum;
	statementEntity->endIndex = nodeValue->node->child_node_list[2]->index;
	statementEntity->endLineNum = nodeValue->node->child_node_list[2]->lineNum;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["AnnotationContent"] = P_Token(p);

};



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
void R005_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContentStatements_0Analyzer");
	//TO DO  R005_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R005_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationContentStatements_1Analyzer");
	//TO DO  R005_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R005_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_0Analyzer");
	//TO DO  R005_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R005_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_1Analyzer");
	//TO DO  R005_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R005_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_2Analyzer");
	//TO DO  R005_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R005_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_3Analyzer");
	//TO DO  R005_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R005_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_4Analyzer");
	//TO DO  R005_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R005_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_5Analyzer");
	//TO DO  R005_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R005_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_6Analyzer");
	//TO DO  R005_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R005_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_7Analyzer");
	//TO DO  R005_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R005_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_8Analyzer");
	//TO DO  R005_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R005_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_9Analyzer");
	//TO DO  R005_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : 'EQUAL'
void R005_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonPARENTHESES_10Analyzer");
	//TO DO  R005_NonPARENTHESES_10Analyzer
};



//beg_NonPARENTHESES : AnnotationContent
void R005_NonPARENTHESES_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR005("R005_NonPARENTHESES_11Analyzer");
   //TO DO  R005_NonPARENTHESES_11Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
void R005_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArguments_0Analyzer");
	TypeListToken *p = new TypeListToken();
	p->begLine = nodeValue->node->child_node_list[0]->lineNum;
	p->begIndex = nodeValue->node->child_node_list[0]->index;
	p->endLine = nodeValue->node->child_node_list[2]->lineNum;
	p->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
void R005_TypeArguments_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArguments_1Analyzer");
	TypeListToken *p = new TypeListToken();
	p->begLine = nodeValue->node->child_node_list[0]->lineNum;
	p->begIndex = nodeValue->node->child_node_list[0]->index;
	p->endLine = nodeValue->node->child_node_list[3]->lineNum;
	p->endIndex = nodeValue->node->child_node_list[3]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
void R005_TypeArguments_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArguments_2Analyzer");
	TypeListToken *p = new TypeListToken();
	p->begLine = nodeValue->node->child_node_list[0]->lineNum;
	p->begIndex = nodeValue->node->child_node_list[0]->index;
	p->endLine = nodeValue->node->child_node_list[2]->lineNum;
	p->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R005_TypeArguments_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArguments_3Analyzer");
	TypeListToken *p = new TypeListToken();
	p->begLine = nodeValue->node->child_node_list[0]->lineNum;
	p->begIndex = nodeValue->node->child_node_list[0]->index;
	p->endLine = nodeValue->node->child_node_list[2]->lineNum;
	p->endIndex = nodeValue->node->child_node_list[2]->index;
	nodeValue->context["TypeArguments"] = P_Token(p);
};



//beg_TypeArgumentListL2 : TypeArguments TypeArgumentListL2
void R005_TypeArgumentListL2_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL2_0Analyzer");
	//TO DO  R005_TypeArgumentListL2_0Analyzer
};



//beg_TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
void R005_TypeArgumentListL2_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL2_1Analyzer");
	//TO DO  R005_TypeArgumentListL2_1Analyzer
};



//beg_TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
void R005_TypeArgumentListL2_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL2_2Analyzer");
	//TO DO  R005_TypeArgumentListL2_2Analyzer
};



//beg_TypeArgumentListL1 : TypeArguments TypeArgumentListL1
void R005_TypeArgumentListL1_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL1_0Analyzer");
	//TO DO  R005_TypeArgumentListL1_0Analyzer
};



//beg_TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
void R005_TypeArgumentListL1_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL1_1Analyzer");
	//TO DO  R005_TypeArgumentListL1_1Analyzer
};



//beg_TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
void R005_TypeArgumentListL1_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentListL1_2Analyzer");
	//TO DO  R005_TypeArgumentListL1_2Analyzer
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R005_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentList_0Analyzer");
	//TO DO  R005_TypeArgumentList_0Analyzer
};



//beg_TypeArgumentList : 0
void R005_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_TypeArgumentList_1Analyzer");
	//TO DO  R005_TypeArgumentList_1Analyzer
};



//beg_NonANGLE_BRACKET : 'QUESTION'
void R005_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_0Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_0Analyzer
};



//beg_NonANGLE_BRACKET : 'extends'
void R005_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_1Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_1Analyzer
};



//beg_NonANGLE_BRACKET : 'super'
void R005_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_2Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_2Analyzer
};



//beg_NonANGLE_BRACKET : 'COMMA'
void R005_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_3Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_3Analyzer
};



//beg_NonANGLE_BRACKET : Identifier
void R005_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_4Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_4Analyzer
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
void R005_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_5Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_5Analyzer
};



//beg_NonANGLE_BRACKET : 'SPOT'
void R005_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_6Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_6Analyzer
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
void R005_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_7Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_7Analyzer
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R005_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_8Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_8Analyzer
};


//beg_NonANGLE_BRACKET : TypeArguments
void R005_NonANGLE_BRACKET_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NonANGLE_BRACKET_9Analyzer");
	//TO DO  R005_NonANGLE_BRACKET_9Analyzer
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R005_Dims_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Dims_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p2.get()))->num = ((DimListToken *)(p2.get()))->num + 1;

	nodeValue->context["Dims"] = p2;

};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R005_Dims_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Dims_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p3.get()))->num = ((DimListToken *)(p3.get()))->num + 1;

	nodeValue->context["Dims"] = p3;
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R005_Dims_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Dims_2Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);

};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R005_Dims_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Dims_3Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);
};



//beg_UnannType : UnannArrayType
void R005_UnannType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannArrayType"];
	nodeValue->context["UnannType"] = p0;
};



//beg_UnannType : UnannPrimitiveType
void R005_UnannType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	nodeValue->context["UnannType"] = p0;

};



//beg_UnannType : UnannClassOrInterfaceType
void R005_UnannType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	nodeValue->context["UnannType"] = p0;
};







//beg_UnannPrimitiveType : 'boolean'
void R005_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_0Analyzer");

	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("boolean");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);


};



//beg_UnannPrimitiveType : 'byte'
void R005_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_1Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("byte");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'short'
void R005_UnannPrimitiveType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_2Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("short");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'int'
void R005_UnannPrimitiveType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_3Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("int");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'long'
void R005_UnannPrimitiveType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_4Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("long");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'char'
void R005_UnannPrimitiveType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_5Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("char");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'float'
void R005_UnannPrimitiveType_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_6Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("float");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'double'
void R005_UnannPrimitiveType_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannPrimitiveType_7Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("double");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' AnnotationList UnannClassOrInterfaceType
void R005_UnannClassOrInterfaceType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p4.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p4;
};


//beg_UnannClassOrInterfaceType : Identifier 'SPOT' AnnotationList UnannClassOrInterfaceType
void R005_UnannClassOrInterfaceType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' UnannClassOrInterfaceType
void R005_UnannClassOrInterfaceType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier 'SPOT' UnannClassOrInterfaceType
void R005_UnannClassOrInterfaceType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p2.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p2;

};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments
void R005_UnannClassOrInterfaceType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};



//beg_UnannClassOrInterfaceType : Identifier
void R005_UnannClassOrInterfaceType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannClassOrInterfaceType_5Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};




//beg_UnannArrayType : UnannPrimitiveType Dims
void R005_UnannArrayType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannArrayType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



//beg_UnannArrayType : UnannClassOrInterfaceType Dims
void R005_UnannArrayType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_UnannArrayType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



//beg_VariableDeclaratorList : VariableDeclarator 'COMMA' VariableDeclaratorList
void R005_VariableDeclaratorList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclaratorList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclarator"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];

	FieldToken *fieldP = new FieldToken();
	fieldP->name = ((DimListToken *)(p0.get()))->name;
	fieldP->dimNum = ((DimListToken *)(p0.get()))->num;
	((StatementToken *)(p2.get()))->statementEntity->fieldList.push_front(P_FieldToken(fieldP));



	nodeValue->context["VariableDeclaratorList"] = p2;
};



//beg_VariableDeclaratorList : VariableDeclarator
void R005_VariableDeclaratorList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclaratorList_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclarator"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "VariableDeclaratorList";

	FieldToken *fieldP = new FieldToken();
	fieldP->name = ((DimListToken *)(p0.get()))->name;
	fieldP->dimNum = ((DimListToken *)(p0.get()))->num;
	statementEntity->fieldList.push_front(P_FieldToken(fieldP));


	p->statementEntity = P_StatementEntity(statementEntity);

	nodeValue->context["VariableDeclaratorList"] = P_Token(p);
};


//beg_VariableDeclarator : VariableDeclaratorId 'EQUAL' VariableInitializer
void R005_VariableDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclarator_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclaratorId"];
	nodeValue->context["VariableDeclarator"] = p0;
};




//beg_VariableDeclarator : VariableDeclaratorId
void R005_VariableDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclarator_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclaratorId"];
	nodeValue->context["VariableDeclarator"] = p0;


};



//beg_VariableInitializer : VariableInitializerEle VariableInitializer
void R005_VariableInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializer_0Analyzer");
	//TO DO  R005_VariableInitializer_0Analyzer
};



//beg_VariableInitializer : VariableInitializerEle
void R005_VariableInitializer_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializer_1Analyzer");
	//TO DO  R005_VariableInitializer_1Analyzer
};







//beg_VariableInitializerEle : StatementEle
void R005_VariableInitializerEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializerEle_0Analyzer");
	//TO DO  R005_VariableInitializerEle_0Analyzer
};



//beg_VariableInitializerEle : Block
void R005_VariableInitializerEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializerEle_1Analyzer");
	//TO DO  R005_VariableInitializerEle_1Analyzer
};



//beg_VariableInitializerEle : AnnotationContent
void R005_VariableInitializerEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializerEle_2Analyzer");
	//TO DO  R005_VariableInitializerEle_2Analyzer
};



//beg_VariableInitializerEle : TypeArguments
void R005_VariableInitializerEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializerEle_3Analyzer");
	//TO DO  R005_VariableInitializerEle_3Analyzer
};



//beg_VariableInitializerEle : 'LEFT_BRACKET' VariableInitializer 'RIGHT_BRACKET'
void R005_VariableInitializerEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableInitializerEle_4Analyzer");
	//TO DO  R005_VariableInitializerEle_4Analyzer
};



//beg_VariableInitializerEle : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R005_VariableInitializerEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
   logR005("R005_VariableInitializerEle_5Analyzer");
   //TO DO  R005_VariableInitializerEle_5Analyzer
};



//beg_DimExpr : AnnotationList 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
void R005_DimExpr_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DimExpr_0Analyzer");
	//TO DO  R005_DimExpr_0Analyzer
};



//beg_DimExpr : 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
void R005_DimExpr_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_DimExpr_1Analyzer");
	//TO DO  R005_DimExpr_1Analyzer
};



//beg_VariableDeclaratorId : Identifier Dims
void R005_VariableDeclaratorId_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclaratorId_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p1.get()))->name = p0->content;

	nodeValue->context["VariableDeclaratorId"] = p1;
};


//beg_VariableDeclaratorId : Identifier
void R005_VariableDeclaratorId_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_VariableDeclaratorId_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = p0->content;


	nodeValue->context["VariableDeclaratorId"] = P_Token(p);

};



//beg_MethodDeclaration : ModifierList TypeArguments AnnotationList Result MethodDeclarator Throws 'semicolon'
void R005_MethodDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Result"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p4.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p4.get()))->statementEntity->resultType = ((UnannTypeToken *)(p3.get()))->getText();
	((StatementToken *)(p4.get()))->statementEntity->typeParameters = p1;
	


	nodeValue->context["MethodDeclaration"] = p4;
};



//beg_MethodDeclaration : ModifierList TypeArguments Result MethodDeclarator Throws 'semicolon'
void R005_MethodDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : ModifierList TypeArguments AnnotationList Result MethodDeclarator 'semicolon'
void R005_MethodDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Result"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p4.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p4.get()))->statementEntity->resultType = ((UnannTypeToken *)(p3.get()))->getText();
	((StatementToken *)(p4.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p4;
};



//beg_MethodDeclaration : ModifierList TypeArguments Result MethodDeclarator 'semicolon'
void R005_MethodDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : ModifierList TypeArguments AnnotationList Result MethodDeclarator Throws Block
void R005_MethodDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_4Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Result"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p4.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p4.get()))->statementEntity->resultType = ((UnannTypeToken *)(p3.get()))->getText();
	((StatementToken *)(p4.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p4;
};



//beg_MethodDeclaration : ModifierList TypeArguments Result MethodDeclarator Throws Block
void R005_MethodDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_5Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : ModifierList TypeArguments AnnotationList Result MethodDeclarator Block
void R005_MethodDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_6Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Result"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p4.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p4.get()))->statementEntity->resultType = ((UnannTypeToken *)(p3.get()))->getText();
	((StatementToken *)(p4.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p4;
};



//beg_MethodDeclaration : ModifierList TypeArguments Result MethodDeclarator Block
void R005_MethodDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_7Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p1;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : TypeArguments AnnotationList Result MethodDeclarator Throws 'semicolon'
void R005_MethodDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_8Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : TypeArguments Result MethodDeclarator Throws 'semicolon'
void R005_MethodDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_9Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Result"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p2.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((StatementToken *)(p2.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p1;
};



//beg_MethodDeclaration : TypeArguments AnnotationList Result MethodDeclarator 'semicolon'
void R005_MethodDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_10Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : TypeArguments Result MethodDeclarator 'semicolon'
void R005_MethodDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_11Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Result"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p2.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((StatementToken *)(p2.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p1;
};



//beg_MethodDeclaration : TypeArguments AnnotationList Result MethodDeclarator Throws Block
void R005_MethodDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_12Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p3;
};



//beg_MethodDeclaration : TypeArguments Result MethodDeclarator Throws Block
void R005_MethodDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_13Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Result"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p2.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((StatementToken *)(p2.get()))->statementEntity->typeParameters = p0;


	nodeValue->context["MethodDeclaration"] = p1;
};



//beg_MethodDeclaration : TypeArguments AnnotationList Result MethodDeclarator Block
void R005_MethodDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_14Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Result"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p3.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p2.get()))->getText();
	((StatementToken *)(p3.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p3;

};



//beg_MethodDeclaration : TypeArguments Result MethodDeclarator Block
void R005_MethodDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_15Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Result"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p2.get()))->statementEntity->type = "MethodDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	((StatementToken *)(p2.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["MethodDeclaration"] = p2;

};



//beg_MethodDeclaration : ModifierList MethodHeader 'semicolon'
void R005_MethodDeclaration_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_16Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodHeader"];
	((StatementToken *)(p1.get()))->statementEntity->type = "MethodDeclaration";
	nodeValue->context["MethodDeclaration"] = p1;
};



//beg_MethodDeclaration : ModifierList MethodHeader Block
void R005_MethodDeclaration_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_17Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodHeader"];
	((StatementToken *)(p1.get()))->statementEntity->type = "MethodDeclaration";
	nodeValue->context["MethodDeclaration"] = p1;
};



//beg_MethodDeclaration : MethodHeader 'semicolon'
void R005_MethodDeclaration_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_18Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodHeader"];
	((StatementToken *)(p0.get()))->statementEntity->type = "MethodDeclaration";
	nodeValue->context["MethodDeclaration"] = p0;
};



//beg_MethodDeclaration : MethodHeader Block
void R005_MethodDeclaration_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclaration_19Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["MethodHeader"];
	((StatementToken *)(p0.get()))->statementEntity->type = "MethodDeclaration";
	nodeValue->context["MethodDeclaration"] = p0;
};



//beg_MethodHeader : Result MethodDeclarator Throws
void R005_MethodHeader_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodHeader_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Result"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p1.get()))->statementEntity->type = "MethodHeader";
	((StatementToken *)(p1.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();

	nodeValue->context["MethodHeader"] = p1;
	nodeValue->context["MethodHeader"] = p1;
};


//beg_MethodHeader : Result MethodDeclarator
void R005_MethodHeader_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodHeader_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Result"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["MethodDeclarator"];

	((StatementToken *)(p1.get()))->statementEntity->type = "MethodHeader";
	((StatementToken *)(p1.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();

	nodeValue->context["MethodHeader"] = p1;

};



//beg_Result : UnannType
void R005_Result_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Result_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	nodeValue->context["Result"] = p0;

};



//beg_Result : 'void'
void R005_Result_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Result_1Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->isPrimitive = true;
	p->nameList.push_front("void");
	p->dimNum = 0;
	nodeValue->context["Result"] = P_Token(p);
};



//beg_MethodDeclarator : Identifier AnnotationContent
void R005_MethodDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclarator_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p1.get()))->statementEntity->name = p0->content;
	nodeValue->context["MethodDeclarator"] = p1;

};



//beg_MethodDeclarator : Identifier AnnotationContent Dims
void R005_MethodDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_MethodDeclarator_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p1.get()))->statementEntity->name = p0->content;
	nodeValue->context["MethodDeclarator"] = p1;
};



//beg_Throws : 'throws' ExceptionTypeList
void R005_Throws_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Throws_0Analyzer");
	//TO DO  R005_Throws_0Analyzer
};



//beg_ExceptionTypeList : ExceptionType 'COMMA' ExceptionTypeList
void R005_ExceptionTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExceptionTypeList_0Analyzer");
	//TO DO  R005_ExceptionTypeList_1Analyzer
};



//beg_ExceptionTypeList : ExceptionType
void R005_ExceptionTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExceptionTypeList_1Analyzer");
	//TO DO  R005_ExceptionTypeList_0Analyzer
};






//beg_ExceptionType : UnannClassOrInterfaceType
void R005_ExceptionType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExceptionType_0Analyzer");
	//TO DO  R005_ExceptionType_0Analyzer
};



//beg_ExceptionType : AnnotationList UnannClassOrInterfaceType
void R005_ExceptionType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExceptionType_1Analyzer");
	//TO DO  R005_ExceptionType_1Analyzer
};



//beg_ConstructorDeclaration : ConstructorDeclarator Block
void R005_ConstructorDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ConstructorDeclarator"];
	nodeValue->context["ConstructorDeclaration"] = p0;

};



//beg_ConstructorDeclaration : ModifierList ConstructorDeclarator Block
void R005_ConstructorDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclaration_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ConstructorDeclarator"];
	nodeValue->context["ConstructorDeclaration"] = p1;
};



//beg_ConstructorDeclaration : ConstructorDeclarator Throws Block
void R005_ConstructorDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclaration_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ConstructorDeclarator"];
	nodeValue->context["ConstructorDeclaration"] = p0;
};



//beg_ConstructorDeclaration : ModifierList ConstructorDeclarator Throws Block
void R005_ConstructorDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["ConstructorDeclarator"];
	nodeValue->context["ConstructorDeclaration"] = p1;
};



//beg_ConstructorDeclarator : Identifier AnnotationContent
void R005_ConstructorDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclarator_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["AnnotationContent"];

	((StatementToken *)(p1.get()))->statementEntity->name = p0->content;

	nodeValue->context["ConstructorDeclarator"] = p1;

};



//beg_ConstructorDeclarator : TypeArguments Identifier AnnotationContent
void R005_ConstructorDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ConstructorDeclarator_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeArguments"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationContent"];

	((StatementToken *)(p2.get()))->statementEntity->name = p1->content;
	((StatementToken *)(p2.get()))->statementEntity->typeParameters = p0;

	nodeValue->context["ConstructorDeclarator"] = p2;
};



//beg_ClassDeclaration : NormalClassDeclaration
void R005_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassDeclaration_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;

};



//beg_ClassDeclaration : EnumDeclaration
void R005_ClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassDeclaration_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;

};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass Superinterfaces Block
void R005_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_0Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};

//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces Block
void R005_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_1Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces Block
void R005_NormalClassDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_2Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces Block
void R005_NormalClassDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_3Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces Block
void R005_NormalClassDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_4Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces Block
void R005_NormalClassDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_5Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces Block
void R005_NormalClassDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_6Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces Block
void R005_NormalClassDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_7Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass Block
void R005_NormalClassDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_8Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Block
void R005_NormalClassDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_9Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Block
void R005_NormalClassDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_10Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : 'class' Identifier Superclass Block
void R005_NormalClassDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_11Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Block
void R005_NormalClassDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_12Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Block
void R005_NormalClassDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_13Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier Block
void R005_NormalClassDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_14Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_NormalClassDeclaration : 'class' Identifier Block
void R005_NormalClassDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalClassDeclaration_15Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_Superclass : 'extends' ClassType
void R005_Superclass_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Superclass_0Analyzer");
	//TO DO  R005_Superclass_0Analyzer
};


//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
void R005_ClassTypeEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_0Analyzer");
	//TO DO  R005_ClassTypeEle_3Analyzer
};


//beg_ClassTypeEle : Identifier TypeArguments
void R005_ClassTypeEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_1Analyzer");
	//TO DO  R005_ClassTypeEle_2Analyzer
};


//beg_ClassTypeEle : AnnotationList Identifier
void R005_ClassTypeEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_2Analyzer");
	//TO DO  R005_ClassTypeEle_1Analyzer
};


//beg_ClassTypeEle : Identifier
void R005_ClassTypeEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassTypeEle_3Analyzer");
	//TO DO  R005_ClassTypeEle_0Analyzer
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
void R005_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassType_0Analyzer");
	//TO DO  R005_ClassType_1Analyzer
};


//beg_ClassType : ClassTypeEle
void R005_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ClassType_1Analyzer");
	//TO DO  R005_ClassType_0Analyzer
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
void R005_Superinterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_Superinterfaces_0Analyzer");
	//TO DO  R005_Superinterfaces_0Analyzer
};


//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
void R005_InterfaceTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceTypeList_0Analyzer");
	//TO DO  R005_InterfaceTypeList_1Analyzer
};


//beg_InterfaceTypeList : ClassType
void R005_InterfaceTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceTypeList_1Analyzer");
	//TO DO  R005_InterfaceTypeList_0Analyzer
};



//beg_EnumDeclaration : 'enum' Identifier Block
void R005_EnumDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Block
void R005_EnumDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces Block
void R005_EnumDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces Block
void R005_EnumDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_EnumDeclaration_3Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
void R005_InterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalInterfaceDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
void R005_InterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_InterfaceDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier Block
void R005_NormalInterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_0Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier Block
void R005_NormalInterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_1Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};


//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments Block
void R005_NormalInterfaceDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_2Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments Block
void R005_NormalInterfaceDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_3Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces Block
void R005_NormalInterfaceDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_4Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces Block
void R005_NormalInterfaceDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_5Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces Block
void R005_NormalInterfaceDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_6Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	statementEntity->typeParameters = p2;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces Block
void R005_NormalInterfaceDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_NormalInterfaceDeclaration_7Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["TypeArguments"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	statementEntity->typeParameters = p3;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
void R005_ExtendsInterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_ExtendsInterfaces_0Analyzer");
	//TO DO  R005_ExtendsInterfaces_0Analyzer
};







//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier Block
void R005_AnnotationTypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "AnnotationTypeDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier Block
void R005_AnnotationTypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationTypeDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "AnnotationTypeDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationList : Annotation AnnotationList
void R005_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationList_0Analyzer");
	//TO DO  R005_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R005_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR005("R005_AnnotationList_1Analyzer");
	//TO DO  R005_AnnotationList_1Analyzer
};



