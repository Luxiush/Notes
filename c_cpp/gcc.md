---
Reference: 
    http://blog.csdn.net/u013467442/article/details/44560443
---

## GCC (GNU C Compiler)

### 编译的四个步骤
1. 预处理(预编译，Preprocessing)
.c --> .i 
展开在源文件中定义的宏，插入“#include”语句所包含的内容

2. 编译(Compilation)
.i --> .s 
生成汇编代码

3. 汇编 (Assembly)
.s --> .o 
生成目标文件

4. 连接(Linking)
.o --> .exe 
将程序的目标文件与所需的所有附加的目标文件连接起来，最终生成可执行文件。


### gcc常用参数
| 参数 | 说明 |
|:---|:---|
| -o | 输出到指定文件 |
| -I | 指定头文件所在目录 |
| -L | 指定库文件所在目录 |
| -l | 指定程序要链接的库 |
| -E | `Preprocess` only; do not compile, assemble or link |
| -S | `Compile` only; do not assemble or link | 
| -C | `Compile` and `assemble`, but do not link |

* extra 
动态库名格式: lib<lib_name>.so 
静态库: lib<lib_name>.a 