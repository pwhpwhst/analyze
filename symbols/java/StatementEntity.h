#pragma once
#include <memory>
#include <string>
#include <deque>
#include "FieldToken.h"
#include "TypeListToken.h"
using namespace std;



class StatementEntity {


public: long begIndex = -1;	//词法流位置
public: long begLineNum = -1;	//词法流位置
public: long endIndex = -1;
public: long endLineNum = -1;
public: string type;
public: string resultType;
public: string name;
public: string endWith;
public: deque<P_FieldToken> fieldList;
public: P_Token typeParameters;



public: StatementEntity();
public: virtual ~StatementEntity();

};

typedef std::shared_ptr<StatementEntity> P_StatementEntity;