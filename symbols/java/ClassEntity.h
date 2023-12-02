#pragma once
#include <memory>
#include <string>
using namespace std;



class ClassEntity {

public:  long  id;
public:  string  name;
public:  string  package;
public: long index = -1;	//´Ê·¨Á÷Î»ÖÃ
public: long lineNum = -1;


public: ClassEntity();
public: virtual ~ClassEntity();

};

typedef std::shared_ptr<ClassEntity> P_ClassEntity;