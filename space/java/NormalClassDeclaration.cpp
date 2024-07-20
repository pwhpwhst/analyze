#include "NormalClassDeclaration.h"
using namespace std;





NormalClassDeclaration::NormalClassDeclaration() {
	Space::type = "NormalClassDeclaration";
}

NormalClassDeclaration::NormalClassDeclaration(string &name) {
	Space::type = "NormalClassDeclaration";
	this->name = name;
}

NormalClassDeclaration::~NormalClassDeclaration() {
}
