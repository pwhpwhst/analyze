#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TForecast2Dao :virtual public BaseDao {

public: TForecast2Dao();

public: virtual ~TForecast2Dao();

private: static shared_ptr<TForecast2Dao> instance;

public: static shared_ptr<TForecast2Dao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void queryByS(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void queryByR(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void queryByDescOfS(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TForecast2Dao> P_TForecast2Dao;





		