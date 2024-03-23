#pragma once
#include<deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "CompilationUnit.h"
using namespace std;



class CompilationUnit : public Space {

public: string package;
public: deque<ImportEntity> importList;

public: CompilationUnit();
public: CompilationUnit(string &name);
public: virtual ~CompilationUnit();

};

