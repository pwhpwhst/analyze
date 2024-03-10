#pragma once
#include <deque>
#include "Space.h"
#include "../../symbols/java/ImportEntity.h"
#include "AnnotationTypeDeclaration.h"
using namespace std;



class AnnotationTypeDeclaration : public Space {

public: string name;
public: string package;
public: deque<ImportEntity> importList;
//public: deque<Space> spaceList;

public: AnnotationTypeDeclaration();
public: AnnotationTypeDeclaration(string name);
public: virtual ~AnnotationTypeDeclaration();

};

