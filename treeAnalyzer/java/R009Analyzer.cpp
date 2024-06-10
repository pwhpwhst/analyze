#include "R009Analyzer.h"
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


#include <iostream>
#include <sstream>
using namespace std;

#include "R009Analyzer_1.h"

void logR009(const string& s) {
	//	Util::log(s);
}



P_NodeValue R009_DefaultAnalyzer::handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {

	logR009("R009_DefaultAnalyzer");
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




//beg_ele_begin : AnnotationTypeMemberDeclaration
void R009_ele_begin_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ele_begin_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeMemberDeclaration"];
	nodeValue->context["ele_begin"] = p0;

	env.list.push_back(nodeValue->context["ele_begin"]);
};



//beg_AnnotationTypeMemberDeclaration : AnnotationTypeElementDeclaration
void R009_AnnotationTypeMemberDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeMemberDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeElementDeclaration"];

	nodeValue->context["AnnotationTypeMemberDeclaration"] = p0;
};



//beg_AnnotationTypeMemberDeclaration : ConstantDeclaration
void R009_AnnotationTypeMemberDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeMemberDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ConstantDeclaration"];

	nodeValue->context["AnnotationTypeMemberDeclaration"] = p0;
};



//beg_AnnotationTypeMemberDeclaration : ConstantDeclarationFake
void R009_AnnotationTypeMemberDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeMemberDeclaration_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ConstantDeclarationFake"];

	nodeValue->context["AnnotationTypeMemberDeclaration"] = p0;
};



//beg_AnnotationTypeMemberDeclaration : ClassDeclaration
void R009_AnnotationTypeMemberDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeMemberDeclaration_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["ClassDeclaration"];

	nodeValue->context["AnnotationTypeMemberDeclaration"] = p0;
};



//beg_AnnotationTypeMemberDeclaration : InterfaceDeclaration
void R009_AnnotationTypeMemberDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeMemberDeclaration_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["InterfaceDeclaration"];

	nodeValue->context["AnnotationTypeMemberDeclaration"] = p0;
};



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
void R009_InterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_InterfaceDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalInterfaceDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
void R009_InterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_InterfaceDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["AnnotationTypeDeclaration"];
	nodeValue->context["InterfaceDeclaration"] = p0;
};



//beg_ClassDeclaration : NormalClassDeclaration
void R009_ClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["NormalClassDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_ClassDeclaration : EnumDeclaration
void R009_ClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassDeclaration_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["EnumDeclaration"];
	nodeValue->context["ClassDeclaration"] = p0;
};



//beg_EnumDeclaration : 'enum' Identifier Block
void R009_EnumDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_EnumDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Block
void R009_EnumDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_EnumDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces Block
void R009_EnumDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_EnumDeclaration_2Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces Block
void R009_EnumDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_EnumDeclaration_3Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "EnumDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["EnumDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass Superinterfaces Block
void R009_NormalClassDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_0Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces Block
void R009_NormalClassDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_1Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces Block
void R009_NormalClassDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_2Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces Block
void R009_NormalClassDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_3Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces Block
void R009_NormalClassDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_4Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};





//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces Block
void R009_NormalClassDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_5Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces Block
void R009_NormalClassDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_6Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces Block
void R009_NormalClassDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_7Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superclass Block
void R009_NormalClassDeclaration_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_8Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};


//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Block
void R009_NormalClassDeclaration_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_9Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Block
void R009_NormalClassDeclaration_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_10Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};



//beg_NormalClassDeclaration : 'class' Identifier Superclass Block
void R009_NormalClassDeclaration_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_11Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};

//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Block
void R009_NormalClassDeclaration_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_12Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);


};




//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Block
void R009_NormalClassDeclaration_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_13Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);
};



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Block
void R009_NormalClassDeclaration_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_14Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};

//beg_NormalClassDeclaration : 'class' Identifier Block
void R009_NormalClassDeclaration_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalClassDeclaration_15Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalClassDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalClassDeclaration"] = P_Token(p);

};








//beg_Superclass : 'extends' ClassType
void R009_Superclass_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Superclass_0Analyzer");
	//TO DO  R009_Superclass_0Analyzer
};



//beg_Superinterfaces : 'implements' InterfaceTypeList
void R009_Superinterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Superinterfaces_0Analyzer");
	//TO DO  R009_Superinterfaces_0Analyzer
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier Block
void R009_NormalInterfaceDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_0Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier Block
void R009_NormalInterfaceDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_1Analyzer");

	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments Block
void R009_NormalInterfaceDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_2Analyzer");

	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments Block
void R009_NormalInterfaceDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_3Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces Block
void R009_NormalInterfaceDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_4Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces Block
void R009_NormalInterfaceDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_5Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces Block
void R009_NormalInterfaceDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_6Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces Block
void R009_NormalInterfaceDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NormalInterfaceDeclaration_7Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "NormalInterfaceDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["NormalInterfaceDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier Block
void R009_AnnotationTypeDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeDeclaration_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "AnnotationTypeDeclaration";
	statementEntity->name = p1->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier Block
void R009_AnnotationTypeDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeDeclaration_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];

	StatementToken *p = new StatementToken();
	StatementEntity *statementEntity = new StatementEntity();
	statementEntity->type = "AnnotationTypeDeclaration";
	statementEntity->name = p2->content;
	p->statementEntity = P_StatementEntity(statementEntity);


	nodeValue->context["AnnotationTypeDeclaration"] = P_Token(p);
};



//beg_Identifier : 'IDENTIFIER'
void R009_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
void R009_Block_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Block_0Analyzer");
	//TO DO  R009_Block_0Analyzer
};



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
void R009_Block_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Block_1Analyzer");
	//TO DO  R009_Block_1Analyzer
};



//beg_BlockStatements : Block BlockStatements
void R009_BlockStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_BlockStatements_0Analyzer");
	//TO DO  R009_BlockStatements_0Analyzer
};



//beg_BlockStatements : NonBrace BlockStatements
void R009_BlockStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_BlockStatements_1Analyzer");
	//TO DO  R009_BlockStatements_1Analyzer
};



//beg_BlockStatements : 0
void R009_BlockStatements_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_BlockStatements_2Analyzer");
	//TO DO  R009_BlockStatements_2Analyzer
};



//beg_NonBrace : StatementEle
void R009_NonBrace_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_0Analyzer");
	//TO DO  R009_NonBrace_0Analyzer
};



//beg_NonBrace : 'COMMA'
void R009_NonBrace_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_1Analyzer");
	//TO DO  R009_NonBrace_1Analyzer
};



//beg_NonBrace : 'semicolon'
void R009_NonBrace_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_2Analyzer");
	//TO DO  R009_NonBrace_2Analyzer
};



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
void R009_NonBrace_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_3Analyzer");
	//TO DO  R009_NonBrace_3Analyzer
};



//beg_NonBrace : 'LEFT_BRACKET'
void R009_NonBrace_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_4Analyzer");
	//TO DO  R009_NonBrace_4Analyzer
};



//beg_NonBrace : 'LEFT_PARENTHESES'
void R009_NonBrace_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_5Analyzer");
	//TO DO  R009_NonBrace_5Analyzer
};



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
void R009_NonBrace_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_6Analyzer");
	//TO DO  R009_NonBrace_6Analyzer
};



//beg_NonBrace : 'RIGHT_BRACKET'
void R009_NonBrace_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_7Analyzer");
	//TO DO  R009_NonBrace_7Analyzer
};



//beg_NonBrace : 'RIGHT_PARENTHESES'
void R009_NonBrace_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_8Analyzer");
	//TO DO  R009_NonBrace_8Analyzer
};



//beg_NonBrace : 'EQUAL'
void R009_NonBrace_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonBrace_9Analyzer");
	//TO DO  R009_NonBrace_9Analyzer
};



//beg_StatementEle : Identifier
void R009_StatementEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_0Analyzer");
	//TO DO  R009_StatementEle_0Analyzer
};



//beg_StatementEle : 'AND'
void R009_StatementEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_1Analyzer");
	//TO DO  R009_StatementEle_1Analyzer
};



//beg_StatementEle : 'AND_EQUAL'
void R009_StatementEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_2Analyzer");
	//TO DO  R009_StatementEle_2Analyzer
};



//beg_StatementEle : 'AT'
void R009_StatementEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_3Analyzer");
	//TO DO  R009_StatementEle_3Analyzer
};



//beg_StatementEle : 'AT_INTERFACE'
void R009_StatementEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_4Analyzer");
	//TO DO  R009_StatementEle_4Analyzer
};



//beg_StatementEle : 'BIT_AND'
void R009_StatementEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_5Analyzer");
	//TO DO  R009_StatementEle_5Analyzer
};



//beg_StatementEle : 'BIT_OR'
void R009_StatementEle_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_6Analyzer");
	//TO DO  R009_StatementEle_6Analyzer
};



//beg_StatementEle : 'BooleanLiteral'
void R009_StatementEle_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_7Analyzer");
	//TO DO  R009_StatementEle_7Analyzer
};



//beg_StatementEle : 'CARET'
void R009_StatementEle_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_8Analyzer");
	//TO DO  R009_StatementEle_8Analyzer
};



//beg_StatementEle : 'COLON'
void R009_StatementEle_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_9Analyzer");
	//TO DO  R009_StatementEle_9Analyzer
};



//beg_StatementEle : 'CharacterLiteral'
void R009_StatementEle_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_10Analyzer");
	//TO DO  R009_StatementEle_10Analyzer
};



//beg_StatementEle : 'DB_EQUAL'
void R009_StatementEle_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_11Analyzer");
	//TO DO  R009_StatementEle_11Analyzer
};



//beg_StatementEle : 'DIVIDE_EQUAL'
void R009_StatementEle_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_12Analyzer");
	//TO DO  R009_StatementEle_12Analyzer
};



//beg_StatementEle : 'FloatingPointLiteral'
void R009_StatementEle_13Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_13Analyzer");
	//TO DO  R009_StatementEle_13Analyzer
};



//beg_StatementEle : 'GT_EQUAL'
void R009_StatementEle_14Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_14Analyzer");
	//TO DO  R009_StatementEle_14Analyzer
};



//beg_StatementEle : 'IntegerLiteral'
void R009_StatementEle_15Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_15Analyzer");
	//TO DO  R009_StatementEle_15Analyzer
};



//beg_StatementEle : 'LAMBDA_TO'
void R009_StatementEle_16Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_16Analyzer");
	//TO DO  R009_StatementEle_16Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT'
void R009_StatementEle_17Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_17Analyzer");
	//TO DO  R009_StatementEle_17Analyzer
};



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
void R009_StatementEle_18Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_18Analyzer");
	//TO DO  R009_StatementEle_18Analyzer
};



//beg_StatementEle : 'LT_EQUAL'
void R009_StatementEle_19Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_19Analyzer");
	//TO DO  R009_StatementEle_19Analyzer
};



//beg_StatementEle : 'MULTI_EQUAL'
void R009_StatementEle_20Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_20Analyzer");
	//TO DO  R009_StatementEle_20Analyzer
};



//beg_StatementEle : 'NOT_EQUAL'
void R009_StatementEle_21Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_21Analyzer");
	//TO DO  R009_StatementEle_21Analyzer
};



//beg_StatementEle : 'OR'
void R009_StatementEle_22Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_22Analyzer");
	//TO DO  R009_StatementEle_22Analyzer
};



//beg_StatementEle : 'OR_EQUAL'
void R009_StatementEle_23Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_23Analyzer");
	//TO DO  R009_StatementEle_23Analyzer
};



//beg_StatementEle : 'PLUS'
void R009_StatementEle_24Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_24Analyzer");
	//TO DO  R009_StatementEle_24Analyzer
};



//beg_StatementEle : 'PLUS_EQUAL'
void R009_StatementEle_25Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_25Analyzer");
	//TO DO  R009_StatementEle_25Analyzer
};



//beg_StatementEle : 'PRECENTAGE'
void R009_StatementEle_26Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_26Analyzer");
	//TO DO  R009_StatementEle_26Analyzer
};



//beg_StatementEle : 'PRECENTAGE_EQUAL'
void R009_StatementEle_27Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_27Analyzer");
	//TO DO  R009_StatementEle_27Analyzer
};



//beg_StatementEle : 'PackageOrTypeNameId'
void R009_StatementEle_28Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_28Analyzer");
	//TO DO  R009_StatementEle_28Analyzer
};



//beg_StatementEle : 'QUESTION'
void R009_StatementEle_29Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_29Analyzer");
	//TO DO  R009_StatementEle_29Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT'
void R009_StatementEle_30Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_30Analyzer");
	//TO DO  R009_StatementEle_30Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2'
void R009_StatementEle_31Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_31Analyzer");
	//TO DO  R009_StatementEle_31Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
void R009_StatementEle_32Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_32Analyzer");
	//TO DO  R009_StatementEle_32Analyzer
};



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
void R009_StatementEle_33Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_33Analyzer");
	//TO DO  R009_StatementEle_33Analyzer
};



//beg_StatementEle : 'RIGTH_BRACKET'
void R009_StatementEle_34Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_34Analyzer");
	//TO DO  R009_StatementEle_34Analyzer
};



//beg_StatementEle : 'SLASH'
void R009_StatementEle_35Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_35Analyzer");
	//TO DO  R009_StatementEle_35Analyzer
};



//beg_StatementEle : 'SPOT'
void R009_StatementEle_36Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_36Analyzer");
	//TO DO  R009_StatementEle_36Analyzer
};



//beg_StatementEle : 'STAR'
void R009_StatementEle_37Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_37Analyzer");
	//TO DO  R009_StatementEle_37Analyzer
};



//beg_StatementEle : 'SUBTRACT'
void R009_StatementEle_38Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_38Analyzer");
	//TO DO  R009_StatementEle_38Analyzer
};



//beg_StatementEle : 'SUBTRACT_EQUAL'
void R009_StatementEle_39Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_39Analyzer");
	//TO DO  R009_StatementEle_39Analyzer
};



//beg_StatementEle : 'SURPRISE'
void R009_StatementEle_40Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_40Analyzer");
	//TO DO  R009_StatementEle_40Analyzer
};



//beg_StatementEle : 'StringLiteral'
void R009_StatementEle_41Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_41Analyzer");
	//TO DO  R009_StatementEle_41Analyzer
};



//beg_StatementEle : 'THREE_SPOT'
void R009_StatementEle_42Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_42Analyzer");
	//TO DO  R009_StatementEle_42Analyzer
};



//beg_StatementEle : 'TILDE'
void R009_StatementEle_43Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_43Analyzer");
	//TO DO  R009_StatementEle_43Analyzer
};



//beg_StatementEle : 'TWO_COLON'
void R009_StatementEle_44Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_44Analyzer");
	//TO DO  R009_StatementEle_44Analyzer
};



//beg_StatementEle : 'TWO_PLUS'
void R009_StatementEle_45Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_45Analyzer");
	//TO DO  R009_StatementEle_45Analyzer
};



//beg_StatementEle : 'TWO_SUBTRACT'
void R009_StatementEle_46Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_46Analyzer");
	//TO DO  R009_StatementEle_46Analyzer
};



//beg_StatementEle : 'TypeNameId'
void R009_StatementEle_47Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_47Analyzer");
	//TO DO  R009_StatementEle_47Analyzer
};



//beg_StatementEle : 'XOR_EQUAL'
void R009_StatementEle_48Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_48Analyzer");
	//TO DO  R009_StatementEle_48Analyzer
};



//beg_StatementEle : 'abstract'
void R009_StatementEle_49Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_49Analyzer");
	//TO DO  R009_StatementEle_49Analyzer
};



//beg_StatementEle : 'boolean'
void R009_StatementEle_50Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_50Analyzer");
	//TO DO  R009_StatementEle_50Analyzer
};



//beg_StatementEle : 'byte'
void R009_StatementEle_51Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_51Analyzer");
	//TO DO  R009_StatementEle_51Analyzer
};



//beg_StatementEle : 'char'
void R009_StatementEle_52Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_52Analyzer");
	//TO DO  R009_StatementEle_52Analyzer
};



//beg_StatementEle : 'class'
void R009_StatementEle_53Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_53Analyzer");
	//TO DO  R009_StatementEle_53Analyzer
};



//beg_StatementEle : 'default'
void R009_StatementEle_54Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_54Analyzer");
	//TO DO  R009_StatementEle_54Analyzer
};



//beg_StatementEle : 'double'
void R009_StatementEle_55Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_55Analyzer");
	//TO DO  R009_StatementEle_55Analyzer
};



//beg_StatementEle : 'enum'
void R009_StatementEle_56Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_56Analyzer");
	//TO DO  R009_StatementEle_56Analyzer
};



//beg_StatementEle : 'extends'
void R009_StatementEle_57Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_57Analyzer");
	//TO DO  R009_StatementEle_57Analyzer
};



//beg_StatementEle : 'final'
void R009_StatementEle_58Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_58Analyzer");
	//TO DO  R009_StatementEle_58Analyzer
};



//beg_StatementEle : 'float'
void R009_StatementEle_59Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_59Analyzer");
	//TO DO  R009_StatementEle_59Analyzer
};



//beg_StatementEle : 'implements'
void R009_StatementEle_60Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_60Analyzer");
	//TO DO  R009_StatementEle_60Analyzer
};



//beg_StatementEle : 'instanceof'
void R009_StatementEle_61Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_61Analyzer");
	//TO DO  R009_StatementEle_61Analyzer
};



//beg_StatementEle : 'int'
void R009_StatementEle_62Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_62Analyzer");
	//TO DO  R009_StatementEle_62Analyzer
};



//beg_StatementEle : 'interface'
void R009_StatementEle_63Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_63Analyzer");
	//TO DO  R009_StatementEle_63Analyzer
};



//beg_StatementEle : 'long'
void R009_StatementEle_64Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_64Analyzer");
	//TO DO  R009_StatementEle_64Analyzer
};



//beg_StatementEle : 'native'
void R009_StatementEle_65Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_65Analyzer");
	//TO DO  R009_StatementEle_65Analyzer
};



//beg_StatementEle : 'new'
void R009_StatementEle_66Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_66Analyzer");
	//TO DO  R009_StatementEle_66Analyzer
};



//beg_StatementEle : 'null'
void R009_StatementEle_67Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_67Analyzer");
	//TO DO  R009_StatementEle_67Analyzer
};



//beg_StatementEle : 'private'
void R009_StatementEle_68Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_68Analyzer");
	//TO DO  R009_StatementEle_68Analyzer
};



//beg_StatementEle : 'protected'
void R009_StatementEle_69Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_69Analyzer");
	//TO DO  R009_StatementEle_69Analyzer
};



//beg_StatementEle : 'public'
void R009_StatementEle_70Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_70Analyzer");
	//TO DO  R009_StatementEle_70Analyzer
};



//beg_StatementEle : 'short'
void R009_StatementEle_71Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_71Analyzer");
	//TO DO  R009_StatementEle_71Analyzer
};



//beg_StatementEle : 'static'
void R009_StatementEle_72Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_72Analyzer");
	//TO DO  R009_StatementEle_72Analyzer
};



//beg_StatementEle : 'super'
void R009_StatementEle_73Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_73Analyzer");
	//TO DO  R009_StatementEle_73Analyzer
};



//beg_StatementEle : 'synchronized'
void R009_StatementEle_74Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_74Analyzer");
	//TO DO  R009_StatementEle_74Analyzer
};



//beg_StatementEle : 'this'
void R009_StatementEle_75Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_75Analyzer");
	//TO DO  R009_StatementEle_75Analyzer
};



//beg_StatementEle : 'throws'
void R009_StatementEle_76Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_76Analyzer");
	//TO DO  R009_StatementEle_76Analyzer
};



//beg_StatementEle : 'transient'
void R009_StatementEle_77Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_77Analyzer");
	//TO DO  R009_StatementEle_77Analyzer
};



//beg_StatementEle : 'void'
void R009_StatementEle_78Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_78Analyzer");
	//TO DO  R009_StatementEle_78Analyzer
};



//beg_StatementEle : 'volatile'
void R009_StatementEle_79Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_StatementEle_79Analyzer");
	//TO DO  R009_StatementEle_79Analyzer
};



//beg_ModifierList : Modifier ModifierList
void R009_ModifierList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ModifierList_0Analyzer");
	//TO DO  R009_ModifierList_0Analyzer
};



//beg_ModifierList : Modifier
void R009_ModifierList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ModifierList_1Analyzer");
	//TO DO  R009_ModifierList_1Analyzer
};



//beg_Modifier : 'public'
void R009_Modifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_0Analyzer");
	//TO DO  R009_Modifier_0Analyzer
};



//beg_Modifier : 'protected'
void R009_Modifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_1Analyzer");
	//TO DO  R009_Modifier_1Analyzer
};



//beg_Modifier : 'private'
void R009_Modifier_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_2Analyzer");
	//TO DO  R009_Modifier_2Analyzer
};



//beg_Modifier : 'abstract'
void R009_Modifier_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_3Analyzer");
	//TO DO  R009_Modifier_3Analyzer
};



//beg_Modifier : 'static'
void R009_Modifier_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_4Analyzer");
	//TO DO  R009_Modifier_4Analyzer
};



//beg_Modifier : 'final'
void R009_Modifier_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_5Analyzer");
	//TO DO  R009_Modifier_5Analyzer
};



//beg_Modifier : 'strictfp'
void R009_Modifier_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_6Analyzer");
	//TO DO  R009_Modifier_6Analyzer
};



//beg_Modifier : 'default'
void R009_Modifier_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_7Analyzer");
	//TO DO  R009_Modifier_7Analyzer
};



//beg_Modifier : 'volatile'
void R009_Modifier_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_8Analyzer");
	//TO DO  R009_Modifier_8Analyzer
};



//beg_Modifier : 'synchronized'
void R009_Modifier_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_9Analyzer");
	//TO DO  R009_Modifier_9Analyzer
};



//beg_Modifier : 'transient'
void R009_Modifier_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_10Analyzer");
	//TO DO  R009_Modifier_10Analyzer
};



//beg_Modifier : 'native'
void R009_Modifier_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_11Analyzer");
	//TO DO  R009_Modifier_11Analyzer
};



//beg_Modifier : Annotation
void R009_Modifier_12Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Modifier_12Analyzer");
	//TO DO  R009_Modifier_12Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
void R009_Annotation_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Annotation_0Analyzer");
	//TO DO  R009_Annotation_0Analyzer
};



//beg_Annotation : 'AT' DetailIdentifier
void R009_Annotation_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Annotation_1Analyzer");
	//TO DO  R009_Annotation_1Analyzer
};



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
void R009_DetailIdentifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_DetailIdentifier_0Analyzer");
	//TO DO  R009_DetailIdentifier_0Analyzer
};



//beg_DetailIdentifier : Identifier
void R009_DetailIdentifier_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_DetailIdentifier_1Analyzer");
	//TO DO  R009_DetailIdentifier_1Analyzer
};



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
void R009_AnnotationContent_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationContent_0Analyzer");
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
void R009_AnnotationContentStatements_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationContentStatements_0Analyzer");
	//TO DO  R009_AnnotationContentStatements_0Analyzer
};



//beg_AnnotationContentStatements : 0
void R009_AnnotationContentStatements_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationContentStatements_1Analyzer");
	//TO DO  R009_AnnotationContentStatements_1Analyzer
};



//beg_NonPARENTHESES : StatementEle
void R009_NonPARENTHESES_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_0Analyzer");
	//TO DO  R009_NonPARENTHESES_0Analyzer
};



//beg_NonPARENTHESES : 'COMMA'
void R009_NonPARENTHESES_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_1Analyzer");
	//TO DO  R009_NonPARENTHESES_1Analyzer
};



//beg_NonPARENTHESES : 'semicolon'
void R009_NonPARENTHESES_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_2Analyzer");
	//TO DO  R009_NonPARENTHESES_2Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACE'
void R009_NonPARENTHESES_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_3Analyzer");
	//TO DO  R009_NonPARENTHESES_3Analyzer
};



//beg_NonPARENTHESES : 'LEFT_BRACKET'
void R009_NonPARENTHESES_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_4Analyzer");
	//TO DO  R009_NonPARENTHESES_4Analyzer
};



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
void R009_NonPARENTHESES_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_5Analyzer");
	//TO DO  R009_NonPARENTHESES_5Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACE'
void R009_NonPARENTHESES_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_6Analyzer");
	//TO DO  R009_NonPARENTHESES_6Analyzer
};



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
void R009_NonPARENTHESES_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_7Analyzer");
	//TO DO  R009_NonPARENTHESES_7Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
void R009_NonPARENTHESES_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_8Analyzer");
	//TO DO  R009_NonPARENTHESES_8Analyzer
};



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
void R009_NonPARENTHESES_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_9Analyzer");
	//TO DO  R009_NonPARENTHESES_9Analyzer
};



//beg_NonPARENTHESES : 'EQUAL'
void R009_NonPARENTHESES_10Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_10Analyzer");
	//TO DO  R009_NonPARENTHESES_10Analyzer
};


//beg_NonPARENTHESES: AnnotationContent
void R009_NonPARENTHESES_11Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonPARENTHESES_11Analyzer");
	//TO DO  R009_NonPARENTHESES_11Analyzer
};





//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL2 'RIGHT_SHIFT2'
void R009_TypeArguments_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArguments_0Analyzer");
	//TO DO  R009_TypeArguments_0Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'LEFT_ANGLE_BRACKET' 'RIGHT_SHIFT2'
void R009_TypeArguments_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArguments_1Analyzer");
	//TO DO  R009_TypeArguments_1Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1 'RIGHT_SHIFT'
void R009_TypeArguments_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArguments_2Analyzer");
	//TO DO  R009_TypeArguments_2Analyzer
};



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
void R009_TypeArguments_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArguments_3Analyzer");
	//TO DO  R009_TypeArguments_3Analyzer
};



//beg_TypeArgumentListL2 : TypeArguments TypeArgumentListL2
void R009_TypeArgumentListL2_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL2_0Analyzer");
	//TO DO  R009_TypeArgumentListL2_0Analyzer
};



//beg_TypeArgumentListL2 : NonANGLE_BRACKET TypeArgumentListL2
void R009_TypeArgumentListL2_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL2_1Analyzer");
	//TO DO  R009_TypeArgumentListL2_1Analyzer
};



//beg_TypeArgumentListL2 : 'LEFT_ANGLE_BRACKET' TypeArgumentListL1
void R009_TypeArgumentListL2_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL2_2Analyzer");
	//TO DO  R009_TypeArgumentListL2_2Analyzer
};



//beg_TypeArgumentListL1 : TypeArguments TypeArgumentListL1
void R009_TypeArgumentListL1_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL1_0Analyzer");
	//TO DO  R009_TypeArgumentListL1_0Analyzer
};



//beg_TypeArgumentListL1 : NonANGLE_BRACKET TypeArgumentListL1
void R009_TypeArgumentListL1_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL1_1Analyzer");
	//TO DO  R009_TypeArgumentListL1_1Analyzer
};



//beg_TypeArgumentListL1 : 'LEFT_ANGLE_BRACKET' TypeArgumentList
void R009_TypeArgumentListL1_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentListL1_2Analyzer");
	//TO DO  R009_TypeArgumentListL1_2Analyzer
};



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
void R009_TypeArgumentList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentList_0Analyzer");
	//TO DO  R009_TypeArgumentList_0Analyzer
};



//beg_TypeArgumentList : 0
void R009_TypeArgumentList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_TypeArgumentList_1Analyzer");
	//TO DO  R009_TypeArgumentList_1Analyzer
};



//beg_NonANGLE_BRACKET : 'QUESTION'
void R009_NonANGLE_BRACKET_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_0Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_0Analyzer
};



//beg_NonANGLE_BRACKET : 'extends'
void R009_NonANGLE_BRACKET_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_1Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_1Analyzer
};



//beg_NonANGLE_BRACKET : 'super'
void R009_NonANGLE_BRACKET_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_2Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_2Analyzer
};



//beg_NonANGLE_BRACKET : 'COMMA'
void R009_NonANGLE_BRACKET_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_3Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_3Analyzer
};



//beg_NonANGLE_BRACKET : Identifier
void R009_NonANGLE_BRACKET_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_4Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_4Analyzer
};



//beg_NonANGLE_BRACKET : UnannPrimitiveType
void R009_NonANGLE_BRACKET_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_5Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_5Analyzer
};



//beg_NonANGLE_BRACKET : 'SPOT'
void R009_NonANGLE_BRACKET_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_6Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_6Analyzer
};



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
void R009_NonANGLE_BRACKET_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_7Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_7Analyzer
};



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
void R009_NonANGLE_BRACKET_8Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_8Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_8Analyzer
};



//beg_NonANGLE_BRACKET : TypeArguments
void R009_NonANGLE_BRACKET_9Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_NonANGLE_BRACKET_9Analyzer");
	//TO DO  R009_NonANGLE_BRACKET_9Analyzer
};



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
void R009_ExtendsInterfaces_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ExtendsInterfaces_0Analyzer");
	//TO DO  R009_ExtendsInterfaces_0Analyzer
};




//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
void R009_InterfaceTypeList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_InterfaceTypeList_0Analyzer");
	//TO DO  R009_InterfaceTypeList_0Analyzer
};



//beg_InterfaceTypeList : ClassType
void R009_InterfaceTypeList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_InterfaceTypeList_1Analyzer");
	//TO DO  R009_InterfaceTypeList_1Analyzer
};



//beg_ClassTypeEle : Identifier
void R009_ClassTypeEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassTypeEle_0Analyzer");
	//TO DO  R009_ClassTypeEle_0Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier
void R009_ClassTypeEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassTypeEle_1Analyzer");
	//TO DO  R009_ClassTypeEle_1Analyzer
};



//beg_ClassTypeEle : Identifier TypeArguments
void R009_ClassTypeEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassTypeEle_2Analyzer");
	//TO DO  R009_ClassTypeEle_2Analyzer
};



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
void R009_ClassTypeEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassTypeEle_3Analyzer");
	//TO DO  R009_ClassTypeEle_3Analyzer
};



//beg_ClassType : ClassTypeEle
void R009_ClassType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassType_0Analyzer");
	//TO DO  R009_ClassType_0Analyzer
};



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
void R009_ClassType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ClassType_1Analyzer");
	//TO DO  R009_ClassType_1Analyzer
};




//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent 'semicolon'
void R009_AnnotationTypeElementDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p2.get()))->statementEntity->name = p1->content;
	((StatementToken *)(p2.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p2;
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent 'semicolon'
void R009_AnnotationTypeElementDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p3.get()))->statementEntity->name = p2->content;
	((StatementToken *)(p3.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p3;
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent Dims 'semicolon'
void R009_AnnotationTypeElementDeclaration_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p2.get()))->statementEntity->name = p1->content;
	((StatementToken *)(p2.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p2;
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent Dims 'semicolon'
void R009_AnnotationTypeElementDeclaration_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_3Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p3.get()))->statementEntity->name = p2->content;
	((StatementToken *)(p3.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p3;
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent DefaultValue 'semicolon'
void R009_AnnotationTypeElementDeclaration_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p2.get()))->statementEntity->name = p1->content;
	((StatementToken *)(p2.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p2;
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent DefaultValue 'semicolon'
void R009_AnnotationTypeElementDeclaration_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_5Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p3.get()))->statementEntity->name = p2->content;
	((StatementToken *)(p3.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p3;
};



//beg_AnnotationTypeElementDeclaration : UnannType Identifier AnnotationContent Dims DefaultValue 'semicolon'
void R009_AnnotationTypeElementDeclaration_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_6Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p2.get()))->statementEntity->name = p1->content;
	((StatementToken *)(p2.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p2.get()))->statementEntity->resultType = ((UnannTypeToken *)(p0.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p2;
};



//beg_AnnotationTypeElementDeclaration : ModifierList UnannType Identifier AnnotationContent Dims DefaultValue 'semicolon'
void R009_AnnotationTypeElementDeclaration_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationTypeElementDeclaration_7Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["AnnotationContent"];


	((StatementToken *)(p3.get()))->statementEntity->name = p2->content;
	((StatementToken *)(p3.get()))->statementEntity->type = "AnnotationTypeElementDeclaration";
	((StatementToken *)(p3.get()))->statementEntity->resultType = ((UnannTypeToken *)(p1.get()))->getText();
	nodeValue->context["AnnotationTypeElementDeclaration"] = p3;
};



//beg_DefaultValue : 'default' ElementValue
void R009_DefaultValue_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_DefaultValue_0Analyzer");
	//TO DO  R009_DefaultValue_0Analyzer
};



//beg_ElementValue : Annotation
void R009_ElementValue_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ElementValue_0Analyzer");
	//TO DO  R009_ElementValue_0Analyzer
};



//beg_ElementValue : VariableInitializer
void R009_ElementValue_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ElementValue_1Analyzer");
	//TO DO  R009_ElementValue_1Analyzer
};



//beg_Result : UnannType
void R009_Result_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Result_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	nodeValue->context["Result"] = p0;

};



//beg_Result : 'void'
void R009_Result_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Result_1Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->isPrimitive = true;
	p->nameList.push_front("void");
	p->dimNum = 0;
	nodeValue->context["Result"] = P_Token(p);
};



//beg_UnannType : UnannArrayType
void R009_UnannType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannArrayType"];
	nodeValue->context["UnannType"] = p0;
};



//beg_UnannType : UnannPrimitiveType
void R009_UnannType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	nodeValue->context["UnannType"] = p0;

};



//beg_UnannType : UnannClassOrInterfaceType
void R009_UnannType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	nodeValue->context["UnannType"] = p0;
};



//beg_UnannPrimitiveType : 'boolean'
void R009_UnannPrimitiveType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_0Analyzer");

	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("boolean");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);


};



//beg_UnannPrimitiveType : 'byte'
void R009_UnannPrimitiveType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_1Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("byte");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'short'
void R009_UnannPrimitiveType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_2Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("short");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'int'
void R009_UnannPrimitiveType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_3Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("int");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'long'
void R009_UnannPrimitiveType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_4Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("long");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'char'
void R009_UnannPrimitiveType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_5Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("char");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'float'
void R009_UnannPrimitiveType_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_6Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("float");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannPrimitiveType : 'double'
void R009_UnannPrimitiveType_7Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannPrimitiveType_7Analyzer");
	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front("double");
	p->isPrimitive = true;
	p->dimNum = 0;

	nodeValue->context["UnannPrimitiveType"] = P_Token(p);
};



//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' AnnotationList UnannClassOrInterfaceType
void R009_UnannClassOrInterfaceType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p4 = nodeValueMap[child(nodeValue, 4, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p4.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p4;
};


//beg_UnannClassOrInterfaceType : Identifier 'SPOT' AnnotationList UnannClassOrInterfaceType
void R009_UnannClassOrInterfaceType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier TypeArguments 'SPOT' UnannClassOrInterfaceType
void R009_UnannClassOrInterfaceType_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_2Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p3.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p3;
};


//beg_UnannClassOrInterfaceType : Identifier 'SPOT' UnannClassOrInterfaceType
void R009_UnannClassOrInterfaceType_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_3Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];

	((UnannTypeToken *)(p2.get()))->nameList.push_front(p0->content);

	nodeValue->context["UnannClassOrInterfaceType"] = p2;

};


//beg_UnannClassOrInterfaceType : Identifier TypeArguments
void R009_UnannClassOrInterfaceType_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_4Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};


//beg_UnannClassOrInterfaceType : Identifier
void R009_UnannClassOrInterfaceType_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannClassOrInterfaceType_5Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];


	UnannTypeToken *p = new UnannTypeToken();
	p->nameList.push_front(p0->content);
	p->isPrimitive = false;
	p->dimNum = 0;

	nodeValue->context["UnannClassOrInterfaceType"] = P_Token(p);
};


//beg_UnannArrayType : UnannPrimitiveType Dims
void R009_UnannArrayType_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannArrayType_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannPrimitiveType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



//beg_UnannArrayType : UnannClassOrInterfaceType Dims
void R009_UnannArrayType_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_UnannArrayType_1Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannClassOrInterfaceType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];

	((UnannTypeToken *)(p0.get()))->dimNum = ((DimListToken *)(p1.get()))->num;

	nodeValue->context["UnannArrayType"] = p0;
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R009_Dims_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Dims_0Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p2.get()))->num = ((DimListToken *)(p2.get()))->num + 1;

	nodeValue->context["Dims"] = p2;
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET' Dims
void R009_Dims_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Dims_1Analyzer");
	P_Token  p3 = nodeValueMap[child(nodeValue, 3, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p3.get()))->num = ((DimListToken *)(p3.get()))->num + 1;

	nodeValue->context["Dims"] = p3;
};



//beg_Dims : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R009_Dims_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Dims_2Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);
};



//beg_Dims : AnnotationList 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R009_Dims_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_Dims_3Analyzer");
	DimListToken *p = new DimListToken();
	p->num = 1;
	nodeValue->context["Dims"] = P_Token(p);
};


//beg_ConstantDeclaration : UnannType VariableDeclaratorList 'semicolon'
void R009_ConstantDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ConstantDeclaration_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["UnannType"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p1.get()))->statementEntity->type = "ConstantDeclaration";

	for (auto &e : ((StatementToken *)(p1.get()))->statementEntity->fieldList) {
		e->isPrimitiveType = ((UnannTypeToken *)(p0.get()))->isPrimitive;
		e->dimNum += ((UnannTypeToken *)(p0.get()))->dimNum;
	}

	for (auto &e : ((StatementToken *)(p1.get()))->statementEntity->fieldList) {
		((UnannTypeToken *)(p0.get()))->dimNum = e->dimNum;
		e->unannType = ((UnannTypeToken *)(p0.get()))->getText();
	}

	nodeValue->context["ConstantDeclaration"] = p1;
};



//beg_ConstantDeclaration : ModifierList UnannType VariableDeclaratorList 'semicolon'
void R009_ConstantDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ConstantDeclaration_1Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["UnannType"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];



	((StatementToken *)(p2.get()))->statementEntity->type = "ConstantDeclaration";

	for (auto &e : ((StatementToken *)(p2.get()))->statementEntity->fieldList) {
		e->isPrimitiveType = ((UnannTypeToken *)(p1.get()))->isPrimitive;
		e->dimNum += ((UnannTypeToken *)(p1.get()))->dimNum;
	}

	for (auto &e : ((StatementToken *)(p2.get()))->statementEntity->fieldList) {
		((UnannTypeToken *)(p1.get()))->dimNum = e->dimNum;
		e->unannType = ((UnannTypeToken *)(p1.get()))->getText();
	}


	nodeValue->context["ConstantDeclaration"] = p2;
};



//beg_ConstantDeclarationFake : UnannType VariableDeclaratorList
void R009_ConstantDeclarationFake_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ConstantDeclarationFake_0Analyzer");
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p1.get()))->statementEntity->type = "ConstantDeclarationFake";

	nodeValue->context["ConstantDeclarationFake"] = p1;
};



//beg_ConstantDeclarationFake : ModifierList UnannType VariableDeclaratorList
void R009_ConstantDeclarationFake_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_ConstantDeclarationFake_1Analyzer");
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];

	((StatementToken *)(p2.get()))->statementEntity->type = "ConstantDeclarationFake";

	nodeValue->context["ConstantDeclarationFake"] = p2;
};



//beg_VariableDeclaratorList : VariableDeclarator 'COMMA' VariableDeclaratorList
void R009_VariableDeclaratorList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclaratorList_0Analyzer");
	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclarator"];
	P_Token  p2 = nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["VariableDeclaratorList"];

	FieldToken *fieldP = new FieldToken();
	fieldP->name = ((DimListToken *)(p0.get()))->name;
	fieldP->dimNum = ((DimListToken *)(p0.get()))->num;
	((StatementToken *)(p2.get()))->statementEntity->fieldList.push_front(P_FieldToken(fieldP));



	nodeValue->context["VariableDeclaratorList"] = p2;
};



//beg_VariableDeclaratorList : VariableDeclarator
void R009_VariableDeclaratorList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclaratorList_1Analyzer");

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
void R009_VariableDeclarator_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclarator_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclaratorId"];
	nodeValue->context["VariableDeclarator"] = p0;
};




//beg_VariableDeclarator : VariableDeclaratorId
void R009_VariableDeclarator_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclarator_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["VariableDeclaratorId"];
	nodeValue->context["VariableDeclarator"] = p0;


};



//beg_VariableInitializer : VariableInitializerEle VariableInitializer
void R009_VariableInitializer_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializer_0Analyzer");
	//TO DO  R009_VariableInitializer_0Analyzer
};



//beg_VariableInitializer : VariableInitializerEle
void R009_VariableInitializer_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializer_1Analyzer");
	//TO DO  R009_VariableInitializer_1Analyzer
};



//beg_VariableInitializerEle : StatementEle
void R009_VariableInitializerEle_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_0Analyzer");
	//TO DO  R009_VariableInitializerEle_0Analyzer
};



//beg_VariableInitializerEle : Block
void R009_VariableInitializerEle_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_1Analyzer");
	//TO DO  R009_VariableInitializerEle_1Analyzer
};



//beg_VariableInitializerEle : AnnotationContent
void R009_VariableInitializerEle_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_2Analyzer");
	//TO DO  R009_VariableInitializerEle_2Analyzer
};



//beg_VariableInitializerEle : TypeArguments
void R009_VariableInitializerEle_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_3Analyzer");
	//TO DO  R009_VariableInitializerEle_3Analyzer
};



//beg_VariableInitializerEle : DimExpr
void R009_VariableInitializerEle_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_4Analyzer");
	//TO DO  R009_VariableInitializerEle_4Analyzer
};



//beg_VariableInitializerEle : 'LEFT_BRACKET' 'RIGHT_BRACKET'
void R009_VariableInitializerEle_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableInitializerEle_5Analyzer");
	//TO DO  R009_VariableInitializerEle_5Analyzer
};



//beg_VariableDeclaratorId : Identifier Dims
void R009_VariableDeclaratorId_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclaratorId_0Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];
	P_Token  p1 = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["Dims"];
	((DimListToken *)(p1.get()))->name = p0->content;

	nodeValue->context["VariableDeclaratorId"] = p1;
};


//beg_VariableDeclaratorId : Identifier
void R009_VariableDeclaratorId_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_VariableDeclaratorId_1Analyzer");

	P_Token  p0 = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["Identifier"];

	DimListToken *p = new DimListToken();
	p->num = 0;
	p->name = p0->content;


	nodeValue->context["VariableDeclaratorId"] = P_Token(p);

};




//beg_AnnotationList : Annotation AnnotationList
void R009_AnnotationList_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationList_0Analyzer");
	//TO DO  R009_AnnotationList_0Analyzer
};



//beg_AnnotationList : Annotation
void R009_AnnotationList_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_AnnotationList_1Analyzer");
	//TO DO  R009_AnnotationList_1Analyzer
};



//beg_DimExpr : AnnotationList 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
void R009_DimExpr_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_DimExpr_0Analyzer");
	//TO DO  R009_DimExpr_0Analyzer
};



//beg_DimExpr : 'LEFT_BRACKET' VariableInitializerEle 'RIGHT_BRACKET'
void R009_DimExpr_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR009("R009_DimExpr_1Analyzer");
	//TO DO  R009_DimExpr_1Analyzer
};



