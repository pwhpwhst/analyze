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

public: long beg_index = -1;
public: long end_index = -1;

public: MethodOrFieldEntity();
public: virtual ~MethodOrFieldEntity();

};

typedef std::shared_ptr<MethodOrFieldEntity> P_MethodOrFieldEntity;
