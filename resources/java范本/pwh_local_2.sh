oriFile="/c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/Lalr.cpp"


lineNum=`cat $oriFile|wc -l`
num=1
while [[ ${num} -le ${lineNum} ]]
do
str=`cat $oriFile|head -n ${num}|tail -n 1`
echo "${str}"

num=`expr ${num} + 1`
done