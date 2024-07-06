#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "NormalClassDeclaration.h"
using namespace std;



class NormalClassDeclaration : public Space {

public: string name;
public: deque<string> superInterface;
public: string superClasses;
public: deque<string> typeParameters;

public: NormalClassDeclaration();
public: NormalClassDeclaration(string &name);
public: virtual ~NormalClassDeclaration();

};

