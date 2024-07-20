#pragma once
#include <memory>
#include <vector>
#include "StatementEntity.h"
#include "../Token.h"

using namespace std;



class StatementToken : public Token  {

public:  P_StatementEntity statementEntity = nullptr;




public: StatementToken();
public: virtual ~StatementToken();

};

typedef std::shared_ptr<StatementToken> P_StatementToken;