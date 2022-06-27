#include "R001Analyzer.h"
#include "../../symbols/java/Class.h"
#include "../../symbols/java/Array.h"
#include "../../symbols/java/CompileUnit.h"
#include<iostream>
using namespace std;

void logR001(const string& s) {
			  cout<<s<<endl;
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
#include "R001Analyzer3.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////

string getPackageName(Array *ptr) {
	
		ostringstream os;
		for (int i1 = 0; i1 < ptr->list.size();i1++) {
			os << ptr->list[i1]->content;
			if (i1!= ptr->list.size()-1) {
				os << ".";
			}
		}
		return os.str();
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
//CompilationUnit : PackageDeclaration
void R001_CompilationUnit_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_0");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);
	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
	
}


//CompilationUnit : ImportDeclarationList
void R001_CompilationUnit_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_1");
	nodeValue->context["CompilationUnit"] = P_Token(new CompileUnit());
}


//CompilationUnit : PackageDeclaration ImportDeclarationList
void R001_CompilationUnit_3Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_3");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);
	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
}


//CompilationUnit : TypeDeclarationList
void R001_CompilationUnit_2Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_2Analyzer");
	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->type_declaration_list = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
	
}


//CompilationUnit : PackageDeclaration TypeDeclarationList
void R001_CompilationUnit_4Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_4");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;

	p->type_declaration_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : ImportDeclarationList TypeDeclarationList
void R001_CompilationUnit_5Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_5");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->type_declaration_list = nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["TypeDeclarationList"];
	env.list.push_back(nodeValue->context["CompilationUnit"]);
}


//CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
void R001_CompilationUnit_6Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_CompilationUnit_6");

	CompileUnit *p = new CompileUnit();
	nodeValue->context["CompilationUnit"] = P_Token(p);

	p->package = nodeValueMap[child(nodeValue, 0, NodeValue::SYN)]->context["PackageDeclaration"]->content;
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


//Identifier : 'IDENTIFIER'
void R001_Identifier_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_Identifier_0Analyzer");
	nodeValue->context["Identifier"] = P_Token(new Token("string", nodeValue->node->child_node_list[0]->content, 0));
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


//PackageDeclaration : AnnotationList 'package' DetailIdentifier 'semicolon'
void R001_PackageDeclaration_0Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_PackageDeclaration_0");
	Array *arr=(Array*)nodeValueMap[child(nodeValue, 2, NodeValue::SYN)]->context["DetailIdentifier"].get();
	nodeValue->context["PackageDeclaration"]= P_Token(new Token("string", getPackageName(arr),0));
}


//PackageDeclaration : 'package' DetailIdentifier 'semicolon'
void R001_PackageDeclaration_1Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {
	logR001("R001_PackageDeclaration_1");
	Array *arr = (Array*)nodeValueMap[child(nodeValue, 1, NodeValue::SYN)]->context["DetailIdentifier"].get();
	nodeValue->context["PackageDeclaration"] = P_Token(new Token("string", getPackageName(arr), 0));
}