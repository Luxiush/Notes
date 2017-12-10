# python2.7

---
## 简介


---
## 基础
### 数据类型

* 整数, 浮点数, 字符串, 布尔
* 空值(None), 一个特殊的值

### 变量
> Python支持多种数据类型，在计算机内部，可以把任何数据都看成一个“对象”，而变量就是在程序中用来指向这些数据对象的，对变量赋值就是把数据和变量给关联起来。

* 没有机制保证常量的值不会被改变.


### list & tuple


### dict & set


### 字符串和编码
```python
s1 = 'aaaa'  # str 对象
s2 = "aaaaa" # str对象
# 三引号中的字符串可以保护制表、换行以及其他特殊字符
s3 = '''ccc\tcc\nccc'''
su = u'uuuuu'  # unicode 对象
```


### 基本语句
* 特殊的运算符
```python
# a=3, b=2
a/b = 1.5
a//b = 1
b**a = 2*2*2 = 8
```


---
## 函数
<p> 定义函数时，需要确定函数名和参数个数；</p>
<p> 如果有必要，可以先对参数的数据类型做检查；</p>
<p> 函数体内部可以用return随时返回函数结果；</p>
<p> 函数执行完毕也没有return语句时，自动return None。</p>
<p> 函数可以同时返回多个值，但其实就是一个tuple。</p>

### 可变对象/不可变对象
#### 可变对象
* 对象的内容可以改变, 对一个对象进行修改时是直接对对象本身进行修改, 没有生成拷贝
* list, dict

#### 不可变对象
* 对象的内容不可改变, 对一个对象的修改实际是另外生成了该对象的一个拷贝(深拷贝/浅拷贝?)
* 其他

* 那自定义类型的对象呢?

### 函数参数
#### 参数传递
* python中函数参数的传递都是`引用传递`, 不存在值传递
* 因此对于`可变对象`, 函数内对参数的修改会影响到原始对象

#### 默认参数
默认参数必须指向不变对象, 因为默认参数是函数的`属性`(函数也是对象), 默认参数的值可能随着函数被调用而改变.

#### 可变参数
* 传入的参数的个数是可变的
* 在list或tuple前面加一个`*`号,可以把list或tuple的元素变成可变参数进行传递
```
def cacl(*numbers):
    sum = 0
    for n in numbers:
        sum += n
    return sum

>>> cacl(1, 2, 3)
6
>>> num = [1, 2, 3]
>>> cacl(*num)
6
```

#### 关键字参数
* 关键字参数允许你传入0个或任意个含参数名的参数，这些关键字参数在函数内部自动组装为一个dict
* 和可变参数类似，可以在dict前面加上`**`号，将其变成关键字参数进行传递
```
def person(name, age, **kw):
    print "name: %s, age: %s" % (name, age)
    print "others: "
    for k,v in kw.iteritems():
        print "%s: %s" % (k, v)

```

#### 参数组合
* 参数定义的顺序必须是：`必选参数`、`默认参数`、`可变参数`和`关键字参数`

---
## 函数式编程
* 允许把函数本身作为参数传入另一个函数，还允许返回一个函数， python对函数式编程提供`部分支持`。

### 高阶函数
* 变量可以指向函数 (函数指针)
* 函数名也是变量
* 高阶函数：可以接受另一个函数作为参数的函数
```
def add(x, y, func):
    return func(x)+func(y)
>>> add(5, -6, abs)
11
```

> 把函数作为参数传入，这样的函数称为`高阶函数`，`函数式编程`就是指这种高度抽象的`编程范式`。

#### 函数作为返回值
```
def lazy_sum(*args):
    def sum():
        res = 0
        for n in args:
            res += n
        return res
    return sum
>>> f = lazy_sum(1,3,5,7,9)
>>> f
<function sum at 0x10452f668>
>>> f()
25
```

> 我们在函数lazy_sum中又定义了函数sum，并且，内部函数sum可以引用外部函数lazy_sum的参数和局部变量，当lazy_sum返回函数sum时，相关参数和变量都保存在返回的函数中，这种称为`闭包(Closure)`的程序结构拥有极大的威力。

* 每次调用都会返回一个新的函数，即使传入相同的参数

### 匿名函数
* lambda
* 只是一个表达式，函数体比def简单得多
* 只能写一行
* 不能访问自有参数列表之外或全局命名空间里的参数
```
>>> f = lambda x: x * x
>>> f
<function <lambda> at 0x10453d7d0>
>>> f(5)
25
```

### 装饰器
* decorator
* 在代码运行期间动态增加功能，本质上是一个返回函数的`高阶函数`
```
import functools
# 不带参数
def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print 'call %s():' % func.__name__
        return func(*args, **kw)
    return wrapper

# 带参数的decorator
def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print '%s %s():' % (text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator

```


### 偏函数
...


---
## 面向对象编程(Object Oriented Programming)

* 把对象作为程序的基本单元, 一个对象包含了`数据`和操作数据的`函数`.
* 三大特点: 数据封装, 继承, 多态

> 自定义的对象数据类型就是面向对象中的类(Class)的概念。

### 类和实例
* 类方法的第一个参数永远为`self`, 并且调用时不用传递该参数

* 与静态语言不同, python允许自由地给一个实例变量绑定属性和方法, 同时也可以通过定义一个构造函数`__init__`在创建实例的时候绑定一些必须属性.
```
calss Student(object):
    pass

s = Student()
s.name = 'Sam'  # 动态给实例绑定属性

def set_age(self, age):
    self.age = age

from types import MethodType
s.set_age = MethodType(set_age, s, Student)     # 给实例绑定方法
```

* 私有变量: \__xxxx, 只能在类内访问

* 特殊变量: \__xxxx\__, 不是私有变量, 可以直接访问

### 继承和多态
* 子类可以直接拥有父类的所有属性和方法, 子类可以在此基础上新增自己特有的功能,或者重写父类不适合的方法.
* 在调用类实例方法的时候, 尽量把变量视作父类类型,这样所有子类类型都可以被正常接收.

* 所有的类都继承自`object`类.

### 获取对象信息
* type()
* isinstance()
* dir()
* getattr(), setattr(), hasattr()

### OOP高级编程

#### \@property
```
class Student(object):

    @property
    def birth(self):
        return self._birth

    @birth.setter
    def birth(self, value):
        self._birth = value

    @property
    def age(self):
        return 2014 - self._birth
```

#### 元类(metaclass)
* 动态语言支持运行期间动态创建类
* 先定义metaclass, 然后创建类, 最后创建实例. 可以把`类`看做是`metaclass`创建出来的`实例`.
* metaclass继承自type, 构造函数为`__new__`
```
# metaclass是创建类，所以必须从`type`类型派生：
class ListMetaclass(type):
    def __new__(cls, name, bases, attrs):
        attrs['add'] = lambda self, value: self.append(value)
        return type.__new__(cls, name, bases, attrs)

class MyList(list):
    __metaclass__ = ListMetaclass # 指示使用ListMetaclass来定制类

>>> L = MyList()
>>> L.add(1)
>>> L
[1]
```

#### 类方法&&实例方法
* 类方法(\@classmethod)有点像c++类中的静态函数,不需要实例化即可调用, 而实例方法则类似c++中的普通成员函数,需要实例化才能调用


---
## 进程和线程
### Global Interpreter Lock(全局解释器锁)
python的原始解释器CPython中存在着GIL, 用来限制线程对共享变量的访问. 由于CPython整体作为一个进程同一时刻只能有一个获得GIL的线程在跑, 所以即使在多核CPU中, 多线程也只是**分时切换而已**.

### 多线程
> 多线程的并发在Python中就是一个美丽的梦

* threading 模块实现多线程
* ThreadLocal对象: 线程内的全局变量, 介于局部变量和全局变量之间,作用范围为一个线程, 线程之间互不干扰. 通常用于为每个线程绑定一个数据库连接,http请求,用户身份等.

### 多进程
* 在linux下可以用`os.fork()`调用实现多进程
* 要实现跨平台则需要用`multiprocessing`模块
* 进程间可以通过`Queue`, `Pipe`进行通信

---
## I/O编程
### input & raw_input
* raw_input, 从标准输入读取一行，并返回一个字符串
* input，与raw_input类似，但可以接收一个Python表达式作为输入，并返回运算结果
```python
#name = raw_input('please input your name: ')
name = input('please input your name:')
age = input("your age: ")
print("your name is ", name, "\n")
print("name: %s, age: %s\n" %(name,age))
```

### 文件I/O
```python

```

* open close read write tell seek
* os: rename, remove(remove file), mkdir, rmdir, chdir(change dir), getcwd(get current work dir)

---
## 网络编程


---
## else
