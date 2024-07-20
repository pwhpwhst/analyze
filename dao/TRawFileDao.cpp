
#include "TRawFileDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
#include "../Util/Util.h"
using namespace std;
P_TRawFileDao TRawFileDao::instance = nullptr;


TRawFileDao::TRawFileDao() {
}

TRawFileDao::~TRawFileDao() {
}

P_TRawFileDao TRawFileDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TRawFileDao(new TRawFileDao);
	}
	return instance;
};



void TRawFileDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into raw_file(appName,fileId,fileName,md5) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["appName"] << "'"<< ",";
			sql_os << list[i1]["fileId"]  << ",";
			sql_os << "'" << list[i1]["fileName"] << "'"<<",";
			sql_os << "'" << list[i1]["md5"] << "'";
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



void TRawFileDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn); 

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "appName","fileId","fileName","md5" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 4; i1++) {
			col_map[col[i1]] = i1;
		}
		sql_os << "select  appName,fileId,fileName,md5 from raw_file ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("appName") != transfer_map.end()) {
			sql_os << "and appName =" << "'" << transfer_map["appName"] << "'" << " ";
		}
		if (transfer_map.find("fileName") != transfer_map.end()) {
			sql_os << "and fileName =" << "'" << transfer_map["fileName"] << "'" << " ";
		}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["appName"] = mysql_row[col_map["appName"]];
				result_list.back()["fileId"] = mysql_row[col_map["fileId"]];
				result_list.back()["fileName"] = mysql_row[col_map["fileName"]];
				result_list.back()["md5"] = mysql_row[col_map["md5"]];
			}
		}
		mysql_close(&conn);
	}
}


void TRawFileDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	//if (transfer_map.count("md5") == 0) {
	//	return;
	//}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from raw_file ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("appName") != transfer_map.end()) {
			sql_os << "and appName =" << "'" << transfer_map["appName"] << "'" << " ";
		}
		if (transfer_map.find("fileId") != transfer_map.end()) {
			sql_os << "and fileId ="<< transfer_map["fileId"]  << " ";
		}
		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

