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
