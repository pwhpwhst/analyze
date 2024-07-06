#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawSuperClassParmaDao :virtual public BaseDao {

public: TRawSuperClassParmaDao();

public: virtual ~TRawSuperClassParmaDao();

private: static shared_ptr<TRawSuperClassParmaDao> instance;

public: static shared_ptr<TRawSuperClassParmaDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawSuperClassParmaDao> P_TRawSuperClassParmaDao;
