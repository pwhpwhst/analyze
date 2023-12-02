#pragma once
#include <memory>
#include <vector>
#include "ModifierEntity.h"
#include "../Token.h"

using namespace std;



class ModifierToken : public Token  {

public:  P_ModifierEntity modifierEntity;




public: ModifierToken();
public: virtual ~ModifierToken();

};

typedef std::shared_ptr<ModifierToken> P_ModifierToken;