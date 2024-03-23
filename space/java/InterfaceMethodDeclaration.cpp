#include "InterfaceMethodDeclaration.h"
using namespace std;





InterfaceMethodDeclaration::InterfaceMethodDeclaration() {
}


InterfaceMethodDeclaration::InterfaceMethodDeclaration(string &type, string &name) {
	this->type = type;
	this->name = name;
}

InterfaceMethodDeclaration::~InterfaceMethodDeclaration() {
}
