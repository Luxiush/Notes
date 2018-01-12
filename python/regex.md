## 正则表达式
- <http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143193331387014ccd1040c814dee8b2164bb4f064cff000>
- <http://www.runoob.com/regexp/regexp-syntax.html>
- <http://www.cnblogs.com/huxi/archive/2010/07/04/1771073.html>

用一种描述性的语言来给字符串定义一个规则

### 入门
#### 基本语句
```
    字符
\               转意符
.               任意任意`一个`字符
[ ]             字符集(对应的位置可以是字符集中的任意字符), "^"开头表示取反

    预定义字符集, 可以写在"[]"中
\s              空白符` [<space>\t\n\r]
\d              数字 [0-9]
\w              单词字符 [0-9a-zA-Z_]
\S              非空白符
\D              非数字 [^0-9]
\W              非单词字符

    数量词, 用在字符或"()"之后
*               匹配前面的子表达式`任意`次
+               重复`至少`一次
?               匹配前面的子表达式`零次`或`一次`
{n}             匹配n次
{n,m}           n到m次
{n,}            至少n次
{,m}            最多m次

    边界匹配
^               字符串`开头`, 多行模式中匹配行的开头
$               字符串`末尾`, 多行模式中匹配行的末尾
^\d             以数字开头
\d$             以数字结尾

    逻辑, 分组
A|B             A或者B
( )             分组
\n             引用编号为n的分组匹配到的字符串

```


#### 例
```
[0-9]                     匹配一个数字
[0-9a-zA-Z\_]             匹配一个数字、字母或者下划线
[0-9a-zA-Z\_]+            匹配至少由一个数字、字母或者下划线组成的字符串
[a-zA-Z\_][0-9a-zA-Z\_]*  匹配由字母或下划线开头，后接任意个由一个数字、字母或者下划线组成的字符串
[\u4e00-\u9fa5]           匹配`中文`

ab+c      匹配 abc，abbc，abbbc，abbbbc ...
ab*c      匹配 ac，abc，abbc，abbbc ...

(\d+)\[a-zA-Z]+\1         匹配 12aaa12, 34fjigj54

```

#### 贪婪 v.s. 非贪婪模式
- 贪婪模式: 匹配`尽可能多`的字符, [0-9]+
- 非贪婪模式: 匹配`尽可能少`的字符, [0-9]+?


### 进阶(re模块)

```python
# encoding: UTF-8
import re

# 将正则表达式编译成Pattern对象
pattern = re.compile(r'hello')

# 使用Pattern匹配文本，获得匹配结果，无法匹配时将返回None
match = pattern.match('hello world!')

if match:
    # 使用group获得分组信息
    print match.group()

### 输出 ###
# hello
```

#### complie
- 将字符串形式的正则表达式编译为Pattern对象
```
re.compile(pattern[, FLAG])
```
FLAG的取值:
    - re.I: 忽略大小写
    - re.M: 多行模式, 改变'^'和'$'的行为
    - re.X: 详细模式, 正则表达式可以是多行, 忽略空白字符



#### match
match()只检测RE是不是在string的开始位置匹配, search()会扫描整个string查找匹配.
也就是说match()只有在0位置匹配成功的话才有返回.
如果不是开始位置匹配成功的话, match()就返回none.

```python
import re
s = r'\d\d-\w\w'
string = "1244"

if re.match(s, string):
    print "matched"
else:
    print "failed"

### 输出: failed
```

#### search
search()扫描整个字符串并返回第一个成功的匹配

#### findall
以list的形式返回所有能够匹配到的子串

#### split
```
re.split(pattern, string[, max_split])
```
按照匹配到的字符串将string分割, max_split指定最大分割次数, 返回一个list

#### sub
- 使用给定的替换内容将匹配模式的子字符串(最左端并且非重叠的子字符串)**替换** 掉

```python
    >>> re.sub(r'{name}', u'Jhon', u'Dear {name}')
    >>> 'Dear Jhon'
```

#### group
* example
```
import re
a = "123abc456"
print re.search("([0-9]*)([a-z]*)([0-9]*)",a).group(0)   #123abc456,返回整体
print re.search("([0-9]*)([a-z]*)([0-9]*)",a).group(1)   #123
print re.search("([0-9]*)([a-z]*)([0-9]*)",a).group(2)   #abc
print re.search("([0-9]*)([a-z]*)([0-9]*)",a).group(3)   #456
```
1. 正则表达式中的三组括号把匹配结果分成三组
* group() 同group（0）就是匹配正则表达式整体结果
* group(1) 列出第一个括号匹配部分，group(2) 列出第二个括号匹配部分，group(3) 列出第三个括号匹配部分。
2. 没有匹配成功的，re.search（）返回None
3. 当然正则表达式中没有括号，group(1)肯定不对了。


#### groups
m.groups() 返回所有括号匹配的字符，以tuple格式。
m.groups() == (m.group(0), m.group(1), ...)
