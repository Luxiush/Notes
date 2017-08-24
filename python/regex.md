## 正则表达式
ref: http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143193331387014ccd1040c814dee8b2164bb4f064cff000
ref: http://www.runoob.com/regexp/regexp-syntax.html

用一种描述性的语言来给字符串定义一个规则

### 入门
#### 基本语句
```
\               转意符
\d              数字
\w              字母或数字
\s              匹配一个`空格`或`Tab`等`空白符`
{n}             n个字符
{n,m}           n到m个字符
.               任意`一个`字符
?               匹配前面的子表达式`零次`或`一次`
+               重复`至少`一次
*               重复`任意`次

A|B             A或者B

^               行的`开头`
^\d             以数字开头
$               行的`结尾`
\d$             以数字结尾

( )             子表达式
[ ]             中括号表达式
{ }             限定表达式
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
```

#### 贪婪 v.s. 非贪婪模式


### 进阶(re库)

#### match
match（）函数只检测RE是不是在string的开始位置匹配，search()会扫描整个string查找匹配.
也就是说match（）只有在0位置匹配成功的话才有返回.
如果不是开始位置匹配成功的话，match()就返回none。

```python
import re
s = r'\d\d-\w\w'
str = "1244"

if re.match(s, str):
    print "matched"
else:
    print "failed"
```

#### search
search()会扫描整个字符串并返回第一个成功的匹配

#### findall


#### finditer


#### sub
> re.sub：使用给定的替换内容将匹配模式的子字符串（最左端并且非重叠的子字符串）替换掉
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
