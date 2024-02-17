#pragma once
#include <memory>
#include <string>
#include "../Token.h"
using namespace std;



class FieldToken : public Token {

public:  bool  isPrimitiveType;
public:  string  unannType;
public:  string  name;
public:  int  dimNum;
public: bool isMultiParameters;
public: bool isReceiverParameter;


public: FieldToken();
public: virtual ~FieldToken();

};

typedef std::shared_ptr<FieldToken> P_FieldToken;