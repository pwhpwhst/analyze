#pragma once
#include <memory>
#include <string>
using namespace std;



class ModifierEntity {



public: long index = -1;	//�ʷ���λ��
public: long lineNum = -1;
public: string name;

public: ModifierEntity();
public: virtual ~ModifierEntity();

};

typedef std::shared_ptr<ModifierEntity> P_ModifierEntity;