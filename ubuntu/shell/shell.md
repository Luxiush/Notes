# shell 常用命令

## 基本命令

### 解压&打包
* unzip

|  | . |
|:---|:---|
| -q  | quiet,不显示解压过程  |
| -l  | list,显示压缩包中包含的文件,不解压  |
| -f  | freshen,更新现有文件  |
| -u  | update,更新现有文件,同时将其他文件解压  |
| -n  | 不覆盖已有文件  |

* tar

|  | . |
|:---|:---|
| -c | 建立新的压缩文件(create) |
| -x | 从压缩文件中提取(extract) |
| -v | 显示操作过程 |
| -f | 指定压缩文件 |
| -t | 列出压缩文件的内容 |

### 改变文件所有者/所属组
* chown
```
$ chown [OPTION]... [OWNER][:[GROUP]] FILE...
```

| OPTION |  |
|:---|:---|
| -R | recursively |


* chgrp
```
$ chgrp [OPTION]... GROUP FILE...
```

| OPTION |  |
|:---|:---|
| -R | recursively |


### 进程管理
#### ps
|  |  `ps aux` 各列的含义 |
|:---|:---|
| USER | 所属用户  |
| PID | 进程ID  |
| %CPU | 占用的CPU百分比  |
| %MEM | 占用的内存百分比  |
| VSZ |  虚拟内存占用量(kb) |
| RSS  | 固定内存占用量(kb)  |
| TTY  | 所运行的终端,'?'表示与终端无关  |
| STAT  | 状态  |
| START  | 启动的时间  |
| TIME   | 实际使用CPU总的时间  |
|COMMAND | 进程的命令和参数  |

|  | STAT的常见取值 |
|:---|:---|
| Z  | 僵尸进程  |
| S  | 休眠  |
| + | 位于后台 |
| s | 包含子进程 |
| D  | 无法中断的休眠状态(I/O)  |
| T  | 停止  |
| <  | 优先级较高  |
| N  | 优先级较低  |


#### kill
* 用于发送`指定信号`到`指定进程`
```
$ kill -KILL 1234
```

|  | 常用信号 |  |
|:---|:---|:---|
| HUP  |   1  |  终端断线 |
| INT  |   2  |  中断（同 Ctrl + C） |
| QUIT |   3  |  退出（同 Ctrl + \） |
| KILL |   9  |  强制终止(注意会产生僵尸进程), 其他信号进程都有权利忽略 |
| TERM |  15  |  终止(默认值), 在退出之前可以清理并释放资源 |
| CONT |  18  |  继续（与STOP相反， fg/bg命令） |
| STOP |  19  |  暂停（同 Ctrl + Z） |


##### 关于僵尸进程&孤儿进程
* 孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作。

* 僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中。僵尸进程会占用PID, 过多僵尸进程会导致PID耗尽, 系统无法产生新的进程.

>任何一个进程，当其运行结束(exit)之后，其使用的所有资源和内存空间都会释放，以供其他进程使用；但其在OS内核的process table中仍旧保留一条记录，包含该进程的process ID，退出状态exit status，运行时间等信息。这些信息是方便该进程的父进程随时获取它的exit status(即子进程结束后为什么要进入zombie状态)。

* 杀僵尸进程: 由于僵尸进程是死后每个给他收尸造成的, 所以一个办法是kill僵尸进程的父进程, 让僵尸进程变成孤儿进程, 过继给1号进程init清理.  --- <http://blog.51cto.com/6244685/1316234>


---
## grep
- 文件搜索
```
$ grep <options> <pattern> <files>   
$ grep '<要找的内容>' <目标文件>
$ grep '<要找的内容>' *                        # 在当前文件夹下的所有文件中找指定内容
$ grep <pattern1> | <pattern2> <files>       # 显示匹配 pattern1 或 pattern2的行，
$ grep <pattern1> <files> | grep <pattern2>  # 显示既匹配 pattern1 又匹配pattern2 的行。
```

常用参数

| 参数 | 说明 |
|:---|:---|
| -i | 忽略大小写 |
| -E | 支持正则表达式搜索 |
| -w | 只匹配整个单词 |
| -x | 只匹配整行 |
| -v | 显示不匹配的行,(反选) |
| -m | 指定最大匹配次数(max-count) |
| -n | 同时输出行数(line number) |
| -c | 只输出匹配的个数(count) |
| -B | 同时输出第一个匹配的前n行(before) |
| -A | 同时输出最后一个匹配的后n行(after) |
| -r | 递归查找 |
| -R | 查找所有文件包含子目录 |
| -l | 只显示文件名 |


* 文件比较
```
$ grep -vwf file1 file2 # 统计file1中没有，file2中有的行
```


## 文空查看命令

### head
* 显示文档开头
```
$ head <options> <file>
```

| 参数 | 说明 |
|:---|:---|
| -[N] | 输出文件的头[N]行 |
| -n -[N] | 不显示最后[N]行 |


### tail
* 显示文档结尾
```
$ tail <options> <file>
```

| 参数 | 说明 |
|:---|:---|
| -[N] | 输出文件的最后[N]行 |
| -n +[N] | 从第[N]行开始显示 |
| -f | 循环读取, 用于监视文件的增长 |


### more
* 用于分页显示文件, [Space]/[Enter]下一页, [b]上一页.
* 同时还支持字符串查找(与vi相似)
* 启动时就加载整个文件

### less
* 用于分页查看文件
* 比more更灵活, 也支持字符串查找
* 在查看之前不会加载整个文件

### cat
> Concatenate FILE(s), or standard input, to standard output.

### tac
* 从最后一行开始输出文件
* 或者将文件倒序输出



## sort
将文件的每一行作为一个单位，相互比较，比较原则是从首字符向后，依次按ASCII码值进行比较，最后将他们按升序输出。
```
$ sort <options> <file>
```

| 参数 | 说明 |
|:---|:---|
| -b | 忽略前导空白符 |
| -d | 字典序 |
| -f | 忽略大小写排序 |
| -g | 按数字排序 |
| -n | 根据每行数字的值排序 |
| -i | 忽略不可显示字符 |
| -m | 月份排序(JAN < ... < 'DEC') |
| -R | 根据随机的哈希值排序 |
| -r | reverse |
| -m | merge 合并已经有序的文件 |
| -u | 去除重复行 |



## uniq
报告或者消除文件中的重复内容


* 对文本进行排序去重
```
$ sort <file_in> | uniq > <file_out>
```

## cut
从输入文件中提取每行的特定部分
```
$ cut <options> <file>
```
常用参数

| 参数 | 例子 | 说明 |
|:---|:---|:---|
| -b | 3 or 3,5,7 or 3-9 or 3- or -9  | 指定提取每行的特定`字节` |
| -c | 3 or 3,5,7 or 3-9 or 3- or -9 | 指定提取每行的特定`字符` |
| -f | 3 or 3,5,7 or 3-9 or 3- or -9 | 指定要提取的`域` |
| -d | "<delimiter1>,<delimiter2>..." | 指定每行的分隔符(默认为\t),根据分隔符将每行切分若干`域` |


## [find](http://www.cnblogs.com/johnnyliu/archive/2013/04/09/3010384.html)
```
$ find <查找目录> <参数> <匹配模型>
```

| **参数** | **匹配模型** | **说明** |
|:---|:---|:---|
| -name | *.sh | 以.sh结尾 |
| -regex | <pattern> | 用正则表达式匹配文件路径 |
| -mtime | -5 | 更改时间在5天以内 |
| -mtime | +3 | 更改时间在3天以前 |
| -size | +1000000c | 文件大小大于1M(1000000bytes) |
| -type | d | 文件类型为d的目录文件 |
| -type | l | 文件类型为l的链接文件 |
| -type | f | 普通文件 |
| -perm | 755 | 属性为755 |
| -inum | <inode_number> | 通过文件的inode number 查找 |
| -user | root | 属主为root |
| -depth | ... | 广度优先遍历 |
| -maxdepth | <int_number> | 设定递归搜索的目录层级, 1为当前目录(不递归) |
| -print | ... | 一行一个 |
| -print0 | ... | 不换行 |


## ls
```
$ ls <options> <directory or file>
```

### 常用参数

| 参数 | 说明 |
|:---|:---|
| -a | all |
| -h | size in human readable |
| -l | list format |
| -r | reverse order |
| -R | --recursive(递归子目录) |
| -s | size,输出大小 |
| -t | 按修改时间排序 |
| -d | 只显示目录 |

### 输出格式:
```shell
$ ls -l /etc
属性 硬链接数 owner  group  size(byte) date      文件名
-rw-r--r-- 1 root    root     388 Jan 15 02:33 logrotate.status
drwxr-xr-x 2 root    root    4096 Sep 23  2011 misc
drwxr-x--- 2 root    slocate 4096 Mar 12  2015 mlocate
drwxr-xr-x 2 mongodb root    4096 Sep 19  2016 mongodb
drwxr-xr-x 2 root    root    4096 Aug 23  2016 net-snmp
drwx------ 3 nginx   nginx   4096 Dec 18 03:23 nginx  
drwxr-xr-x 2 root    root    4096 Nov 26  2016 plymouth
```

#### 属性(1+9): 
- 类型(1): `-`表示普通文件, `d`表示目录, `l`表示软链接
- 权限(9): rwx(Owner)r-x(Group)r-x(Other)

#### 硬链接数
- 目录的硬链接数等于目录中的子目录数量加2(.和..).
- 每个目录都会保存一个其父目录的硬链接

- 每创建一个目录, 在其父目录中会新增一个目录项, 用于将子目录的名称和子目录的inode关联起来. 同时, 新的目录中也会自动创建两个目录项, 分别将"..","."和父目录,当前目录关联起来. 

## ln
- 创建链接
```
ln [option] [target] [link_name]
```

| . | . |
|:---|:---|
| -s | 软链接(symbolic), 符号链接 |
| -P | 硬链接(physical) |
| -b | 删除，覆盖以前建立的链接 |
| -d | 允许超级用户制作目录的硬链接 |
| -f | 强制执行 |
| -i | 交互模式，文件存在则提示用户是否覆盖 |
| -n | 把符号链接视为一般目录 |

### 软连接 & 硬链接
#### 简而言之
- 软链接:  (指针)
- 硬链接: (引用), 不能对目录创建, 不可以跨文件系统, 删除一个硬链接不会影响对其他硬链接的访问

#### Details 
##### 关于文件系统
- 在unix系统中, 文件的存储分为两部分: 1)保存文件中数据的数据块, 2)保存文件的大小,创建日期,权限等`元数据`的索引节点(inode).
- 硬盘格式化的时候, 操作系统自动将硬盘分成两个区域: 1)存放文件数据的数据区, 2)专门存放文件元数据的inode区.

##### inode和硬链接
- 每个inode都有一个唯一的id, 用于标识不同文件, 移动和重命名文件不会改变inode id. 
- 而文件名则只是一个便于用户记忆的inode"绰号", 一个文件可以有多个文件名, 一个文件名就相当于文件的一个`硬链接`.
- 由于共用一个inode, 因此各个硬链接具有相同的文件按属性. 
- 创建一个硬链接时, 对应inode中的`链接数`就会加1, 反之, 删除一个就减一, 当减到0时, 操作系统就会将inode号和与之对应的数据块回收. 

##### 软链接
- 本质是一个文件, 保存的是所指向文件的路径.

##### 为什么不能为目录创建硬链接
- 简单来说这样会破坏目录的树型结构, 产生循环, 导致循环引用.

##### ref: 
- 理解inode: < http://www.ruanyifeng.com/blog/2011/12/inode.html >
- Linux中的硬链接与软链接: <https://segmentfault.com/a/1190000010029786>
- 多角度分析为什么linux的硬链接不能指向目录: < http://blog.csdn.net/longerzone/article/details/23870297 > 


## [xargs](http://blog.csdn.net/xifeijian/article/details/9286189)
> xargs是给命令传递参数的一个过滤器，也是组合多个命令的一个工具。它把一个数据流分割为一些足够小的块，以方便过滤器和命令进行处理。
```
$ <command> | xargs -n <max_args>       # -n 指定每行显示的参数个数
$ <command> | xargs -d "<delimeter>"    # -d 指定参数之间的分隔符为<delimeter>
$ <command> | xargs -e "<EOF_string>"   # 将<EOF_string>之前的参数传递给xargs后面的命令(不包括<EOF_string>)
$ <command> | xargs -i                  # 将结果传递给{}
```

examples:
```
$ find . -type f -print | xargs grep "admin"        # 在当前路径下的普通文件中搜索 "admin"
$ find . -type f -print | xargs -i cp {} /usr/      # -i 选项后，xargs将匹配的结果传递给 {}
```


## 重定向
* 输出重定向(>, >>)
```
$ cat > <file>.out    
```

* 输入重定向(<, <<)
```
$ cat > <file>.out < <file>.in
```

* 管道(|)
```
$ <command_1> | <command_2>
```


## wc
WordCount
```
$ wc <options> <filename>
```

常用参数

| 参数 | 说明 |
|:---|:---|
| -w | 统计字数 |
| -l | 统计行数 |
| -c | 统计字节数 |
| -L | 最长行的长度 |
| -m | 统计字符数 |


## whereis
* 只能用于程序名的搜索
```
$ whereis <options> <directory> <filename>                       
```
常用参数

| 参数 | 说明 |
|:---|:---|
| -b | 定位可执行文件 |
| -B | 指定搜索可执行文件的路径 |
| -s | 定位源代码文件 |
| -S | 指定搜索源代码文件的路径 |
| -m | 定位帮助文件 |
| -M | 指定帮助文档的搜索路径 |


## nohup
nohup命令可以将程序以忽略挂起信号的方式运行起来，被运行的程序的输出信息将不会显示到终端.
```
$ nohup <command> &
```

## [crontab]( http://www.cnblogs.com/peida/archive/2013/01/08/2850483.html )
设置定时任务

### 关于crond服务
> crond是linux下用来周期性的执行某种任务或等待处理某些事件的一个守护进程，与windows下的计划任务类似，当安装完成操作系统后，默认会安装此服务工具，并且会自动启动crond进程，crond进程每分钟会定期检查是否有要执行的任务，如果有要执行的任务，则自动执行该任务。

> Linux下的任务调度分为两类，系统任务调度和用户任务调度。

### 相关配置
- 日志文件: /var/log/cron
- 系统任务调度: /etc/cron*
- 用户任务调度: /var/spool/cron/<username>

- crontab文件格式(/etc/crontab):
```
min hour day-of-month month day-of-week command-to-be-executed

各个时间字段的特殊字符:
    星号（*）：代表所有可能的值，例如month字段如果是星号，则表示在满足其它字段的制约条件后每月都执行该命令操作。
    逗号（,）：可以用逗号隔开的值指定一个列表范围，例如，“1,2,5,7,8,9”
    中杠（-）：可以用整数之间的中杠表示一个整数范围，例如“2-6”表示“2,3,4,5,6”
    正斜线（/）：可以用正斜线指定时间的间隔频率，例如“0-23/2”表示每两小时执行一次。同时正斜线可以和星号一起使用，例如*/10，如果用在minute字段，表示每十分钟执行一次。
```

## [update-alternatives]( http://blog.csdn.net/jasonding1354/article/details/50470109 )
* 用于维护系统命令链接符

| 常用选项 |   |
|:---|:---|
| list | 显示一个命令链接符的可选命令 |
|   | $ update-alternatives --list <name> |
| install | 添加链接符 |
|   | $ update-alternatives --install <link> <name> <path> <priority> |
| remove | 删除一个命令的link值 |
|   | $ update-alternatives --remove <name> <path> |
| config | 修改命令链接符的指向 |
|   | $ update-alternatives --config <name> |
    

## service
- 启动,停止服务

## update-rc.d
- 添加, 删除`/etc/init.d`目录下的服务



## expr
布尔运算, 比较运算, 四则算术运算, 正则匹配, 表达式求值


## df
- 查看磁盘使用情况


## [free]( https://www.cnblogs.com/coldplayerest/archive/2010/02/20/1669949.html )
- 显示系统使用和空闲的内存情况，包括物理内存、交互区内存(swap)和内核缓冲区内存. 共享内存将被忽略.

| 参数说明 |  |
|:---|:---|
| b,k,m,g | 设置显示的单位 |
| h | 自动调整单位, 以适合人阅读 |
| s <间隔秒数> | 持续观察 |

```
[root@SF1150 ~]$ free -m
             total       used       free     shared    buffers     cached
Mem:          3000       2000       1000         61        100        500
-/+ buffers/cache:       1400       1600
Swap:         4092        375       3717
```

- 第二行(Mem): 是从OS角度来看的, total = used + free;
<p> shared(被多个进程共享的内存), buffer(被OS buffer的内存), cached(被OS cached的内存). </p>

- 第三行(buffer/cache): 从应用程序角度看到的系统内存使用情况.
<p> used(即-buffers/cached), 表示应用程序认为系统被用掉的内存, = Mem used - Mem buffer - Mem cached. </p>
<p> free(即+buffers/cached), 表示应用程序认为系统还有多少内存, = Mem free + Mem buffer + Mem cached. </p>

- buffer & cache:
buffer, 存放要输出到disk的数据;
cache, 存放从disk读取到的数据;
两者都由OS管理.


## [apt & yum]( https://www.cnblogs.com/garinzhang/p/diff_between_yum_apt-get_in_linux.html )
一般来说著名的linux系统基本上分两大类：
1. RedHat系列：Redhat、`Centos`、Fedora等
2. Debian系列：`Debian`、Ubuntu等

### RedHat 系列
1. 常见的安装包格式 rpm包,安装rpm包的命令是“rpm -参数”
2. 包管理工具 `yum`

| yum常用的命令 |  |
|:---|:---|
| yum search xxx   | 搜索软件包（以名字为关键字） |
| yum install xxx  | 安装xxx软件 |
| yum info xxx     | 查看xxx软件的信息 |
| yum remove xxx   | 删除软件包 |
| yum list         | 列出软件包 |
| yum clean        | 清除缓冲和就的包 |
| yum provides xxx | 以xxx为关键字搜索包（提供的信息为关键字） |

### Debian系列
1. 常见的安装包格式 deb包,安装deb包的命令是“dpkg -参数”
2. 包管理工具 `apt-get`

| apt-get常用命令 |  |
|:---|:---|
| sudo apt-get install <package> | 安装包 |
| sudo apt-get install <package> --reinstall | 重新安装包 |
| sudo apt-get -f install | 修复安装 |
| sudo apt-get remove <package> | 删除包 |
| sudo apt-get remove package --purge | 删除包，包括删除配置文件等 |
| sudo apt-get update | 更新源 |
| sudo apt-get upgrade | 更新已安装的包 |
| sudo apt-get dist-upgrade | 升级系统 |
| apt-cache search <package> | 搜索包 |
| apt-cache show <package> | 获取包的相关信息，如说明、大小、版本等 |


## rz & sz
- Linux/Unix同Windows进行ZModem文件传输的命令行工具

```shell
$ yum install lrzsz -y
```

### rz
- recieve: xshell -> linux
- 支持拖拽上传

### sz
- send: linux -> xshell



## curl
- 与wget类似.
- curl是一个向服务器传输数据的工具.
- 支持http、https、ftp、ftps、scp、sftp、tftp、telnet等协议.

### 常用参数
<http://blog.csdn.net/lansesl2008/article/details/14523303>

$ curl [options] <url>
```
-o, --output <file> Write to file instead of stdout
 -C, --continue-at <offset> Resumed transfer offset
 -b, --cookie <data> Send cookies from string/file
 -c, --cookie-jar <filename> Write cookies to <filename> after operation
     --create-dirs   Create necessary local directory hierarchy
 -d, --data <data>   HTTP POST data
 -D, --dump-header <filename> Write the received headers to <filename>
 -G, --get           Put the post data in the URL and use GET
 -U, --proxy-user <user:password> Proxy user and password
 -u, --user <user:password> Server user and password
 -A, --user-agent <name> Send User-Agent <name> to server
```


## 配置系统时间
- 查看当前时间:
```
date
```

- 修改系统时区:
```
cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime   //亚洲上海时区替换系统时区
```

- 用ntp自动同步网络时间
```
yum install ntp # 安装
ntpd # 启动ntp守护进程,自动同步时间
```

.
