---
Reference: http://www.cnblogs.com/xinruzhishui/p/5832765.html
---


# Makefile

## ����
```
    target... : prerequisites ...
	command (�����ԡ�tab������ͷ)
	......
```
-- target ��Ϊ.o, .exe ���ǩ
-- prerequisites ΪҪ����target������ļ�
-- command Ϊmake��Ҫִ�е��������shell���
-- prerequisites�������һ�����ϵ��ļ���target�£���command�����������ͻᱻִ�С�

## ʵ��һ
```
   edit: main.o kbd.o command.o display.o insert.o search.o files.o utils.o 
   cc -o edit main.o kbd.o command.o display.o insert.o search.o files.o utils.o
   
   # ע��
   main.o: mian.c defs.h
   cc -c main.c 
   files.o: files.c defs.h buffer.h command.h 
   cc -c files.c 
   utils.o: utils.c defs.h 
   cc -c utils.c 
```


## ������ʽ
1. ����make������
2. �ڶ���Ŀ¼��Ѱ������ΪMakefile��makefile���ļ�
3. ����ҵ������ļ��еĵ�һ��target��Ϊ����Ŀ�꣬(����������targetΪedit)
4. ���edit�ļ������ڣ���edit��������.o�ļ����޸�ʱ��Ҫ��edit�£���ִ�к������������������������edit�ļ�
5. ���edit��������.o�ļ�Ҳ�����ڣ���make���ڵ�ǰ�ļ���Ѱ��Ŀ��Ϊ��Ӧ.o�ļ��������ԣ�����ҵ��������Ӧ��������.o�ļ�


## ������ʹ��
```
   objects = main.o kbd.o command.o display.o insert.o search.o files.o utils.o
   edit: $(objects)
   cc -o edit $(objects)
   
   ......
 ``` 


## make�Զ��Ƶ�
* make���Զ��Ƶ��ļ��Լ��ļ�������ϵ���������
--- ֻҪmake����һ��.o�ļ����ͻ��Զ��İ�ͬ����.c�ļ�����������ϵ��

���磺���make�ҵ�һ��whatever.o����ôwhatever.c�ͻ��Զ�����ӵ�whatever.o��������ϵ�У����� cc -c whatever.cҲ�ᱻ�Զ��Ƶ�����

```
	objects = main.o kbd.o command.o display.o insert.o search.o files.o utils.o
	edit: $(objects)
	cc -o edit $(objects)  

	main.o: defs.h
	files.o: defs.h buffer.h command.h 
	utils.o: defs.h 
```


## ������
```
	objects = main.o kbd.o command.o display.o /
	insert.o search.o files.o utils.o

	edit : $(objects)
	cc -o edit $(objects)

	$(objects) : defs.h
	kbd.o command.o files.o : command.h
	display.o insert.o search.o files.o : buffer.h 
```


## ���Ŀ���ļ�
```
	.PHONY : clean
	clean :
		-rm edit $(objects) 
```
* .PHONY ��ʾclean��һ��αĿ��
* rmǰ��ġ�-����ʾ��Ҳ��ĳЩ�ļ��������⣬����Ҫ�ܣ�����ִ��
* clean�������Ƿ����ļ������
 
 
 ## ���Ŀ��
 ```
 all: server client

.PHONY: all

server:
	@g++ server.cpp -o server -lwsock32 -lws2_32

client:
	@g++ client.cpp -o client -lwsock32 -lws2_32
```



