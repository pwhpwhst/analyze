#include "ErpMethodDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_ErpMethodDao ErpMethodDao::instance = nullptr;


ErpMethodDao::ErpMethodDao() {
}

ErpMethodDao::~ErpMethodDao() {
}

P_ErpMethodDao ErpMethodDao::getInstance() {
	if (instance == nullptr) {
		instance = P_ErpMethodDao(new ErpMethodDao);
	}
	return instance;
};



void ErpMethodDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		sql_os << "insert into erp_method(id,classId, typeId, name, comment, project,bodyBeg,bodyEnd,bodyBegLine,bodyEndLine) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["id"] << "'" << ",";
			sql_os << "'" << list[i1]["classId"] << "'" << ",";
			sql_os << "'" << list[i1]["typeId"] << "'" << ",";
			sql_os << "'" << list[i1]["name"] << "'" << ",";
			sql_os << "'" << list[i1]["comment"] << "'" << ",";
			sql_os << "'" << list[i1]["project"] << "'" << ",";
			sql_os << list[i1]["bodyBeg"] << ",";
			sql_os << list[i1]["bodyEnd"] << ",";
			sql_os << list[i1]["bodyBegLine"] << ",";
			sql_os << list[i1]["bodyEndLine"];
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




void ErpMethodDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "id","classId","typeId","name","comment","project","bodyBeg","bodyEnd","bodyBegLine","bodyEndLine" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 5; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  id,classId, typeId, name, comment, project,bodyBeg,bodyEnd,bodyBegLine,bodyEndLine from erp_method ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(unordered_map<string, string>());
				result_list.back()["id"] = mysql_row[col_map["id"]];
				result_list.back()["classId"] = mysql_row[col_map["classId"]];
				result_list.back()["typeId"] = mysql_row[col_map["typeId"]];
				result_list.back()["name"] = mysql_row[col_map["name"]];
				result_list.back()["comment"] = mysql_row[col_map["comment"]];
				result_list.back()["project"] = mysql_row[col_map["project"]];
				result_list.back()["bodyBeg"] = mysql_row[col_map["bodyBeg"]];
				result_list.back()["bodyEnd"] = mysql_row[col_map["bodyEnd"]];
				result_list.back()["bodyBegLine"] = mysql_row[col_map["bodyBegLine"]];
				result_list.back()["bodyEndLine"] = mysql_row[col_map["bodyEndLine"]];
			}
		}
		mysql_close(&conn);
	}
}





void ErpMethodDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("project") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from erp_method ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("project") != transfer_map.end()) {
			sql_os << "and project =" << "'" << transfer_map["project"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

