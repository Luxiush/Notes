## xlrd库
- 用于操作excel表格

### [常用方法]( https://www.cnblogs.com/lhj588/archive/2012/01/06/2314181.html )

#### read
```python
# 打开文件
book = xlrd.open_workbook(file_in)

# 获取一个工作表格
table = book.sheets()[0]

# nrows 获取行数;
# ncols 获取列数
for r in range(table.nrows):

    # row_values(i) 获取某一行
    # col_values(i) 获取某一列
    row = table.row_values(r)

    for d in row:
        print "%s" % d
    print "\n"

```


#### write
...



.
