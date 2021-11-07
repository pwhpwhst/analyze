#pragma once
#include <memory>
#include <string>
using namespace std;



class BaseDao {

protected: string host;
protected: string user;
protected: string password;
protected: string db;
protected: int port;

public: BaseDao();
public: virtual ~BaseDao();

};

