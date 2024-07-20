#include "EnumConstant.h"
using namespace std;





EnumConstant::EnumConstant() {
	type = "EnumConstant";
}

EnumConstant::EnumConstant(string &name) {
	type = "EnumConstant";
	this->name = name;
}


EnumConstant::~EnumConstant() {
}
