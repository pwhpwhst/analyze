#pragma once
#include "Space.h"
#include "TypeDeclaration.h"
using namespace std;



class TypeDeclaration : public Space {

public: string name;
public: deque<string> parmaList;

public: TypeDeclaration();
public: TypeDeclaration(string &name);
public: virtual ~TypeDeclaration();

};

