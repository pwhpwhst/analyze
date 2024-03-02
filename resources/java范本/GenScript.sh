type="${1}"


function writeFile(){
vFile=$1
vContent=$2
if [[ "${vFile}" != "" ]];then
 echo "${vContent}" >>  ${vFile}
else
 echo "${vContent}"
fi

}


###########################################

if [[ "${type}" == "1" ]];then

srcFile=${2}
ruleFile=${3}
filePrefix=${4}
preFilePrefix=${5}

part1End=`cat ${srcFile} -n|grep "${filePrefix}_"|grep "}"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`

if [[ "${part1End}" != "" ]];then
part1End=`expr ${part1End} - 1`
else
part1End=`cat ${srcFile} -n|grep "${preFilePrefix}_"|grep -v case|grep "}"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
fi






#cat ${srcFile}|head -n ${part1End}


part2Beg=`cat ${srcFile} -n|grep "${filePrefix}_"|grep -v case|grep "}"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
if [[ "${part2Beg}" != "" ]];then
part2Beg=`expr ${part2Beg} + 1`
else
part2Beg=`cat ${srcFile} -n|grep "${preFilePrefix}_"|grep -v case|grep "}"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
part2Beg=`expr ${part2Beg} + 1`
fi

part2End=`cat ${srcFile} -n|grep "${filePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`
if [[ "${part2End}" != "" ]];then
part2End=`expr ${part2End} - 1`
else
part2End=`cat ${srcFile} -n|grep "${preFilePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
fi



part3Beg=`cat ${srcFile} -n|grep "${filePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
if [[ "${part3Beg}" != "" ]];then
part3Beg=`expr ${part3Beg} + 1`
else
part3Beg=`cat ${srcFile} -n|grep "${preFilePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
part3Beg=`expr ${part3Beg} + 1`
fi

part3End=`cat ${srcFile}|wc -l`


echo "1:${part1End}:${part2Beg}:${part2End}:${part3Beg}:${part3End}"

elif [[ "${type}" == "printPart" ]];then

begIndex=${2}
endIndex=${3}
srcFile=${4}


cat ${srcFile}|head -n ${endIndex}|tail -n `expr ${endIndex} + 1 - ${begIndex}`

elif [[ "${type}" == "printPart2" ]];then

filePrefix=${2}

echo "#include <vector>"
echo "#include <sstream>"
echo "#include <iostream>"
echo "#include \"SDT_${filePrefix}_Factory.h\""
echo "#include<boost/algorithm/string.hpp>"
echo "#include \"../treeAnalyzer/java/${filePrefix}Analyzer.h\""
echo "using namespace std;"
echo "using namespace boost;"
echo ""
echo ""
echo ""
echo "SDT_${filePrefix}_Factory SDT_${filePrefix}_Factory::instance;"
echo "SDT_${filePrefix}_Factory::SDT_${filePrefix}_Factory() {"
echo "	control_Param = {"

elif [[ "${type}" == "printPart3" ]];then
filePrefix=${2}

echo "	};"
echo "}"
echo ""
echo "P_SDT_genertor SDT_${filePrefix}_Factory::getSDT_genertor(const string &key) {"
echo "	if (factory.count(key) > 0) {"
echo "		return factory[key];"
echo "	}"
echo ""
echo ""
echo "	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;"
echo ""
echo ""
echo "	switch (caseValue) {"


elif [[ "${type}" == "printPart4" ]];then
filePrefix=${2}

echo "	default:"
echo ""
echo "		if (key.find(\"${filePrefix}_\") == 0) {"
echo "			vector <string> string_list;"
echo "			split(string_list, key, is_any_of(\"_\"));"
echo "			if (string_list[1] == \"0\" || string_list[1].find(\"'\") == 0) {"
echo "				factory[key] = P_SDT_genertor(new ${filePrefix}_DefaultAnalyzer());"
echo "			}"
echo "		}"
echo ""
echo "	}"
echo ""
echo ""
echo ""
echo "	return factory[key];"
echo "}"
echo "SDT_${filePrefix}_Factory::~SDT_${filePrefix}_Factory() {}"







elif [[ "${type}" == "readFile" ]];then

file=${2}
cat ${file}

elif [[ "${type}" == "2" ]];then

ruleFile=${2}
prefix=${3}
logFile=""

writeFile "${logFile}" "#pragma once"
writeFile "${logFile}" "#include \"../../SLR/SDT_genertor.h\""
writeFile "${logFile}" "using namespace std;"
writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" ""




writeFile "${logFile}" "class ${prefix}_DefaultAnalyzer :virtual public SDT_genertor {"
writeFile "${logFile}" "public: ${prefix}_DefaultAnalyzer();"
writeFile "${logFile}" "public: P_NodeValue handle(const P_NodeValue &nodeValue, vector<P_NodeValue> &stack, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);"
writeFile "${logFile}" "public: virtual ~${prefix}_DefaultAnalyzer();"
writeFile "${logFile}" "};"


elif [[ "${type}" == "4_1" ]];then

baseFolder=${2}
srcFile=${3}
ruleFile=${4}
prefix=${5}


cd ${baseFolder}

part1End=`cat ${srcFile} -n|grep "//beg_"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`
if [[ "${part1End}" != "" ]];then
part1End=`expr ${part1End} - 1`
else
part1End=`cat ${srcFile}|wc -l`
fi

cat ${srcFile}|head -n ${part1End}


elif [[ "${type}" == "implement_position" ]];then

baseFolder=${2}
srcFile=${3}
ruleFile=${4}
prefix=${5}

cat ${srcFile}|wc -l
cat ${srcFile} -n |grep "//beg_"


fi





































