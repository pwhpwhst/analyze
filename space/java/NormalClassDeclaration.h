#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "NormalClassDeclaration.h"
using namespace std;



class NormalClassDeclaration : public Space {

public: string name;
public: string package;
public: deque<ImportEntity> importList;
//public: deque<Space> spaceList;

public: NormalClassDeclaration();
public: NormalClassDeclaration(string name);
public: virtual ~NormalClassDeclaration();

};

