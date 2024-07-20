#pragma once
#include <memory>
#include <string>
#include "../Token.h"
using namespace std;



class ClassEntity {

public:  long  id;
public:  string  name;
public:  string  type;
public:  string  package;
public: long index = -1;	//´Ê·¨Á÷Î»ÖÃ
public: long lineNum = -1;
public: P_Token typeParameters=nullptr;
public: P_Token superClass = nullptr;
public: P_Token superInterfaceList = nullptr;
public: P_Token statementList = nullptr;

public: ClassEntity();
public: virtual ~ClassEntity();

};

typedef std::shared_ptr<ClassEntity> P_ClassEntity;