#include "AnnotationTypeDeclaration.h"
using namespace std;





AnnotationTypeDeclaration::AnnotationTypeDeclaration() {
	Space::type = "AnnotationTypeDeclaration";
}

AnnotationTypeDeclaration::AnnotationTypeDeclaration(string &name) {
	Space::type = "AnnotationTypeDeclaration";
	this->name = name;
}

AnnotationTypeDeclaration::~AnnotationTypeDeclaration() {
}
