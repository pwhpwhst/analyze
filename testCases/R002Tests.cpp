
//	https://docs.oracle.com/javase/specs/jls/se8/html/jls-19.html

//(Lexical Structure)
//
//(Types, Values, and Variables)
//
//(Names)
//
//(Packages)
//
//(Classes)
//
//(Interfaces)
//
//(Arrays)
//
//(Blocks and Statements)
//
//(Expressions)



#include "R002Tests.h"
#include"../Lalr.h"
#include "../symbols/java/Import.h"
#include "../symbols/java/Array.h"
#include "../symbols/java/Class.h"
#include "../symbols/java/Method.h"
#include "../symbols/java/CompileUnit.h"
#include "../Util/Util.h"
#include "../dao/TCompileFileDao.h"
#include "../dao/ErpClassDao.h"
#include "../dao/ErpMethodDao.h"
#include "../dao/ErpImportDao.h"
#include <iostream>


using namespace std;
R002Tests::R002Tests() {}
R002Tests::~R002Tests() {}





void sitTest2() {
	string projectName = "AaronDemo";

	string i_rule_file = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001Default.txt";

	P_ErpMethodDao tErpMethodDao = ErpMethodDao::getInstance();


	unordered_map<string, string> transfer_map;


	transfer_map.clear();
	transfer_map["project"] = projectName;
	vector<unordered_map<string, string>> result_list;
	tErpMethodDao->queryListWithPath(transfer_map, result_list);


	//初始化状态机 begin
	CompileInfo compileInfo;
	string rule_file0 = i_rule_file;
	Lalr lalr;
	if (-1 == lalr.init(rule_file0)) {
		return;
	}
	lalr.switchParseProcess = false;
	lalr.switchNotSilent = true;

	for (int i1 = 0; i1 < result_list.size(); i1++) {

		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string compile_file = result_list[i1]["path"] + "\\" + result_list[i1]["fileName"];
		cout << compile_file << endl;

		int bodyBeg = atoi(result_list[i1]["bodyBeg"].c_str());
		int bodyEnd = atoi(result_list[i1]["bodyEnd"].c_str());


		//载入词法流
		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, bodyBeg, bodyEnd);

		Env env;
		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << result_list[i1]["className"]<<","<< result_list[i1]["methodName"] << ":" << "分析失败" << endl;
		}
		else {
			cout << result_list[i1]["className"] << "," << result_list[i1]["methodName"] << ":" << "分析成功" << endl;
		}
	}

}




void devTest() {
	string projectName = "AaronDemo";

	string i_rule_file = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R002.txt";

	P_ErpMethodDao tErpMethodDao = ErpMethodDao::getInstance();


	unordered_map<string, string> transfer_map;





	//初始化状态机 begin
	CompileInfo compileInfo;
	string rule_file0 = i_rule_file;
	Lalr lalr;
	if (-1 == lalr.init(rule_file0)) {
		return;
	}
	lalr.switchParseProcess = false;
	lalr.switchNotSilent = true;



	PrimarySymbolConverter primarySymbolConverter;
	set<string> end_symbol_set0;
	string compile_file = "C://Users//Administrator//Desktop//Maven//src//main//java//com//pwhTest//hadoopService//AaronDemoTest3.java";
		

	//载入词法流
	lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

	Env env;
	Node*  node_tree = lalr.slr(env, compileInfo);
	if (node_tree == nullptr) {
		cout << "AaronDemoTest3.java" << ":" << "分析失败" << endl;
	}
	else {
		cout << "AaronDemoTest3.java" << ":" << "分析成功" << endl;
	}


}

int main() {
	devTest();
	//sitTest();

}