#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawMethodDao :virtual public BaseDao {

public: TRawMethodDao();

public: virtual ~TRawMethodDao();

private: static shared_ptr<TRawMethodDao> instance;

public: static shared_ptr<TRawMethodDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawMethodDao> P_TRawMethodDao;
