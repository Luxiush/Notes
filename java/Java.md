# windows7 多版本java共存及切换
## [在windows上实现java6和Java8共存解决办法](http://www.ituring.com.cn/article/207395)
* 环境变量设置
```
JAVA_HOME6 = jdk6的安装路径
JAVA_HOME7 = jdk7的安装路径
JAVA_HOME8 = jdk8的安装路径

JAVA_HOME  = %JAVA_HOME7%

Path = %JAVA_HOME%/bin;...
```
* 如果Path中有 C:\ProgramData\Oracle\Java\javapath; 删除之。否则会引变量错误
* 删除C:\Windows\System32目录下的java.exe
因为安装jdk时自动将java.exe、javaw.exe、javaws.exe三个可执行文件复制到了C:\Windows\System32目录，
而这个目录在WINDOWS环境变量中的优先级高于JAVA_HOME设置的环境变量优先级

## [关于单独的jre和jdk目录下的jre的解析](http://blog.csdn.net/han_dongwei/article/details/7782771)
* jre(Java Runtime Environment)
单独存在的jre文件夹只是提供java运行所需的环境，只有client性质的jvm.dll
安装的时候自动把jre的java.exe放到了C:\Windows\System32目录中，因此不必再为之设置环境变量

* jdk(Java Development Kit)
java开发工具包，也包含一个jre，
具备开发功能的jdk自己的jre下会同时有client性质的jvm和server性质的 jvm


---
# [eclipse多jdk版本共存问题](http://blog.csdn.net/u010666884/article/details/51831519)
	* 在Preference里设置整个workspace的jdk：Preferences->Java->Installed JREs，把各个版本加上
	    同时相应更改Compiler版本：Preferences->Java->Compiler
	* 每个工程都指定一个jdk版本：
		Properties->Java Build Path->Libraries->Add Library->JRE System Library->Execution Environment里选J2SE 1.4/1.5
		Properties->Java Compiler->Enable project specific settings->JDK Compiliance选1.4/1.5 
		
---
# 基本命令行命令
	编译：
	$ javac -d destdir srcFile
	
	打包：
	$ jar cvf destdir/name.jar srcdir


