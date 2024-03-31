#pragma once
#include "pwh.h"
#include"../Lalr.h"
#include "../Util/Util.h"
#include "../dao/TCompileFileDao.h"
#include "../dao/ErpClassDao.h"
#include "../dao/ErpMethodDao.h"
#include "../dao/ErpImportDao.h"
#include "../symbols/PrimarySymbolConverter.h"
#include "../RecursiveDescentJava.h"
#include "../symbols/java/ClassListToken.h"
#include "../symbols/java/StatementToken.h"
#include "../symbols/java/StatementListToken.h"
#include <iostream>
#include <fstream>

using namespace std;
pwh::pwh() {}
pwh::~pwh() {}




void analyzeNormalClassDeclaration(StatementListToken *p, PrimarySymbolConverter &primarySymbolConverter,
	unordered_map<string, string> &imfo_map,
	string &compile_file,
	RecursiveDescentJava &recursiveDescentJava5,
	RecursiveDescentJava &recursiveDescentJava6) {

	for (int i1 = 1; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				recursiveDescentJava5.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
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

					cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
					cout << "statementType:" << statementType << endl;

					if (statementType == "FieldDeclaration") {
						for (auto &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}


					if (statementType == "MethodDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->resultType << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;

						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;

						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);


						for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}

					if (statementType == "ConstructorDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;


						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;
						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);

						if (((StatementToken *)(env3.list[0].get()))->statementEntity->type != "Empty") {
							for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
								cout << e->name << endl;
								cout << e->unannType << endl;
							}
						}


						Node::releaseNode(node_tree6);
					}


					if (statementType == "NormalClassDeclaration" || statementType == "EnumDeclaration" || statementType == "NormalInterfaceDeclaration" || statementType == "AnnotationTypeDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						cout << "name:" << name << endl;
					}
				}
			}

			if (statementType == "") {
				cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
			}
		}
	}
}



void analyzeEnumDeclaration(StatementListToken *p, PrimarySymbolConverter &primarySymbolConverter,
	unordered_map<string, string> &imfo_map,
	string &compile_file, 
	RecursiveDescentJava &recursiveDescentJava5,
	RecursiveDescentJava &recursiveDescentJava6,
	RecursiveDescentJava &recursiveDescentJava7 ){
	Env env3;
	recursiveDescentJava7.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[0]->begIndex, p->list[0]->endIndex);
	Node*  node_tree7 = recursiveDescentJava7.slr(env3, "ele_begin", 0);

	recursiveDescentJava7.gen_middle_code(env3, node_tree7, imfo_map);
	for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
		cout << e->name << endl;
	}
	Node::releaseNode(node_tree7);


	for (int i1 = 1; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {

			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				recursiveDescentJava5.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
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

					cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
					cout << "statementType:" << statementType << endl;

					if (statementType == "FieldDeclaration") {
						for (auto &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}

					if (statementType == "MethodDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->resultType << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;

						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;

						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);


						for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}

					if (statementType == "ConstructorDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;


						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;
						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);

						if (((StatementToken *)(env3.list[0].get()))->statementEntity->type != "Empty") {
							for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
								cout << e->name << endl;
								cout << e->unannType << endl;
							}
						}


						Node::releaseNode(node_tree6);
					}


					if (statementType == "NormalClassDeclaration" || statementType == "EnumDeclaration" || statementType == "NormalInterfaceDeclaration" || statementType == "AnnotationTypeDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						cout << "name:" << name << endl;
					}
				}
			}

			if (statementType == "") {
				cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
			}
		}
	}
}



void analyzeNormalInterfaceDeclaration(StatementListToken *p, PrimarySymbolConverter &primarySymbolConverter,
	unordered_map<string, string> &imfo_map,
	string &compile_file,
	RecursiveDescentJava &recursiveDescentJava8,
	RecursiveDescentJava &recursiveDescentJava6) {
	
	Env env3;

	for (int i1 = 0; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {
			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				retryNum--;
				Env env2;
				recursiveDescentJava8.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree8 = recursiveDescentJava8.slr(env2, "ele_begin", 0);
				if (node_tree8 != nullptr) {

					recursiveDescentJava8.gen_middle_code(env2, node_tree8, imfo_map);
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

					cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
					cout << "statementType:" << statementType << endl;

					if (statementType == "ConstantDeclaration") {
						for (auto &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}

					if (statementType == "InterfaceMethodDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->resultType << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;

						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;

						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);


						for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}




					if (statementType == "NormalClassDeclaration" || statementType == "EnumDeclaration" || statementType == "NormalInterfaceDeclaration" || statementType == "AnnotationTypeDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						cout << "name:" << name << endl;
					}
				}
			}

			if (statementType == "") {
				cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
			}

		}
	
	}


}


void analyzeAnnotationTypeDeclaration(StatementListToken *p, PrimarySymbolConverter &primarySymbolConverter,
	unordered_map<string, string> &imfo_map,
	string &compile_file,
	RecursiveDescentJava &recursiveDescentJava9,
	RecursiveDescentJava &recursiveDescentJava6) {

	Env env3;


	for (int i1 = 0; i1 < p->list.size(); i1++) {

		if (p->list[i1]->endWith != "useless") {
			bool isProcessed = false;
			int retryNum = 3;
			string statementType = "";

			while (!isProcessed && retryNum > 0) {
				
				retryNum--;
				Env env2;
				recursiveDescentJava9.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
				Node*  node_tree9 = recursiveDescentJava9.slr(env2, "ele_begin", 0);

				if (node_tree9 != nullptr) {
					recursiveDescentJava9.gen_middle_code(env2, node_tree9, imfo_map);
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

					cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
					cout << "statementType:" << statementType << endl;

					if (statementType == "ConstantDeclaration") {
						for (auto &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}

					if (statementType == "AnnotationTypeElementDeclaration") {
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->resultType << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->name << endl;

						((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex += p->list[i1]->begIndex;
						((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex += p->list[i1]->begIndex;

						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex << endl;
						cout << ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex << endl;

						int paramBeg = ((StatementToken *)(env2.list[0].get()))->statementEntity->begIndex;
						int paramEnd = ((StatementToken *)(env2.list[0].get()))->statementEntity->endIndex;
						Env env3;
						recursiveDescentJava6.init_total_lex_word_list(compile_file, primarySymbolConverter, paramBeg, paramEnd);
						Node*  node_tree6 = recursiveDescentJava6.slr(env3, "ele_begin", 0);

						recursiveDescentJava6.gen_middle_code(env3, node_tree6, imfo_map);


						for (auto &e : ((StatementToken *)(env3.list[0].get()))->statementEntity->fieldList) {
							cout << e->name << endl;
							cout << e->unannType << endl;
						}

					}




					if (statementType == "NormalClassDeclaration" || statementType == "EnumDeclaration" || statementType == "NormalInterfaceDeclaration" || statementType == "AnnotationTypeDeclaration") {
						string &name = ((StatementToken *)(env2.list[0].get()))->statementEntity->name;
						cout << "name:" << name << endl;
					}
				}
			}

			if (statementType == "") {
				cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
			}

		}

	}


}




int main1(int argc, char* argv[]) {

	//0 -µÝ¹éÏÂ½µ·¨ µ¥¸öÎÄ¼þ²âÊÔ
	//1 -µÝ¹éÏÂ½µ·¨ ÅúÁ¿²âÊÔ²âÊÔ
	//2 -LalrÎÄ·¨ÊÊÅäÐÔ¼ì²â
	//3 -Lalr µ¥¸öÎÄ¼þ²âÊÔ
	//4 ÅúÁ¿²âÊÔ
	Util::cleanLog();

	int mode =  2;


	
	if (mode == 0) {
		Env env;
		string path = "C:\\Users\\Administrator\\Desktop\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\";
		string fileName = "JavaAnnotation.java";
		string rule_file4 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R004.txt";
		string rule_file5 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R005.txt";
		string rule_file6 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R006.txt";
		string rule_file7 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R007.txt";
		string rule_file8 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R008.txt";
		string rule_file9 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R009.txt";

		string compile_file = path + "\\" + fileName;

		set<string> end_symbol_set0;

		RecursiveDescentJava recursiveDescentJava4;
		PrimarySymbolConverter primarySymbolConverter;
		recursiveDescentJava4.init(rule_file4);
		recursiveDescentJava4.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);


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

		Node*  node_tree4 = recursiveDescentJava4.slr(env, "ele_begin",0);

		string className;
		int wordListIdOfclass;

		if (node_tree4 == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {
			
			unordered_map<string, string> imfo_map;
			recursiveDescentJava4.gen_middle_code(env, node_tree4, imfo_map);
			Node::releaseNode(node_tree4);

			cout <<"packageName:"<< ((ClassListToken *)(env.list[0].get()))->packageName << endl;
			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();

			if (importListToken!=nullptr) {
				for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
					cout << "import[" << i1 << "]:" << importListToken->list[i1]->name << endl;
					cout << importListToken->list[i1]->isStatic << endl;
				}
			}


			cout <<"className:"<< ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
			string classType=((ClassListToken *)(env.list[0].get()))->list[0]->type;
			cout << classType << endl;


			StatementListToken* p = (StatementListToken*)((ClassListToken *)(env.list[0].get()))->list[0]->statementList.get();

			if ("NormalClassDeclaration"== classType) {
				analyzeNormalClassDeclaration(p, primarySymbolConverter,imfo_map,compile_file,
					recursiveDescentJava5,recursiveDescentJava6);
			}
			else if ("EnumDeclaration" == classType) {
				analyzeEnumDeclaration(p, primarySymbolConverter, imfo_map, compile_file,
					recursiveDescentJava5,recursiveDescentJava6,recursiveDescentJava7);
			}
			else if ("NormalInterfaceDeclaration" == classType) {
				analyzeNormalInterfaceDeclaration(p, primarySymbolConverter, imfo_map, compile_file,
					recursiveDescentJava8, recursiveDescentJava6);
			}
			else if ("AnnotationTypeDeclaration" == classType) {
				analyzeAnnotationTypeDeclaration(p, primarySymbolConverter, imfo_map, compile_file,
					recursiveDescentJava9, recursiveDescentJava6);
			}

		}

	}
	else if (mode == 1) {

		Env env;
		//string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R004.txt";
		string fileName = argv[2];
		string compile_file = argv[1];
		//string fileName = "jakarta\\annotation\\Generated.java";
		//string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Generated.java";

		set<string> end_symbol_set0;

		RecursiveDescentJava recursiveDescentJava;
		PrimarySymbolConverter primarySymbolConverter;
		recursiveDescentJava.init(rule_file0);
		recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = recursiveDescentJava.slr(env, "ele_begin",0);


		if (node_tree == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {
			cout << fileName << ":" << "analyze successfully" << endl;
			unordered_map<string, string> imfo_map;
			recursiveDescentJava.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);
			//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;


			cout << "PACKAGE_NAME:" << ((ClassListToken *)(env.list[0].get()))->packageName << endl;

			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
			for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
				cout << "IMPORT_NAME:" << importListToken->list[i1]->name << endl;
			}



			if (((ClassListToken *)(env.list[0].get()))->list.size() > 0) {
				cout << "CLASS_NAME:" << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
			}

		}

		return 0;
	}
	else if (mode == 2) {
		Lalr lalr;
//		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R004.txt";
		string rule_file0 = argv[1];
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
		else {
			cout << "done" << endl;
		}
	}
	else if (mode == 3) {

		Env env;
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R005.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = true;
		lalr.switchAllowIllegalInput = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\";
		string fileName = "JavaSyntaxTest.java";
		string compile_file = path + "\\" + fileName;

		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env);

		string className;
		int wordListIdOfclass;

		if (node_tree == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {

			unordered_map<string, string> imfo_map;
			lalr.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);

			cout << "packageName:" << ((ClassListToken *)(env.list[0].get()))->packageName << endl;
			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();

			for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
				cout << "import[" << i1 << "]:" << importListToken->list[i1]->name << endl;
				cout << importListToken->list[i1]->isStatic << endl;
			}




			cout << "className:" << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
			string classType = ((ClassListToken *)(env.list[0].get()))->list[0]->type;
			cout << classType << endl;
			if ("NormalClassDeclaration" == classType) {
				StatementListToken* p = (StatementListToken*)((ClassListToken *)(env.list[0].get()))->list[0]->statementList.get();
				//NormalClassDeclaration

				for (int i1 = 0; i1 < p->list.size(); i1++) {
					cout << "statement[" << i1 << "]:" << p->list[i1]->begIndex << "," << p->list[i1]->endIndex << endl;
				}
			}

		}
	}
	else if (mode == 4) {

		string method = argv[1];
		string srceListFile = argv[2];

		//string method = "Lalr";
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\pwh_local_0.txt";

		//string method = "RecursiveDescent";
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\pwh_local_0.txt";

		if (method == "RecursiveDescent") {
			string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R009.txt";

			string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
			RecursiveDescentJava recursiveDescentJava;
			PrimarySymbolConverter primarySymbolConverter;
			recursiveDescentJava.init(rule_file0);

			set<string> end_symbol_set0;

			ifstream input_file;
			input_file.open(srceListFile.data());
			string fileStr;
			while (getline(input_file, fileStr)) {
				Env env;
				if (recursiveDescentJava.startsWith(fileStr, "#") == 0) {
					string compile_file = path + "\\" + fileStr;
					recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

					Node*  node_tree = recursiveDescentJava.slr(env, "ele_begin",0);

					if (node_tree == nullptr) {
						cout << fileStr << ":" << "analyze failed" << endl;
					}
					else {
						cout << fileStr << ":" << "analyze successfully" << endl;
						unordered_map<string, string> imfo_map;
						recursiveDescentJava.gen_middle_code(env, node_tree, imfo_map);
						Node::releaseNode(node_tree);
						//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;


						cout << "PACKAGE_NAME:" << ((ClassListToken *)(env.list[0].get()))->packageName << endl;

						ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
						for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
							cout << "IMPORT_NAME:" << importListToken->list[i1]->name << endl;
						}



						if (((ClassListToken *)(env.list[0].get()))->list.size() > 0) {
							cout << "CLASS_NAME:" << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
						}
					}

				}
			}



		}
		else if (method=="Lalr") {
		
			
			
			string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R004.txt";
			Lalr lalr;
			if (-1 == lalr.init(rule_file0)) {
				return -1;
			}

			lalr.switchParseProcess = false;
			lalr.switchNotSilent = true;
			lalr.switchAllowIllegalInput = true;
			PrimarySymbolConverter primarySymbolConverter;
			set<string> end_symbol_set0;

			string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
			//string fileName = "HadoopTest.java";
			//string compile_file = path + "\\" + fileName;

			ifstream input_file;
			input_file.open(srceListFile.data());
			string fileStr;
			while (getline(input_file, fileStr)) {
				Env env;
				if (lalr.startsWith(fileStr,"#")==0) {
					string compile_file = path + "\\" + fileStr;
					lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

					Node*  node_tree = lalr.slr(env);

					if (node_tree == nullptr) {
						cout << fileStr << ":" << "analyze failed" << endl;
					}
					else {
						cout << fileStr << ":" << "analyze successfully" << endl;
						unordered_map<string, string> imfo_map;
						lalr.gen_middle_code(env, node_tree, imfo_map);
						Node::releaseNode(node_tree);
						//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;


						cout << "PACKAGE_NAME:" << ((ClassListToken *)(env.list[0].get()))->packageName << endl;

						ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
						for (int i1 = 0; i1 < importListToken->list.size(); i1++) {
							cout << "IMPORT_NAME:" << importListToken->list[i1]->name << endl;
						}

						if (((ClassListToken *)(env.list[0].get()))->list.size() > 0) {
							cout << "CLASS_NAME:" << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
						}
					}


				}	
			}

		}


	}
	
}

