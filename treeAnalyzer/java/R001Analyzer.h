#pragma once
#include "../../SLR/SDT_genertor.h"
using namespace std;



class R001_DefaultAnalyzer :virtual public SDT_genertor {
public: R001_DefaultAnalyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_DefaultAnalyzer();
};

class R001_CompilationUnit_2Analyzer :virtual public SDT_genertor {
public: R001_CompilationUnit_2Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_CompilationUnit_2Analyzer();
};



class R001_TypeDeclarationList_1Analyzer :virtual public SDT_genertor {
public: R001_TypeDeclarationList_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_TypeDeclarationList_1Analyzer();
};



class R001_TypeDeclaration_0Analyzer :virtual public SDT_genertor {
public: R001_TypeDeclaration_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_TypeDeclaration_0Analyzer();
};



class R001_ClassDeclaration_0Analyzer :virtual public SDT_genertor {
public: R001_ClassDeclaration_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassDeclaration_0Analyzer();
};



class R001_NormalClassDeclaration_1Analyzer :virtual public SDT_genertor {
public: R001_NormalClassDeclaration_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_NormalClassDeclaration_1Analyzer();
};

class R001_ModifierList_1Analyzer :virtual public SDT_genertor {
public: R001_ModifierList_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ModifierList_1Analyzer();
};



class R001_Identifier_0Analyzer :virtual public SDT_genertor {
public: R001_Identifier_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_Identifier_0Analyzer();
};


class R001_ClassBody_0Analyzer :virtual public SDT_genertor {
public: R001_ClassBody_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassBody_0Analyzer();
};

class R001_ClassBodyDeclarationList_0Analyzer :virtual public SDT_genertor {
public: R001_ClassBodyDeclarationList_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassBodyDeclarationList_0Analyzer();
};


class R001_ClassBodyDeclaration_0Analyzer :virtual public SDT_genertor {
public: R001_ClassBodyDeclaration_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassBodyDeclaration_0Analyzer();
};

class R001_ClassMemberDeclaration_1Analyzer :virtual public SDT_genertor {
public: R001_ClassMemberDeclaration_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassMemberDeclaration_1Analyzer();
};

class R001_ClassMemberDeclaration_2Analyzer :virtual public SDT_genertor {
public: R001_ClassMemberDeclaration_2Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassMemberDeclaration_2Analyzer();
};


class R001_NormalClassDeclaration_0Analyzer :virtual public SDT_genertor {
public: R001_NormalClassDeclaration_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_NormalClassDeclaration_0Analyzer();
};




class R001_ClassBodyDeclarationList_1Analyzer :virtual public SDT_genertor {
public: R001_ClassBodyDeclarationList_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_ClassBodyDeclarationList_1Analyzer();
};


class R001_MethodDeclaration_1Analyzer :virtual public SDT_genertor {
public: R001_MethodDeclaration_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_MethodDeclaration_1Analyzer();
};


class R001_MethodHeader_12Analyzer :virtual public SDT_genertor {
public: R001_MethodHeader_12Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_MethodHeader_12Analyzer();
};


class R001_MethodDeclarator_0Analyzer :virtual public SDT_genertor {
public: R001_MethodDeclarator_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_MethodDeclarator_0Analyzer();
};

class R001_MethodBody_0Analyzer :virtual public SDT_genertor {
public: R001_MethodBody_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_MethodBody_0Analyzer();
};

class R001_Block_0Analyzer :virtual public SDT_genertor {
public: R001_Block_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_Block_0Analyzer();
};

class R001_BlockStatements_1Analyzer :virtual public SDT_genertor {
public: R001_BlockStatements_1Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_BlockStatements_1Analyzer();
};



class R001_NonBrace_0Analyzer :virtual public SDT_genertor {
public: R001_NonBrace_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_NonBrace_0Analyzer();
};


class R001_StatementEle_63Analyzer :virtual public SDT_genertor {
public: R001_StatementEle_63Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_StatementEle_63Analyzer();
};


class R001_StatementEle_0Analyzer :virtual public SDT_genertor {
public: R001_StatementEle_0Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_StatementEle_0Analyzer();
};




class R001_NonBrace_2Analyzer :virtual public SDT_genertor {
public: R001_NonBrace_2Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_NonBrace_2Analyzer();
};



class R001_BlockStatements_2Analyzer :virtual public SDT_genertor {
public: R001_BlockStatements_2Analyzer();
public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);
public: ~R001_BlockStatements_2Analyzer();
};
