#include "TConvertMapDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
#include <memory>


P_TConvertMapDao TConvertMapDao::instance = nullptr;


TConvertMapDao::TConvertMapDao() {
}

TConvertMapDao::~TConvertMapDao() {
}

P_TConvertMapDao TConvertMapDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TConvertMapDao(new TConvertMapDao);
	}
	return instance;
};



void TConvertMapDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_convert_map(md5,src_item,move,desc_item) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["md5"] << "'" << ",";
			sql_os << list[i1]["srcItem"] << ",";
			sql_os << "'" << list[i1]["move"] << "'" << ",";
			sql_os << list[i1]["descItem"] ;
			sql_os << ")";
			if (i1 != (list.size() - 1)) {
				sql_os << ",";
			}
		}
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}

void TConvertMapDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "md5","src_item","move","desc_item" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 4; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  md5,src_item,move,desc_item from t_convert_map ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["md5"] = mysql_row[col_map["md5"]];
				result_list.back()["srcItem"] = mysql_row[col_map["src_item"]];
				result_list.back()["move"] = mysql_row[col_map["move"]];
				result_list.back()["descItem"] = mysql_row[col_map["desc_item"]];
			}
		}
		mysql_close(&conn);
	}
}


void TConvertMapDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("md5") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from t_convert_map ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}