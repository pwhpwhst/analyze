#pragma once
#include <memory>
#include <string>
#include <deque>
using namespace std;



class StatementEntity {


public: long begIndex = -1;	//�ʷ���λ��
public: long begLineNum = -1;	//�ʷ���λ��
public: long endIndex = -1;
public: long endLineNum = -1;
public: string type;
public: string name;
public: string endWith;
public:  deque<string> nameList;

public: StatementEntity();
public: virtual ~StatementEntity();

};

typedef std::shared_ptr<StatementEntity> P_StatementEntity;