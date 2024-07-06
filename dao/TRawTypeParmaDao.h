#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawTypeParmaDao :virtual public BaseDao {

public: TRawTypeParmaDao();

public: virtual ~TRawTypeParmaDao();

private: static shared_ptr<TRawTypeParmaDao> instance;

public: static shared_ptr<TRawTypeParmaDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawTypeParmaDao> P_TRawTypeParmaDao;
