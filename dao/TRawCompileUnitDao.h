#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawCompileUnitDao :virtual public BaseDao {

public: TRawCompileUnitDao();

public: virtual ~TRawCompileUnitDao();

private: static shared_ptr<TRawCompileUnitDao> instance;

public: static shared_ptr<TRawCompileUnitDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawCompileUnitDao> P_TRawCompileUnitDao;
