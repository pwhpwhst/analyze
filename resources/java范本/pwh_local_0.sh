cd /c/Users/Administrator/Desktop/代码武器库-总/万花筒写轮眼/kaleidoscope-writing-wheel-eye/symbols/java/

templates=(
ClassEntity.cpp
ClassEntity.h
ClassListToken.cpp
ClassListToken.h
ClassToken.cpp
ClassToken.h
)

componentName="Class"

newComponentName="Statement"


for var in ${templates[@]}
do
suffix=`echo "${var}"|cut -d'.' -f2`
suffix=".${suffix}"
oldFileName=`echo "${var}"|sed -e "s/${suffix}//g"`
newFileName=`echo "${var}"|sed -e "s/${componentName}/${newComponentName}/g"|sed -e "s/${suffix}//g"`



cat ${oldFileName}${suffix}|sed -e "s/${oldFileName}/${newFileName}/g" > ${newFileName}${suffix}
done