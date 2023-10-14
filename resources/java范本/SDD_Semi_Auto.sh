
function writeFile(){
vFile=$1
vContent=$2
if [[ "${vFile}" != "" ]];then
 echo "${vContent}" >>  ${vFile}
else
 echo "${vContent}"
fi


}



function SDT_Factory_Part_1(){

ruleFile="R003.txt"
index=0
prefix="R003"


ruleFileTmp="${ruleFile}.tmp"
cat ${ruleFile} |sed -e "s/ : /#/g"|sed -e "s/ /#/g" > ${ruleFileTmp}


presentSymbol=""
subIndex=0
for var in `cat ${ruleFileTmp}`
do
	if [[ "${var}" != "--"* ]];then
		ruleName=`echo "${var}"|cut -d "#" -f1`
		if [[ "${presentSymbol}" != "${ruleName}" ]];then
			presentSymbol="${ruleName}"
                        subIndex="0"
		fi
		echo "{ \"${prefix}_${presentSymbol}_${subIndex}\", ${index} },"
		let index++
		let subIndex++
	fi


done

rm -rf ${ruleFileTmp}
}



function SDT_Factory_Part_2(){
ruleFile="R003.txt"
index=0
prefix="R003"


ruleFileTmp="${ruleFile}.tmp"
cat ${ruleFile} |sed -e "s/ : /#/g"|sed -e "s/ /#/g" > ${ruleFileTmp}


presentSymbol=""
subIndex=0
for var in `cat ${ruleFileTmp}`
do
	if [[ "${var}" != "--"* ]];then
		ruleName=`echo "${var}"|cut -d "#" -f1`
		if [[ "${presentSymbol}" != "${ruleName}" ]];then
			presentSymbol="${ruleName}"
                        subIndex="0"
		fi

echo "case ${index}: factory[\"${prefix}_${presentSymbol}_${subIndex}\"] = P_SDT_genertor(new ${prefix}_${presentSymbol}_${subIndex}Analyzer()); break;"

		let index++
		let subIndex++
	fi


done

rm -rf ${ruleFileTmp}
}





function gen_SDD_Rule_Header(){

ruleFile="R003.txt"
index=0
prefix="R003"

logFile="a.txt"

if [[ "${logFile}" != "" ]];then
rm -rf ${logFile}
fi


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


ruleFileTmp="${ruleFile}.tmp"
cat ${ruleFile} |sed -e "s/ : /#/g"|sed -e "s/ /#/g" > ${ruleFileTmp}


presentSymbol=""
subIndex=0

for var in `cat ${ruleFileTmp}`
do
	if [[ "${var}" != "--"* ]];then
		ruleName=`echo "${var}"|cut -d "#" -f1`
		if [[ "${presentSymbol}" != "${ruleName}" ]];then
			presentSymbol="${ruleName}"
                        subIndex="0"
		fi

writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" ""
str="beg_${var}"
str=`echo ${str}|sed -e "s/#/ /g"|sed -e "s/beg_${presentSymbol} /beg_${presentSymbol} : /g"`

writeFile "${logFile}" "//${str}"
writeFile "${logFile}" "class ${prefix}_${presentSymbol}_${subIndex}Analyzer :virtual public Non_Terminate_genertor {"
writeFile "${logFile}" "   public: ${prefix}_${presentSymbol}_${subIndex}Analyzer();"
writeFile "${logFile}" "   public: void handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap);"
writeFile "${logFile}" "   public: virtual ~${prefix}_${presentSymbol}_${subIndex}Analyzer();"
writeFile "${logFile}" "};"






		let index++
		let subIndex++
	fi


done


writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" "${prefix}_DefaultAnalyzer::${prefix}_DefaultAnalyzer() {}"
writeFile "${logFile}" "${prefix}_DefaultAnalyzer::~${prefix}_DefaultAnalyzer() {}"


index=0
presentSymbol=""
subIndex=0

for var in `cat ${ruleFileTmp}`
do
	if [[ "${var}" != "--"* ]];then
		ruleName=`echo "${var}"|cut -d "#" -f1`
		if [[ "${presentSymbol}" != "${ruleName}" ]];then
			presentSymbol="${ruleName}"
                        subIndex="0"
		fi

writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" ""
str="beg_${var}"
str=`echo ${str}|sed -e "s/#/ /g"|sed -e "s/beg_${presentSymbol} /beg_${presentSymbol} : /g"`

writeFile "${logFile}" "//${str}"
writeFile "${logFile}" "${prefix}_${presentSymbol}_${subIndex}Analyzer::${prefix}_${presentSymbol}_${subIndex}Analyzer() {}"
writeFile "${logFile}" "${prefix}_${presentSymbol}_${subIndex}Analyzer::~${prefix}_${presentSymbol}_${subIndex}Analyzer() {}"





		let index++
		let subIndex++
	fi


done

rm -rf ${ruleFileTmp}

}




function gen_SDD_Rule_Body(){

ruleFile="R003.txt"
index=0
prefix="R003"

analyzerCppFile="../../treeAnalyzer/java/R003Analyzer.cpp"


logFile="a.txt"

if [[ "${logFile}" != "" ]];then
rm -rf ${logFile}
fi


ruleFileTmp="${ruleFile}.tmp"
cat ${ruleFile} |sed -e "s/ : /#/g"|sed -e "s/ /#/g" > ${ruleFileTmp}


for var in `cat ${ruleFileTmp}`
do
	if [[ "${var}" != "--"* ]];then
		ruleName=`echo "${var}"|cut -d "#" -f1`
		if [[ "${presentSymbol}" != "${ruleName}" ]];then
			presentSymbol="${ruleName}"
                        subIndex="0"
		fi


		count=`cat ${analyzerCppFile}|grep "TO DO"|grep "${prefix}_${presentSymbol}_${subIndex}Analyzer"|wc -l`

		if [[ "${count}" == "0" ]];then
			writeFile "${logFile}" ""
			writeFile "${logFile}" ""
			writeFile "${logFile}" ""
			str="beg_${var}"
			str=`echo ${str}|sed -e "s/#/ /g"|sed -e "s/beg_${presentSymbol} /beg_${presentSymbol} : /g"`
			writeFile "${logFile}" "//${str}"
			writeFile "${logFile}" "void ${prefix}_${presentSymbol}_${subIndex}Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {"
			writeFile "${logFile}" "   logR003(\"${prefix}_${presentSymbol}_${subIndex}Analyzer\");"
			writeFile "${logFile}" "   //TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer"
			writeFile "${logFile}" "};"
		fi


		let index++
		let subIndex++
	fi
done

rm -rf ${ruleFileTmp}





}



#SDT_Factory_Part_1

#SDT_Factory_Part_2


#gen_SDD_Rule_Header

#gen_SDD_Rule_Body