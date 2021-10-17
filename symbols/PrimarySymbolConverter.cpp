#include "PrimarySymbolConverter.h"



PrimarySymbolConverter::PrimarySymbolConverter() {

}

PrimarySymbolConverter::~PrimarySymbolConverter() {

}


void PrimarySymbolConverter::convert(Lex_Word &oriLexWord, Lex_Word &newLexWord) {
	newLexWord.content = oriLexWord.content;

	if (oriLexWord.type == "'IDENTIFIER'") {
		if (oriLexWord.content == "package") {
			newLexWord.type = "'package'";
		}
		else if (oriLexWord.content == "import") {
			newLexWord.type = "'import'";
		}
		else if (oriLexWord.content == "public") {
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
		else if (oriLexWord.content == "extends") {
			newLexWord.type = "'extends'";
		}
		else if (oriLexWord.content == "implements") {
			newLexWord.type = "'implements'";
		}
		else if (oriLexWord.content == "byte") {
			newLexWord.type = "'byte'";
		}
		else if (oriLexWord.content == "short") {
			newLexWord.type = "'short'";
		}
		else if (oriLexWord.content == "char") {
			newLexWord.type = "'char'";
		}
		else if (oriLexWord.content == "int") {
			newLexWord.type = "'int'";
		}
		else if (oriLexWord.content == "long") {
			newLexWord.type = "'long'";
		}
		else if (oriLexWord.content == "float") {
			newLexWord.type = "'float'";
		}
		else if (oriLexWord.content == "double") {
			newLexWord.type = "'double'";
		}
		else if (oriLexWord.content == "boolean") {
			newLexWord.type = "'boolean'";
		}
		else {
			newLexWord.type = oriLexWord.type;
		}
	}else {
		newLexWord.type = oriLexWord.type;
	}



	
}


