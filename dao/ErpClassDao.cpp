#include "ErpClassDao.h"
#include "../Entity/ErpClassEntity.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_ErpClassDao ErpClassDao::instance = nullptr;


ErpClassDao::ErpClassDao() {
}

ErpClassDao::~ErpClassDao() {
}

P_ErpClassDao ErpClassDao::getInstance() {
	if (instance == nullptr) {
		instance = P_ErpClassDao(new ErpClassDao);
	}
	return instance;
};



void ErpClassDao::insertList(vector<P_ErpClassEntity> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		sql_os << "insert into erp_class(id,fileId, name, package, project, comment) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]->id << "'" << ",";
			sql_os << "'" << list[i1]->fileId << "'" << ",";
			sql_os << "'" << list[i1]->name << "'" << ",";
			sql_os << "'" << list[i1]->package << "'" << ",";
			sql_os << "'" << list[i1]->project << "'" << ",";
			sql_os << "'" << list[i1]->comment << "'";
			sql_os << ")";
			if (i1 != (list.size() - 1)) {
				sql_os << ",";
			}
		}
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}




void ErpClassDao::queryList(unordered_map<string, string> &transfer_map, vector<P_ErpClassEntity> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "id","fileId","name","package","project","comment" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 5; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  id,fileId, name, package, project, comment from erp_class ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(P_ErpClassEntity());
				result_list.back()->id = mysql_row[col_map["id"]];
				result_list.back()->fileId = atol(mysql_row[col_map["fileId"]]);
				result_list.back()->name = mysql_row[col_map["name"]];
				result_list.back()->package = mysql_row[col_map["package"]];
				result_list.back()->project = mysql_row[col_map["project"]];
				result_list.back()->comment = mysql_row[col_map["comment"]];
			}
		}
		mysql_close(&conn);
	}
}





void ErpClassDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("project") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from erp_class ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("project") != transfer_map.end()) {
			sql_os << "and project =" << "'" << transfer_map["project"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

