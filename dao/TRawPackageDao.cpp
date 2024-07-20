
#include "TRawPackageDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;
P_TRawPackageDao TRawPackageDao::instance = nullptr;


TRawPackageDao::TRawPackageDao() {
}

TRawPackageDao::~TRawPackageDao() {
}

P_TRawPackageDao TRawPackageDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TRawPackageDao(new TRawPackageDao);
	}
	return instance;
};



void TRawPackageDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into raw_package(appName,fileId,content) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["appName"] << "'"<< ",";
			sql_os << list[i1]["fileId"]  << ",";
			sql_os << "'" << list[i1]["content"] << "'";
			sql_os << ")";
			if (i1 != (list.size() - 1)) {
				sql_os << ",";
			}
		}
		//Util::log(sql_os.str()); 
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}



void TRawPackageDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "appName","fileId","content" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 3; i1++) {
			col_map[col[i1]] = i1;
		}
		sql_os << "select  appName,fileId,content from raw_package ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}
		//sql_os << "order by interal_id" << " ";

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["appName"] = mysql_row[col_map["appName"]];
				result_list.back()["fileId"] = mysql_row[col_map["fileId"]];
				result_list.back()["content"] = mysql_row[col_map["content"]];
			}
		}
		mysql_close(&conn);
	}
}


void TRawPackageDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	//if (transfer_map.count("md5") == 0) {
	//	return;
	//}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from raw_package ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}
		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

