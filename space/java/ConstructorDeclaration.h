#pragma once
#include<deque>
#include "Space.h"
#include "ConstructorDeclaration.h"
#include "ParamDeclaration.h"
using namespace std;



class ConstructorDeclaration : public Space {

public: string name;
public: deque<ParamDeclaration> paramList;

public: ConstructorDeclaration();
public: ConstructorDeclaration(string name);
public: virtual ~ConstructorDeclaration();

};

