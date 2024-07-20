#include "InterfaceMethodDeclaration.h"
using namespace std;





InterfaceMethodDeclaration::InterfaceMethodDeclaration() {
	Space::type = "InterfaceMethodDeclaration";
}


InterfaceMethodDeclaration::InterfaceMethodDeclaration(string &type, string &name) {
	Space::type = "InterfaceMethodDeclaration";
	this->type = type;
	this->name = name;
}

InterfaceMethodDeclaration::~InterfaceMethodDeclaration() {
}
