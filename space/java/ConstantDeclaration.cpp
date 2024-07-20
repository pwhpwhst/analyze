#include "ConstantDeclaration.h"
using namespace std;



ConstantDeclaration::ConstantDeclaration(string &type, string &name) {
	Space::type = "ConstantDeclaration";
	this->type = type;
	this->name = name;
}

ConstantDeclaration::ConstantDeclaration() {
	Space::type = "ConstantDeclaration";
}

ConstantDeclaration::~ConstantDeclaration() {
}
