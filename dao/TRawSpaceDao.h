#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawSpaceDao :virtual public BaseDao {

public: TRawSpaceDao();

public: virtual ~TRawSpaceDao();

private: static shared_ptr<TRawSpaceDao> instance;

public: static shared_ptr<TRawSpaceDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawSpaceDao> P_TRawSpaceDao;
