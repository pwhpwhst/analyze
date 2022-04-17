#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TShortCodeDao :virtual public BaseDao {

public: TShortCodeDao();

public: virtual ~TShortCodeDao();

private: static shared_ptr<TShortCodeDao> instance;

public: static shared_ptr<TShortCodeDao> getInstance();

public: void insertList(vector<unordered_map<string, string>> &list);

public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);

public: void deleteRecord(unordered_map<string, string> &transfer_map);

};

typedef std::shared_ptr<TShortCodeDao> P_TShortCodeDao;





		