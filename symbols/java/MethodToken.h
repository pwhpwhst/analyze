#pragma once
#include <memory>
#include <vector>
#include "MethodEntity.h"
#include "../Token.h"

using namespace std;



class MethodToken : public Token  {

public:  vector<P_MethodEntity> list;




public: MethodToken();
public: virtual ~MethodToken();

};

typedef std::shared_ptr<MethodToken> P_MethodToken;