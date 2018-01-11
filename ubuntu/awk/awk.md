## [awk]( http://man.linuxde.net/awk#awk的工作原理 )
```
$ awk [options] 'script' var=value file(s)
$ awk [options] -f scriptfile var=value file(s)
```
| options | . |
|:---|:---|
| -f | 从脚本文件中读取awk命令 |
| -F | 指定输入分隔符(可以是字符串或正则表达式) |


> awk是一种**编程语言**(语法类似C)，用于在linux/unix下对文本和数据进行处理。

> 简单来说awk就是把文件逐行的读入，以空格为默认分隔符将每行切片，切开的部分再进行各种分析处理。

### 工作原理
```
awk 'BEGIN{ commands } pattern{ commands } END{ commands }'
```
* `BEGIN{ command }`, 在读取行`之前`执行, 常用于初始化
* `patter{ command }`, 每次读取一行, 对每一行都执行指定的操作
* `END{ command}`, 在读取完所有行`之后`执行

### 内置变量
$n 当前记录的第n个字段
$0 当前行
NR 当前行号
NF 当前行的字段数
FS 字段分隔符（默认是任何空格）
RS 记录分隔符（默认是一个换行符）

ARGC 命令行参数的数目。
ARGV 包含命令行参数的数组。
ARGIND 命令行中当前文件的位置（从0开始算）。
CONVFMT 数字转换格式（默认值为%.6g）。
ENVIRON 环境变量关联数组。
ERRNO 最后一个系统错误的描述。
FIELDWIDTHS 字段宽度列表（用空格键分隔）。
FILENAME 当前输入文件的名。
FNR 同NR，但相对于当前文件。
IGNORECASE 如果为真，则进行忽略大小写的匹配。

OFMT 数字的输出格式（默认值是%.6g）。
OFS 输出字段分隔符（默认值是一个空格）。
ORS 输出记录分隔符（默认值是一个换行符）。
RSTART 由match函数所匹配的字符串的第一个位置。
RLENGTH 由match函数所匹配的字符串的长度。
SUBSEP 数组下标分隔符（默认值是34）。


### 运算符
- 基本与c一致

~ ~!	匹配正则表达式和不匹配正则表达式
```
~!/the/{print}  // 输出不包含the的行
$2~/the/{print}
```
in      判断数组中是否存在某个字符(串)


### 用法示例
* 读取文件第一行
```
$ awk 'NR==1; NR==2 {exit;}' <file_in>
```

* 累加求和
```
$ gawk '{ sum += $1 }; END { print sum}' <file>
```

---
--- 太过复杂的任务, 完全可以用python来完成 ---

### 流程控制语句
- if-else, while, for语法与c一致


### 内置函数
#### 字符串函数
- sub, match, split, substr
