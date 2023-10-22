#pragma once
#include <memory>
#include <string>
using namespace std;



class ImportEntity {

public:  long  id;
public:  string  name;
public:  bool  isStatic=false;


public: ImportEntity();
public: virtual ~ImportEntity();

};

typedef std::shared_ptr<ImportEntity> P_ImportEntity;