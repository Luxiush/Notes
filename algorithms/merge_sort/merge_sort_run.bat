@echo off
cd .

set file_name=merge_sort
g++ -o %file_name%.exe %file_name%.cpp

if exist %file_name%.exe (
	%file_name%.exe %file_name%_in.txt %file_name%_out.txt
) else (
	echo file %file_name%.exe missing.
	pause
)