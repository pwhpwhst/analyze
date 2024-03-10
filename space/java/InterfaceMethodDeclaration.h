#pragma once
#include<deque>
#include "Space.h"
#include "InterfaceMethodDeclaration.h"
#include "ParamDeclaration.h"
using namespace std;



class InterfaceMethodDeclaration : public Space {

public: string type;
public: string name;
public: deque<ParamDeclaration> paramList;
//public: deque<Space> spaceList;

public: InterfaceMethodDeclaration();
public: virtual ~InterfaceMethodDeclaration();

};