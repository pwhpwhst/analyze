#pragma once
#include <memory>
#include <string>
using namespace std;



class ClassEntity {

public:  long  id;
public:  string  name;
public:  string  package;



public: ClassEntity();
public: virtual ~ClassEntity();

};

typedef std::shared_ptr<ClassEntity> P_ClassEntity;