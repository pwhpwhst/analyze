#include "TRuleDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_TRuleDao TRuleDao::instance = nullptr;


TRuleDao::TRuleDao() {
}

TRuleDao::~TRuleDao() {
}

P_TRuleDao TRuleDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TRuleDao(new TRuleDao);
	}
	return instance;
};



void TRuleDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_rule(md5,id,rule_name,rule) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["md5"] << "'" << ",";
			sql_os  << list[i1]["id"]  << ",";
			sql_os << "'" << list[i1]["ruleName"] << "'" << ",";
			sql_os << "'" << list[i1]["rule"] << "'";
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



void TRuleDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "md5","id","rule_name","rule" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 4; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  md5,id,rule from t_rule ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		if (transfer_map.find("ruleName") != transfer_map.end()) {
			sql_os << "and rule_name =" << "'" << transfer_map["ruleName"] << "'" << " ";
		}

		if (transfer_map.find("rule") != transfer_map.end()) {
			sql_os << "and rule =" << "'" << transfer_map["rule"] << "'" << " ";
		}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["md5"] = mysql_row[col_map["md5"]];
				result_list.back()["id"] = mysql_row[col_map["id"]];
				result_list.back()["ruleName"] = mysql_row[col_map["rule_name"]];
				result_list.back()["rule"] = mysql_row[col_map["rule"]];
			}
		}
		mysql_close(&conn);
	}
}


void TRuleDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("md5") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from t_rule ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

