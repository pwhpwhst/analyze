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
class pwh2 {

public:	pwh2();
public:	~pwh2();
};


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


 Parser *parser4;
 Parser *parser5;
 Parser *parser6;
 Parser *parser7;
 Parser *parser8;
 Parser *parser9;

void initParsers();

void deleteParsers();

void processContext(P_Context &context, deque<P_Context> &contextDeque);

void processCompilationUnit(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);


void processNormalClassDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);


void processNormalInterfaceDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);




void processEnumDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);


void processAnnotationTypeMemberDeclaration(Parser *parser4,
	Parser *parser5,
	Parser *parser6,
	Parser *parser7,
	Parser *parser8,
	Parser *parser9,
	PrimarySymbolConverter primarySymbolConverter,
	P_Context &context, deque<P_Context> &contextDeque,
	set<string> &end_symbol_set0);



void fillWithStatementFieldDeclaration(P_Context &context, Env &env);
void fillWithStatementConstantDeclaration(P_Context &context, Env &env);
void fillWithStatementMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter);
void fillWithStatementInterfaceMethodDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter);
void fillWithStatementAnnotationTypeElementDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter);

void fillWithStatementConstructorDeclaration(P_Context &context, Env &env, StatementListToken *&p, int &i1, Parser *parser6,
	PrimarySymbolConverter &primarySymbolConverter);
void fillWithClassTypeNormalClassDeclaration(P_Context &context, long &basegLineNum, long &baseIndex,Env &env, P_Context &childContext);
void fillWithClassTypeEnumDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext);
void fillWithClassTypeNormalInterfaceDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext);
void fillWithClassTypeAnnotationTypeDeclaration(P_Context &context, long &basegLineNum, long &baseIndex, Env &env, P_Context &childContext);







