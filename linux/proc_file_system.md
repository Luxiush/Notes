## [proc文件系统]( http://man7.org/linux/man-pages/man5/proc.5.html )
- 用于访问内核数据, 一般挂载在`/proc`目录下: `mount -t proc proc /proc`

### 进程相关(`/proc/[pid]`)
- 每个进程都会有一个以其进程id命名的目录

- `/proc/self`: 一个神奇的软链接, 指向访问者的进程目录

- `/proc/[pid]/cmdline`: 进程的启动命令
```
$ cat /proc/3417/cmdline
/opt/google/chrome/chrome
```

- `/proc/[pid]/cwd`: 进程当前工作目录的软链接(current word directory)
```
$ ll /proc/3417/cwd
lrwxrwxrwx 1 snail snail 0 Dec 22 10:09 /proc/3417/cwd -> /home/snail/
```

- `/proc/[pid]/environ`: `execve()`在启动进程时传过来的环境变量
```
$ cat /proc/1/environ | tr '\0' '\n'
HOME=/
init=/sbin/init
locale=en_US
PWD=/
...
```

- `/proc/[pid]/exe`: 指向进程可执行文件的软链接
```
$ ll /proc/1/exe
lrwxrwxrwx 1 root root 0 Dec 20 08:11 /proc/1/exe -> /sbin/init
```

- `/proc/[pid]/root/`: 软链接, 在进程视角下的文件系统的根目录, 不同的进程看到的进程根目录会有所不同(chroot)

- `/proc/[pid]/fd/`: 记录进程打开的文件, 每一项都是一个软链接, 以文件描述符命名, 指向对应的文件.
几个相关的`/dev`目录:
```
$ ll /dev/fd
lrwxrwxrwx 1 root root 13 Sep 16 07:54 /dev/fd -> /proc/self/fd/

$ ll /dev/stdin
lrwxrwxrwx 1 root root 15 Sep 16 07:54 /dev/stdin -> /proc/self/fd/0

$ ll /dev/stdout
lrwxrwxrwx 1 root root 15 Sep 16 07:54 /dev/stdout -> /proc/self/fd/1

$ ll /dev/stderr
lrwxrwxrwx 1 root root 15 Sep 16 07:54 /dev/stderr -> /proc/self/fd/2
```

- `/proc/[pid]/io`: 记录进程的i/o信息

- `/proc/[pid]/uid_map`:

- `/proc/[pid]/gid_map`:

- `/proc/[pid]/mountinfo`:
- `/proc/[pid]/mounts`:

- `/proc/[pid]/ns`:

- 关于linux的命名空间(namespace):
> A namespace wraps a global system resource in an abstraction that
> makes it appear to the processes within the namespace that they have
> their own isolated instance of the global resource.  Changes to the
> global resource are visible to other processes that are members of
> the namespace, but are invisible to other processes.  One use of
> namespaces is to implement containers.


- `/proc/[pid]/stat`: 记录进程的状态(status)信息, `ps`命令就是从这里获取每个进程的信息的
- `/proc/[pid]/statm`: 记录进程的内存使用情况
- `/proc/[pid]/status`: 记录的信息和`stat`,`statm`一样, 只是更适于人眼读取

- `/proc/[pid]/task/`: 记录进程的所有子线程信息

### sys目录(`/proc/sys`)
一些内核变量

- `/proc/sys/fs/binfmt_misc`: 记录哪些程序关联了哪些类型的文件, 相当于windows下的指定什么类型的文件用什么程序打开.
其中`proc/sysfs/binfmt_misc/register`注册自定义的脚本解释器, 将特定类型的文件关联到对应的程序(Documentation/admin-guide/binfmt-misc.rst)


#### `/proc/keys`, `/proc/keys-user`
- 关于linux的keyrings: TODO


#### `/proc/meminfo`
- 记录内存的使用情况.
- `free`命令就是从这里读数据的


#### else
- `/proc/filesystem`: 记录现在内核所支持的文件系统, 即文件系统直接被编进内核的或者是已经加载了对应的模块. `nodev`表示不需要挂载到具体的磁盘

- `/proc/fs`: 已挂载的文件系统信息

- `/proc/cmdline`: 记录引导器传给内核的启动参数
```
$ cat /proc/cmdline
BOOT_IMAGE=/boot/vmlinuz-4.4.0-83-generic root=UUID=3f95f99d-e001-4670-ab2d-63e29c2bb76d
ro find_preseed=/preseed.cfg auto noprompt priority=critical locale=en_US quiet
```

- `/proc/loadavg`: 平均负载(一段时间内所有cpu上的活动进程数的平均值)
```
$ cat /proc/loadavg
1.53 0.80 0.72 2/950 82884
(1)  (2)  (3) (4)/(5)  (6)

(1),(2),(3): 分别对应1,5,15分钟内的平均负载
(4): 当前内核可执行的进程(线程)数
(5): 当前内核的进程(线程)总数
(6): 最近创建的进程的pid
```

- `/proc/modules`: 当前已经加载的模块, 主要用于`lsmod`命令

- `/proc/mounts`:
```
$ ll /proc/mounts
lrwxrwxrwx 1 root root 11 Jan  7 08:24 /proc/mounts -> self/mounts
```

- `/proc/net`: 网络相关
```
$ ll /proc/net
lrwxrwxrwx 1 root root 8 Jan  8 08:07 /proc/net -> self/net/
```

- `/proc/swap`: 记录当前用于页面置换的设备
