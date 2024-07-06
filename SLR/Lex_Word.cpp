#include<vector>
#include<iostream>
#include "Lex_Word.h"
#include  "../Util/Util.h"
using namespace std;

extern "C"
{
#include "lex.yy.h"
};



Lex_Word::Lex_Word(){
	//Util::log("create Lex_Word");
}


Lex_Word::Lex_Word(const string &type,const string &content){
this->type=type;
this->content=content;
}

Lex_Word::Lex_Word(const Lex_Word &lex_word){
this->type=lex_word.type;
this->content=lex_word.content;
this->lineNum = lex_word.lineNum;
this->colNum = lex_word.colNum;
this->index = lex_word.index;
}


Lex_Word::~Lex_Word(){
}


// word_parser(compile_file,total_lex_word_list);

void word_parser(const string& path,vector<P_Lex_Word> &lex_word_list, PrimarySymbolConverter *primarySymbolConverter){
   struct C_Lex_Word **beg=(struct C_Lex_Word **)malloc(sizeof(struct C_Lex_Word *));
   struct C_Lex_Word **end=(struct C_Lex_Word **)malloc(sizeof(struct C_Lex_Word *));
   char *c_path = const_cast<char *>(path.c_str()) ;
   c_word_parser(c_path,beg,end);
	struct C_Lex_Word *p=*beg;

	Lex_Word *pp1 = new Lex_Word();



	while(p!=*end){

		pp1->type = string(p->type);
		pp1->content = string(p->content);
		pp1->index = lex_word_list.size();

		Lex_Word *pp2 = new Lex_Word();
		primarySymbolConverter->convert(pp1, pp2);
		if (pp2->type != "0") {
			P_Lex_Word pp = P_Lex_Word(pp2);
			lex_word_list.push_back(pp);
		}

		p++;
	}
	free(beg);
	free(end);
	delete pp1;
	c_free();
}
