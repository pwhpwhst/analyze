#pragma once
#include <memory>
#include <string>
#include "TypeEntity.h"

using namespace std;



class MethodEntity {

public:  long  id;
public:  long  classId;
public:  string  name;
public:  P_TypeEntity typeEntity = nullptr;


public: MethodEntity();
public: virtual ~MethodEntity();

};

typedef std::shared_ptr<MethodEntity> P_MethodEntity;