#pragma once
#include "Space.h"
#include "ParamDeclaration.h"
using namespace std;



class ParamDeclaration : public Space {

public: string type;
public: string name;

public: ParamDeclaration();
public: ParamDeclaration(string &type, string &name);
public: virtual ~ParamDeclaration();

};

