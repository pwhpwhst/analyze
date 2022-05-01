#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TRuleDao :virtual public BaseDao {

public: TRuleDao();

public: virtual ~TRuleDao();

private: static shared_ptr<TRuleDao> instance;

public: static shared_ptr<TRuleDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TRuleDao> P_TRuleDao;





		