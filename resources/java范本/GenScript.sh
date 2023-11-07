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


part1End=`cat ${srcFile} -n|grep "${filePrefix}_"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`
part1End=`expr ${part1End} - 1`


#cat ${srcFile}|head -n ${part1End}


part2Beg=`cat ${srcFile} -n|grep "${filePrefix}_"|grep -v case|grep "}"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`

part2Beg=`expr ${part2Beg} + 1`


part2End=`cat ${srcFile} -n|grep "${filePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`
part2End=`expr ${part2End} - 1`


part3Beg=`cat ${srcFile} -n|grep "${filePrefix}_"|grep case| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|tail -n 1`
part3Beg=`expr ${part3Beg} + 1`

part3End=`cat ${srcFile}|wc -l`


echo "1:${part1End}:${part2Beg}:${part2End}:${part3Beg}:${part3End}"

elif [[ "${type}" == "printPart" ]];then

begIndex=${2}
endIndex=${3}
srcFile=${4}

cat ${srcFile}|head -n ${endIndex}|tail -n `expr ${endIndex} + 1 - ${begIndex}`


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
part1End=`expr ${part1End} - 1`
cat ${srcFile}|head -n ${part1End}


elif [[ "${type}" == "implement_position" ]];then

baseFolder=${2}
srcFile=${3}
ruleFile=${4}
prefix=${5}

cat ${srcFile}|wc -l
cat ${srcFile} -n |grep "//beg_"


fi





































