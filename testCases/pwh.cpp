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
int pwh::test1(string i_rule_file,string i_testCaseFolder,string i_test_file,Env &env) {
	return 0;
}


int main(int argc, char* argv[]) {

	//0 -递归下降法 单个文件测试
	//1 -递归下降法 批量测试测试
	//2 -Lalr文法适配性检测
	//3 -Lalr 单个文件测试
	//4 批量测试

	int mode =  0;

	if (mode == 0) {
		Env env;
		string path = "C:\\Users\\Administrator\\Desktop\\LinuxScriptAssist\\demo\\src\\main\\java\\com\\example\\demo\\test\\";
		string fileName = "JavaSyntaxTest.java";
		string rule_file4 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";

		string rule_file5 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R005.txt";


		string compile_file = path + "\\" + fileName;

		set<string> end_symbol_set0;

		RecursiveDescentJava recursiveDescentJava4;
		PrimarySymbolConverter primarySymbolConverter;
		recursiveDescentJava4.init(rule_file4);
		recursiveDescentJava4.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);


		RecursiveDescentJava recursiveDescentJava5;
		recursiveDescentJava5.logSwitch = false;
		recursiveDescentJava5.init(rule_file5);

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

			if ("NormalClassDeclaration"== classType|| "EnumDeclaration" == classType 
				|| "NormalInterfaceDeclaration" == classType || "AnnotationTypeDeclaration" == classType) {
				StatementListToken* p = (StatementListToken*)((ClassListToken *)(env.list[0].get()))->list[0]->statementList.get();
				//NormalClassDeclaration
				
				for (int i1 = 0; i1 < p->list.size(); i1++) {

					if (p->list[i1]->endWith!="useless") {
						
						

						bool isProcessed = false;
						int retryNum = 3;
						string statementType = "";
						
						while (!isProcessed && retryNum>0) {
							retryNum--;
							Env env2;
							recursiveDescentJava5.init_total_lex_word_list(compile_file, primarySymbolConverter, p->list[i1]->begIndex, p->list[i1]->endIndex);
							Node*  node_tree5 = recursiveDescentJava5.slr(env2, "ele_begin", 0);

							if (node_tree5 != nullptr) {

								recursiveDescentJava5.gen_middle_code(env2, node_tree5, imfo_map);
								 statementType = ((StatementToken *)(env2.list[0].get()))->statementEntity->type;
								


								if (statementType == "FieldDeclarationFake") {
									for (int i2 = i1; i2 < p->list.size(); i2++) {
										if(p->list[i2]->endWith!="semicolon") {
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
										for (const string &e : ((StatementToken *)(env2.list[0].get()))->statementEntity->nameList) {
											cout << e << endl;
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

		}

	}
	else if (mode == 1) {

		Env env;
		//string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";
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
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
	}
	else if (mode == 3) {

		Env env;
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R005.txt";
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
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh_local_0.txt";

		//string method = "RecursiveDescent";
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh_local_0.txt";

		if (method == "RecursiveDescent") {
			string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";

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
		
			
			
			string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";
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

