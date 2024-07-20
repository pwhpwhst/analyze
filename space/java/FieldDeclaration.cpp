#include "FieldDeclaration.h"
using namespace std;



FieldDeclaration::FieldDeclaration(string &type, string &name) {
	Space::type = "FieldDeclaration";
	this->type = type;
	this->name = name;
}

FieldDeclaration::FieldDeclaration() {
	Space::type = "FieldDeclaration";
}

FieldDeclaration::~FieldDeclaration() {
}
