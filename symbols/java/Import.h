#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Import : public Token {

public: string name;
public: int isStatic;
public: int isSingle;

//默认构造器
public: Import();


public: virtual ~Import();

};


