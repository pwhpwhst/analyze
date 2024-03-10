#pragma once
#include "pwh2.h"
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






using namespace std;
pwh2::pwh2() {}
pwh2::~pwh2() {}


struct Context {
	string compile_file;
	int beginIndex;
	int endIndex;
	string type;
	P_Token token;
	Space *parent;
	Space *root;
};

typedef std::shared_ptr<Context> P_Context;

void processContext(P_Context &context, deque<P_Context> &contextDeque);

void processCompilationUnit(RecursiveDescentJava &recursiveDescentJava4,
	RecursiveDescentJava &recursiveDescentJava5,
	RecursiveDescentJava &recursiveDescentJava6,
	RecursiveDescentJava &recursiveDescentJava7,
	RecursiveDescentJava &recursiveDescentJava8,
	RecursiveDescentJava &recursiveDescentJava9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);


void processNormalClassDeclaration(RecursiveDescentJava &recursiveDescentJava4,
	RecursiveDescentJava &recursiveDescentJava5,
	RecursiveDescentJava &recursiveDescentJava6,
	RecursiveDescentJava &recursiveDescentJava7,
	RecursiveDescentJava &recursiveDescentJava8,
	RecursiveDescentJava &recursiveDescentJava9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);


void fillWithStatementFieldDeclaration(P_Context &context, Env &env);
void fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, RecursiveDescentJava &recursiveDescentJava6,
	PrimarySymbolConverter &primarySymbolConverter);
void fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, RecursiveDescentJava &recursiveDescentJava6,
	PrimarySymbolConverter &primarySymbolConverter);
void fillWithClassTypeNormalClassDeclaration(P_Context &context, Env &env, P_Context &childContext);
void fillWithClassTypeEnumDeclaration(P_Context &context, Env &env, P_Context &childContext);
void fillWithClassTypeNormalInterfaceDeclaration(P_Context &context, Env &env, P_Context &childContext);
void fillWithClassTypeAnnotationTypeDeclaration(P_Context &context, Env &env, P_Context &childContext);


void processContext(P_Context &context, deque<P_Context> &contextDeque) {

	string rule_file4 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R004.txt";
	string rule_file5 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R005.txt";
	string rule_file6 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R006.txt";
	string rule_file7 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R007.txt";
	string rule_file8 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R008.txt";
	string rule_file9 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R009.txt";

	PrimarySymbolConverter primarySymbolConverter;

	RecursiveDescentJava recursiveDescentJava4;
	recursiveDescentJava4.logSwitch = false;
	recursiveDescentJava4.init(rule_file4);

	RecursiveDescentJava recursiveDescentJava5;
	recursiveDescentJava5.logSwitch = false;
	recursiveDescentJava5.init(rule_file5);

	RecursiveDescentJava recursiveDescentJava6;
	recursiveDescentJava6.logSwitch = false;
	recursiveDescentJava6.init(rule_file6);

	RecursiveDescentJava recursiveDescentJava7;
	recursiveDescentJava7.logSwitch = false;
	recursiveDescentJava7.init(rule_file7);


	RecursiveDescentJava recursiveDescentJava8;
	recursiveDescentJava8.logSwitch = false;
	recursiveDescentJava8.init(rule_file8);

	RecursiveDescentJava recursiveDescentJava9;
	recursiveDescentJava9.logSwitch = false;
	recursiveDescentJava9.init(rule_file9);

	set<string> end_symbol_set0;


	if (context->type == "CompilationUnit") {
		processCompilationUnit(recursiveDescentJava4,
			recursiveDescentJava5,
			recursiveDescentJava6,
			recursiveDescentJava7,
			recursiveDescentJava8,
			recursiveDescentJava9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);

	}
	else if (context->type == "NormalClassDeclaration") {
		processNormalClassDeclaration(recursiveDescentJava4,
			recursiveDescentJava5,
			recursiveDescentJava6,
			recursiveDescentJava7,
			recursiveDescentJava8,
			recursiveDescentJava9,
			primarySymbolConverter,
			context, contextDeque,
			end_symbol_set0);
	}
	else if (context->type == "EnumDeclaration") {
		cout << "dasda2" << endl;
	}
	else if (context->type == "NormalInterfaceDeclaration") {
		cout << "dasda3" << endl;
	}
	else if (context->type == "AnnotationTypeDeclaration") {
		cout << "dasda4" << endl;
	}
}


void fillWithStatementFieldDeclaration(P_Context &context, Env &env) {
	//for (auto &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->fieldList) {
//	cout << e->name << endl;
//	cout << e->unannType << endl;
//}
	for (auto &e : ((StatementToken *)(env.list[0].get()))->statementEntity->fieldList) {
		context->parent->spaceList.push_back(new FieldDeclaration(e->unannType, e->name));
	}
}

void fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, RecursiveDescentJava &recursiveDescentJava6, 
	PrimarySymbolConverter &primarySymbolConverter) {
	unordered_map<string, string> imfo_map;
	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->resultType << endl;
	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;

	string resultType = ((StatementToken *)(env.list[0].get()))->statementEntity->resultType;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;

	int paramBeg = ((StatementToken *)(env.list[0].get()))->statementEntity->begIndex;
	int paramEnd = ((StatementToken *)(env.list[0].get()))->statementEntity->endIndex;
	Env env3;
	recursiveDescentJava6.init_total_lex_word_list(context->compile_file, primarySymbolConverter, paramBeg, paramEnd);
	Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

	recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);

	MethodDeclaration* methodDeclaration = new MethodDeclaration(resultType, name);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
		//cout << e->name << endl;
		//cout << e->unannType << endl;
		methodDeclaration->paramList.push_back(ParamDeclaration(e->unannType, e->name));
	}
	context->parent->spaceList.push_back(methodDeclaration);
}


void fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, RecursiveDescentJava &recursiveDescentJava6,
	PrimarySymbolConverter &primarySymbolConverter) {
	unordered_map<string, string> imfo_map;

	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;
	string name = ((StatementToken *)(env.list[0].get()))->statementEntity->name;

	((StatementToken *)(env.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
	((StatementToken *)(env.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
	//cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;
	int paramBeg = ((StatementToken *)(env.list[0].get()))->statementEntity->begIndex;
	int paramEnd = ((StatementToken *)(env.list[0].get()))->statementEntity->endIndex;
	Env env3;
	recursiveDescentJava6.init_total_lex_word_list(context->compile_file, primarySymbolConverter, paramBeg, paramEnd);
	Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

	recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);

	ConstructorDeclaration* constructorDeclaration = new ConstructorDeclaration(name);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
		//cout << e->name << endl;
		//cout << e->unannType << endl;
		constructorDeclaration->paramList.push_back(ParamDeclaration(e->unannType, e->name));
	}
	context->parent->spaceList.push_back(constructorDeclaration);

	Node::releaseNode(node_tree6);
}


void processNormalClassDeclaration(RecursiveDescentJava &recursiveDescentJava4,
	RecursiveDescentJava &recursiveDescentJava5,
	RecursiveDescentJava &recursiveDescentJava6,
	RecursiveDescentJava &recursiveDescentJava7,
	RecursiveDescentJava &recursiveDescentJava8,
	RecursiveDescentJava &recursiveDescentJava9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0) {

	unordered_map<string, string> imfo_map;
	P_Token statementListP = ((ClassListToken *)((context->token).get()))->list[0]->statementList;
	StatementListToken *p = (StatementListToken *)statementListP.get();

	


	for (int i1 = 0; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				recursiveDescentJava5.init_total_lex_word_list(context->compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree5 = recursiveDescentJava5.slr(env2, "ele_begin", 0);

				if (node_tree5 != nullptr) {

					recursiveDescentJava5.gen_middle_code(env2, node_tree5, imfo_map);
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

					//cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
					//cout << "statementType:" << statementType << endl;

					if (statementType == "FieldDeclaration") {
						fillWithStatementFieldDeclaration(context, env2);
					}


					if (statementType == "MethodDeclaration") {
						fillWithStatementMethodDeclaration(context, env2, p, i1, recursiveDescentJava6, primarySymbolConverter);
					}

					if (statementType == "ConstructorDeclaration") {
						fillWithStatementConstructorDeclaration(context, env2, p, i1, recursiveDescentJava6,primarySymbolConverter);

					}

					if (statementType == "StaticInitializer") {
						context->parent->spaceList.push_back(new StaticInitializer());
					}
					
					if (statementType == "InstanceInitializer") {
						context->parent->spaceList.push_back(new InstanceInitializer());
					}

					if (statementType == "NormalClassDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						context->parent->spaceList.push_back(new NormalClassDeclaration(name));
					}

					if (statementType == "EnumDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						context->parent->spaceList.push_back(new EnumDeclaration(name));
					}

					if (statementType == "NormalInterfaceDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						context->parent->spaceList.push_back(new NormalInterfaceDeclaration(name));
					}

					if (statementType == "AnnotationTypeDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						context->parent->spaceList.push_back(new AnnotationTypeDeclaration(name));
					}
				}
			}

			if (statementType == "") {
				cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
			}
		}
	}

}

void fillWithClassTypeNormalClassDeclaration(P_Context &context,Env &env, P_Context &childContext) {
	NormalClassDeclaration *p = new NormalClassDeclaration();


	if (context->root == nullptr) {
		context->root = p;
	}

	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;
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



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalClassDeclaration";
	childContext->token = env.list[0];
	childContext->parent = context->root;
}

void fillWithClassTypeEnumDeclaration(P_Context &context, Env &env, P_Context &childContext) {
	EnumDeclaration *p = new EnumDeclaration();


	if (context->root != nullptr) {
		context->root = p;
	}

	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;
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



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "EnumDeclaration";
	childContext->token = env.list[0];
	childContext->parent = context->root;
}


void fillWithClassTypeNormalInterfaceDeclaration(P_Context &context, Env &env, P_Context &childContext) {
	NormalInterfaceDeclaration *p = new NormalInterfaceDeclaration();


	if (context->root != nullptr) {
		context->root = p;
	}

	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;
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



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "NormalInterfaceDeclaration";
	childContext->token = env.list[0];
	childContext->parent = context->root;
}


void fillWithClassTypeAnnotationTypeDeclaration(P_Context &context, Env &env, P_Context &childContext) {
	AnnotationTypeDeclaration *p = new AnnotationTypeDeclaration();


	if (context->root != nullptr) {
		context->root = p;
	}

	p->name = ((ClassListToken *)(env.list[0].get()))->list[0]->name;
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



	childContext = P_Context(new Context());
	childContext->compile_file = context->compile_file;
	childContext->type = "AnnotationTypeDeclaration";
	childContext->token = env.list[0];
	childContext->parent = context->root;
}



	void processCompilationUnit(RecursiveDescentJava &recursiveDescentJava4,
		RecursiveDescentJava &recursiveDescentJava5, 
		RecursiveDescentJava &recursiveDescentJava6, 
		RecursiveDescentJava &recursiveDescentJava7, 
		RecursiveDescentJava &recursiveDescentJava8, 
		RecursiveDescentJava &recursiveDescentJava9,
		PrimarySymbolConverter primarySymbolConverter,
		P_Context &context, deque<P_Context> &contextDeque,
		set<string> &end_symbol_set0){
		Env env;
		recursiveDescentJava4.init_total_lex_word_list(context->compile_file, primarySymbolConverter, end_symbol_set0);
		Node*  node_tree4 = recursiveDescentJava4.slr(env, "ele_begin", 0);

		string className;
		int wordListIdOfclass;

		if (node_tree4 == nullptr) {
			cout << context->compile_file << ":" << "analyze failed" << endl;
		}
		else {

			unordered_map<string, string> imfo_map;
			recursiveDescentJava4.gen_middle_code(env, node_tree4, imfo_map);
			Node::releaseNode(node_tree4);

			string classType = ((ClassListToken *)(env.list[0].get()))->list[0]->type;

			P_Context childContext = nullptr;

			if (classType == "NormalClassDeclaration") {
				fillWithClassTypeNormalClassDeclaration(context, env, childContext);
			}
			else if (classType == "EnumDeclaration") {
				fillWithClassTypeEnumDeclaration(context, env, childContext);
			}
			else if (classType == "NormalInterfaceDeclaration") {
				fillWithClassTypeNormalInterfaceDeclaration(context, env, childContext);
			}
			else if (classType == "AnnotationTypeDeclaration") {
				fillWithClassTypeAnnotationTypeDeclaration(context, env, childContext);
			}


			contextDeque.push_front(childContext);

		}
}



void main(int argc, char* argv[]) {

	string path = "C:\\Users\\Administrator\\Desktop\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\";
	string fileName = "JavaSyntaxTest.java";

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
		processContext(presentContext, contextDeque);
		contextDeque.pop_back();
	}
	cout << "asdas" << endl;
}
