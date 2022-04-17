#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TItemDao :virtual public BaseDao {

public: TItemDao();

public: virtual ~TItemDao();

private: static shared_ptr<TItemDao> instance;

public: static shared_ptr<TItemDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TItemDao> P_TItemDao;





		