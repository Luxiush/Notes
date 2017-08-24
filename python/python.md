# [Python](http://www.runoob.com/python/python-tutorial.html)
## 文件格式
* 第一行用于指示Python的安装位置
* 第二行用于指示文件的编码方式（文件中有中文时要指定）
```
#! /usr/bin/python 
# coding: utf-8
...
```

## 数据类型
* 整数，浮点数，字符串(可以是二进制数据)
* 布尔(Ture,False), (and, or, not)
* 空值(None)

## 运算符
### 算术运算 （a=3,b=2)
* a / b = 1.5
* a // b= 1
* a ** b= 3 * 3 = 9


## 条件语句
```python
if a>b :
    ...
elif a<b :
    ...
else :
    ...
```

## 循环语句
* while
```python
count = 0
while (count<10) :
    print("count=",count)
        count += 1
```

* for
```python
for letter in 'python':
	print(letter," ")

fruits = ['banana', 'apple', 'orange']
for fruit in fruits:
	print(fruit," ")

for inex in range(len(fruits)):
	print(fruits[index]," ")
```

## 字符串
```python
str = "0123456789"
sub_str = str[0:5] # 012345
```

* 字符串格式化
```python
print("my name is %s, I'm %d years old.", 'Jane', 21)
```

* 三引号
  --- 三引号中的字符串可以保护制表、换行以及其他特殊字符
```python
create_table = '''
CREATE TABLE user(
login varchar(8),
uid integer,
password varchar(10)
);
'''
```
## 列表（List）
```
list = ['physics','math',1995,2001]
del list[2]    #删除
list[3] = 2222 #更新

list1 = [1,2,3]
list2 = [4]
list12 = list1 + list2 #拼接
list2_ = list2 * 4 #重复 (list2_ = [4,4,4,4])
```

## 元组	
* 元组的元素不能修改，而列表可以

## 字典
* 存储键值对(key:value)
* 键值不允许`重复`,不允许`修改`

### 基本操作
```python 
dict = {'Name':'Zara', 'Age':7, 'Class':'First'}   # 创建字典
dict['Age'] = 8                                    # 更新元组
dict['Department'] = 'Computer Science'            # 添加元组
del dict['Age']                                    # 删除条目
del dict                                           # 删除字典
```

## 日期和时间


## 函数
```python
def func(str):
	"函数说明"
	print str
	return 
func("abcdefg")
```

### 参数传递
* 可变类型
  -- 类似c++的引用传递
  -- 如：list、dict
  -- 变量赋值 la=[1,2,3,4] 后再赋值 la[2]=5，
  则是将 list la 的第二个元素值更改，
  本身la没有动

* 不可变类型
  -- 类似c++的值传递
  -- 如：strings、tuples、numbers
  -- 变量赋值 a=5 后再赋值 a=10，
  重新生成一个int值对象10，
  再让a指向它，
  而原来的对象被丢弃

### 参数
* 必备参数
  -- 必须以正确的顺序传入函数，调用时的数量必须和声明时的一样

* 关键字参数
  -- 允许调用时参数的顺序与声明时不一致
```python
def printinfo(name, age):
  "函数说明"
  print "Name: ", name
  print "Age: ", age 
  return 
  
printinfo(age=50, name="Kiwi")
```

* 缺省参数
  -- 缺省参数的值如果没有传入则被认为是默认值
```python
def printinfo(name, age=50):
  "函数说明"
  print "Name:", name
  print "Age: ", age 
  return 
  
printinfo(name="Alice")
```

* 不定长参数
  o `*`  表示`数组`类型的变长参数
  o `**`表示`字典`类型的变长参数
```python
def printinfo(arg1, *vartuple): 
  "函数说明"
  print arg1
  for var in vartuple:
     print var 
  return 
  
printinfo(10)
printinfo(10,20,30,40)

def printinfo2(**kwargs):
  for k in kwargs:
    print k, ":", kwargs[k],"; "

conf = {'name':'xxx', 'age':22, 'class':'yyyy'}
printinfo2(conf)
```

### 匿名函数（lambda --- λ）
* 只是一个表达式，函数体比def简单得多
* 只能写一行
* 不能访问自有参数列表之外或全局命名空间里的参数
```
sum = lambda arg1,arg2: arg1+arg2
print sum(10,20)
```

## 模块		
### import 语句
-- 将另一个Python源文件里的程序引入当前文件
-- 一个模块之后被导入一次，不管执行多少次import
```python
# support.py
def support(var):
  print "In support.py:", var
  return 
  
# func.py 
import support.py 
support.support("VAR")
```

### from...import 语句
-- 导入模块中的特定部分 
```
from fib import fibonacci # 将fib模块中的fibonacci函数导入
from fib import *         #
```

## 包
```python
#-------定义包
# Phone/func1.py 
def func1():
  print "hello func1."

# Phone/func2.py 
def func2():
  print "hello func2."

# Phone/__init__.py 
from func1 import func1 
from func2 import func2 

#--------在另一个文件中导入包
import Phone 
Phone.func1()
Phone.func2()
```

## 文件I/O 
### 读取键盘输入
* raw_input, 从标准输入读取一行，并返回一个字符串
* input，与raw_input类似，但可以接收一个Python表达式作为输入，并返回运算结果
```python
#name = raw_input('please input your name: ') 
name = input('please input your name:') 
age = input("your age: ")
print("your name is ", name, "\n")
print("name: %s, age: %s\n" %(name,age))
```

### 打开/关闭文件
* open
```
file f = open(file_name,mode,buffering)
# mode 可取：r(读), rb(读，二进制),  w(写), wb, a(追加), ab 
# buffering 0,1 表示是否寄存; >1 表示缓冲区大小; <1 表示默认缓冲大小
```

* close
```
fileObject.close(); #刷新缓冲区里任何还没写入的数据，并关闭文件		
```

### 文件读写	
* write 
```
fileObject.write(string); # 将任意字符串写入一个打开的文件
```

* read 
```
fileObject.read(count); 
```
-- 从一个打开的文件中读取字符串
-- count指定要读取的字节数

### 文件定位
* tell
  -- 当前文件位置

* seek
  -- 改变当前文件的位置


### 重命名和删除文件
* rename
```
import os
os.rename(current_file_name, new_file_name)
```

* remove 
  os.remove(file_name)

### 目录
* mkdir
  -- 在当前目录下创建目录
  os.mkdir("new_dir") # 先 import os

* rmdir
  -- 删除目录
  os.rmdir("dir_name")

* chdir
  -- 改变当前目录

* getcwd
  -- 显示当前工作目录  



