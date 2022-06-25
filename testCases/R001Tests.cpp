#include "R001Tests.h"
#include"../Lalr.h"
#include "../symbols/java/Array.h"
#include "../symbols/java/Class.h"

using namespace std;
R001Tests::R001Tests() {}
R001Tests::~R001Tests() {}
int R001Tests::test1(string i_rule_file,string i_testCaseFolder,string i_test_file,Env &env) {

	
	CompileInfo compileInfo;

	string rule_file0 = i_rule_file;
	Lalr lalr;
	if (-1 == lalr.init(rule_file0)) {
		return -1;
	}
	lalr.switchParseProcess = false;
	lalr.switchNotSilent = true;
	PrimarySymbolConverter primarySymbolConverter;
	set<string> end_symbol_set0;
	string path = i_testCaseFolder;
	string fileName = i_test_file;
	string compile_file = path + "\\" + fileName;

	lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

	Node*  node_tree = lalr.slr(env, compileInfo);
	if (node_tree == nullptr) {
		cout << fileName << ":" << "·ÖÎöÊ§°Ü" << endl;
	}
	else {
		cout << fileName << ":" << "·ÖÎö³É¹¦" << endl;
		//lalr.printStackTree(node_tree, "");
		unordered_map<string, string> imfo_map;
		lalr.gen_middle_code(env, node_tree, imfo_map);


		//lalr.printStackTree(node_tree, "");
		Node::releaseNode(node_tree);
	}
	return 0;
}


int main() {
	//R001Tests r001Tests;
	//Env env;
	//string i_rule_file = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R001.txt";
	//string i_testCaseFolder = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\testCases";
	//string i_test_file = "SingleClass.java";
	//r001Tests.test1( i_rule_file,  i_testCaseFolder,  i_test_file, env);
	//Array* p = (Array*)(env.list.get());
	//Class* p2 = (Class*)(p->list[0].get());
	//cout << "classType=" << p2->classType << endl;
	//cout << "className=" << p2->className << endl;
	//Array* p3 = (Array*)p2->list.get();
	//Class* p4 = (Class*)(p3->list[0].get());
	//cout << "classType=" << p4->classType << endl;
	//cout << "subClassName=" << p4->className << endl;


	//R001Tests r001Tests;
	//Env env;
	//string i_rule_file = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R001.txt";
	//string i_testCaseFolder = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\testCases";
	//string i_test_file = "SingleEnum.java";
	//r001Tests.test1( i_rule_file,  i_testCaseFolder,  i_test_file, env);
	//Array* p = (Array*)(env.list.get());
	//Class* p2 = (Class*)(p->list[0].get());
	//cout << "classType=" << p2->classType << endl;
	//cout << "className=" << p2->className << endl;
	//Array* p3 = (Array*)p2->list.get();
	//Class* p4 = (Class*)(p3->list[0].get());
	//cout << "subClassType=" << p4->classType << endl;
	//cout << "subClassName=" << p4->className << endl;

	//R001Tests r001Tests;
	//Env env;
	//string i_rule_file = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R001.txt";
	//string i_testCaseFolder = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\testCases";
	//string i_test_file = "SingleInterface.java";
	//r001Tests.test1( i_rule_file,  i_testCaseFolder,  i_test_file, env);
	//Array* p = (Array*)(env.list.get());
	//Class* p2 = (Class*)(p->list[0].get());
	//cout << "classType=" << p2->classType << endl;
	//cout << "className=" << p2->className << endl;
	//Array* p3 = (Array*)p2->list.get();
	//Class* p4 = (Class*)(p3->list[0].get());
	//cout << "subClassType=" << p4->classType << endl;
	//cout << "subClassName=" << p4->className << endl;

	R001Tests r001Tests;
	Env env;
	string i_rule_file = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\java·¶±¾\\R001.txt";
	string i_testCaseFolder = "C:\\Users\\Administrator\\Desktop\\´úÂëÎäÆ÷¿â-×Ü\\Íò»¨Í²Ð´ÂÖÑÛ\\kaleidoscope-writing-wheel-eye\\resources\\testCases";
	string i_test_file = "SingleAnnotation.java";
	r001Tests.test1( i_rule_file,  i_testCaseFolder,  i_test_file, env);
	Array* p = (Array*)(env.list.get());
	Class* p2 = (Class*)(p->list[0].get());
	cout << "classType=" << p2->classType << endl;
	cout << "className=" << p2->className << endl;
	Array* p3 = (Array*)p2->list.get();
	Class* p4 = (Class*)(p3->list[0].get());
	cout << "subClassType=" << p4->classType << endl;
	cout << "subClassName=" << p4->className << endl;




}