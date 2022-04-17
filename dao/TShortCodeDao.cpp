#include "TShortCodeDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_TShortCodeDao TShortCodeDao::instance = nullptr;


TShortCodeDao::TShortCodeDao() {
}

TShortCodeDao::~TShortCodeDao() {
}

P_TShortCodeDao TShortCodeDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TShortCodeDao(new TShortCodeDao);
	}
	return instance;
};



void TShortCodeDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_short_code(md5,symbol,short_code) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["md5"] << "'" << ",";
			sql_os << "'" << list[i1]["symbol"] << "'" << ",";
			sql_os << list[i1]["shortCode"] ;
			sql_os << ")";
			if (i1 != (list.size() - 1)) {
				sql_os << ",";
			}
		}
		//cout << sql_os.str() << endl;
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}



void TShortCodeDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "md5","symbol","short_code" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 3; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  md5,item_id,rule_id,status,end_for_symbol from t_short_code ";
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
				result_list.back()["symbol"] = mysql_row[col_map["symbol"]];
				result_list.back()["shortCode"] = mysql_row[col_map["short_code"]];
			}
		}
		mysql_close(&conn);
	}
}


void TShortCodeDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("md5") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from t_short_code ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

