#pragma once

#include"../Lalr.h"
#include "../Util/Util.h"
#include "../dao/TCompileFileDao.h"
#include "../dao/ErpClassDao.h"
#include "../dao/ErpMethodDao.h"
#include "../dao/ErpImportDao.h"

#include "../dao/TRawSpaceDao.h"
#include "../dao/TRawFieldDao.h"
#include "../dao/TRawClassDao.h"
#include "../dao/TRawMethodDao.h"
#include "../dao/TRawParmaDao.h"
#include "../dao/TRawTypeParmaDao.h"
#include "../dao/TRawSuperClassParmaDao.h"
#include "../dao/TRawPackageDao.h"
#include "../dao/TRawImportDao.h"
#include "../dao/TRawFileDao.h"


#include "../symbols/PrimarySymbolConverter.h"
#include "../space/java/Space.h"
#include "../RecursiveDescentJava.h"
#include "../symbols/java/ClassListToken.h"
#include "../symbols/java/StatementToken.h"
#include "../symbols/java/StatementListToken.h"
#include "../symbols/java/TypeToken.h"
#include "../symbols/java/TypeListToken.h"
#include "../symbols/java/ModifierListToken.h"
#include "../symbols/java/ModifierToken.h"


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


//process --
//fill ++



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


void JavaDeclareParser::setSpaceId(Space *&space, int parentId, int id) {
	space->parentId = parentId;
	space->id = id;
}


void JavaDeclareParser::initParsers() {
	string rule_file4 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";
	string rule_file5 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R005.txt";
	string rule_file6 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R006.txt";
	string rule_file7 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R007.txt";
	string rule_file8 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R008.txt";
	string rule_file9 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R009.txt";
	string rule_file10 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R010.txt";



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
	cout << "init parser10" << endl;
	initParser(parser10, "Lalr", false, rule_file10);

	primarySymbolConverter= new PrimarySymbolConverter();
}

void JavaDeclareParser::deleteParsers() {
	delete parser4;
	delete parser5;
	delete parser6;
	delete parser7;
	delete parser8;
	delete parser9;
	delete parser10;
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
						setSpaceId(context->root->spaceList.back(), context->root->id,seq++);
					}

					if (statementType == "InstanceInitializer") {
						context->root->spaceList.push_back(new InstanceInitializer());
						setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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
			setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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
						setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
					}

					if (statementType == "InstanceInitializer") {
						context->root->spaceList.push_back(new InstanceInitializer());
						setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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
		p->id = seq;
		seq++;

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
		setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
	}
}



void JavaDeclareParser::fillWithStatementFieldDeclaration(P_Context &context, Env &env) {

	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->root->spaceList.push_back(new FieldDeclaration(e->unannType, e->name));
		setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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

	if (((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters!=nullptr) {
		TypeListToken *typeParameters = (TypeListToken *)((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters.get();
		typeParameters->begIndex + p->list[i1]->begIndex;
		typeParameters->endIndex + p->list[i1]->begIndex;

		Env env10;
		parser10->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
		parser10->init_total_lex_word_list2(typeParameters->begIndex + p->list[i1]->begIndex, typeParameters->endIndex + p->list[i1]->begIndex, primarySymbolConverter);
		Node*  node_tree10 = parser10->slr(env10, "ele_begin", 0);
		imfo_map.clear();
		parser10->gen_middle_code(env10, node_tree10, imfo_map);

		for (auto &e : ((TypeListToken *)(env10.list[0].get()))->list) {
			methodDeclaration->typeParameters.push_back(e->name);
		}
	}



	
	context->root->spaceList.push_back(methodDeclaration);
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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

	if (((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters!=nullptr) {
		ModifierToken *typeParameters = (ModifierToken *)((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters.get();
		typeParameters->modifierEntity->begIndex + p->list[i1]->begIndex;
		typeParameters->modifierEntity->endIndex + p->list[i1]->begIndex;


		Env env10;
		parser10->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
		parser10->init_total_lex_word_list2(typeParameters->modifierEntity->begIndex + p->list[i1]->begIndex, typeParameters->modifierEntity->endIndex + p->list[i1]->begIndex, primarySymbolConverter);
		Node*  node_tree10 = parser10->slr(env10, "ele_begin", 0);
		imfo_map.clear();
		parser10->gen_middle_code(env10, node_tree10, imfo_map);

		for (auto &e : ((TypeListToken *)(env10.list[0].get()))->list) {
			interfaceMethodDeclaration->typeParameters.push_back(e->name);
		}
	}




	context->root->spaceList.push_back(interfaceMethodDeclaration);
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
}


void JavaDeclareParser::fillWithStatementAnnotationTypeElementDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	AnnotationTypeElementDeclaration* interfaceMethodDeclaration = new AnnotationTypeElementDeclaration(resultType, name);

	context->root->spaceList.push_back(interfaceMethodDeclaration);
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
}




void JavaDeclareParser::fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1) {
	unordered_map<string, string> imfo_map;


	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;






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


	if (((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters != nullptr) {
		TypeListToken *typeParameters = (TypeListToken *)((StatementToken *)(env.list[0].get()))->statementEntity->typeParameters.get();
		typeParameters->begIndex + p->list[i1]->begIndex;
		typeParameters->endIndex + p->list[i1]->begIndex;

		Env env10;
		parser10->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
		parser10->init_total_lex_word_list2(typeParameters->begIndex + p->list[i1]->begIndex, typeParameters->endIndex + p->list[i1]->begIndex, primarySymbolConverter);
		Node*  node_tree10 = parser10->slr(env10, "ele_begin", 0);
		imfo_map.clear();
		parser10->gen_middle_code(env10, node_tree10, imfo_map);

		for (auto &e : ((TypeListToken *)(env10.list[0].get()))->list) {
			constructorDeclaration->typeParameters.push_back(e->name);
		}
	}


	context->root->spaceList.push_back(constructorDeclaration);
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);

	Node::releaseNode(node_tree6);
}



void JavaDeclareParser::fillWithClassTypeNormalClassDeclaration(P_Context &context, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	
	unordered_map<string, string> imfo_map;
	
	NormalClassDeclaration *p = new NormalClassDeclaration();

	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;

	TypeToken* pSuperClasses = (TypeToken*)((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->superClass.get();
	TypeListToken* pSuperInterfaces = (TypeListToken*)((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->superInterfaceList.get();



	if (pSuperClasses!=nullptr) {
		p->superClasses=pSuperClasses->typeEntity->name;
	}
	
	if (pSuperInterfaces != nullptr) {

		for (auto &e: pSuperInterfaces->list) {
			p->superInterface.push_back(e->name);
		}

	}

	if (((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->typeParameters) {
		StatementToken *typeParameters = (StatementToken*)((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->typeParameters.get();


		Env env10;
		parser10->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
		parser10->init_total_lex_word_list2(typeParameters->statementEntity->begIndex + baseIndex, typeParameters->statementEntity->endIndex + baseIndex, primarySymbolConverter);
		Node*  node_tree10 = parser10->slr(env10, "ele_begin", 0);
		imfo_map.clear();
		parser10->gen_middle_code(env10, node_tree10, imfo_map);

		for (auto &e : ((TypeListToken *)(env10.list[0].get()))->list) {
			p->typeParameters.push_back(e->name);
		}

	}


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
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
}


void JavaDeclareParser::fillWithClassTypeNormalInterfaceDeclaration(P_Context &context,  long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext) {
	NormalInterfaceDeclaration *p = new NormalInterfaceDeclaration();
	unordered_map<string, string> imfo_map;

	p->name = ((ClassListToken *)(env.list[0].get()))->list[classTypeIndex]->name;


	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalInterfaceDeclaration";
	childContext->token = ((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->statementList;

	if (((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->typeParameters) {
		StatementToken *typeParameters = (StatementToken*)((ClassListToken *)((env.list[0]).get()))->list[classTypeIndex]->typeParameters.get();


		Env env10;
		parser10->init_total_lex_word_list(context->compile_file, primarySymbolConverter);
		parser10->init_total_lex_word_list2(typeParameters->statementEntity->begIndex + baseIndex, typeParameters->statementEntity->endIndex + baseIndex, primarySymbolConverter);
		Node*  node_tree10 = parser10->slr(env10, "ele_begin", 0);
		imfo_map.clear();
		parser10->gen_middle_code(env10, node_tree10, imfo_map);

		for (auto &e : ((TypeListToken *)(env10.list[0].get()))->list) {
			p->typeParameters.push_back(e->name);
		}
	
	}




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
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
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
	setSpaceId(context->root->spaceList.back(), context->root->id, seq++);
}


string JavaDeclareParser::replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}

void JavaDeclareParser::parse(vector<string> &files,string appName) {
	int fileId = 0;
	for (const string &e : files) {
		seq = 0;
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
		saveResult(context, appName,e, fileId++);

		

	}
}

void JavaDeclareParser::saveResult( P_Context &context, const string &appName, const string &fileName, int fileId) {
	vector<unordered_map<string, string>> fileList;
	vector<unordered_map<string, string>> packageList;
	vector<unordered_map<string, string>> importList;

	vector<unordered_map<string, string>> spaceList;
	vector<unordered_map<string, string>> classList;
	vector<unordered_map<string, string>> superClassList;
	vector<unordered_map<string, string>> typeParameterList;

	vector<unordered_map<string, string>> paramaterList;
	vector<unordered_map<string, string>> methodList;
	vector<unordered_map<string, string>> fieldList;
	

	fileList.push_back(unordered_map<string, string>());
	unordered_map<string, string> &map = fileList.back();
	map["appName"] = appName;
	map["fileId"] = std::to_string(fileId);
	string fileName2 = replaceAll(replaceAll(fileName, "\\", "&"), "&", "\\\\");
	map["fileName"] = fileName2;

	CompilationUnit* compilationUnit = (CompilationUnit*)context->root;

	if (compilationUnit->package!="") {
		packageList.push_back(unordered_map<string, string>());
		unordered_map<string, string> &map=packageList.back();
		map["appName"] = appName;
		map["fileId"] = std::to_string(fileId);
		map["content"] = ((CompilationUnit*)context->root)->package;
		
	}


	if (compilationUnit->importList.size()>0) {
		int index = 0;
		for (const auto &e: compilationUnit->importList) {
			importList.push_back(unordered_map<string, string>());
			unordered_map<string, string> &map = importList.back();

			map["appName"] = appName;
			map["fileId"] = std::to_string(fileId);
			map["subId"] = std::to_string(index);
			map["content"] = e.name;
			index++;
			
		}
	}

	if (compilationUnit->spaceList.size() > 0) {
		deque<Space*> stack;
		set<Space*> hasVisit;
		stack.push_back(compilationUnit->spaceList[0]);
		while (stack.size()>0) {
			Space * pSpack=stack.back();
			if (pSpack->spaceList.size()>0 && hasVisit.count(pSpack->spaceList[0])==0 ) {
				for (int i1 = pSpack->spaceList.size() - 1; i1 >= 0;i1--) {
					stack.push_back(pSpack->spaceList[i1]);
				}
			}
			else {

				if (pSpack->type=="AnnotationTypeDeclaration"|| pSpack->type == "EnumDeclaration" ||
					pSpack->type == "NormalClassDeclaration" || pSpack->type == "NormalInterfaceDeclaration") {

					
					spaceList.push_back(unordered_map<string, string>());
					unordered_map<string, string> &map = spaceList.back();
					map["appName"] = appName;
					//string fileName2 = replaceAll(replaceAll(fileName, "\\", "&"), "&", "\\\\");
					//map["fileName"] = fileName2;
					map["fileId"] = std::to_string(fileId);
					map["subId"] = std::to_string(pSpack->id);
					map["parentId"] = std::to_string(pSpack->parentId);
					map["spaceType"] = pSpack->type;
					map["begLine"] = std::to_string(pSpack->begLine);
					map["endLine"] = std::to_string(pSpack->endLine);
					map["begIndex"] = std::to_string(pSpack->begIndex);
					map["endIndex"] = std::to_string(pSpack->endIndex);
					
					classList.push_back(unordered_map<string, string>());
					unordered_map<string, string> &map2 = classList.back();
					map2["appName"] = appName;
					map2["fileId"] = std::to_string(fileId);
					map2["subId"] = std::to_string(pSpack->id);
					map2["classType"] = pSpack->type;

					if (pSpack->type == "AnnotationTypeDeclaration") {
						AnnotationTypeDeclaration* pSpace=(AnnotationTypeDeclaration*)pSpack;
						map2["name"] = pSpace->name;
					}
					else if (pSpack->type == "EnumDeclaration") {
						EnumDeclaration* pSpace = (EnumDeclaration*)pSpack;
						map2["name"] = pSpace->name;

						if (pSpace->superInterfaces.size() > 0) {
							int index2 = 0;
							for (const auto &e : pSpace->superInterfaces) {
								superClassList.push_back(unordered_map<string, string>());
								unordered_map<string, string> &map3 = superClassList.back();
								map3["appName"] = appName;
								map3["fileId"] = std::to_string(fileId);
								map3["subId"] = std::to_string(pSpack->id);
								map3["subId2"] = std::to_string(index2);
								map3["classType"] = "interface";
								map3["name"] = e;
								index2++;
							}
						}

					}
					else if (pSpack->type == "NormalClassDeclaration") {
						NormalClassDeclaration* pSpace = (NormalClassDeclaration*)pSpack;
						map2["name"] = pSpace->name;

						
						if (pSpace->superInterface.size()>0) {
							int index2 = 0;
							for (const auto &e : pSpace->superInterface) {
								superClassList.push_back(unordered_map<string, string>());
								unordered_map<string, string> &map3 = superClassList.back();
								map3["appName"] = appName;
								map3["fileId"] = std::to_string(fileId);
								map3["subId"] = std::to_string(pSpack->id);
								map3["subId2"] = std::to_string(index2);
								map3["classType"] = "interface";
								map3["name"] = e;
								index2++;
							}
						}


						if (pSpace->superClasses!="") {
							superClassList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map3 = superClassList.back();
							map3["appName"] = appName;
							map3["fileId"] = std::to_string(fileId);
							map3["subId"] = std::to_string(pSpack->id);
							map3["subId2"] = "0";
							map3["classType"] = "class";
							map3["name"] = pSpace->superClasses;
						}


						if (pSpace->typeParameters.size()>0) {
							int index2 = 0;
							for (const auto &e : pSpace->typeParameters) {
								typeParameterList.push_back(unordered_map<string, string>());
								unordered_map<string, string> &map3 = typeParameterList.back();
								map3["appName"] = appName;
								map3["fileId"] = std::to_string(fileId);
								map3["subId"] = std::to_string(pSpack->id);
								map3["subId2"] = std::to_string(index2);
								map3["name"] = e;
								index2++;
							}
						}

					}
					else if (pSpack->type == "NormalInterfaceDeclaration") {
						NormalInterfaceDeclaration* pSpace = (NormalInterfaceDeclaration*)pSpack;
						map2["name"] = pSpace->name;

						if (pSpace->superInterface.size() > 0) {
							int index2 = 0;
							for (const auto &e : pSpace->superInterface) {
								superClassList.push_back(unordered_map<string, string>());
								unordered_map<string, string> &map3 = superClassList.back();
								map3["appName"] = appName;
								map3["fileId"] = std::to_string(fileId);
								map3["subId"] = std::to_string(pSpack->id);
								map3["subId2"] = std::to_string(index2);
								map3["classType"] = "interface";
								map3["name"] = e;
								index2++;
							}
						}



						if (pSpace->typeParameters.size() > 0) {
							int index2 = 0;
							for (const auto &e : pSpace->typeParameters) {
								typeParameterList.push_back(unordered_map<string, string>());
								unordered_map<string, string> &map3 = typeParameterList.back();
								map3["appName"] = appName;
								map3["fileId"] = std::to_string(fileId);
								map3["subId"] = std::to_string(pSpack->id);
								map3["subId2"] = std::to_string(index2);
								map3["name"] = e;
								index2++;
							}
						}

					}

					
				}else if (pSpack->type == "InterfaceMethodDeclaration"|| pSpack->type == "MethodDeclaration"
						|| pSpack->type == "ConstructorDeclaration") {

					spaceList.push_back(unordered_map<string, string>());
					unordered_map<string, string> &map = spaceList.back();

					map["appName"] = appName;
					//string fileName2 = replaceAll(replaceAll(fileName, "\\", "&"), "&", "\\\\");
					//map["fileName"] = fileName2;
					map["fileId"] = std::to_string(fileId);
					map["subId"] = std::to_string(pSpack->id);
					map["parentId"] = std::to_string(pSpack->parentId);
					map["spaceType"] = pSpack->type;
					map["begLine"] = std::to_string(pSpack->begLine);
					map["endLine"] = std::to_string(pSpack->endLine);
					map["begIndex"] = std::to_string(pSpack->begIndex);
					map["endIndex"] = std::to_string(pSpack->endIndex);
					

					if (pSpack->type == "InterfaceMethodDeclaration") {
						InterfaceMethodDeclaration* pSpace = (InterfaceMethodDeclaration*)pSpack;
						methodList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = methodList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["name"] = pSpace->name;
						map2["resultType"] = pSpace->type;



						int index = 0;
						for (const auto &e : pSpace->paramList) {
							paramaterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map3 = paramaterList.back();
							map3["appName"] = appName;
							map3["fileId"] = std::to_string(fileId);
							map3["subId"] = std::to_string(pSpack->id);
							map3["subId2"] = std::to_string(index);
							map3["resultType"] = e.type;
							map3["name"] = e.name;
							index++;
						}


						index = 0;
						for (const auto &e : pSpace->typeParameters) {
							typeParameterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map4 = typeParameterList.back();
							map4["appName"] = appName;
							map4["fileId"] = std::to_string(fileId);
							map4["subId"] = std::to_string(pSpack->id);
							map4["subId2"] = index;
							map4["name"] = e;
							index++;
						}



					}
					else if (pSpack->type == "MethodDeclaration") {
						MethodDeclaration* pSpace = (MethodDeclaration*)pSpack;
						methodList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = methodList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["name"] = pSpace->name;
						map2["resultType"] = pSpace->type;



						int index = 0;
						for (const auto &e:pSpace->paramList) {
							paramaterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map3 = paramaterList.back();
							map3["appName"] = appName;
							map3["fileId"] = std::to_string(fileId);
							map3["subId"] = std::to_string(pSpack->id);
							map3["subId2"] = std::to_string(index);
							map3["resultType"] = e.type;
							map3["name"] = e.name;
							index++;
						}



						index = 0;
						for (const auto &e : pSpace->typeParameters) {
							typeParameterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map4 = typeParameterList.back();
							map4["appName"] = appName;
							map4["fileId"] = std::to_string(fileId);
							map4["subId"] = std::to_string(pSpack->id);
							map4["subId2"] = index;
							map4["name"] = e;
							index++;
						}


					}
					else if (pSpack->type == "ConstructorDeclaration") {
						ConstructorDeclaration* pSpace = (ConstructorDeclaration*)pSpack;
						methodList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = methodList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["name"] = pSpace->name;
						map2["resultType"] ="";



						int index = 0;
						for (const auto &e : pSpace->paramList) {
							paramaterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map3 = paramaterList.back();
							map3["appName"] = appName;
							map3["fileId"] = std::to_string(fileId);
							map3["subId"] = std::to_string(pSpack->id);
							map3["subId2"] = std::to_string(index);
							map3["resultType"] = e.type;
							map3["name"] = e.name;
							index++;
						}



						index = 0;
						for (const auto &e : pSpace->typeParameters) {
							typeParameterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map4 = typeParameterList.back();
							map4["appName"] = appName;
							map4["fileId"] = std::to_string(fileId);
							map4["subId"] = std::to_string(pSpack->id);
							map4["subId2"] = index;
							map4["name"] = e;
							index++;
						}

					}

				}
				else if (pSpack->type == "ConstantDeclaration" || pSpack->type == "FieldDeclaration" 
					|| pSpack->type == "AnnotationTypeElementDeclaration" || pSpack->type == "EnumConstant") {

					spaceList.push_back(unordered_map<string, string>());
					unordered_map<string, string> &map = spaceList.back();

					map["appName"] = appName;
					//string fileName2 = replaceAll(replaceAll(fileName, "\\", "&"), "&", "\\\\");
					//map["fileName"] = fileName2;
					map["fileId"] = std::to_string(fileId);
					map["subId"] = std::to_string(pSpack->id);
					map["parentId"] = std::to_string(pSpack->parentId);
					map["spaceType"] = pSpack->type;
					map["begLine"] = std::to_string(pSpack->begLine);
					map["endLine"] = std::to_string(pSpack->endLine);
					map["begIndex"] = std::to_string(pSpack->begIndex);
					map["endIndex"] = std::to_string(pSpack->endIndex);
					

					if (pSpack->type == "ConstantDeclaration") {
						ConstantDeclaration* pSpace = (ConstantDeclaration*)pSpack;
						fieldList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = fieldList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["subId2"] = "-1";
						map2["resultType"] = pSpace->type;
						map2["name"] = pSpace->name;
						map2["dimNum"] = "-1";

					}else if (pSpack->type == "FieldDeclaration") {
						FieldDeclaration* pSpace = (FieldDeclaration*)pSpack;
						fieldList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = fieldList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["subId2"] = "-1";
						map2["resultType"] = pSpace->type;
						map2["name"] = pSpace->name;
						map2["dimNum"] = "-1";

					}
					else if (pSpack->type == "AnnotationTypeElementDeclaration") {
						AnnotationTypeElementDeclaration* pSpace = (AnnotationTypeElementDeclaration*)pSpack;
						fieldList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = fieldList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["subId2"] = "-1";
						map2["resultType"] = pSpace->type;
						map2["name"] = pSpace->name;
						map2["dimNum"] = pSpace->dimNum;

					}
					else if (pSpack->type == "EnumConstant") {
						EnumConstant* pSpace = (EnumConstant*)pSpack;
						fieldList.push_back(unordered_map<string, string>());
						unordered_map<string, string> &map2 = fieldList.back();

						map2["appName"] = appName;
						map2["fileId"] = std::to_string(fileId);
						map2["subId"] = std::to_string(pSpack->id);
						map2["subId2"] = "-1";
						map2["resultType"] = "";
						map2["name"] = pSpace->name;
						map2["dimNum"] = "-1";



						int index = 0;
						for (const auto &e : pSpace->paramList) {
							paramaterList.push_back(unordered_map<string, string>());
							unordered_map<string, string> &map3 = paramaterList.back();
							map3["appName"] = appName;
							map3["fileId"] = std::to_string(fileId);
							map3["subId"] = std::to_string(pSpack->id);
							map3["subId2"] = std::to_string(index);
							map3["resultType"] = "";
							map3["name"] = e.name;
							index++;
						}

					}
					
				}

				hasVisit.insert(pSpack);
				stack.pop_back();
			}
		}
	}
	
	P_TRawFileDao tRawFileDao = TRawFileDao::getInstance();
	P_TRawPackageDao tRawPackageDao = TRawPackageDao::getInstance();
	P_TRawImportDao tRawImportDao = TRawImportDao::getInstance();
	P_TRawSpaceDao tRawSpaceDao = TRawSpaceDao::getInstance();
	P_TRawFieldDao tRawFieldDao = TRawFieldDao::getInstance();
	P_TRawClassDao tRawClassDao = TRawClassDao::getInstance();
	P_TRawMethodDao tRawMethodDao = TRawMethodDao::getInstance();
	P_TRawParmaDao tRawParmaDao = TRawParmaDao::getInstance();
	P_TRawTypeParmaDao tRawTypeParmaDao = TRawTypeParmaDao::getInstance();
	P_TRawSuperClassParmaDao tRawSuperClassParmaDao = TRawSuperClassParmaDao::getInstance();

	tRawFileDao->insertList(fileList);
	tRawPackageDao->insertList(packageList);
	tRawImportDao->insertList(importList);
	tRawSpaceDao->insertList(spaceList);

	tRawFieldDao->insertList(fieldList);
	tRawClassDao->insertList(classList);
	tRawMethodDao->insertList(methodList);

	tRawParmaDao->insertList(paramaterList);
	tRawTypeParmaDao->insertList(typeParameterList);
	tRawSuperClassParmaDao->insertList(superClassList);



	Util::log("asdas2");
}



void main(int argc, char* argv[]) {

	//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaAnnotation.java",
	//"F :\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaEnumTest.java",
	//"F :\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaInterfaceTest.java",
	//"F :\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaSyntaxTest.java",
	
	
	string appName = "Tomcat8";

	string files[] = {
		//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaAnnotation.java",
		//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaEnumTest.java",
		//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaInterfaceTest.java",
		//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaInterfaceTest.java",
		"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaSyntaxTest.java",
	};


	vector<string> filesVector;

	for (const auto &e : files) {
		filesVector.push_back(e);
	}

	Util::cleanLog();
	JavaDeclareParser javaDeclareParser;
	javaDeclareParser.initParsers();
	javaDeclareParser.parse(filesVector, appName);
	javaDeclareParser.deleteParsers();

}



