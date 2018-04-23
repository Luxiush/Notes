## LPC
<http://192.168.12.7/lpc.html>
<https://www.cnblogs.com/cfas/p/5877842.html>

- 用于游戏服务器开发的`脚本语言`.
- 语法与c很相似, 但是二者却有很大的不同: 前者是面向过程, 而后者是oop.
- 解释型语言, 类似java

### 基本概念
- MUD : Multiple User Dimension, 多用户层面, 通常指一种网络游戏
- lpMUD: MudLib + MudOS

- mudlib: lpc对象的集合, 定义了一些基本的游戏元素.

- driver: 基本的对象管理核心和解释器, 用于执行lpc指令.
- 一个lpc文件描述的是一个对象(Object), 在必要时会调用create函数进行Object的初始化, 程序没有特殊的开始和结束的标志(比如c中的main函数).



### 一些概念
#### 外部函数(efun)
MUD系统函数

#### local function (lfun)

#### Objects
master object: 程序加载的时候会在内存生成一个master object,
其他的object都是master object的拷贝, 共用一个指令集, 内存独立,
但是重新编译源码后master object会更新, 但是其他object不会被更新.
> If you want to change the program you must update the master object to instruct the gamedriver that a new list of instructions is to be compiled from the source code.
> However, any already existing clones will not change just because the master does.
> However, any already existing clones will not change just because the master does. They will keep their reference to the old instruction list.


### data type


### operator expression
- 算术运算: +, -, \*, /, %, ++, --
- 布尔运算: &, |, ^, ~, <<, >>
- 逻辑运算: ||, &&, !
- 比较: >, <, >=, <=, ==, !=


### 常见用法:
- sort_array: 数组排序
- copy: 复制一个对象
- static的骚操作: 在.h中定义为static, 在.c中初始化.

---
### 常用函数
```c++
if( strsrch(lsId, "USER") != -1 )
```

```c++
string *legions = sort_array(keys(LogicService["LEGION"]), 1);
```

```c++
mapping info = LogicServer[lsId];
return copy(info);
```

```c++
fs_ls_rpc_call(vfd, pid, args...);  
```

```c++
string typeUpper = upper_case(type);
```

```c++
/// vfd: socket id
int vfd = socket_create( "on_gs_connection_close", 1 );  
```

```c++

```

```c++

```
