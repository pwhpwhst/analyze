#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Method : public Token {

public: string methodName;

public: int bodyBeg;
public: int bodyEnd;
public: int bodyBegLine;
public: int bodyEndLine;


//默认构造器
public: Method();


public: virtual ~Method();

};


