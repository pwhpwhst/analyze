#include "R001Tests.h"
#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>
#include<boost/algorithm/string.hpp>
#include"../Lalr.h"
#include "../symbols/java/Array.h"
#include "../symbols/java/Class.h"

using namespace std;
R001Tests::R001Tests() {}
R001Tests::~R001Tests() {}
int R001Tests::test1() {

	Env env;
	CompileInfo compileInfo;

	string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
	Lalr lalr;
	if (-1 == lalr.init(rule_file0)) {
		return -1;
	}
	lalr.switchParseProcess = false;
	lalr.switchNotSilent = true;
	PrimarySymbolConverter primarySymbolConverter;
	set<string> end_symbol_set0;
	string path = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\testCases";
	string fileName = "Sample.java";
	string compile_file = path + "\\" + fileName;

	lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

	Node*  node_tree = lalr.slr(env, compileInfo);
	if (node_tree == nullptr) {
		cout << fileName << ":" << "分析失败" << endl;
	}
	else {
		cout << fileName << ":" << "分析成功" << endl;
		//lalr.printStackTree(node_tree, "");
		unordered_map<string, string> imfo_map;
		lalr.gen_middle_code(env, node_tree, imfo_map);

		Array* p = (Array*)(env.list.get());
		Class* p2 = (Class*)(p->list[0].get());
		cout << "className=" << p2->className << endl;
		//lalr.printStackTree(node_tree, "");
		Node::releaseNode(node_tree);
	}
}


void main() {
	R001Tests r001Tests;
	r001Tests.test1();
}