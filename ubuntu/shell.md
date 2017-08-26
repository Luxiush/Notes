# shell 常用命令
## grep
* 文件搜索 
grep <option>... <pattern> <file>... 
```
$ grep '<要找的内容>' <目标文件>
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


* 文件比较
```
$ grep -vwf file1 file2 # 统计file1中没有，file2中有的行
```

## wc
```
$ wc -l <filename>                         # 统计文件行数
$ grep -o "<keyword>" <filename> |wc -l    # 统计某文件中某个关键字出现的次数

```


## whereis
```
$ whereis <filename>                       # 查找文件所在目录
```


## ll
```
$ ll -h
$ ll -t|head
```

## [find](http://www.cnblogs.com/johnnyliu/archive/2013/04/09/3010384.html)
* find <查找目录> <参数> <匹配模型>

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








