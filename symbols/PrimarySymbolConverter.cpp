#include "PrimarySymbolConverter.h"



PrimarySymbolConverter::PrimarySymbolConverter() {

}

PrimarySymbolConverter::~PrimarySymbolConverter() {

}


void PrimarySymbolConverter::convert(Lex_Word &oriLexWord, Lex_Word &newLexWord) {
	newLexWord.content = oriLexWord.content;

	if (oriLexWord.type == "'IDENTIFIER'") {
		if (oriLexWord.content == "public") {
			newLexWord.type = "'public'";
		}
		else if (oriLexWord.content == "protected") {
			newLexWord.type = "'protected'";
		}
		else if (oriLexWord.content == "private") {
			newLexWord.type = "'private'";
		}
		else if (oriLexWord.content == "static") {
			newLexWord.type = "'static'";
		}
		else if (oriLexWord.content == "abstract") {
			newLexWord.type = "'abstract'";
		}
		else if (oriLexWord.content == "final") {
			newLexWord.type = "'final'";
		}
		else if (oriLexWord.content == "native") {
			newLexWord.type = "'native'";
		}
		else if (oriLexWord.content == "synchronized") {
			newLexWord.type = "'synchronized'";
		}
		else if (oriLexWord.content == "transient") {
			newLexWord.type = "'transient'";
		}
		else if (oriLexWord.content == "volatile") {
			newLexWord.type = "'volatile'";
		}
		else if (oriLexWord.content == "class") {
			newLexWord.type = "'class'";
		}
//		else if (oriLexWord.content == "String") {
//			newLexWord.type = "'TypeParameter'";
//		}
		else {
			newLexWord.type = oriLexWord.type;
		}
	}else {
		newLexWord.type = oriLexWord.type;
	}



	
}


