#pragma once
#include "Space.h"
#include "ConstantDeclaration.h"
using namespace std;



class ConstantDeclaration : public Space {

public: string type;
public: string name;

public: ConstantDeclaration(string &type, string &name);
public: ConstantDeclaration();
public: virtual ~ConstantDeclaration();

};

