#include "ErpImportDao.h"
#include "../Entity/ErpImportEntity.h"
#include "../Util/Util.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


P_ErpImportDao ErpImportDao::instance = nullptr;


ErpImportDao::ErpImportDao() {
}

ErpImportDao::~ErpImportDao() {
}

P_ErpImportDao ErpImportDao::getInstance() {
	if (instance == nullptr) {
		instance = P_ErpImportDao(new ErpImportDao);
	}
	return instance;
};



void ErpImportDao::insertList(vector<P_ErpImportEntity> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		sql_os << "insert into erp_import(id,fileId, name, isStatic,isSingle, project, comment) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]->id << "'" << ",";
			sql_os << "'" << list[i1]->fileId << "'" << ",";
			sql_os << "'" << list[i1]->name << "'" << ",";
			sql_os << list[i1]->isStatic  << ",";
			sql_os << list[i1]->isSingle << ",";
			sql_os << "'" << list[i1]->project << "'" << ",";
			sql_os << "'" << list[i1]->comment << "'";
			sql_os << ")";
			if (i1 != (list.size() - 1)) {
				sql_os << ",";
			}
		}
		Util::log(sql_os.str()); 
		res = mysql_query(&conn, sql_os.str().data());
		mysql_close(&conn);
	}
}




void ErpImportDao::queryList(unordered_map<string, string> &transfer_map, vector<P_ErpImportEntity> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "id","fileId","name","isStatic","isSingle","project","comment" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 5; i1++) {
			col_map[col[i1]] = i1;
		}

		sql_os << "select  id,fileId, name,isStatic,isSingle, project, comment from erp_import ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}

		if (mysql_query(&conn, sql_os.str().data()) == 0) {
			MYSQL_RES *mysql_result = mysql_store_result(&conn);
			long num_row = mysql_num_rows(mysql_result);
			for (size_t i1 = 0; i1 < num_row; i1++) {
				mysql_row = mysql_fetch_row(mysql_result);
				result_list.push_back(P_ErpImportEntity());
				result_list.back()->id = mysql_row[col_map["id"]];
				result_list.back()->fileId = atol(mysql_row[col_map["fileId"]]);
				result_list.back()->name = mysql_row[col_map["name"]];
				result_list.back()->isStatic = atol(mysql_row[col_map["isStatic"]]);
				result_list.back()->isSingle = atol(mysql_row[col_map["isSingle"]]);
				result_list.back()->project = mysql_row[col_map["project"]];
				result_list.back()->comment = mysql_row[col_map["comment"]];
			}
		}
		mysql_close(&conn);
	}
}





void ErpImportDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (transfer_map.count("project") == 0) {
		return;
	}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from erp_import ";
		sql_os << "where 1=1 ";
		if (transfer_map.find("project") != transfer_map.end()) {
			sql_os << "and project =" << "'" << transfer_map["project"] << "'" << " ";
		}

		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

