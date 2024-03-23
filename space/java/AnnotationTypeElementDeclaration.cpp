#include "AnnotationTypeElementDeclaration.h"
using namespace std;





AnnotationTypeElementDeclaration::AnnotationTypeElementDeclaration() {
}

AnnotationTypeElementDeclaration::AnnotationTypeElementDeclaration(string &type, string &name) {
	this->type = type;
	this->name = name;
}

AnnotationTypeElementDeclaration::~AnnotationTypeElementDeclaration() {
}
