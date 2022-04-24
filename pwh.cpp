#include"symbols\Env.h"
#include"symbols\CompileInfo.h"
#include"Lalr.h"
#include"Lr1.h"
#include"symbols\Type.h"
#include"symbols\Tag.h"
#include"SLR\Lex_Word.h"
#include"symbols\PrimarySymbolConverter.h"
#include"treeAnalyzer\java\JAVATreeAnalyzer.h"
#include"treeAnalyzer\java\JAVASpaceTreeAnalyzer.h"
#include <vector>
#include <deque>
#include "Config.h"
#include "dao/BaseDao.h"
#include "dao/TCompileFileDao.h"
#include<io.h>
#include<boost/algorithm/string.hpp>
#include "MD5.h"
#include "dao/TFileMD5Dao.h"
#include "dao/TConvertMapDao.h"


void findSpecificNode(Node *node_tree,string ruleName,vector<Node*> &nodeList) {
	deque<Node*> queue;
	queue.push_front(node_tree);

	Node* target_node = nullptr;
	while (queue.size() > 0) {
		Node* present_node = queue.back();

		if (present_node->symbol == ruleName) {
			nodeList.push_back(present_node);
		}

		if (present_node->child_node_list.size() > 0) {
			for (auto &e : present_node->child_node_list) {
				queue.push_front(e);
			}
		}
		queue.pop_back();
	}
}












int main() {
//	MD5算法来自于
// https://blog.csdn.net/think_A_lot/article/details/86749730

	//string rule_file4 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPackages.txt";

	//bool isChanged=isRuleFileChanged(rule_file4);

	//cout << "isChanged=" << isChanged << endl;

	//0 - 测试 -Package
	//1 - 测试 -expression
	//3 - 查看非终端符号实际囊括的终端符号
	//4 - 真实批量
	//5 - 真实单体

	Env env;
	CompileInfo compileInfo;

	int mode = 0;
	cout << "分析器初始化！" << endl;
	if (mode == 0) {

		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPackages.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
		lalr.switchParseProcess = true;
		lalr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本";
		string fileName = "Sample.java";
		string compile_file = path + "\\" + fileName;

		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << fileName << ":" << "分析失败" << endl;
		}
		else {
			cout << fileName << ":" << "分析成功" << endl;
			Node::releaseNode(node_tree);
		}


		//set<int> itemSet = { 101 };
		//lalr.printGraph(itemSet);

	}
	else if (mode == 1) {
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForExpression.txt";
		//string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForExpressionConflict.txt";
		//string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPrimary.txt";
		string fileName = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\Sample.java";

		Lr1 lr1;
		if (-1 == lr1.init(rule_file0)) {
			return -1;
		}


		lr1.switchParseProcess = true;
		lr1.switchNotSilent = true;

		PrimarySymbolConverter primarySymbolConverter;
		primarySymbolConverter.identifierMap("String", "'TypeNameId'");
		set<string> end_symbol_set0;
		lr1.init_total_lex_word_list(fileName, primarySymbolConverter);

		Node*  node_tree = lr1.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << "Sample.java" << ":" << "分析失败" << endl;
		}
		else {
			lr1.printStackTree(node_tree, "");
		}

	}
	else if (mode == 3) {

		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPrimary.txt";




		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.calculate_f_terminate("Expression", rule_file0);
	}
	else if (mode == 4) {

		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPackages.txt";

		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = false;

		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		

		P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
		unordered_map<string, string> transfer_map;

		vector<unordered_map<string, string>> result_list;


		tCompileFileDao->queryList(transfer_map, result_list);

		vector<Node*> nodeList;

		for (int i1 = 0; i1 < result_list.size();i1++) {

			 auto &e=result_list[i1];
			string compile_file = e["path"] + "\\" + e["file_name"];
			
			lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

			Node*  node_tree = lalr.slr(env, compileInfo);
			if (node_tree == nullptr) {
				cout << e["file_name"] << ":" << "分析失败" << endl;
			}
			else {
				//cout << e["file_name"] << ":" << "分析成功" << endl;
				nodeList.clear();
				findSpecificNode(node_tree, "NormalClassDeclaration", nodeList);
				cout << e["file_name"] << ":" << nodeList.size() << endl;
				Node::releaseNode(node_tree);
			}

		}
		cout << "分析完成" << endl;
	}else if (mode == 5) {
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPackages.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
		lalr.switchParseProcess = true;
		lalr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\jakarta\\el";
		string fileName = "ArrayELResolver.java";
		string compile_file = path + "\\" + fileName;

		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << fileName << ":" << "分析失败" << endl;
		}
		else {
			cout << fileName << ":" << "分析成功" << endl;
			Node::releaseNode(node_tree);
		}
		//set<int> itemSet = { 196 };
		//lalr.printGraph(itemSet);
	}



}



