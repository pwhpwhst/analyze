#pragma once
using namespace std;
#include "..\SLR\Lex_Word.h"
# include<set>

class Lex_Word;
typedef std::shared_ptr<Lex_Word> P_Lex_Word;

class PrimarySymbolConverter {
/*
ע���˳�
������ʶ lineNum colNum
�ؼ���ת�� ��identifier ת int ʲô�ģ�
*/
private: bool is_comment1=false;
private: bool is_comment2 = false;
private: bool is_comment3 = false;
private: bool spotStar = false;
private: set<string> key_word_set;
private: unordered_map<string, string> env;

private: int lineNum = 1;
private: int colNum = 0;

public: PrimarySymbolConverter();

public: ~PrimarySymbolConverter();

public: void convert(Lex_Word *oriLexWord, Lex_Word *newLexWord);

public: void convert(const string &type, Lex_Word *oriLexWord, vector<P_Lex_Word>  &_total_lex_word_list);

public: void identifierMap(string idName, string type);

public: void initPositionInfo();
};



