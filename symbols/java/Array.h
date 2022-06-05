#pragma once
#include <memory>
#include <vector>
#include<string>
#include <deque>
#include"../Token.h"
using namespace std;


class Array : public Token {

public: deque<P_Token> list;


		//默认构造器
public: Array();


public: virtual ~Array();

};


