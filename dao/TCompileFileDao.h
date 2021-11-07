#pragma once
#include "BaseDao.h"
#include <vector>
#include <unordered_map>
using namespace std;



class TCompileFileDao :virtual public BaseDao {

public: TCompileFileDao();

public: virtual ~TCompileFileDao();

private: static shared_ptr<TCompileFileDao> instance;

public: void insertList( vector<unordered_map<string, string>> &list);

public: static shared_ptr<TCompileFileDao> getInstance();

public: void queryList(const unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);
};

typedef std::shared_ptr<TCompileFileDao> P_TCompileFileDao;





		