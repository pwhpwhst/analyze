#pragma once
#include <memory>
#include <vector>
#include "ImportEntity.h"
#include "../Token.h"

using namespace std;



class ImportToken : public Token  {

public:  P_ImportEntity importEntity;




public: ImportToken();
public: virtual ~ImportToken();

};

typedef std::shared_ptr<ImportToken> P_ImportToken;