function writeFile(){
vFile=$1
vContent=$2
if [[ "${vFile}" != "" ]];then
 echo "${vContent}" >>  ${vFile}
else
 echo "${vContent}"
fi


}



function refreshSDT_FactoryCpp(){


srcFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/SLR/SDT_Factory.cpp"
ruleFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本/R004.txt"
filePrefix="R004"


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




cat ${srcFile}|head -n ${part1End}

index=`cat ${srcFile}|head -n ${part1End}|tail -n 1|cut -d',' -f2|sed -e "s/}//g"|sed -e "s/ //g"`
index=`expr ${index} + 1`

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
		echo "	{ \"${filePrefix}_${presentSymbol}_${subIndex}\", ${index} },"
		let index++
		let subIndex++
	fi


done



cat ${srcFile}|head -n ${part2End}|tail -n `expr ${part2End} + 1 - ${part2Beg}`





index=`cat ${srcFile}|head -n ${part2End}|tail -n 1|cut -d':' -f1|sed -e "s/ /:/g"|cut -d':' -f2`
index=`expr ${index} + 1`


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

echo "	case ${index}: factory[\"${filePrefix}_${presentSymbol}_${subIndex}\"] = P_SDT_genertor(new ${filePrefix}_${presentSymbol}_${subIndex}Analyzer()); break;"

		let index++
		let subIndex++
	fi


done

rm -rf ${ruleFileTmp}









cat ${srcFile}|tail -n `expr ${part3End} + 1 - ${part3Beg}`

}










function gen_SDD_Rule_Header(){

ruleFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本/R004.txt"
prefix="R004"

logFile=""



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







		let subIndex++
	fi


done


writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" ""
writeFile "${logFile}" "${prefix}_DefaultAnalyzer::${prefix}_DefaultAnalyzer() {}"
writeFile "${logFile}" "${prefix}_DefaultAnalyzer::~${prefix}_DefaultAnalyzer() {}"



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






		let subIndex++
	fi

done

rm -rf ${ruleFileTmp}

}


function gen_SDD_Rule_Body(){
baseFolder="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本"
srcFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/treeAnalyzer/java/R004Analyzer.cpp"
ruleFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本/R004.txt"
prefix="R004"
logFile=""

cd ${baseFolder}

part1End=`cat ${srcFile} -n|grep "//beg_"| awk -F '\t' '{print $1}'|sed -e "s/\s//g"|head -n 1`
part1End=`expr ${part1End} - 1`
cat ${srcFile}|head -n ${part1End}

cat ${srcFile} -n |grep "//beg_" > position.txt
srcFileTotalNum=`cat ${srcFile} -n |wc -l`

positionTotalNum=`cat position.txt|wc -l`
dos2Unix position.txt
#cat position.txt


#    43	//beg_ele_begin : CompilationUnit
#    54	//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
#    72	//beg_CompilationUnit : PackageDeclaration ImportDeclarationList

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
                ruleComment="beg_${var}"
                ruleComment=`echo ${ruleComment}|sed -e "s/beg_${ruleName}#/beg_${ruleName} : /g"|sed -e "s/#/ /g"`
                ruleComment="//${ruleComment}"
                str=`cat position.txt|grep "${ruleComment}$"`

                if [[ "${str}" != "" ]];then

                   begIndex=`echo "${str}"|awk -F '\t' '{print $1}'|sed -e "s/\s//g"`
                   nextRecodId=`cat -n position.txt|grep "${ruleComment}$"|awk -F '\t' '{print $1}'|sed -e "s/\s//g"`
                   if [[ ${nextRecodId} -lt ${positionTotalNum} ]];then
                        let nextRecodId++
                        endIndex=`cat position.txt|head -n ${nextRecodId}|tail -n 1|awk -F '\t' '{print $1}'|sed -e "s/\s//g"`
                        let endIndex--
                   else
                        endIndex="${srcFileTotalNum}"

                   fi
                        cat ${srcFile}|head -n ${endIndex}|tail -n `expr ${endIndex} + 1 - ${begIndex}`
                  
                else
			str="beg_${var}"
			str=`echo ${str}|sed -e "s/#/ /g"|sed -e "s/beg_${presentSymbol} /beg_${presentSymbol} : /g"`
			writeFile "${logFile}" "//${str}"
			writeFile "${logFile}" "void ${prefix}_${presentSymbol}_${subIndex}Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {"
			writeFile "${logFile}" "   log${prefix}(\"${prefix}_${presentSymbol}_${subIndex}Analyzer\");"
			writeFile "${logFile}" "   //TO DO  ${prefix}_${presentSymbol}_${subIndex}Analyzer"
			writeFile "${logFile}" "};"
			writeFile "${logFile}" ""
			writeFile "${logFile}" ""
			writeFile "${logFile}" ""
		


#beg_NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody





                fi

		let subIndex++
	fi


done

rm -rf ${ruleFileTmp}
rm -rf position.txt



}


function refreshSDT_FactoryCpp1(){
srcFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/SLR/SDT_Factory.cpp"
ruleFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本/R004.txt"
filePrefix="R004"


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


cat ${srcFile}|head -n ${part1End}

cat ${srcFile}|head -n ${part2End}|tail -n `expr ${part2End} + 1 - ${part2Beg}`

cat ${srcFile}|tail -n `expr ${part3End} + 1 - ${part3Beg}`

}




#refreshSDT_FactoryCpp



#gen_SDD_Rule_Header




#gen_SDD_Rule_Body



#refreshSDT_FactoryCpp1










