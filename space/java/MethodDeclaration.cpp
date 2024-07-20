#include "MethodDeclaration.h"
using namespace std;





MethodDeclaration::MethodDeclaration() {
	Space::type = "MethodDeclaration";
}

MethodDeclaration::MethodDeclaration(string &type, string &name) {
	Space::type = "MethodDeclaration";
	this->type = type;
	this->name = name;
}



MethodDeclaration::~MethodDeclaration() {
}
