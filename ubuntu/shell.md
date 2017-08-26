# shell 常用命令
## grep
* 文件搜索
```
$ grep '<要找的内容>' <目标文件>
$ grep -E '<要找的内容>' <目标文件>             # 支持正则表达式
$ grep <pattern1> | <pattern2> <files>       # 显示匹配 pattern1 或 pattern2的行，
$ grep <pattern1> <files> | grep <pattern2>  # 显示既匹配 pattern1 又匹配pattern2 的行。
```

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
| -perm | 755 | 属性为755 |
| -user | root | 属主为root |








