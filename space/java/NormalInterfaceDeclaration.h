#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "NormalInterfaceDeclaration.h"
using namespace std;



class NormalInterfaceDeclaration : public Space {

public: string name;
public: string superInterface;
public: deque<string> typeParameters;

public: NormalInterfaceDeclaration();
public: NormalInterfaceDeclaration(string &name);
public: virtual ~NormalInterfaceDeclaration();

};

