@echo off
set /p name=输入要编译的文件名，没有后缀： 

if exist %name%.exe del %name%.exe

if exist %name%.cpp (
	g++ %name%.cpp -I"D:\opencv\build\include" -O2 -g2 -pedantic -c -fmessage-length=0 -o %name%.o 
	
)else echo there is no such file %name%.cpp.

if exist %name%.o   g++ -L"D:\opencv\build\x64\mingw\bin" -llibopencv_core249 -llibopencv_highgui249 -llibopencv_imgproc249 %name%.o -o %name%.exe
				
del %name%.o

echo finished !



rem ************************************gcc(g++)编译器的常识**********************************************************************************
rem 	最基本命令： gcc hello.c -o hello				把hello.c 编译成 hello.exe
rem		预编译：	 gcc -E hello.c -o hello.i	 		使用-E参数可以让gcc在预处理结束后停止编译过程
rem														展开在源文件中定义的宏，并向其中插入“#include”语句所包含的内容
rem					 gcc -c hello.i -o hello.o 			使用-c参数将hello.i编译为目标代码
rem					 gcc hello.o -o hello				将生成的目标文件链接成可执行文件
rem 
rem					 gcc src1.c src2.c -o res			编译由多个文件组成的程序，
rem					 相当于		gcc -c src1.c -o src1.o		
rem								gcc -c src2.c -o src2.o
rem								gcc src1.o src2.o -o res
rem
rem 	警告：
rem			大多以 W 开头，其中 Wall   最有价值（产生尽可能多的警告信息）
rem								Werror 在所有产生警告的地方停止编译，迫使程序员对自己的代码进行修改
rem
rem 	第三方库函数：
rem				函数库实际上就是一些头文件（.h）和库文件（.so或者.a）的集合
rem					 gcc canny.c -I"D:\\opencv_neccessary\\include" -o canny		
rem 													-I选项可以向GCC的【头文件】搜索路径中添加新的目录
rem					 gcc canny.o -L"D:\\opencv_neccessary\\lib" -llibopencv_core249 -llibopencv_highgui249 -llibopencv_imgproc249 -o canny.exe
rem														-L选项可以向GCC的【库文件】搜索路径中添加新的目录
rem
rem 	代码优化：	-On
rem							数字 n 越大优化的等级越高，同时也就意味着程序的运行速度越快（通常n = 2）
rem ************************************* http://blog.chinaunix.net/uid-7340476-id-2436979.html *********************************************
















