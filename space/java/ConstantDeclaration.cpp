#include "ConstantDeclaration.h"
using namespace std;



ConstantDeclaration::ConstantDeclaration(string &type, string &name) {
	this->type = type;
	this->name = name;
}

ConstantDeclaration::ConstantDeclaration() {
}

ConstantDeclaration::~ConstantDeclaration() {
}
