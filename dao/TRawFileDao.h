#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawFileDao :virtual public BaseDao {

public: TRawFileDao();

public: virtual ~TRawFileDao();

private: static shared_ptr<TRawFileDao> instance;

public: static shared_ptr<TRawFileDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawFileDao> P_TRawFileDao;
