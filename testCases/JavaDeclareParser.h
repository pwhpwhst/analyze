#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "../symbols/Env.h"
#include "../Parser.h"
using namespace std;

struct Context {
	string compile_file;
	int beginIndex;
	int endIndex;
	string type;
	P_Token token;
	Space *parent;
	Space *root;
};

typedef std::shared_ptr<Context> P_Context;

class JavaDeclareParser {


private:Parser *parser4;
private:Parser *parser5;
private:Parser *parser6;
private:Parser *parser7;
private:Parser *parser8;
private:Parser *parser9;
private:Parser *parser10;

private:int spaceSeq;

private:deque<P_Context> contextDeque;

private:PrimarySymbolConverter* primarySymbolConverter;

private:void initParser(Parser *&parser, const string& parserType, bool logSwitch, string& ruelFile);
private:void setSpaceId(Space *&space, int parentId,int id);

private:void processContext(P_Context &context);
private:void processCompilationUnit(P_Context &context);
private:void processNormalClassDeclaration(P_Context &context);
private:void processNormalInterfaceDeclaration(P_Context &context);
private:void processEnumDeclaration(P_Context &context);
private:void processAnnotationTypeMemberDeclaration(P_Context &context);


private:void fillWithStatementFieldDeclaration(P_Context &context, Env &env);
private:void fillWithStatementConstantDeclaration(P_Context &context, Env &env);
private:void fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1);
private:void fillWithStatementInterfaceMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1);
private:void fillWithStatementAnnotationTypeElementDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1);
private:void fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1);

private:void fillWithClassTypeNormalClassDeclaration(P_Context &context, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext);
private:void fillWithClassTypeEnumDeclaration(P_Context &context, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext);
private:void fillWithClassTypeNormalInterfaceDeclaration(P_Context &context, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext);
private:void fillWithClassTypeAnnotationTypeDeclaration(P_Context &contex, long &baseIndex, Env &env, int classTypeIndex, P_Context &childContext);

private:string replaceAll(string str, string sub, string replacement);

public:void initParsers();
public:void parse(vector<string> &files, string appName,int baseFileId);

public:void saveResult(P_Context &context, const string &appName, const string &fileName, const string &md5, int fileId);
public:void delResult(const string &appName, const string &fileName);

public:void deleteParsers();

public: JavaDeclareParser();
public: virtual ~JavaDeclareParser();

};






