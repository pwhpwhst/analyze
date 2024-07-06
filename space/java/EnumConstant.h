#pragma once
#include "Space.h"
#include "EnumConstant.h"
#include "ParamDeclaration.h"
using namespace std;



class EnumConstant : public Space {

public: string name;
public: deque<ParamDeclaration> paramList;

public: EnumConstant();
public: EnumConstant(string &name);
public: virtual ~EnumConstant();

};

