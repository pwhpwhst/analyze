#pragma once
#include <memory>
#include <vector>
#include <deque>
#include "../Token.h"

using namespace std;



class UnannTypeToken : public Token  {

public:  bool isPrimitive;
public:  deque<string> nameList;
public:  int dimNum=0;
public: string getText();

public: UnannTypeToken();
public: virtual ~UnannTypeToken();

};

typedef std::shared_ptr<UnannTypeToken> P_UnannTypeToken;