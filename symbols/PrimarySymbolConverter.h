#pragma once
using namespace std;
#include "..\SLR\Lex_Word.h"

class PrimarySymbolConverter {

private: bool is_comment1=false;
private: bool is_comment2 = false;
private: bool is_comment3 = false;

public: PrimarySymbolConverter();

public: ~PrimarySymbolConverter();

private: unordered_map<string, unordered_map<string,string>> env;

public: void convert(Lex_Word &oriLexWord, Lex_Word &newLexWord);
	
};



