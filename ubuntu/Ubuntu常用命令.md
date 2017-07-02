#Ubuntu 常用命令：

* 安装程序 
	$ sudo apt-get install [software_name]
* 卸载程序
	$ sudo apt-get remove [software_name]
* 切换到root用户
	$ su

* 查看ip
	$ mn-tool
* 查看进程
	$ ps -A 	#查看所有进程

* 查看已安装程序
	$ dpkg --list > installed.txt

* 启动服务
	$ service mysql start
	$ service mysql restart 


## [查找命令]( http://www.cnblogs.com/skynet/archive/2010/12/25/1916873.html )
### find

### grep


## ssh
* 配置文件
/etc/ssh/sshd_config
* 生成密钥对
ssh-keygen -t rsa
* 公钥登录
修改配置文件将 AuthorizedKeyFile 的值置为 ./ssh/authorized_keys
将本地的公钥文件~/.ssh/id_rsa.pub，重定向追加到远程文件authorized_keys的末尾
* 远程登录
ssh user@host 
* scp 
scp <本地文件> <user@host>:<路径>


## vi
Ctrl+s 锁定屏幕
Ctrl+q 解锁
### vi工作模式
1. 普通模式
由Shell进入vi编辑器时，首先进入普通模式。在普通模式下，从键盘输入任何字符都被当作命令来解释。
2. 编辑模式
编辑模式主要用于文本的编辑。该模式下用户输入的任何字符都被作为文件的内容保存起来，并在屏幕上显示出来。
3. 命令模式
命令模式下，用户可以对文件进行一些高级处理。尽管普通模式下的命令可以完成很多功能，但要执行一些如字符串查找、替换、显示行号等操作还是必须要进入命令模式。

* 工作模式切换：
普通模式 -- i, c, o --> 编辑模式
    | <------ Esc ---------| 
普通模式 ------ : ----> 命令模式
    | <------ Esc ---------| 
	
> 在普通模式下输入 i(插入)、c(修改)、o(另起一行) 命令时进入编辑模式；按 esc 键退回到普通模式。
> 在普通模式下输入冒号(:)可以进入命令模式。输入完命令按回车，命令执行完后会自动退回普通模式。
> 提示：如果不确定当前处于哪种模式，按两次 Esc 键将回到普通模式。


### vi 常用命令 
* 文本编辑
i
在当前位置之前插入。使用 I 在当前行的前面插入。
a
在当前位置之后插入。使用 A 插入当前行的结尾。

* 退出
q	如果未被修改则直接退出，否则提示保存修改
q!	强行退出，不保存修改
wq	保存并退出 
ZZ	同wq



## Ubuntu脚本文件：
	* 格式： 第一行必须为 #!/bin/bash 
		* #!字符序列是一种特殊的结构叫做 shebang。 
	    shebang 用来告诉操作系统将执行此脚本所用的解释器的名字。
		每个 shell 脚本都应该把这一文本行 作为它的第一行
	*赋予脚本可执行权限：
		chmod 755[or 700] [filename]
		* 755权限 --- 则每个人都能执行 
		* 700权限 --- 只有文件所有者能够执行
		

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 0xB01FA116

sudo apt-get install ros-jade-desktop-full

设置环境变量：http://jadeluo.iteye.com/blog/940113
设置临时环境变量
	export PATH=/home/yan/share/usr/local/arm/3.4.1/bin:$PATH 
