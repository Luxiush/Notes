---
Reference: http://www.cnblogs.com/xinruzhishui/p/5832765.html
---


# Makefile

## 规则
```
    target... : prerequisites ...
	command (必须以【tab】键开头)
	......
```
-- target 可为.o, .exe 或标签
-- prerequisites 为要生成target所需的文件
-- command 为make需要执行的命令（任意shell命令）
-- prerequisites中如果有一个以上的文件比target新，则command所定义的命令就会被执行。

## 实例一
```
   edit: main.o kbd.o command.o display.o insert.o search.o files.o utils.o 
   cc -o edit main.o kbd.o command.o display.o insert.o search.o files.o utils.o
   
   # 注释
   main.o: mian.c defs.h
   cc -c main.c 
   files.o: files.c defs.h buffer.h command.h 
   cc -c files.c 
   utils.o: utils.c defs.h 
   cc -c utils.c 
```


## 工作方式
1. 输入make，命令
2. 在定期目录下寻找名字为Makefile或makefile的文件
3. 如果找到，则将文件中的第一个target作为最终目标，(上例中最终target为edit)
4. 如果edit文件不存在，或edit所依赖的.o文件的修改时间要比edit新，则执行后面所定义的命令来重新生成edit文件
5. 如果edit所依赖的.o文件也不存在，则make会在当前文件中寻找目标为对应.o文件的依赖性，如果找到则根据相应规则生成.o文件


## 变量的使用
```
   objects = main.o kbd.o command.o display.o insert.o search.o files.o utils.o
   edit: $(objects)
   cc -o edit $(objects)
   
   ......
 ``` 


## make自动推导
* make会自动推导文件以及文件依赖关系后面的命令
--- 只要make看到一个.o文件，就会自动的把同名的.c文件加在依赖关系中

例如：如果make找到一个whatever.o，那么whatever.c就会自动的添加到whatever.o的依赖关系中，并且 cc -c whatever.c也会被自动推导出来

```
	objects = main.o kbd.o command.o display.o insert.o search.o files.o utils.o
	edit: $(objects)
	cc -o edit $(objects)  

	main.o: defs.h
	files.o: defs.h buffer.h command.h 
	utils.o: defs.h 
```


## 另类风格
```
	objects = main.o kbd.o command.o display.o /
	insert.o search.o files.o utils.o

	edit : $(objects)
	cc -o edit $(objects)

	$(objects) : defs.h
	kbd.o command.o files.o : command.h
	display.o insert.o search.o files.o : buffer.h 
```


## 清空目标文件
```
	.PHONY : clean
	clean :
		-rm edit $(objects) 
```
* .PHONY 表示clean是一个伪目标
* rm前面的“-”表示，也许某些文件出现问题，但不要管，继续执行
* clean从来都是放在文件的最后
 
 
 ## 多个目标
 ```
 all: server client

.PHONY: all

server:
	@g++ server.cpp -o server -lwsock32 -lws2_32

client:
	@g++ client.cpp -o client -lwsock32 -lws2_32
```



