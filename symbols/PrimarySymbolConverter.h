#pragma once
using namespace std;
#include "..\SLR\Lex_Word.h"
# include<set>

class PrimarySymbolConverter {

private: bool is_comment1=false;
private: bool is_comment2 = false;
private: bool is_comment3 = false;
private: set<string> key_word_set;
private: unordered_map<string, string> env;

private: int lineNum = 1;
private: int colNum = 0;

public: PrimarySymbolConverter();

public: ~PrimarySymbolConverter();


public: void convert(Lex_Word &oriLexWord, Lex_Word &newLexWord);

public: void identifierMap(string idName, string type);

};



