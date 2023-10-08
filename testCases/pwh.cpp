#include "pwh.h"
#include"../Lalr.h"
#include "../Util/Util.h"
#include "../dao/TCompileFileDao.h"
#include "../dao/ErpClassDao.h"
#include "../dao/ErpMethodDao.h"
#include "../dao/ErpImportDao.h"
#include "../symbols/PrimarySymbolConverter.h"
#include "../RecursiveDescentJava.h"
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
	string rule_file0 = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R003.txt";
	string fileName = "HadoopTest.java";
	string compile_file = path + "\\" + fileName;

	set<string> end_symbol_set0;

	RecursiveDescentJava recursiveDescentJava;
	PrimarySymbolConverter primarySymbolConverter;
	recursiveDescentJava.init(rule_file0);
	recursiveDescentJava.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

	Node*  node_tree = recursiveDescentJava.slr(env,"CompilationUnit");


	return 0;
}



