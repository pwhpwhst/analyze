#pragma once
#include<vector>
#include "../Entity/MethodOrFieldEntity.h"
#include "../SLR/Node.h"
using namespace std;



class JAVATreeAnalyzer {

public: JAVATreeAnalyzer();
public: virtual ~JAVATreeAnalyzer();

public: void parse(Node *treeNode,vector<P_MethodOrFieldEntity> &result_vector);

private:void parse_MethodOrFieldDecl(MethodOrFieldEntity &entity, Node *node);

private:void parse_Type(MethodOrFieldEntity &entity, Node *node);

private:void parse_MethodOrFieldRest(MethodOrFieldEntity &entity, Node *node);

private:void parse_FormalParameterDecls(MethodOrFieldEntity &entity, Node *node);
};




