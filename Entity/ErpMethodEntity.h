#pragma once
#include <memory>
#include <string>
using namespace std;



class ErpMethodEntity {

public:  string  id;
public:  string  classId;
public:  string  typeId;
public:  string  name;
public:  string  comment;
public:  string  project;
public:  long bodyBeg;
public:  long bodyEnd;
public:  long bodyBegLine;
public:  long bodyEndLine;


public: ErpMethodEntity();
public: virtual ~ErpMethodEntity();

};

typedef std::shared_ptr<ErpMethodEntity> P_ErpMethodEntity;