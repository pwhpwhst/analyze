#pragma once
#include <memory>
#include <deque>
#include "ClassEntity.h"
#include "ImportListToken.h"
#include "../Token.h"

using namespace std;



class ClassListToken : public Token  {

public: P_Token importList;
public:  deque<P_ClassEntity> list;
public: string packageName;



public: ClassListToken();
public: virtual ~ClassListToken();

};

typedef std::shared_ptr<ClassListToken> P_ClassListToken;