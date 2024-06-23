文件不存在

ruleFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/resources/java范本/R004.txt"

totalNum=`cat ${ruleFile}|grep "StatementEle :"|grep -v "\-\-"|wc -l`

index=0

while [ ${index} -lt ${totalNum} ];
do
nextIndex=`expr ${index} + 1`
ruleContent=`cat ${ruleFile}|grep "StatementEle :"|grep -v "\-\-"|head -n ${nextIndex}|tail -n 1`


echo "//beg_${ruleContent}"

ruleName=`echo "${ruleContent}"|cut -d":" -f1|sed -e "s/ //g"`

echo "void R004_${ruleName}_${index}Analyzer::handle(const P_NodeValue &nodeValue, Env &env, unordered_map<string, P_NodeValue> &nodeValueMap) {"
echo "	logR004(\"R004_${ruleName}_${index}Analyzer\");"
echo "	StatementToken *p = new StatementToken();"
echo "	p->statementEntity = P_StatementEntity(new StatementEntity);"
echo "	p->statementEntity->begLineNum= nodeValue->node->child_node_list[0]->lineNum;"
echo "	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;"
echo "	p->statementEntity->endLineNum = nodeValue->node->child_node_list[0]->lineNum;"
echo "	p->statementEntity->begIndex = nodeValue->node->child_node_list[0]->index;"
echo "	nodeValue->context[\"StatementEle\"] = P_Token(p);"
echo "};"

echo ""
echo ""
echo ""

index=`expr ${index} + 1`
done