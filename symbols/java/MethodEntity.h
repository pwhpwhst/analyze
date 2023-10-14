#pragma once
#include <memory>
#include <string>
using namespace std;



class MethodEntity {

public:  long  id;
public:  long  classId;
public:  string  name;



public: MethodEntity();
public: virtual ~MethodEntity();

};

typedef std::shared_ptr<MethodEntity> P_MethodEntity;