#include"symbols\Env.h"
#include"symbols\CompileInfo.h"
#include"Lalr.h"
#include"Lr1.h"
#include"symbols\Type.h"
#include"symbols\Tag.h"
#include"SLR\Lex_Word.h"
#include"SLR\NodeValue.h"
#include"SLR\SDT_Factory.h"
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
#include "symbols/java/Array.h"
#include "symbols/java/Class.h"
#include "symbols/java/CompileUnit.h"


int main2() {

	Env env;
	CompileInfo compileInfo;

	//0 - 测试 -Package
	//1 - 测试 -expression
	//3 - 查看非终端符号实际囊括的终端符号
	//4 - 真实批量	done
	//5 - 真实单体	done
	//6 - 逐步小批量测试
	//7 - 真实单体

	int Mode0 = 0;
	int Mode1 = 1;
	int Mode3 = 3;
	int Mode4 = 4;
	int Mode5 = 5;
	int Mode6 = 6;
	int Mode7 = 7;

	int mode = 4;

	if (mode == Mode4) {
		
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";

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

		for (int i1 = 0; i1 < result_list.size(); i1++) {

			auto &e = result_list[i1];

			string compile_file = e["path"] + "\\" + e["file_name"];

			lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

			Node*  node_tree = lalr.slr(env, compileInfo);
			if (node_tree == nullptr) {
				cout << e["file_name"] << ":" << "分析失败" << endl;
			}
			else {
				//cout << e["file_name"] << ":" << "分析成功" << endl;
				unordered_map<string, string> imfo_map;
				lalr.gen_middle_code(env, node_tree, imfo_map);
				Node::releaseNode(node_tree);
			}


			int class_num = 0;
			vector<Class*> class_stack;
			CompileUnit* cu = (CompileUnit*)(env.list[0].get());
			Array* p = (Array*)(cu->type_declaration_list.get());
			//Class* p2 = (Class*)(p->list[0].get());
			set<Class*> has_visited_set;

			if (p != nullptr) {
				for (auto &e : p->list) {
					Class* p2 = (Class*)e.get();
					if (p2 != nullptr) {
						class_stack.push_back(p2);
					}
				}
			}

			while (class_stack.size() > 0) {
				Class* presentPtr = class_stack.back();
				Array* arrayPtr = (Array*)presentPtr->list.get();
				bool is_completed = true;
				for (auto &e : arrayPtr->list) {
					if (e.get() != nullptr) {
						Class* nextPtr = (Class*)e.get();
						if (has_visited_set.count(nextPtr) == 0) {
							class_stack.push_back(nextPtr);
							is_completed = false;
						}
					}
				}
				if (is_completed) {
					has_visited_set.insert(presentPtr);
					//cout << "classType=" << presentPtr->classType << endl;
					//cout << "className=" << presentPtr->className << endl;
					//if (presentPtr->classType == "NormalClassDeclaration") {
					//	class_num++;
					//}
					if (presentPtr->classType == "EnumDeclaration") {
						class_num++;
					}

					class_stack.pop_back();
				}
			}

			cout << e["file_name"] << ":" << class_num << endl;

		}
		cout << "分析完成" << endl;

	}
	else if (mode == Mode5) {
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = true; 
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0; 
		string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\tomcat\\util\\http\\fileupload\\servlet";
		string fileName = "package-info.java";
		string compile_file = path + "\\" + fileName;

		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << fileName << ":" << "分析失败" << endl;
		}
		else {
			cout << fileName << ":" << "分析成功" << endl;
			unordered_map<string, string> imfo_map;
			lalr.gen_middle_code(env, node_tree, imfo_map);
			Node::releaseNode(node_tree);
		}

		int class_num = 0;
		vector<Class*> class_stack;
		CompileUnit* cu = (CompileUnit*)(env.list[0].get());
		Array* p = (Array*)(cu->type_declaration_list.get());
		//Class* p2 = (Class*)(p->list[0].get());
		set<Class*> has_visited_set;

		if (p!=nullptr) {
			for (auto &e : p->list) {
				Class* p2 = (Class*)e.get();
				if (p2 != nullptr) {
					class_stack.push_back(p2);
				}
			}
		}


		

		while (class_stack.size()>0) {
			Class* presentPtr=class_stack.back();
			Array* arrayPtr = (Array*)presentPtr->list.get();
			bool is_completed=true;
			for (auto &e : arrayPtr->list) {
					if (e.get() != nullptr) {
						Class* nextPtr = (Class*)e.get();
						if (has_visited_set.count(nextPtr)==0) {
							class_stack.push_back(nextPtr);
							is_completed = false;
						}
					}				
			}
			if (is_completed) {
				has_visited_set.insert(presentPtr);
				//cout << "classType=" << presentPtr->classType << endl;
				//cout << "className=" << presentPtr->className << endl;
				if (presentPtr->classType=="NormalInterfaceDeclaration") {
					class_num++;
				}
				
				class_stack.pop_back();
			}
		}

		cout << fileName<<":" << class_num;

		//cout << "classType=" << p2->classType << endl;
		//cout << "className=" << p2->className << endl;
		//Array* p3 = (Array*)p2->list.get();

		//for (auto &e: p3->list) {
		//	if (e.get() != nullptr) {
		//		Class* p4 = (Class*)e.get();
		//		cout << "classType=" << p4->classType << endl;
		//		cout << "subClassName=" << p4->className << endl;
		//	}
		//}
	}


}