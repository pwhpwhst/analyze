#include "ParamDeclaration.h"
using namespace std;



ParamDeclaration::ParamDeclaration(string &type, string &name) {
	this->type = type;
	this->name = name;
}

ParamDeclaration::ParamDeclaration() {
}

ParamDeclaration::~ParamDeclaration() {
}
