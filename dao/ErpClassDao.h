#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
#include "../Entity/ErpClassEntity.h"
using namespace std;



class ErpClassDao :virtual public BaseDao {

public: ErpClassDao();

public: virtual ~ErpClassDao();

private: static shared_ptr<ErpClassDao> instance;

public: static shared_ptr<ErpClassDao> getInstance();

public: void insertList(vector<P_ErpClassEntity> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<P_ErpClassEntity> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<ErpClassDao> P_ErpClassDao;





		