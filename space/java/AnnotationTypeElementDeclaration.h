#pragma once
#include "Space.h"
#include "AnnotationTypeElementDeclaration.h"
using namespace std;



class AnnotationTypeElementDeclaration : public Space {

public: string type;
public: string name;

public: AnnotationTypeElementDeclaration();
public: virtual ~AnnotationTypeElementDeclaration();

};

