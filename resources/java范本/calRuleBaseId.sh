ruleNames=(
CompilationUnit
ImportDeclarationList
TypeDeclarationList
PackageDeclaration
)

vRulefile="R003.txt"



lineCount=`cat ${vRulefile}|wc -l`

id=0;
ruleId=-1;
rm -rf tmp.txt
touch tmp.txt

while [ $id -le $lineCount ]
do
let id++
str=`cat ${vRulefile}|head -n $id|tail -n 1`
echo "${str}"
if [[ "$str" != "--"* ]];then
let ruleId++
ruleName=`echo "${str}"| cut -d":" -f1|sed -e "s/ //g"`
num=`cat tmp.txt|grep "${ruleName}:"|wc -l`
if [[ "${num}" == "0" ]];then
echo "${ruleName}:${ruleId}" >>tmp.txt
fi
fi



done
echo "result:"
cat tmp.txt