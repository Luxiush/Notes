## gdb

### 常用命令
```
set args <arg1> <arg2>          # 在启动调试时给程序传递参数
run                             # 启动调试进程
quit                            # 退出gdb
Ctrl-C                          # 停止进程
Ctrl-L                          # 刷新窗口
Enter                           # 重复上一条命令

set breakpoint pending on       # 当前不能识别的breakpoint自动成为pending breakpoint

save breakpoints <filename>     # 保存断点到文件

source <filename>               # 加载GDB脚本

shell <cmd>                     # 执行shell命令
```

##### 切分窗口
```
layout src                      # 显示源码窗口
layout asm                      # 显示反汇编窗口
```

##### 设置断点
```
break <filename>:<linenum>
break <filename>:<function>
break <function>
break ... if <condition>        # 设置条件断点
```

##### 断点操作
```
info breakpoints                # 查看断点
condition <bnum> <condition>    # 修改第<bnum>个断点的命中条件, <condition>为空则清楚条件
ignore <bnum> <count>           # 忽略第<bnum>个断点<count>次
enable <bnum>                   # 启用断点
disable <bnum>                  # 禁用断点
delete <bnum>                   # 删除断点
clear <linenum>                 # 清除某一行的断点
```

##### 数据断点(观察点, watchpoint)
```
watch <expr>                    # 设置数据断点, 当表达式<expr>的值变化时中断
watch <expr> if <condition>     # 和break一样, watch也支持添加命中条件
rwatch <expr>                   # 当表达式<expr>被`读`时中断
awatch <expr>                   # 当表达式<expr>的值被`读`或`写`时中断

info watchpoints                # 列出所有观察点
```


##### 流程控制
```
next
step
continue
```

##### 查看堆栈
```
backtrace                       # 打印堆栈
frame <n>                       # 切换到第n个栈帧
up                              # 上移一个栈帧
down                            # 下移一个栈帧
```

##### 查看变量
```
display                         # 设置每次命中断点后都显示的内容
undisplay

print /x <var>                  # 查看变量 (简写p), 自定义输出格式: /x 十六进制, /u 十六进制无符号, /d 十进制, /o 八进制, /c 字符格式, /f 浮点数格式
print "aa=%d", aa               # 也可以像c中printf函数一样用

examine /nfu <addr>             # 查看内存 (简写x)
例: x /3ub 0xaaaaa              # 3表示3个单位, u表示按16进制显示(同print的格式), b表示以单字节为一个单位(还可以为: h 双字节, w 四字节, g 八字节)
```

##### 设置变量
```
set var aaa=123                 # 改变程序中变量的值
set {int}0x83040 = 4            # 将地址0x83040强制转成int, 并赋值
```

### 多进程/多线程
```
set follow-fork-mode parent     # (默认) fork后调试父进程, 子进程不受影响
set follow-fork-mode child      # fork后调试子进程

set detach-on-fork on           # (默认) fork后只控制需要调试的进程, 取决于`follow-fork-mode`
set detach-on-fork off          # fork后两个进程都受gdb控制, 至于哪个被调试哪个被挂起则受`follow-fork-mode`的控制

set schedule-multiple on/off    # ...

info threads                    # 显示所有线程
info inferiors                  # 显示所有进程

thread <thread_id>              # 切换要调试的线程
inferior <inferior_id>          # 切换要调试的进程
```

### gdb脚本

- 将调试信息输出到文件
```
set logging on
set logging file <filename>
```

##### gdb变量
- 类似于shell, gdb变量也是以`$`开头

##### command
定义命中断点<bnum>后需要执行的操作, 如果不指定<bnum>则默认为最后一个断点
```
command <bnum>
    print "aaaa"
    c
end
```


##### define
- 定义用户自定义命令, 类似于shell中的函数, 参数可以通过$0,$1,...$9访问
```
define sum
    print $1+$2+$3
end
```


#### [tracepoints(追踪点)]( https://sourceware.org/gdb/onlinedocs/gdb/Tracepoints.html )
- [Linux Kernel GDB tracepoint module(KGTP)]( http://teawater.github.io/kgtp/kgtpcn.html#__RefHeading__11613_71337508 )
- trace, action, collect, tfind



