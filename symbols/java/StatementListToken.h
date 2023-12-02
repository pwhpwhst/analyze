#pragma once
#include <memory>
#include <deque>
#include "StatementEntity.h"
#include "../Token.h"

using namespace std;



class StatementListToken : public Token  {


public:  deque<P_StatementEntity> list;




public: StatementListToken();
public: virtual ~StatementListToken();

};

typedef std::shared_ptr<StatementListToken> P_StatementListToken;