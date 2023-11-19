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
#include <iostream>


using namespace std;
pwh::pwh() {}
pwh::~pwh() {}
int pwh::test1(string i_rule_file,string i_testCaseFolder,string i_test_file,Env &env) {
	return 0;
}


int main(int argc, char* argv[]) {
	int mode = 3;

	if (mode==0) {
		Env env;
		string path = "C:\\Users\\Administrator\\Desktop\\Maven3\\src\\main\\java\\com\\pwhTest\\hadoopTest";
		string fileName = "HadoopTest.java";
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R004.txt";
		string compile_file = path + "\\" + fileName;

		set<string> end_symbol_set0;

		RecursiveDescentJava recursiveDescentJava;
		PrimarySymbolConverter primarySymbolConverter;
		recursiveDescentJava.init(rule_file0);
		recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = recursiveDescentJava.slr(env, "ele_begin");


		if (node_tree == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {
			cout << fileName << ":" << "analyze successfully" << endl;
			unordered_map<string, string> imfo_map;
			recursiveDescentJava.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);
			//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;
			cout << ((ClassListToken *)(env.list[0].get()))->packageName << endl;
			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
			cout << importListToken->list[0]->name << endl;
			cout << importListToken->list[0]->isStatic << endl;
			cout << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
		}
	}
	else if(mode == 1) {




		
		Env env;
		//string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java";
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R004.txt";
		string fileName = argv[2];
		string compile_file = argv[1];
		//string fileName = "jakarta\\annotation\\Generated.java";
		//string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\annotation\\Generated.java";

		set<string> end_symbol_set0;

		RecursiveDescentJava recursiveDescentJava;
		PrimarySymbolConverter primarySymbolConverter;
		recursiveDescentJava.init(rule_file0);
		recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = recursiveDescentJava.slr(env, "ele_begin");


		if (node_tree == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {
			cout << fileName << ":" << "analyze successfully" << endl;
			unordered_map<string, string> imfo_map;
			recursiveDescentJava.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);
			//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;


			cout << "PACKAGE_NAME:"<< ((ClassListToken *)(env.list[0].get()))->packageName << endl;

			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
			for (int i1 = 0; i1 < importListToken->list.size();i1++) {
				cout << "IMPORT_NAME:" << importListToken->list[i1]->name << endl;
			}
			

	
			if (((ClassListToken *)(env.list[0].get()))->list.size()>0) {
				cout <<"CLASS_NAME:"<< ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
			}
			


			
	}





	return 0;
}
	else if(mode == 2) {
		Lalr lalr;
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R004.txt";
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
	}
	else if (mode == 3) {
		RecursiveDescentJava recursiveDescentJava;
		Env env;
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\����������-��\\��Ͳд����\\kaleidoscope-writing-wheel-eye\\resources\\java����\\R004.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = true;
		lalr.switchAllowIllegalInput = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\Maven3\\src\\main\\java\\com\\pwhTest\\hadoopTest";
		string fileName = "HadoopTest.java";
		string compile_file = path + "\\" + fileName;

		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env);


		if (node_tree == nullptr) {
			cout << fileName << ":" << "analyze failed" << endl;
		}
		else {
			cout << fileName << ":" << "analyze successfully" << endl;
			unordered_map<string, string> imfo_map;
			lalr.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);
			//cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;
			cout << ((ClassListToken *)(env.list[0].get()))->packageName << endl;
			ImportListToken* importListToken = (ImportListToken *)((ClassListToken *)(env.list[0].get()))->importList.get();
			cout << importListToken->list[0]->name << endl;
			cout << importListToken->list[0]->isStatic << endl;
			cout << ((ClassListToken *)(env.list[0].get()))->list[0]->name << endl;
		}
	}
}



