#!/bin/bash
# 提取源文件开头的说明

cd ./
f_out=./index.md
if [ -e "$f_out" ]; then rm $f_out; fi # '['和']'前后的空格不能少
echo "# 剑指offer" > $f_out

fs=`ls *.cpp` # 等号两边不能有空格
for f in $fs
do
    echo " "  >> $f_out
    echo --- >> $f_out
    echo $f  >> $f_out
    sed -n -e '/^\/\*\*/,/^\*\*\//p' $f | sed -e '/^\/\*\*/d' -e '/^\*\*\//d' >> $f_out
done
