#include "FieldDeclaration.h"
using namespace std;



FieldDeclaration::FieldDeclaration(string &type, string &name) {
	this->type = type;
	this->name = name;
}

FieldDeclaration::FieldDeclaration() {
}

FieldDeclaration::~FieldDeclaration() {
}
