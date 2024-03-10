#pragma once
#include <deque>
#include <string>

using namespace std;




class Space {

public:  int begLine;
public:  int endLine;
public:  int begIndex;
public:  int endIndex;

public:  long id;
public:  string type;

public: deque<Space*> spaceList;

public: Space();
public: virtual ~Space();
};

