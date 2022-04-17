#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TForecastDao :virtual public BaseDao {

public: TForecastDao();

public: virtual ~TForecastDao();

private: static shared_ptr<TForecastDao> instance;

public: static shared_ptr<TForecastDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TForecastDao> P_TForecastDao;





		