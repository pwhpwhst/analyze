#pragma once
#include <memory>
#include <string>
using namespace std;



class TypeEntity {

public:  string  name;

public: TypeEntity();
public: virtual ~TypeEntity();

};

typedef std::shared_ptr<TypeEntity> P_TypeEntity;