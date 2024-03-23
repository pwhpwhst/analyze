#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "NormalClassDeclaration.h"
using namespace std;



class NormalClassDeclaration : public Space {

public: string name;


public: NormalClassDeclaration();
public: NormalClassDeclaration(string &name);
public: virtual ~NormalClassDeclaration();

};

