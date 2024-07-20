#include "EnumDeclaration.h"
using namespace std;





EnumDeclaration::EnumDeclaration() {
	Space::type = "EnumDeclaration";
}

EnumDeclaration::EnumDeclaration(string &name) {
	Space::type = "EnumDeclaration";
	this->name = name;
}

EnumDeclaration::~EnumDeclaration() {
}
