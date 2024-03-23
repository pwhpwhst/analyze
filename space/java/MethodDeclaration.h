#pragma once
#include<deque>
#include "Space.h"
#include "MethodDeclaration.h"
#include "ParamDeclaration.h"
using namespace std;



class MethodDeclaration : public Space {

public: string type;
public: string name;
public: deque<ParamDeclaration> paramList;

public: MethodDeclaration();
public: MethodDeclaration(string &type, string &name);
public: virtual ~MethodDeclaration();

};

