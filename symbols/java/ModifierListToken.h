#pragma once
#include <memory>
#include <deque>
#include "../Token.h"
#include "ModifierEntity.h"
using namespace std;



class ModifierListToken : public Token  {


public:  deque<P_ModifierEntity> list;



public: ModifierListToken();
public: virtual ~ModifierListToken();

};

typedef std::shared_ptr<ModifierListToken> P_ModifierListToken;