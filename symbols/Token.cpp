#include "Token.h"
#include <iostream>
using namespace std;



Token::Token(){
}

Token::Token(const string &tag,const string &content, const long &content2){
	this->tag=tag;
	this->content=content;
	this->content2 = content2;
}




Token::~Token(){
}

Token * Token::clone(){
    Token* p= new Token();
	p->tag=this->tag;
	p->content=this->content;
	p->content2 = this->content2;
	return p;
}

bool Token::operator==(Token const& rh) const{
	return this->tag== rh.tag;
	return this->content== rh.content;
}



