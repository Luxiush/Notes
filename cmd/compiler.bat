@echo off
set /p name=����Ҫ������ļ�����û�к�׺�� 

if exist %name%.exe del %name%.exe

if exist %name%.cpp (
	g++ %name%.cpp -I"D:\opencv\build\include" -O2 -g2 -pedantic -c -fmessage-length=0 -o %name%.o 
	
)else echo there is no such file %name%.cpp.

if exist %name%.o   g++ -L"D:\opencv\build\x64\mingw\bin" -llibopencv_core249 -llibopencv_highgui249 -llibopencv_imgproc249 %name%.o -o %name%.exe
				
del %name%.o

echo finished !



rem ************************************gcc(g++)�������ĳ�ʶ**********************************************************************************
rem 	�������� gcc hello.c -o hello				��hello.c ����� hello.exe
rem		Ԥ���룺	 gcc -E hello.c -o hello.i	 		ʹ��-E����������gcc��Ԥ���������ֹͣ�������
rem														չ����Դ�ļ��ж���ĺ꣬�������в��롰#include�����������������
rem					 gcc -c hello.i -o hello.o 			ʹ��-c������hello.i����ΪĿ�����
rem					 gcc hello.o -o hello				�����ɵ�Ŀ���ļ����ӳɿ�ִ���ļ�
rem 
rem					 gcc src1.c src2.c -o res			�����ɶ���ļ���ɵĳ���
rem					 �൱��		gcc -c src1.c -o src1.o		
rem								gcc -c src2.c -o src2.o
rem								gcc src1.o src2.o -o res
rem
rem 	���棺
rem			����� W ��ͷ������ Wall   ���м�ֵ�����������ܶ�ľ�����Ϣ��
rem								Werror �����в�������ĵط�ֹͣ���룬��ʹ����Ա���Լ��Ĵ�������޸�
rem
rem 	�������⺯����
rem				������ʵ���Ͼ���һЩͷ�ļ���.h���Ϳ��ļ���.so����.a���ļ���
rem					 gcc canny.c -I"D:\\opencv_neccessary\\include" -o canny		
rem 													-Iѡ�������GCC�ġ�ͷ�ļ�������·��������µ�Ŀ¼
rem					 gcc canny.o -L"D:\\opencv_neccessary\\lib" -llibopencv_core249 -llibopencv_highgui249 -llibopencv_imgproc249 -o canny.exe
rem														-Lѡ�������GCC�ġ����ļ�������·��������µ�Ŀ¼
rem
rem 	�����Ż���	-On
rem							���� n Խ���Ż��ĵȼ�Խ�ߣ�ͬʱҲ����ζ�ų���������ٶ�Խ�죨ͨ��n = 2��
rem ************************************* http://blog.chinaunix.net/uid-7340476-id-2436979.html *********************************************
















