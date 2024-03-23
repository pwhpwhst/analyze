#pragma once
#include "Space.h"
#include "EnumConstant.h"
using namespace std;



class EnumConstant : public Space {

public: string name;

public: EnumConstant();
public: EnumConstant(string &name);
public: virtual ~EnumConstant();

};

