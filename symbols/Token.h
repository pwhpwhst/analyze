#pragma once
#include <memory>
#include<string>
using namespace std;


class Token {

public: string tag;

public: string content;
public: long content2 = 0;

		//默认构造器
public: Token();

public: Token(const string &tag, const string &content, const long &content2);

public: virtual ~Token();

public: virtual Token* clone();

public: bool operator==(Token const& rh) const;
};

typedef std::shared_ptr<Token> P_Token;

