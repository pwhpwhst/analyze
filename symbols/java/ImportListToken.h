#pragma once
#include <memory>
#include <deque>
#include "ImportEntity.h"
#include "../Token.h"

using namespace std;



class ImportListToken : public Token  {

public:  deque<P_ImportEntity> list;




public: ImportListToken();
public: virtual ~ImportListToken();

};

typedef std::shared_ptr<ImportListToken> P_ImportListToken;