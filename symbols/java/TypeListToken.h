#pragma once
#include <memory>
#include <deque>
#include "TypeEntity.h"
#include "../Token.h"

using namespace std;



class TypeListToken : public Token  {

public:  deque<P_TypeEntity> list;

public:  int begLine;
public:  int endLine;
public:  int begIndex;
public:  int endIndex;


public: TypeListToken();
public: virtual ~TypeListToken();

};

typedef std::shared_ptr<TypeListToken> P_TypeListToken;