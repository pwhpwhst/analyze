
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



#include "R001Tests.h"
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
		cout << fileName << ":" << "分析失败" << endl;
	}
	else {
		cout << fileName << ":" << "分析成功" << endl;
		//lalr.printStackTree(node_tree, "");
		unordered_map<string, string> imfo_map;
		lalr.gen_middle_code(env, node_tree, imfo_map);


		//lalr.printStackTree(node_tree, "");
		Node::releaseNode(node_tree);
	}
	return 0;
}




void scanMethod();
void sitTest() {

	//1、找出所有类型
	//2.2、扫描方法
	scanMethod();


}

void scanMethod() {
	string projectName = "AaronDemo";
	string projectBasePath = "C:\\Users\\Administrator\\Desktop\\Maven\\src\\main\\java";

	string i_rule_file = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";

	P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
	P_ErpClassDao tErpClassDao = ErpClassDao::getInstance();
	P_ErpMethodDao tErpMethodDao = ErpMethodDao::getInstance();
	P_ErpImportDao tErpImportDao = ErpImportDao::getInstance();

	unordered_map<string, string> transfer_map;
	transfer_map["project"] = projectName;
	tCompileFileDao->deleteRecord(transfer_map);
	tErpClassDao->deleteRecord(transfer_map);
	tErpMethodDao->deleteRecord(transfer_map);
	tErpImportDao->deleteRecord(transfer_map);


	//获取文件列表
	Util::getFileList(projectBasePath, projectName);
	transfer_map.clear();
	vector<unordered_map<string, string>> result_list;
	transfer_map["project"] = projectName;
	tCompileFileDao->queryList(transfer_map, result_list);

	//初始化状态机 begin
	CompileInfo compileInfo;
	string rule_file0 = i_rule_file;
	Lalr lalr;
	if (-1 == lalr.init(rule_file0)) {
		return;
	}
	lalr.switchParseProcess = false;
	lalr.switchNotSilent = true;
	//初始化状态机 end

	vector<unordered_map<string, string>> importList;
	vector<unordered_map<string, string>> classList;

	vector<unordered_map<string, string>> methodList;

	for (int i1 = 0; i1 < result_list.size(); i1++) {
		cout << result_list[i1]["path"] << endl;
		cout << result_list[i1]["file_name"] << endl;


		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string compile_file = result_list[i1]["path"] + "\\" + result_list[i1]["file_name"];

		//载入词法流
		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		//构筑语法树
		Env env;
		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << result_list[i1]["file_name"] << ":" << "分析失败" << endl;
		}
		else {
			cout << result_list[i1]["file_name"] << ":" << "分析成功" << endl;
			//lalr.printStackTree(node_tree, "");
			unordered_map<string, string> imfo_map;
			lalr.gen_middle_code(env, node_tree, imfo_map);


			//lalr.printStackTree(node_tree, "");
			Node::releaseNode(node_tree);
		}



		//分析env begin
		CompileUnit* cu = (CompileUnit*)(env.list[0].get());
		Array* importClassListPtr = (Array*)cu->import_class_list.get();
		cout << "package=" << cu->package << endl;
		Array* p = (Array*)(cu->type_declaration_list.get());
		Class* classPtr = (Class*)(p->list[0].get());
		cout << "classType=" << classPtr->classType << endl;
		cout << "className=" << classPtr->className << endl;
		Array* classMembersPtr = (Array*)classPtr->list.get();





		classList.push_back(unordered_map<string, string>());
		classList.back()["id"] = Util::genUUID();
		classList.back()["fileId"] = result_list[i1]["id"];
		classList.back()["name"] = classPtr->className;
		classList.back()["package"] = cu->package;
		classList.back()["project"] = projectName;
		classList.back()["comment"] = "";



		
		for (auto &e : importClassListPtr->list) {
			importList.push_back(unordered_map<string, string>());
			importList.back()["id"] = Util::genUUID();
			importList.back()["fileId"] = result_list[i1]["id"];
			importList.back()["name"] = ((Import*)e.get())->name;
			importList.back()["isSingle"] = std::to_string(((Import*)e.get())->isSingle);
			importList.back()["isStatic"] = std::to_string(((Import*)e.get())->isStatic);
			importList.back()["project"] = projectName;
			importList.back()["comment"] = "";
		}


		//MethodDeclaration : MethodHeader MethodBody
	//MethodBody: Block

		for (auto &e : classMembersPtr->list) {
			if (e != nullptr&& e->tag == "Method") {
				cout << ((Method*)e.get())->methodName << endl;
				methodList.push_back(unordered_map<string, string>());
				methodList.back()["id"] = Util::genUUID();
				methodList.back()["classId"] = classList.back()["id"];
				methodList.back()["typeId"] = "0";
				methodList.back()["name"] = ((Method*)e.get())->methodName;
				methodList.back()["comment"] = "";
				methodList.back()["project"] = projectName;
				methodList.back()["bodyBeg"] = std::to_string(((Method*)e.get())->bodyBeg);
				methodList.back()["bodyEnd"] = std::to_string(((Method*)e.get())->bodyEnd);
				methodList.back()["bodyBegLine"] = std::to_string(((Method*)e.get())->bodyBegLine);
				methodList.back()["bodyEndLine"] = std::to_string(((Method*)e.get())->bodyEndLine);
			}
		}
		//分析env end
	}


	//填入结果
	tErpClassDao->insertList(classList);
	tErpMethodDao->insertList(methodList);
	tErpImportDao->insertList(importList);
}


//int main() {
//
//	sitTest();
//
//}



