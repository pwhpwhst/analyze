#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TMoveTableDao :virtual public BaseDao {

public: TMoveTableDao();

public: virtual ~TMoveTableDao();

private: static shared_ptr<TMoveTableDao> instance;

public: static shared_ptr<TMoveTableDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TMoveTableDao> P_TMoveTableDao;





		