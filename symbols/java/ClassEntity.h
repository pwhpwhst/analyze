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
public: P_Token typeParameters;
public: P_Token superClass;
public: P_Token superInterfaceList;
public: P_Token statementList;

public: ClassEntity();
public: virtual ~ClassEntity();

};

typedef std::shared_ptr<ClassEntity> P_ClassEntity;