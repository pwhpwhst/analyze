#pragma once
#include "Space.h"
#include "FieldDeclaration.h"
using namespace std;



class FieldDeclaration : public Space {

public: string type;
public: string name;

public: FieldDeclaration();
public: FieldDeclaration(string &type, string &name);
public: virtual ~FieldDeclaration();

};

