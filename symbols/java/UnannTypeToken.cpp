#include "UnannTypeToken.h"
#include<sstream>

using namespace std;





UnannTypeToken::UnannTypeToken() {
}

UnannTypeToken::~UnannTypeToken() {
}


string UnannTypeToken::getText() {
	
	ostringstream os;
	for (int i1 = 0; i1 < nameList.size(); i1++) {
		os << nameList[i1];
		if (i1!=(nameList.size()-1)) {
			os << ".";
		}
	}
	for (int i1 = 0; i1 < dimNum; i1++) {
		os << "[]";
	}
	
	
	return os.str();
}