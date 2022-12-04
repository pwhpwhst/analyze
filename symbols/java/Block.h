#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Block : public Token {

public: int beg;
public: int end;
public: int lineBeg;
public: int lineEnd;

//默认构造器
public: Block();


public: virtual ~Block();

};


