//#define __PRINT_NODE_TREE





#include"symbols\Env.h"
#include"symbols\CompileInfo.h"
#include"slr.h"
#include"slr2.h"
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





int testForSynax(){
//string rule_file="E:\\Users\\Administrator\\Desktop\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\pwh的试验\\ruleForLexical.txt";
//string compile_file="E:\\Users\\Administrator\\Desktop\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\pwh的试验\\testForLexical.txt";

string rule_file="C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\rule.txt";
//string compile_file= "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh.java";
string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";
string ignore_file_path = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ignore.txt";

//string rule_file="F:\\codeWeaponStore\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\rule.txt";
//string compile_file="F:\\codeWeaponStore\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\test.txt";
Env env;
//



cout<<"尝试将java转成符号表！"<<endl;
Slr slr;
CompileInfo compileInfo;
PrimarySymbolConverter primarySymbolConverter;

if (-1 == slr.init(rule_file)) {
	return -1;
}
slr.init_total_lex_word_list(compile_file, primarySymbolConverter);
Node*  node_tree =slr.slr( env, compileInfo);


#ifdef __PRINT_NODE_TREE
if (node_tree != nullptr) {
	//printStack(node_tree);
	slr.printStackTree(node_tree, ignore_file_path);
}
#endif

JAVATreeAnalyzer javaTreeAnalyzer;
vector<P_MethodOrFieldEntity> result_vector;

javaTreeAnalyzer.parse(node_tree, result_vector);

cout << endl;
for (auto &e : result_vector) {
	cout << e->beg_index<<","<<e->end_index << endl;
}


delete node_tree;

cout<<"检测完成！"<<endl;

return 0;
}


int testForSpace() {



	string rule_file = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForSpace.txt";

	Env env;
	cout << "尝试将java转成符号表！" << endl;
	Slr slr;
	CompileInfo compileInfo;
	PrimarySymbolConverter primarySymbolConverter;

	if (-1 == slr.init(rule_file)) {
		return -1;
	}

	string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";
	slr.init_total_lex_word_list(compile_file, primarySymbolConverter);
	Node*  node_tree = slr.slr(env, compileInfo);


	string ignore_file_path = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ignore.txt";
	#ifdef __PRINT_NODE_TREE
		if (node_tree != nullptr) {
			//printStack(node_tree);
			slr.printStackTree(node_tree, ignore_file_path);
		}
	#endif


	JAVASpaceTreeAnalyzer javaSpaceTreeAnalyzer;
	vector<P_MethodOrFieldEntity> result_vector;

	if (node_tree != nullptr) {
		javaSpaceTreeAnalyzer.parse(node_tree, result_vector);

		cout << endl;
		for (auto &e : result_vector) {
			cout << e->beg_index << "," << e->end_index << endl;
		}
		delete node_tree;
	}

	cout << "检测完成！" << endl;

	return 0;
}




void testForLexer(){
	//string compile_file="C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh.java";
	string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";

Env env;
vector<P_Lex_Word>  total_lex_word_list;
total_lex_word_list.clear();
word_parser(compile_file,total_lex_word_list);

PrimarySymbolConverter primarySymbolConverter;

vector<P_Lex_Word>  primary_total_lex_word_list;



for(P_Lex_Word &e:total_lex_word_list){
	primary_total_lex_word_list.push_back(P_Lex_Word(new Lex_Word()));
	primarySymbolConverter.convert(*e,*primary_total_lex_word_list.back());
}

for (P_Lex_Word &e : primary_total_lex_word_list) {
	cout << e->type <<","<< e->content << endl;
}

}

void getFiles(string path, vector<string>& files)
{
	deque<string> deq;
	_finddata_t file;
	int k;
	__int64 handle;
	k = handle = _findfirst((path + "\\*").data(), &file);
	
	while (k != -1)
	{
		string file_name(file.name);
		if (file_name != "."&&file_name != "..") {
			deq.push_front(file.name);
			cout << file_name << endl;
		}
		k = _findnext(handle, &file);
	}
	_findclose(handle);


}


void listFiles(const string dir, vector<string>& files)
{
	string dirNew;
	dirNew = dir + "\\*.*";    // 在目录后面加上"\\*.*"进行第一次搜索

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew.data(), &findData);
	if (handle == -1)        // 检查是否成功
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			//cout << findData.name << "\t<dir>\n";

			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			dirNew = dir + "\\"+ findData.name;

			listFiles(dirNew, files);
		}
		else {
			files.push_back(dir + "\\" +findData.name);
		}
			
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // 关闭搜索句柄
}

bool endsWith(string s, string sub) {
	return s.rfind(sub) == (s.length() - sub.length());
}

void getFileList(string base_path) {
	//获取文件列表 begin
	vector<string> files;
	//	string base_path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java";
		//getFiles(path, files);
	listFiles(base_path.data(), files);

	vector <string> behaves;
	ostringstream os;
	vector <unordered_map<string, string>> file_list;

	for (auto &e : files) {
		behaves.clear();
		boost::split(behaves, e, boost::is_any_of("\\"));
		if (endsWith(behaves.back(), ".java")) {
			file_list.push_back(unordered_map<string, string>());
			os.str("");
			if (behaves.size() > 1) {
				for (int i1 = 0; i1 < (behaves.size() - 1); i1++) {
					os << behaves[i1];
					if (i1 != (behaves.size() - 2)) {
						os << "\\\\";
					}
				}
			}
			file_list.back()["path"] = os.str();
			file_list.back()["fileName"] = behaves.back();
			file_list.back()["status"] = "0";
		}
	}

	P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
	tCompileFileDao->insertList(file_list);
	//获取文件列表 end
}




int main(){

	
	//getFileList("C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java");

	string rule_file = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForSpace.txt";

	Env env;
	cout << "分析器初始化！" << endl;
	Slr slr;
	Slr2 slr2;
	CompileInfo compileInfo;
	



	//单体分析 - 词法分析
	/*
	PrimarySymbolConverter primarySymbolConverter;
	slr.init_total_lex_word_list("C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\jakarta\\el\\ArrayELResolver.java", primarySymbolConverter);
	cout << "abcd" << endl;
	*/

	//单体分析 - 文法分析
	/*
	0-单体分析
	1-批量分析
	2-非终端对应什么终端？
	*/
	int mode= 0;

	if (mode==0) {


		if (-1 == slr2.init(rule_file)) {
			return -1;
		}
		if (-1 == slr.init(rule_file)) {
			return -1;
		}

		for (int i1 = 0; i1 < slr.items_list.size();i1++) {
			



			for (int i2 = 0; i2 < slr.items_list[i1].size();i2++) {
				
				bool isMatch=true;
				if (slr.items_list[i1][i2]->end_for_symbol.size() != slr2.items_list[i1][i2]->end_for_symbol.size()) {
					
					isMatch = false;
				}
				else {
					for (const auto &e : slr.items_list[i1][i2]->end_for_symbol) {
						if (slr2.items_list[i1][i2]->end_for_symbol.count(e)==0) {
							isMatch = false;
							break;
						}
					}
				}

				if (!isMatch) {
					cout << "项" << i1 <<","<< slr.items_list[i1][i2]->rule->index << "有差异" << endl;
					cout <<"新:" << endl;
					cout << slr.items_list[i1][i2]->rule->rule_name;
					cout << " :";
					for (auto e2 : slr.items_list[i1][i2]->rule->symbols) {
						cout << " " << e2;
					}
					cout << " " << slr.items_list[i1][i2]->status << " ###";
					for (auto e2 : slr.items_list[i1][i2]->end_for_symbol) {
						cout << " " << e2;
					}
					cout << endl;


					cout << "旧:" << endl;
					cout << slr2.items_list[i1][i2]->rule->rule_name;
					cout << " :";
					for (auto e2 : slr2.items_list[i1][i2]->rule->symbols) {
						cout << " " << e2;
					}
					cout << " " << slr2.items_list[i1][i2]->status << " ###";
					for (auto e2 : slr2.items_list[i1][i2]->end_for_symbol) {
						cout << " " << e2;
					}
					cout << endl;


				}

			}
		}

		

		
		/*
		slr.switchParseProcess = true;
		slr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		slr.init_total_lex_word_list("C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\jakarta\\annotation\\Generated.java", primarySymbolConverter);
		

		Node*  node_tree = slr.slr(env, compileInfo); 
		if (node_tree == nullptr) {
			cout << "Generated.java" << ":" << "分析失败" << endl;
		}
		else {
			cout << "Generated.java" << ":" << "分析成功" << endl;
			Node::releaseNode(node_tree);
		}
		*/
	}
	else if(mode==1) {
		if (-1 == slr.init(rule_file)) {
			return -1;
		}
	//批量分析 - 文法分析
			slr.switchParseProcess = false;
			slr.switchNotSilent = true;
			P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
			unordered_map<string, string> transfer_map;
			//transfer_map["start_id"] = "505657";
			transfer_map["start_id"] = "505455";
			transfer_map["end_id"] = "505857";
		//	505455~505656												508916
			vector<unordered_map<string, string>> result_list;


		tCompileFileDao->queryList(transfer_map, result_list);
			for (auto &e:result_list) {
				string compile_file =e["path"]+"\\"+ e["file_name"];
		//		string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";
				PrimarySymbolConverter primarySymbolConverter;
				slr.init_total_lex_word_list(compile_file, primarySymbolConverter);
				Node*  node_tree = slr.slr(env, compileInfo);
				if (node_tree==nullptr) {
					cout << e["file_name"] << ":" << "分析失败" << endl;
				}
				else {
					cout << e["file_name"] << ":" << "分析成功" << endl;
					Node::releaseNode(node_tree);
				}
			}

			cout << "分析完成" << endl;

			
	}
	else if (mode==2) {
		slr.calculate_f_terminate("Expression", rule_file);
	}













	//testForSynax();
	//testForLexer();
	//testForSpace();




}


