#pragma once
#include <memory>
#include<string>
#include"../Token.h"
using namespace std;


class Method : public Token {

public: string methodName;


//默认构造器
public: Method();


public: virtual ~Method();

};


