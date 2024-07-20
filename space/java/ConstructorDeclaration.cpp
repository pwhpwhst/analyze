#include "ConstructorDeclaration.h"
using namespace std;





ConstructorDeclaration::ConstructorDeclaration() {
	Space::type = "ConstructorDeclaration";
}

ConstructorDeclaration::ConstructorDeclaration(string &name) {
	Space::type = "ConstructorDeclaration";
	this->name = name;
}


ConstructorDeclaration::~ConstructorDeclaration() {
}
