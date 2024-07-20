#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawImportDao :virtual public BaseDao {

public: TRawImportDao();

public: virtual ~TRawImportDao();

private: static shared_ptr<TRawImportDao> instance;

public: static shared_ptr<TRawImportDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawImportDao> P_TRawImportDao;
