#pragma once

#include"../Lalr.h"
#include "../Util/Util.h"
#include "../dao/TCompileFileDao.h"
#include "../dao/ErpClassDao.h"
#include "../dao/ErpMethodDao.h"
#include "../dao/ErpImportDao.h"
#include "../symbols/PrimarySymbolConverter.h"
#include "../space/java/Space.h"
#include "../RecursiveDescentJava.h"
#include "../symbols/java/ClassListToken.h"
#include "../symbols/java/StatementToken.h"
#include "../symbols/java/StatementListToken.h"

#include "../space/java/FieldDeclaration.h"
#include "../space/java/CompilationUnit.h"
#include "../space/java/MethodDeclaration.h"
#include "../space/java/InstanceInitializer.h"
#include "../space/java/StaticInitializer.h"
#include "../space/java/ConstructorDeclaration.h"
#include "../space/java/EnumConstant.h"
#include "../space/java/ConstantDeclaration.h"
#include "../space/java/InterfaceMethodDeclaration.h"
#include "../space/java/AnnotationTypeElementDeclaration.h"
#include "../space/java/NormalClassDeclaration.h"
#include "../space/java/EnumDeclaration.h"
#include "../space/java/NormalInterfaceDeclaration.h"
#include "../space/java/AnnotationTypeDeclaration.h"
#include "../space/java/Space.h"
#include "../space/java/ParamDeclaration.h"


#include <deque>
#include <iostream>
#include <fstream>
#include "JavaDeclareParser.h"






using namespace std;
using namespace boost;
JavaDeclareParser::JavaDeclareParser(){}

JavaDeclareParser::~JavaDeclareParser(){}




void JavaDeclareParser::initParser(Parser *&parser, const string& parserType, bool logSwitch, string& ruelFile) {
	if (parserType == "RecursiveDescentJava") {
		parser = new RecursiveDescentJava();
	}
	else if (parserType == "Lalr") {
		parser = new Lalr();
	}

	parser->logSwitch = logSwitch;
	parser->init(ruelFile);
}

void JavaDeclareParser::initParsers() {
	string rule_file4 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R004.txt";
	string rule_file5 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R005.txt";
	string rule_file6 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R006.txt";
	string rule_file7 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R007.txt";
	string rule_file8 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R008.txt";
	string rule_file9 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R009.txt";

	cout << "init parser4" << endl;
	initParser(parser4, "Lalr", false, rule_file4);
	cout << "init parser5" << endl;
	initParser(parser5, "Lalr", false, rule_file5);
	cout << "init parser6" << endl;
	initParser(parser6, "Lalr", false, rule_file6);
	cout << "init parser7" << endl;
	initParser(parser7, "Lalr", false, rule_file7);
	cout << "init parser8" << endl;
	initParser(parser8, "Lalr", false, rule_file8);
	cout << "init parser9" << endl;
	initParser(parser9, "Lalr", false, rule_file9);

	primarySymbolConverter= new PrimarySymbolConverter();
}

void JavaDeclareParser::deleteParsers() {
	delete parser4;
	delete parser5;
	delete parser6;
	delete parser7;
	delete parser8;
	delete parser9;
	delete primarySymbolConverter;
}


void JavaDeclareParser::processContext(P_Context &context) {


	if (context->type == "CompilationUnit") {
		processCompilationUnit(context);

	}
	else if (context->type == "NormalClassDeclaration") {
		processNormalClassDeclaration(context);
	}
	else if (context->type == "EnumDeclaration") {
		processEnumDeclaration(context);
	}
	else if (context->type == "NormalInterfaceDeclaration") {
		processNormalInterfaceDeclaration(context);
	}
	else if (context->type == "AnnotationTypeDeclaration") {
		processAnnotationTypeMemberDeclaration(context);
	}


}


void JavaDeclareParser::processNormalClassDeclaration(P_Context &context) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = context->token;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	if (p == nullptr) {
		return;
	}


	for (int i1 = 0; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				parser5->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree5 = parser5->slr(env2, "ele_begin", 0);

				if (node_tree5 != nullptr) {

					parser5->gen_middle_code(env2, node_tree5, imfo_map);
					statementType = ((StatementToken *)(env2.list[0].get()))->statementEntity->type;

					if (statementType == "FieldDeclarationFake") {
						for (int i2 = i1; i2 < p->list.size(); i2++) {
							if (p->list[i2]->endWith != "semicolon") {
								p->list[i2]->endWith = "useless";
							}
							else {
								p->list[i2]->endWith = "useless";
								p->list[i1]->endWith = "semicolon";
								p->list[i1]->endIndex = p->list[i2]->endIndex;
								break;
							}
						}
						Node::releaseNode(node_tree5);
						statementType = "";
						continue;
					}

					Node::releaseNode(node_tree5);
				}
				isProcessed = true;
				if (statementType != "") {


					if (statementType == "FieldDeclaration") {
						fillWithStatementFieldDeclaration(context, env2);
					}


					if (statementType == "MethodDeclaration") {
						fillWithStatementMethodDeclaration(context, env2, p, i1);
					}

					if (statementType == "ConstructorDeclaration") {
						fillWithStatementConstructorDeclaration(context, env2, p, i1);

					}

					if (statementType == "StaticInitializer") {
						context->root->spaceList.push_back(new StaticInitializer());
					}

					if (statementType == "InstanceInitializer") {
						context->root->spaceList.push_back(new InstanceInitializer());
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context,  p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context,p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}
				}
			}

			if (statementType == "") {

				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));
			}
		}
	}

}


void JavaDeclareParser::processNormalInterfaceDeclaration(P_Context &context) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = context->token;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	if (p == nullptr) {
		return;
	}


	for (int i1 = 0; i1 < p->list.size(); i1++) {
		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				parser8->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree8 = parser8->slr(env2, "ele_begin", 0);

				if (node_tree8 != nullptr) {

					parser8->gen_middle_code(env2, node_tree8, imfo_map);
					statementType = ((StatementToken *)(env2.list[0].get()))->statementEntity->type;

					if (statementType == "ConstantDeclarationFake") {
						for (int i2 = i1; i2 < p->list.size(); i2++) {
							if (p->list[i2]->endWith != "semicolon") {
								p->list[i2]->endWith = "useless";
							}
							else {
								p->list[i2]->endWith = "useless";
								p->list[i1]->endWith = "semicolon";
								p->list[i1]->endIndex = p->list[i2]->endIndex;
								break;
							}
						}
						Node::releaseNode(node_tree8);
						statementType = "";
						continue;
					}

					Node::releaseNode(node_tree8);
				}
				isProcessed = true;
				if (statementType != "") {


					if (statementType == "ConstantDeclaration") {
						fillWithStatementConstantDeclaration(context, env2);
					}

					if (statementType == "InterfaceMethodDeclaration") {
						fillWithStatementInterfaceMethodDeclaration(context, env2, p, i1);
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

				}


			}

			if (statementType == "") {
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));
			}
		}
	}

}



void JavaDeclareParser::processEnumDeclaration(P_Context &context) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = context->token;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	if (p != nullptr) {
		Env env3;
		parser7->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[0]->begIndex, p->list[0]->endIndex);
		Node*  node_tree7 = parser7->slr(env3, "ele_begin", 0);

		parser7->gen_middle_code(env3, node_tree7, imfo_map);
		for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
			context->root->spaceList.push_back(new EnumConstant(e->name));
		}
		Node::releaseNode(node_tree7);

	}


	if (p == nullptr) {
		return;
	}


	for (int i1 = 1; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				parser5->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree5 = parser5->slr(env2, "ele_begin", 0);

				if (node_tree5 != nullptr) {

					parser5->gen_middle_code(env2, node_tree5, imfo_map);
					statementType = ((StatementToken *)(env2.list[0].get()))->statementEntity->type;

					if (statementType == "FieldDeclarationFake") {
						for (int i2 = i1; i2 < p->list.size(); i2++) {
							if (p->list[i2]->endWith != "semicolon") {
								p->list[i2]->endWith = "useless";
							}
							else {
								p->list[i2]->endWith = "useless";
								p->list[i1]->endWith = "semicolon";
								p->list[i1]->endIndex = p->list[i2]->endIndex;
								break;
							}
						}
						Node::releaseNode(node_tree5);
						statementType = "";
						continue;
					}

					Node::releaseNode(node_tree5);
				}
				isProcessed = true;
				if (statementType != "") {


					if (statementType == "FieldDeclaration") {
						fillWithStatementFieldDeclaration(context, env2);
					}


					if (statementType == "MethodDeclaration") {
						fillWithStatementMethodDeclaration(context, env2, p, i1);
					}

					if (statementType == "ConstructorDeclaration") {
						fillWithStatementConstructorDeclaration(context, env2, p, i1);

					}

					if (statementType == "StaticInitializer") {
						context->root->spaceList.push_back(new StaticInitializer());
					}

					if (statementType == "InstanceInitializer") {
						context->root->spaceList.push_back(new InstanceInitializer());
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}
				}
			}

			if (statementType == "") {
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));

			}
		}
	}

}


void JavaDeclareParser::processAnnotationTypeMemberDeclaration(P_Context &context) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = context->token;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	if (p == nullptr) {
		return;
	}


	for (int i1 = 0; i1 < p->list.size(); i1++) {
		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				parser9->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree9 = parser9->slr(env2, "ele_begin", 0);

				if (node_tree9 != nullptr) {

					parser9->gen_middle_code(env2, node_tree9, imfo_map);
					statementType = ((StatementToken *)(env2.list[0].get()))->statementEntity->type;

					if (statementType == "ConstantDeclarationFake" || statementType == "AnnotationTypeElementDeclarationFake") {
						for (int i2 = i1; i2 < p->list.size(); i2++) {
							if (p->list[i2]->endWith != "semicolon") {
								p->list[i2]->endWith = "useless";
							}
							else {
								p->list[i2]->endWith = "useless";
								p->list[i1]->endWith = "semicolon";
								p->list[i1]->endIndex = p->list[i2]->endIndex;
								break;
							}
						}
						Node::releaseNode(node_tree9);
						statementType = "";
						continue;
					}

					Node::releaseNode(node_tree9);
				}
				isProcessed = true;
				if (statementType != "") {


					if (statementType == "ConstantDeclaration") {
						fillWithStatementConstantDeclaration(context, env2);
					}





					if (statementType == "AnnotationTypeElementDeclaration") {
						fillWithStatementAnnotationTypeElementDeclaration(context, env2, p, i1);
					}




					if (statementType == "InterfaceMethodDeclaration") {
						fillWithStatementInterfaceMethodDeclaration(context, env2, p, i1);
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context,  p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begIndex, env3, 0, childContext);
						contextDeque.push_front(childContext);
					}


				}


			}

			if (statementType == "") {
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));
			}
		}
	}
}



void JavaDeclareParser::processCompilationUnit(P_Context &context) {
	Env env;
	parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
	Node*  node_tree4 = parser4->slr(env, "ele_begin", 0);

	string className;
	int wordListIdOfclass;

	if (node_tree4 == nullptr) {
		Util::log(context->compile_file + ":" + "analyze failed");
	}
	else {

		unordered_map<string, string> imfo_map;
		parser4->gen_middle_code(env, node_tree4, imfo_map);
		Node::releaseNode(node_tree4);

		if (((ClassListToken *)(env.list[0].get()))->list.size() == 0) {
			return;
		}

		CompilationUnit *p = new CompilationUnit();

		p->package = ((ClassListToken *)(env.list[0].get()))->packageName;

		ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
		if (importListToken != nullptr) {
			for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
				ImportEntity importEntity;
				importEntity.name = importListToken->list[i1]->name;
				importEntity.isStatic = importListToken->list[i1]->isStatic;
				p->importList.push_back(importEntity);
			}
		}

		context->root = p;


		for (int i1 = 0; i1 < ((ClassListToken *)(env.list[0].get()))->list.size(); i1++) {
			string classType = ((ClassListToken *)(env.list[0].get()))->list[i1]->type;

			long ZERO = 0;
			if (classType == "NormalClassDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeNormalClassDeclaration(context,  ZERO, env, i1, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "EnumDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeEnumDeclaration(context,  ZERO, env, i1, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "NormalInterfaceDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeNormalInterfaceDeclaration(context,  ZERO, env, i1, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "AnnotationTypeDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeAnnotationTypeDeclaration(context, ZERO, env, i1, childContext);
				contextDeque.push_front(childContext);
			}

		}




	}
}


void JavaDeclareParser::fillWithStatementConstantDeclaration(P_Context &context, Env &env) {

	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->root->spaceList.push_back(new ConstantDeclaration(e->unannType, e->name));
	}
}



void JavaDeclareParser::fillWithStatementFieldDeclaration(P_Context &context, Env &env) {

	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->root->spaceList.push_back(new FieldDeclaration(e->unannType, e->name));
	}
}

void JavaDeclareParser::fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;
	Util::log("MethodDeclaration:name:" + name);
	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;



	int paramBeg = ((StatementToken *)(env.list[0].get()))->statementEntity->begIndex;
	int paramEnd = ((StatementToken *)(env.list[0].get()))->statementEntity->endIndex;
	Env env3;
	parser6->init_total_lex_word_list(context->compile_file, primarySymbolConverter, paramBeg, paramEnd);
	Node*  node_tree6 = parser6->slr(env3, "ele_begin", 0);

	if (node_tree6 == nullptr) {
		Util::log("Fail to parse parameters");
	}

	parser6->gen_middle_code(env3, node_tree6, imfo_map);

	MethodDeclaration* methodDeclaration = new MethodDeclaration(resultType, name);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {

		methodDeclaration->paramList.push_back(ParamDeclaration(e->unannType, e->name));
	}
	context->root->spaceList.push_back(methodDeclaration);
}


void JavaDeclareParser::fillWithStatementInterfaceMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;



	int paramBeg = ((StatementToken *)(env.list[0].get()))->statementEntity->begIndex;
	int paramEnd = ((StatementToken *)(env.list[0].get()))->statementEntity->endIndex;
	Env env3;
	parser6->init_total_lex_word_list(context->compile_file, primarySymbolConverter, paramBeg, paramEnd);
	Node*  node_tree6 = parser6->slr(env3, "ele_begin", 0);

	parser6->gen_middle_code(env3, node_tree6, imfo_map);

	InterfaceMethodDeclaration* interfaceMethodDeclaration = new InterfaceMethodDeclaration(resultType, name);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {

		interfaceMethodDeclaration->paramList.push_back(ParamDeclaration(e->unannType, e->name));
	}
	context->root->spaceList.push_back(interfaceMethodDeclaration);
}


void JavaDeclareParser::fillWithStatementAnnotationTypeElementDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	AnnotationTypeElementDeclaration* interfaceMethodDeclaration = new AnnotationTypeElementDeclaration(resultType, name);

	context->root->spaceList.push_back(interfaceMethodDeclaration);
}




void JavaDeclareParser::fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;

	//Util::log(((StatementToken *)(env2.list[0].get()))->statementEntity->name);
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

	//Util::log(""+((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex);
	//Util::log(""+((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex);
	int paramBeg = ((StatementToken *)(env.list[0].get()))->statementEntity->begIndex;
	int paramEnd = ((StatementToken *)(env.list[0].get()))->statementEntity->endIndex;
	Env env3;
	parser6->init_total_lex_word_list(context->compile_file, primarySymbolConverter, paramBeg, paramEnd);
	Node*  node_tree6 = parser6->slr(env3, "ele_begin", 0);

	parser6->gen_middle_code(env3, node_tree6, imfo_map);

	ConstructorDeclaration* constructorDeclaration = new ConstructorDeclaration(name);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
		Util::log(e->name);
		Util::log(e->unannType);
		constructorDeclaration->paramList.push_back(ParamDeclaration(e->unannType, e->name));
	}
	context->root->spaceList.push_back(constructorDeclaration);

	Node::releaseNode(node_tree6);
}



void JavaDeclareParser::fillWithClassTypeNormalClassDeclaration(P_Context &context, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	NormalClassDeclaration *p = new NormalClassDeclaration();

	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;

	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalClassDeclaration";
	childContext->token = ((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->statementList;


	StatementListToken *p2 = (StatementListToken *)(childContext->token.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endIndex += baseIndex;
		}
	}


	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
	;
}

void JavaDeclareParser::fillWithClassTypeEnumDeclaration(P_Context &context,  long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	EnumDeclaration *p = new EnumDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "EnumDeclaration";
	childContext->token = ((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->statementList;

	StatementListToken *p2 = (StatementListToken *)(childContext->token.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endIndex += baseIndex;
		}
	}

	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}


void JavaDeclareParser::fillWithClassTypeNormalInterfaceDeclaration(P_Context &context,  long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	NormalInterfaceDeclaration *p = new NormalInterfaceDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;


	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalInterfaceDeclaration";
	childContext->token = ((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->statementList;

	StatementListToken *p2 = (StatementListToken *)(childContext->token.get());

	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endIndex += baseIndex;
		}
	}

	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}


void JavaDeclareParser::fillWithClassTypeAnnotationTypeDeclaration(P_Context &context,  long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	AnnotationTypeDeclaration *p = new AnnotationTypeDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;


	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "AnnotationTypeDeclaration";
	childContext->token = ((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->statementList;

	StatementListToken *p2 = (StatementListToken *)(childContext->token.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endIndex += baseIndex;
		}
	}


	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}


string JavaDeclareParser::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()���ַ��ĳ��ȣ�ע��str������string����
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}

void JavaDeclareParser::parse(vector<string> &files) {
	for (const string &e : files) {
		Util::log(e);
		vector <string> strs;
		split(strs, e, is_any_of("\\"));
		string fileName = strs.back();
		string path = replaceAll(e, fileName, "");

		string compile_file = path + "\\" + fileName;

		P_Context context = P_Context(new Context());

		context->compile_file = compile_file;
		context->beginIndex = -1;
		context->endIndex = -1;
		context->type = "CompilationUnit";
		context->parent = nullptr;




		contextDeque.push_front(context);

		while (contextDeque.size() > 0) {
			P_Context presentContext = contextDeque.back();
			Util::log("process type=" + presentContext->type);
			processContext(presentContext);
			contextDeque.pop_back();
		}

		Util::log("asdas");

	}
}



void main(int argc, char* argv[]) {


	string files[] = {
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Generated.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\ManagedBean.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\PostConstruct.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\PreDestroy.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Priority.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Resource.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Resources.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\security\\DeclareRoles.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\security\\DenyAll.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\security\\PermitAll.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\security\\RolesAllowed.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\security\\RunAs.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\sql\\DataSourceDefinition.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\sql\\DataSourceDefinitions.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\ejb\\EJB.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\ejb\\EJBs.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ArrayELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\BeanELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\BeanNameELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\BeanNameResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\CompositeELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELClass.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELContextEvent.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELContextListener.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELException.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELManager.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELProcessor.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\EvaluationListener.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\Expression.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ExpressionFactory.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\FunctionMapper.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ImportHandler.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\LambdaExpression.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ListELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\MapELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\MethodExpression.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\MethodInfo.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\MethodNotFoundException.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\MethodReference.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\PropertyNotFoundException.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\PropertyNotWritableException.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ResourceBundleELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\StandardELContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\StaticFieldELResolver.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\TypeConverter.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\Util.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ValueExpression.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\ValueReference.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\VariableMapper.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\Authenticator.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\internet\\InternetAddress.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\internet\\MimeMessage.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\internet\\MimePart.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\internet\\MimePartDataSource.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\PasswordAuthentication.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\mail\\Session.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceContexts.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceContextType.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceProperty.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceUnit.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceUnits.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\SynchronizationType.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\AuthException.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\AuthStatus.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\CallerPrincipalCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\CertStoreCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\GroupPrincipalCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\PasswordValidationCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\PrivateKeyCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\SecretKeyCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\TrustStoreCallback.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\ClientAuth.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfig.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfigFactory.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfigProvider.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ClientAuthConfig.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ClientAuthContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\RegistrationListener.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ServerAuthConfig.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ServerAuthContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\MessageInfo.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\MessagePolicy.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\module\\ClientAuthModule.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\module\\ServerAuthModule.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\ServerAuth.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HandlesTypes.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HttpConstraint.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HttpMethodConstraint.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\MultipartConfig.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\ServletSecurity.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebFilter.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebInitParam.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebListener.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebServlet.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncContext.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncEvent.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncListener.java",
	};


	vector<string> filesVector;

	for (const auto &e : files) {
		filesVector.push_back(e);
	}

	Util::cleanLog();
	JavaDeclareParser javaDeclareParser;
	javaDeclareParser.initParsers();
	javaDeclareParser.parse(filesVector);
	javaDeclareParser.deleteParsers();

}


