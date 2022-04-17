#include "TFileMD5Dao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_TFileMD5Dao TFileMD5Dao::instance = nullptr;


TFileMD5Dao::TFileMD5Dao() {
}

TFileMD5Dao::~TFileMD5Dao() {
}

P_TFileMD5Dao TFileMD5Dao::getInstance() {
	if (instance == nullptr) {
		instance = P_TFileMD5Dao(new TFileMD5Dao);
	}
	return instance;
};


void TFileMD5Dao::insertList( vector<unordered_map<string,string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_file_md5(file_name,md5) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size();i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["fileName"] << "'" << ",";
			sql_os << "'" << list[i1]["md5"] << "'";
			sql_os << ")";
			if (i1!=(list.size()-1)) {
				sql_os << ",";
			}
		}
		mysql_query(&conn, "set names gbk");
		//mysql_query(&conn, "set names utf8");
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}


void TFileMD5Dao::queryList( unordered_map<string,string> &transfer_map,vector<unordered_map<string,string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "file_name","md5" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 2; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select file_name,md5 from t_file_md5 ";
		sql_os << "where 1=1 ";
		
		if (transfer_map.find("fileName") != transfer_map.end()) {
			sql_os << "and file_name='" << transfer_map["fileName"]<<"' ";
		}
		
		mysql_query(&conn, "set names gbk");
		//mysql_query(&conn, "set names utf8");
		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["fileName"] = mysql_row[col_map["file_name"]];
				result_list.back()["md5"] = mysql_row[col_map["md5"]];
			}
		}
		mysql_close(&conn);
	}
}



void TFileMD5Dao::update(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	int res;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "update t_file_md5(file_name,md5) ";
		sql_os << "set md5='"<< transfer_map["md5"]<<"' ";
		sql_os << "where file_name='"<< transfer_map["fileName"]<<"'";
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}

}



