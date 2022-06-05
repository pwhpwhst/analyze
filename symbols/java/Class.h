#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Class :virtual public Token {

public: string className;
public: P_Token list;

//默认构造器
public: Class();


public: virtual ~Class();

};


