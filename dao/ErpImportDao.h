#pragma once
#include "BaseDao.h"
#include "../Entity/ErpImportEntity.h"
#include <vector>
#include <unordered_map>
using namespace std;



class ErpImportDao :virtual public BaseDao {

public: ErpImportDao();

public: virtual ~ErpImportDao();

private: static shared_ptr<ErpImportDao> instance;

public: static shared_ptr<ErpImportDao> getInstance();

public: void insertList(vector<P_ErpImportEntity> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<P_ErpImportEntity> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<ErpImportDao> P_ErpImportDao;





		