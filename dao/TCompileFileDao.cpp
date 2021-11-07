#include "TCompileFileDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
using namespace std;


P_TCompileFileDao TCompileFileDao::instance = nullptr;


TCompileFileDao::TCompileFileDao() {
}

TCompileFileDao::~TCompileFileDao() {
}

P_TCompileFileDao TCompileFileDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TCompileFileDao(new TCompileFileDao);
	}
	return instance;
};


void TCompileFileDao::insertList( vector<unordered_map<string,string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_compile_file(path,file_name,status) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size();i1++) {
			sql_os << "(";
			sql_os <<"'"<< list[i1]["path"]<<"'" << ",";
			sql_os << "'" << list[i1]["fileName"] << "'" << ",";
			sql_os << list[i1]["status"];
			sql_os << ")";
			if (i1!=(list.size()-1)) {
				sql_os << ",";
			}
		}
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}


void TCompileFileDao::queryList(const unordered_map<string,string> &transfer_map,vector<unordered_map<string,string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;

		string col[] = { "id","path","file_name","status" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 4; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  id,path,file_name,status from t_compile_file ";
		sql_os << "where 1=1 ";


		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["id"] = mysql_row[col_map["id"]];
				result_list.back()["path"] = mysql_row[col_map["path"]];
				result_list.back()["file_name"] = mysql_row[col_map["file_name"]];
				result_list.back()["status"] = mysql_row[col_map["status"]];
			}
		}
		mysql_close(&conn);
	}
}




