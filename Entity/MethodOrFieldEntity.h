#pragma once
#include <memory>
#include <string>
using namespace std;



class MethodOrFieldEntity {

public: string id;
public: string type;
public: string name;
public: string return_type;
public: string parameters;

public: MethodOrFieldEntity();
public: virtual ~MethodOrFieldEntity();

};

typedef std::shared_ptr<MethodOrFieldEntity> P_MethodOrFieldEntity;
