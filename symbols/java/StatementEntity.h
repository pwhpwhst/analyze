#pragma once
#include <memory>
#include <string>
using namespace std;



class StatementEntity {


public: long begIndex = -1;	//词法流位置
public: long begLineNum = -1;	//词法流位置
public: long endIndex = -1;
public: long endLineNum = -1;

public: StatementEntity();
public: virtual ~StatementEntity();

};

typedef std::shared_ptr<StatementEntity> P_StatementEntity;