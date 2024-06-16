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

	//parser4 = new RecursiveDescentJava();
	//parser4->logSwitch = false;
	//parser4->init(rule_file4);
	cout << "init parser4" << endl;
	parser4 = new Lalr();
	parser4->logSwitch = false;
	parser4->init(rule_file4);

	cout << "init parser5" << endl;
	parser5 = new Lalr();
	parser5->logSwitch = false;
	parser5->init(rule_file5);

	cout << "init parser6" << endl;
	parser6 = new Lalr();
	parser6->logSwitch = false;
	parser6->init(rule_file6);

	cout << "init parser7" << endl;
	parser7 = new Lalr();
	parser7->logSwitch = false;
	parser7->init(rule_file7);

	cout << "init parser8" << endl;
	parser8 = new Lalr();
	parser8->logSwitch = false;
	parser8->init(rule_file8);

	cout << "init parser9" << endl;
	parser9 = new Lalr();
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

				Util::log(string("statement[" + to_string(i1) ) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));
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
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));
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
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));

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

					if (statementType == "ConstantDeclarationFake"|| statementType == "AnnotationTypeElementDeclarationFake") {
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
				Util::log(string("statement[" + to_string(i1)) + string("]:" + to_string(p->list[i1]->begIndex)) + string("," + to_string(p->list[i1]->endIndex)));

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
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\servlet\\jsp\\el\\ImplicitObjectELResolver.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationFilterChain.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\ApplicationHttpRequest.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\core\\StandardWrapper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\filters\\ExpiresFilter.java",
 "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\JspHelper.java",
 //"C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\catalina\\manager\\util\\SessionUtils.java",
	};

	//string files[] = {
	//"F:\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\JavaSyntaxTest.java"
	//};



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
