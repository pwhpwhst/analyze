#pragma once
#include <memory>
#include <vector>
#include "TypeEntity.h"
#include "../Token.h"

using namespace std;



class TypeToken : public Token  {

public:  P_TypeEntity typeEntity = nullptr;




public: TypeToken();
public: virtual ~TypeToken();

};

typedef std::shared_ptr<TypeToken> P_TypeToken;