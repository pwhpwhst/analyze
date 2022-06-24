#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Class : public Token {

public: string className;
public: string classType;
public: P_Token list;
public: P_Token prev;

//默认构造器
public: Class();


public: virtual ~Class();

};


