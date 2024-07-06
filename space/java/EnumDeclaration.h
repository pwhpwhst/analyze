#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "EnumDeclaration.h"
using namespace std;



class EnumDeclaration : public Space {

public: string name;
public: deque<string> superInterfaces;


public: EnumDeclaration();
public: EnumDeclaration(string &name);
public: virtual ~EnumDeclaration();

};

