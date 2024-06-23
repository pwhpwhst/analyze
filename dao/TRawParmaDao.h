#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawParmaDao :virtual public BaseDao {

public: TRawParmaDao();

public: virtual ~TRawParmaDao();

private: static shared_ptr<TRawParmaDao> instance;

public: static shared_ptr<TRawParmaDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawParmaDao> P_TRawParmaDao;
