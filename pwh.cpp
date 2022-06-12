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
			dirNew = dir + "\\" + findData.name;

			listFiles(dirNew, files);
		}
		else {
			files.push_back(dir + "\\" + findData.name);
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

/*
int main() {

	//getFileList("C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java");

	Env env;
	CompileInfo compileInfo;

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
			nodeList.clear();
			findSpecificNode(node_tree, "NormalClassDeclaration", nodeList);
			cout << e["file_name"] << ":" << nodeList.size() << endl;
			Node::releaseNode(node_tree);
		}

	}
	cout << "分析完成" << endl;
}
*/



void gen_middle_code(Lalr &lalr,Env &env, Node* &node_tree, unordered_map<string,string> &imfo_map) {

	cout << "生成中间代码:" << endl;

	//set<string> has_calculate_set;
	unordered_map<string, P_NodeValue> nodeValueMap;

	vector<P_NodeValue> stack;
	stack.push_back(P_NodeValue(new NodeValue(node_tree, NodeValue::SYN)));

	//P_NodeValue childNodeValue = nullptr;
	while (stack.size() > 0) {
		auto top = stack.back();
		string  sdtKey=lalr.ruleFileName + "_" + top->node->symbol + "_" + std::to_string(lalr.ruleIdToSubId[top->node->ruleId]);
		P_SDT_genertor sdt_genertor = SDT_Factory::instance.getSDT_genertor(sdtKey);
		if (sdt_genertor == nullptr) {
			cout<<sdtKey << "未定义";
			throw;
		}

		sdt_genertor->handle(top, stack, env, nodeValueMap);

	}

}



int main1() {
//	MD5算法来自于
// https://blog.csdn.net/think_A_lot/article/details/86749730

	//string rule_file4 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";

	//bool isChanged=isRuleFileChanged(rule_file4);

	//cout << "isChanged=" << isChanged << endl;

	//0 - 测试 -Package
	//1 - 测试 -expression
	//3 - 查看非终端符号实际囊括的终端符号
	//4 - 真实批量	done
	//5 - 真实单体	done
	//6 - 逐步小批量测试
	//7 - 真实单体

	Env env;
	CompileInfo compileInfo;

	int Mode0 = 0;
	int Mode1 = 1;
	int Mode3 = 3;
	int Mode4 = 4;
	int Mode5 = 5;
	int Mode6 = 6;
	int Mode7 = 7;

	int mode = 0;
	cout << "分析器初始化！" << endl;
	if (mode == Mode0) {

		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}
		lalr.switchParseProcess = false;
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
			//lalr.printStackTree(node_tree, "");
			unordered_map<string, string> imfo_map;
			gen_middle_code(lalr,env, node_tree, imfo_map);

			Array* p = (Array*)(env.list.get());
			Class* p2 = (Class*)(p->list[0].get());
			cout << "className=" << p2->className << endl;
			//lalr.printStackTree(node_tree, "");
			Node::releaseNode(node_tree);
		}


		//set<int> itemSet = { 101 };
		//lalr.printGraph(itemSet);

	}
	else if (mode == Mode1) {
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
	else if (mode == Mode3) {

		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ruleForPrimary.txt";




		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.calculate_f_terminate("Expression", rule_file0);
	}
	else if (mode == Mode4) {

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
				//cout << e["file_name"] << ":" << nodeList.size() << endl;
				Node::releaseNode(node_tree);
			}

		}
		cout << "分析完成" << endl;
	}else if (mode == Mode5) {
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = true;
		lalr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\org\\apache\\tomcat\\jni";
		string fileName = "Buffer.java";
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
	else if (mode == Mode6) {
		P_TCompileFileDao tCompileFileDao = TCompileFileDao::getInstance();
		unordered_map<string, string> transfer_map;
		vector<unordered_map<string, string>> result_list;
		string fileArr[] = {
		"AbandonedConfig.java",
		"AbandonedTrace.java",
		"AbsoluteOrder.java",
		"AbstractAccessLogValve.java",
		"AbstractAjpProtocol.java",
		"AbstractArchiveResource.java",
		"AbstractArchiveResourceSet.java",
		"AbstractCatalinaCommandTask.java",
		"AbstractCatalinaTask.java",
		"AbstractChunk.java",
		"AbstractEndpoint.java",
		"AbstractFileResourceSet.java",
		"AbstractGroup.java",
		"AbstractHttp11JsseProtocol.java",
		"AbstractHttp11Protocol.java",
		"AbstractInputStreamJar.java",
		"AbstractJsseEndpoint.java",
		"AbstractNonZeroStream.java",
		"AbstractObjectCreationFactory.java",
		"AbstractProcessor.java",
		"AbstractProcessorLight.java",
		"AbstractProtocol.java",
		"AbstractRef.java",
		"AbstractReplicatedMap.java",
		"AbstractResource.java",
		"AbstractResourceSet.java",
		"AbstractRole.java",
		"AbstractRxTask.java",
		"AbstractSender.java",
		"AbstractSingleArchiveResource.java",
		"AbstractSingleArchiveResourceSet.java",
		"AbstractStream.java",
		"AbstractStreamProvider.java",
		"AbstractUser.java",
		"AcceptEncoding.java",
		"AcceptLanguage.java",
		"Acceptor.java",
		"AccessLog.java",
		"AccessLogAdapter.java",
		"AccessLogValve.java",
		"ActionCode.java",
		"ActionHook.java",
		"Adapter.java",
		"AddDefaultCharsetFilter.java",
		"AddPortOffsetRule.java",
		"AjpMessage.java",
		"AjpNio2Protocol.java",
		"AjpNioProtocol.java",
		"AjpProcessor.java",
		"AnnotationElementValue.java",
		"AnnotationEntry.java",
		"Annotations.java",
		"AntCompiler.java",
		"ApplicationBufferHandler.java",
		"ApplicationContext.java",
		"ApplicationContextFacade.java",
		"ApplicationDispatcher.java",
		"ApplicationFilterChain.java",
		"ApplicationFilterConfig.java",
		"ApplicationFilterFactory.java",
		"ApplicationFilterRegistration.java",
		"ApplicationHttpRequest.java",
		"ApplicationHttpResponse.java",
		"ApplicationMapping.java",
		"ApplicationParameter.java",
		"ApplicationPart.java",
		"ApplicationPushBuilder.java",
		"ApplicationRequest.java",
		"ApplicationResponse.java",
		"ApplicationServletRegistration.java",
		"ApplicationSessionCookieConfig.java",
		"AprLifecycleListener.java",
		"AprStatus.java",
		"Arg.java",
		"ArithmeticNode.java",
		"ArrayElementValue.java",
		"ArrayELResolver.java",
		"Arrays.java",
		"ArrayStack.java",
		"Ascii.java",
		"Asn1Parser.java",
		"Asn1Writer.java",
		"AstAnd.java",
		"AstAssign.java",
		"AstBracketSuffix.java",
		"AstChoice.java",
		"AstCompositeExpression.java",
		"AstConcatenation.java",
		"AstDeferredExpression.java",
		"AstDiv.java",
		"AstDotSuffix.java",
		"AstDynamicExpression.java",
		"AstEmpty.java",
		"AstEqual.java",
		"AstFalse.java",
		"AstFloatingPoint.java",
		"AstFunction.java",
		"AstGreaterThan.java",
		"AstGreaterThanEqual.java",
		"AstIdentifier.java"
		};

		ostringstream os;
		for (int i1 = 0; i1 < 100;i1++) {
			os << "'" << fileArr[i1] << "'";
			if (i1!= 100-1) {
				os << "," ;
			}
		}
		transfer_map["fileNameList"] = os.str();
		transfer_map["orderFileName"] = "true";
		tCompileFileDao->queryList(transfer_map, result_list);

		
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;

		//result_list.back()["id"] = mysql_row[col_map["id"]];
		//result_list.back()["path"] = mysql_row[col_map["path"]];
		//result_list.back()["file_name"] = mysql_row[col_map["file_name"]];
		//result_list.back()["status"] = mysql_row[col_map["status"]];


		for (auto &e:result_list) {
			string path = e["path"];
			string fileName = e["file_name"];
			string className0 = lalr.replaceAll(fileName, ".java", "");
			string compile_file = path + "\\" + fileName;

			lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

			Node*  node_tree = lalr.slr(env, compileInfo);
			if (node_tree == nullptr) {
				cout << fileName << ":" << "分析失败" << endl;
			}
			else {
				//cout << fileName << ":" << "分析成功" << endl;
				vector<Node*> totalNodeList;
				vector<Node*> nodeList;

				nodeList.clear();
				findSpecificNode(node_tree, "NormalClassDeclaration", nodeList);
				for (const auto &e: nodeList) {
					totalNodeList.push_back(e);
				}
				

				nodeList.clear();
				findSpecificNode(node_tree, "NormalInterfaceDeclaration", nodeList);
				for (const auto &e : nodeList) {
					totalNodeList.push_back(e);
				}
				

				for (const auto &e : totalNodeList) {
					for (const auto e2 : e->child_node_list) {
						if (e2->symbol == "Identifier") {
							string _className = e2->child_node_list[0]->content;
							if (className0 != _className) {
								_className = className0 + "$" + _className;
							}
							cout << _className << endl;
						}
					}
				}

				Node::releaseNode(node_tree);
			}
		}
		
	}
	else if (mode == Mode7) {
		string rule_file0 = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\R001.txt";
		Lalr lalr;
		if (-1 == lalr.init(rule_file0)) {
			return -1;
		}

		lalr.switchParseProcess = false;
		lalr.switchNotSilent = true;
		PrimarySymbolConverter primarySymbolConverter;
		set<string> end_symbol_set0;
		string path = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat8\\java\\jakarta\\el";
		string className0 = "StandardELContext";
		string fileName = className0+".java";
		string compile_file = path + "\\" + fileName;



		lalr.init_total_lex_word_list(compile_file, primarySymbolConverter, end_symbol_set0);

		Node*  node_tree = lalr.slr(env, compileInfo);
		if (node_tree == nullptr) {
			cout << fileName << ":" << "分析失败" << endl;
		}
		else {
			cout << fileName << ":" << "分析成功" << endl;
			vector<Node*> nodeList;
			findSpecificNode(node_tree, "NormalClassDeclaration", nodeList);

			for (const auto &e : nodeList) {
				for (const auto e2:e->child_node_list) {
					if (e2->symbol == "Identifier") {
						string _className = e2->child_node_list[0]->content;
						if (className0!= _className) {
							_className = className0 + "$" + _className;
						}
						cout << _className << endl;
					}
				}
			}

			Node::releaseNode(node_tree);
		}
	}


}
