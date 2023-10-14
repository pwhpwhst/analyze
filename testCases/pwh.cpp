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
#include "../symbols/java/ClassToken.h"
#include <iostream>


using namespace std;
pwh::pwh() {}
pwh::~pwh() {}
int pwh::test1(string i_rule_file,string i_testCaseFolder,string i_test_file,Env &env) {
	return 0;
}


int main() {

	Env env;
	string path = "C:\\Users\\Administrator\\Desktop\\Maven3\\src\\main\\java\\com\\pwhTest\\hadoopTest";
	string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R003.txt";
	string fileName = "HadoopTest.java";
	string compile_file = path + "\\" + fileName;

	set<string> end_symbol_set0;

	RecursiveDescentJava recursiveDescentJava;
	PrimarySymbolConverter primarySymbolConverter;
	recursiveDescentJava.init(rule_file0);
	recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

	Node*  node_tree = recursiveDescentJava.slr(env,"ele_begin");


	if (node_tree == nullptr) {
		cout << fileName << ":" << "分析失败" << endl;
	}
	else {
		cout << fileName << ":" << "分析成功" << endl;
		unordered_map<string, string> imfo_map;
		recursiveDescentJava.gen_middle_code(env, node_tree, imfo_map);
		Node::releaseNode(node_tree);
		cout << ((ClassToken *)(env.list[0].get()))->list[0]->name << endl;
	}



	return 0;
}



