#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class ErpMethodDao :virtual public BaseDao {

public: ErpMethodDao();

public: virtual ~ErpMethodDao();

private: static shared_ptr<ErpMethodDao> instance;

public: static shared_ptr<ErpMethodDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<ErpMethodDao> P_ErpMethodDao;





		