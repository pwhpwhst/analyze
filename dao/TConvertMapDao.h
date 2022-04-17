#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TConvertMapDao :virtual public BaseDao {

public: TConvertMapDao();

public: virtual ~TConvertMapDao();

private: static shared_ptr<TConvertMapDao> instance;

public: static shared_ptr<TConvertMapDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TConvertMapDao> P_TConvertMapDao;