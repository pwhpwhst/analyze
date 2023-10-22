#pragma once
#include <memory>
#include <vector>
#include "ClassEntity.h"
#include "../Token.h"

using namespace std;



class ClassToken : public Token  {

public:  P_ClassEntity classEntity;




public: ClassToken();
public: virtual ~ClassToken();

};

typedef std::shared_ptr<ClassToken> P_ClassToken;