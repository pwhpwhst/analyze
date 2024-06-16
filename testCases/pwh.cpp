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

int startsWith(const string& s, const string& sub) {
	if (sub.length() > s.length()) {
		return 0;
	}
	return s.find(sub) == 0 ? 1 : 0;
}






int main1(int argc, char* argv[]) {

	//0 -递归下降法 单个文件测试
	//1 -递归下降法 批量测试测试
	//2 -Lalr文法适配性检测
	//3 -Lalr 单个文件测试
	//4 批量测试
	//5 Lalr 缓存刷新
	Util::cleanLog();

	//int mode =  5;
	int mode = atoi(argv[1]);
	
	
	if (mode == 0) {

		return 0;
	}
	else if (mode == 1) {



		return 0;
	}
	else if (mode == 2) {
		Lalr lalr;
		//string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R004.txt";

		string rule_file0 = argv[2];
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
		else {
			cout << "done" << endl;
		}
	}
	else if (mode == 3) {

	}
	else if (mode == 4) {

		string method = argv[1];
		string srceListFile = argv[2];

		//string method = "Lalr";
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh_local_0.txt";

		//string method = "RecursiveDescent";
		//string srceListFile = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh_local_0.txt";

		if (method == "RecursiveDescent") {
			string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R009.txt";

			string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
			RecursiveDescentJava recursiveDescentJava;
			PrimarySymbolConverter *primarySymbolConverter=new PrimarySymbolConverter();
			recursiveDescentJava.init(rule_file0);


			ifstream input_file;
			input_file.open(srceListFile.data());
			string fileStr;
			while (getline(input_file, fileStr)) {
				Env env;
				if (startsWith(fileStr, "#") == 0) {
					string compile_file = path + "\\" + fileStr;
					recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter);

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
			PrimarySymbolConverter *primarySymbolConverter = new PrimarySymbolConverter();
			set<string> end_symbol_set0;

			string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
			//string fileName = "HadoopTest.java";
			//string compile_file = path + "\\" + fileName;

			ifstream input_file;
			input_file.open(srceListFile.data());
			string fileStr;
			while (getline(input_file, fileStr)) {
				Env env;
				if (startsWith(fileStr,"#")==0) {
					string compile_file = path + "\\" + fileStr;
					lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

					Node*  node_tree = lalr.slr(env,"ele_begin",0);

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
	else if (mode == 5) {
		string rule_file0 = argv[2];
		//string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R005.txt";
		cout << "init parser"<< rule_file0 << endl;
		Parser* parser = new Lalr();
		parser->logSwitch = true;
		parser->init(rule_file0);
		cout << "Refresh Completed" << endl;
	}
	
}

