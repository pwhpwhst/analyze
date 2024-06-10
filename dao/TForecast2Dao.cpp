#include "TForecast2Dao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_TForecast2Dao TForecast2Dao::instance = nullptr;


TForecast2Dao::TForecast2Dao() {
}

TForecast2Dao::~TForecast2Dao() {
}

P_TForecast2Dao TForecast2Dao::getInstance() {
	if (instance == nullptr) {
		instance = P_TForecast2Dao(new TForecast2Dao);
	}
	return instance;
};



void TForecast2Dao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into t_forecast2(md5,interal_id,short_code,action) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["md5"] << "'" << ",";
			sql_os << list[i1]["interalId"]  << ",";
			sql_os << list[i1]["shortCode"] << ",";
			sql_os << "'" << list[i1]["action"] << "'";
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


void TForecast2Dao::queryByS(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "interalId" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 1; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select distinct t_move_table.interal_id interalId from t_item, t_rule, t_convert_map, t_move_table  where 1 = 1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and t_item.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_rule.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_convert_map.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_move_table.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		sql_os << "and t_item.rule_id = t_rule.id ";
		sql_os << "and t_item.status != 0 ";
		sql_os << "and t_move_table.item_id = t_convert_map.src_item ";
		sql_os << "and t_item.item_id = t_convert_map.desc_item ";
		if (transfer_map.find("ruleName") != transfer_map.end()) {
			sql_os << "and t_rule.rule_name =" << "'" << transfer_map["ruleName"] << "'" << " ";
		}

		if (transfer_map.find("rule") != transfer_map.end()) {
			sql_os << "and t_rule.rule =" << "'" << transfer_map["rule"] << "'" << " ";
		}
		if (transfer_map.find("status") != transfer_map.end()) {
			sql_os << "and status =" << transfer_map["status"] << " ";
		}
		if (transfer_map.find("move") != transfer_map.end()) {
			sql_os << "and t_convert_map.move = " << "'" << transfer_map["move"] << "'" << " ";
			sql_os << "and substring_index(substring_index(rule, ' ', status), ' ',-1) =" << "'" << transfer_map["move"] << "'" << " ";
		}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["interalId"] = mysql_row[col_map["interalId"]];
			}
		}
		mysql_close(&conn);

	}
}


void TForecast2Dao::queryByR(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "interalId" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 1; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select t_move_table.interal_id interalId from t_item, t_rule, t_move_table where 1=1 ";


		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and t_item.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_rule.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_move_table.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}


		sql_os << "and t_item.rule_id = t_rule.id ";
		sql_os << "and t_move_table.item_id = t_item.item_id ";
		if (transfer_map.find("ruleName") != transfer_map.end()) {
			sql_os << "and t_rule.rule_name =" << "'" << transfer_map["ruleName"] << "'" << " ";
		}
		if (transfer_map.find("rule") != transfer_map.end()) {
			sql_os << "and trim(t_rule.rule) =" << "'" << transfer_map["rule"] << "'" << " ";
		}

		if (transfer_map.find("status") != transfer_map.end()) {
			sql_os << "and status =" << transfer_map["status"] << " ";
		}
		sql_os << "and length(trim(t_rule.rule)) - length(replace(trim(t_rule.rule), ' ', '')) +1 = t_item.status ";
		
		if (transfer_map.find("move") != transfer_map.end()) {
			sql_os << "and t_item.end_for_symbol like "<<"'%" << transfer_map["move"] <<"%'";
		}
		
		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["interalId"] = mysql_row[col_map["interalId"]];
			}
		}
		mysql_close(&conn);

	}
}

void TForecast2Dao::queryByDescOfS(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "descItem" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 1; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select t_convert_map.desc_item descItem from t_convert_map, t_move_table, t_move_table mt2 ";
		sql_os << "where 1 = 1 ";

		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and t_convert_map.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and t_move_table.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
			sql_os << "and mt2.md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}
		sql_os << "and t_move_table.item_id = t_convert_map.src_item ";
		sql_os << "and mt2.item_id = t_convert_map.desc_item ";
		if (transfer_map.find("interalId") != transfer_map.end()) {
			sql_os << "and t_move_table.interal_id =" <<"'"<< transfer_map["interalId"] << "'" << " ";
		}
		if (transfer_map.find("move") != transfer_map.end()) {
			sql_os << "and move = '" << transfer_map["move"] << "' ";
		}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["descItem"] = mysql_row[col_map["descItem"]];
			}
		}
		mysql_close(&conn);

	}
}






void TForecast2Dao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "md5","interal_id","short_code","action" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 4; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  md5,interal_id,short_code,action from t_forecast2 ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}
		sql_os << "order by interal_id" << " ";

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["md5"] = mysql_row[col_map["md5"]];
				result_list.back()["interalId"] = mysql_row[col_map["interal_id"]];
				result_list.back()["shortCode"] = mysql_row[col_map["short_code"]];
				result_list.back()["action"] = mysql_row[col_map["action"]];
			}
		}
		mysql_close(&conn);
	}
}


void TForecast2Dao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("md5") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from t_forecast2 ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("md5") != transfer_map.end()) {
			sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

