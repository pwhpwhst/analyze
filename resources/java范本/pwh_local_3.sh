
#TRawCompileUnitDao
#TRawFieldDao
#TRawMethodDao
#TRawParmaDao


function daoFileFen_h(){
local className="TRawParmaDao"

local targetFile=/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/dao/${className}.h
rm -rf ${targetFile}

echo "#pragma once" >>${targetFile}
echo "#include \"BaseDao.h\"" >>${targetFile}
echo "#include <vector>" >>${targetFile}
echo "#include <unordered_map>" >>${targetFile}
echo "using namespace std;" >>${targetFile}
echo"" >>${targetFile}
echo"" >>${targetFile}
echo"" >>${targetFile}
echo "class ${className} :virtual public BaseDao {" >>${targetFile}
echo"" >>${targetFile}
echo "public: ${className}();" >>${targetFile}
echo"" >>${targetFile}
echo "public: virtual ~${className}();" >>${targetFile}
echo"" >>${targetFile}
echo "private: static shared_ptr<${className}> instance;" >>${targetFile}
echo"" >>${targetFile}
echo "public: static shared_ptr<${className}> getInstance();" >>${targetFile}
echo"" >>${targetFile}
echo "public: void insertList(vector<unordered_map<string, string>> &list);" >>${targetFile}
echo"" >>${targetFile}
echo "public: void queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list);" >>${targetFile}
echo"" >>${targetFile}
echo "public: void deleteRecord(unordered_map<string, string> &transfer_map);" >>${targetFile}
echo"" >>${targetFile}
echo "};" >>${targetFile}
echo"" >>${targetFile}
echo "typedef std::shared_ptr<${className}> P_${className};" >>${targetFile}

}

#daoFileFen_h



#TRawCompileUnitDao
#TRawFieldDao
#TRawMethodDao
#TRawParmaDao





function daoFileFen_cpp(){

local className="TRawCompileUnitDao"
local tableName="raw_compile_unit"




fields=(
appName#string
fileId#int
fileName#string
subId#int
parentId#int
structType#string
begLine#int
endLine#int
begIndex#int
endIndex#int
)



local latestField="name#string"

local targetFile=/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/dao/${className}.cpp



rm -rf ${targetFile}

local str1=""
local colNum="0";
for var in ${fields[@]}
do
local field=`echo ${var}|cut -d "#" -f1`

if [[ "${str1}" == "" ]];then
str1="${field}"
else
str1="${str1},${field}"
fi
colNum=`expr ${colNum} + 1`
done

local str2=""


for var in ${fields[@]}
do
local field=`echo ${var}|cut -d "#" -f1`

if [[ "${str2}" == "" ]];then
str2="\"${field}\""
else
str2="${str2},\"${field}\""
fi
done



echo "" >>${targetFile}
echo "include \"${className}.h\"" >>${targetFile}
echo "#pragma comment(lib,\"libmysql.lib\")" >>${targetFile}
echo "#include <mysql.h>" >>${targetFile}
echo "#include <sstream>" >>${targetFile}
echo "#include <iostream>" >>${targetFile}
echo "using namespace std;" >>${targetFile}
echo ""
echo ""
echo "P_${className} ${className}::instance = nullptr;" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "${className}::${className}() {" >>${targetFile}
echo "}" >>${targetFile}
echo "" >>${targetFile}
echo "${className}::~${className}() {" >>${targetFile}
echo "}" >>${targetFile}
echo "" >>${targetFile}
echo "P_${className} ${className}::getInstance() {" >>${targetFile}
echo "	if (instance == nullptr) {" >>${targetFile}
echo "		instance = P_${className}(new ${className});" >>${targetFile}
echo "	}" >>${targetFile}
echo "	return instance;" >>${targetFile}
echo "};" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "void ${className}::insertList(vector<unordered_map<string, string>> &list) {" >>${targetFile}
echo "	if (list.size() == 0) {" >>${targetFile}
echo "		return;" >>${targetFile}
echo "	}" >>${targetFile}
echo "	MYSQL conn;" >>${targetFile}
echo "	int res;" >>${targetFile}
echo "	mysql_init(&conn);" >>${targetFile}
echo "	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {" >>${targetFile}
echo "		ostringstream sql_os;" >>${targetFile}
echo "		sql_os << \"insert into ${tableName}(${str1}) \";" >>${targetFile}
echo "		sql_os << \"values\";" >>${targetFile}
echo "		for (int i1 = 0; i1 < list.size(); i1++) {" >>${targetFile}
echo "			sql_os << \"(\";" >>${targetFile}
for var in ${fields[@]}
do
local fieldName=`echo ${var}|cut -d "#" -f1`
local fieldType=`echo ${var}|cut -d "#" -f2`
if [[ "${fieldType}" == "int" && "${var}" != "${latestField}" ]];then
echo "			sql_os << list[i1][\"${fieldName}\"]  << \",\";" >>${targetFile}
elif [[ "${fieldType}" == "string" && "${var}" != "${latestField}"  ]];then
echo "			sql_os << \"'\" << list[i1][\"${fieldName}\"] << \"'\"<< \",\";" >>${targetFile}
elif [[ "${fieldType}" == "int" && "${var}" == "${latestField}" ]];then
echo "			sql_os << list[i1][\"${fieldName}\"];" >>${targetFile}
elif [[ "${fieldType}" == "string" && "${var}" == "${latestField}"  ]];then
echo "			sql_os << \"'\" << list[i1][\"${fieldName}\"] << \"'\";" >>${targetFile}
fi
done
echo "			sql_os << \")\";" >>${targetFile}
echo "			if (i1 != (list.size() - 1)) {" >>${targetFile}
echo "				sql_os << \",\";" >>${targetFile}
echo "			}" >>${targetFile}
echo "		}" >>${targetFile}
echo "		//Util::log(sql_os.str()); " >>${targetFile}
echo "		res = mysql_query(&conn, sql_os.str().data());" >>${targetFile}
echo "		mysql_close(&conn);" >>${targetFile}
echo "	}" >>${targetFile}
echo "}" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "void ${className}::queryList(unordered_map<string, string> &transfer_map, vector<unordered_map<string, string>> &result_list) {" >>${targetFile}
echo "" >>${targetFile}
echo "	result_list.clear();" >>${targetFile}
echo "	MYSQL conn;" >>${targetFile}
echo "	MYSQL_ROW mysql_row;" >>${targetFile}
echo "	mysql_init(&conn);" >>${targetFile}
echo "" >>${targetFile}
echo "	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {" >>${targetFile}
echo "" >>${targetFile}
echo "		ostringstream sql_os;" >>${targetFile}
echo "		string col[] = { ${str2} };" >>${targetFile}
echo "" >>${targetFile}
echo "		unordered_map<string, int> col_map;" >>${targetFile}
echo "		for (int i1 = 0; i1 < ${colNum}; i1++) {" >>${targetFile}
echo "			col_map[col[i1]] = i1;" >>${targetFile}
echo "		}" >>${targetFile}
echo "		sql_os << \"select  ${str1} from ${tableName} \";" >>${targetFile}
echo "		sql_os << \"where 1=1 \";" >>${targetFile}
echo "		//if (transfer_map.find(\"md5\") != transfer_map.end()) {" >>${targetFile}
echo "		//	sql_os << \"and md5 =\" << \"'\" << transfer_map[\"md5\"] << \"'\" << \" \";" >>${targetFile}
echo "		//}" >>${targetFile}
echo "		//sql_os << \"order by interal_id\" << \" \";" >>${targetFile}
echo "" >>${targetFile}
echo "		if (mysql_query(&conn, sql_os.str().data()) == 0) {" >>${targetFile}
echo "			MYSQL_RES *mysql_result = mysql_store_result(&conn);" >>${targetFile}
echo "			long num_row = mysql_num_rows(mysql_result);" >>${targetFile}
echo "			for (size_t i1 = 0; i1 < num_row; i1++) {" >>${targetFile}
echo "				mysql_row = mysql_fetch_row(mysql_result);" >>${targetFile}
echo "				result_list.push_back(unordered_map<string, string>());" >>${targetFile}
for var in ${fields[@]}
do
local fieldName=`echo ${var}|cut -d "#" -f1`
echo "				result_list.back()[\"${fieldName}\"] = mysql_row[col_map[\"${fieldName}\"]];" >>${targetFile}
done
echo "			}" >>${targetFile}
echo "		}" >>${targetFile}
echo "		mysql_close(&conn);" >>${targetFile}
echo "	}" >>${targetFile}
echo "}" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "void ${className}::deleteRecord(unordered_map<string, string> &transfer_map) {" >>${targetFile}
echo "	MYSQL conn;" >>${targetFile}
echo "	MYSQL_ROW mysql_row;" >>${targetFile}
echo "	mysql_init(&conn);" >>${targetFile}
echo "" >>${targetFile}
echo "	//if (transfer_map.count(\"md5\") == 0) {" >>${targetFile}
echo "	//	return;" >>${targetFile}
echo "	//}" >>${targetFile}
echo "" >>${targetFile}
echo "	if (mysql_real_connect(&conn, host.data(), user.data(), password.data(), db.data(), 0, NULL, CLIENT_FOUND_ROWS)) {" >>${targetFile}
echo "" >>${targetFile}
echo "		ostringstream sql_os;" >>${targetFile}
echo "" >>${targetFile}
echo "" >>${targetFile}
echo "		sql_os << \"delete from ${tableName} \";" >>${targetFile}
echo "		sql_os << \"where 1=1 \";" >>${targetFile}
echo "		//if (transfer_map.find(\"md5\") != transfer_map.end()) {" >>${targetFile}
echo "		//	sql_os << \"and md5 =\" << \"'\" << transfer_map[\"md5\"] << \"'\" << \" \";" >>${targetFile}
echo "		//}" >>${targetFile}
echo ""
echo "		mysql_query(&conn, sql_os.str().data());" >>${targetFile}
echo "" >>${targetFile}
echo "		mysql_close(&conn);" >>${targetFile}
echo "	}" >>${targetFile}
echo "" >>${targetFile}
echo "}" >>${targetFile}
echo "" >>${targetFile}

}


daoFileFen_cpp















