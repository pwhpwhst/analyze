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
#include "pwh2.h"






using namespace std;
using namespace boost;
pwh2::pwh2() {}

pwh2::~pwh2() {}


void initParsers() {
	string rule_file4 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";
	string rule_file5 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R005.txt";
	string rule_file6 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R006.txt";
	string rule_file7 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R007.txt";
	string rule_file8 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R008.txt";
	string rule_file9 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R009.txt";

	parser4 = new RecursiveDescentJava();
	parser4->logSwitch = false;
	parser4->init(rule_file4);

	parser5 = new RecursiveDescentJava();
	parser5->logSwitch = false;
	parser5->init(rule_file5);

	parser6 = new RecursiveDescentJava();
	parser6->logSwitch = false;
	parser6->init(rule_file6);

	parser7 = new RecursiveDescentJava();
	parser7->logSwitch = false;
	parser7->init(rule_file7);


	parser8 = new RecursiveDescentJava();
	parser8->logSwitch = false;
	parser8->init(rule_file8);

	parser9 = new RecursiveDescentJava();
	parser9->logSwitch = false;
	parser9->init(rule_file9);
}

void deleteParsers() {
	delete parser4;
	delete parser5;
	delete parser6;
	delete parser7;
	delete parser8;
	delete parser9;
}

string replaceAll(string str, string sub, string replacement) {
	int pos;
	pos = str.find(sub);
	while (pos != -1) {
		// str.length()求字符的长度，注意str必须是string类型
		str.replace(pos, string(sub).length(), replacement);
		pos = str.find(sub);
	}

	return str;
}



void processContext(P_Context &context, deque<P_Context> &contextDeque) {


	PrimarySymbolConverter primarySymbolConverter;



	set<string> end_symbol_set0;


	if (context->type == "CompilationUnit") {
		processCompilationUnit(parser4,
			parser5,
			parser6,
			parser7,
			parser8,
			parser9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);

	}
	else if (context->type == "NormalClassDeclaration") {
		processNormalClassDeclaration(parser4,
			parser5,
			parser6,
			parser7,
			parser8,
			parser9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);
	}
	else if (context->type == "EnumDeclaration") {
		 processEnumDeclaration(parser4,
			 parser5,
			 parser6,
			 parser7,
			 parser8,
			 parser9,
			 primarySymbolConverter,
			 context, contextDeque,
			 end_symbol_set0);
	}
	else if (context->type == "NormalInterfaceDeclaration") {
		processNormalInterfaceDeclaration(parser4,
			parser5,
			parser6,
			parser7,
			parser8,
			parser9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);
	}
	else if (context->type == "AnnotationTypeDeclaration") {
		processAnnotationTypeMemberDeclaration(parser4,
			parser5,
			parser6,
			parser7,
			parser8,
			parser9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);
	}
}


void fillWithStatementConstantDeclaration(P_Context &context, Env &env) {

	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->root->spaceList.push_back(new ConstantDeclaration(e->unannType, e->name));
	}
}



void fillWithStatementFieldDeclaration(P_Context &context, Env &env) {

	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->root->spaceList.push_back(new FieldDeclaration(e->unannType, e->name));
	}
}

void fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;
	Util::log("MethodDeclaration:name:"+name);
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


void fillWithStatementInterfaceMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter) {
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


void fillWithStatementAnnotationTypeElementDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter) {
	unordered_map<string, string> imfo_map;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	AnnotationTypeElementDeclaration* interfaceMethodDeclaration = new AnnotationTypeElementDeclaration(resultType, name);

	context->root->spaceList.push_back(interfaceMethodDeclaration);
}




void fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter) {
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



void fillWithClassTypeNormalClassDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext) {
	NormalClassDeclaration *p = new NormalClassDeclaration();

	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;

	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalClassDeclaration";
	childContext->token = env.list[0];


	StatementListToken *p2 = (StatementListToken *)(((ClassListToken *)(childContext->token.get()))->list[0]->statementList.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begLineNum += basegLineNum;
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endLineNum += basegLineNum;
			p2->list[i1]->endIndex += baseIndex;
		}
	}


	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
;
}

void fillWithClassTypeEnumDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext) {
	EnumDeclaration *p = new EnumDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "EnumDeclaration";
	childContext->token = env.list[0];

	StatementListToken *p2 = (StatementListToken *)(((ClassListToken *)(childContext->token.get()))->list[0]->statementList.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begLineNum += basegLineNum;
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endLineNum += basegLineNum;
			p2->list[i1]->endIndex += baseIndex;
		}
	}

	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}


void fillWithClassTypeNormalInterfaceDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext) {
	NormalInterfaceDeclaration *p = new NormalInterfaceDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;


	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalInterfaceDeclaration";
	childContext->token = env.list[0];

	StatementListToken *p2 = (StatementListToken *)(((ClassListToken *)(childContext->token.get()))->list[0]->statementList.get());
	
	if (p2!=nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begLineNum += basegLineNum;
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endLineNum += basegLineNum;
			p2->list[i1]->endIndex += baseIndex;
		}
	}

	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}


void fillWithClassTypeAnnotationTypeDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext) {
	AnnotationTypeDeclaration *p = new AnnotationTypeDeclaration();


	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;


	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "AnnotationTypeDeclaration";
	childContext->token = env.list[0];

	StatementListToken *p2 = (StatementListToken *)(((ClassListToken *)(childContext->token.get()))->list[0]->statementList.get());
	if (p2 != nullptr) {
		for (int i1 = 0; i1 < p2->list.size(); i1++) {
			p2->list[i1]->begLineNum += basegLineNum;
			p2->list[i1]->begIndex += baseIndex;
			p2->list[i1]->endLineNum += basegLineNum;
			p2->list[i1]->endIndex += baseIndex;
		}
	}


	childContext->root = p;
	childContext->parent = context->root;
	context->root->spaceList.push_back(childContext->root);
}

void processNormalClassDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = ((ClassListToken *)((context->token).get()))->list[0]->statementList;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	if (p==nullptr) {
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
						fillWithStatementMethodDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);
					}

					if (statementType == "ConstructorDeclaration") {
						fillWithStatementConstructorDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);

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
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}
				}
			}

			if (statementType == "") {

				Util::log(string("statement[" + i1) + string("]:" + p->list[i1]->begIndex) + string("," + p->list[i1]->endIndex));
			}
		}
	}

}


void processNormalInterfaceDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = ((ClassListToken *)((context->token).get()))->list[0]->statementList;
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
						fillWithStatementInterfaceMethodDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

				}


			}

			if (statementType == "") {
				Util::log(string("statement[" + i1) + string("]:" + p->list[i1]->begIndex) + string("," + p->list[i1]->endIndex));
			}
		}
	}

}



void processEnumDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = ((ClassListToken *)((context->token).get()))->list[0]->statementList;
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
						fillWithStatementMethodDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);
					}

					if (statementType == "ConstructorDeclaration") {
						fillWithStatementConstructorDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);

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
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}
				}
			}

			if (statementType == "") {
				Util::log(string("statement[" + i1) + string("]:" + p->list[i1]->begIndex) + string("," + p->list[i1]->endIndex));

			}
		}
	}

}


void processAnnotationTypeMemberDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = ((ClassListToken *)((context->token).get()))->list[0]->statementList;
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
						fillWithStatementAnnotationTypeElementDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);
					}
					



					if (statementType == "InterfaceMethodDeclaration") {
						fillWithStatementInterfaceMethodDeclaration(context, env2, p, i1, parser6, primarySymbolConverter);
					}

					if (statementType == "NormalClassDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalClassDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "EnumDeclaration") {

						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeEnumDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);

					}

					if (statementType == "NormalInterfaceDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeNormalInterfaceDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}

					if (statementType == "AnnotationTypeDeclaration") {
						Env env3;
						parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
						Node*  node_tree4 = parser4->slr(env3, "ele_begin", 0);
						parser4->gen_middle_code(env3, node_tree4, imfo_map);


						P_Context childContext = nullptr;
						fillWithClassTypeAnnotationTypeDeclaration(context, p->list[i1]->begLineNum, p->list[i1]->begIndex, env3, childContext);
						contextDeque.push_front(childContext);
					}


				}


			}

			if (statementType == "") {
				Util::log(string("statement[" + i1) + string("]:" + p->list[i1]->begIndex) + string("," + p->list[i1]->endIndex));

			}
		}
	}
}



	void processCompilationUnit(Parser *parser4,
		Parser *parser5,
		Parser *parser6,
		Parser *parser7,
		Parser *parser8,
		Parser *parser9,
		PrimarySymbolConverter primarySymbolConverter,
		P_Context &context, deque<P_Context> &contextDeque,
		set<string> &end_symbol_set0){
		Env env;
		parser4->init_total_lex_word_list(context->compile_file, primarySymbolConverter, end_symbol_set0);
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

			string classType = ((ClassListToken *)(env.list[0].get()))->list[0]->type;

			

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
			long ZERO = 0;
			if (classType == "NormalClassDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeNormalClassDeclaration(context, ZERO, ZERO, env, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "EnumDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeEnumDeclaration(context, ZERO, ZERO, env, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "NormalInterfaceDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeNormalInterfaceDeclaration(context, ZERO, ZERO, env, childContext);
				contextDeque.push_front(childContext);
			}
			else if (classType == "AnnotationTypeDeclaration") {
				P_Context childContext = nullptr;
				fillWithClassTypeAnnotationTypeDeclaration(context,ZERO, ZERO, env, childContext);
				contextDeque.push_front(childContext);
			}

		}
}



void main(int argc, char* argv[]) {
	Util::cleanLog();

	initParsers();

	string files[] = { 
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceContextType.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceProperty.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceUnit.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\PersistenceUnits.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\persistence\\SynchronizationType.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\AuthException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\AuthStatus.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\CallerPrincipalCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\CertStoreCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\GroupPrincipalCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\PasswordValidationCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\PrivateKeyCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\SecretKeyCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\callback\\TrustStoreCallback.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\ClientAuth.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfigFactory.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\AuthConfigProvider.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ClientAuthConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ClientAuthContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\RegistrationListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ServerAuthConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\config\\ServerAuthContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\MessageInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\MessagePolicy.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\module\\ClientAuthModule.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\module\\ServerAuthModule.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\security\\auth\\message\\ServerAuth.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HandlesTypes.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HttpConstraint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\HttpMethodConstraint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\MultipartConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\ServletSecurity.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebInitParam.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\annotation\\WebServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\AsyncListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\descriptor\\JspConfigDescriptor.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\descriptor\\JspPropertyGroupDescriptor.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\descriptor\\TaglibDescriptor.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\DispatcherType.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\Filter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\FilterChain.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\FilterConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\FilterRegistration.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\GenericFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\GenericServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\Cookie.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServletMapping.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServletRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServletRequestWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServletResponse.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpServletResponseWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSession.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionActivationListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionAttributeListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionBindingEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionBindingListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionIdListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpSessionListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\HttpUpgradeHandler.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\MappingMatch.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\Part.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\PushBuilder.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\http\\WebConnection.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\HttpConstraintElement.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\HttpMethodConstraintElement.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ELException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ELParseException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\Expression.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ExpressionEvaluator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\FunctionMapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ImplicitObjectELResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ImportELResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\NotFoundELResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ScopedAttributeELResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\VariableResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\ErrorData.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\HttpJspPage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspApplicationContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspEngineInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspFactory.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspPage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspTagException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\JspWriter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\PageContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\SkipPageException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\BodyContent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\BodyTag.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\BodyTagSupport.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\DynamicAttributes.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\FunctionInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\IterationTag.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\JspFragment.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\JspIdConsumer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\JspTag.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\PageData.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\SimpleTag.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\SimpleTagSupport.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\Tag.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagAdapter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagAttributeInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagData.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagExtraInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagFileInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagLibraryInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagLibraryValidator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagSupport.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TagVariableInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\TryCatchFinally.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\ValidationMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\tagext\\VariableInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\MultipartConfigElement.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ReadListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\Registration.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\RequestDispatcher.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\Servlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletConnection.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContainerInitializer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContextAttributeEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContextAttributeListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContextEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletContextListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletInputStream.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletOutputStream.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRegistration.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequestAttributeEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequestAttributeListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequestEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequestListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletRequestWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletResponse.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletResponseWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\ServletSecurityElement.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\SessionCookieConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\SessionTrackingMode.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\UnavailableException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\WriteListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\HeuristicCommitException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\HeuristicMixedException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\HeuristicRollbackException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\InvalidTransactionException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\NotSupportedException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\RollbackException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\Status.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\Synchronization.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\SystemException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\Transaction.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\TransactionManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\TransactionRequiredException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\TransactionRolledbackException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\TransactionSynchronizationRegistry.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\transaction\\UserTransaction.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\ClientEndpoint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\ClientEndpointConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\CloseReason.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\ContainerProvider.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\DecodeException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\Decoder.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\DefaultClientEndpointConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\DeploymentException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\EncodeException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\Encoder.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\Endpoint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\EndpointConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\Extension.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\HandshakeResponse.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\MessageHandler.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\OnClose.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\OnError.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\OnMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\OnOpen.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\PongMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\RemoteEndpoint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\SendHandler.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\SendResult.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\DefaultServerEndpointConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\HandshakeRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\PathParam.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\ServerApplicationConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\ServerContainer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\ServerEndpoint.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\server\\ServerEndpointConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\Session.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\SessionException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\websocket\\WebSocketContainer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\xml\\ws\\WebServiceRef.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\xml\\ws\\WebServiceRefs.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\AccessLog.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\BaseRedirectorHelperTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\DeployTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\FindLeaksTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\JKStatusUpdateTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\Arg.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorCondition.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorConditionBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorCreateTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorEqualsCondition.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorGetTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorInvokeTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorQueryTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorSetTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\jmx\\JMXAccessorUnregisterTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\JMXGetTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\JMXQueryTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\JMXSetTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ListTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ReloadTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ResourcesTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ServerinfoTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\SessionsTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\SslConnectorCiphersTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\StartTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\StopTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ThreaddumpTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\UndeployTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\ValidatorTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ant\\VminfoTask.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\AsyncDispatcher.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\AuthenticatorBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\BasicAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\DigestAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\FormAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\AuthConfigFactoryImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\CallbackHandlerImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\MessageInfoImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\PersistentProviderRegistrations.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\SimpleAuthConfigProvider.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\SimpleServerAuthConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\jaspic\\SimpleServerAuthContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\NonLoginAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SavedRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SingleSignOn.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SingleSignOnEntry.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SingleSignOnListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SingleSignOnSessionKey.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SpnegoAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\authenticator\\SSLAuthenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Authenticator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Cluster.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\ClientAbortException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\Connector.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyoteAdapter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyoteInputStream.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyoteOutputStream.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyotePrincipal.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyoteReader.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\CoyoteWriter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\InputBuffer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\OutputBuffer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\Request.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\RequestFacade.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\Response.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\connector\\ResponseFacade.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Contained.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Container.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ContainerEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ContainerListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ContainerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Context.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\AccessLogAdapter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationContextFacade.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationDispatcher.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationFilterChain.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationFilterConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationFilterFactory.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationFilterRegistration.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationHttpRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationHttpResponse.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationMapping.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationPart.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationPushBuilder.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationResponse.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationServletRegistration.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationSessionCookieConfig.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\AprLifecycleListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\AprStatus.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\AsyncContextImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\AsyncListenerWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ContainerBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\DefaultInstanceManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\FrameworkListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\JniLifecycleListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\JreMemoryLeakPreventionListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\NamingContextListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardContextValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardEngine.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardEngineValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardHost.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardHostValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardPipeline.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardServer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardService.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardThreadExecutor.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardWrapperFacade.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardWrapperValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ThreadLocalLeakPreventionListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\CredentialHandler.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\deploy\\NamingResourcesImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\DistributedManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Engine.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Executor.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\AddDefaultCharsetFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\CorsFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\CsrfPreventionFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\CsrfPreventionFilterBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\ExpiresFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\FailedRequestFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\FilterBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\HttpHeaderSecurityFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RemoteAddrFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RemoteCIDRFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RemoteHostFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RemoteIpFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RequestDumperFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RequestFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\RestCsrfPreventionFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\SessionInitializerFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\SetCharacterEncodingFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\WebdavFixFilter.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Globals.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Group.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\authenticator\\ClusterSingleSignOn.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\authenticator\\ClusterSingleSignOnListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\CollectedInfo.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\HeartbeatListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\MultiCastSender.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\Proxy.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\Sender.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\backend\\TcpSender.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\CatalinaCluster.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterDeployer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterMessageBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterRuleSet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterSession.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\ClusterValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\context\\ReplicatedContext.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\FarmWarDeployer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\FileChangeListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\FileMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\FileMessageFactory.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\UndeployMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\deploy\\WarWatcher.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\BackupManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\ClusterManagerBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\ClusterSessionListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\DeltaManager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\DeltaRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\DeltaSession.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\JvmRouteBinderValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\ReplicatedSessionListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\SessionMessage.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\session\\SessionMessageImpl.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\tcp\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\tcp\\ReplicationValve.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\tcp\\SendMessageData.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\ha\\tcp\\SimpleTcpCluster.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Host.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\JmxEnabled.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Lifecycle.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\LifecycleEvent.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\LifecycleException.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\LifecycleListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\LifecycleState.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\JdbcLeakPrevention.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\ParallelWebappClassLoader.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\ResourceEntry.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\WebappClassLoader.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\WebappClassLoaderBase.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\loader\\WebappLoader.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Loader.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\DummyProxySession.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\host\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\host\\HostManagerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\host\\HTMLHostManagerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\HTMLManagerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\JMXProxyServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\JspHelper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\ManagerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\StatusManagerServlet.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\StatusTransformer.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\util\\BaseSessionComparator.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\util\\SessionUtils.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Manager.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mapper\\Constants.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mapper\\Mapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mapper\\MapperListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mapper\\MappingData.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mapper\\WrapperMappingInfo.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\BaseCatalinaMBean.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ClassNameMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ConnectorMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ContainerMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ContextEnvironmentMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ContextMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ContextResourceLinkMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ContextResourceMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\DataSourceUserDatabaseMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\GlobalResourcesLifecycleListener.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\GroupMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\MBeanDumper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\MBeanFactory.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\MBeanUtils.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\MemoryUserDatabaseMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\NamingResourcesMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\RoleMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\ServiceMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\SparseUserDatabaseMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\mbeans\\UserMBean.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\Pipeline.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\realm\\AuthenticatedUserRealm.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\realm\\CombinedRealm.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\realm\\DataSourceRealm.java",
	};





	for (const string &e: files) {
		Util::log(e);
		vector <string> strs;
		split(strs, e, is_any_of("\\"));
		string fileName = strs.back();
		string path = replaceAll(e, fileName, "");


		//string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el\\";
		//string fileName = "Expression.java";


		//string path = "C:\\Users\\Administrator\\Desktop\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\";
		//string fileName = "JavaSyntaxTest.java";



		string compile_file = path + "\\" + fileName;

		P_Context context = P_Context(new Context());

		context->compile_file = compile_file;
		context->beginIndex = -1;
		context->endIndex = -1;
		context->type = "CompilationUnit";
		context->parent = nullptr;



		deque<P_Context>  contextDeque;

		contextDeque.push_front(context);

		while (contextDeque.size() > 0) {
			P_Context presentContext=contextDeque.back();
			Util::log("process type=" + presentContext->type);
			processContext(presentContext, contextDeque);
			contextDeque.pop_back();
		}

		Util::log("asdas");

	}

	deleteParsers();

}
