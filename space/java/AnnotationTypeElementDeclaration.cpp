#include "AnnotationTypeElementDeclaration.h"
using namespace std;





AnnotationTypeElementDeclaration::AnnotationTypeElementDeclaration() {
	Space::type = "AnnotationTypeElementDeclaration";
}

AnnotationTypeElementDeclaration::AnnotationTypeElementDeclaration(string &type, string &name) {
	Space::type = "AnnotationTypeElementDeclaration";
	this->type = type;
	this->name = name;
}

AnnotationTypeElementDeclaration::~AnnotationTypeElementDeclaration() {
}
