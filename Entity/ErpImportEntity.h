#pragma once
#include <memory>
#include <string>
using namespace std;



class ErpImportEntity {

public:  string  id;
public:  long fileId;
public:  string  name;
public:  long isStatic;
public:  long isSingle;
public:  string  project;
public:  string  comment;


public: ErpImportEntity();
public: virtual ~ErpImportEntity();

};

typedef std::shared_ptr<ErpImportEntity> P_ErpImportEntity;