#include "TRawSpaceDao.h"
#pragma comment(lib,"libmysql.lib")
#include <mysql.h>
#include <sstream>
#include <iostream>
using namespace std;
P_TRawSpaceDao TRawSpaceDao::instance = nullptr;


TRawSpaceDao::TRawSpaceDao() {
}

TRawSpaceDao::~TRawSpaceDao() {
}

P_TRawSpaceDao TRawSpaceDao::getInstance() {
	if (instance == nullptr) {
		instance = P_TRawSpaceDao(new TRawSpaceDao);
	}
	return instance;
};



void TRawSpaceDao::insertList(vector<unordered_map<string, string>> &list) {
	if (list.size() == 0) {
		return;
	}
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {
		ostringstream sql_os;
		sql_os << "insert into raw_space(appName,fileName,fileId,subId,parentId,type,begLine,endLine,begIndex,endIndex) ";
		sql_os << "values";
		for (int i1 = 0; i1 < list.size(); i1++) {
			sql_os << "(";
			sql_os << "'" << list[i1]["appName"] << "'"<< ",";
			sql_os << "'" << list[i1]["fileName"] << "'"<< ",";
			sql_os << list[i1]["fileId"]  << ",";
			sql_os << list[i1]["subId"]  << ",";
			sql_os << list[i1]["parentId"]  << ",";
			sql_os << "'" << list[i1]["type"] << "'"<< ",";
			sql_os << list[i1]["begLine"]  << ",";
			sql_os << list[i1]["endLine"]  << ",";
			sql_os << list[i1]["begIndex"]  << ",";
			sql_os << list[i1]["endIndex"]  << ",";
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



void TRawSpaceDao::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {

	result_list.clear();
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;
		string col[] = { "appName","fileName","fileId","subId","parentId","type","begLine","endLine","begIndex","endIndex" };

		unordered_map<string, int> col_map;
		for (int i1 = 0; i1 < 10; i1++) {
			col_map[col[i1]] = i1;
		}
		sql_os << "select  appName,fileName,fileId,subId,parentId,type,begLine,endLine,begIndex,endIndex from raw_space ";
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
				result_list.back()["fileName"] = mysql_row[col_map["fileName"]];
				result_list.back()["fileId"] = mysql_row[col_map["fileId"]];
				result_list.back()["subId"] = mysql_row[col_map["subId"]];
				result_list.back()["parentId"] = mysql_row[col_map["parentId"]];
				result_list.back()["type"] = mysql_row[col_map["type"]];
				result_list.back()["begLine"] = mysql_row[col_map["begLine"]];
				result_list.back()["endLine"] = mysql_row[col_map["endLine"]];
				result_list.back()["begIndex"] = mysql_row[col_map["begIndex"]];
				result_list.back()["endIndex"] = mysql_row[col_map["endIndex"]];
			}
		}
		mysql_close(&conn);
	}
}


void TRawSpaceDao::deleteRecord(unordered_map<string, string> &transfer_map) {
	MYSQL conn;
	MYSQL_ROW mysql_row;
	mysql_init(&conn);

	//if (transfer_map.count("md5") == 0) {
	//	return;
	//}

	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {

		ostringstream sql_os;


		sql_os << "delete from raw_space ";
		sql_os << "where 1=1 ";
		//if (transfer_map.find("md5") != transfer_map.end()) {
		//	sql_os << "and md5 =" << "'" << transfer_map["md5"] << "'" << " ";
		//}
		mysql_query(&conn, sql_os.str().data());

		mysql_close(&conn);
	}

}

