#pragma once
#include <memory>
#include <string>
using namespace std;



class ErpClassEntity {

public:  string  id;
public:  long  fileId;
public:  string  name;
public:  string  package;
public:  string  project;
public:  string  comment;


public: ErpClassEntity();
public: virtual ~ErpClassEntity();

};

typedef std::shared_ptr<ErpClassEntity> P_ErpClassEntity;