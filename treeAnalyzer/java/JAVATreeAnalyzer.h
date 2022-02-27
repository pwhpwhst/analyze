#pragma once
#include<vector>
#include<unordered_map>
#include "../../Entity/MethodOrFieldEntity.h"
#include "../../SLR/Node.h"
#include "../TreeAnalyzer.h"
using namespace std;



class JAVATreeAnalyzer :virtual public TreeAnalyzer {

public: JAVATreeAnalyzer();
public: virtual ~JAVATreeAnalyzer();

public: void findTypeDeclarationListBegin(Node *treeNode, unordered_map<string, string> &resultMap);
};




