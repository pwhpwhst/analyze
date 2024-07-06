#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawClassDao :virtual public BaseDao {

public: TRawClassDao();

public: virtual ~TRawClassDao();

private: static shared_ptr<TRawClassDao> instance;

public: static shared_ptr<TRawClassDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawClassDao> P_TRawClassDao;
