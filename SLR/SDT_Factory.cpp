#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include "../treeAnalyzer/java/R001Analyzer.h"
using namespace std;

SDT_Factory SDT_Factory::instance;
SDT_Factory::SDT_Factory() {
}

P_SDT_genertor SDT_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key)>0) {
		return factory[key];
	}
	
	if ("R001_CompilationUnit_2" == key) {
		factory["R001_CompilationUnit_2"] = P_SDT_genertor(new R001_CompilationUnit_2Analyzer());
	}
	else if ("R001_TypeDeclarationList_1" == key) {
		factory["R001_TypeDeclarationList_1"] = P_SDT_genertor(new R001_TypeDeclarationList_1Analyzer());
	}
	else if ("R001_TypeDeclarationList_1" == key) {
		factory["R001_TypeDeclarationList_1"] = P_SDT_genertor(new R001_TypeDeclarationList_1Analyzer());
	}
	else if ("R001_TypeDeclaration_0" == key) {
		factory["R001_TypeDeclaration_0"] = P_SDT_genertor(new R001_TypeDeclaration_0Analyzer());
	}
	else if ("R001_ClassDeclaration_0" == key) {
		factory["R001_ClassDeclaration_0"] = P_SDT_genertor(new R001_ClassDeclaration_0Analyzer());
	}
	else if ("R001_NormalClassDeclaration_1" == key) {
		factory["R001_NormalClassDeclaration_1"] = P_SDT_genertor(new R001_NormalClassDeclaration_1Analyzer());
	}
	else if ("R001_ModifierList_1" == key) {
		factory["R001_ModifierList_1"] = P_SDT_genertor(new R001_ModifierList_1Analyzer());
	}
	else if ("R001_Identifier_0" == key) {
		factory["R001_Identifier_0"] = P_SDT_genertor(new R001_Identifier_0Analyzer());
	}
	else if ("R001_ClassBody_0" == key) {
		factory["R001_ClassBody_0"] = P_SDT_genertor(new R001_ClassBody_0Analyzer());
	}
	else if ("R001_ClassBodyDeclarationList_0" == key) {
		factory["R001_ClassBodyDeclarationList_0"] = P_SDT_genertor(new R001_ClassBodyDeclarationList_0Analyzer());
	}
	else if ("R001_ClassBodyDeclaration_0" == key) {
		factory["R001_ClassBodyDeclaration_0"] = P_SDT_genertor(new R001_ClassBodyDeclaration_0Analyzer());
	}
	else if ("R001_ClassMemberDeclaration_1" == key) {
		factory["R001_ClassMemberDeclaration_1"] = P_SDT_genertor(new R001_ClassMemberDeclaration_1Analyzer());
	}
	else if ("R001_ClassMemberDeclaration_2" == key) {
		factory["R001_ClassMemberDeclaration_2"] = P_SDT_genertor(new R001_ClassMemberDeclaration_2Analyzer());
	}
	else if ("R001_NormalClassDeclaration_0" == key) {
		factory["R001_NormalClassDeclaration_0"] = P_SDT_genertor(new R001_NormalClassDeclaration_0Analyzer());
	}
	else if ("R001_ClassBodyDeclarationList_1" == key) {
		factory["R001_ClassBodyDeclarationList_1"] = P_SDT_genertor(new R001_ClassBodyDeclarationList_1Analyzer());
	}
	else if ("R001_MethodDeclaration_1" == key) {
		factory["R001_MethodDeclaration_1"] = P_SDT_genertor(new R001_MethodDeclaration_1Analyzer());
	}
	else if ("R001_MethodHeader_12" == key) {
		factory["R001_MethodHeader_12"] = P_SDT_genertor(new R001_MethodHeader_12Analyzer());
	}
	else if ("R001_MethodDeclarator_0" == key) {
		factory["R001_MethodDeclarator_0"] = P_SDT_genertor(new R001_MethodDeclarator_0Analyzer());
	}
	else if ("R001_MethodBody_0" == key) {
		factory["R001_MethodBody_0"] = P_SDT_genertor(new R001_MethodBody_0Analyzer());
	}
	else if ("R001_Block_0" == key) {
		factory["R001_Block_0"] = P_SDT_genertor(new R001_Block_0Analyzer());
	}
	else if ("R001_BlockStatements_1" == key) {
		factory["R001_BlockStatements_1"] = P_SDT_genertor(new R001_BlockStatements_1Analyzer());
	}
	else if ("R001_NonBrace_0" == key) {
		factory["R001_NonBrace_0"] = P_SDT_genertor(new R001_NonBrace_0Analyzer());
	}
	else if ("R001_StatementEle_63" == key) {
		factory["R001_StatementEle_63"] = P_SDT_genertor(new R001_StatementEle_63Analyzer());
	}
	else if ("R001_StatementEle_0" == key) {
		factory["R001_StatementEle_0"] = P_SDT_genertor(new R001_StatementEle_0Analyzer());
	}
	else if ("R001_NonBrace_2" == key) {
		factory["R001_NonBrace_2"] = P_SDT_genertor(new R001_NonBrace_2Analyzer());
	}
	else if ("R001_BlockStatements_2" == key) {
		factory["R001_BlockStatements_2"] = P_SDT_genertor(new R001_BlockStatements_2Analyzer());
	}
	else {
		
		
		
		
		if ("R001_'class'_0" == key
			|| "R001_'IDENTIFIER'_0" == key
			|| "R001_'LEFT_BRACE'_0" == key
			|| "R001_0_0" == key
			|| "R001_'RIGHT_BRACE'_0" == key
			|| "R001_'LEFT_PARENTHESES'_0" == key
			|| "R001_'RIGHT_PARENTHESES'_0" == key
			|| "R001_'int'_0" == key
			|| "R001_'semicolon'_0" == key) {
			factory[key] = P_SDT_genertor(new R001_DefaultAnalyzer());
		}
	}
	return factory[key];
}
SDT_Factory::~SDT_Factory() {}


