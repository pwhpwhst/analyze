#pragma once
#include<vector>
#include "../../Entity/MethodOrFieldEntity.h"
#include "../../SLR/Node.h"

using namespace std;



class JAVASpaceTreeAnalyzer {

public: JAVASpaceTreeAnalyzer();
public: virtual ~JAVASpaceTreeAnalyzer();

public: void parse(Node *treeNode,vector<P_MethodOrFieldEntity> &result_vector);

public: void parse_ClassBody(MethodOrFieldEntity &entity, Node *node);
};







