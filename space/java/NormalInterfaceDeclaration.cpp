#include "NormalInterfaceDeclaration.h"
using namespace std;





NormalInterfaceDeclaration::NormalInterfaceDeclaration() {
	Space::type = "NormalInterfaceDeclaration";
}

NormalInterfaceDeclaration::NormalInterfaceDeclaration(string &name) {
	Space::type = "NormalInterfaceDeclaration";
	this->name = name;
}

NormalInterfaceDeclaration::~NormalInterfaceDeclaration() {
}
