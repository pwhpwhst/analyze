#pragma once
#include <memory>
#include <string>
using namespace std;




class ModifierEntity {


public: long index = -1;	//´Ê·¨Á÷Î»ÖÃ
public: long lineNum = -1;
public:  int begLine;
public:  int endLine;
public:  int begIndex;
public:  int endIndex;
public: string name;

public: ModifierEntity();
public: virtual ~ModifierEntity();

};

typedef std::shared_ptr<ModifierEntity> P_ModifierEntity;