#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TFileMD5Dao :virtual public BaseDao {

public: TFileMD5Dao();

public: virtual ~TFileMD5Dao();

private: static shared_ptr<TFileMD5Dao> instance;

public: static shared_ptr<TFileMD5Dao> getInstance();

public: void queryList( unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void insertList(vector<unordered_map<string, string>> &list);

public: void update(unordered_map<string, string> &transfer_map);
};

typedef std::shared_ptr<TFileMD5Dao> P_TFileMD5Dao;





		