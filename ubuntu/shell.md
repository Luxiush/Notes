# shell 常用命令
## grep
文件搜索 
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


* 文件比较
```
$ grep -vwf file1 file2 # 统计file1中没有，file2中有的行
```


## cat
> Concatenate FILE(s), or standard input, to standard output.


## sort
将文件的每一行作为一个单位，相互比较，比较原则是从首字符向后，依次按ASCII码值进行比较，最后将他们按升序输出。
```
$ sort <options> <file>
```

|参数 | 说明 |
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


## awk
* 读取文件第一行
```
$ awk 'NR==1; NR==2 {exit;}' <file_in>
```

## [find](http://www.cnblogs.com/johnnyliu/archive/2013/04/09/3010384.html)
```
$ find <查找目录> <参数> <匹配模型>
```

| **参数** | **匹配模型** | **说明** |
|:---|:---|:---|
| -name | *.sh | 以.sh结尾 | 
| -mtime | -5 | 更改时间在5天以内 |
| -mtime | +3 | 更改时间在3天以前 |
| -size | +1000000c | 文件大小大于1M(1000000bytes) |
| -type | d | 文件类型为d的目录文件 |
| -type | I | 文件类型为|的链接文件 |
| -type | f | 普通文件 |
| -perm | 755 | 属性为755 |
| -user | root | 属主为root |
| -depth | ... | 广度优先遍历 | 
| -maxdepth | <int_number> | 设定递归搜索的目录层级, 1为当前目录(不递归) |
| -print | ... | 一行一个 |
| -print0 | ... | 不换行 |


## ll,ls
```
$ ls <options> <directory or file>
$ ll <options> <directory>
```

常用参数

| 参数 | 说明 |
|:---|:---|
| -a | all |
| -h | size in human readable |
| -l | list format |
| -r | reverse order |
| -s | size,输出大小 |
| -t | 按修改时间排序 | 
| -d | 只显示目录 |


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

## crontab
设置定时任务







