#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawPackageDao :virtual public BaseDao {

public: TRawPackageDao();

public: virtual ~TRawPackageDao();

private: static shared_ptr<TRawPackageDao> instance;

public: static shared_ptr<TRawPackageDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawPackageDao> P_TRawPackageDao;
