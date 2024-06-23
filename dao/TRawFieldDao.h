#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRawFieldDao :virtual public BaseDao {

public: TRawFieldDao();

public: virtual ~TRawFieldDao();

private: static shared_ptr<TRawFieldDao> instance;

public: static shared_ptr<TRawFieldDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRawFieldDao> P_TRawFieldDao;
