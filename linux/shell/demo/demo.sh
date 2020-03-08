#!/bin/bash

echo "---arguments---"
echo "arguments numbers: $#"
echo '$0: '$0
echo "------"

echo "---file---\n"
files=`ls`
desc=""
for file in ${files} ; do
	if [ -d ${file} ]; then
		desc="directory"		
	else
		if [ ! -s ${file} ]; then
			desc="empty file"
		elif [ -x ${file} ]; then
			desc="executable file"
		else
			desc="file"
		fi
	fi
	echo "${file}: ${desc}"
done
echo "------"

echo "---string---"
str="abcdefg"
echo "substring: "${str:1:4}
if [ str ] 
then
	echo "str is not empty."
else
	echo "str is empty."
fi
echo "------"

echo "---array---"
arr=("00" "aa" "bb" "cc" "dd")
arr[5]="ee"
arr[6]="ff"

echo "arr: "${arr[@]}
echo "length of arr: ${#arr[@]}"
echo "arr[3]: ${arr[3]}"
echo "------"

echo "---while---"
i=1
while (( $i <= 5 )); do
    echo -e "$i \c"
    i=$(($i+1))
done
echo -e "\n------"

echo "---for---"
for((i=0; i<10; i++)); do
	echo -e "$i\t\c"
done
echo -e "\n------"

echo "---case---"
echo -e "Input a number: \c"
read num
case $num in
	1) echo "one";;
	2) echo "two";;
	3) echo "three";;
	*) echo "ohters";;
esac
echo "------"
